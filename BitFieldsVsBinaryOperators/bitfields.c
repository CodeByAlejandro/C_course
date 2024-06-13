#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "box.h"

struct BoxProps {
    // 0 - transparent; 1 - opaque
    bool opacity:1;
    // 000 -black; 001 - red; 010 - green; 011 - yellow; 100 - blue; 101 - magenta; 110 - cyan; 111 - white
    uint16_t fillColor:3;
    // 0 - hidden; 1 - visible
    bool border:1;
    // 000 -black; 001 - red; 010 - green; 011 - yellow; 100 - blue; 101 - magenta; 110 - cyan; 111 - white
    uint16_t borderColor:3;
    // 00 - solid; 01 - dotted; 10 - dashed
    uint16_t lineStyle:2;
    // padding
    uint16_t :6;
};

static void displayBoxProps(struct BoxProps boxProps);

void createAndModifyBoxUsingBitFields(void) {
    printf("\n");
    printf("The size of the BoxProps struct is %zu bytes\n\n", sizeof(struct BoxProps));
    
    struct BoxProps myBoxProps = {true, YELLOW, true, GREEN, DASHED};
    printf("Orignal box settings:\n");
    displayBoxProps(myBoxProps);
    
    myBoxProps = (struct BoxProps) { false, GREEN, false, YELLOW, DOTTED };
    printf("Modified box settings:\n");
    displayBoxProps(myBoxProps);
}

static void displayBoxProps(struct BoxProps boxProps) {
    printf("Box is %s.\n", boxProps.opacity ? "opaque" : "transparent");
    printf("The fill color is %s.\n", ColorNames[boxProps.fillColor]);
    printf("Border %s.\n", boxProps.border ? "shown" : "hidden");
    printf("The border color is %s.\n", ColorNames[boxProps.borderColor]);
    printf("The border style is %s.\n", LineStyles[boxProps.lineStyle]);
    printf("\n");
}