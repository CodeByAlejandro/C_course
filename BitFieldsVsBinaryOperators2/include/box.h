#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

enum color { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };
enum opacity { TRANSPARENT, OPAQUE };
enum borderVisibility { HIDDEN, VISIBLE };
enum borderStyle { SOLID, DOTTED, DASHED };

char * getColorDescription(enum color color);
char * getBorderStyleDescription(enum borderStyle borderStyle);

#endif // BOX_H_INCLUDED