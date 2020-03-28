#include "termfmt.h"
#include <iostream>
#include <initializer_list>
#include <fmt/core.h>

std::string colorExample(std::initializer_list<termfmt::TerminalFormat> colors,
        const char* name, const char* content = "Example text") {
    return fmt::format("\t{:<16s}", name) + termfmt::format(colors, content);
}
std::string colorExample(termfmt::TerminalFormat color,
        const char* name, const char* content = "Example text") {
    return colorExample({ color }, name, content);
}

int main()
{
    using namespace termfmt;
    std::cout << "========== Core color test ==========\n";
    std::cout << colorExample(FgBlack, "Black") << colorExample(BgBlack, "Black") << "\n";
    std::cout << colorExample(FgRed, "Red") << colorExample(BgRed, "Red") << "\n";
    std::cout << colorExample(FgGreen, "Green") << colorExample(BgGreen, "Green") << "\n";
    std::cout << colorExample(FgYellow, "Yellow") << colorExample(BgYellow, "Yellow") << "\n";
    std::cout << colorExample(FgBlue, "Blue") << colorExample(BgBlue, "Blue") << "\n";
    std::cout << colorExample(FgMagenta, "Magenta") << colorExample(BgMagenta, "Magenta") << "\n";
    std::cout << colorExample(FgCyan, "Cyan") << colorExample(BgCyan, "Cyan") << "\n";
    std::cout << colorExample(FgWhite, "White") << colorExample(BgWhite, "White") << "\n";
    std::cout << colorExample(FgBrightBlack, "BrightBlack")
            << colorExample(BgBrightBlack, "BrightBlack") << "\n";
    std::cout << colorExample(FgBrightRed, "BrightRed")
            << colorExample(BgBrightRed, "BrightRed") << "\n";
    std::cout << colorExample(FgBrightGreen, "BrightGreen")
            << colorExample(BgBrightGreen, "BrightGreen") << "\n";
    std::cout << colorExample(FgBrightYellow, "BrightYellow")
            << colorExample(BgBrightYellow, "BrightYellow") << "\n";
    std::cout << colorExample(FgBrightBlue, "BrightBlue")
            << colorExample(BgBrightBlue, "BrightBlue") << "\n";
    std::cout << colorExample(FgBrightMagenta, "BrightMagenta")
            << colorExample(BgBrightMagenta, "BrightMagenta") << "\n";
    std::cout << colorExample(FgBrightCyan, "BrightCyan")
            << colorExample(BgBrightCyan, "BrightCyan") << "\n";
    std::cout << colorExample(FgBrightWhite, "BrightWhite")
            << colorExample(BgBrightWhite, "BrightWhite") << "\n";

    std::cout << "Common combinations:\n";
    std::cout << colorExample({ FgBlack, BgWhite }, "Black on white") << "\n";
    std::cout << colorExample({ FgYellow, BgBlack }, "Yellow on black") << "\n";
    std::cout << colorExample({ FgWhite, BgBlack }, "White on black") << "\n";
    std::cout << colorExample({ FgGreen, BgBlack }, "Green on black") << "\n";
    std::cout << colorExample({ FgWhite, BgBlue }, "White on blue") << "\n";
    return 0;
}