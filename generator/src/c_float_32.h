#ifndef C_FLOAT_CCC_32_H
#define C_FLOAT_CCC_32_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_CCC_32 26
#define EXPONENT_BITS_F_CCC_32 06
#define BITS_F_CCC_32 SIGNIFICAND_BITS_F_CCC_32 + EXPONENT_BITS_F_CCC_32

#define C_FLOAT_CCC_32_DEBUG true

typedef uint32_t fDDD32_t;

#define SIGNIFICAND_MASK_F_CCC_32 ((1UL << SIGNIFICAND_BITS_F_CCC_32) - 1)
#define SIGNIFICAND_2_MASK_F_CCC_32 ((1ULL << 2 * SIGNIFICAND_BITS_F_CCC_32) - 1)
#define EXPONENT_MASK_F_CCC_32 (((1UL << EXPONENT_BITS_F_CCC_32) - 1) << SIGNIFICAND_BITS_F_CCC_32)
#define SIGNIFICAND_SIGN_MASK_F_CCC_32 (1UL << (SIGNIFICAND_BITS_F_CCC_32 - 1))
#define EXPONENT_SIGN_MASK_F_CCC_32 (1UL << (EXPONENT_BITS_F_CCC_32 - 1))
#define BITS_SIGN_MASK_F_CCC_32 (1UL << (BITS_F_CCC_32 - 1))

#define MAX_VALUE_F_CCC_32 (((1U << (EXPONENT_BITS_F_CCC_32 - 2)) - 1) << SIGNIFICAND_BITS_F_CCC_32) | ((1U << (SIGNIFICAND_BITS_F_CCC_32 - 2)) - 1)
#define MIN_VALUE_F_CCC_32 (((1U << (EXPONENT_BITS_F_CCC_32 - 2)) - 1) << SIGNIFICAND_BITS_F_CCC_32) | (SIGNIFICAND_SIGN_MASK_F_CCC_32)

// construct float DDD32
fDDD32_t new_fDDD32(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float DDD32
fDDD32_t new_fDDD32_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float DDD32
fDDD32_t new_fDDD32_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float DDD32
int32_t exp_fDDD32(fDDD32_t a);
// significand part of float DDD32
int32_t sig_fDDD32(fDDD32_t a);
// add float DDD32
fDDD32_t add_fDDD32(fDDD32_t a, fDDD32_t b);
// subtract float DDD32
fDDD32_t sub_fDDD32(fDDD32_t a, fDDD32_t b);
// negate float DDD32
fDDD32_t neg_fDDD32(fDDD32_t a);
// multiply float DDD32
fDDD32_t mul_fDDD32(fDDD32_t a, fDDD32_t b);
// divide float DDD32
fDDD32_t div_fDDD32(fDDD32_t a, fDDD32_t b);
// equals float DDD32
bool equ_fDDD32(fDDD32_t a, fDDD32_t b);
// compare float DDD32
int com_fDDD32(fDDD32_t a, fDDD32_t b);

#endif // C_FLOAT_CCC_32_H

