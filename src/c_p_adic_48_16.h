#ifndef C_P_ADIC_48_16_H
#define C_P_ADIC_48_16_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_48_16 48
#define EXPONENT_BITS_P_48_16 16
#define BITS_P_48_16 SIGNIFICAND_BITS_P_48_16 + EXPONENT_BITS_P_48_16

#define C_P_ADIC_48_16_DEBUG true

typedef uint64_t p4816_t;

#define SIGNIFICAND_MASK_P_48_16 ((1ULL << SIGNIFICAND_BITS_P_48_16) - 1)
#define EXPONENT_MASK_P_48_16 (((1ULL << EXPONENT_BITS_P_48_16) - 1) << SIGNIFICAND_BITS_P_48_16)
#define SIGNIFICAND_SIGN_MASK_P_48_16 (1ULL << (SIGNIFICAND_BITS_P_48_16 - 1))
#define EXPONENT_SIGN_MASK_P_48_16 (1ULL << (EXPONENT_BITS_P_48_16 - 1))
#define BITS_SIGN_MASK_P_48_16 (1ULL << (BITS_P_48_16 - 1))

// construct p-adic 4816
p4816_t new_p4816(uint64_t exp, uint64_t sig);
// exponent part of p-adic 4816
uint64_t exp_p4816(p4816_t a);
// significand part of p-adic 4816
uint64_t sig_p4816(p4816_t a);
// add p-adic 4816
p4816_t add_p4816(p4816_t a, p4816_t b);
// subtract p-adic 4816
p4816_t sub_p4816(p4816_t a, p4816_t b);
// negate p-adic 4816
p4816_t neg_p4816(p4816_t a);
// multiply p-adic 4816
p4816_t mul_p4816(p4816_t a, p4816_t b);
// divide p-adic 4816
p4816_t div_p4816(p4816_t a, p4816_t b);
// equals p-adic 4816
bool equ_p4816(p4816_t a, p4816_t b);
// compare p-adic 4816
int com_p4816(p4816_t a, p4816_t b);

#endif //C_P_ADIC_48_16_H

