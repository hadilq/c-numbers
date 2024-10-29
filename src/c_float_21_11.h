#ifndef C_FLOAT_21_11_H
#define C_FLOAT_21_11_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_21_11 21
#define EXPONENT_BITS_F_21_11 06
#define BITS_F_21_11 SIGNIFICAND_BITS_F_21_11 + EXPONENT_BITS_F_21_11

#define C_FLOAT_21_11_DEBUG true

typedef uint32_t f2111_t;

#define SIGNIFICAND_MASK_F_21_11 ((1UL << SIGNIFICAND_BITS_F_21_11) - 1)
#define SIGNIFICAND_2_MASK_F_21_11 ((1ULL << 2 * SIGNIFICAND_BITS_F_21_11) - 1)
#define EXPONENT_MASK_F_21_11 (((1UL << EXPONENT_BITS_F_21_11) - 1) << SIGNIFICAND_BITS_F_21_11)
#define SIGNIFICAND_SIGN_MASK_F_21_11 (1UL << (SIGNIFICAND_BITS_F_21_11 - 1))
#define EXPONENT_SIGN_MASK_F_21_11 (1UL << (EXPONENT_BITS_F_21_11 - 1))
#define BITS_SIGN_MASK_F_21_11 (1UL << (BITS_F_21_11 - 1))

#define MAX_VALUE_F_21_11 (((1U << (EXPONENT_BITS_F_21_11 - 2)) - 1) << SIGNIFICAND_BITS_F_21_11) | ((1U << (SIGNIFICAND_BITS_F_21_11 - 2)) - 1)
#define MIN_VALUE_F_21_11 (((1U << (EXPONENT_BITS_F_21_11 - 2)) - 1) << SIGNIFICAND_BITS_F_21_11) | (SIGNIFICAND_SIGN_MASK_F_21_11)

// construct float 2111
f2111_t new_f2111(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 2111
f2111_t new_f2111_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 2111
f2111_t new_f2111_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 2111
int32_t exp_f2111(f2111_t a);
// significand part of float 2111
int32_t sig_f2111(f2111_t a);
// add float 2111
f2111_t add_f2111(f2111_t a, f2111_t b);
// subtract float 2111
f2111_t sub_f2111(f2111_t a, f2111_t b);
// negate float 2111
f2111_t neg_f2111(f2111_t a);
// multiply float 2111
f2111_t mul_f2111(f2111_t a, f2111_t b);
// divide float 2111
f2111_t div_f2111(f2111_t a, f2111_t b);
// equals float 2111
bool equ_f2111(f2111_t a, f2111_t b);
// compare float 2111
int com_f2111(f2111_t a, f2111_t b);

#endif // C_FLOAT_21_11_H

