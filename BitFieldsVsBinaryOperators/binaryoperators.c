#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "box.h"

static void displayBoxProps(uint16_t boxProps);

static bool isOpaque(uint16_t boxProps);
static void setOpaque(uint16_t* pBoxProps, bool opacity);
static uint8_t getFillColor(uint16_t boxProps);
static void setFillColor(uint16_t* pBoxProps, uint8_t fillColor);
static bool hasBorder(uint16_t boxProps);
static void setBorder(uint16_t* pBoxProps, bool border);
static uint8_t getBorderColor(uint16_t boxProps);
static void setBorderColor(uint16_t* pBoxProps, uint8_t borderColor);
static uint8_t getLineStyle(uint16_t boxProps);
static void setLineStyle(uint16_t* pBoxProps, uint8_t lineStyle);


void createAndModifyBoxUsingBinaryOperators(void) {
    uint16_t boxProps = 0;
    
    printf("\n");
    printf("The size of the boxProps packed field is %zu bytes\n\n", sizeof(boxProps));
    
    setOpaque(&boxProps, true);
    setFillColor(&boxProps, YELLOW);
    setBorder(&boxProps, true);
    setBorderColor(&boxProps, GREEN);
    setLineStyle(&boxProps, DASHED);
    
    printf("Orignal box settings:\n");
    displayBoxProps(boxProps);
    
    setOpaque(&boxProps, false);
    setFillColor(&boxProps, GREEN);
    setBorder(&boxProps, false);
    setBorderColor(&boxProps, YELLOW);
    setLineStyle(&boxProps, DOTTED);
    
    printf("Modified box settings:\n");
    displayBoxProps(boxProps);
}

static void displayBoxProps(uint16_t boxProps) {
    printf("Box is %s.\n", isOpaque(boxProps) ? "opaque" : "transparent");
    printf("The fill color is %s.\n", ColorNames[getFillColor(boxProps)]);
    printf("Border %s.\n", hasBorder(boxProps) ? "shown" : "hidden");
    printf("The border color is %s.\n", ColorNames[getBorderColor(boxProps)]);
    printf("The border style is %s.\n", LineStyles[getLineStyle(boxProps)]);
    printf("\n");
}


static bool isOpaque(uint16_t boxProps) {
    return boxProps & 1;
}

static void setOpaque(uint16_t* pBoxProps, bool opacity) {
    *pBoxProps = (*pBoxProps & 0xFFFE) | opacity;
}

static uint8_t getFillColor(uint16_t boxProps) {
    return boxProps >> 1 & 7;
}

static void setFillColor(uint16_t* pBoxProps, uint8_t fillColor) {
    *pBoxProps = (*pBoxProps & ~(7 << 1)) | fillColor << 1;
}

static bool hasBorder(uint16_t boxProps) {
    return boxProps >> 4 & 1;
}

static void setBorder(uint16_t* pBoxProps, bool border) {
    *pBoxProps = (*pBoxProps & ~(1 << 4)) | border << 4;
}

static uint8_t getBorderColor(uint16_t boxProps) {
    return boxProps >> 5 & 7;
}

static void setBorderColor(uint16_t* pBoxProps, uint8_t borderColor) {
    *pBoxProps = (*pBoxProps & ~(7 << 5)) | borderColor << 5;
}

static uint8_t getLineStyle(uint16_t boxProps) {
    return boxProps >> 8 & 3;
}

static void setLineStyle(uint16_t* pBoxProps, uint8_t lineStyle) {
    *pBoxProps = (*pBoxProps & ~(3 << 8)) | lineStyle << 8;
}