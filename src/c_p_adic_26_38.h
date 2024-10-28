#ifndef C_P_ADIC_26_38_H
#define C_P_ADIC_26_38_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_26_38 26
#define EXPONENT_BITS_P_26_38 38
#define BITS_P_26_38 SIGNIFICAND_BITS_P_26_38 + EXPONENT_BITS_P_26_38

#define C_P_ADIC_26_38_DEBUG true

typedef uint64_t p2638_t;

#define SIGNIFICAND_MASK_P_26_38 ((1ULL << SIGNIFICAND_BITS_P_26_38) - 1)
#define EXPONENT_MASK_P_26_38 (((1ULL << EXPONENT_BITS_P_26_38) - 1) << SIGNIFICAND_BITS_P_26_38)
#define SIGNIFICAND_SIGN_MASK_P_26_38 (1ULL << (SIGNIFICAND_BITS_P_26_38 - 1))
#define EXPONENT_SIGN_MASK_P_26_38 (1ULL << (EXPONENT_BITS_P_26_38 - 1))
#define BITS_SIGN_MASK_P_26_38 (1ULL << (BITS_P_26_38 - 1))

// construct p-adic 2638
p2638_t new_p2638(uint64_t exp, uint64_t sig);
// exponent part of p-adic 2638
uint64_t exp_p2638(p2638_t a);
// significand part of p-adic 2638
uint64_t sig_p2638(p2638_t a);
// add p-adic 2638
p2638_t add_p2638(p2638_t a, p2638_t b);
// subtract p-adic 2638
p2638_t sub_p2638(p2638_t a, p2638_t b);
// negate p-adic 2638
p2638_t neg_p2638(p2638_t a);
// multiply p-adic 2638
p2638_t mul_p2638(p2638_t a, p2638_t b);
// divide p-adic 2638
p2638_t div_p2638(p2638_t a, p2638_t b);
// equals p-adic 2638
bool equ_p2638(p2638_t a, p2638_t b);
// compare p-adic 2638
int com_p2638(p2638_t a, p2638_t b);

#endif //C_P_ADIC_26_38_H

