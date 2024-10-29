#ifndef C_FLOAT_05_27_H
#define C_FLOAT_05_27_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_05_27 5
#define EXPONENT_BITS_F_05_27 06
#define BITS_F_05_27 SIGNIFICAND_BITS_F_05_27 + EXPONENT_BITS_F_05_27

#define C_FLOAT_05_27_DEBUG true

typedef uint32_t f0527_t;

#define SIGNIFICAND_MASK_F_05_27 ((1UL << SIGNIFICAND_BITS_F_05_27) - 1)
#define SIGNIFICAND_2_MASK_F_05_27 ((1ULL << 2 * SIGNIFICAND_BITS_F_05_27) - 1)
#define EXPONENT_MASK_F_05_27 (((1UL << EXPONENT_BITS_F_05_27) - 1) << SIGNIFICAND_BITS_F_05_27)
#define SIGNIFICAND_SIGN_MASK_F_05_27 (1UL << (SIGNIFICAND_BITS_F_05_27 - 1))
#define EXPONENT_SIGN_MASK_F_05_27 (1UL << (EXPONENT_BITS_F_05_27 - 1))
#define BITS_SIGN_MASK_F_05_27 (1UL << (BITS_F_05_27 - 1))

#define MAX_VALUE_F_05_27 (((1U << (EXPONENT_BITS_F_05_27 - 2)) - 1) << SIGNIFICAND_BITS_F_05_27) | ((1U << (SIGNIFICAND_BITS_F_05_27 - 2)) - 1)
#define MIN_VALUE_F_05_27 (((1U << (EXPONENT_BITS_F_05_27 - 2)) - 1) << SIGNIFICAND_BITS_F_05_27) | (SIGNIFICAND_SIGN_MASK_F_05_27)

// construct float 0527
f0527_t new_f0527(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float 0527
f0527_t new_f0527_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float 0527
f0527_t new_f0527_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 0527
int32_t exp_f0527(f0527_t a);
// significand part of float 0527
int32_t sig_f0527(f0527_t a);
// add float 0527
f0527_t add_f0527(f0527_t a, f0527_t b);
// subtract float 0527
f0527_t sub_f0527(f0527_t a, f0527_t b);
// negate float 0527
f0527_t neg_f0527(f0527_t a);
// multiply float 0527
f0527_t mul_f0527(f0527_t a, f0527_t b);
// divide float 0527
f0527_t div_f0527(f0527_t a, f0527_t b);
// equals float 0527
bool equ_f0527(f0527_t a, f0527_t b);
// compare float 0527
int com_f0527(f0527_t a, f0527_t b);

#endif // C_FLOAT_05_27_H

