#ifndef C_P_ADIC_28_36_H
#define C_P_ADIC_28_36_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_28_36 28
#define EXPONENT_BITS_P_28_36 36
#define BITS_P_28_36 SIGNIFICAND_BITS_P_28_36 + EXPONENT_BITS_P_28_36

#define C_P_ADIC_28_36_DEBUG true

typedef uint64_t p2836_t;

#define SIGNIFICAND_MASK_P_28_36 ((1ULL << SIGNIFICAND_BITS_P_28_36) - 1)
#define EXPONENT_MASK_P_28_36 (((1ULL << EXPONENT_BITS_P_28_36) - 1) << SIGNIFICAND_BITS_P_28_36)
#define SIGNIFICAND_SIGN_MASK_P_28_36 (1ULL << (SIGNIFICAND_BITS_P_28_36 - 1))
#define EXPONENT_SIGN_MASK_P_28_36 (1ULL << (EXPONENT_BITS_P_28_36 - 1))
#define BITS_SIGN_MASK_P_28_36 (1ULL << (BITS_P_28_36 - 1))

// construct p-adic 2836
p2836_t new_p2836(uint64_t exp, uint64_t sig);
// exponent part of p-adic 2836
uint64_t exp_p2836(p2836_t a);
// significand part of p-adic 2836
uint64_t sig_p2836(p2836_t a);
// add p-adic 2836
p2836_t add_p2836(p2836_t a, p2836_t b);
// subtract p-adic 2836
p2836_t sub_p2836(p2836_t a, p2836_t b);
// negate p-adic 2836
p2836_t neg_p2836(p2836_t a);
// multiply p-adic 2836
p2836_t mul_p2836(p2836_t a, p2836_t b);
// divide p-adic 2836
p2836_t div_p2836(p2836_t a, p2836_t b);
// equals p-adic 2836
bool equ_p2836(p2836_t a, p2836_t b);
// compare p-adic 2836
int com_p2836(p2836_t a, p2836_t b);

#endif //C_P_ADIC_28_36_H

