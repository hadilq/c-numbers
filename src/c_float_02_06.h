#ifndef C_FLOAT_02_06_H
#define C_FLOAT_02_06_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_02_06 2
#define EXPONENT_BITS_F_02_06 6
#define BITS_F_02_06 SIGNIFICAND_BITS_F_02_06 + EXPONENT_BITS_F_02_06

#define C_FLOAT_02_06_DEBUG true

typedef uint8_t f0206_t;

#define SIGNIFICAND_MASK_F_02_06 ((1U << SIGNIFICAND_BITS_F_02_06) - 1)
#define SIGNIFICAND_2_MASK_F_02_06 ((1UL << 2 * SIGNIFICAND_BITS_F_02_06) - 1)
#define EXPONENT_MASK_F_02_06 (((1U << EXPONENT_BITS_F_02_06) - 1) << SIGNIFICAND_BITS_F_02_06)
#define SIGNIFICAND_SIGN_MASK_F_02_06 (1U << (SIGNIFICAND_BITS_F_02_06 - 1))
#define EXPONENT_SIGN_MASK_F_02_06 (1U << (EXPONENT_BITS_F_02_06 - 1))
#define BITS_SIGN_MASK_F_02_06 (1U << (BITS_F_02_06 - 1))

// construct float 0206
f0206_t new_f0206(uint8_t exp, uint8_t sig);
// exponent part of float 0206
uint8_t exp_f0206(f0206_t a);
// significand part of float 0206
uint8_t sig_f0206(f0206_t a);
// add float 0206
f0206_t add_f0206(f0206_t a, f0206_t b);
// subtract float 0206
f0206_t sub_f0206(f0206_t a, f0206_t b);
// negate float 0206
f0206_t neg_f0206(f0206_t a);
// multiply float 0206
f0206_t mul_f0206(f0206_t a, f0206_t b);
// divide float 0206
f0206_t div_f0206(f0206_t a, f0206_t b);
// equals float 0206
bool equ_f0206(f0206_t a, f0206_t b);
// compare float 0206
int com_f0206(f0206_t a, f0206_t b);

#endif // C_FLOAT_02_06_H

