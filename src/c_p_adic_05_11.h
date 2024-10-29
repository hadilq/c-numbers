#ifndef C_P_ADIC_05_11_H
#define C_P_ADIC_05_11_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_05_11 5
#define EXPONENT_BITS_P_05_11 11
#define BITS_P_05_11 SIGNIFICAND_BITS_P_05_11 + EXPONENT_BITS_P_05_11

#define C_P_ADIC_05_11_DEBUG true

typedef uint16_t p0511_t;

#define SIGNIFICAND_MASK_P_05_11 ((1ULL << SIGNIFICAND_BITS_P_05_11) - 1)
#define EXPONENT_MASK_P_05_11 (((1ULL << EXPONENT_BITS_P_05_11) - 1) << SIGNIFICAND_BITS_P_05_11)
#define SIGNIFICAND_SIGN_MASK_P_05_11 (1U << (SIGNIFICAND_BITS_P_05_11 - 1))
#define EXPONENT_SIGN_MASK_P_05_11 (1U << (EXPONENT_BITS_P_05_11 - 1))
#define BITS_SIGN_MASK_P_05_11 (1U << (BITS_P_05_11 - 1))

#define MAX_VALUE_P_05_11 (((1U << (EXPONENT_BITS_P_05_11 - 2)) - 1) << SIGNIFICAND_BITS_P_05_11) | ((1U << (SIGNIFICAND_BITS_P_05_11 - 2)) - 1)
#define MIN_VALUE_P_05_11 (((1U << (EXPONENT_BITS_P_05_11 - 2)) - 1) << SIGNIFICAND_BITS_P_05_11) | (SIGNIFICAND_SIGN_MASK_P_05_11)

// construct p-adic 0511
p0511_t new_p0511(int16_t exp, int16_t sig);
// exponent part of p-adic 0511
int16_t exp_p0511(p0511_t a);
// significand part of p-adic 0511
int16_t sig_p0511(p0511_t a);
// add p-adic 0511
p0511_t add_p0511(p0511_t a, p0511_t b);
// subtract p-adic 0511
p0511_t sub_p0511(p0511_t a, p0511_t b);
// negate p-adic 0511
p0511_t neg_p0511(p0511_t a);
// multiply p-adic 0511
p0511_t mul_p0511(p0511_t a, p0511_t b);
// divide p-adic 0511
p0511_t div_p0511(p0511_t a, p0511_t b);
// equals p-adic 0511
bool equ_p0511(p0511_t a, p0511_t b);
// compare p-adic 0511
int com_p0511(p0511_t a, p0511_t b);

#endif //C_P_ADIC_05_11_H

