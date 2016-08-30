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
 * @brief Unit tests for SRGColor class.
 * @date 2016-08-29
 */


#include "gtest/gtest.h"
#include "SRGBColor.h"

using namespace NSColor;

const double EQ_TOLERANCE = 10e-6;

TEST(RGBColorTests, RGBColor_constructor)
{
    SRGBColor color(255, 255, 255);

    EXPECT_NEAR(color.getLuminance(), 1.0, EQ_TOLERANCE);
}

TEST(RGBColorTests, RGBColor_vectorConstructor)
{
    std::vector<RGBVal> colors {0, 0, 0};
    SRGBColor color(colors);

    EXPECT_NEAR(color.getLuminance(), 0.0, EQ_TOLERANCE);
}

TEST(RGBColorTests, RGBColor_perceivedBrightnessForGreen)
{
    SRGBColor color(0, 255, 0);

    EXPECT_NEAR(color.getLuminance(), 0.7152, EQ_TOLERANCE);
}

TEST(RGBColorTests, RGBColor_perceivedBrightnessForRed)
{
    SRGBColor color(255, 0, 0);

    EXPECT_NEAR(color.getLuminance(), 0.2126, EQ_TOLERANCE);
}

TEST(RGBColorTests, RGBColor_perceivedBrightnessForBlue)
{
    SRGBColor color(0, 0, 255);

    EXPECT_NEAR(color.getLuminance(), 0.0722, EQ_TOLERANCE);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
