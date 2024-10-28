#ifndef C_FLOAT_03_13_H
#define C_FLOAT_03_13_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_03_13 3
#define EXPONENT_BITS_F_03_13 05
#define BITS_F_03_13 SIGNIFICAND_BITS_F_03_13 + EXPONENT_BITS_F_03_13

#define C_FLOAT_03_13_DEBUG true

typedef uint16_t f0313_t;

#define SIGNIFICAND_MASK_F_03_13 ((1U << SIGNIFICAND_BITS_F_03_13) - 1)
#define SIGNIFICAND_2_MASK_F_03_13 ((1UL << 2 * SIGNIFICAND_BITS_F_03_13) - 1)
#define EXPONENT_MASK_F_03_13 (((1U << EXPONENT_BITS_F_03_13) - 1) << SIGNIFICAND_BITS_F_03_13)
#define SIGNIFICAND_SIGN_MASK_F_03_13 (1U << (SIGNIFICAND_BITS_F_03_13 - 1))
#define EXPONENT_SIGN_MASK_F_03_13 (1U << (EXPONENT_BITS_F_03_13 - 1))
#define BITS_SIGN_MASK_F_03_13 (1U << (BITS_F_03_13 - 1))

// construct float 0313
f0313_t new_f0313(uint16_t exp, uint16_t sig);
// exponent part of float 0313
uint16_t exp_f0313(f0313_t a);
// significand part of float 0313
uint16_t sig_f0313(f0313_t a);
// add float 0313
f0313_t add_f0313(f0313_t a, f0313_t b);
// subtract float 0313
f0313_t sub_f0313(f0313_t a, f0313_t b);
// negate float 0313
f0313_t neg_f0313(f0313_t a);
// multiply float 0313
f0313_t mul_f0313(f0313_t a, f0313_t b);
// divide float 0313
f0313_t div_f0313(f0313_t a, f0313_t b);
// equals float 0313
bool equ_f0313(f0313_t a, f0313_t b);
// compare float 0313
int com_f0313(f0313_t a, f0313_t b);

#endif // C_FLOAT_03_13_H

