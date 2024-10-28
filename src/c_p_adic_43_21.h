#ifndef C_P_ADIC_43_21_H
#define C_P_ADIC_43_21_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_43_21 43
#define EXPONENT_BITS_P_43_21 21
#define BITS_P_43_21 SIGNIFICAND_BITS_P_43_21 + EXPONENT_BITS_P_43_21

#define C_P_ADIC_43_21_DEBUG true

typedef uint64_t p4321_t;

#define SIGNIFICAND_MASK_P_43_21 ((1ULL << SIGNIFICAND_BITS_P_43_21) - 1)
#define EXPONENT_MASK_P_43_21 (((1ULL << EXPONENT_BITS_P_43_21) - 1) << SIGNIFICAND_BITS_P_43_21)
#define SIGNIFICAND_SIGN_MASK_P_43_21 (1ULL << (SIGNIFICAND_BITS_P_43_21 - 1))
#define EXPONENT_SIGN_MASK_P_43_21 (1ULL << (EXPONENT_BITS_P_43_21 - 1))
#define BITS_SIGN_MASK_P_43_21 (1ULL << (BITS_P_43_21 - 1))

// construct p-adic 4321
p4321_t new_p4321(uint64_t exp, uint64_t sig);
// exponent part of p-adic 4321
uint64_t exp_p4321(p4321_t a);
// significand part of p-adic 4321
uint64_t sig_p4321(p4321_t a);
// add p-adic 4321
p4321_t add_p4321(p4321_t a, p4321_t b);
// subtract p-adic 4321
p4321_t sub_p4321(p4321_t a, p4321_t b);
// negate p-adic 4321
p4321_t neg_p4321(p4321_t a);
// multiply p-adic 4321
p4321_t mul_p4321(p4321_t a, p4321_t b);
// divide p-adic 4321
p4321_t div_p4321(p4321_t a, p4321_t b);
// equals p-adic 4321
bool equ_p4321(p4321_t a, p4321_t b);
// compare p-adic 4321
int com_p4321(p4321_t a, p4321_t b);

#endif //C_P_ADIC_43_21_H

