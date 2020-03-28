#include "termfmt.h"
#include <iostream>
#include <fmt/core.h>

int main()
{
    using namespace termfmt;
    std::cout << "========== 8-bit color test ==========\n";
    std::cout << "* Core:\n";
    for (int i = 0; i < 16; ++i) {
        std::cout << "\t" << fmt::format("{:3d}: ", i)
            << termfmt::format({ Fg8bit(i) }, "Example text") << " "
            << termfmt::format({ Bg8bit(i) }, "Example text") << "\n";
    }
    std::cout << "* Color:\n";
    for (int i = 16; i < 232; ++i) {
        std::cout << "\t" << fmt::format("{:3d}: ", i)
            << termfmt::format({ Fg8bit(i) }, "Example text") << " "
            << termfmt::format({ Bg8bit(i) }, "Example text") << "\n";
    }
    std::cout << "* Grayscale:\n";
    for (int i = 232; i < 256; ++i) {
        std::cout << "\t" << fmt::format("{:3d}: ", i)
            << termfmt::format({ Fg8bit(i) }, "Example text") << " "
            << termfmt::format({ Bg8bit(i) }, "Example text") << "\n";
    }
    return 0;
}