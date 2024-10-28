#ifndef C_P_ADIC_23_09_H
#define C_P_ADIC_23_09_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_23_09 23
#define EXPONENT_BITS_P_23_09 06
#define BITS_P_23_09 SIGNIFICAND_BITS_P_23_09 + EXPONENT_BITS_P_23_09

#define C_P_ADIC_23_09_DEBUG true

typedef uint32_t p2309_t;

#define SIGNIFICAND_MASK_P_23_09 ((1ULL << SIGNIFICAND_BITS_P_23_09) - 1)
#define EXPONENT_MASK_P_23_09 (((1ULL << EXPONENT_BITS_P_23_09) - 1) << SIGNIFICAND_BITS_P_23_09)
#define SIGNIFICAND_SIGN_MASK_P_23_09 (1U << (SIGNIFICAND_BITS_P_23_09 - 1))
#define EXPONENT_SIGN_MASK_P_23_09 (1U << (EXPONENT_BITS_P_23_09 - 1))
#define BITS_SIGN_MASK_P_23_09 (1U << (BITS_P_23_09 - 1))

// construct p-adic 2309
p2309_t new_p2309(uint32_t exp, uint32_t sig);
// exponent part of p-adic 2309
uint32_t exp_p2309(p2309_t a);
// significand part of p-adic 2309
uint32_t sig_p2309(p2309_t a);
// add p-adic 2309
p2309_t add_p2309(p2309_t a, p2309_t b);
// subtract p-adic 2309
p2309_t sub_p2309(p2309_t a, p2309_t b);
// negate p-adic 2309
p2309_t neg_p2309(p2309_t a);
// multiply p-adic 2309
p2309_t mul_p2309(p2309_t a, p2309_t b);
// divide p-adic 2309
p2309_t div_p2309(p2309_t a, p2309_t b);
// equals p-adic 2309
bool equ_p2309(p2309_t a, p2309_t b);
// compare p-adic 2309
int com_p2309(p2309_t a, p2309_t b);

#endif //C_P_ADIC_23_09_H

