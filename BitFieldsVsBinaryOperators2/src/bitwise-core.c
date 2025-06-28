#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bitwise-core.h"

static void validateBitFieldOffsetAndLenght(uint8_t fieldOffset, uint8_t fieldBitLength);
static void validateBitFieldValue(uint16_t fieldValue, uint8_t fieldBitLength);

uint16_t readBitField(uint16_t packed, uint8_t fieldOffset, uint8_t fieldBitLength) {
    validateBitFieldOffsetAndLenght(fieldOffset, fieldBitLength);
    uint16_t mask = (uint16_t) (pow(2, fieldBitLength) - 1);
    return (packed >> fieldOffset) & mask;
}

uint16_t writeBitField(uint16_t packed, uint16_t fieldValue, uint8_t fieldOffset, uint8_t fieldBitLength) {
    validateBitFieldOffsetAndLenght(fieldOffset, fieldBitLength);
    validateBitFieldValue(fieldValue, fieldBitLength);
    uint16_t mask = (uint16_t) (pow(2, fieldBitLength) - 1);
    packed &= ~(mask << fieldOffset); // Clear bitfield in packed field (set bitfield to all 0's)
    packed |= fieldValue << fieldOffset; // Set bitfield value in packed field
    return packed;
}

static void validateBitFieldOffsetAndLenght(uint8_t fieldOffset, uint8_t fieldBitLength) {
    if(fieldOffset < 0 || fieldOffset >= PACKED_SIZE) {
        fprintf(stderr, "Invalid bitfield offset received!\n");
        exit(1);
    }
    if(fieldBitLength < 1 || fieldBitLength > PACKED_SIZE) {
        fprintf(stderr, "Invalid bitfield length received!\n");
        exit(1);
    }
    if(fieldBitLength > (PACKED_SIZE - fieldOffset)) {
        fprintf(stderr, "Invalid bitfield offset<->length combination received!\n");
        exit(1);
    }
}

static void validateBitFieldValue(uint16_t fieldValue, uint8_t fieldBitLength) {
    if(fieldValue > (uint16_t) (pow(2, fieldBitLength) - 1)) {
        fprintf(stderr, "Invalid bitfield value received!\n");
        exit(1);
    }
}