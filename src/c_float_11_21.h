#ifndef C_FLOAT_11_21_H
#define C_FLOAT_11_21_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_11_21 11
#define EXPONENT_BITS_F_11_21 06
#define BITS_F_11_21 SIGNIFICAND_BITS_F_11_21 + EXPONENT_BITS_F_11_21

#define C_FLOAT_11_21_DEBUG true

typedef uint32_t f1121_t;

#define SIGNIFICAND_MASK_F_11_21 ((1UL << SIGNIFICAND_BITS_F_11_21) - 1)
#define SIGNIFICAND_2_MASK_F_11_21 ((1ULL << 2 * SIGNIFICAND_BITS_F_11_21) - 1)
#define EXPONENT_MASK_F_11_21 (((1UL << EXPONENT_BITS_F_11_21) - 1) << SIGNIFICAND_BITS_F_11_21)
#define SIGNIFICAND_SIGN_MASK_F_11_21 (1UL << (SIGNIFICAND_BITS_F_11_21 - 1))
#define EXPONENT_SIGN_MASK_F_11_21 (1UL << (EXPONENT_BITS_F_11_21 - 1))
#define BITS_SIGN_MASK_F_11_21 (1UL << (BITS_F_11_21 - 1))

#define MAX_VALUE_F_11_21 (((1U << (EXPONENT_BITS_F_11_21 - 2)) - 1) << SIGNIFICAND_BITS_F_11_21) | ((1U << (SIGNIFICAND_BITS_F_11_21 - 2)) - 1)
#define MIN_VALUE_F_11_21 (((1U << (EXPONENT_BITS_F_11_21 - 2)) - 1) << SIGNIFICAND_BITS_F_11_21) | (SIGNIFICAND_SIGN_MASK_F_11_21)

// construct float 1121
f1121_t new_f1121(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 1121
f1121_t new_f1121_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 1121
f1121_t new_f1121_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 1121
int32_t exp_f1121(f1121_t a);
// significand part of float 1121
int32_t sig_f1121(f1121_t a);
// add float 1121
f1121_t add_f1121(f1121_t a, f1121_t b);
// subtract float 1121
f1121_t sub_f1121(f1121_t a, f1121_t b);
// negate float 1121
f1121_t neg_f1121(f1121_t a);
// multiply float 1121
f1121_t mul_f1121(f1121_t a, f1121_t b);
// divide float 1121
f1121_t div_f1121(f1121_t a, f1121_t b);
// equals float 1121
bool equ_f1121(f1121_t a, f1121_t b);
// compare float 1121
int com_f1121(f1121_t a, f1121_t b);

#endif // C_FLOAT_11_21_H

