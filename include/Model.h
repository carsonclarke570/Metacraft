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

#ifndef _MODEL_H_
#define _MODEL_H_

#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags

#include <Mesh.h>
#include <Shader.h>

extern TexturePool texture_pool;

typedef struct {
    Mesh* meshes;
    unsigned int num_meshes;
} Model;

/**
 * Constructs a new Model from a 3D object file.
 *
 * @param model     Pointer to Model struct
 * @param filename  Path to 3D object file to load
 * @return  CODE_SUCCESS if success, else a relevant error code.
 */
int model_create(Model *model, const char *filename);

/**
 * Destroys a Model.
 *
 * @param model     Pointer to Model struct
 */
void model_delete(Model *model);

/**
 * Renders a model by drawing all of its children meshes after binding a
 * shader.
 *
 * @param model     Pointer to Model struct
 * @param shader    Shader to run on the model.
 */
void model_render(Model *model, Shader* shader);


// Helper function
void process(Model* model, struct aiNode *node, const struct aiScene *scene, int *n);

#endif
