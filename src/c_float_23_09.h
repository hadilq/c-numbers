#ifndef C_FLOAT_23_09_H
#define C_FLOAT_23_09_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_23_09 23
#define EXPONENT_BITS_F_23_09 06
#define BITS_F_23_09 SIGNIFICAND_BITS_F_23_09 + EXPONENT_BITS_F_23_09

#define C_FLOAT_23_09_DEBUG true

typedef uint32_t f2309_t;

#define SIGNIFICAND_MASK_F_23_09 ((1UL << SIGNIFICAND_BITS_F_23_09) - 1)
#define SIGNIFICAND_2_MASK_F_23_09 ((1ULL << 2 * SIGNIFICAND_BITS_F_23_09) - 1)
#define EXPONENT_MASK_F_23_09 (((1UL << EXPONENT_BITS_F_23_09) - 1) << SIGNIFICAND_BITS_F_23_09)
#define SIGNIFICAND_SIGN_MASK_F_23_09 (1UL << (SIGNIFICAND_BITS_F_23_09 - 1))
#define EXPONENT_SIGN_MASK_F_23_09 (1UL << (EXPONENT_BITS_F_23_09 - 1))
#define BITS_SIGN_MASK_F_23_09 (1UL << (BITS_F_23_09 - 1))

#define MAX_VALUE_F_23_09 (((1U << (EXPONENT_BITS_F_23_09 - 2)) - 1) << SIGNIFICAND_BITS_F_23_09) | ((1U << (SIGNIFICAND_BITS_F_23_09 - 2)) - 1)
#define MIN_VALUE_F_23_09 (((1U << (EXPONENT_BITS_F_23_09 - 2)) - 1) << SIGNIFICAND_BITS_F_23_09) | (SIGNIFICAND_SIGN_MASK_F_23_09)

// construct float 2309
f2309_t new_f2309(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float 2309
f2309_t new_f2309_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float 2309
f2309_t new_f2309_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 2309
int32_t exp_f2309(f2309_t a);
// significand part of float 2309
int32_t sig_f2309(f2309_t a);
// add float 2309
f2309_t add_f2309(f2309_t a, f2309_t b);
// subtract float 2309
f2309_t sub_f2309(f2309_t a, f2309_t b);
// negate float 2309
f2309_t neg_f2309(f2309_t a);
// multiply float 2309
f2309_t mul_f2309(f2309_t a, f2309_t b);
// divide float 2309
f2309_t div_f2309(f2309_t a, f2309_t b);
// equals float 2309
bool equ_f2309(f2309_t a, f2309_t b);
// compare float 2309
int com_f2309(f2309_t a, f2309_t b);

#endif // C_FLOAT_23_09_H

