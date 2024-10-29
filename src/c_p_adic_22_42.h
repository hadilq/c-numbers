#ifndef C_P_ADIC_22_42_H
#define C_P_ADIC_22_42_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_22_42 22
#define EXPONENT_BITS_P_22_42 42
#define BITS_P_22_42 SIGNIFICAND_BITS_P_22_42 + EXPONENT_BITS_P_22_42

#define C_P_ADIC_22_42_DEBUG true

typedef uint64_t p2242_t;

#define SIGNIFICAND_MASK_P_22_42 ((1ULL << SIGNIFICAND_BITS_P_22_42) - 1)
#define EXPONENT_MASK_P_22_42 (((1ULL << EXPONENT_BITS_P_22_42) - 1) << SIGNIFICAND_BITS_P_22_42)
#define SIGNIFICAND_SIGN_MASK_P_22_42 (1ULL << (SIGNIFICAND_BITS_P_22_42 - 1))
#define EXPONENT_SIGN_MASK_P_22_42 (1ULL << (EXPONENT_BITS_P_22_42 - 1))
#define BITS_SIGN_MASK_P_22_42 (1ULL << (BITS_P_22_42 - 1))

#define MAX_VALUE_P_22_42 (((1ULL << (EXPONENT_BITS_P_22_42 - 2)) - 1) << SIGNIFICAND_BITS_P_22_42) | ((1ULL << (SIGNIFICAND_BITS_P_22_42 - 2)) - 1)
#define MIN_VALUE_P_22_42 (((1ULL << (EXPONENT_BITS_P_22_42 - 2)) - 1) << SIGNIFICAND_BITS_P_22_42) | (SIGNIFICAND_SIGN_MASK_P_22_42)

// construct p-adic 2242
p2242_t new_p2242(int64_t exp, int64_t sig);
// exponent part of p-adic 2242
int64_t exp_p2242(p2242_t a);
// significand part of p-adic 2242
int64_t sig_p2242(p2242_t a);
// add p-adic 2242
p2242_t add_p2242(p2242_t a, p2242_t b);
// subtract p-adic 2242
p2242_t sub_p2242(p2242_t a, p2242_t b);
// negate p-adic 2242
p2242_t neg_p2242(p2242_t a);
// multiply p-adic 2242
p2242_t mul_p2242(p2242_t a, p2242_t b);
// divide p-adic 2242
p2242_t div_p2242(p2242_t a, p2242_t b);
// equals p-adic 2242
bool equ_p2242(p2242_t a, p2242_t b);
// compare p-adic 2242
int com_p2242(p2242_t a, p2242_t b);

#endif //C_P_ADIC_22_42_H

