#pragma once
#include "Vector2.h"

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

namespace nu
{

    struct ENGINE_API Transform {
        Vector2 position;
        float rotation;
        float scale;
        Vector2 velocity;
    };
}