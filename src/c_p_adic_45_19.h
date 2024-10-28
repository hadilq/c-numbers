#ifndef C_P_ADIC_45_19_H
#define C_P_ADIC_45_19_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_45_19 45
#define EXPONENT_BITS_P_45_19 19
#define BITS_P_45_19 SIGNIFICAND_BITS_P_45_19 + EXPONENT_BITS_P_45_19

#define C_P_ADIC_45_19_DEBUG true

typedef uint64_t p4519_t;

#define SIGNIFICAND_MASK_P_45_19 ((1ULL << SIGNIFICAND_BITS_P_45_19) - 1)
#define EXPONENT_MASK_P_45_19 (((1ULL << EXPONENT_BITS_P_45_19) - 1) << SIGNIFICAND_BITS_P_45_19)
#define SIGNIFICAND_SIGN_MASK_P_45_19 (1ULL << (SIGNIFICAND_BITS_P_45_19 - 1))
#define EXPONENT_SIGN_MASK_P_45_19 (1ULL << (EXPONENT_BITS_P_45_19 - 1))
#define BITS_SIGN_MASK_P_45_19 (1ULL << (BITS_P_45_19 - 1))

// construct p-adic 4519
p4519_t new_p4519(uint64_t exp, uint64_t sig);
// exponent part of p-adic 4519
uint64_t exp_p4519(p4519_t a);
// significand part of p-adic 4519
uint64_t sig_p4519(p4519_t a);
// add p-adic 4519
p4519_t add_p4519(p4519_t a, p4519_t b);
// subtract p-adic 4519
p4519_t sub_p4519(p4519_t a, p4519_t b);
// negate p-adic 4519
p4519_t neg_p4519(p4519_t a);
// multiply p-adic 4519
p4519_t mul_p4519(p4519_t a, p4519_t b);
// divide p-adic 4519
p4519_t div_p4519(p4519_t a, p4519_t b);
// equals p-adic 4519
bool equ_p4519(p4519_t a, p4519_t b);
// compare p-adic 4519
int com_p4519(p4519_t a, p4519_t b);

#endif //C_P_ADIC_45_19_H

