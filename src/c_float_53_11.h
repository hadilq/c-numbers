#ifndef C_FLOAT_53_11_H
#define C_FLOAT_53_11_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_53_11 53
#define EXPONENT_BITS_F_53_11 11
#define BITS_F_53_11 SIGNIFICAND_BITS_F_53_11 + EXPONENT_BITS_F_53_11

#define C_FLOAT_53_11_DEBUG true

typedef uint64_t f5311_t;

#define SIGNIFICAND_MASK_F_53_11 ((1ULL << SIGNIFICAND_BITS_F_53_11) - 1)
#define SIGNIFICAND_2_MASK_F_53_11 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_53_11) - 1)
#define EXPONENT_MASK_F_53_11 (((1ULL << EXPONENT_BITS_F_53_11) - 1) << SIGNIFICAND_BITS_F_53_11)
#define SIGNIFICAND_SIGN_MASK_F_53_11 (1ULL << (SIGNIFICAND_BITS_F_53_11 - 1))
#define EXPONENT_SIGN_MASK_F_53_11 (1ULL << (EXPONENT_BITS_F_53_11 - 1))
#define BITS_SIGN_MASK_F_53_11 (1ULL << (BITS_F_53_11 - 1))

#define MAX_VALUE_F_53_11 (((1ULL << (EXPONENT_BITS_F_53_11 - 2)) - 1) << SIGNIFICAND_BITS_F_53_11) | ((1ULL << (SIGNIFICAND_BITS_F_53_11 - 2)) - 1)
#define MIN_VALUE_F_53_11 (((1ULL << (EXPONENT_BITS_F_53_11 - 2)) - 1) << SIGNIFICAND_BITS_F_53_11) | (SIGNIFICAND_SIGN_MASK_F_53_11)

// construct float 5311
f5311_t new_f5311(int64_t exp, int64_t sig);
// construct float 5311
f5311_t new_f5311_from_float64(_Float64 f);
// construct float 5311
f5311_t new_f5311_from_float32(_Float32 f);
// construct float 5311
f5311_t new_f5311_from_float16(_Float16 f);
// exponent part of float 5311
int64_t exp_f5311(f5311_t a);
// significand part of float 5311
int64_t sig_f5311(f5311_t a);
// add float 5311
f5311_t add_f5311(f5311_t a, f5311_t b);
// subtract float 5311
f5311_t sub_f5311(f5311_t a, f5311_t b);
// negate float 5311
f5311_t neg_f5311(f5311_t a);
// multiply float 5311
f5311_t mul_f5311(f5311_t a, f5311_t b);
// divide float 5311
f5311_t div_f5311(f5311_t a, f5311_t b);
// equals float 5311
bool equ_f5311(f5311_t a, f5311_t b);
// compare float 5311
int com_f5311(f5311_t a, f5311_t b);

#endif // C_FLOAT_53_11_H

