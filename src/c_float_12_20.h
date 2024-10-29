#ifndef C_FLOAT_12_20_H
#define C_FLOAT_12_20_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_12_20 12
#define EXPONENT_BITS_F_12_20 06
#define BITS_F_12_20 SIGNIFICAND_BITS_F_12_20 + EXPONENT_BITS_F_12_20

#define C_FLOAT_12_20_DEBUG true

typedef uint32_t f1220_t;

#define SIGNIFICAND_MASK_F_12_20 ((1UL << SIGNIFICAND_BITS_F_12_20) - 1)
#define SIGNIFICAND_2_MASK_F_12_20 ((1ULL << 2 * SIGNIFICAND_BITS_F_12_20) - 1)
#define EXPONENT_MASK_F_12_20 (((1UL << EXPONENT_BITS_F_12_20) - 1) << SIGNIFICAND_BITS_F_12_20)
#define SIGNIFICAND_SIGN_MASK_F_12_20 (1UL << (SIGNIFICAND_BITS_F_12_20 - 1))
#define EXPONENT_SIGN_MASK_F_12_20 (1UL << (EXPONENT_BITS_F_12_20 - 1))
#define BITS_SIGN_MASK_F_12_20 (1UL << (BITS_F_12_20 - 1))

#define MAX_VALUE_F_12_20 (((1U << (EXPONENT_BITS_F_12_20 - 2)) - 1) << SIGNIFICAND_BITS_F_12_20) | ((1U << (SIGNIFICAND_BITS_F_12_20 - 2)) - 1)
#define MIN_VALUE_F_12_20 (((1U << (EXPONENT_BITS_F_12_20 - 2)) - 1) << SIGNIFICAND_BITS_F_12_20) | (SIGNIFICAND_SIGN_MASK_F_12_20)

// construct float 1220
f1220_t new_f1220(int32_t exp, int32_t sig);
// construct float 1220
f1220_t new_f1220_from_float32(_Float32 f);
// construct float 1220
f1220_t new_f1220_from_float16(_Float16 f);
// exponent part of float 1220
int32_t exp_f1220(f1220_t a);
// significand part of float 1220
int32_t sig_f1220(f1220_t a);
// add float 1220
f1220_t add_f1220(f1220_t a, f1220_t b);
// subtract float 1220
f1220_t sub_f1220(f1220_t a, f1220_t b);
// negate float 1220
f1220_t neg_f1220(f1220_t a);
// multiply float 1220
f1220_t mul_f1220(f1220_t a, f1220_t b);
// divide float 1220
f1220_t div_f1220(f1220_t a, f1220_t b);
// equals float 1220
bool equ_f1220(f1220_t a, f1220_t b);
// compare float 1220
int com_f1220(f1220_t a, f1220_t b);

#endif // C_FLOAT_12_20_H

