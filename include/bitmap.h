#ifndef _bitmap_h_
#define _bitmap_h_

#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

void bitmap_zero(uint8_t* bitmap, unsigned int nbits);
void bitmap_fill(uint8_t* bitmap, unsigned int nbits);

void bitmap_set(uint8_t *bitmap, unsigned int start, unsigned int len);
void bitmap_clear(uint8_t *bitmap, unsigned int start, unsigned int len);

void bitmap_or(uint8_t* result, const uint8_t* src1, const uint8_t* src2, unsigned int nbits);
void bitmap_and(uint8_t* result, const uint8_t* src1, const uint8_t* src2, unsigned int nbits);
void bitmap_xor(uint8_t* result, const uint8_t* src1, const uint8_t* src2, unsigned int nbits);

unsigned int bitmap_count_leading_zero(const uint8_t* bitmap, unsigned int nbits);
unsigned int bitmap_count_next_zero(const uint8_t* bitmap, unsigned int nbits, unsigned int start);
unsigned int bitmap_find_first_zero(const uint8_t* bitmap, unsigned int nbits);
unsigned int bitmap_find_next_zero(const uint8_t* bitmap, unsigned int nbits, unsigned int start);
unsigned int bitmap_weight(const uint8_t* bitmap, unsigned int nbits);

/// @return 0-not set, other-set to 1
int bitmap_test_bit(const uint8_t* bitmap, unsigned int bits);

#if defined(__cplusplus)
}
#endif
#endif /* !_bitmap_h_ */
