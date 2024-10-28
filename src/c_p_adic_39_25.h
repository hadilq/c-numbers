#ifndef C_P_ADIC_39_25_H
#define C_P_ADIC_39_25_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_39_25 39
#define EXPONENT_BITS_P_39_25 25
#define BITS_P_39_25 SIGNIFICAND_BITS_P_39_25 + EXPONENT_BITS_P_39_25

#define C_P_ADIC_39_25_DEBUG true

typedef uint64_t p3925_t;

#define SIGNIFICAND_MASK_P_39_25 ((1ULL << SIGNIFICAND_BITS_P_39_25) - 1)
#define EXPONENT_MASK_P_39_25 (((1ULL << EXPONENT_BITS_P_39_25) - 1) << SIGNIFICAND_BITS_P_39_25)
#define SIGNIFICAND_SIGN_MASK_P_39_25 (1ULL << (SIGNIFICAND_BITS_P_39_25 - 1))
#define EXPONENT_SIGN_MASK_P_39_25 (1ULL << (EXPONENT_BITS_P_39_25 - 1))
#define BITS_SIGN_MASK_P_39_25 (1ULL << (BITS_P_39_25 - 1))

// construct p-adic 3925
p3925_t new_p3925(uint64_t exp, uint64_t sig);
// exponent part of p-adic 3925
uint64_t exp_p3925(p3925_t a);
// significand part of p-adic 3925
uint64_t sig_p3925(p3925_t a);
// add p-adic 3925
p3925_t add_p3925(p3925_t a, p3925_t b);
// subtract p-adic 3925
p3925_t sub_p3925(p3925_t a, p3925_t b);
// negate p-adic 3925
p3925_t neg_p3925(p3925_t a);
// multiply p-adic 3925
p3925_t mul_p3925(p3925_t a, p3925_t b);
// divide p-adic 3925
p3925_t div_p3925(p3925_t a, p3925_t b);
// equals p-adic 3925
bool equ_p3925(p3925_t a, p3925_t b);
// compare p-adic 3925
int com_p3925(p3925_t a, p3925_t b);

#endif //C_P_ADIC_39_25_H

