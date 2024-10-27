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
#define EXPONENT_MASK_F_04_04 (((1U << EXPONENT_BITS_F_04_04) - 1) << SIGNIFICAND_BITS_F_04_04)
#define SIGNIFICAND_SIGN_MASK_F_04_04 (1U << (SIGNIFICAND_BITS_F_04_04 - 1))
#define EXPONENT_SIGN_MASK_F_04_04 (1U << (EXPONENT_BITS_F_04_04 - 1))

// construct float 04 04
f0404_t new_f0404(uint8_t exp, uint8_t sig);
// exponent part of float 04 04
uint8_t exp_f0404(f0404_t a);
// significand part of float 04 04
uint8_t sig_f0404(f0404_t a);
// add float 04 04
f0404_t add_f0404(f0404_t a, f0404_t b);
// subtract float 04 04
f0404_t sub_f0404(f0404_t a, f0404_t b);
// negate float 04 04
f0404_t neg_f0404(f0404_t a);
// multiply float 04 04
f0404_t mul_f0404(f0404_t a, f0404_t b);
// divide float 04 04
f0404_t div_f0404(f0404_t a, f0404_t b);
// equals float 04 04
bool equ_f0404(f0404_t a, f0404_t b);
// compare float 04 04
int com_f0404(f0404_t a, f0404_t b);

#endif // C_FLOAT_04_04_H

