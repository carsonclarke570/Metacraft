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

#ifndef TESTING_H
#define TESTING_H

#include <stdio.h>

#define FAIL printf("\tFAIL\n\t\t%s\t%s:%d\n", __func__, __FILE__, __LINE__)
#define TEST_START(test) printf("\tTEST %s:", test)
#define TEST_END() printf("\tPASS\n")
#define ASSERT(test) do { if (!(test)) { FAIL; return 1; }} while(0)
#define VERIFY(test, suite) do { int r = test(suite); if (r) { free(suite); return r;} } while(0)
#define VERIFY_MODULE(test) do { int r = test(); if (r) return r; } while(0)

#ifdef ENABLE_UNIT_TESTING
    #define UNIT_TEST()                 \
        VERIFY_MODULE(test_util);       \
        printf("\n");                   \
        return 0

#else
    #define UNIT_TEST()
#endif

// Module tests
int test_util();

#endif
