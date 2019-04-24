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

#include <cstdint>

#include <glad/glad.h>

#include <Common.h>

namespace daybreak {

    class Texture {
        NO_COPY(Texture)
    private:
        uint32_t _texture;
    public:

        /**
         * Creates a new Texture object.
         */
        Texture();

        /**
         * Destroys a Texture object.
         */
        ~Texture();

        /**
         * Loads pixel data from a file and stores it in the Texture.
         *
         * @param file  Filepath of image to open.
         */
        void load_image(const char* file);

        /**
         * Binds the texture to a specific texture slot.
         *
         * @param id    Id number of the texture slot.
         */
        void bind(uint32_t id);

        /**
         * Unbinds the texture.
         */
        void unbind();
    };
}


#endif
