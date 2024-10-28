#ifndef C_P_ADIC_12_52_H
#define C_P_ADIC_12_52_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_12_52 12
#define EXPONENT_BITS_P_12_52 52
#define BITS_P_12_52 SIGNIFICAND_BITS_P_12_52 + EXPONENT_BITS_P_12_52

#define C_P_ADIC_12_52_DEBUG true

typedef uint64_t p1252_t;

#define SIGNIFICAND_MASK_P_12_52 ((1ULL << SIGNIFICAND_BITS_P_12_52) - 1)
#define EXPONENT_MASK_P_12_52 (((1ULL << EXPONENT_BITS_P_12_52) - 1) << SIGNIFICAND_BITS_P_12_52)
#define SIGNIFICAND_SIGN_MASK_P_12_52 (1ULL << (SIGNIFICAND_BITS_P_12_52 - 1))
#define EXPONENT_SIGN_MASK_P_12_52 (1ULL << (EXPONENT_BITS_P_12_52 - 1))
#define BITS_SIGN_MASK_P_12_52 (1ULL << (BITS_P_12_52 - 1))

// construct p-adic 1252
p1252_t new_p1252(uint64_t exp, uint64_t sig);
// exponent part of p-adic 1252
uint64_t exp_p1252(p1252_t a);
// significand part of p-adic 1252
uint64_t sig_p1252(p1252_t a);
// add p-adic 1252
p1252_t add_p1252(p1252_t a, p1252_t b);
// subtract p-adic 1252
p1252_t sub_p1252(p1252_t a, p1252_t b);
// negate p-adic 1252
p1252_t neg_p1252(p1252_t a);
// multiply p-adic 1252
p1252_t mul_p1252(p1252_t a, p1252_t b);
// divide p-adic 1252
p1252_t div_p1252(p1252_t a, p1252_t b);
// equals p-adic 1252
bool equ_p1252(p1252_t a, p1252_t b);
// compare p-adic 1252
int com_p1252(p1252_t a, p1252_t b);

#endif //C_P_ADIC_12_52_H

