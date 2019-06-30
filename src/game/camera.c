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

#include <camera.h>

// Helper function
void update_vector(Camera* camera) {
    const float p_cos = cosf(camera->pitch);
    vec3 f = {
        cosf(camera->yaw) * p_cos,
        sinf(camera->pitch),
        sinf(camera->yaw) * p_cos
    };
    vec3_normalize(f, camera->front);

    vec3 world_up = WORLD_UP;
    vec3_cross(camera->front, world_up, f);
    vec3_normalize(f, camera->right);

    vec3_cross(camera->right, camera->front, f);
    vec3_normalize(f, camera->up);
}

void camera_init(Camera* camera) {
    memset(camera, 0, sizeof(Camera));
    camera->front[2] = 1.0f;
    camera->up[1] = 1.0f;
    camera->speed = CAMERA_SPEED;
    camera->sensitivity = CAMERA_SENSITIVITY;
    camera->pitch = CAMERA_PITCH;
    camera->yaw = CAMERA_YAW;
    update_vector(camera);
}


void camera_view_matrix(Camera* camera, mat4 view) {
    vec3 temp;
    vec3_add(camera->position, camera->front, temp);
    mat4_look_at(view, camera->position, temp, camera->up);
}


void camera_move(Camera* camera, Window* window, float delta) {
    const float velocity = camera->speed * delta;
    GLFWwindow* win = window->window;

    vec3 temp;
    if (glfwGetKey(win, KEY_BIND_FORWARD) == GLFW_PRESS) {
        vec3_mulf(camera->front, velocity, temp);
        vec3_add(camera->position, temp, camera->position);
    }
    if (glfwGetKey(win, KEY_BIND_BACKWARD) == GLFW_PRESS) {
        vec3_mulf(camera->front, velocity, temp);
        vec3_sub(camera->position, temp, camera->position);
    }
    if (glfwGetKey(win, KEY_BIND_LEFT) == GLFW_PRESS) {
        vec3_mulf(camera->right, velocity, temp);
        vec3_sub(camera->position, temp, camera->position);
    }
    if (glfwGetKey(win, KEY_BIND_RIGHT) == GLFW_PRESS) {
        vec3_mulf(camera->right, velocity, temp);
        vec3_add(camera->position, temp, camera->position);
    }
}


void camera_look(Camera* camera, vec2 offset) {
    vec2 temp;
    vec2_mulf(offset, camera->sensitivity, temp);

    camera->yaw = camera->yaw + temp[0];
    camera->pitch = camera->pitch + temp[1];

    if (camera->pitch > 89.0f) {
        camera->pitch = 89.0f;
    }
    if (camera->pitch < -89.0f) {
        camera->pitch = -89.0f;
    }

    update_vector(camera);
}
