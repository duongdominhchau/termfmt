#include "termfmt.h"
#include <iostream>
#include <fmt/core.h>

void testSingleFormat()
{
    using namespace Terminal;
    std::cout << "Bold: " << Terminal::format({ Bold }, "Bold\n");
    std::cout << "Dim: " << Terminal::format({ Dim }, "Dim\n");
    std::cout << "Italic: " << Terminal::format({ Italic }, "Italic\n");
    std::cout << "Strikethrough: " << Terminal::format({ Strikethrough }, "Strikethrough\n");
    std::cout << "Underline: " << Terminal::format({ Underline }, "Underline\n");
    std::cout << "Invert: " << Terminal::format({ Invert }, "Invert\n");
    std::cout << "Conceal: " << Terminal::format({ Conceal }, "Conceal\n");
}
void testCombinedTwoFormats()
{
    using namespace Terminal;
    std::cout << "Bold, dim: " << Terminal::format({ Bold, Dim }, "Example text\n");
    std::cout << "Bold, italic: " << Terminal::format({ Bold, Italic }, "Example text\n");
    std::cout << "Bold, strikethrough: " << Terminal::format({ Bold, Strikethrough }, "Example text\n");
    std::cout << "Bold, underline: " << Terminal::format({ Bold, Underline }, "Example text\n");
    std::cout << "Bold, invert: " << Terminal::format({ Bold, Invert }, "Example text\n");

    std::cout << "Dim, italic: " << Terminal::format({ Dim, Italic }, "Example text\n");
    std::cout << "Dim, strikethrough: " << Terminal::format({ Dim, Strikethrough }, "Example text\n");
    std::cout << "Dim, underline: " << Terminal::format({ Dim, Underline }, "Example text\n");
    std::cout << "Dim, invert: " << Terminal::format({ Dim, Invert }, "Example text\n");

    std::cout << "Italic, strikethrough: " << Terminal::format({ Italic, Strikethrough }, "Example text\n");
    std::cout << "Italic, underline: " << Terminal::format({ Italic, Underline }, "Example text\n");
    std::cout << "Italic, invert: " << Terminal::format({ Italic, Invert }, "Example text\n");

    std::cout << "Strikethrough, underline: " << Terminal::format({ Strikethrough, Underline }, "Example text\n");
    std::cout << "Strikethrough, invert: " << Terminal::format({ Strikethrough, Invert }, "Example text\n");

    std::cout << "Underline, invert: " << Terminal::format({ Underline, Invert }, "Example text\n");
}
void testFormat()
{
    using namespace Terminal;
    testSingleFormat();
    testCombinedTwoFormats();
    std::cout << "Bold, Dim, Italic, Strikethrough, Underline: " << Terminal::format({ Bold, Dim, Italic, Strikethrough, Underline }, "Example text\n");
    std::cout << "Bold, Dim, Italic, Strikethrough, Underline, Invert: " << Terminal::format({ Bold, Dim, Italic, Strikethrough, Underline, Invert }, "Example text\n");
    std::cout << "Done\n";
}

