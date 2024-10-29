#ifndef C_FLOAT_13_19_H
#define C_FLOAT_13_19_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_13_19 13
#define EXPONENT_BITS_F_13_19 06
#define BITS_F_13_19 SIGNIFICAND_BITS_F_13_19 + EXPONENT_BITS_F_13_19

#define C_FLOAT_13_19_DEBUG true

typedef uint32_t f1319_t;

#define SIGNIFICAND_MASK_F_13_19 ((1UL << SIGNIFICAND_BITS_F_13_19) - 1)
#define SIGNIFICAND_2_MASK_F_13_19 ((1ULL << 2 * SIGNIFICAND_BITS_F_13_19) - 1)
#define EXPONENT_MASK_F_13_19 (((1UL << EXPONENT_BITS_F_13_19) - 1) << SIGNIFICAND_BITS_F_13_19)
#define SIGNIFICAND_SIGN_MASK_F_13_19 (1UL << (SIGNIFICAND_BITS_F_13_19 - 1))
#define EXPONENT_SIGN_MASK_F_13_19 (1UL << (EXPONENT_BITS_F_13_19 - 1))
#define BITS_SIGN_MASK_F_13_19 (1UL << (BITS_F_13_19 - 1))

#define MAX_VALUE_F_13_19 (((1U << (EXPONENT_BITS_F_13_19 - 2)) - 1) << SIGNIFICAND_BITS_F_13_19) | ((1U << (SIGNIFICAND_BITS_F_13_19 - 2)) - 1)
#define MIN_VALUE_F_13_19 (((1U << (EXPONENT_BITS_F_13_19 - 2)) - 1) << SIGNIFICAND_BITS_F_13_19) | (SIGNIFICAND_SIGN_MASK_F_13_19)

// construct float 1319
f1319_t new_f1319(int32_t exp, int32_t sig);
// construct float 1319
f1319_t new_f1319_from_float32(_Float32 f);
// construct float 1319
f1319_t new_f1319_from_float16(_Float16 f);
// exponent part of float 1319
int32_t exp_f1319(f1319_t a);
// significand part of float 1319
int32_t sig_f1319(f1319_t a);
// add float 1319
f1319_t add_f1319(f1319_t a, f1319_t b);
// subtract float 1319
f1319_t sub_f1319(f1319_t a, f1319_t b);
// negate float 1319
f1319_t neg_f1319(f1319_t a);
// multiply float 1319
f1319_t mul_f1319(f1319_t a, f1319_t b);
// divide float 1319
f1319_t div_f1319(f1319_t a, f1319_t b);
// equals float 1319
bool equ_f1319(f1319_t a, f1319_t b);
// compare float 1319
int com_f1319(f1319_t a, f1319_t b);

#endif // C_FLOAT_13_19_H

