#ifndef C_P_ADIC_11_21_H
#define C_P_ADIC_11_21_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_11_21 11
#define EXPONENT_BITS_P_11_21 06
#define BITS_P_11_21 SIGNIFICAND_BITS_P_11_21 + EXPONENT_BITS_P_11_21

#define C_P_ADIC_11_21_DEBUG true

typedef uint32_t p1121_t;

#define SIGNIFICAND_MASK_P_11_21 ((1ULL << SIGNIFICAND_BITS_P_11_21) - 1)
#define EXPONENT_MASK_P_11_21 (((1ULL << EXPONENT_BITS_P_11_21) - 1) << SIGNIFICAND_BITS_P_11_21)
#define SIGNIFICAND_SIGN_MASK_P_11_21 (1U << (SIGNIFICAND_BITS_P_11_21 - 1))
#define EXPONENT_SIGN_MASK_P_11_21 (1U << (EXPONENT_BITS_P_11_21 - 1))
#define BITS_SIGN_MASK_P_11_21 (1U << (BITS_P_11_21 - 1))

// construct p-adic 1121
p1121_t new_p1121(uint32_t exp, uint32_t sig);
// exponent part of p-adic 1121
uint32_t exp_p1121(p1121_t a);
// significand part of p-adic 1121
uint32_t sig_p1121(p1121_t a);
// add p-adic 1121
p1121_t add_p1121(p1121_t a, p1121_t b);
// subtract p-adic 1121
p1121_t sub_p1121(p1121_t a, p1121_t b);
// negate p-adic 1121
p1121_t neg_p1121(p1121_t a);
// multiply p-adic 1121
p1121_t mul_p1121(p1121_t a, p1121_t b);
// divide p-adic 1121
p1121_t div_p1121(p1121_t a, p1121_t b);
// equals p-adic 1121
bool equ_p1121(p1121_t a, p1121_t b);
// compare p-adic 1121
int com_p1121(p1121_t a, p1121_t b);

#endif //C_P_ADIC_11_21_H

