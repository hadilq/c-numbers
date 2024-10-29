#ifndef C_FLOAT_51_13_H
#define C_FLOAT_51_13_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_51_13 51
#define EXPONENT_BITS_F_51_13 13
#define BITS_F_51_13 SIGNIFICAND_BITS_F_51_13 + EXPONENT_BITS_F_51_13

#define C_FLOAT_51_13_DEBUG true

typedef uint64_t f5113_t;

#define SIGNIFICAND_MASK_F_51_13 ((1ULL << SIGNIFICAND_BITS_F_51_13) - 1)
#define SIGNIFICAND_2_MASK_F_51_13 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_51_13) - 1)
#define EXPONENT_MASK_F_51_13 (((1ULL << EXPONENT_BITS_F_51_13) - 1) << SIGNIFICAND_BITS_F_51_13)
#define SIGNIFICAND_SIGN_MASK_F_51_13 (1ULL << (SIGNIFICAND_BITS_F_51_13 - 1))
#define EXPONENT_SIGN_MASK_F_51_13 (1ULL << (EXPONENT_BITS_F_51_13 - 1))
#define BITS_SIGN_MASK_F_51_13 (1ULL << (BITS_F_51_13 - 1))

#define MAX_VALUE_F_51_13 (((1ULL << (EXPONENT_BITS_F_51_13 - 2)) - 1) << SIGNIFICAND_BITS_F_51_13) | ((1ULL << (SIGNIFICAND_BITS_F_51_13 - 2)) - 1)
#define MIN_VALUE_F_51_13 (((1ULL << (EXPONENT_BITS_F_51_13 - 2)) - 1) << SIGNIFICAND_BITS_F_51_13) | (SIGNIFICAND_SIGN_MASK_F_51_13)

// construct float 5113
f5113_t new_f5113(int64_t exp, int64_t sig);
// construct float 5113
f5113_t new_f5113_from_float64(_Float64 f);
// construct float 5113
f5113_t new_f5113_from_float32(_Float32 f);
// construct float 5113
f5113_t new_f5113_from_float16(_Float16 f);
// exponent part of float 5113
int64_t exp_f5113(f5113_t a);
// significand part of float 5113
int64_t sig_f5113(f5113_t a);
// add float 5113
f5113_t add_f5113(f5113_t a, f5113_t b);
// subtract float 5113
f5113_t sub_f5113(f5113_t a, f5113_t b);
// negate float 5113
f5113_t neg_f5113(f5113_t a);
// multiply float 5113
f5113_t mul_f5113(f5113_t a, f5113_t b);
// divide float 5113
f5113_t div_f5113(f5113_t a, f5113_t b);
// equals float 5113
bool equ_f5113(f5113_t a, f5113_t b);
// compare float 5113
int com_f5113(f5113_t a, f5113_t b);

#endif // C_FLOAT_51_13_H

