# colors - simple terminal coloring utility
- Utility for the coloring of terminal text in both the foreground and background.
# Synopsis
```cpp
#include <colors.h>

Namespace Color {
    inline std::ostream& setColor(std::ostream& os, Color::Basic color, bool bold = false);
    inline std::ostream& setColor(std::ostream& os, int code, bool bold = false);
    inline std::ostream& setColor(std::ostream& os, int r, int g, int b, bool bold = false);

    inline std::ostream& setBgColor(std::ostream& os, Color::Basic color);
    inline std::ostream& setBgColor(std::ostream& os, int code);
    inline std::ostream& setBgColor(std::ostream& os, int r, int g, int b);

    inline std::ostream& reset(std::ostream& os);
}
```

# Description
- Returns an escape code containing the associate color code that will set all code after the function call to be the given color. 
- Both setColor and setBgColor support a simple 8-color format, extended 256-color format, and RGB colors.
- setColor contains a bold argument(false by default) that will bold the text given.
    - Note: When setting bold to true, color may be lighter than the unbolded version.

# Return Value
- Returns an std::ostream object containing the given escape code.

# Errors
- Will throw a std::invalid_argument if RGB values are not in the range of 0-255, or if the extended colors are  not in the range of 0-255.

# Notes
- There are no defined values for extended colors. Color codes can be viewed [here](https://misc.flogisoft.com/bash/tip_colors_and_formatting#colors1).
