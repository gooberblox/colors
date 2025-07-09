#ifndef COLOR_H
#define COLOR_H

#include <ostream>



namespace Color {
    
    enum class Basic {
        Reset        = 0,
        /// standard 8
        Black        = 30,
        Red          = 31,
        Green        = 32,
        Yellow       = 33,
        Blue         = 34,
        Magenta      = 35,
        Cyan         = 36,
        White        = 37,
        // bright/bold
        BrightBlack  = 90,
        BrightRed    = 91,
        BrightGreen  = 92,
        BrightYellow = 93,
        BrightBlue   = 94,
        BrightMagenta= 95,
        BrightCyan   = 96,
        BrightWhite  = 97
    };

    inline std::ostream& setColor(std::ostream& os, Basic color, bool bold = false) {
        // basic colors 
        return os << "\033[" << (bold ? "1" : "0") << ";" << static_cast<int>(color) << "m";
    }

    inline std::ostream& setColor(std::ostream& os, int code, bool bold = false) {
        // 256-color
        if((code < 0) || (code > 255)) {
            // could maybe throw an exception here...
            throw std::invalid_argument("ERROR: Extended color code values must be in the range of 0-255.");
            return os;
        } else {
            return os << "\033[" << (bold ? "1" : "0") << ";38;5;" << code << "m";
        }
    }

    inline std::ostream& setColor(std::ostream& os, int r, int g, int b, bool bold = false) {
        // rgb
        if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
            throw std::invalid_argument("ERROR: RGB values must be between 0 and 255.");
            return os;
        } else {
            return os << "\033[" << (bold ? "1" : "0") << ";38;2;" << r << ";" << g << ";" << b << "m";
        }
    }

    // all the above functions but dealing with the backgrounds 

    inline std::ostream& setBgColor(std::ostream& os, Basic color) {
        int code = static_cast<int>(color);

        if((code >=30 && code <= 37) || (code >= 90 && code <= 97)) {
            code+=10;
        }
        return os << "\033[" << code << "m";
    }

    inline std::ostream& setBgColor(std::ostream& os, int code) {
        if(code < 0 || code > 255) {
            throw std::invalid_argument("ERROR: Extended color code values must be in the range of 0-255.");
            return os;
        } else {
            return os << "\033[38;5;" << code << "m";
        }
    }

    inline std::ostream& setBgColor(std::ostream& os, int r, int b, int g) {
        if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
            throw std::invalid_argument("ERROR: RGB values must be between 0 and 255.");
            return os;
        } else {
            return os << "\033[38;2;" << r << ";" << g << ";" << b << "m";
        }
    }

    inline std::ostream& reset(std::ostream& os) {
        return os << "\033[0m";
    }

    
}
#endif
// - bwintt/gooberblox
