#ifndef C_FLOAT_40_24_H
#define C_FLOAT_40_24_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_40_24 40
#define EXPONENT_BITS_F_40_24 24
#define BITS_F_40_24 SIGNIFICAND_BITS_F_40_24 + EXPONENT_BITS_F_40_24

#define C_FLOAT_40_24_DEBUG true

typedef uint64_t f4024_t;

#define SIGNIFICAND_MASK_F_40_24 ((1ULL << SIGNIFICAND_BITS_F_40_24) - 1)
#define SIGNIFICAND_2_MASK_F_40_24 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_40_24) - 1)
#define EXPONENT_MASK_F_40_24 (((1ULL << EXPONENT_BITS_F_40_24) - 1) << SIGNIFICAND_BITS_F_40_24)
#define SIGNIFICAND_SIGN_MASK_F_40_24 (1ULL << (SIGNIFICAND_BITS_F_40_24 - 1))
#define EXPONENT_SIGN_MASK_F_40_24 (1ULL << (EXPONENT_BITS_F_40_24 - 1))
#define BITS_SIGN_MASK_F_40_24 (1ULL << (BITS_F_40_24 - 1))

// construct float 4024
f4024_t new_f4024(uint64_t exp, uint64_t sig);
// exponent part of float 4024
uint64_t exp_f4024(f4024_t a);
// significand part of float 4024
uint64_t sig_f4024(f4024_t a);
// add float 4024
f4024_t add_f4024(f4024_t a, f4024_t b);
// subtract float 4024
f4024_t sub_f4024(f4024_t a, f4024_t b);
// negate float 4024
f4024_t neg_f4024(f4024_t a);
// multiply float 4024
f4024_t mul_f4024(f4024_t a, f4024_t b);
// divide float 4024
f4024_t div_f4024(f4024_t a, f4024_t b);
// equals float 4024
bool equ_f4024(f4024_t a, f4024_t b);
// compare float 4024
int com_f4024(f4024_t a, f4024_t b);

#endif // C_FLOAT_40_24_H
