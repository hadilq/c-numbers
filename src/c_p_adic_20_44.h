#ifndef C_P_ADIC_20_44_H
#define C_P_ADIC_20_44_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_20_44 20
#define EXPONENT_BITS_P_20_44 44
#define BITS_P_20_44 SIGNIFICAND_BITS_P_20_44 + EXPONENT_BITS_P_20_44

#define C_P_ADIC_20_44_DEBUG true

typedef uint64_t p2044_t;

#define SIGNIFICAND_MASK_P_20_44 ((1ULL << SIGNIFICAND_BITS_P_20_44) - 1)
#define EXPONENT_MASK_P_20_44 (((1ULL << EXPONENT_BITS_P_20_44) - 1) << SIGNIFICAND_BITS_P_20_44)
#define SIGNIFICAND_SIGN_MASK_P_20_44 (1ULL << (SIGNIFICAND_BITS_P_20_44 - 1))
#define EXPONENT_SIGN_MASK_P_20_44 (1ULL << (EXPONENT_BITS_P_20_44 - 1))
#define BITS_SIGN_MASK_P_20_44 (1ULL << (BITS_P_20_44 - 1))

// construct p-adic 2044
p2044_t new_p2044(uint64_t exp, uint64_t sig);
// exponent part of p-adic 2044
uint64_t exp_p2044(p2044_t a);
// significand part of p-adic 2044
uint64_t sig_p2044(p2044_t a);
// add p-adic 2044
p2044_t add_p2044(p2044_t a, p2044_t b);
// subtract p-adic 2044
p2044_t sub_p2044(p2044_t a, p2044_t b);
// negate p-adic 2044
p2044_t neg_p2044(p2044_t a);
// multiply p-adic 2044
p2044_t mul_p2044(p2044_t a, p2044_t b);
// divide p-adic 2044
p2044_t div_p2044(p2044_t a, p2044_t b);
// equals p-adic 2044
bool equ_p2044(p2044_t a, p2044_t b);
// compare p-adic 2044
int com_p2044(p2044_t a, p2044_t b);

#endif //C_P_ADIC_20_44_H

