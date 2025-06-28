#ifndef BITWISE_H_INCLUDED
#define BITWISE_H_INCLUDED

#include <stdint.h>
#include "box.h"

void testBitwise(void);
uint16_t initializeBitwiseBox(uint16_t box);
uint16_t getBitwiseBoxOpacity(uint16_t box);
uint16_t setBitwiseBoxOpacity(uint16_t box, enum opacity opacity);
uint16_t getBitwiseBoxFillColor(uint16_t box);
uint16_t setBitwiseBoxFillColor(uint16_t box, enum color fillColor);
uint16_t getBitwiseBoxBorderVisibility(uint16_t box);
uint16_t setBitwiseBoxBorderVisibility(uint16_t box, enum borderVisibility borderVisibility);
uint16_t getBitwiseBoxBorderColor(uint16_t box);
uint16_t setBitwiseBoxBorderColor(uint16_t box, enum color borderColor);
uint16_t getBitwiseBoxBorderStyle(uint16_t box);
uint16_t setBitwiseBoxBorderStyle(uint16_t box, enum borderStyle borderStyle);
void displayBitwiseBox(uint16_t box);

#endif // BITWISE_H_INCLUDED