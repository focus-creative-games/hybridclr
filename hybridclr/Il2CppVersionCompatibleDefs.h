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
#include "./generated/UnityVersion.inc"

#ifndef HYBRIDCLR_UNITY_VERSION
#error "please run 'HybridCLR/Generate/All' before building"
#endif

#if HYBRIDCLR_UNITY_VERSION < 20220300
#error "unsupported unity version, minimum supported version is 2022.3.0"
#endif

#if HYBRIDCLR_UNITY_VERSION >= 20220000 && HYBRIDCLR_UNITY_VERSION < 20230000
#define HYBRIDCLR_UNITY_2022 1
#endif

#if HYBRIDCLR_UNITY_VERSION >= 20220311
#define HYBRIDCLR_IL2CPP_ACTIVE_EXCEPTION_POP_WITH_RET 1
#else
#define HYBRIDCLR_IL2CPP_ACTIVE_EXCEPTION_POP_WITH_RET 0
#endif

#if HYBRIDCLR_UNITY_VERSION >= 20230000 && HYBRIDCLR_UNITY_VERSION < 60000000
#error "2023.x.y is not supported"
#endif

#if HYBRIDCLR_UNITY_VERSION >= 60000000 && HYBRIDCLR_UNITY_VERSION < 70000000
#define HYBRIDCLR_UNITY_6000 1

#if HYBRIDCLR_UNITY_VERSION < 60000100
#define HYBRIDCLR_UNITY_6000_0_X 1
#elif HYBRIDCLR_UNITY_VERSION < 60000200
#error "6000.1.x is not supported"
#elif HYBRIDCLR_UNITY_VERSION < 60000300
#error "6000.2.x is not supported"
#elif HYBRIDCLR_UNITY_VERSION < 60000400
#define HYBRIDCLR_UNITY_6000_3_X 1
#elif HYBRIDCLR_UNITY_VERSION < 60000500
#error "6000.4.x is not supported"
#elif HYBRIDCLR_UNITY_VERSION < 60000600
#error "6000.5.x is not supported"
#elif HYBRIDCLR_UNITY_VERSION < 60000700
#error "6000.6.x is not supported"
#else
#error "6000.7.x or newer LTS version will be supported in the future"
#endif

#endif

#if HYBRIDCLR_UNITY_VERSION >= 20220000
#define HYBRIDCLR_UNITY_2022_OR_NEWER 1
#endif

#if HYBRIDCLR_UNITY_VERSION >= 60000000
#define HYBRIDCLR_UNITY_6000_OR_NEWER 1
#define HYBRIDCLR_UNITY_6000_0_X_OR_NEWER 1
#endif

#if HYBRIDCLR_UNITY_VERSION >= 60000300
#define HYBRIDCLR_UNITY_6000_3_X_OR_NEWER 1
#endif

#if HYBRIDCLR_UNITY_VERSION >= 60000500
#define HYBRIDCLR_UNITY_6000_5_X_OR_NEWER 1
#endif

#if HYBRIDCLR_UNITY_2022 && HYBRIDCLR_UNITY_VERSION >= 20220333
// in unity 2022.3.33+, method return type custom attribute is supported
#define SUPPORT_METHOD_RETURN_TYPE_CUSTOM_ATTRIBUTE 1
#elif HYBRIDCLR_UNITY_6000_0_X && HYBRIDCLR_UNITY_VERSION >= 60000010
// in unity 6000.0.10+, method return type custom attribute is supported
#define SUPPORT_METHOD_RETURN_TYPE_CUSTOM_ATTRIBUTE 1
#elif HYBRIDCLR_UNITY_6000_3_X && HYBRIDCLR_UNITY_VERSION >= 60000300
// in unity 6000.3.x+, method return type custom attribute is supported
#define SUPPORT_METHOD_RETURN_TYPE_CUSTOM_ATTRIBUTE 1
#else
#define SUPPORT_METHOD_RETURN_TYPE_CUSTOM_ATTRIBUTE 0
#endif