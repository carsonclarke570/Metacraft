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

#include <Texture.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void create_texture(Texture texture) {
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set texture wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void destroy_texture(Texture texture) {
    glDeleteTextures(1, &texture);
}

int load_texture(Texture texture, const char* file) {
    glBindTexture(GL_TEXTURE_2D, texture);

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
    } else {
        fprintf(stderr, "ERROR: Failed to read file %s\n", file);
        return CODE_INVALID_FILENAME;
    }
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
    return CODE_SUCCESS;
}

void bind_texture(Texture texture, unsigned int slot) {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture);
}