#ifndef C_FLOAT_07_57_H
#define C_FLOAT_07_57_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_07_57 7
#define EXPONENT_BITS_F_07_57 57
#define BITS_F_07_57 SIGNIFICAND_BITS_F_07_57 + EXPONENT_BITS_F_07_57

#define C_FLOAT_07_57_DEBUG true

typedef uint64_t f0757_t;

#define SIGNIFICAND_MASK_F_07_57 ((1ULL << SIGNIFICAND_BITS_F_07_57) - 1)
#define SIGNIFICAND_2_MASK_F_07_57 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_07_57) - 1)
#define EXPONENT_MASK_F_07_57 (((1ULL << EXPONENT_BITS_F_07_57) - 1) << SIGNIFICAND_BITS_F_07_57)
#define SIGNIFICAND_SIGN_MASK_F_07_57 (1ULL << (SIGNIFICAND_BITS_F_07_57 - 1))
#define EXPONENT_SIGN_MASK_F_07_57 (1ULL << (EXPONENT_BITS_F_07_57 - 1))
#define BITS_SIGN_MASK_F_07_57 (1ULL << (BITS_F_07_57 - 1))

#define MAX_VALUE_F_07_57 (((1ULL << (EXPONENT_BITS_F_07_57 - 2)) - 1) << SIGNIFICAND_BITS_F_07_57) | ((1ULL << (SIGNIFICAND_BITS_F_07_57 - 2)) - 1)
#define MIN_VALUE_F_07_57 (((1ULL << (EXPONENT_BITS_F_07_57 - 2)) - 1) << SIGNIFICAND_BITS_F_07_57) | (SIGNIFICAND_SIGN_MASK_F_07_57)

// construct float 0757
f0757_t new_f0757(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float64)
// construct float 0757
f0757_t new_f0757_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 0757
f0757_t new_f0757_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 0757
f0757_t new_f0757_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 0757
int64_t exp_f0757(f0757_t a);
// significand part of float 0757
int64_t sig_f0757(f0757_t a);
// add float 0757
f0757_t add_f0757(f0757_t a, f0757_t b);
// subtract float 0757
f0757_t sub_f0757(f0757_t a, f0757_t b);
// negate float 0757
f0757_t neg_f0757(f0757_t a);
// multiply float 0757
f0757_t mul_f0757(f0757_t a, f0757_t b);
// divide float 0757
f0757_t div_f0757(f0757_t a, f0757_t b);
// equals float 0757
bool equ_f0757(f0757_t a, f0757_t b);
// compare float 0757
int com_f0757(f0757_t a, f0757_t b);

#endif // C_FLOAT_07_57_H

