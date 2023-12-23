#pragma once
#include "glad/glad.h"
#include <assert.h>

#define ASSERT(x) if (!(x)) assert(false)

#define glCall(x) glClearError();\
    x;\
    ASSERT(glCheckError())

void glClearError();
bool glCheckError();