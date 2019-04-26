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

#include <glad/glad.h>

#include <Common.h>

typedef GLuint Texture;

/**
 * Creates a new Texture object.
 *
 * @param texture   Pointer to Texture struct
 */
void create_texture(Texture texture);

/**
 * Destroys a Texture object.
 *
 * @param texture   Pointer to Texture struct
 */
void destroy_texture(Texture texture);

/**
 * Loads pixel data from a file and stores it in the Texture.
 *
 * @param texture   Pointer to Texture struct
 * @param file      Filepath of image to open.
 * @return  CODE_SUCCESS if success, else a relevant error code.
 */
int load_texture(Texture texture, const char* file);

/**
 * Binds the texture to a specific texture slot.
 *
 * @param texture   Pointer to Texture struct
 * @param id        Number of the texture slot.
 */
void bind_texture(Texture texture, unsigned int slot);


#endif
