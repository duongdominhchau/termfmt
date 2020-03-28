Bug:
- RGB combined with a core color result in no color.

Feature:
- Generate a structure to represent styled text.
- Parse input to the structure above.
- Sticky styling: turn on a style and it applies to all text output after that until the user turn it off.
- Cursor and screen control, should rethink about the interface.

References:
- https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_sequences
- https://linux.die.net/man/5/terminfo
- man7.org/linux/man-pages/man4/console_codes.4.html
