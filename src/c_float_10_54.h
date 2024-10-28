#ifndef C_FLOAT_10_54_H
#define C_FLOAT_10_54_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_10_54 10
#define EXPONENT_BITS_F_10_54 54
#define BITS_F_10_54 SIGNIFICAND_BITS_F_10_54 + EXPONENT_BITS_F_10_54

#define C_FLOAT_10_54_DEBUG true

typedef uint64_t f1054_t;

#define SIGNIFICAND_MASK_F_10_54 ((1ULL << SIGNIFICAND_BITS_F_10_54) - 1)
#define SIGNIFICAND_2_MASK_F_10_54 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_10_54) - 1)
#define EXPONENT_MASK_F_10_54 (((1ULL << EXPONENT_BITS_F_10_54) - 1) << SIGNIFICAND_BITS_F_10_54)
#define SIGNIFICAND_SIGN_MASK_F_10_54 (1ULL << (SIGNIFICAND_BITS_F_10_54 - 1))
#define EXPONENT_SIGN_MASK_F_10_54 (1ULL << (EXPONENT_BITS_F_10_54 - 1))
#define BITS_SIGN_MASK_F_10_54 (1ULL << (BITS_F_10_54 - 1))

// construct float 1054
f1054_t new_f1054(uint64_t exp, uint64_t sig);
// exponent part of float 1054
uint64_t exp_f1054(f1054_t a);
// significand part of float 1054
uint64_t sig_f1054(f1054_t a);
// add float 1054
f1054_t add_f1054(f1054_t a, f1054_t b);
// subtract float 1054
f1054_t sub_f1054(f1054_t a, f1054_t b);
// negate float 1054
f1054_t neg_f1054(f1054_t a);
// multiply float 1054
f1054_t mul_f1054(f1054_t a, f1054_t b);
// divide float 1054
f1054_t div_f1054(f1054_t a, f1054_t b);
// equals float 1054
bool equ_f1054(f1054_t a, f1054_t b);
// compare float 1054
int com_f1054(f1054_t a, f1054_t b);

#endif // C_FLOAT_10_54_H

