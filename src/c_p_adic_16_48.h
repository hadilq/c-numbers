#ifndef C_P_ADIC_16_48_H
#define C_P_ADIC_16_48_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_16_48 16
#define EXPONENT_BITS_P_16_48 48
#define BITS_P_16_48 SIGNIFICAND_BITS_P_16_48 + EXPONENT_BITS_P_16_48

#define C_P_ADIC_16_48_DEBUG true

typedef uint64_t p1648_t;

#define SIGNIFICAND_MASK_P_16_48 ((1ULL << SIGNIFICAND_BITS_P_16_48) - 1)
#define EXPONENT_MASK_P_16_48 (((1ULL << EXPONENT_BITS_P_16_48) - 1) << SIGNIFICAND_BITS_P_16_48)
#define SIGNIFICAND_SIGN_MASK_P_16_48 (1ULL << (SIGNIFICAND_BITS_P_16_48 - 1))
#define EXPONENT_SIGN_MASK_P_16_48 (1ULL << (EXPONENT_BITS_P_16_48 - 1))
#define BITS_SIGN_MASK_P_16_48 (1ULL << (BITS_P_16_48 - 1))

#define MAX_VALUE_P_16_48 (((1ULL << (EXPONENT_BITS_P_16_48 - 2)) - 1) << SIGNIFICAND_BITS_P_16_48) | ((1ULL << (SIGNIFICAND_BITS_P_16_48 - 2)) - 1)
#define MIN_VALUE_P_16_48 (((1ULL << (EXPONENT_BITS_P_16_48 - 2)) - 1) << SIGNIFICAND_BITS_P_16_48) | (SIGNIFICAND_SIGN_MASK_P_16_48)

// construct p-adic 1648
p1648_t new_p1648(int64_t exp, int64_t sig);
// exponent part of p-adic 1648
int64_t exp_p1648(p1648_t a);
// significand part of p-adic 1648
int64_t sig_p1648(p1648_t a);
// add p-adic 1648
p1648_t add_p1648(p1648_t a, p1648_t b);
// subtract p-adic 1648
p1648_t sub_p1648(p1648_t a, p1648_t b);
// negate p-adic 1648
p1648_t neg_p1648(p1648_t a);
// multiply p-adic 1648
p1648_t mul_p1648(p1648_t a, p1648_t b);
// divide p-adic 1648
p1648_t div_p1648(p1648_t a, p1648_t b);
// equals p-adic 1648
bool equ_p1648(p1648_t a, p1648_t b);
// compare p-adic 1648
int com_p1648(p1648_t a, p1648_t b);

#endif //C_P_ADIC_16_48_H

