#ifndef C_FLOAT_24_40_H
#define C_FLOAT_24_40_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_24_40 24
#define EXPONENT_BITS_F_24_40 40
#define BITS_F_24_40 SIGNIFICAND_BITS_F_24_40 + EXPONENT_BITS_F_24_40

#define C_FLOAT_24_40_DEBUG true

typedef uint64_t f2440_t;

#define SIGNIFICAND_MASK_F_24_40 ((1ULL << SIGNIFICAND_BITS_F_24_40) - 1)
#define SIGNIFICAND_2_MASK_F_24_40 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_24_40) - 1)
#define EXPONENT_MASK_F_24_40 (((1ULL << EXPONENT_BITS_F_24_40) - 1) << SIGNIFICAND_BITS_F_24_40)
#define SIGNIFICAND_SIGN_MASK_F_24_40 (1ULL << (SIGNIFICAND_BITS_F_24_40 - 1))
#define EXPONENT_SIGN_MASK_F_24_40 (1ULL << (EXPONENT_BITS_F_24_40 - 1))
#define BITS_SIGN_MASK_F_24_40 (1ULL << (BITS_F_24_40 - 1))

// construct float 2440
f2440_t new_f2440(uint64_t exp, uint64_t sig);
// exponent part of float 2440
uint64_t exp_f2440(f2440_t a);
// significand part of float 2440
uint64_t sig_f2440(f2440_t a);
// add float 2440
f2440_t add_f2440(f2440_t a, f2440_t b);
// subtract float 2440
f2440_t sub_f2440(f2440_t a, f2440_t b);
// negate float 2440
f2440_t neg_f2440(f2440_t a);
// multiply float 2440
f2440_t mul_f2440(f2440_t a, f2440_t b);
// divide float 2440
f2440_t div_f2440(f2440_t a, f2440_t b);
// equals float 2440
bool equ_f2440(f2440_t a, f2440_t b);
// compare float 2440
int com_f2440(f2440_t a, f2440_t b);

#endif // C_FLOAT_24_40_H

