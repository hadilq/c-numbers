#ifndef C_P_ADIC_51_13_H
#define C_P_ADIC_51_13_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_51_13 51
#define EXPONENT_BITS_P_51_13 13
#define BITS_P_51_13 SIGNIFICAND_BITS_P_51_13 + EXPONENT_BITS_P_51_13

#define C_P_ADIC_51_13_DEBUG true

typedef uint64_t p5113_t;

#define SIGNIFICAND_MASK_P_51_13 ((1ULL << SIGNIFICAND_BITS_P_51_13) - 1)
#define EXPONENT_MASK_P_51_13 (((1ULL << EXPONENT_BITS_P_51_13) - 1) << SIGNIFICAND_BITS_P_51_13)
#define SIGNIFICAND_SIGN_MASK_P_51_13 (1ULL << (SIGNIFICAND_BITS_P_51_13 - 1))
#define EXPONENT_SIGN_MASK_P_51_13 (1ULL << (EXPONENT_BITS_P_51_13 - 1))
#define BITS_SIGN_MASK_P_51_13 (1ULL << (BITS_P_51_13 - 1))

// construct p-adic 5113
p5113_t new_p5113(uint64_t exp, uint64_t sig);
// exponent part of p-adic 5113
uint64_t exp_p5113(p5113_t a);
// significand part of p-adic 5113
uint64_t sig_p5113(p5113_t a);
// add p-adic 5113
p5113_t add_p5113(p5113_t a, p5113_t b);
// subtract p-adic 5113
p5113_t sub_p5113(p5113_t a, p5113_t b);
// negate p-adic 5113
p5113_t neg_p5113(p5113_t a);
// multiply p-adic 5113
p5113_t mul_p5113(p5113_t a, p5113_t b);
// divide p-adic 5113
p5113_t div_p5113(p5113_t a, p5113_t b);
// equals p-adic 5113
bool equ_p5113(p5113_t a, p5113_t b);
// compare p-adic 5113
int com_p5113(p5113_t a, p5113_t b);

#endif //C_P_ADIC_51_13_H

