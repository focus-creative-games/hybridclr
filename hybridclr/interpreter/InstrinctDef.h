// Copyright 2026 Code Philosophy
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include "../CommonDef.h"

namespace hybridclr
{
namespace interpreter
{

struct HtVector2f
{
    float x;
    float y;
};

static_assert(sizeof(HtVector2f) == 8, "Vector2f");

struct HtVector3f
{
    float x;
    float y;
    float z;
};

static_assert(sizeof(HtVector3f) == 12, "Vector3f");

struct HtVector4f
{
    float x;
    float y;
    float z;
    float w;
};

static_assert(sizeof(HtVector4f) == 16, "Vector4f");

struct HtVector2d
{
    double x;
    double y;
};

static_assert(sizeof(HtVector2d) == 16, "Vector2d");

struct HtVector3d
{
    double x;
    double y;
    double z;
};

static_assert(sizeof(HtVector3d) == 24, "Vector3d");

struct HtVector4d
{
    double x;
    double y;
    double z;
    double w;
};

static_assert(sizeof(HtVector4d) == 32, "Vector4d");

struct HtVector2i
{
    int32_t x;
    int32_t y;
};

static_assert(sizeof(HtVector2i) == 8, "IntVector2i");

struct HtVector3i
{
    int32_t x;
    int32_t y;
    int32_t z;
};

static_assert(sizeof(HtVector3i) == 12, "IntVector3i");

struct HtVector4i
{
    int32_t x;
    int32_t y;
    int32_t z;
    int32_t w;
};

static_assert(sizeof(HtVector4i) == 16, "IntVector4i");

#pragma endregion

} // namespace interpreter
} // namespace hybridclr
