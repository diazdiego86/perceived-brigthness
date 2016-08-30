/**
 * Copyright (C) Diego Alejandro Diaz.
 * Distributed under the MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * @file mathUtils.h
 * @brief Declaration of utilitarian methods for general purposes.
 * @date 2016-08-29
 */


#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <cmath>

namespace NSUtils
{

/**
 * @brief Checks if \p val is in the range of \p min and \p max.
 *
 * @param val   The value
 * @param min   The minimum
 * @param max   The maximum
 * @return     True if val belongs to [0, 255]. False, otherwise.
 */
template <class T>
inline bool in_range(T val, T min, T max)
{
    return (min <= val) && (val <= max);
}

/**
 * @brief Checks if a number \p x is smaller than an epsilon.
 * @details We need this to check if two double values are
 * "equal" if they are within one scaled epsilon of each other.
 *
 * @param  x: a number.
 * @param  tolerance: the epsilon.
 */
template <class T>
inline bool is_near_zero(T x, T tolerance = T(10e-6))
{
    return std::abs(x) < tolerance;
}

} // end namespace

#endif // MATH_UTILS_H