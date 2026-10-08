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

#include <iostream>

#include "CommonDef.h"

namespace hybridclr
{
void LogPanic(const char* errMsg)
{
    std::cerr << "panic:" << std::endl;
    std::cerr << "\t" << errMsg << std::endl;
    exit(1);
}

const char* GetAssemblyNameFromPath(const char* assPath)
{
    const char* last = nullptr;
    for (const char* p = assPath; *p; p++)
    {
        if (*p == '/' || *p == '\\')
        {
            last = p + 1;
        }
    }
    return last ? last : assPath;
}

const char* CopyString(const char* src)
{
    size_t len = std::strlen(src);
    char* dst = (char*)HYBRIDCLR_MALLOC(len + 1);
    std::strcpy(dst, src);
    return dst;
}

const char* ConcatNewString(const char* s1, const char* s2)
{
    size_t len1 = std::strlen(s1);
    size_t len = len1 + std::strlen(s2);
    char* dst = (char*)HYBRIDCLR_MALLOC(len + 1);
    std::strcpy(dst, s1);
    strcpy(dst + len1, s2);
    return dst;
}

void* CopyBytes(const void* src, size_t length)
{
    void* dst = HYBRIDCLR_MALLOC(length);
    std::memcpy(dst, src, length);
    return dst;
}
} // namespace hybridclr
