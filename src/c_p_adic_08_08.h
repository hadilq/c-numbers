#ifndef C_P_ADIC_08_08_H
#define C_P_ADIC_08_08_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_08_08 8
#define EXPONENT_BITS_P_08_08 8
#define BITS_P_08_08 SIGNIFICAND_BITS_P_08_08 + EXPONENT_BITS_P_08_08

#define C_P_ADIC_08_08_DEBUG true

typedef uint16_t p0808_t;

#define SIGNIFICAND_MASK_P_08_08 ((1ULL << SIGNIFICAND_BITS_P_08_08) - 1)
#define EXPONENT_MASK_P_08_08 (((1ULL << EXPONENT_BITS_P_08_08) - 1) << SIGNIFICAND_BITS_P_08_08)
#define SIGNIFICAND_SIGN_MASK_P_08_08 (1U << (SIGNIFICAND_BITS_P_08_08 - 1))
#define EXPONENT_SIGN_MASK_P_08_08 (1U << (EXPONENT_BITS_P_08_08 - 1))
#define BITS_SIGN_MASK_P_08_08 (1U << (BITS_P_08_08 - 1))

#define MAX_VALUE_P_08_08 (((1U << (EXPONENT_BITS_P_08_08 - 2)) - 1) << SIGNIFICAND_BITS_P_08_08) | ((1U << (SIGNIFICAND_BITS_P_08_08 - 2)) - 1)
#define MIN_VALUE_P_08_08 (((1U << (EXPONENT_BITS_P_08_08 - 2)) - 1) << SIGNIFICAND_BITS_P_08_08) | (SIGNIFICAND_SIGN_MASK_P_08_08)

// construct p-adic 0808
p0808_t new_p0808(int16_t exp, int16_t sig);
// exponent part of p-adic 0808
int16_t exp_p0808(p0808_t a);
// significand part of p-adic 0808
int16_t sig_p0808(p0808_t a);
// add p-adic 0808
p0808_t add_p0808(p0808_t a, p0808_t b);
// subtract p-adic 0808
p0808_t sub_p0808(p0808_t a, p0808_t b);
// negate p-adic 0808
p0808_t neg_p0808(p0808_t a);
// multiply p-adic 0808
p0808_t mul_p0808(p0808_t a, p0808_t b);
// divide p-adic 0808
p0808_t div_p0808(p0808_t a, p0808_t b);
// equals p-adic 0808
bool equ_p0808(p0808_t a, p0808_t b);
// compare p-adic 0808
int com_p0808(p0808_t a, p0808_t b);

#endif //C_P_ADIC_08_08_H

