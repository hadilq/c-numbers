#ifndef C_P_ADIC_09_55_H
#define C_P_ADIC_09_55_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_09_55 9
#define EXPONENT_BITS_P_09_55 55
#define BITS_P_09_55 SIGNIFICAND_BITS_P_09_55 + EXPONENT_BITS_P_09_55

#define C_P_ADIC_09_55_DEBUG true

typedef uint64_t p0955_t;

#define SIGNIFICAND_MASK_P_09_55 ((1ULL << SIGNIFICAND_BITS_P_09_55) - 1)
#define EXPONENT_MASK_P_09_55 (((1ULL << EXPONENT_BITS_P_09_55) - 1) << SIGNIFICAND_BITS_P_09_55)
#define SIGNIFICAND_SIGN_MASK_P_09_55 (1ULL << (SIGNIFICAND_BITS_P_09_55 - 1))
#define EXPONENT_SIGN_MASK_P_09_55 (1ULL << (EXPONENT_BITS_P_09_55 - 1))
#define BITS_SIGN_MASK_P_09_55 (1ULL << (BITS_P_09_55 - 1))

#define MAX_VALUE_P_09_55 (((1ULL << (EXPONENT_BITS_P_09_55 - 2)) - 1) << SIGNIFICAND_BITS_P_09_55) | ((1ULL << (SIGNIFICAND_BITS_P_09_55 - 2)) - 1)
#define MIN_VALUE_P_09_55 (((1ULL << (EXPONENT_BITS_P_09_55 - 2)) - 1) << SIGNIFICAND_BITS_P_09_55) | (SIGNIFICAND_SIGN_MASK_P_09_55)

// construct p-adic 0955
p0955_t new_p0955(int64_t exp, int64_t sig);
// exponent part of p-adic 0955
int64_t exp_p0955(p0955_t a);
// significand part of p-adic 0955
int64_t sig_p0955(p0955_t a);
// add p-adic 0955
p0955_t add_p0955(p0955_t a, p0955_t b);
// subtract p-adic 0955
p0955_t sub_p0955(p0955_t a, p0955_t b);
// negate p-adic 0955
p0955_t neg_p0955(p0955_t a);
// multiply p-adic 0955
p0955_t mul_p0955(p0955_t a, p0955_t b);
// divide p-adic 0955
p0955_t div_p0955(p0955_t a, p0955_t b);
// equals p-adic 0955
bool equ_p0955(p0955_t a, p0955_t b);
// compare p-adic 0955
int com_p0955(p0955_t a, p0955_t b);

#endif //C_P_ADIC_09_55_H

