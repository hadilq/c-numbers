#ifndef C_P_ADIC_05_59_H
#define C_P_ADIC_05_59_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_05_59 5
#define EXPONENT_BITS_P_05_59 59
#define BITS_P_05_59 SIGNIFICAND_BITS_P_05_59 + EXPONENT_BITS_P_05_59

#define C_P_ADIC_05_59_DEBUG true

typedef uint64_t p0559_t;

#define SIGNIFICAND_MASK_P_05_59 ((1ULL << SIGNIFICAND_BITS_P_05_59) - 1)
#define EXPONENT_MASK_P_05_59 (((1ULL << EXPONENT_BITS_P_05_59) - 1) << SIGNIFICAND_BITS_P_05_59)
#define SIGNIFICAND_SIGN_MASK_P_05_59 (1ULL << (SIGNIFICAND_BITS_P_05_59 - 1))
#define EXPONENT_SIGN_MASK_P_05_59 (1ULL << (EXPONENT_BITS_P_05_59 - 1))
#define BITS_SIGN_MASK_P_05_59 (1ULL << (BITS_P_05_59 - 1))

// construct p-adic 0559
p0559_t new_p0559(uint64_t exp, uint64_t sig);
// exponent part of p-adic 0559
uint64_t exp_p0559(p0559_t a);
// significand part of p-adic 0559
uint64_t sig_p0559(p0559_t a);
// add p-adic 0559
p0559_t add_p0559(p0559_t a, p0559_t b);
// subtract p-adic 0559
p0559_t sub_p0559(p0559_t a, p0559_t b);
// negate p-adic 0559
p0559_t neg_p0559(p0559_t a);
// multiply p-adic 0559
p0559_t mul_p0559(p0559_t a, p0559_t b);
// divide p-adic 0559
p0559_t div_p0559(p0559_t a, p0559_t b);
// equals p-adic 0559
bool equ_p0559(p0559_t a, p0559_t b);
// compare p-adic 0559
int com_p0559(p0559_t a, p0559_t b);

#endif //C_P_ADIC_05_59_H

