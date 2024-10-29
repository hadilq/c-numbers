#ifndef C_FLOAT_07_25_H
#define C_FLOAT_07_25_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_07_25 7
#define EXPONENT_BITS_F_07_25 06
#define BITS_F_07_25 SIGNIFICAND_BITS_F_07_25 + EXPONENT_BITS_F_07_25

#define C_FLOAT_07_25_DEBUG true

typedef uint32_t f0725_t;

#define SIGNIFICAND_MASK_F_07_25 ((1UL << SIGNIFICAND_BITS_F_07_25) - 1)
#define SIGNIFICAND_2_MASK_F_07_25 ((1ULL << 2 * SIGNIFICAND_BITS_F_07_25) - 1)
#define EXPONENT_MASK_F_07_25 (((1UL << EXPONENT_BITS_F_07_25) - 1) << SIGNIFICAND_BITS_F_07_25)
#define SIGNIFICAND_SIGN_MASK_F_07_25 (1UL << (SIGNIFICAND_BITS_F_07_25 - 1))
#define EXPONENT_SIGN_MASK_F_07_25 (1UL << (EXPONENT_BITS_F_07_25 - 1))
#define BITS_SIGN_MASK_F_07_25 (1UL << (BITS_F_07_25 - 1))

#define MAX_VALUE_F_07_25 (((1U << (EXPONENT_BITS_F_07_25 - 2)) - 1) << SIGNIFICAND_BITS_F_07_25) | ((1U << (SIGNIFICAND_BITS_F_07_25 - 2)) - 1)
#define MIN_VALUE_F_07_25 (((1U << (EXPONENT_BITS_F_07_25 - 2)) - 1) << SIGNIFICAND_BITS_F_07_25) | (SIGNIFICAND_SIGN_MASK_F_07_25)

// construct float 0725
f0725_t new_f0725(int32_t exp, int32_t sig);
// construct float 0725
f0725_t new_f0725_from_float32(_Float32 f);
// construct float 0725
f0725_t new_f0725_from_float16(_Float16 f);
// exponent part of float 0725
int32_t exp_f0725(f0725_t a);
// significand part of float 0725
int32_t sig_f0725(f0725_t a);
// add float 0725
f0725_t add_f0725(f0725_t a, f0725_t b);
// subtract float 0725
f0725_t sub_f0725(f0725_t a, f0725_t b);
// negate float 0725
f0725_t neg_f0725(f0725_t a);
// multiply float 0725
f0725_t mul_f0725(f0725_t a, f0725_t b);
// divide float 0725
f0725_t div_f0725(f0725_t a, f0725_t b);
// equals float 0725
bool equ_f0725(f0725_t a, f0725_t b);
// compare float 0725
int com_f0725(f0725_t a, f0725_t b);

#endif // C_FLOAT_07_25_H

