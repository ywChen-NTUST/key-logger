#include <Windows.h>

static const char* keymap[0xff] = {
    // 0x00 - 0x0f
    "[NONE]",
    "[LMOUSE]",
    "[RMOUSE]",
    "[CANCEL]",
    "[MMOUSE]",
    "[XMOUSE1]",
    "[XMOUSE2]",
    "[RESERVED]",
    "[BACKSPACE]",
    "[TAB]",
    "[RESERVED]", "[RESERVED]",
    "[CLEAR]",
    "[ENTER]",
    "[UNASSIGNED]", "[UNASSIGNED]",

    // 0x10 - 0x1f
    "[SHIFT]",
    "[CTRL]",
    "[ALT]",
    "[PAUSE]",
    "[CAPSLOCK]",
    "[IME KANA / HANGUL]",
    "[IME ON]",
    "[IME JUNJA]",
    "[IME FINAL]",
    "[IME HANJA / KANJI]",
    "[IME OFF]",
    "[ESC]",
    "[IME CONVERT]",
    "[IME NONCONVERT]",
    "[IME ACCEPT]",
    "[IME MODE CHANGE REQUEST]",

    // 0x20 - 0x2f
    "[SPACE]",
    "[PGUP]",
    "[PGDN]",
    "[END]",
    "[HOME]",
    "[LEFT ARROW]",
    "[UP ARROW]",
    "[RIGHT ARROW]",
    "[DOWN ARROW]",
    "[SELECT]",
    "[PRINT]",
    "[EXECUTE]",
    "[PRINT SCREEN]",
    "[INS]",
    "[DEL]",
    "[HELP]",

    // 0x30 - 0x3f
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    "[UNDEFINED]", "[UNDEFINED]", "[UNDEFINED]", "[UNDEFINED]", "[UNDEFINED]", "[UNDEFINED]",

    // 0x40 - 0x4f
    "[UNDEFINED]", 
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o",

    // 0x50 - 0x5f
    "p", "q", "r", "s", "t", "u", "v", "w", "x", "y",
    "z",
    "[LWIN]",
    "[RWIN]",
    "[APPLICATION]",
    "[RESERVED]",
    "[SLEEP]",

    // 0x60 - 0x6f
    "[NUMPAD 0]", "[NUMPAD 1]", "[NUMPAD 2]", "[NUMPAD 3]", "[NUMPAD 4]",
    "[NUMPAD 5]", "[NUMPAD 6]", "[NUMPAD 7]", "[NUMPAD 8]", "[NUMPAD 9]",
    "[MULTIPLY]",
    "[ADD]",
    "[SEPARATOR]",
    "[SUBTRACT]",
    "[DECIMAL]",
    "[DIVIDE]",

    // 0x70 - 0x7f
    "[F1]", "[F2]", "[F3]", "[F4]", "[F5]", "[F6]", "[F7]", "[F8]", "[F9]", "[F10]",
    "[F11]", "[F12]", "[F13]", "[F14]", "[F15]", "[F16]",
    
    // 0x80 - 0x8f
    "[F17]", "[F18]", "[F19]", "[F20]", "[F21]", "[F22]", "[F23]", "[F24]",
    "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]",
    "[RESERVED]", "[RESERVED]", "[RESERVED]",

    // 0x90 - 0x9f
    "[NUMLOCK]",
    "[SCROLLLOCK]",
    "[OEM SPECIFIC]", "[OEM SPECIFIC]", "[OEM SPECIFIC]", "[OEM SPECIFIC]", "[OEM SPECIFIC]",
    "[UNASSIGNED]", "[UNASSIGNED]", "[UNASSIGNED]", "[UNASSIGNED]", "[UNASSIGNED]",
    "[UNASSIGNED]", "[UNASSIGNED]", "[UNASSIGNED]", "[UNASSIGNED]",

    // 0xa0 - 0xaf
    "[LSHIFT]",
    "[RSHIFT]",
    "[LCTRL]",
    "[RCTRL]",
    "[LALT]",
    "[RALT]",
    "[BROWSER BACK]",
    "[BROWSER FORWARD]",
    "[BROWSER REFRESH]",
    "[BROWSER STOP]",
    "[BROWSER SEARCH]",
    "[BROWSER FAVORITES]",
    "[BROWSER HOME]",
    "[VOLUME MUTE]",
    "[VOLUME DOWN]",
    "[VOLUME UP]",
    
    // 0xb0 - 0xbf
    "[MEDIA NEXT TRACK]",
    "[MEDIA PREV TRACK]",
    "[MEDIA STOP]",
    "[MEDIA PLAY / PAUSE]",
    "[LAUNCH MAIL]",
    "[LAUNCH MEDIA SELECT]",
    "[LAUNCH APP 1]",
    "[LAUNCH APP 2]",
    "[RESERVED]", "[RESERVED]", 
    ";", // OEM 1
    "+", // OEM PLUS
    ",", // OEM COMMA
    "-", // OEM MINUS
    ".", // OEM PERIOD
    "/", // OEM 2

    // 0xc0 - 0xcf
    "`", // OEM 3
    "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]",
    "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]",
    "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]",

    // 0xd0 - 0xdf
    "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]",
    "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]", "[RESERVED]",
    "[RESERVED]",
    "[", // OEM 4
    "\\", // OEM 5
    "]", // OEM 6
    "'", // OEM 7
    "[OEM 8]",

    // 0xe0 - 0xef
    "[RESERVED]",
    "[OEM SPECIFIC]",
    "[OEM 102]",
    "[OEM SPECIFIC]", "[OEM SPECIFIC]",
    "[PROCESS KEY]",
    "[OEM SPECIFIC]",
    "[PACKET]",
    "[UNASSIGNED]",
    "[OEM SPECIFIC]", "[OEM SPECIFIC]", "[OEM SPECIFIC]", "[OEM SPECIFIC]", "[OEM SPECIFIC]",
    "[OEM SPECIFIC]", "[OEM SPECIFIC]",

    // 0xf0 - 0xff
    "[OEM SPECIFIC]", "[OEM SPECIFIC]", "[OEM SPECIFIC]", "[OEM SPECIFIC]", "[OEM SPECIFIC]",
    "[OEM SPECIFIC]",
    "[ATTN]",
    "[CRSEL]",
    "[EXSEL]",
    "[EREOF]",
    "[PLAY]",
    "[ZOOM]",
    "[NONAME]",
    "[PA1]",
    "[OEM CLEAR]"
};