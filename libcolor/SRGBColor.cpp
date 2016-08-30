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
 * @file SRGBColor.cpp
 * @brief The SRGBColor class definition.
 * @date 2016-08-29
 */

#include "SRGBColor.h"
#include "mathUtils.h"

namespace NSColor
{

static const SRGBVal RED_LUMINANCE   = 0.2126;
static const SRGBVal GREEN_LUMINANCE = 0.7152;
static const SRGBVal BLUE_LUMINANCE  = 0.0722;

static const SRGBVal GAMMA_AT_MAX_DENSITY = 2.4;


SRGBColor::SRGBColor(const RGBVal red, const RGBVal green, const RGBVal blue) :
    _red(_convertRGBIntoSRGSpace(red)),
    _green(_convertRGBIntoSRGSpace(green)),
    _blue(_convertRGBIntoSRGSpace(blue))
{}

SRGBColor::SRGBColor(const std::vector<RGBVal>& colors) :
    _red(_convertRGBIntoSRGSpace(colors[Colors::RED])),
    _green(_convertRGBIntoSRGSpace(colors[Colors::GREEN])),
    _blue(_convertRGBIntoSRGSpace(colors[Colors::BLUE]))
{}

Luminance SRGBColor::getLuminance() const
{
    return (RED_LUMINANCE   * _getCorrectValueAccordingGamma(_red))   +
           (GREEN_LUMINANCE * _getCorrectValueAccordingGamma(_green)) +
           (BLUE_LUMINANCE  * _getCorrectValueAccordingGamma(_blue));
}


SRGBVal SRGBColor::_convertRGBIntoSRGSpace(const RGBVal rgb) const
{
    return rgb / (SRGBVal) MAX_RGB_VAL;
}

SRGBVal SRGBColor::_getCorrectValueAccordingGamma(const SRGBVal rgb) const
{
    static const SRGBVal CUTOFF_SLOPE = 0.03928;

    if (rgb < CUTOFF_SLOPE || NSUtils::is_near_zero(rgb - CUTOFF_SLOPE))
    {
        return rgb / 12.92;
    }
    else
    {
        return std::pow( (rgb + 0.055) / 1.055, GAMMA_AT_MAX_DENSITY );
    }
}


} // end namespace