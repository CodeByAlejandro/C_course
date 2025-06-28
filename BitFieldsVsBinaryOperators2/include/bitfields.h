#ifndef BITFIELDS_H_INCLUDED
#define BITFIELDS_H_INCLUDED

#include "box.h"

struct box {
    unsigned short int opacity :1;
    unsigned short int fillColor :3;
    unsigned short int :4;
    unsigned short int borderVisibility :1;
    unsigned short int borderColor :3;
    unsigned short int borderStyle :2;
    unsigned short int :2;
};

void testBitFields(void);
struct box initializeBitfieldBox(struct box box);
struct box setBitfieldBoxOpacity(struct box box, enum opacity opacity);
struct box setBitfieldBoxFillColor(struct box box, enum color fillColor);
struct box setBitfieldBoxBorderVisibility(struct box box, enum borderVisibility borderVisibility);
struct box setBitfieldBoxBorderColor(struct box box, enum color borderColor);
struct box setBitfieldBoxBorderStyle(struct box box, enum borderStyle borderStyle);
void displayBitfieldBox(struct box box);

#endif // BITFIELDS_H_INCLUDED