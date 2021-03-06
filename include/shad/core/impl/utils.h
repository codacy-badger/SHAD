//===------------------------------------------------------------*- C++ -*-===//
//
//                                     SHAD
//
//      The Scalable High-performance Algorithms and Data Structure Library
//
//===----------------------------------------------------------------------===//
//
// Copyright 2018 Battelle Memorial Institute
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy
// of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations
// under the License.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDE_SHAD_CORE_IMPL_UTILS_H
#define INCLUDE_SHAD_CORE_IMPL_UTILS_H

#include <algorithm>
#include <functional>
#include <iterator>
#include "shad/core/iterator.h"
#include "shad/distributed_iterator_traits.h"
#include "shad/runtime/runtime.h"

namespace shad {
namespace impl {

template <typename It, typename It2>
void advance_output_iterator(It &it, It2 first, It2 last) {
  std::advance(it, std::distance(first, last));
}

template <typename T, typename It2>
void advance_output_iterator(shad::insert_iterator<T> &, It2, It2) {}

template <typename T, typename It2>
void advance_output_iterator(shad::buffered_insert_iterator<T>, It2, It2) {}

template <typename It>
void flush_iterator(It &) {}

template <typename T>
void flush_iterator(shad::buffered_insert_iterator<T> &it) {
  it.flush();
}

}  // namespace impl
}  // namespace shad

#endif /* INCLUDE_SHAD_CORE_IMPL_UTILS_H */
