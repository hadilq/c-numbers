#ifndef C_FLOAT_32_32_H
#define C_FLOAT_32_32_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_32_32 32
#define EXPONENT_BITS_F_32_32 32
#define BITS_F_32_32 SIGNIFICAND_BITS_F_32_32 + EXPONENT_BITS_F_32_32

#define C_FLOAT_32_32_DEBUG true

typedef uint64_t f3232_t;

#define SIGNIFICAND_MASK_F_32_32 ((1ULL << SIGNIFICAND_BITS_F_32_32) - 1)
#define SIGNIFICAND_2_MASK_F_32_32 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_32_32) - 1)
#define EXPONENT_MASK_F_32_32 (((1ULL << EXPONENT_BITS_F_32_32) - 1) << SIGNIFICAND_BITS_F_32_32)
#define SIGNIFICAND_SIGN_MASK_F_32_32 (1ULL << (SIGNIFICAND_BITS_F_32_32 - 1))
#define EXPONENT_SIGN_MASK_F_32_32 (1ULL << (EXPONENT_BITS_F_32_32 - 1))
#define BITS_SIGN_MASK_F_32_32 (1ULL << (BITS_F_32_32 - 1))

// construct float 3232
f3232_t new_f3232(uint64_t exp, uint64_t sig);
// exponent part of float 3232
uint64_t exp_f3232(f3232_t a);
// significand part of float 3232
uint64_t sig_f3232(f3232_t a);
// add float 3232
f3232_t add_f3232(f3232_t a, f3232_t b);
// subtract float 3232
f3232_t sub_f3232(f3232_t a, f3232_t b);
// negate float 3232
f3232_t neg_f3232(f3232_t a);
// multiply float 3232
f3232_t mul_f3232(f3232_t a, f3232_t b);
// divide float 3232
f3232_t div_f3232(f3232_t a, f3232_t b);
// equals float 3232
bool equ_f3232(f3232_t a, f3232_t b);
// compare float 3232
int com_f3232(f3232_t a, f3232_t b);

#endif // C_FLOAT_32_32_H

