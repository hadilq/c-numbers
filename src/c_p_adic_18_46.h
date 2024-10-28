#ifndef C_P_ADIC_18_46_H
#define C_P_ADIC_18_46_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_18_46 18
#define EXPONENT_BITS_P_18_46 46
#define BITS_P_18_46 SIGNIFICAND_BITS_P_18_46 + EXPONENT_BITS_P_18_46

#define C_P_ADIC_18_46_DEBUG true

typedef uint64_t p1846_t;

#define SIGNIFICAND_MASK_P_18_46 ((1ULL << SIGNIFICAND_BITS_P_18_46) - 1)
#define EXPONENT_MASK_P_18_46 (((1ULL << EXPONENT_BITS_P_18_46) - 1) << SIGNIFICAND_BITS_P_18_46)
#define SIGNIFICAND_SIGN_MASK_P_18_46 (1ULL << (SIGNIFICAND_BITS_P_18_46 - 1))
#define EXPONENT_SIGN_MASK_P_18_46 (1ULL << (EXPONENT_BITS_P_18_46 - 1))
#define BITS_SIGN_MASK_P_18_46 (1ULL << (BITS_P_18_46 - 1))

// construct p-adic 1846
p1846_t new_p1846(uint64_t exp, uint64_t sig);
// exponent part of p-adic 1846
uint64_t exp_p1846(p1846_t a);
// significand part of p-adic 1846
uint64_t sig_p1846(p1846_t a);
// add p-adic 1846
p1846_t add_p1846(p1846_t a, p1846_t b);
// subtract p-adic 1846
p1846_t sub_p1846(p1846_t a, p1846_t b);
// negate p-adic 1846
p1846_t neg_p1846(p1846_t a);
// multiply p-adic 1846
p1846_t mul_p1846(p1846_t a, p1846_t b);
// divide p-adic 1846
p1846_t div_p1846(p1846_t a, p1846_t b);
// equals p-adic 1846
bool equ_p1846(p1846_t a, p1846_t b);
// compare p-adic 1846
int com_p1846(p1846_t a, p1846_t b);

#endif //C_P_ADIC_18_46_H

