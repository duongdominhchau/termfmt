#include "termfmt.h"
#include <iostream>
#include <fmt/core.h>

int main()
{
    using namespace termfmt;
    const int red = 100;
    const int green = 150;
    const int blue = 50;
    for (int i = 0; i < 256; ++i) {
        std::cout << fmt::format("{:3d},{:3d},{:3d}: ", red, i, blue)
            << termfmt::format({ FgRgb(red, i, blue) }, "Example text") << " "
            << termfmt::format({ BgRgb(red, i, blue) }, "Example text") << "\t"
            << fmt::format("{:3d},{:3d},{:3d}: ", red, green, i)
            << termfmt::format({ FgRgb(red, green, i) }, "Example text") << " "
            << termfmt::format({ BgRgb(red, green, i) }, "Example text") << "\n";
    }
    return 0;
}