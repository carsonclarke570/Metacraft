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

#include <texture.h>

#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

// Member

int create_texture(Texture* texture, const char* file, enum TextureType type) {
    texture->type = type;

    glGenTextures(1, &texture->texture);
    glBindTexture(GL_TEXTURE_2D, texture->texture);

    // Set texture wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load images
    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);

    uint8_t* data = stbi_load(file, &width, &height, &channels, 0);
    if (data) {
        GLint format = 0;
        switch (channels) {
            case 1:
                format = GL_RED;
                break;
            case 2:
                format = GL_RG;
                break;
            case 3:
                format = GL_RGB;
                break;
            case 4:
                format = GL_RGBA;
                break;
            default:
                fprintf(stderr, "ERROR: Unrecognized image format\n");
                stbi_image_free(data);
                return CODE_UNRECOGNIZED_FORMAT;
        }
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        texture->channels = format;
    } else {
        fprintf(stderr, "ERROR: Failed to read file %s\n", file);
        return CODE_INVALID_FILENAME;
    }
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
    return CODE_SUCCESS;
}

void destroy_texture(Texture* texture) {
    glDeleteTextures(1, &texture->texture);
    texture->texture = 0;
}

void bind_texture(Texture* texture, unsigned int slot) {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture->texture);
}

// Globals
TexturePool texture_pool = {NULL, 0, 0};

const char *texture_type_map[4] = {
        "texture_diffuse",
        "texture_specular",
        "texture_normal",
        "texture_height"
};


void texture_pool_allocate(unsigned int size) {
    texture_pool.textures = malloc(size * sizeof(Texture));
    texture_pool.capacity = size;
    texture_pool.num_textures = 0;
}

void texture_pool_delete() {
    free(texture_pool.textures);
    texture_pool.textures = NULL;
    texture_pool.capacity = 0;
    texture_pool.num_textures = 0;
}