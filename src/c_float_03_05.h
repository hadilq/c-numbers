#ifndef C_FLOAT_03_05_H
#define C_FLOAT_03_05_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_03_05 3
#define EXPONENT_BITS_F_03_05 5
#define BITS_F_03_05 SIGNIFICAND_BITS_F_03_05 + EXPONENT_BITS_F_03_05

#define C_FLOAT_03_05_DEBUG true

typedef uint8_t f0305_t;

#define SIGNIFICAND_MASK_F_03_05 ((1U << SIGNIFICAND_BITS_F_03_05) - 1)
#define SIGNIFICAND_2_MASK_F_03_05 ((1UL << 2 * SIGNIFICAND_BITS_F_03_05) - 1)
#define EXPONENT_MASK_F_03_05 (((1U << EXPONENT_BITS_F_03_05) - 1) << SIGNIFICAND_BITS_F_03_05)
#define SIGNIFICAND_SIGN_MASK_F_03_05 (1U << (SIGNIFICAND_BITS_F_03_05 - 1))
#define EXPONENT_SIGN_MASK_F_03_05 (1U << (EXPONENT_BITS_F_03_05 - 1))
#define BITS_SIGN_MASK_F_03_05 (1U << (BITS_F_03_05 - 1))

#define MAX_VALUE_F_03_05 (((1U << (EXPONENT_BITS_F_03_05 - 2)) - 1) << SIGNIFICAND_BITS_F_03_05) | ((1U << (SIGNIFICAND_BITS_F_03_05 - 2)) - 1)
#define MIN_VALUE_F_03_05 (((1U << (EXPONENT_BITS_F_03_05 - 2)) - 1) << SIGNIFICAND_BITS_F_03_05) | (SIGNIFICAND_SIGN_MASK_F_03_05)

// construct float 0305
f0305_t new_f0305(int8_t exp, int8_t sig);
// exponent part of float 0305
int8_t exp_f0305(f0305_t a);
// significand part of float 0305
int8_t sig_f0305(f0305_t a);
// add float 0305
f0305_t add_f0305(f0305_t a, f0305_t b);
// subtract float 0305
f0305_t sub_f0305(f0305_t a, f0305_t b);
// negate float 0305
f0305_t neg_f0305(f0305_t a);
// multiply float 0305
f0305_t mul_f0305(f0305_t a, f0305_t b);
// divide float 0305
f0305_t div_f0305(f0305_t a, f0305_t b);
// equals float 0305
bool equ_f0305(f0305_t a, f0305_t b);
// compare float 0305
int com_f0305(f0305_t a, f0305_t b);

#endif // C_FLOAT_03_05_H

