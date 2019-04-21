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

#ifndef _MESH_H_
#define _MESH_H_

#include <cstdint>

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace daybreak {

    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texture;
    };

    class Mesh {
    private:
        uint32_t _vbo;
        uint32_t _vao;
        uint32_t _ibo;
        uint32_t _num_elements;
        bool _indexed;
    public:

         /**
          * Constructs a new Mesh object. The indices is set to nullptr, the mesh
          * will draw it's vertices sequentially.
          *
          * @param vertices     Vertices to add into the Mesh's buffer.
          * @param num_v        Number of vertices to add.
          * @param indices      Indices to add inti the Mesh's buffer.
          * @param num_i        Number of indices to add.
          */
        Mesh(Vertex *vertices, uint32_t num_v, uint32_t* indices, uint32_t num_i);

        /**
         * Destroys a Mesh object.
         */
        ~Mesh();

        /**
         * Renders the Mesh to the screen.
         */
        void render();
    };
}


#endif //DAYBREAK_MESH_H
