#include "box.h"

struct colorAttr {
    enum color color;
    char * description;
};

static struct colorAttr colors[8] = {
    { BLACK, "black" },
    { RED, "red" },
    { GREEN, "green" },
    { YELLOW, "yellow" },
    { BLUE, "blue" },
    { MAGENTA, "magenta" },
    { CYAN, "cyan" },
    { WHITE, "white" }
};

struct borderStyleAttr {
    enum borderStyle borderStyle;
    char * description;
};

static struct borderStyleAttr borderStyles[3] = {
    { SOLID, "solid" },
    { DOTTED, "dotted" },
    { DASHED, "dashed" }
};

char * getColorDescription(enum color color) {
    return colors[color].description;
}

char * getBorderStyleDescription(enum borderStyle borderStyle) {
    return borderStyles[borderStyle].description;
}