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
 * @file main.cpp
 * @brief The main function
 * @date 2016-08-29
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <getopt.h>

#include "SRGBColor.h"
#include "mathUtils.h"

using namespace NSColor;
using namespace NSUtils;

static const int NO_MORE_OPTIONS = -1;
static const unsigned int REQUIRED_ARGS = 5u;

static void showHelpMessage()
{
    std::cout << "\n\nperceived-brightness: a relative luminance calculator.\n";
    std::cout << "Usage:\n \tperceived-brightness -c [red green blue]\n";
    std::cout << "\tFor example:\n";
    std::cout << "\t\t ./perceived-brightness -c 255 255 255\n";
    std::cout << "\nOther options: \n";
    std::cout << "\t-h Prints this help message." << std::endl;
}


static bool getColors(const int numberOfArgs, char** arguments, const int startIndex, std::vector<RGBVal>& colors)
{
    RGBVal val;
    bool convertionOk = true;
    unsigned int i = startIndex;

    while(i < numberOfArgs && convertionOk)
    {
        std::stringstream convert(arguments[i]);
        if ((convert >> val) && in_range<RGBVal>(val, 0, MAX_RGB_VAL))
            colors.push_back(val);
         else
            convertionOk = false;

        i++;
    }
    return convertionOk;
}


int execPerceivedBrightness(const int numberOfArgs, char** arguments, const int optionIndex)
{
    int retVal = 0;
    std::vector<RGBVal> colors;
    if (getColors(numberOfArgs, arguments, optionIndex, colors))
    {
        if (colors.size() == AMOUNT_OF_COLORS)
        {
            SRGBColor color(colors);

            std::cout << "\nperceived brightness is: ";
            std::cout.precision(4); // This is only to show four numbers after the decimal point
            std::cout << color.getLuminance() << std::endl;
        }
        else
        {
            retVal = -1;
            std::cout << "\nYou forgot to enter the rest of the numbers. ";
            std::cout << "For more info, try -h for help\n";
        }
    }
    else
    {
        retVal = -1;
        std::cout << "\nYou must enter three positive integer values, from 0 to 255. ";
        std::cout << "For more info, try -h for help\n";
    }

    return retVal;
}

int main(int argc, char** argv)
{
    if (argc > 1 && argc <= REQUIRED_ARGS)
    {
        int option;
        while ((option = getopt(argc, argv, "c:h")) != NO_MORE_OPTIONS)
        {
            switch (option)
            {
            case 'c':
                return execPerceivedBrightness(argc, argv, optind-1);

            case 'h':
            default:
                showHelpMessage();
                break;
            }
        }
    }
    else
    {
        showHelpMessage();
    }

    return 0;
}