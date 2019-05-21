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

#ifndef COMMON_H
#define COMMON_H

#include <GLFW/glfw3.h>



// Error Codes
#define CODE_SUCCESS                ( 0)
#define CODE_GLFW_INIT_ERR          ( 1)   // GLFW
#define CODE_WINDOW_CREATE_ERR      ( 2)
#define CODE_GLAD_INIT_ERR          (10)   // glad
#define CODE_INVALID_SHADER_TYPE    (20)   // Shaders
#define CODE_SHADER_COMPILE_ERROR   (21)
#define CODE_SHADER_LINK_ERROR      (22)
#define CODE_INVALID_FILENAME       (30)  // File reading
#define CODE_READING_ERROR          (31)
#define CODE_UNRECOGNIZED_FORMAT    (40)  // Textures
#define CODE_MALLOC_ERROR           (50)
#define CODE_FILE_ERROR             (51)

// String stuff
#define MAX_STR_LEN (50)

// GL
#define GL_VER_MAJ  (4)
#define GL_VER_MIN  (3)

#define GL_CLEAR_COLOR_R (0.1f)
#define GL_CLEAR_COLOR_G (0.1f)
#define GL_CLEAR_COLOR_B (0.1f)

#define GL_PI   (3.14159265358979323846f)

// Engine settings
#define WIN_WIDTH   (1200)
#define WIN_HEIGHT  (800)
#define WIN_TITLE   ("Metacraft")
#define WIN_FULL    (false)

#define ENG_FRAME_CAP       (60.0f)
#define ENG_FRAME_TIME      (1.0f / ENG_FRAME_CAP)

// Coordinate stuff
#define WORLD_UP        {0.0f, 1.0f, 0.0f}
#define WORLD_DOWN      {0.0f, -1.0f, 0.0f}
#define WORLD_LEFT      {-1.0f, 0.0f, 0.0f}
#define WORLD_RIGHT     {1.0f, 0.0f, 0.0f}
#define WORLD_FORWARD   {0.0f, 0.0f, -1.0f}
#define WORLD_BACKWARD  {0.0f, 0.0f, 1.0f}

// Camera defaults
#define CAMERA_YAW          -(GL_PI / 2.0f);
#define CAMERA_PITCH        0.0f
#define CAMERA_SPEED        2.5f
#define CAMERA_SENSITIVITY  0.005f

#define KEY_BIND_FORWARD    GLFW_KEY_W
#define KEY_BIND_BACKWARD   GLFW_KEY_S
#define KEY_BIND_LEFT       GLFW_KEY_A
#define KEY_BIND_RIGHT      GLFW_KEY_D

#define KEY_BIND_QUIT       GLFW_KEY_ESCAPE

// Chunk stuff
#define CHUNK_HEIGHT    (256)
#define CHUNK_WIDTH     (16)
#define CHUNK_INDEX(r, c, h) ((WIDTH * (h * WIDTH) + r) + c)

#define CHUNK_MESH_SIZE  (5.0f)
#define BLOCK_SIZE  (CHUNK_MESH_SIZE / CHUNK_WIDTH)

#define FACE_NORTH  (1u)
#define FACE_SOUTH  (2u)
#define FACE_EAST   (4u)
#define FACE_WEST   (8u)
#define FACE_UP     (16u)
#define FACE_DOWN   (32u)



// Log

#define LOG_MSG_MALLOC_ERROR ("Failed to 'malloc()' at line %s of \'%s\'", __LINE__, __FILE__)

#if LOG
FILE *logfile;
#define LOG_REDIRECT(F) do {\
  LOG_CLOSE();\
  LOG_OPEN(F);\
} while (0)
#define LOG_OPEN(F) do {\
  LOG_CLOSE();\
  if ((F) == stderr || (F) == stdout) {\
    logfile = F;\
  } else if (!(logfile = fopen(F, "w"))) {\
    fprintf(stderr, "Failed to open '%s' for logging.", F);\
    exit(CODE_FILE_ERROR);\
  }\
} while (0)
#define LOG_CLOSE() do {\
  if (logfile && logfile != stderr && logfile != stdout) {\
    fclose(logfile);\
    logfile = NULL;\
  }\
} while (0)
#define LOG_T(...) fprintf(logfile, __VA_ARGS__)
#define LOG_I(...) do {\
  fprintf(logfile, "[INFO]: "); fprintf(logfile, __VA_ARGS__);\
} while (0)
#define LOG_D(...) do {\
  fprintf(logfile, "[DEBUG]: "); fprintf(logfile, __VA_ARGS__);\
} while (0)
#define LOG_W(...) do {\
  fprintf(logfile, "[WARNING]: "); fprintf(logfile, __VA_ARGS__);\
} while (0)
#define LOG_E(...) do {\
  fprintf(logfile, "[ERROR]: "); fprintf(logfile, __VA_ARGS__);\
} while (0)
#else
#define LOG_REDIRECT(F)
#define LOG_OPEN(F)
#define LOG_CLOSE()
#define LOG_T(...)
#define LOG_I(...)
#define LOG_D(...)
#define LOG_W(...)
#define LOG_E(...)
#endif



#endif
