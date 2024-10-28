#ifndef C_P_ADIC_04_60_H
#define C_P_ADIC_04_60_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_04_60 4
#define EXPONENT_BITS_P_04_60 60
#define BITS_P_04_60 SIGNIFICAND_BITS_P_04_60 + EXPONENT_BITS_P_04_60

#define C_P_ADIC_04_60_DEBUG true

typedef uint64_t p0460_t;

#define SIGNIFICAND_MASK_P_04_60 ((1ULL << SIGNIFICAND_BITS_P_04_60) - 1)
#define EXPONENT_MASK_P_04_60 (((1ULL << EXPONENT_BITS_P_04_60) - 1) << SIGNIFICAND_BITS_P_04_60)
#define SIGNIFICAND_SIGN_MASK_P_04_60 (1ULL << (SIGNIFICAND_BITS_P_04_60 - 1))
#define EXPONENT_SIGN_MASK_P_04_60 (1ULL << (EXPONENT_BITS_P_04_60 - 1))
#define BITS_SIGN_MASK_P_04_60 (1ULL << (BITS_P_04_60 - 1))

// construct p-adic 0460
p0460_t new_p0460(uint64_t exp, uint64_t sig);
// exponent part of p-adic 0460
uint64_t exp_p0460(p0460_t a);
// significand part of p-adic 0460
uint64_t sig_p0460(p0460_t a);
// add p-adic 0460
p0460_t add_p0460(p0460_t a, p0460_t b);
// subtract p-adic 0460
p0460_t sub_p0460(p0460_t a, p0460_t b);
// negate p-adic 0460
p0460_t neg_p0460(p0460_t a);
// multiply p-adic 0460
p0460_t mul_p0460(p0460_t a, p0460_t b);
// divide p-adic 0460
p0460_t div_p0460(p0460_t a, p0460_t b);
// equals p-adic 0460
bool equ_p0460(p0460_t a, p0460_t b);
// compare p-adic 0460
int com_p0460(p0460_t a, p0460_t b);

#endif //C_P_ADIC_04_60_H

