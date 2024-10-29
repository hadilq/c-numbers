#ifndef C_FLOAT_04_04_H
#define C_FLOAT_04_04_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_04_04 4
#define EXPONENT_BITS_F_04_04 4
#define BITS_F_04_04 SIGNIFICAND_BITS_F_04_04 + EXPONENT_BITS_F_04_04

#define C_FLOAT_04_04_DEBUG true

typedef uint8_t f0404_t;

#define SIGNIFICAND_MASK_F_04_04 ((1U << SIGNIFICAND_BITS_F_04_04) - 1)
#define SIGNIFICAND_2_MASK_F_04_04 ((1UL << 2 * SIGNIFICAND_BITS_F_04_04) - 1)
#define EXPONENT_MASK_F_04_04 (((1U << EXPONENT_BITS_F_04_04) - 1) << SIGNIFICAND_BITS_F_04_04)
#define SIGNIFICAND_SIGN_MASK_F_04_04 (1U << (SIGNIFICAND_BITS_F_04_04 - 1))
#define EXPONENT_SIGN_MASK_F_04_04 (1U << (EXPONENT_BITS_F_04_04 - 1))
#define BITS_SIGN_MASK_F_04_04 (1U << (BITS_F_04_04 - 1))

#define MAX_VALUE_F_04_04 (((1U << (EXPONENT_BITS_F_04_04 - 2)) - 1) << SIGNIFICAND_BITS_F_04_04) | ((1U << (SIGNIFICAND_BITS_F_04_04 - 2)) - 1)
#define MIN_VALUE_F_04_04 (((1U << (EXPONENT_BITS_F_04_04 - 2)) - 1) << SIGNIFICAND_BITS_F_04_04) | (SIGNIFICAND_SIGN_MASK_F_04_04)

// construct float 0404
f0404_t new_f0404(int8_t exp, int8_t sig);
// exponent part of float 0404
int8_t exp_f0404(f0404_t a);
// significand part of float 0404
int8_t sig_f0404(f0404_t a);
// add float 0404
f0404_t add_f0404(f0404_t a, f0404_t b);
// subtract float 0404
f0404_t sub_f0404(f0404_t a, f0404_t b);
// negate float 0404
f0404_t neg_f0404(f0404_t a);
// multiply float 0404
f0404_t mul_f0404(f0404_t a, f0404_t b);
// divide float 0404
f0404_t div_f0404(f0404_t a, f0404_t b);
// equals float 0404
bool equ_f0404(f0404_t a, f0404_t b);
// compare float 0404
int com_f0404(f0404_t a, f0404_t b);

#endif // C_FLOAT_04_04_H

