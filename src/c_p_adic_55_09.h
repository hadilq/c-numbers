#ifndef C_P_ADIC_55_09_H
#define C_P_ADIC_55_09_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_55_09 55
#define EXPONENT_BITS_P_55_09 9
#define BITS_P_55_09 SIGNIFICAND_BITS_P_55_09 + EXPONENT_BITS_P_55_09

#define C_P_ADIC_55_09_DEBUG true

typedef uint64_t p5509_t;

#define SIGNIFICAND_MASK_P_55_09 ((1ULL << SIGNIFICAND_BITS_P_55_09) - 1)
#define EXPONENT_MASK_P_55_09 (((1ULL << EXPONENT_BITS_P_55_09) - 1) << SIGNIFICAND_BITS_P_55_09)
#define SIGNIFICAND_SIGN_MASK_P_55_09 (1ULL << (SIGNIFICAND_BITS_P_55_09 - 1))
#define EXPONENT_SIGN_MASK_P_55_09 (1ULL << (EXPONENT_BITS_P_55_09 - 1))
#define BITS_SIGN_MASK_P_55_09 (1ULL << (BITS_P_55_09 - 1))

#define MAX_VALUE_P_55_09 (((1ULL << (EXPONENT_BITS_P_55_09 - 2)) - 1) << SIGNIFICAND_BITS_P_55_09) | ((1ULL << (SIGNIFICAND_BITS_P_55_09 - 2)) - 1)
#define MIN_VALUE_P_55_09 (((1ULL << (EXPONENT_BITS_P_55_09 - 2)) - 1) << SIGNIFICAND_BITS_P_55_09) | (SIGNIFICAND_SIGN_MASK_P_55_09)

// construct p-adic 5509
p5509_t new_p5509(int64_t exp, int64_t sig);
// exponent part of p-adic 5509
int64_t exp_p5509(p5509_t a);
// significand part of p-adic 5509
int64_t sig_p5509(p5509_t a);
// add p-adic 5509
p5509_t add_p5509(p5509_t a, p5509_t b);
// subtract p-adic 5509
p5509_t sub_p5509(p5509_t a, p5509_t b);
// negate p-adic 5509
p5509_t neg_p5509(p5509_t a);
// multiply p-adic 5509
p5509_t mul_p5509(p5509_t a, p5509_t b);
// divide p-adic 5509
p5509_t div_p5509(p5509_t a, p5509_t b);
// equals p-adic 5509
bool equ_p5509(p5509_t a, p5509_t b);
// compare p-adic 5509
int com_p5509(p5509_t a, p5509_t b);

#endif //C_P_ADIC_55_09_H

