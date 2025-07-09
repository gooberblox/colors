#ifndef TERM_COLORS_SIMPLE
#define TERM_COLORS_SIMPLE

#if defined(TERM_COLORS)
#error "Cannot include colors.h and simpleColors.h in the same program!"
#endif

#include <ostream>

/*
lightweight version that only uses
the 8 basic terminal colors
*/

namespace Color {
    
    enum Code {
        FG_RED = 31,
        FG_GREEN = 32,
        FG_BLUE = 34,
        FG_MAGENTA = 35,
        FG_DEFAULT = 39,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_BLUE = 44,
        BG_DEFAULT = 49
    };
}

#endif
