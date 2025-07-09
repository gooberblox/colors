#pragma once

/* 
 * contains a barely filled mapping of every formatting code 
 * used for the terminal. 
 * feel free to add other codes when needed.
 * https://misc.flogisoft.com/bash/tip_colors_and_formatting
 */

namespace Color {
    enum class ExtendedCode {
    	BLACK = 0,
	MAROON = 1,
	GREEN = 2,
	OLIVE = 3,
	NAVY = 4,
	PURPLE = 5,
	TEAL = 6,
	SILVER = 7,
	GREY = 8,
	RED = 9,
	LIME = 10,
	YELLOW = 11,
	BLUE = 12,
	FUCHSIA = 13,
	AQUA = 14, 
	WHITE = 15,
	// all colors past here are NON-SYSTEM,
	// they may not work for some terminals.
	GREY0 = 16,
	NAVYBLUE = 17,
	DARKBLUE = 18,
	BLUE3 = 19,
	BLUE2 = 20,
	BLUE1 = 21,
	DARKGREEN = 22,
	DEEPSKYBLUE = 25 // color for C files

    };

}
