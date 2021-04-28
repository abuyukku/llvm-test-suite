//==-------------- spec_const_int64.cpp  - DPC++ ESIMD on-device test -----===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// REQUIRES: gpu
// On Windows vector compute backend (as a part of IGC) uses llvm-7 and llvm-7
// based spirv translator. This translator doesn't have the ability to overwrite
// the default specialization constant value. That is why the support in Windows
// driver is disabled at all. This feature will start working on Windows when
// the llvm version is switched to 9.
// UNSUPPORTED: windows
// RUN: %clangxx -fsycl -I%S/.. %s -o %t.out
// RUN: %GPU_RUN_PLACEHOLDER %t.out
// UNSUPPORTED: cuda

#include <cstdint>

#define DEF_VAL -99776644220011ll
#define REDEF_VAL 22001144668855ll
#define STORE 1

using spec_const_t = int64_t;
using container_t = int64_t;

#include "Inputs/spec_const_common.hpp"