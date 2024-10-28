#ifndef C_FLOAT_15_49_H
#define C_FLOAT_15_49_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_15_49 15
#define EXPONENT_BITS_F_15_49 49
#define BITS_F_15_49 SIGNIFICAND_BITS_F_15_49 + EXPONENT_BITS_F_15_49

#define C_FLOAT_15_49_DEBUG true

typedef uint64_t f1549_t;

#define SIGNIFICAND_MASK_F_15_49 ((1ULL << SIGNIFICAND_BITS_F_15_49) - 1)
#define SIGNIFICAND_2_MASK_F_15_49 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_15_49) - 1)
#define EXPONENT_MASK_F_15_49 (((1ULL << EXPONENT_BITS_F_15_49) - 1) << SIGNIFICAND_BITS_F_15_49)
#define SIGNIFICAND_SIGN_MASK_F_15_49 (1ULL << (SIGNIFICAND_BITS_F_15_49 - 1))
#define EXPONENT_SIGN_MASK_F_15_49 (1ULL << (EXPONENT_BITS_F_15_49 - 1))
#define BITS_SIGN_MASK_F_15_49 (1ULL << (BITS_F_15_49 - 1))

// construct float 1549
f1549_t new_f1549(uint64_t exp, uint64_t sig);
// exponent part of float 1549
uint64_t exp_f1549(f1549_t a);
// significand part of float 1549
uint64_t sig_f1549(f1549_t a);
// add float 1549
f1549_t add_f1549(f1549_t a, f1549_t b);
// subtract float 1549
f1549_t sub_f1549(f1549_t a, f1549_t b);
// negate float 1549
f1549_t neg_f1549(f1549_t a);
// multiply float 1549
f1549_t mul_f1549(f1549_t a, f1549_t b);
// divide float 1549
f1549_t div_f1549(f1549_t a, f1549_t b);
// equals float 1549
bool equ_f1549(f1549_t a, f1549_t b);
// compare float 1549
int com_f1549(f1549_t a, f1549_t b);

#endif // C_FLOAT_15_49_H
