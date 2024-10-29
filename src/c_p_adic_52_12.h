#ifndef C_P_ADIC_52_12_H
#define C_P_ADIC_52_12_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_52_12 52
#define EXPONENT_BITS_P_52_12 12
#define BITS_P_52_12 SIGNIFICAND_BITS_P_52_12 + EXPONENT_BITS_P_52_12

#define C_P_ADIC_52_12_DEBUG true

typedef uint64_t p5212_t;

#define SIGNIFICAND_MASK_P_52_12 ((1ULL << SIGNIFICAND_BITS_P_52_12) - 1)
#define EXPONENT_MASK_P_52_12 (((1ULL << EXPONENT_BITS_P_52_12) - 1) << SIGNIFICAND_BITS_P_52_12)
#define SIGNIFICAND_SIGN_MASK_P_52_12 (1ULL << (SIGNIFICAND_BITS_P_52_12 - 1))
#define EXPONENT_SIGN_MASK_P_52_12 (1ULL << (EXPONENT_BITS_P_52_12 - 1))
#define BITS_SIGN_MASK_P_52_12 (1ULL << (BITS_P_52_12 - 1))

#define MAX_VALUE_P_52_12 (((1ULL << (EXPONENT_BITS_P_52_12 - 2)) - 1) << SIGNIFICAND_BITS_P_52_12) | ((1ULL << (SIGNIFICAND_BITS_P_52_12 - 2)) - 1)
#define MIN_VALUE_P_52_12 (((1ULL << (EXPONENT_BITS_P_52_12 - 2)) - 1) << SIGNIFICAND_BITS_P_52_12) | (SIGNIFICAND_SIGN_MASK_P_52_12)

// construct p-adic 5212
p5212_t new_p5212(int64_t exp, int64_t sig);
// exponent part of p-adic 5212
int64_t exp_p5212(p5212_t a);
// significand part of p-adic 5212
int64_t sig_p5212(p5212_t a);
// add p-adic 5212
p5212_t add_p5212(p5212_t a, p5212_t b);
// subtract p-adic 5212
p5212_t sub_p5212(p5212_t a, p5212_t b);
// negate p-adic 5212
p5212_t neg_p5212(p5212_t a);
// multiply p-adic 5212
p5212_t mul_p5212(p5212_t a, p5212_t b);
// divide p-adic 5212
p5212_t div_p5212(p5212_t a, p5212_t b);
// equals p-adic 5212
bool equ_p5212(p5212_t a, p5212_t b);
// compare p-adic 5212
int com_p5212(p5212_t a, p5212_t b);

#endif //C_P_ADIC_52_12_H

