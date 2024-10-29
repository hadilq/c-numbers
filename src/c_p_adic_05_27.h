#ifndef C_P_ADIC_05_27_H
#define C_P_ADIC_05_27_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_05_27 5
#define EXPONENT_BITS_P_05_27 06
#define BITS_P_05_27 SIGNIFICAND_BITS_P_05_27 + EXPONENT_BITS_P_05_27

#define C_P_ADIC_05_27_DEBUG true

typedef uint32_t p0527_t;

#define SIGNIFICAND_MASK_P_05_27 ((1ULL << SIGNIFICAND_BITS_P_05_27) - 1)
#define EXPONENT_MASK_P_05_27 (((1ULL << EXPONENT_BITS_P_05_27) - 1) << SIGNIFICAND_BITS_P_05_27)
#define SIGNIFICAND_SIGN_MASK_P_05_27 (1U << (SIGNIFICAND_BITS_P_05_27 - 1))
#define EXPONENT_SIGN_MASK_P_05_27 (1U << (EXPONENT_BITS_P_05_27 - 1))
#define BITS_SIGN_MASK_P_05_27 (1U << (BITS_P_05_27 - 1))

#define MAX_VALUE_P_05_27 (((1U << (EXPONENT_BITS_P_05_27 - 2)) - 1) << SIGNIFICAND_BITS_P_05_27) | ((1U << (SIGNIFICAND_BITS_P_05_27 - 2)) - 1)
#define MIN_VALUE_P_05_27 (((1U << (EXPONENT_BITS_P_05_27 - 2)) - 1) << SIGNIFICAND_BITS_P_05_27) | (SIGNIFICAND_SIGN_MASK_P_05_27)

// construct p-adic 0527
p0527_t new_p0527(int32_t exp, int32_t sig);
// exponent part of p-adic 0527
int32_t exp_p0527(p0527_t a);
// significand part of p-adic 0527
int32_t sig_p0527(p0527_t a);
// add p-adic 0527
p0527_t add_p0527(p0527_t a, p0527_t b);
// subtract p-adic 0527
p0527_t sub_p0527(p0527_t a, p0527_t b);
// negate p-adic 0527
p0527_t neg_p0527(p0527_t a);
// multiply p-adic 0527
p0527_t mul_p0527(p0527_t a, p0527_t b);
// divide p-adic 0527
p0527_t div_p0527(p0527_t a, p0527_t b);
// equals p-adic 0527
bool equ_p0527(p0527_t a, p0527_t b);
// compare p-adic 0527
int com_p0527(p0527_t a, p0527_t b);

#endif //C_P_ADIC_05_27_H

