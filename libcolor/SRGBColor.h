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
 * @file SRGBColor.h
 * @brief The SRGBColor declaration class.
 * @date 2016-08-29
 */

#ifndef RGB_COLOR_H
#define RGB_COLOR_H

#include <cstdint>
#include <vector>

namespace NSColor
{

typedef int     RGBVal;
typedef double  SRGBVal;
typedef double  Luminance;

static const RGBVal MAX_RGB_VAL = 255;

enum Colors
{
    RED = 0,
    GREEN,
    BLUE,
    // end of colors
    AMOUNT_OF_COLORS
};

class SRGBColor
{
public:
    /**
     * @brief Constructor that takes three values, one for each color.
     * @details It is assumed that each color is a valid one, meaning,
     * in range [0, 255].
     *
     * @param red The red color for this standard RGB instance.
     * @param green The green color for this estandar RGB instance.
     * @param blue The blue color for this estandar RGB instance.
     */
    SRGBColor(RGBVal red, RGBVal green, RGBVal blue);

    /**
     * @brief Constructor that takes a vector containing the three
     * required colors for a standard RGB.
     * @details It is assumed the vector is well-formed,
     * containing only three values for each color, all of them
     * in a valid range.
     *
     * @param colors A collection containing the three RGB colors.
     */
    SRGBColor(const std::vector<RGBVal>& colors);

    /**
     * @brief Gets the luminance for the this RGB color.
     * @details You can find the formula in the following link:
     * https://www.w3.org/TR/2008/REC-WCAG20-20081211/#relativeluminancedef
     *
     * @return The luminance for this color.
     */
    Luminance getLuminance() const;


private:

    /**
     * @brief Takes a value expressed in Linear RGB (belonging to
     * range [0, 255]) and returns a standard RGB value between 0 and 1.
     *
     * @param rgb The linear RGB.
     * @return The estandar RGB value.
     */
    SRGBVal _convertRGBIntoSRGSpace(RGBVal rgb) const;

    /**
     * @brief For more details, \sa
     * https://www.w3.org/TR/2008/REC-WCAG20-20081211/#relativeluminancedef
     *
     * @param rgb A standard rgb value
     * @return a standard rgb value
     */
    SRGBVal _getCorrectValueAccordingGamma(SRGBVal rgb) const;

    SRGBVal _red;
    SRGBVal _green;
    SRGBVal _blue;
};

} // end namespace

#endif // RGB_COLOR_H