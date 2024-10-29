#ifndef C_FLOAT_26_06_H
#define C_FLOAT_26_06_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_26_06 26
#define EXPONENT_BITS_F_26_06 06
#define BITS_F_26_06 SIGNIFICAND_BITS_F_26_06 + EXPONENT_BITS_F_26_06

#define C_FLOAT_26_06_DEBUG true

typedef uint32_t f2606_t;

#define SIGNIFICAND_MASK_F_26_06 ((1UL << SIGNIFICAND_BITS_F_26_06) - 1)
#define SIGNIFICAND_2_MASK_F_26_06 ((1ULL << 2 * SIGNIFICAND_BITS_F_26_06) - 1)
#define EXPONENT_MASK_F_26_06 (((1UL << EXPONENT_BITS_F_26_06) - 1) << SIGNIFICAND_BITS_F_26_06)
#define SIGNIFICAND_SIGN_MASK_F_26_06 (1UL << (SIGNIFICAND_BITS_F_26_06 - 1))
#define EXPONENT_SIGN_MASK_F_26_06 (1UL << (EXPONENT_BITS_F_26_06 - 1))
#define BITS_SIGN_MASK_F_26_06 (1UL << (BITS_F_26_06 - 1))

#define MAX_VALUE_F_26_06 (((1U << (EXPONENT_BITS_F_26_06 - 2)) - 1) << SIGNIFICAND_BITS_F_26_06) | ((1U << (SIGNIFICAND_BITS_F_26_06 - 2)) - 1)
#define MIN_VALUE_F_26_06 (((1U << (EXPONENT_BITS_F_26_06 - 2)) - 1) << SIGNIFICAND_BITS_F_26_06) | (SIGNIFICAND_SIGN_MASK_F_26_06)

// construct float 2606
f2606_t new_f2606(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 2606
f2606_t new_f2606_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 2606
f2606_t new_f2606_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 2606
int32_t exp_f2606(f2606_t a);
// significand part of float 2606
int32_t sig_f2606(f2606_t a);
// add float 2606
f2606_t add_f2606(f2606_t a, f2606_t b);
// subtract float 2606
f2606_t sub_f2606(f2606_t a, f2606_t b);
// negate float 2606
f2606_t neg_f2606(f2606_t a);
// multiply float 2606
f2606_t mul_f2606(f2606_t a, f2606_t b);
// divide float 2606
f2606_t div_f2606(f2606_t a, f2606_t b);
// equals float 2606
bool equ_f2606(f2606_t a, f2606_t b);
// compare float 2606
int com_f2606(f2606_t a, f2606_t b);

#endif // C_FLOAT_26_06_H