void testCoreColor()
{
    using namespace Terminal;
    std::cout << "Foreground:\n";
    std::cout << "\tBlack: " << Terminal::format({ FgBlack }, "Example text\n");
    std::cout << "\tRed: " << Terminal::format({ FgRed }, "Example text\n");
    std::cout << "\tGreen: " << Terminal::format({ FgGreen }, "Example text\n");
    std::cout << "\tYellow: " << Terminal::format({ FgYellow }, "Example text\n");
    std::cout << "\tBlue: " << Terminal::format({ FgBlue }, "Example text\n");
    std::cout << "\tMagenta: " << Terminal::format({ FgMagenta }, "Example text\n");
    std::cout << "\tCyan: " << Terminal::format({ FgCyan }, "Example text\n");
    std::cout << "\tWhite: " << Terminal::format({ FgWhite }, "Example text\n");

    std::cout << "Bright foreground:\n";
    std::cout << "\tBright black: " << Terminal::format({ FgBrightBlack }, "Example text\n");
    std::cout << "\tBright green: " << Terminal::format({ FgBrightGreen }, "Example text\n");
    std::cout << "\tBright yellow: " << Terminal::format({ FgBrightYellow }, "Example text\n");
    std::cout << "\tBright blue: " << Terminal::format({ FgBrightBlue }, "Example text\n");
    std::cout << "\tBright magenta: " << Terminal::format({ FgBrightMagenta }, "Example text\n");
    std::cout << "\tBright cyan: " << Terminal::format({ FgBrightCyan }, "Example text\n");
    std::cout << "\tBright white: " << Terminal::format({ FgBrightWhite }, "Example text\n");

    std::cout << "Background:\n";
    std::cout << "\tBlack: " << Terminal::format({ FgBrightBlack, BgBlack }, "Example text") << "\n";
    std::cout << "\tRed: " << Terminal::format({ FgBrightBlack, BgRed }, "Example text") << "\n";
    std::cout << "\tGreen: " << Terminal::format({ FgBrightBlack, BgGreen }, "Example text") << "\n";
    std::cout << "\tYellow: " << Terminal::format({ FgBrightBlack, BgYellow }, "Example text") << "\n";
    std::cout << "\tBlue: " << Terminal::format({ FgBrightBlack, BgBlue }, "Example text") << "\n";
    std::cout << "\tMagenta: " << Terminal::format({ FgBrightBlack, BgMagenta }, "Example text") << "\n";
    std::cout << "\tCyan: " << Terminal::format({ FgBrightBlack, BgCyan }, "Example text") << "\n";
    std::cout << "\tWhite: " << Terminal::format({ FgBrightBlack, BgWhite }, "Example text") << "\n";

    std::cout << "Bright background:\n";
    std::cout << "\tBright black: " << Terminal::format({ FgBlack, BgBrightBlack }, "Example text") << "\n";
    std::cout << "\tBright red: " << Terminal::format({ FgBlack, BgBrightRed }, "Example text") << "\n";
    std::cout << "\tBright green: " << Terminal::format({ FgBlack, BgBrightGreen }, "Example text") << "\n";
    std::cout << "\tBright yellow: " << Terminal::format({ FgBlack, BgBrightYellow }, "Example text") << "\n";
    std::cout << "\tBright blue: " << Terminal::format({ FgBlack, BgBrightBlue }, "Example text") << "\n";
    std::cout << "\tBright magenta: " << Terminal::format({ FgBlack, BgBrightMagenta }, "Example text") << "\n";
    std::cout << "\tBright cyan: " << Terminal::format({ FgBlack, BgBrightCyan }, "Example text") << "\n";
    std::cout << "\tBright white: " << Terminal::format({ FgBlack, BgBrightWhite }, "Example text") << "\n";

    std::cout << "Common combinations:\n";
    std::cout << "\tBlack on white: " << Terminal::format({ FgBlack, BgWhite }, "Example text") << "\n";
    std::cout << "\tBlue on white: " << Terminal::format({ FgBlue, BgWhite }, "Example text") << "\n";
    std::cout << "\tWhite on black: " << Terminal::format({ FgWhite, BgBlack }, "Example text") << "\n";
    std::cout << "\tGreen on black: " << Terminal::format({ FgGreen, BgBlack }, "Example text") << "\n";
    std::cout << "\tWhite on blue: " << Terminal::format({ FgWhite, BgBlue }, "Example text") << "\n";
}
void test8bitColor()
{
    using namespace Terminal;
    std::cout << "8-bit colors:\n";
    std::cout << "* Core:\n";
    for (int i = 0; i < 16; ++i) {
        std::cout << "\t" << fmt::format("{:3d}", i) << ": "
            << Terminal::format({ Fg8bit(i) }, "Example text") << " "
            << Terminal::format({ Bg8bit(i) }, "Example text") << "\n";
    }
    std::cout << "* Color:\n";
    for (int i = 16; i < 232; ++i) {
        std::cout << "\t" << fmt::format("{:3d}", i) << ": "
            << Terminal::format({ Fg8bit(i) }, "Example text") << " "
            << Terminal::format({ Bg8bit(i) }, "Example text") << "\n";
    }
    std::cout << "* Grayscale:\n";
    for (int i = 232; i < 256; ++i) {
        std::cout << "\t" << fmt::format("{:3d}", i) << ": "
            << Terminal::format({ Fg8bit(i) }, "Example text") << " "
            << Terminal::format({ Bg8bit(i) }, "Example text") << "\n";
    }
}
void test24bitColor()
{
    using namespace Terminal;
    std::cout << "RGB colors:\n";
    std::cout << "* Red variations:\n";
    for (int i = 0; i < 256; ++i) {
        std::cout << "\t" << fmt::format("{:3d}", i) << ": "
            << Terminal::format({ Fg24bit(i, 0, 0) }, "Example text") << " "
            << Terminal::format({ Bg24bit(i, 0, 0) }, "Example text") << "\n";
    }
    std::cout << "* Green variations:\n";
    for (int i = 0; i < 256; ++i) {
        std::cout << "\t" << fmt::format("{:3d}", i) << ": "
            << Terminal::format({ Fg24bit(0, i, 0) }, "Example text") << " "
            << Terminal::format({ Bg24bit(0, i, 0) }, "Example text") << "\n";
    }
    std::cout << "* Blue variations:\n";
    for (int i = 0; i < 256; ++i) {
        std::cout << "\t" << fmt::format("{:3d}", i) << ": "
            << Terminal::format({ Fg24bit(0, 0, i) }, "Example text") << " "
            << Terminal::format({ Bg24bit(0, 0, i) }, "Example text") << "\n";
    }
}
void testColor()
{
    testCoreColor();
    test8bitColor();
    test24bitColor();
}

void testFormatWithColor()
{
    using namespace Terminal;
    std::cout << Terminal::format({ Bold, Underline, Italic, FgBrightYellow, BgBlue }, "Example text") << "\n";
}

int main()
{
    testFormat();
    testColor();
    testFormatWithColor();
    return 0;
}