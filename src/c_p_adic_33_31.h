#ifndef C_P_ADIC_33_31_H
#define C_P_ADIC_33_31_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_33_31 33
#define EXPONENT_BITS_P_33_31 31
#define BITS_P_33_31 SIGNIFICAND_BITS_P_33_31 + EXPONENT_BITS_P_33_31

#define C_P_ADIC_33_31_DEBUG true

typedef uint64_t p3331_t;

#define SIGNIFICAND_MASK_P_33_31 ((1ULL << SIGNIFICAND_BITS_P_33_31) - 1)
#define EXPONENT_MASK_P_33_31 (((1ULL << EXPONENT_BITS_P_33_31) - 1) << SIGNIFICAND_BITS_P_33_31)
#define SIGNIFICAND_SIGN_MASK_P_33_31 (1ULL << (SIGNIFICAND_BITS_P_33_31 - 1))
#define EXPONENT_SIGN_MASK_P_33_31 (1ULL << (EXPONENT_BITS_P_33_31 - 1))
#define BITS_SIGN_MASK_P_33_31 (1ULL << (BITS_P_33_31 - 1))

// construct p-adic 3331
p3331_t new_p3331(uint64_t exp, uint64_t sig);
// exponent part of p-adic 3331
uint64_t exp_p3331(p3331_t a);
// significand part of p-adic 3331
uint64_t sig_p3331(p3331_t a);
// add p-adic 3331
p3331_t add_p3331(p3331_t a, p3331_t b);
// subtract p-adic 3331
p3331_t sub_p3331(p3331_t a, p3331_t b);
// negate p-adic 3331
p3331_t neg_p3331(p3331_t a);
// multiply p-adic 3331
p3331_t mul_p3331(p3331_t a, p3331_t b);
// divide p-adic 3331
p3331_t div_p3331(p3331_t a, p3331_t b);
// equals p-adic 3331
bool equ_p3331(p3331_t a, p3331_t b);
// compare p-adic 3331
int com_p3331(p3331_t a, p3331_t b);

#endif //C_P_ADIC_33_31_H

