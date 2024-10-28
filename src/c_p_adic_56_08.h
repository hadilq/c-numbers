#ifndef C_P_ADIC_56_08_H
#define C_P_ADIC_56_08_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_56_08 56
#define EXPONENT_BITS_P_56_08 8
#define BITS_P_56_08 SIGNIFICAND_BITS_P_56_08 + EXPONENT_BITS_P_56_08

#define C_P_ADIC_56_08_DEBUG true

typedef uint64_t p5608_t;

#define SIGNIFICAND_MASK_P_56_08 ((1ULL << SIGNIFICAND_BITS_P_56_08) - 1)
#define EXPONENT_MASK_P_56_08 (((1ULL << EXPONENT_BITS_P_56_08) - 1) << SIGNIFICAND_BITS_P_56_08)
#define SIGNIFICAND_SIGN_MASK_P_56_08 (1ULL << (SIGNIFICAND_BITS_P_56_08 - 1))
#define EXPONENT_SIGN_MASK_P_56_08 (1ULL << (EXPONENT_BITS_P_56_08 - 1))
#define BITS_SIGN_MASK_P_56_08 (1ULL << (BITS_P_56_08 - 1))

// construct p-adic 5608
p5608_t new_p5608(uint64_t exp, uint64_t sig);
// exponent part of p-adic 5608
uint64_t exp_p5608(p5608_t a);
// significand part of p-adic 5608
uint64_t sig_p5608(p5608_t a);
// add p-adic 5608
p5608_t add_p5608(p5608_t a, p5608_t b);
// subtract p-adic 5608
p5608_t sub_p5608(p5608_t a, p5608_t b);
// negate p-adic 5608
p5608_t neg_p5608(p5608_t a);
// multiply p-adic 5608
p5608_t mul_p5608(p5608_t a, p5608_t b);
// divide p-adic 5608
p5608_t div_p5608(p5608_t a, p5608_t b);
// equals p-adic 5608
bool equ_p5608(p5608_t a, p5608_t b);
// compare p-adic 5608
int com_p5608(p5608_t a, p5608_t b);

#endif //C_P_ADIC_56_08_H

