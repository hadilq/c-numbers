#ifndef C_FLOAT_50_14_H
#define C_FLOAT_50_14_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_50_14 50
#define EXPONENT_BITS_F_50_14 14
#define BITS_F_50_14 SIGNIFICAND_BITS_F_50_14 + EXPONENT_BITS_F_50_14

#define C_FLOAT_50_14_DEBUG true

typedef uint64_t f5014_t;

#define SIGNIFICAND_MASK_F_50_14 ((1ULL << SIGNIFICAND_BITS_F_50_14) - 1)
#define SIGNIFICAND_2_MASK_F_50_14 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_50_14) - 1)
#define EXPONENT_MASK_F_50_14 (((1ULL << EXPONENT_BITS_F_50_14) - 1) << SIGNIFICAND_BITS_F_50_14)
#define SIGNIFICAND_SIGN_MASK_F_50_14 (1ULL << (SIGNIFICAND_BITS_F_50_14 - 1))
#define EXPONENT_SIGN_MASK_F_50_14 (1ULL << (EXPONENT_BITS_F_50_14 - 1))
#define BITS_SIGN_MASK_F_50_14 (1ULL << (BITS_F_50_14 - 1))

// construct float 5014
f5014_t new_f5014(uint64_t exp, uint64_t sig);
// exponent part of float 5014
uint64_t exp_f5014(f5014_t a);
// significand part of float 5014
uint64_t sig_f5014(f5014_t a);
// add float 5014
f5014_t add_f5014(f5014_t a, f5014_t b);
// subtract float 5014
f5014_t sub_f5014(f5014_t a, f5014_t b);
// negate float 5014
f5014_t neg_f5014(f5014_t a);
// multiply float 5014
f5014_t mul_f5014(f5014_t a, f5014_t b);
// divide float 5014
f5014_t div_f5014(f5014_t a, f5014_t b);
// equals float 5014
bool equ_f5014(f5014_t a, f5014_t b);
// compare float 5014
int com_f5014(f5014_t a, f5014_t b);

#endif // C_FLOAT_50_14_H

