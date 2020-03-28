#include "termfmt.h"
#include <iostream>
#include <fmt/core.h>

std::string colorExample(int r, int g, int b)
{
    return fmt::format("{:3d},{:3d},{:3d}: {} {}", r, g, b,
            termfmt::format({ termfmt::FgRgb(r, g, b) }, "Text"),
            termfmt::format({ termfmt::BgRgb(r, g, b) }, "Text"));
}
int main()
{
    using namespace termfmt;
    std::cout << "========== RGB color test ==========\n";
    for (int i = 0; i < 256; ++i) {
        std::cout << colorExample(i, 0, 0) << " "
                << colorExample(0, i, 0) << " "
                << colorExample(0, 0, i) << " "
                << colorExample(i, i / 2, i / 3) << "\n";
    }
    return 0;
}