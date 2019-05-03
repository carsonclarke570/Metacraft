/*
    Copyright 2019 Carson Clarke-Magrab

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include <model.h>

int model_create(Model *model, const char *filename) {
    const struct aiScene* scene = aiImportFile(filename, aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!scene) {
        fprintf(stderr, "ERROR: Failed to read 3D object file %s\n", filename);
        return CODE_READING_ERROR;
    }
    model->meshes = malloc(scene->mNumMeshes * sizeof(Mesh));
    model->num_meshes = scene->mNumMeshes;

    int n = 0;
    process(model, scene->mRootNode, scene, &n);

    aiReleaseImport(scene);
    return CODE_SUCCESS;
}

void model_delete(Model *model) {
    free(model->meshes);
    model->meshes = NULL;
    model->num_meshes = 0;
}

void model_render(Model *model, Shader* shader) {
    shader_bind(shader);
    for (int i = 0; i < model->num_meshes; i++) {
        mesh_render(&model->meshes[i], shader);
    }
}

// Helpers
void process(Model* model, struct aiNode *node, const struct aiScene *scene, int *n) {
    for (int i = 0; i < node->mNumMeshes; i++) {
        struct aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];

        int idx = *n;
        Vertex* vertices = malloc(mesh->mNumVertices * sizeof(Vertex));
        unsigned int* indices = malloc(mesh->mNumFaces * 3 * sizeof(unsigned int));

        for (int j = 0; j < mesh->mNumVertices; j++) {
            vertices[j].position[0] = mesh->mVertices[j].x;
            vertices[j].position[1] = mesh->mVertices[j].y;
            vertices[j].position[2] = mesh->mVertices[j].z;

            if (mesh->mNormals) {
                vertices[j].normal[0] = mesh->mNormals[j].x;
                vertices[j].normal[1] = mesh->mNormals[j].y;
                vertices[j].normal[2] = mesh->mNormals[j].z;
            } else {
                vertices[j].normal[0] = 0.0f;
                vertices[j].normal[1] = 0.0f;
                vertices[j].normal[2] = 0.0f;
            }

            if(mesh->mTextureCoords[0]) {
                vertices[j].texture[0] = mesh->mTextureCoords[0][j].x;
                vertices[j].texture[1] = mesh->mTextureCoords[0][j].y;
            } else {
                vertices[j].texture[0] = 0.0f;
                vertices[j].texture[1] = 0.0f;
            }
        }

        for (int j = 0; j < mesh->mNumFaces; j++) {
            struct aiFace face = mesh->mFaces[j];
            for (int k = 0; k < 3; k++) {
                indices[(j * 3) + k] = face.mIndices[k];
            }
        }

        mesh_create(&model->meshes[idx], vertices, mesh->mNumVertices, indices, mesh->mNumFaces * 3);

        free(vertices);
        free(indices);
        (*n)++;
    }
    for (int i = 0; i < node->mNumChildren; i++) {
        process(model, node->mChildren[i], scene, n);
    }
}
