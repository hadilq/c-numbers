#ifndef C_FLOAT_11_53_H
#define C_FLOAT_11_53_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_11_53 11
#define EXPONENT_BITS_F_11_53 53
#define BITS_F_11_53 SIGNIFICAND_BITS_F_11_53 + EXPONENT_BITS_F_11_53

#define C_FLOAT_11_53_DEBUG true

typedef uint64_t f1153_t;

#define SIGNIFICAND_MASK_F_11_53 ((1ULL << SIGNIFICAND_BITS_F_11_53) - 1)
#define SIGNIFICAND_2_MASK_F_11_53 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_11_53) - 1)
#define EXPONENT_MASK_F_11_53 (((1ULL << EXPONENT_BITS_F_11_53) - 1) << SIGNIFICAND_BITS_F_11_53)
#define SIGNIFICAND_SIGN_MASK_F_11_53 (1ULL << (SIGNIFICAND_BITS_F_11_53 - 1))
#define EXPONENT_SIGN_MASK_F_11_53 (1ULL << (EXPONENT_BITS_F_11_53 - 1))
#define BITS_SIGN_MASK_F_11_53 (1ULL << (BITS_F_11_53 - 1))

// construct float 1153
f1153_t new_f1153(uint64_t exp, uint64_t sig);
// exponent part of float 1153
uint64_t exp_f1153(f1153_t a);
// significand part of float 1153
uint64_t sig_f1153(f1153_t a);
// add float 1153
f1153_t add_f1153(f1153_t a, f1153_t b);
// subtract float 1153
f1153_t sub_f1153(f1153_t a, f1153_t b);
// negate float 1153
f1153_t neg_f1153(f1153_t a);
// multiply float 1153
f1153_t mul_f1153(f1153_t a, f1153_t b);
// divide float 1153
f1153_t div_f1153(f1153_t a, f1153_t b);
// equals float 1153
bool equ_f1153(f1153_t a, f1153_t b);
// compare float 1153
int com_f1153(f1153_t a, f1153_t b);

#endif // C_FLOAT_11_53_H

