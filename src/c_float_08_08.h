#ifndef C_FLOAT_08_08_H
#define C_FLOAT_08_08_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_08_08 8
#define EXPONENT_BITS_F_08_08 05
#define BITS_F_08_08 SIGNIFICAND_BITS_F_08_08 + EXPONENT_BITS_F_08_08

#define C_FLOAT_08_08_DEBUG true

typedef uint16_t f0808_t;

#define SIGNIFICAND_MASK_F_08_08 ((1U << SIGNIFICAND_BITS_F_08_08) - 1)
#define SIGNIFICAND_2_MASK_F_08_08 ((1UL << 2 * SIGNIFICAND_BITS_F_08_08) - 1)
#define EXPONENT_MASK_F_08_08 (((1U << EXPONENT_BITS_F_08_08) - 1) << SIGNIFICAND_BITS_F_08_08)
#define SIGNIFICAND_SIGN_MASK_F_08_08 (1U << (SIGNIFICAND_BITS_F_08_08 - 1))
#define EXPONENT_SIGN_MASK_F_08_08 (1U << (EXPONENT_BITS_F_08_08 - 1))
#define BITS_SIGN_MASK_F_08_08 (1U << (BITS_F_08_08 - 1))

#define MAX_VALUE_F_08_08 (((1U << (EXPONENT_BITS_F_08_08 - 2)) - 1) << SIGNIFICAND_BITS_F_08_08) | ((1U << (SIGNIFICAND_BITS_F_08_08 - 2)) - 1)
#define MIN_VALUE_F_08_08 (((1U << (EXPONENT_BITS_F_08_08 - 2)) - 1) << SIGNIFICAND_BITS_F_08_08) | (SIGNIFICAND_SIGN_MASK_F_08_08)

// construct float 0808
f0808_t new_f0808(int16_t exp, int16_t sig);
// construct float DDD32
f0808_t new_f0808_from_float16(_Float16 f);
// exponent part of float 0808
int16_t exp_f0808(f0808_t a);
// significand part of float 0808
int16_t sig_f0808(f0808_t a);
// add float 0808
f0808_t add_f0808(f0808_t a, f0808_t b);
// subtract float 0808
f0808_t sub_f0808(f0808_t a, f0808_t b);
// negate float 0808
f0808_t neg_f0808(f0808_t a);
// multiply float 0808
f0808_t mul_f0808(f0808_t a, f0808_t b);
// divide float 0808
f0808_t div_f0808(f0808_t a, f0808_t b);
// equals float 0808
bool equ_f0808(f0808_t a, f0808_t b);
// compare float 0808
int com_f0808(f0808_t a, f0808_t b);

#endif // C_FLOAT_08_08_H

