#ifndef C_FLOAT_06_26_H
#define C_FLOAT_06_26_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_06_26 6
#define EXPONENT_BITS_F_06_26 06
#define BITS_F_06_26 SIGNIFICAND_BITS_F_06_26 + EXPONENT_BITS_F_06_26

#define C_FLOAT_06_26_DEBUG true

typedef uint32_t f0626_t;

#define SIGNIFICAND_MASK_F_06_26 ((1UL << SIGNIFICAND_BITS_F_06_26) - 1)
#define SIGNIFICAND_2_MASK_F_06_26 ((1ULL << 2 * SIGNIFICAND_BITS_F_06_26) - 1)
#define EXPONENT_MASK_F_06_26 (((1UL << EXPONENT_BITS_F_06_26) - 1) << SIGNIFICAND_BITS_F_06_26)
#define SIGNIFICAND_SIGN_MASK_F_06_26 (1UL << (SIGNIFICAND_BITS_F_06_26 - 1))
#define EXPONENT_SIGN_MASK_F_06_26 (1UL << (EXPONENT_BITS_F_06_26 - 1))
#define BITS_SIGN_MASK_F_06_26 (1UL << (BITS_F_06_26 - 1))

#define MAX_VALUE_F_06_26 (((1U << (EXPONENT_BITS_F_06_26 - 2)) - 1) << SIGNIFICAND_BITS_F_06_26) | ((1U << (SIGNIFICAND_BITS_F_06_26 - 2)) - 1)
#define MIN_VALUE_F_06_26 (((1U << (EXPONENT_BITS_F_06_26 - 2)) - 1) << SIGNIFICAND_BITS_F_06_26) | (SIGNIFICAND_SIGN_MASK_F_06_26)

// construct float 0626
f0626_t new_f0626(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 0626
f0626_t new_f0626_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 0626
f0626_t new_f0626_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 0626
int32_t exp_f0626(f0626_t a);
// significand part of float 0626
int32_t sig_f0626(f0626_t a);
// add float 0626
f0626_t add_f0626(f0626_t a, f0626_t b);
// subtract float 0626
f0626_t sub_f0626(f0626_t a, f0626_t b);
// negate float 0626
f0626_t neg_f0626(f0626_t a);
// multiply float 0626
f0626_t mul_f0626(f0626_t a, f0626_t b);
// divide float 0626
f0626_t div_f0626(f0626_t a, f0626_t b);
// equals float 0626
bool equ_f0626(f0626_t a, f0626_t b);
// compare float 0626
int com_f0626(f0626_t a, f0626_t b);

#endif // C_FLOAT_06_26_H

