#ifndef C_FLOAT_10_22_H
#define C_FLOAT_10_22_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_10_22 10
#define EXPONENT_BITS_F_10_22 06
#define BITS_F_10_22 SIGNIFICAND_BITS_F_10_22 + EXPONENT_BITS_F_10_22

#define C_FLOAT_10_22_DEBUG true

typedef uint32_t f1022_t;

#define SIGNIFICAND_MASK_F_10_22 ((1UL << SIGNIFICAND_BITS_F_10_22) - 1)
#define SIGNIFICAND_2_MASK_F_10_22 ((1ULL << 2 * SIGNIFICAND_BITS_F_10_22) - 1)
#define EXPONENT_MASK_F_10_22 (((1UL << EXPONENT_BITS_F_10_22) - 1) << SIGNIFICAND_BITS_F_10_22)
#define SIGNIFICAND_SIGN_MASK_F_10_22 (1UL << (SIGNIFICAND_BITS_F_10_22 - 1))
#define EXPONENT_SIGN_MASK_F_10_22 (1UL << (EXPONENT_BITS_F_10_22 - 1))
#define BITS_SIGN_MASK_F_10_22 (1UL << (BITS_F_10_22 - 1))

#define MAX_VALUE_F_10_22 (((1U << (EXPONENT_BITS_F_10_22 - 2)) - 1) << SIGNIFICAND_BITS_F_10_22) | ((1U << (SIGNIFICAND_BITS_F_10_22 - 2)) - 1)
#define MIN_VALUE_F_10_22 (((1U << (EXPONENT_BITS_F_10_22 - 2)) - 1) << SIGNIFICAND_BITS_F_10_22) | (SIGNIFICAND_SIGN_MASK_F_10_22)

// construct float 1022
f1022_t new_f1022(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 1022
f1022_t new_f1022_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 1022
f1022_t new_f1022_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 1022
int32_t exp_f1022(f1022_t a);
// significand part of float 1022
int32_t sig_f1022(f1022_t a);
// add float 1022
f1022_t add_f1022(f1022_t a, f1022_t b);
// subtract float 1022
f1022_t sub_f1022(f1022_t a, f1022_t b);
// negate float 1022
f1022_t neg_f1022(f1022_t a);
// multiply float 1022
f1022_t mul_f1022(f1022_t a, f1022_t b);
// divide float 1022
f1022_t div_f1022(f1022_t a, f1022_t b);
// equals float 1022
bool equ_f1022(f1022_t a, f1022_t b);
// compare float 1022
int com_f1022(f1022_t a, f1022_t b);

#endif // C_FLOAT_10_22_H

