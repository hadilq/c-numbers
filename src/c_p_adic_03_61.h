#ifndef C_P_ADIC_03_61_H
#define C_P_ADIC_03_61_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_03_61 3
#define EXPONENT_BITS_P_03_61 61
#define BITS_P_03_61 SIGNIFICAND_BITS_P_03_61 + EXPONENT_BITS_P_03_61

#define C_P_ADIC_03_61_DEBUG true

typedef uint64_t p0361_t;

#define SIGNIFICAND_MASK_P_03_61 ((1ULL << SIGNIFICAND_BITS_P_03_61) - 1)
#define EXPONENT_MASK_P_03_61 (((1ULL << EXPONENT_BITS_P_03_61) - 1) << SIGNIFICAND_BITS_P_03_61)
#define SIGNIFICAND_SIGN_MASK_P_03_61 (1ULL << (SIGNIFICAND_BITS_P_03_61 - 1))
#define EXPONENT_SIGN_MASK_P_03_61 (1ULL << (EXPONENT_BITS_P_03_61 - 1))
#define BITS_SIGN_MASK_P_03_61 (1ULL << (BITS_P_03_61 - 1))

#define MAX_VALUE_P_03_61 (((1ULL << (EXPONENT_BITS_P_03_61 - 2)) - 1) << SIGNIFICAND_BITS_P_03_61) | ((1ULL << (SIGNIFICAND_BITS_P_03_61 - 2)) - 1)
#define MIN_VALUE_P_03_61 (((1ULL << (EXPONENT_BITS_P_03_61 - 2)) - 1) << SIGNIFICAND_BITS_P_03_61) | (SIGNIFICAND_SIGN_MASK_P_03_61)

// construct p-adic 0361
p0361_t new_p0361(int64_t exp, int64_t sig);
// exponent part of p-adic 0361
int64_t exp_p0361(p0361_t a);
// significand part of p-adic 0361
int64_t sig_p0361(p0361_t a);
// add p-adic 0361
p0361_t add_p0361(p0361_t a, p0361_t b);
// subtract p-adic 0361
p0361_t sub_p0361(p0361_t a, p0361_t b);
// negate p-adic 0361
p0361_t neg_p0361(p0361_t a);
// multiply p-adic 0361
p0361_t mul_p0361(p0361_t a, p0361_t b);
// divide p-adic 0361
p0361_t div_p0361(p0361_t a, p0361_t b);
// equals p-adic 0361
bool equ_p0361(p0361_t a, p0361_t b);
// compare p-adic 0361
int com_p0361(p0361_t a, p0361_t b);

#endif //C_P_ADIC_03_61_H

