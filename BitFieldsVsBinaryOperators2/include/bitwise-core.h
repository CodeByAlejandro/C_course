#ifndef BITWISE_CORE_H_INCLUDED
#define BITWISE_CORE_H_INCLUDED

#include <stdint.h>

// to make the size generic macro's would be needed to generate different versions of the code
#define PACKED_SIZE 16

uint16_t readBitField(uint16_t packed, uint8_t fieldOffset, uint8_t fieldBitLength);
uint16_t writeBitField(uint16_t packed, uint16_t fieldValue, uint8_t fieldOffset, uint8_t fieldBitLength);

#endif // BITWISE_CORE_H_INCLUDED