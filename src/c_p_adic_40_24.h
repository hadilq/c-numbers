#ifndef C_P_ADIC_40_24_H
#define C_P_ADIC_40_24_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_40_24 40
#define EXPONENT_BITS_P_40_24 24
#define BITS_P_40_24 SIGNIFICAND_BITS_P_40_24 + EXPONENT_BITS_P_40_24

#define C_P_ADIC_40_24_DEBUG true

typedef uint64_t p4024_t;

#define SIGNIFICAND_MASK_P_40_24 ((1ULL << SIGNIFICAND_BITS_P_40_24) - 1)
#define EXPONENT_MASK_P_40_24 (((1ULL << EXPONENT_BITS_P_40_24) - 1) << SIGNIFICAND_BITS_P_40_24)
#define SIGNIFICAND_SIGN_MASK_P_40_24 (1ULL << (SIGNIFICAND_BITS_P_40_24 - 1))
#define EXPONENT_SIGN_MASK_P_40_24 (1ULL << (EXPONENT_BITS_P_40_24 - 1))
#define BITS_SIGN_MASK_P_40_24 (1ULL << (BITS_P_40_24 - 1))

// construct p-adic 4024
p4024_t new_p4024(uint64_t exp, uint64_t sig);
// exponent part of p-adic 4024
uint64_t exp_p4024(p4024_t a);
// significand part of p-adic 4024
uint64_t sig_p4024(p4024_t a);
// add p-adic 4024
p4024_t add_p4024(p4024_t a, p4024_t b);
// subtract p-adic 4024
p4024_t sub_p4024(p4024_t a, p4024_t b);
// negate p-adic 4024
p4024_t neg_p4024(p4024_t a);
// multiply p-adic 4024
p4024_t mul_p4024(p4024_t a, p4024_t b);
// divide p-adic 4024
p4024_t div_p4024(p4024_t a, p4024_t b);
// equals p-adic 4024
bool equ_p4024(p4024_t a, p4024_t b);
// compare p-adic 4024
int com_p4024(p4024_t a, p4024_t b);

#endif //C_P_ADIC_40_24_H

