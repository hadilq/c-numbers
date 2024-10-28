#ifndef C_P_ADIC_15_49_H
#define C_P_ADIC_15_49_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_15_49 15
#define EXPONENT_BITS_P_15_49 49
#define BITS_P_15_49 SIGNIFICAND_BITS_P_15_49 + EXPONENT_BITS_P_15_49

#define C_P_ADIC_15_49_DEBUG true

typedef uint64_t p1549_t;

#define SIGNIFICAND_MASK_P_15_49 ((1ULL << SIGNIFICAND_BITS_P_15_49) - 1)
#define EXPONENT_MASK_P_15_49 (((1ULL << EXPONENT_BITS_P_15_49) - 1) << SIGNIFICAND_BITS_P_15_49)
#define SIGNIFICAND_SIGN_MASK_P_15_49 (1ULL << (SIGNIFICAND_BITS_P_15_49 - 1))
#define EXPONENT_SIGN_MASK_P_15_49 (1ULL << (EXPONENT_BITS_P_15_49 - 1))
#define BITS_SIGN_MASK_P_15_49 (1ULL << (BITS_P_15_49 - 1))

// construct p-adic 1549
p1549_t new_p1549(uint64_t exp, uint64_t sig);
// exponent part of p-adic 1549
uint64_t exp_p1549(p1549_t a);
// significand part of p-adic 1549
uint64_t sig_p1549(p1549_t a);
// add p-adic 1549
p1549_t add_p1549(p1549_t a, p1549_t b);
// subtract p-adic 1549
p1549_t sub_p1549(p1549_t a, p1549_t b);
// negate p-adic 1549
p1549_t neg_p1549(p1549_t a);
// multiply p-adic 1549
p1549_t mul_p1549(p1549_t a, p1549_t b);
// divide p-adic 1549
p1549_t div_p1549(p1549_t a, p1549_t b);
// equals p-adic 1549
bool equ_p1549(p1549_t a, p1549_t b);
// compare p-adic 1549
int com_p1549(p1549_t a, p1549_t b);

#endif //C_P_ADIC_15_49_H

