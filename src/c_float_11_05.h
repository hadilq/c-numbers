#ifndef C_FLOAT_11_05_H
#define C_FLOAT_11_05_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_11_05 11
#define EXPONENT_BITS_F_11_05 05
#define BITS_F_11_05 SIGNIFICAND_BITS_F_11_05 + EXPONENT_BITS_F_11_05

#define C_FLOAT_11_05_DEBUG true

typedef uint16_t f1105_t;

#define SIGNIFICAND_MASK_F_11_05 ((1U << SIGNIFICAND_BITS_F_11_05) - 1)
#define SIGNIFICAND_2_MASK_F_11_05 ((1UL << 2 * SIGNIFICAND_BITS_F_11_05) - 1)
#define EXPONENT_MASK_F_11_05 (((1U << EXPONENT_BITS_F_11_05) - 1) << SIGNIFICAND_BITS_F_11_05)
#define SIGNIFICAND_SIGN_MASK_F_11_05 (1U << (SIGNIFICAND_BITS_F_11_05 - 1))
#define EXPONENT_SIGN_MASK_F_11_05 (1U << (EXPONENT_BITS_F_11_05 - 1))
#define BITS_SIGN_MASK_F_11_05 (1U << (BITS_F_11_05 - 1))

// construct float 1105
f1105_t new_f1105(uint16_t exp, uint16_t sig);
// exponent part of float 1105
uint16_t exp_f1105(f1105_t a);
// significand part of float 1105
uint16_t sig_f1105(f1105_t a);
// add float 1105
f1105_t add_f1105(f1105_t a, f1105_t b);
// subtract float 1105
f1105_t sub_f1105(f1105_t a, f1105_t b);
// negate float 1105
f1105_t neg_f1105(f1105_t a);
// multiply float 1105
f1105_t mul_f1105(f1105_t a, f1105_t b);
// divide float 1105
f1105_t div_f1105(f1105_t a, f1105_t b);
// equals float 1105
bool equ_f1105(f1105_t a, f1105_t b);
// compare float 1105
int com_f1105(f1105_t a, f1105_t b);

#endif // C_FLOAT_11_05_H

