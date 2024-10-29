#ifndef C_FLOAT_17_15_H
#define C_FLOAT_17_15_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_17_15 17
#define EXPONENT_BITS_F_17_15 06
#define BITS_F_17_15 SIGNIFICAND_BITS_F_17_15 + EXPONENT_BITS_F_17_15

#define C_FLOAT_17_15_DEBUG true

typedef uint32_t f1715_t;

#define SIGNIFICAND_MASK_F_17_15 ((1UL << SIGNIFICAND_BITS_F_17_15) - 1)
#define SIGNIFICAND_2_MASK_F_17_15 ((1ULL << 2 * SIGNIFICAND_BITS_F_17_15) - 1)
#define EXPONENT_MASK_F_17_15 (((1UL << EXPONENT_BITS_F_17_15) - 1) << SIGNIFICAND_BITS_F_17_15)
#define SIGNIFICAND_SIGN_MASK_F_17_15 (1UL << (SIGNIFICAND_BITS_F_17_15 - 1))
#define EXPONENT_SIGN_MASK_F_17_15 (1UL << (EXPONENT_BITS_F_17_15 - 1))
#define BITS_SIGN_MASK_F_17_15 (1UL << (BITS_F_17_15 - 1))

#define MAX_VALUE_F_17_15 (((1U << (EXPONENT_BITS_F_17_15 - 2)) - 1) << SIGNIFICAND_BITS_F_17_15) | ((1U << (SIGNIFICAND_BITS_F_17_15 - 2)) - 1)
#define MIN_VALUE_F_17_15 (((1U << (EXPONENT_BITS_F_17_15 - 2)) - 1) << SIGNIFICAND_BITS_F_17_15) | (SIGNIFICAND_SIGN_MASK_F_17_15)

// construct float 1715
f1715_t new_f1715(int32_t exp, int32_t sig);
// construct float 1715
f1715_t new_f1715_from_float32(_Float32 f);
// construct float 1715
f1715_t new_f1715_from_float16(_Float16 f);
// exponent part of float 1715
int32_t exp_f1715(f1715_t a);
// significand part of float 1715
int32_t sig_f1715(f1715_t a);
// add float 1715
f1715_t add_f1715(f1715_t a, f1715_t b);
// subtract float 1715
f1715_t sub_f1715(f1715_t a, f1715_t b);
// negate float 1715
f1715_t neg_f1715(f1715_t a);
// multiply float 1715
f1715_t mul_f1715(f1715_t a, f1715_t b);
// divide float 1715
f1715_t div_f1715(f1715_t a, f1715_t b);
// equals float 1715
bool equ_f1715(f1715_t a, f1715_t b);
// compare float 1715
int com_f1715(f1715_t a, f1715_t b);

#endif // C_FLOAT_17_15_H

