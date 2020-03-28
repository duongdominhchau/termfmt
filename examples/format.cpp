#include "termfmt.h"
#include <iostream>
#include <fmt/core.h>

int main()
{
    using namespace termfmt;
    std::cout << "========== Format test ==========\n";
    std::cout << "Normal "
            << termfmt::format({ Bold }, "Bold") << " "
            << termfmt::format({ Dim }, "Dim") << " "
            << termfmt::format({ Italic }, "Italic") << " "
            << termfmt::format({ Strikethrough }, "Strikethrough") << " "
            << termfmt::format({ Underline }, "Underline") << " "
            << termfmt::format({ Conceal }, "Conceal") << " "
            << termfmt::format({ Invert }, "Invert") << "\n";
    std::cout << termfmt::format({ Bold, Dim }, "BoldDim") << " "
            << termfmt::format({ Bold, Italic }, "BoldItalic") << " "
            << termfmt::format({ Bold, Strikethrough }, "BoldStrikethrough") << " "
            << termfmt::format({ Bold, Underline }, "BoldUnderline") << " "
            << termfmt::format({ Bold, Invert }, "BoldInvert") << "\n";
    std::cout << termfmt::format({ Dim, Italic }, "DimItalic") << " "
            << termfmt::format({ Dim, Strikethrough }, "DimStrikethrough") << " "
            << termfmt::format({ Dim, Underline }, "DimUnderline") << " "
            << termfmt::format({ Dim, Invert }, "DimInvert") << "\n";
    std::cout << termfmt::format({ Italic, Strikethrough }, "ItalicStrikethrough") << " "
            << termfmt::format({ Italic, Underline }, "ItalicUnderline") << " "
            << termfmt::format({ Italic, Invert }, "ItalicInvert") << "\n";
    std::cout << termfmt::format({ Strikethrough, Underline }, "StrikethroughUnderline") << " "
            << termfmt::format({ Strikethrough, Invert }, "StrikethroughInvert") << "\n";
    std::cout << termfmt::format({ Underline, Invert }, "UnderlineInvert") << "\n";
    std::cout << termfmt::format({ Bold, Dim, Italic, Strikethrough, Underline },
            "BoldDimItalicStrikethroughUnderline") << "\n";
    std::cout << termfmt::format({ Bold, Dim, Italic, Strikethrough, Underline, Invert },
            "BoldDimItalicStrikethroughUnderlineInvert") << "\n";
    std::cout << "Done\n";
    return 0;
}
