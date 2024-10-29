#ifndef C_FLOAT_08_56_H
#define C_FLOAT_08_56_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_08_56 8
#define EXPONENT_BITS_F_08_56 56
#define BITS_F_08_56 SIGNIFICAND_BITS_F_08_56 + EXPONENT_BITS_F_08_56

#define C_FLOAT_08_56_DEBUG true

typedef uint64_t f0856_t;

#define SIGNIFICAND_MASK_F_08_56 ((1ULL << SIGNIFICAND_BITS_F_08_56) - 1)
#define SIGNIFICAND_2_MASK_F_08_56 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_08_56) - 1)
#define EXPONENT_MASK_F_08_56 (((1ULL << EXPONENT_BITS_F_08_56) - 1) << SIGNIFICAND_BITS_F_08_56)
#define SIGNIFICAND_SIGN_MASK_F_08_56 (1ULL << (SIGNIFICAND_BITS_F_08_56 - 1))
#define EXPONENT_SIGN_MASK_F_08_56 (1ULL << (EXPONENT_BITS_F_08_56 - 1))
#define BITS_SIGN_MASK_F_08_56 (1ULL << (BITS_F_08_56 - 1))

#define MAX_VALUE_F_08_56 (((1ULL << (EXPONENT_BITS_F_08_56 - 2)) - 1) << SIGNIFICAND_BITS_F_08_56) | ((1ULL << (SIGNIFICAND_BITS_F_08_56 - 2)) - 1)
#define MIN_VALUE_F_08_56 (((1ULL << (EXPONENT_BITS_F_08_56 - 2)) - 1) << SIGNIFICAND_BITS_F_08_56) | (SIGNIFICAND_SIGN_MASK_F_08_56)

// construct float 0856
f0856_t new_f0856(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float64)
// construct float 0856
f0856_t new_f0856_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 0856
f0856_t new_f0856_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 0856
f0856_t new_f0856_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 0856
int64_t exp_f0856(f0856_t a);
// significand part of float 0856
int64_t sig_f0856(f0856_t a);
// add float 0856
f0856_t add_f0856(f0856_t a, f0856_t b);
// subtract float 0856
f0856_t sub_f0856(f0856_t a, f0856_t b);
// negate float 0856
f0856_t neg_f0856(f0856_t a);
// multiply float 0856
f0856_t mul_f0856(f0856_t a, f0856_t b);
// divide float 0856
f0856_t div_f0856(f0856_t a, f0856_t b);
// equals float 0856
bool equ_f0856(f0856_t a, f0856_t b);
// compare float 0856
int com_f0856(f0856_t a, f0856_t b);

#endif // C_FLOAT_08_56_H

