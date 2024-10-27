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
#define EXPONENT_MASK_F_11_05 (((1U << EXPONENT_BITS_F_11_05) - 1) << SIGNIFICAND_BITS_F_11_05)
#define SIGNIFICAND_SIGN_MASK_F_11_05 (1U << (SIGNIFICAND_BITS_F_11_05 - 1))
#define EXPONENT_SIGN_MASK_F_11_05 (1U << (EXPONENT_BITS_F_11_05 - 1))

// construct float 11 05
f1105_t new_f1105(uint16_t exp, uint16_t sig);
// exponent part of float 11 05
uint16_t exp_f1105(f1105_t a);
// significand part of float 11 05
uint16_t sig_f1105(f1105_t a);
// add float 11 05
f1105_t add_f1105(f1105_t a, f1105_t b);
// subtract float 11 05
f1105_t sub_f1105(f1105_t a, f1105_t b);
// negate float 11 05
f1105_t neg_f1105(f1105_t a);
// multiply float 11 05
f1105_t mul_f1105(f1105_t a, f1105_t b);
// divide float 11 05
f1105_t div_f1105(f1105_t a, f1105_t b);
// equals float 11 05
bool equ_f1105(f1105_t a, f1105_t b);
// compare float 11 05
int com_f1105(f1105_t a, f1105_t b);

#endif // C_FLOAT_11_05_H

