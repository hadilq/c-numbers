#ifndef C_FLOAT_CCC_64_H
#define C_FLOAT_CCC_64_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_CCC_64 57
#define EXPONENT_BITS_F_CCC_64 7
#define BITS_F_CCC_64 SIGNIFICAND_BITS_F_CCC_64 + EXPONENT_BITS_F_CCC_64

#define C_FLOAT_CCC_64_DEBUG true

typedef uint64_t fDDD64_t;

#define SIGNIFICAND_MASK_F_CCC_64 ((1ULL << SIGNIFICAND_BITS_F_CCC_64) - 1)
#define SIGNIFICAND_2_MASK_F_CCC_64 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_CCC_64) - 1)
#define EXPONENT_MASK_F_CCC_64 (((1ULL << EXPONENT_BITS_F_CCC_64) - 1) << SIGNIFICAND_BITS_F_CCC_64)
#define SIGNIFICAND_SIGN_MASK_F_CCC_64 (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1))
#define EXPONENT_SIGN_MASK_F_CCC_64 (1ULL << (EXPONENT_BITS_F_CCC_64 - 1))
#define BITS_SIGN_MASK_F_CCC_64 (1ULL << (BITS_F_CCC_64 - 1))

#define MAX_VALUE_F_CCC_64 (((1ULL << (EXPONENT_BITS_F_CCC_64 - 2)) - 1) << SIGNIFICAND_BITS_F_CCC_64) | ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) - 1)
#define MIN_VALUE_F_CCC_64 (((1ULL << (EXPONENT_BITS_F_CCC_64 - 2)) - 1) << SIGNIFICAND_BITS_F_CCC_64) | (SIGNIFICAND_SIGN_MASK_F_CCC_64)

// construct float DDD64
fDDD64_t new_fDDD64(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float64)
// construct float DDD64
fDDD64_t new_fDDD64_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float DDD64
fDDD64_t new_fDDD64_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float DDD64
fDDD64_t new_fDDD64_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float DDD64
int64_t exp_fDDD64(fDDD64_t a);
// significand part of float DDD64
int64_t sig_fDDD64(fDDD64_t a);
// add float DDD64
fDDD64_t add_fDDD64(fDDD64_t a, fDDD64_t b);
// subtract float DDD64
fDDD64_t sub_fDDD64(fDDD64_t a, fDDD64_t b);
// negate float DDD64
fDDD64_t neg_fDDD64(fDDD64_t a);
// multiply float DDD64
fDDD64_t mul_fDDD64(fDDD64_t a, fDDD64_t b);
// divide float DDD64
fDDD64_t div_fDDD64(fDDD64_t a, fDDD64_t b);
// equals float DDD64
bool equ_fDDD64(fDDD64_t a, fDDD64_t b);
// compare float DDD64
int com_fDDD64(fDDD64_t a, fDDD64_t b);

#endif // C_FLOAT_CCC_64_H

