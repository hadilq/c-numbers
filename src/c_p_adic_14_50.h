#ifndef C_P_ADIC_14_50_H
#define C_P_ADIC_14_50_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_14_50 14
#define EXPONENT_BITS_P_14_50 50
#define BITS_P_14_50 SIGNIFICAND_BITS_P_14_50 + EXPONENT_BITS_P_14_50

#define C_P_ADIC_14_50_DEBUG true

typedef uint64_t p1450_t;

#define SIGNIFICAND_MASK_P_14_50 ((1ULL << SIGNIFICAND_BITS_P_14_50) - 1)
#define EXPONENT_MASK_P_14_50 (((1ULL << EXPONENT_BITS_P_14_50) - 1) << SIGNIFICAND_BITS_P_14_50)
#define SIGNIFICAND_SIGN_MASK_P_14_50 (1ULL << (SIGNIFICAND_BITS_P_14_50 - 1))
#define EXPONENT_SIGN_MASK_P_14_50 (1ULL << (EXPONENT_BITS_P_14_50 - 1))
#define BITS_SIGN_MASK_P_14_50 (1ULL << (BITS_P_14_50 - 1))

// construct p-adic 1450
p1450_t new_p1450(uint64_t exp, uint64_t sig);
// exponent part of p-adic 1450
uint64_t exp_p1450(p1450_t a);
// significand part of p-adic 1450
uint64_t sig_p1450(p1450_t a);
// add p-adic 1450
p1450_t add_p1450(p1450_t a, p1450_t b);
// subtract p-adic 1450
p1450_t sub_p1450(p1450_t a, p1450_t b);
// negate p-adic 1450
p1450_t neg_p1450(p1450_t a);
// multiply p-adic 1450
p1450_t mul_p1450(p1450_t a, p1450_t b);
// divide p-adic 1450
p1450_t div_p1450(p1450_t a, p1450_t b);
// equals p-adic 1450
bool equ_p1450(p1450_t a, p1450_t b);
// compare p-adic 1450
int com_p1450(p1450_t a, p1450_t b);

#endif //C_P_ADIC_14_50_H

