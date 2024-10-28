#ifndef C_P_ADIC_06_58_H
#define C_P_ADIC_06_58_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_06_58 6
#define EXPONENT_BITS_P_06_58 58
#define BITS_P_06_58 SIGNIFICAND_BITS_P_06_58 + EXPONENT_BITS_P_06_58

#define C_P_ADIC_06_58_DEBUG true

typedef uint64_t p0658_t;

#define SIGNIFICAND_MASK_P_06_58 ((1ULL << SIGNIFICAND_BITS_P_06_58) - 1)
#define EXPONENT_MASK_P_06_58 (((1ULL << EXPONENT_BITS_P_06_58) - 1) << SIGNIFICAND_BITS_P_06_58)
#define SIGNIFICAND_SIGN_MASK_P_06_58 (1ULL << (SIGNIFICAND_BITS_P_06_58 - 1))
#define EXPONENT_SIGN_MASK_P_06_58 (1ULL << (EXPONENT_BITS_P_06_58 - 1))
#define BITS_SIGN_MASK_P_06_58 (1ULL << (BITS_P_06_58 - 1))

// construct p-adic 0658
p0658_t new_p0658(uint64_t exp, uint64_t sig);
// exponent part of p-adic 0658
uint64_t exp_p0658(p0658_t a);
// significand part of p-adic 0658
uint64_t sig_p0658(p0658_t a);
// add p-adic 0658
p0658_t add_p0658(p0658_t a, p0658_t b);
// subtract p-adic 0658
p0658_t sub_p0658(p0658_t a, p0658_t b);
// negate p-adic 0658
p0658_t neg_p0658(p0658_t a);
// multiply p-adic 0658
p0658_t mul_p0658(p0658_t a, p0658_t b);
// divide p-adic 0658
p0658_t div_p0658(p0658_t a, p0658_t b);
// equals p-adic 0658
bool equ_p0658(p0658_t a, p0658_t b);
// compare p-adic 0658
int com_p0658(p0658_t a, p0658_t b);

#endif //C_P_ADIC_06_58_H

