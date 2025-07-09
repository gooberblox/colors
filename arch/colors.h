#ifndef TERM_COLORS
#define TERM_COLORS

#if defined(TERM_COLORS_SIMPLE)
#error "Cannot include colors.h and simpleColors.h in the same program!"
#endif

#include <ostream>
#include "extendedColors.h"

// https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
// more codes @ https://misc.flogisoft.com/bash/tip_colors_and_formatting

/* 
* namespace for creating a colored text output in the terminal.
* supports universal 8-color formats, 256 color extended format
* and a rgb "true color" format.
* 
* USAGE
* see usage for each statement below.
*/
namespace Color
{
    enum class Type {
	BASIC,
	EXTENDED,
	TRUECOLOR
    };
// codes for 8/16-color ANSI codes
    enum BasicCode {
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

    class Modifier
    {
        Type type;
        bool bold;
	int fg_code = -1;
	// int bg_code = -1;
	// ^^ if you want to have background colors
	int r = 0, g = 0, b = 0; // for true color

    public:
	/*
	* USAGE
	*
	* either store aes a variable first:
	* Color::Modifier VARNAME(args)
	* or use directly in an output statement:
	* cout << Color::Modifier(args)
	* for basic and extended:
	* Color::Modifier (
	* 	Color::Type type,
	* 	int code
	* 	OR
	* 	Color::ExtendedCode,
	* 	bool bold = false // by default false
	*   )
	* 
	* for the basic and extended color types, 
	* include their Color::Type and their corresponding code,
	* either a Color::FG_COLORNAME for basic, or a Color::ExtendedCode, 
	* and whether or not it should be bolded
	* for extended colors(see extendedColors.h)
	* e.g. Color::Modifier VAR_NAME(Type::TYPE_HERE, Color::COLORCODE, true)
	*
	* for true color/rgb:
	* Color::Modifier (
	* int r, 
	* int g,
	* int b,
	* bool bold = false // by default false
	* 
	* include your red, green, and blue in int format and then 
	* if you want it to be bold
	* )
	* 
	* c
	*/

	// basic colors
        Modifier(Type type, int code, bool bold = false) : type(type), bold(bold), fg_code(code) {
	 // you COULD check if the input is correct here, but IDGAF so i won't.   
	}
		// 256-color
		Modifier(Type type, ExtendedCode code, bool bold = false) 
		: type(type), bold(bold), fg_code(static_cast<int>(code)) {}
		// could i make the extendedCode a regular enum? maybe.
		// am i going to? no.
	

	// true color
	Modifier(int r, int g, int b, bool bold = false) 
	: type(Type::TRUECOLOR), bold(bold), r(r), g(g), b(b) {}

        friend std::ostream &operator<<(std::ostream &os, const Modifier &mod) {
	    switch(mod.type) {
	    	case Type::BASIC:
		    return os << "\033[" << (mod.bold ? "1" : "0") << ";" << mod.fg_code << "m";
		case Type::EXTENDED:
		    return os << "\033["  << (mod.bold ? "1" : "0") << ";38;5;" << mod.fg_code << "m";
		case Type::TRUECOLOR:
		    return os << "\033[" << (mod.bold ? "1" : "0") << ";38;2"
			      << mod.r << ";" << mod.g << ";" << mod.b << "m";
	    }
	    return os; // fallback

        }

	static std::ostream& reset(std::ostream& os) {
		/*
		* either call Colors::Modifier::reset in your cout statement,
		* or store it like this:
		* ostream& (*VAR_NAME)(ostream&) = Color::Modifier::reset;
		*/
	    return os << "\033[0m";
	} 
    };
}
#endif
// - bwintt
