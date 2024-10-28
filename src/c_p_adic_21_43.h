#ifndef C_P_ADIC_21_43_H
#define C_P_ADIC_21_43_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_21_43 21
#define EXPONENT_BITS_P_21_43 43
#define BITS_P_21_43 SIGNIFICAND_BITS_P_21_43 + EXPONENT_BITS_P_21_43

#define C_P_ADIC_21_43_DEBUG true

typedef uint64_t p2143_t;

#define SIGNIFICAND_MASK_P_21_43 ((1ULL << SIGNIFICAND_BITS_P_21_43) - 1)
#define EXPONENT_MASK_P_21_43 (((1ULL << EXPONENT_BITS_P_21_43) - 1) << SIGNIFICAND_BITS_P_21_43)
#define SIGNIFICAND_SIGN_MASK_P_21_43 (1ULL << (SIGNIFICAND_BITS_P_21_43 - 1))
#define EXPONENT_SIGN_MASK_P_21_43 (1ULL << (EXPONENT_BITS_P_21_43 - 1))
#define BITS_SIGN_MASK_P_21_43 (1ULL << (BITS_P_21_43 - 1))

// construct p-adic 2143
p2143_t new_p2143(uint64_t exp, uint64_t sig);
// exponent part of p-adic 2143
uint64_t exp_p2143(p2143_t a);
// significand part of p-adic 2143
uint64_t sig_p2143(p2143_t a);
// add p-adic 2143
p2143_t add_p2143(p2143_t a, p2143_t b);
// subtract p-adic 2143
p2143_t sub_p2143(p2143_t a, p2143_t b);
// negate p-adic 2143
p2143_t neg_p2143(p2143_t a);
// multiply p-adic 2143
p2143_t mul_p2143(p2143_t a, p2143_t b);
// divide p-adic 2143
p2143_t div_p2143(p2143_t a, p2143_t b);
// equals p-adic 2143
bool equ_p2143(p2143_t a, p2143_t b);
// compare p-adic 2143
int com_p2143(p2143_t a, p2143_t b);

#endif //C_P_ADIC_21_43_H

