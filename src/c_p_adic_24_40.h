#ifndef C_P_ADIC_24_40_H
#define C_P_ADIC_24_40_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_24_40 24
#define EXPONENT_BITS_P_24_40 40
#define BITS_P_24_40 SIGNIFICAND_BITS_P_24_40 + EXPONENT_BITS_P_24_40

#define C_P_ADIC_24_40_DEBUG true

typedef uint64_t p2440_t;

#define SIGNIFICAND_MASK_P_24_40 ((1ULL << SIGNIFICAND_BITS_P_24_40) - 1)
#define EXPONENT_MASK_P_24_40 (((1ULL << EXPONENT_BITS_P_24_40) - 1) << SIGNIFICAND_BITS_P_24_40)
#define SIGNIFICAND_SIGN_MASK_P_24_40 (1ULL << (SIGNIFICAND_BITS_P_24_40 - 1))
#define EXPONENT_SIGN_MASK_P_24_40 (1ULL << (EXPONENT_BITS_P_24_40 - 1))
#define BITS_SIGN_MASK_P_24_40 (1ULL << (BITS_P_24_40 - 1))

// construct p-adic 2440
p2440_t new_p2440(uint64_t exp, uint64_t sig);
// exponent part of p-adic 2440
uint64_t exp_p2440(p2440_t a);
// significand part of p-adic 2440
uint64_t sig_p2440(p2440_t a);
// add p-adic 2440
p2440_t add_p2440(p2440_t a, p2440_t b);
// subtract p-adic 2440
p2440_t sub_p2440(p2440_t a, p2440_t b);
// negate p-adic 2440
p2440_t neg_p2440(p2440_t a);
// multiply p-adic 2440
p2440_t mul_p2440(p2440_t a, p2440_t b);
// divide p-adic 2440
p2440_t div_p2440(p2440_t a, p2440_t b);
// equals p-adic 2440
bool equ_p2440(p2440_t a, p2440_t b);
// compare p-adic 2440
int com_p2440(p2440_t a, p2440_t b);

#endif //C_P_ADIC_24_40_H

