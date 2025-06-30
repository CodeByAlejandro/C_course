#include <stdio.h>
#include "bitfields.h"

void testBitFields(void) {
    struct box box;
    box = initializeBitfieldBox(box);

	printf("The size of the struct is %zd bytes.\n", sizeof(struct box));
	short unsigned int boxAsShortInt = *((short unsigned int *) &box);
	printf("The initialized bitfield in hex is %hX\n", boxAsShortInt);

    printf("\nOriginal box settings:\n");
    displayBitfieldBox(box);
    box = setBitfieldBoxOpacity(box, TRANSPARENT);
    box = setBitfieldBoxFillColor(box, WHITE);
    box = setBitfieldBoxBorderColor(box, MAGENTA);
    box = setBitfieldBoxBorderStyle(box, SOLID);
    printf("\nModified box settings:\n");
    displayBitfieldBox(box);
}

struct box initializeBitfieldBox(struct box box) {
    box.opacity = OPAQUE;
    box.fillColor = YELLOW;
    box.borderVisibility = VISIBLE;
    box.borderColor = GREEN;
    box.borderStyle = DASHED;
    return box;
}

struct box setBitfieldBoxOpacity(struct box box, enum opacity opacity) {
    box.opacity = opacity;
    return box;
}

struct box setBitfieldBoxFillColor(struct box box, enum color fillColor) {
    box.fillColor = fillColor;
    return box;
}

struct box setBitfieldBoxBorderVisibility(struct box box, enum borderVisibility borderVisibility) {
    box.borderVisibility = borderVisibility;
    return box;
}

struct box setBitfieldBoxBorderColor(struct box box, enum color borderColor) {
    box.borderColor = borderColor;
    return box;
}

struct box setBitfieldBoxBorderStyle(struct box box, enum borderStyle borderStyle) {
    box.borderStyle = borderStyle;
    return box;
}

void displayBitfieldBox(struct box box) {
    printf("Box is %s.\n", box.opacity ? "opaque" : "transparent");
    printf("The fill color is %s.\n", getColorDescription(box.fillColor));
    printf("Border %s.\n", box.borderVisibility ? "shown": "hidden");
    printf("The border color is %s.\n", getColorDescription(box.borderColor));
    printf("The border style is %s.\n", getBorderStyleDescription(box.borderStyle));
}