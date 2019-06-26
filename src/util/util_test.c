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

#ifndef UTIL_TEST_C
#define UTIL_TEST_C

#include <testing.h>

#include <list.h>

typedef struct {
    Array array;
} UtilTestSuite;

typedef struct {
    float position[3];
    float texture[2];
} ArrayData;

int create_util_suite(UtilTestSuite *suite) {
    array_allocate(&suite->array, 0, sizeof(ArrayData));
    ASSERT(suite->array.data != NULL);
    ASSERT(suite->array.size == 0);
    ASSERT(suite->array.data_size == sizeof(ArrayData));
    ASSERT(suite->array.capacity == 0);
    return 0;
}

int destroy_util_suite(UtilTestSuite *suite) {
    array_delete(&suite->array);
    ASSERT(suite->array.data == NULL);
    return 0;
}

int test_array_add(UtilTestSuite *suite) {
    ArrayData data;
    data.position[0] = 1.0f;
    data.position[1] = 2.0f;
    data.position[2] = 3.0f;
    data.texture[0] = 0.0f;
    data.texture[1] = 1.0f;

    array_add(&suite->array, &data);
    ASSERT(suite->array.size == 1);
    ASSERT(suite->array.capacity == GROWTH_FACTOR);
    ASSERT(suite->array.data != NULL);

    ArrayData* result = NULL;
    result = array_get(&suite->array, 0);
    ASSERT(result != NULL);
    ASSERT(result->position[0] == 1.0f);
    ASSERT(result->position[1] == 2.0f);
    ASSERT(result->position[2] == 3.0f);
    ASSERT(result->texture[0] == 0.0f);
    ASSERT(result->texture[1] == 1.0f);
    return 0;
}

int test_util() {
    UtilTestSuite *suite = malloc(sizeof(UtilTestSuite));

    int (*test_funcs[])(UtilTestSuite*) = {
            test_array_add,
    };

    char* names[] = {
            "array_add",
    };

    for (int i = 0; i < sizeof(test_funcs) / sizeof(test_funcs[0]); i++) {
        TEST_START(names[i]);
        VERIFY(create_util_suite, suite);
        VERIFY(test_funcs[i], suite);
        VERIFY(destroy_util_suite, suite);
        TEST_END();
    }

    free(suite);
    return 0;
}

#endif