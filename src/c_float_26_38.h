#ifndef C_FLOAT_26_38_H
#define C_FLOAT_26_38_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_26_38 26
#define EXPONENT_BITS_F_26_38 38
#define BITS_F_26_38 SIGNIFICAND_BITS_F_26_38 + EXPONENT_BITS_F_26_38

#define C_FLOAT_26_38_DEBUG true

typedef uint64_t f2638_t;

#define SIGNIFICAND_MASK_F_26_38 ((1ULL << SIGNIFICAND_BITS_F_26_38) - 1)
#define SIGNIFICAND_2_MASK_F_26_38 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_26_38) - 1)
#define EXPONENT_MASK_F_26_38 (((1ULL << EXPONENT_BITS_F_26_38) - 1) << SIGNIFICAND_BITS_F_26_38)
#define SIGNIFICAND_SIGN_MASK_F_26_38 (1ULL << (SIGNIFICAND_BITS_F_26_38 - 1))
#define EXPONENT_SIGN_MASK_F_26_38 (1ULL << (EXPONENT_BITS_F_26_38 - 1))
#define BITS_SIGN_MASK_F_26_38 (1ULL << (BITS_F_26_38 - 1))

// construct float 2638
f2638_t new_f2638(uint64_t exp, uint64_t sig);
// exponent part of float 2638
uint64_t exp_f2638(f2638_t a);
// significand part of float 2638
uint64_t sig_f2638(f2638_t a);
// add float 2638
f2638_t add_f2638(f2638_t a, f2638_t b);
// subtract float 2638
f2638_t sub_f2638(f2638_t a, f2638_t b);
// negate float 2638
f2638_t neg_f2638(f2638_t a);
// multiply float 2638
f2638_t mul_f2638(f2638_t a, f2638_t b);
// divide float 2638
f2638_t div_f2638(f2638_t a, f2638_t b);
// equals float 2638
bool equ_f2638(f2638_t a, f2638_t b);
// compare float 2638
int com_f2638(f2638_t a, f2638_t b);

#endif // C_FLOAT_26_38_H

