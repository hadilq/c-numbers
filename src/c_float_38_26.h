#ifndef C_FLOAT_38_26_H
#define C_FLOAT_38_26_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_38_26 38
#define EXPONENT_BITS_F_38_26 26
#define BITS_F_38_26 SIGNIFICAND_BITS_F_38_26 + EXPONENT_BITS_F_38_26

#define C_FLOAT_38_26_DEBUG true

typedef uint64_t f3826_t;

#define SIGNIFICAND_MASK_F_38_26 ((1ULL << SIGNIFICAND_BITS_F_38_26) - 1)
#define SIGNIFICAND_2_MASK_F_38_26 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_38_26) - 1)
#define EXPONENT_MASK_F_38_26 (((1ULL << EXPONENT_BITS_F_38_26) - 1) << SIGNIFICAND_BITS_F_38_26)
#define SIGNIFICAND_SIGN_MASK_F_38_26 (1ULL << (SIGNIFICAND_BITS_F_38_26 - 1))
#define EXPONENT_SIGN_MASK_F_38_26 (1ULL << (EXPONENT_BITS_F_38_26 - 1))
#define BITS_SIGN_MASK_F_38_26 (1ULL << (BITS_F_38_26 - 1))

// construct float 3826
f3826_t new_f3826(uint64_t exp, uint64_t sig);
// exponent part of float 3826
uint64_t exp_f3826(f3826_t a);
// significand part of float 3826
uint64_t sig_f3826(f3826_t a);
// add float 3826
f3826_t add_f3826(f3826_t a, f3826_t b);
// subtract float 3826
f3826_t sub_f3826(f3826_t a, f3826_t b);
// negate float 3826
f3826_t neg_f3826(f3826_t a);
// multiply float 3826
f3826_t mul_f3826(f3826_t a, f3826_t b);
// divide float 3826
f3826_t div_f3826(f3826_t a, f3826_t b);
// equals float 3826
bool equ_f3826(f3826_t a, f3826_t b);
// compare float 3826
int com_f3826(f3826_t a, f3826_t b);

#endif // C_FLOAT_38_26_H

