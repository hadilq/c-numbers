#ifndef C_P_ADIC_19_45_H
#define C_P_ADIC_19_45_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_19_45 19
#define EXPONENT_BITS_P_19_45 45
#define BITS_P_19_45 SIGNIFICAND_BITS_P_19_45 + EXPONENT_BITS_P_19_45

#define C_P_ADIC_19_45_DEBUG true

typedef uint64_t p1945_t;

#define SIGNIFICAND_MASK_P_19_45 ((1ULL << SIGNIFICAND_BITS_P_19_45) - 1)
#define EXPONENT_MASK_P_19_45 (((1ULL << EXPONENT_BITS_P_19_45) - 1) << SIGNIFICAND_BITS_P_19_45)
#define SIGNIFICAND_SIGN_MASK_P_19_45 (1ULL << (SIGNIFICAND_BITS_P_19_45 - 1))
#define EXPONENT_SIGN_MASK_P_19_45 (1ULL << (EXPONENT_BITS_P_19_45 - 1))
#define BITS_SIGN_MASK_P_19_45 (1ULL << (BITS_P_19_45 - 1))

// construct p-adic 1945
p1945_t new_p1945(uint64_t exp, uint64_t sig);
// exponent part of p-adic 1945
uint64_t exp_p1945(p1945_t a);
// significand part of p-adic 1945
uint64_t sig_p1945(p1945_t a);
// add p-adic 1945
p1945_t add_p1945(p1945_t a, p1945_t b);
// subtract p-adic 1945
p1945_t sub_p1945(p1945_t a, p1945_t b);
// negate p-adic 1945
p1945_t neg_p1945(p1945_t a);
// multiply p-adic 1945
p1945_t mul_p1945(p1945_t a, p1945_t b);
// divide p-adic 1945
p1945_t div_p1945(p1945_t a, p1945_t b);
// equals p-adic 1945
bool equ_p1945(p1945_t a, p1945_t b);
// compare p-adic 1945
int com_p1945(p1945_t a, p1945_t b);

#endif //C_P_ADIC_19_45_H

