#ifndef C_P_ADIC_34_30_H
#define C_P_ADIC_34_30_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_34_30 34
#define EXPONENT_BITS_P_34_30 30
#define BITS_P_34_30 SIGNIFICAND_BITS_P_34_30 + EXPONENT_BITS_P_34_30

#define C_P_ADIC_34_30_DEBUG true

typedef uint64_t p3430_t;

#define SIGNIFICAND_MASK_P_34_30 ((1ULL << SIGNIFICAND_BITS_P_34_30) - 1)
#define EXPONENT_MASK_P_34_30 (((1ULL << EXPONENT_BITS_P_34_30) - 1) << SIGNIFICAND_BITS_P_34_30)
#define SIGNIFICAND_SIGN_MASK_P_34_30 (1ULL << (SIGNIFICAND_BITS_P_34_30 - 1))
#define EXPONENT_SIGN_MASK_P_34_30 (1ULL << (EXPONENT_BITS_P_34_30 - 1))
#define BITS_SIGN_MASK_P_34_30 (1ULL << (BITS_P_34_30 - 1))

// construct p-adic 3430
p3430_t new_p3430(uint64_t exp, uint64_t sig);
// exponent part of p-adic 3430
uint64_t exp_p3430(p3430_t a);
// significand part of p-adic 3430
uint64_t sig_p3430(p3430_t a);
// add p-adic 3430
p3430_t add_p3430(p3430_t a, p3430_t b);
// subtract p-adic 3430
p3430_t sub_p3430(p3430_t a, p3430_t b);
// negate p-adic 3430
p3430_t neg_p3430(p3430_t a);
// multiply p-adic 3430
p3430_t mul_p3430(p3430_t a, p3430_t b);
// divide p-adic 3430
p3430_t div_p3430(p3430_t a, p3430_t b);
// equals p-adic 3430
bool equ_p3430(p3430_t a, p3430_t b);
// compare p-adic 3430
int com_p3430(p3430_t a, p3430_t b);

#endif //C_P_ADIC_34_30_H

