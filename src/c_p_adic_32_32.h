#ifndef C_P_ADIC_32_32_H
#define C_P_ADIC_32_32_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_32_32 32
#define EXPONENT_BITS_P_32_32 32
#define BITS_P_32_32 SIGNIFICAND_BITS_P_32_32 + EXPONENT_BITS_P_32_32

#define C_P_ADIC_32_32_DEBUG true

typedef uint64_t p3232_t;

#define SIGNIFICAND_MASK_P_32_32 ((1ULL << SIGNIFICAND_BITS_P_32_32) - 1)
#define EXPONENT_MASK_P_32_32 (((1ULL << EXPONENT_BITS_P_32_32) - 1) << SIGNIFICAND_BITS_P_32_32)
#define SIGNIFICAND_SIGN_MASK_P_32_32 (1ULL << (SIGNIFICAND_BITS_P_32_32 - 1))
#define EXPONENT_SIGN_MASK_P_32_32 (1ULL << (EXPONENT_BITS_P_32_32 - 1))
#define BITS_SIGN_MASK_P_32_32 (1ULL << (BITS_P_32_32 - 1))

// construct p-adic 3232
p3232_t new_p3232(uint64_t exp, uint64_t sig);
// exponent part of p-adic 3232
uint64_t exp_p3232(p3232_t a);
// significand part of p-adic 3232
uint64_t sig_p3232(p3232_t a);
// add p-adic 3232
p3232_t add_p3232(p3232_t a, p3232_t b);
// subtract p-adic 3232
p3232_t sub_p3232(p3232_t a, p3232_t b);
// negate p-adic 3232
p3232_t neg_p3232(p3232_t a);
// multiply p-adic 3232
p3232_t mul_p3232(p3232_t a, p3232_t b);
// divide p-adic 3232
p3232_t div_p3232(p3232_t a, p3232_t b);
// equals p-adic 3232
bool equ_p3232(p3232_t a, p3232_t b);
// compare p-adic 3232
int com_p3232(p3232_t a, p3232_t b);

#endif //C_P_ADIC_32_32_H

