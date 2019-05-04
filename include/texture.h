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

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <stdbool.h>
#include <stdint.h>

#include <glad/glad.h>

#include <common.h>

// Member

enum TextureType {
    TEXTURE_DIFFUSE, TEXTURE_SPECULAR, TEXTURE_NORMAL, TEXTURE_HEIGHT
};

typedef struct {
    GLuint texture;
    GLint channels;
    enum TextureType type;
} Texture;

/**
 * Creates a new Texture object. Loads pixel data from a file and stores it in
 * the Texture.
 *
 * @param texture   Pointer to Texture struct
 * @param file      Filepath of image to open
 * @param name      The name of texture
 * @return  CODE_SUCCESS if success, else a relevant error code.
 */
int create_texture(Texture* texture, const char* file, enum TextureType type);

/**
 * Destroys a Texture object.
 *
 * @param texture   Pointer to Texture struct
 */
void destroy_texture(Texture* texture);

/**
 * Binds the texture to a specific texture slot.
 *
 * @param texture   Pointer to Texture struct
 * @param id        Number of the texture slot.
 */
void bind_texture(Texture* texture, unsigned int slot);

// Global

typedef struct {
    Texture *textures;
    unsigned int capacity;
    unsigned int num_textures;
} TexturePool;

/**
 * Initializes the global texture pool to a specific size.
 *
 * @param size  Size of the texture pool.
 */
void texture_pool_allocate(unsigned int size);

/**
 * Destroys the global texture pool.
 */
void texture_pool_delete();


#endif