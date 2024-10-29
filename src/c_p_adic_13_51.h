#ifndef C_P_ADIC_13_51_H
#define C_P_ADIC_13_51_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_13_51 13
#define EXPONENT_BITS_P_13_51 51
#define BITS_P_13_51 SIGNIFICAND_BITS_P_13_51 + EXPONENT_BITS_P_13_51

#define C_P_ADIC_13_51_DEBUG true

typedef uint64_t p1351_t;

#define SIGNIFICAND_MASK_P_13_51 ((1ULL << SIGNIFICAND_BITS_P_13_51) - 1)
#define EXPONENT_MASK_P_13_51 (((1ULL << EXPONENT_BITS_P_13_51) - 1) << SIGNIFICAND_BITS_P_13_51)
#define SIGNIFICAND_SIGN_MASK_P_13_51 (1ULL << (SIGNIFICAND_BITS_P_13_51 - 1))
#define EXPONENT_SIGN_MASK_P_13_51 (1ULL << (EXPONENT_BITS_P_13_51 - 1))
#define BITS_SIGN_MASK_P_13_51 (1ULL << (BITS_P_13_51 - 1))

#define MAX_VALUE_P_13_51 (((1ULL << (EXPONENT_BITS_P_13_51 - 2)) - 1) << SIGNIFICAND_BITS_P_13_51) | ((1ULL << (SIGNIFICAND_BITS_P_13_51 - 2)) - 1)
#define MIN_VALUE_P_13_51 (((1ULL << (EXPONENT_BITS_P_13_51 - 2)) - 1) << SIGNIFICAND_BITS_P_13_51) | (SIGNIFICAND_SIGN_MASK_P_13_51)

// construct p-adic 1351
p1351_t new_p1351(int64_t exp, int64_t sig);
// exponent part of p-adic 1351
int64_t exp_p1351(p1351_t a);
// significand part of p-adic 1351
int64_t sig_p1351(p1351_t a);
// add p-adic 1351
p1351_t add_p1351(p1351_t a, p1351_t b);
// subtract p-adic 1351
p1351_t sub_p1351(p1351_t a, p1351_t b);
// negate p-adic 1351
p1351_t neg_p1351(p1351_t a);
// multiply p-adic 1351
p1351_t mul_p1351(p1351_t a, p1351_t b);
// divide p-adic 1351
p1351_t div_p1351(p1351_t a, p1351_t b);
// equals p-adic 1351
bool equ_p1351(p1351_t a, p1351_t b);
// compare p-adic 1351
int com_p1351(p1351_t a, p1351_t b);

#endif //C_P_ADIC_13_51_H

