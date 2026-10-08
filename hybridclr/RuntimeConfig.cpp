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

#include "RuntimeConfig.h"

#include "vm/Exception.h"

namespace hybridclr
{
static int32_t s_threadObjectStackSize = 1024 * 128;
static int32_t s_threadFrameStackSize = 1024 * 2;
static int32_t s_threadExceptionFlowSize = 512;
static int32_t s_maxMethodBodyCacheSize = 1024;
static int32_t s_maxMethodInlineDepth = 3;
static int32_t s_maxInlineableMethodBodySize = 32;

int32_t RuntimeConfig::GetRuntimeOption(RuntimeOptionId optionId)
{
    switch (optionId)
    {
    case RuntimeOptionId::InterpreterThreadObjectStackSize:
        return s_threadObjectStackSize;
    case RuntimeOptionId::InterpreterThreadFrameStackSize:
        return s_threadFrameStackSize;
    case RuntimeOptionId::InterpreterThreadExceptionFlowSize:
        return s_threadExceptionFlowSize;
    case RuntimeOptionId::MaxMethodBodyCacheSize:
        return s_maxMethodBodyCacheSize;
    case RuntimeOptionId::MaxMethodInlineDepth:
        return s_maxMethodInlineDepth;
    case RuntimeOptionId::MaxInlineableMethodBodySize:
        return s_maxInlineableMethodBodySize;
    default:
    {
        TEMP_FORMAT(optionIdStr, "%d", optionId);
        il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentException(optionIdStr, "invalid runtime option id"));
        return 0;
    }
    }
}

void RuntimeConfig::SetRuntimeOption(RuntimeOptionId optionId, int32_t value)
{
    switch (optionId)
    {
    case hybridclr::RuntimeOptionId::InterpreterThreadObjectStackSize:
        s_threadObjectStackSize = value;
        break;
    case hybridclr::RuntimeOptionId::InterpreterThreadFrameStackSize:
        s_threadFrameStackSize = value;
        break;
    case hybridclr::RuntimeOptionId::InterpreterThreadExceptionFlowSize:
        s_threadExceptionFlowSize = value;
        break;
    case RuntimeOptionId::MaxMethodBodyCacheSize:
        s_maxMethodBodyCacheSize = value;
        break;
    case RuntimeOptionId::MaxMethodInlineDepth:
        s_maxMethodInlineDepth = value;
        break;
    case RuntimeOptionId::MaxInlineableMethodBodySize:
        s_maxInlineableMethodBodySize = value;
        break;
    default:
    {
        TEMP_FORMAT(optionIdStr, "%d", optionId);
        il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentException(optionIdStr, "invalid runtime option id"));
        break;
    }
    }
}

uint32_t RuntimeConfig::GetInterpreterThreadObjectStackSize()
{
    return s_threadObjectStackSize;
}

uint32_t RuntimeConfig::GetInterpreterThreadFrameStackSize()
{
    return s_threadFrameStackSize;
}

uint32_t RuntimeConfig::GetInterpreterThreadExceptionFlowSize()
{
    return s_threadExceptionFlowSize;
}

int32_t RuntimeConfig::GetMaxMethodBodyCacheSize()
{
    return s_maxMethodBodyCacheSize;
}

int32_t RuntimeConfig::GetMaxMethodInlineDepth()
{
    return s_maxMethodInlineDepth;
}

int32_t RuntimeConfig::GetMaxInlineableMethodBodySize()
{
    return s_maxInlineableMethodBodySize;
}

} // namespace hybridclr
