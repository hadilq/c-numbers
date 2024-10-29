#ifndef C_FLOAT_04_28_H
#define C_FLOAT_04_28_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_04_28 4
#define EXPONENT_BITS_F_04_28 06
#define BITS_F_04_28 SIGNIFICAND_BITS_F_04_28 + EXPONENT_BITS_F_04_28

#define C_FLOAT_04_28_DEBUG true

typedef uint32_t f0428_t;

#define SIGNIFICAND_MASK_F_04_28 ((1UL << SIGNIFICAND_BITS_F_04_28) - 1)
#define SIGNIFICAND_2_MASK_F_04_28 ((1ULL << 2 * SIGNIFICAND_BITS_F_04_28) - 1)
#define EXPONENT_MASK_F_04_28 (((1UL << EXPONENT_BITS_F_04_28) - 1) << SIGNIFICAND_BITS_F_04_28)
#define SIGNIFICAND_SIGN_MASK_F_04_28 (1UL << (SIGNIFICAND_BITS_F_04_28 - 1))
#define EXPONENT_SIGN_MASK_F_04_28 (1UL << (EXPONENT_BITS_F_04_28 - 1))
#define BITS_SIGN_MASK_F_04_28 (1UL << (BITS_F_04_28 - 1))

#define MAX_VALUE_F_04_28 (((1U << (EXPONENT_BITS_F_04_28 - 2)) - 1) << SIGNIFICAND_BITS_F_04_28) | ((1U << (SIGNIFICAND_BITS_F_04_28 - 2)) - 1)
#define MIN_VALUE_F_04_28 (((1U << (EXPONENT_BITS_F_04_28 - 2)) - 1) << SIGNIFICAND_BITS_F_04_28) | (SIGNIFICAND_SIGN_MASK_F_04_28)

// construct float 0428
f0428_t new_f0428(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float 0428
f0428_t new_f0428_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float 0428
f0428_t new_f0428_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 0428
int32_t exp_f0428(f0428_t a);
// significand part of float 0428
int32_t sig_f0428(f0428_t a);
// add float 0428
f0428_t add_f0428(f0428_t a, f0428_t b);
// subtract float 0428
f0428_t sub_f0428(f0428_t a, f0428_t b);
// negate float 0428
f0428_t neg_f0428(f0428_t a);
// multiply float 0428
f0428_t mul_f0428(f0428_t a, f0428_t b);
// divide float 0428
f0428_t div_f0428(f0428_t a, f0428_t b);
// equals float 0428
bool equ_f0428(f0428_t a, f0428_t b);
// compare float 0428
int com_f0428(f0428_t a, f0428_t b);

#endif // C_FLOAT_04_28_H

