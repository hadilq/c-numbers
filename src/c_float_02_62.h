#ifndef C_FLOAT_02_62_H
#define C_FLOAT_02_62_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_02_62 2
#define EXPONENT_BITS_F_02_62 62
#define BITS_F_02_62 SIGNIFICAND_BITS_F_02_62 + EXPONENT_BITS_F_02_62

#define C_FLOAT_02_62_DEBUG true

typedef uint64_t f0262_t;

#define SIGNIFICAND_MASK_F_02_62 ((1ULL << SIGNIFICAND_BITS_F_02_62) - 1)
#define SIGNIFICAND_2_MASK_F_02_62 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_02_62) - 1)
#define EXPONENT_MASK_F_02_62 (((1ULL << EXPONENT_BITS_F_02_62) - 1) << SIGNIFICAND_BITS_F_02_62)
#define SIGNIFICAND_SIGN_MASK_F_02_62 (1ULL << (SIGNIFICAND_BITS_F_02_62 - 1))
#define EXPONENT_SIGN_MASK_F_02_62 (1ULL << (EXPONENT_BITS_F_02_62 - 1))
#define BITS_SIGN_MASK_F_02_62 (1ULL << (BITS_F_02_62 - 1))

#define MAX_VALUE_F_02_62 (((1ULL << (EXPONENT_BITS_F_02_62 - 2)) - 1) << SIGNIFICAND_BITS_F_02_62) | ((1ULL << (SIGNIFICAND_BITS_F_02_62 - 2)) - 1)
#define MIN_VALUE_F_02_62 (((1ULL << (EXPONENT_BITS_F_02_62 - 2)) - 1) << SIGNIFICAND_BITS_F_02_62) | (SIGNIFICAND_SIGN_MASK_F_02_62)

// construct float 0262
f0262_t new_f0262(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float64)
// construct float 0262
f0262_t new_f0262_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 0262
f0262_t new_f0262_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 0262
f0262_t new_f0262_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 0262
int64_t exp_f0262(f0262_t a);
// significand part of float 0262
int64_t sig_f0262(f0262_t a);
// add float 0262
f0262_t add_f0262(f0262_t a, f0262_t b);
// subtract float 0262
f0262_t sub_f0262(f0262_t a, f0262_t b);
// negate float 0262
f0262_t neg_f0262(f0262_t a);
// multiply float 0262
f0262_t mul_f0262(f0262_t a, f0262_t b);
// divide float 0262
f0262_t div_f0262(f0262_t a, f0262_t b);
// equals float 0262
bool equ_f0262(f0262_t a, f0262_t b);
// compare float 0262
int com_f0262(f0262_t a, f0262_t b);

#endif // C_FLOAT_02_62_H

