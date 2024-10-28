#ifndef C_P_ADIC_17_47_H
#define C_P_ADIC_17_47_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_17_47 17
#define EXPONENT_BITS_P_17_47 47
#define BITS_P_17_47 SIGNIFICAND_BITS_P_17_47 + EXPONENT_BITS_P_17_47

#define C_P_ADIC_17_47_DEBUG true

typedef uint64_t p1747_t;

#define SIGNIFICAND_MASK_P_17_47 ((1ULL << SIGNIFICAND_BITS_P_17_47) - 1)
#define EXPONENT_MASK_P_17_47 (((1ULL << EXPONENT_BITS_P_17_47) - 1) << SIGNIFICAND_BITS_P_17_47)
#define SIGNIFICAND_SIGN_MASK_P_17_47 (1ULL << (SIGNIFICAND_BITS_P_17_47 - 1))
#define EXPONENT_SIGN_MASK_P_17_47 (1ULL << (EXPONENT_BITS_P_17_47 - 1))
#define BITS_SIGN_MASK_P_17_47 (1ULL << (BITS_P_17_47 - 1))

// construct p-adic 1747
p1747_t new_p1747(uint64_t exp, uint64_t sig);
// exponent part of p-adic 1747
uint64_t exp_p1747(p1747_t a);
// significand part of p-adic 1747
uint64_t sig_p1747(p1747_t a);
// add p-adic 1747
p1747_t add_p1747(p1747_t a, p1747_t b);
// subtract p-adic 1747
p1747_t sub_p1747(p1747_t a, p1747_t b);
// negate p-adic 1747
p1747_t neg_p1747(p1747_t a);
// multiply p-adic 1747
p1747_t mul_p1747(p1747_t a, p1747_t b);
// divide p-adic 1747
p1747_t div_p1747(p1747_t a, p1747_t b);
// equals p-adic 1747
bool equ_p1747(p1747_t a, p1747_t b);
// compare p-adic 1747
int com_p1747(p1747_t a, p1747_t b);

#endif //C_P_ADIC_17_47_H

