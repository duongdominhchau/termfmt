#include "termfmt.h"
#include <iostream>
#include <fmt/core.h>

std::string colorExample(int maxlen, int r, int g, int b)
{
    return fmt::format("{:<{}} {} {}",
            fmt::format("{},{},{}", r, g, b), maxlen,
            termfmt::format({ termfmt::FgRgb(r, g, b) }, "Text"),
            termfmt::format({ termfmt::BgRgb(r, g, b) }, "Text"));
}
int main()
{
    using namespace termfmt;
    std::cout << "========== RGB color test ==========\n";
    for (int i = 0; i < 256; ++i) {
        std::cout << colorExample(7, i, 0, 0) << " "
                << colorExample(7, 0, i, 0) << " "
                << colorExample(7, 0, 0, i) << " "
                << colorExample(10, i, i / 2, i / 3) << "\n";
    }
    return 0;
}
