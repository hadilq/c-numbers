#ifndef C_P_ADIC_08_56_H
#define C_P_ADIC_08_56_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_08_56 8
#define EXPONENT_BITS_P_08_56 56
#define BITS_P_08_56 SIGNIFICAND_BITS_P_08_56 + EXPONENT_BITS_P_08_56

#define C_P_ADIC_08_56_DEBUG true

typedef uint64_t p0856_t;

#define SIGNIFICAND_MASK_P_08_56 ((1ULL << SIGNIFICAND_BITS_P_08_56) - 1)
#define EXPONENT_MASK_P_08_56 (((1ULL << EXPONENT_BITS_P_08_56) - 1) << SIGNIFICAND_BITS_P_08_56)
#define SIGNIFICAND_SIGN_MASK_P_08_56 (1ULL << (SIGNIFICAND_BITS_P_08_56 - 1))
#define EXPONENT_SIGN_MASK_P_08_56 (1ULL << (EXPONENT_BITS_P_08_56 - 1))
#define BITS_SIGN_MASK_P_08_56 (1ULL << (BITS_P_08_56 - 1))

#define MAX_VALUE_P_08_56 (((1ULL << (EXPONENT_BITS_P_08_56 - 2)) - 1) << SIGNIFICAND_BITS_P_08_56) | ((1ULL << (SIGNIFICAND_BITS_P_08_56 - 2)) - 1)
#define MIN_VALUE_P_08_56 (((1ULL << (EXPONENT_BITS_P_08_56 - 2)) - 1) << SIGNIFICAND_BITS_P_08_56) | (SIGNIFICAND_SIGN_MASK_P_08_56)

// construct p-adic 0856
p0856_t new_p0856(int64_t exp, int64_t sig);
// exponent part of p-adic 0856
int64_t exp_p0856(p0856_t a);
// significand part of p-adic 0856
int64_t sig_p0856(p0856_t a);
// add p-adic 0856
p0856_t add_p0856(p0856_t a, p0856_t b);
// subtract p-adic 0856
p0856_t sub_p0856(p0856_t a, p0856_t b);
// negate p-adic 0856
p0856_t neg_p0856(p0856_t a);
// multiply p-adic 0856
p0856_t mul_p0856(p0856_t a, p0856_t b);
// divide p-adic 0856
p0856_t div_p0856(p0856_t a, p0856_t b);
// equals p-adic 0856
bool equ_p0856(p0856_t a, p0856_t b);
// compare p-adic 0856
int com_p0856(p0856_t a, p0856_t b);

#endif //C_P_ADIC_08_56_H

