#ifndef C_FLOAT_44_20_H
#define C_FLOAT_44_20_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_44_20 44
#define EXPONENT_BITS_F_44_20 20
#define BITS_F_44_20 SIGNIFICAND_BITS_F_44_20 + EXPONENT_BITS_F_44_20

#define C_FLOAT_44_20_DEBUG true

typedef uint64_t f4420_t;

#define SIGNIFICAND_MASK_F_44_20 ((1ULL << SIGNIFICAND_BITS_F_44_20) - 1)
#define SIGNIFICAND_2_MASK_F_44_20 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_44_20) - 1)
#define EXPONENT_MASK_F_44_20 (((1ULL << EXPONENT_BITS_F_44_20) - 1) << SIGNIFICAND_BITS_F_44_20)
#define SIGNIFICAND_SIGN_MASK_F_44_20 (1ULL << (SIGNIFICAND_BITS_F_44_20 - 1))
#define EXPONENT_SIGN_MASK_F_44_20 (1ULL << (EXPONENT_BITS_F_44_20 - 1))
#define BITS_SIGN_MASK_F_44_20 (1ULL << (BITS_F_44_20 - 1))

#define MAX_VALUE_F_44_20 (((1ULL << (EXPONENT_BITS_F_44_20 - 2)) - 1) << SIGNIFICAND_BITS_F_44_20) | ((1ULL << (SIGNIFICAND_BITS_F_44_20 - 2)) - 1)
#define MIN_VALUE_F_44_20 (((1ULL << (EXPONENT_BITS_F_44_20 - 2)) - 1) << SIGNIFICAND_BITS_F_44_20) | (SIGNIFICAND_SIGN_MASK_F_44_20)

// construct float 4420
f4420_t new_f4420(int64_t exp, int64_t sig);
// construct float 4420
f4420_t new_f4420_from_float64(_Float64 f);
// construct float 4420
f4420_t new_f4420_from_float32(_Float32 f);
// construct float 4420
f4420_t new_f4420_from_float16(_Float16 f);
// exponent part of float 4420
int64_t exp_f4420(f4420_t a);
// significand part of float 4420
int64_t sig_f4420(f4420_t a);
// add float 4420
f4420_t add_f4420(f4420_t a, f4420_t b);
// subtract float 4420
f4420_t sub_f4420(f4420_t a, f4420_t b);
// negate float 4420
f4420_t neg_f4420(f4420_t a);
// multiply float 4420
f4420_t mul_f4420(f4420_t a, f4420_t b);
// divide float 4420
f4420_t div_f4420(f4420_t a, f4420_t b);
// equals float 4420
bool equ_f4420(f4420_t a, f4420_t b);
// compare float 4420
int com_f4420(f4420_t a, f4420_t b);

#endif // C_FLOAT_44_20_H

