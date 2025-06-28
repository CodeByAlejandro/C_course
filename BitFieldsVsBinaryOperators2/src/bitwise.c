#include <stdio.h>
#include "bitwise.h"
#include "bitwise-core.h"

void testBitwise(void) {
    uint16_t box = 0;
    box = initializeBitwiseBox(box);
    
	printf("The size of the box is %zd bytes.\n", sizeof(box));
	printf("The initialized bitfield in hex is %hX\n", box);
    
    printf("\nOriginal box settings:\n");
    displayBitwiseBox(box);
    box = setBitwiseBoxOpacity(box, TRANSPARENT);
    box = setBitwiseBoxFillColor(box, WHITE);
    box = setBitwiseBoxBorderColor(box, MAGENTA);
    box = setBitwiseBoxBorderStyle(box, SOLID);
    printf("\nModified box settings:\n");
    displayBitwiseBox(box);
}

uint16_t initializeBitwiseBox(uint16_t box) {
    // 1 bit opacity, 3 bits border color, 4 bits padding, 1 bit border visibility, 3 bits border color, 2 bits border style, 2 bits padding
    box = 0x2507; // 00|10|010|1 |0000|011|1  <- bitfields are right to left
    return box;
}

uint16_t getBitwiseBoxOpacity(uint16_t box) {
    return readBitField(box, 0, 1);
}
uint16_t setBitwiseBoxOpacity(uint16_t box, enum opacity opacity) {
    return writeBitField(box, opacity, 0, 1);
}

uint16_t getBitwiseBoxFillColor(uint16_t box) {
    return readBitField(box, 1, 3);
}
uint16_t setBitwiseBoxFillColor(uint16_t box, enum color fillColor) {
    return writeBitField(box, fillColor, 1, 3);
}

uint16_t getBitwiseBoxBorderVisibility(uint16_t box) {
    return readBitField(box, 8, 1);
}
uint16_t setBitwiseBoxBorderVisibility(uint16_t box, enum borderVisibility borderVisibility) {
    return writeBitField(box, borderVisibility, 8, 1);
}

uint16_t getBitwiseBoxBorderColor(uint16_t box) {
    return readBitField(box, 9, 3);
}
uint16_t setBitwiseBoxBorderColor(uint16_t box, enum color borderColor) {
    return writeBitField(box, borderColor, 9, 3);
}

uint16_t getBitwiseBoxBorderStyle(uint16_t box) {
    return readBitField(box, 12, 2);
}
uint16_t setBitwiseBoxBorderStyle(uint16_t box, enum borderStyle borderStyle) {
    return writeBitField(box, borderStyle, 12, 2);
}

void displayBitwiseBox(uint16_t box) {
    printf("Box is %s.\n", getBitwiseBoxOpacity(box) ? "opaque" : "transparent");
    printf("The fill color is %s.\n", getColorDescription(getBitwiseBoxFillColor(box)));
    printf("Border %s.\n", getBitwiseBoxBorderVisibility(box) ? "shown": "hidden");
    printf("The border color is %s.\n", getColorDescription(getBitwiseBoxBorderColor(box)));
    printf("The border style is %s.\n", getBorderStyleDescription(getBitwiseBoxBorderStyle(box)));
}