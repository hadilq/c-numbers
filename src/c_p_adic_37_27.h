#ifndef C_P_ADIC_37_27_H
#define C_P_ADIC_37_27_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_37_27 37
#define EXPONENT_BITS_P_37_27 27
#define BITS_P_37_27 SIGNIFICAND_BITS_P_37_27 + EXPONENT_BITS_P_37_27

#define C_P_ADIC_37_27_DEBUG true

typedef uint64_t p3727_t;

#define SIGNIFICAND_MASK_P_37_27 ((1ULL << SIGNIFICAND_BITS_P_37_27) - 1)
#define EXPONENT_MASK_P_37_27 (((1ULL << EXPONENT_BITS_P_37_27) - 1) << SIGNIFICAND_BITS_P_37_27)
#define SIGNIFICAND_SIGN_MASK_P_37_27 (1ULL << (SIGNIFICAND_BITS_P_37_27 - 1))
#define EXPONENT_SIGN_MASK_P_37_27 (1ULL << (EXPONENT_BITS_P_37_27 - 1))
#define BITS_SIGN_MASK_P_37_27 (1ULL << (BITS_P_37_27 - 1))

// construct p-adic 3727
p3727_t new_p3727(uint64_t exp, uint64_t sig);
// exponent part of p-adic 3727
uint64_t exp_p3727(p3727_t a);
// significand part of p-adic 3727
uint64_t sig_p3727(p3727_t a);
// add p-adic 3727
p3727_t add_p3727(p3727_t a, p3727_t b);
// subtract p-adic 3727
p3727_t sub_p3727(p3727_t a, p3727_t b);
// negate p-adic 3727
p3727_t neg_p3727(p3727_t a);
// multiply p-adic 3727
p3727_t mul_p3727(p3727_t a, p3727_t b);
// divide p-adic 3727
p3727_t div_p3727(p3727_t a, p3727_t b);
// equals p-adic 3727
bool equ_p3727(p3727_t a, p3727_t b);
// compare p-adic 3727
int com_p3727(p3727_t a, p3727_t b);

#endif //C_P_ADIC_37_27_H

