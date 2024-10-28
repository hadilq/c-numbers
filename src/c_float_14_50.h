#ifndef C_FLOAT_14_50_H
#define C_FLOAT_14_50_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_14_50 14
#define EXPONENT_BITS_F_14_50 50
#define BITS_F_14_50 SIGNIFICAND_BITS_F_14_50 + EXPONENT_BITS_F_14_50

#define C_FLOAT_14_50_DEBUG true

typedef uint64_t f1450_t;

#define SIGNIFICAND_MASK_F_14_50 ((1ULL << SIGNIFICAND_BITS_F_14_50) - 1)
#define SIGNIFICAND_2_MASK_F_14_50 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_14_50) - 1)
#define EXPONENT_MASK_F_14_50 (((1ULL << EXPONENT_BITS_F_14_50) - 1) << SIGNIFICAND_BITS_F_14_50)
#define SIGNIFICAND_SIGN_MASK_F_14_50 (1ULL << (SIGNIFICAND_BITS_F_14_50 - 1))
#define EXPONENT_SIGN_MASK_F_14_50 (1ULL << (EXPONENT_BITS_F_14_50 - 1))
#define BITS_SIGN_MASK_F_14_50 (1ULL << (BITS_F_14_50 - 1))

// construct float 1450
f1450_t new_f1450(uint64_t exp, uint64_t sig);
// exponent part of float 1450
uint64_t exp_f1450(f1450_t a);
// significand part of float 1450
uint64_t sig_f1450(f1450_t a);
// add float 1450
f1450_t add_f1450(f1450_t a, f1450_t b);
// subtract float 1450
f1450_t sub_f1450(f1450_t a, f1450_t b);
// negate float 1450
f1450_t neg_f1450(f1450_t a);
// multiply float 1450
f1450_t mul_f1450(f1450_t a, f1450_t b);
// divide float 1450
f1450_t div_f1450(f1450_t a, f1450_t b);
// equals float 1450
bool equ_f1450(f1450_t a, f1450_t b);
// compare float 1450
int com_f1450(f1450_t a, f1450_t b);

#endif // C_FLOAT_14_50_H

