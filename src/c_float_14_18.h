#ifndef C_FLOAT_14_18_H
#define C_FLOAT_14_18_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_14_18 14
#define EXPONENT_BITS_F_14_18 06
#define BITS_F_14_18 SIGNIFICAND_BITS_F_14_18 + EXPONENT_BITS_F_14_18

#define C_FLOAT_14_18_DEBUG true

typedef uint32_t f1418_t;

#define SIGNIFICAND_MASK_F_14_18 ((1UL << SIGNIFICAND_BITS_F_14_18) - 1)
#define SIGNIFICAND_2_MASK_F_14_18 ((1ULL << 2 * SIGNIFICAND_BITS_F_14_18) - 1)
#define EXPONENT_MASK_F_14_18 (((1UL << EXPONENT_BITS_F_14_18) - 1) << SIGNIFICAND_BITS_F_14_18)
#define SIGNIFICAND_SIGN_MASK_F_14_18 (1UL << (SIGNIFICAND_BITS_F_14_18 - 1))
#define EXPONENT_SIGN_MASK_F_14_18 (1UL << (EXPONENT_BITS_F_14_18 - 1))
#define BITS_SIGN_MASK_F_14_18 (1UL << (BITS_F_14_18 - 1))

#define MAX_VALUE_F_14_18 (((1U << (EXPONENT_BITS_F_14_18 - 2)) - 1) << SIGNIFICAND_BITS_F_14_18) | ((1U << (SIGNIFICAND_BITS_F_14_18 - 2)) - 1)
#define MIN_VALUE_F_14_18 (((1U << (EXPONENT_BITS_F_14_18 - 2)) - 1) << SIGNIFICAND_BITS_F_14_18) | (SIGNIFICAND_SIGN_MASK_F_14_18)

// construct float 1418
f1418_t new_f1418(int32_t exp, int32_t sig);
// construct float 1418
f1418_t new_f1418_from_float32(_Float32 f);
// construct float 1418
f1418_t new_f1418_from_float16(_Float16 f);
// exponent part of float 1418
int32_t exp_f1418(f1418_t a);
// significand part of float 1418
int32_t sig_f1418(f1418_t a);
// add float 1418
f1418_t add_f1418(f1418_t a, f1418_t b);
// subtract float 1418
f1418_t sub_f1418(f1418_t a, f1418_t b);
// negate float 1418
f1418_t neg_f1418(f1418_t a);
// multiply float 1418
f1418_t mul_f1418(f1418_t a, f1418_t b);
// divide float 1418
f1418_t div_f1418(f1418_t a, f1418_t b);
// equals float 1418
bool equ_f1418(f1418_t a, f1418_t b);
// compare float 1418
int com_f1418(f1418_t a, f1418_t b);

#endif // C_FLOAT_14_18_H

