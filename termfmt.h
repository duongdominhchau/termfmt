#ifndef TERMFMT_H
#define TERMFMT_H

#include <set>
#include <fmt/core.h>
// Delete the line above and use standard library if available:
// #include <format>

bool inRange(int value, int min, int max)
{
    return min <= value && value <= max;
}

namespace termfmt {

// Control
/**
 * @brief Move the cursor up
 * 
 * @param n Number of lines to move up. This must be a positive number.
 * @return The ANSI escape sequence or empty string if the argument is invalid
 */
std::string CursorUp(int n = 1)
{
    if (n < 1)
        return "";
    if (n == 1)
        return "\e[A";
    return fmt::format("\e[{}A", n);
}
/**
 * @brief Move the cursor down
 * 
 * @param n Number of lines to move down. This must be a positive number.
 * @return The ANSI escape sequence or empty string if the argument is invalid
 */
std::string CursorDown(int n = 1)
{
    if (n < 1)
        return "";
    if (n == 1)
        return "\e[B";
    return fmt::format("\e[{}B", n);
}
/**
 * @brief Move the cursor to the right
 * 
 * @param n Number of columns to move right. This must be a positive number.
 * @return The ANSI escape sequence or empty string if the argument is invalid
 */
std::string CursorForward(int n = 1)
{
    if (n < 1)
        return "";
    if (n == 1)
        return "\e[C";
    return fmt::format("\e[{}C", n);
}
/**
 * @brief Move the cursor to the left
 * 
 * @param n Number of columns to move left. This must be a positive number.
 * @return The ANSI escape sequence or empty string if the argument is invalid
 */
std::string CursorBack(int n = 1)
{
    if (n < 1)
        return "";
    if (n == 1)
        return "\e[D";
    return fmt::format("\e[{}D", n);
}
/**
 * @brief Move the cursor down a number of lines and put the cursor at the
 *        beginning of that line
 * 
 * @param n The number of line to move down. This must be a positive number.
 * @return The ANSI escape sequence or empty string if the argument is invalid
 */
std::string CursorNextLine(int n = 1)
{
    if (n < 1)
        return "";
    if (n == 1)
        return "\e[E";
    return fmt::format("\e[{}E", n);
}
/**
 * @brief Move the cursor up a number of lines and put the cursor at the
 *        beginning of that line
 * 
 * @param n The number of line to move up. This must be a positive number.
 * @return The ANSI escape sequence or empty string if the argument is invalid
 */
std::string CursorPreviousLine(int n = 1)
{
    if (n < 1)
        return "";
    if (n == 1)
        return "\e[F";
    return fmt::format("\e[{}F", n);
}
/**
 * @brief Put the cursor at a specific column (1-based value) of current line.
 * 
 * @param col The column to move the cursor to. This must be a positive number.
 * @return The ANSI escape sequence or empty string if the argument is invalid
 */
std::string CursorToColumn(int col = 1)
{
    if (col < 1)
        return "";
    if (col == 1)
        return "\e[G";
    return fmt::format("\e[{}G", col);
}
/**
 * @brief Move the cursor to a specific line and column on the screen.
 *        All values are 1-based.
 * 
 * @param line The line to move the cursor to. This must be a positive number.
 * @param col The column to move the cursor to. This must be a positive number.
 * @return The ANSI escape sequence or empty string if any argument is invalid
 */
std::string CursorToPosition(int line = 1, int col = 1)
{
    if (line < 1 || col < 1)
        return "";
    if (line == 1 && col == 1)
        return "\e[H";
    if (line == 1)
        return fmt::format("\e[;{}H", col);
    if (col == 1)
        return fmt::format("\e[{}H", col);
    // try f instead of H if it doesn't work
    return fmt::format("\e[{};{}H", line, col);
}
/**
 * @brief Erase a part of the screen or the whole screen
 * 
 * @param mode Can be one of these values:
 *      0: Clear from cursor to the end of the screen
 *      1: Clear from cursor to the beginning of the screen
 *      2: Clear entire screen
 *      3: Clear entire screen and delete all lines saved in scrollback buffer
 * @return The ANSI escape sequence or empty string if invalid mode provided
 */
std::string ClearScreen(int mode = 0)
{
    //! TODO: Replace hard-coded value with enums
    if (!inRange(mode, 0, 3))
        return "";
    if (mode == 0)
        return "\e[J";
    return fmt::format("\e[{}J", mode);
}
/**
 * @brief Erase a part of current line or the whole line. Cursor position does
 *        not change after this operation.
 * 
 * @param mode Can be one of these values:
 *      0: Clear from cursor to the end of current line
 *      1: Clear from cursor to the beginning of current line
 *      2: Clear entire line
 * @return The ANSI escape sequence or empty string if invalid mode provided
 */
std::string ClearLine(int mode = 0)
{
    //! TODO: Replace hard-coded value with enums
    if (!inRange(mode, 0, 2))
        return "";
    if (mode == 0)
        return "\e[K";
    return fmt::format("\e[{}K", mode);
}
/**
 * @brief Scroll up a number of lines
 * 
 * @param n Number of lines to scroll up. This must be a positive number.
 * @return The ANSI escape sequence or empty string the argument is invalid
 */
std::string ScrollUp(int n = 1)
{
    if (n < 1)
        return "";
    if (n == 1)
        return "\e[S";
    return fmt::format("\e[{}S", n);
}
/**
 * @brief Scroll down a number of lines
 * 
 * @param n Number of lines to scroll down. This must be a positive number.
 * @return The ANSI escape sequence or empty string the argument is invalid
 */
std::string ScrollDown(int n = 1)
{
    if (n < 1)
        return "";
    if (n == 1)
        return "\e[T";
    return fmt::format("\e[{}T", n);
}

struct TerminalFormat {
    std::string start;
    std::string end;
    TerminalFormat(std::string start, std::string end = "\e[m")
        : start { start }, end { end }
    {
    }
};
std::string format(std::initializer_list<TerminalFormat> formats, std::string content)
{
    std::set<std::string> ending;
    std::string result;
    for (auto format : formats) {
        result += format.start;
        ending.insert(format.end);
    }
    result += content;
    for (auto str : ending) {
        result += str;
    }
    return result;
}
// Text format
//! TODO: Support xxxOn and xxxOff so that users can control directly instead of relying on format()
TerminalFormat Bold { "\e[1m" };
TerminalFormat Dim { "\e[2m" };
TerminalFormat Italic { "\e[3m" };
TerminalFormat Underline { "\e[4m" };
TerminalFormat Invert { "\e[7m" };
TerminalFormat Conceal { "\e[8m" };
TerminalFormat Strikethrough { "\e[9m" };
TerminalFormat Normal { "\e[22m" };
TerminalFormat ItalicOff { "\e[23m" };
TerminalFormat UnderlineOff { "\e[24m" };
TerminalFormat InvertOff { "\e[27m" };
TerminalFormat ConcealOff { "\e[28m" };
TerminalFormat StrikethroughOff { "\e[29m" };

// Color
TerminalFormat FgBlack { "\e[30m" };
TerminalFormat FgRed { "\e[31m" };
TerminalFormat FgGreen { "\e[32m" };
TerminalFormat FgYellow { "\e[33m" };
TerminalFormat FgBlue { "\e[34m" };
TerminalFormat FgMagenta { "\e[35m" };
TerminalFormat FgCyan { "\e[36m" };
TerminalFormat FgWhite { "\e[37m" };
TerminalFormat FgBrightBlack { "\e[90m" };
TerminalFormat FgBrightRed { "\e[91m" };
TerminalFormat FgBrightGreen { "\e[92m" };
TerminalFormat FgBrightYellow { "\e[93m" };
TerminalFormat FgBrightBlue { "\e[94m" };
TerminalFormat FgBrightMagenta { "\e[95m" };
TerminalFormat FgBrightCyan { "\e[96m" };
TerminalFormat FgBrightWhite { "\e[97m" };
// TerminalFormat FgDefault { "\e[39m" };

TerminalFormat BgBlack { "\e[40m" };
TerminalFormat BgRed { "\e[41m" };
TerminalFormat BgGreen { "\e[42m" };
TerminalFormat BgYellow { "\e[43m" };
TerminalFormat BgBlue { "\e[44m" };
TerminalFormat BgMagenta { "\e[45m" };
TerminalFormat BgCyan { "\e[46m" };
TerminalFormat BgWhite { "\e[47m" };
TerminalFormat BgBrightBlack { "\e[100m" };
TerminalFormat BgBrightRed { "\e[101m" };
TerminalFormat BgBrightGreen { "\e[102m" };
TerminalFormat BgBrightYellow { "\e[103m" };
TerminalFormat BgBrightBlue { "\e[104m" };
TerminalFormat BgBrightMagenta { "\e[105m" };
TerminalFormat BgBrightCyan { "\e[106m" };
TerminalFormat BgBrightWhite { "\e[107m" };
// TerminalFormat BgDefault { "\e[49m" };

// 8-bit colors
/*
0-7 are 8 colors above
8-15 are high-intensity of 0-7
16-231 are colors
232-255 are grayscales
*/
TerminalFormat Fg8bit(int n)
{
    if (!inRange(n, 0, 255))
        return { "" };
    return fmt::format("\e[38;5;{}m", n);
}
TerminalFormat Bg8bit(int n)
{
    if (!inRange(n, 0, 255))
        return { "" };
    return fmt::format("\e[48;5;{}m", n);
}
// 24-bit color

TerminalFormat FgRgb(int red, int green, int blue)
{
    int min = 0;
    int max = 255;
    if (!inRange(red, min, max) || !inRange(green, min, max) || !inRange(blue, min, max))
        return { "" };
    return fmt::format("\e[38;2;{};{};{}m", red, green, blue);
}
TerminalFormat BgRgb(int red, int green, int blue)
{
    int min = 0;
    int max = 255;
    if (!inRange(red, min, max) || !inRange(green, min, max) || !inRange(blue, min, max))
        return { "" };
    return fmt::format("\e[48;2;{};{};{}m", red, green, blue);
}

} // end namespace Terminal

#endif