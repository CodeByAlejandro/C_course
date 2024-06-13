#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

enum Color { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

static const char* ColorNames[] = {
    "black",
    "red",
    "green",
    "yellow",
    "blue",
    "magenta",
    "cyan",
    "white"
};

enum LineStyle { SOLID, DOTTED, DASHED };

static const char* LineStyles[] = {
    "solid",
    "dotted",
    "dashed"
};

#endif