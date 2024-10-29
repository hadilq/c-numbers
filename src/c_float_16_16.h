#ifndef C_FLOAT_16_16_H
#define C_FLOAT_16_16_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_16_16 16
#define EXPONENT_BITS_F_16_16 06
#define BITS_F_16_16 SIGNIFICAND_BITS_F_16_16 + EXPONENT_BITS_F_16_16

#define C_FLOAT_16_16_DEBUG true

typedef uint32_t f1616_t;

#define SIGNIFICAND_MASK_F_16_16 ((1UL << SIGNIFICAND_BITS_F_16_16) - 1)
#define SIGNIFICAND_2_MASK_F_16_16 ((1ULL << 2 * SIGNIFICAND_BITS_F_16_16) - 1)
#define EXPONENT_MASK_F_16_16 (((1UL << EXPONENT_BITS_F_16_16) - 1) << SIGNIFICAND_BITS_F_16_16)
#define SIGNIFICAND_SIGN_MASK_F_16_16 (1UL << (SIGNIFICAND_BITS_F_16_16 - 1))
#define EXPONENT_SIGN_MASK_F_16_16 (1UL << (EXPONENT_BITS_F_16_16 - 1))
#define BITS_SIGN_MASK_F_16_16 (1UL << (BITS_F_16_16 - 1))

#define MAX_VALUE_F_16_16 (((1U << (EXPONENT_BITS_F_16_16 - 2)) - 1) << SIGNIFICAND_BITS_F_16_16) | ((1U << (SIGNIFICAND_BITS_F_16_16 - 2)) - 1)
#define MIN_VALUE_F_16_16 (((1U << (EXPONENT_BITS_F_16_16 - 2)) - 1) << SIGNIFICAND_BITS_F_16_16) | (SIGNIFICAND_SIGN_MASK_F_16_16)

// construct float 1616
f1616_t new_f1616(int32_t exp, int32_t sig);
// construct float 1616
f1616_t new_f1616_from_float32(_Float32 f);
// construct float 1616
f1616_t new_f1616_from_float16(_Float16 f);
// exponent part of float 1616
int32_t exp_f1616(f1616_t a);
// significand part of float 1616
int32_t sig_f1616(f1616_t a);
// add float 1616
f1616_t add_f1616(f1616_t a, f1616_t b);
// subtract float 1616
f1616_t sub_f1616(f1616_t a, f1616_t b);
// negate float 1616
f1616_t neg_f1616(f1616_t a);
// multiply float 1616
f1616_t mul_f1616(f1616_t a, f1616_t b);
// divide float 1616
f1616_t div_f1616(f1616_t a, f1616_t b);
// equals float 1616
bool equ_f1616(f1616_t a, f1616_t b);
// compare float 1616
int com_f1616(f1616_t a, f1616_t b);

#endif // C_FLOAT_16_16_H

