#ifndef C_FLOAT_05_11_H
#define C_FLOAT_05_11_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_05_11 5
#define EXPONENT_BITS_F_05_11 05
#define BITS_F_05_11 SIGNIFICAND_BITS_F_05_11 + EXPONENT_BITS_F_05_11

#define C_FLOAT_05_11_DEBUG true

typedef uint16_t f0511_t;

#define SIGNIFICAND_MASK_F_05_11 ((1U << SIGNIFICAND_BITS_F_05_11) - 1)
#define SIGNIFICAND_2_MASK_F_05_11 ((1UL << 2 * SIGNIFICAND_BITS_F_05_11) - 1)
#define EXPONENT_MASK_F_05_11 (((1U << EXPONENT_BITS_F_05_11) - 1) << SIGNIFICAND_BITS_F_05_11)
#define SIGNIFICAND_SIGN_MASK_F_05_11 (1U << (SIGNIFICAND_BITS_F_05_11 - 1))
#define EXPONENT_SIGN_MASK_F_05_11 (1U << (EXPONENT_BITS_F_05_11 - 1))
#define BITS_SIGN_MASK_F_05_11 (1U << (BITS_F_05_11 - 1))

// construct float 0511
f0511_t new_f0511(uint16_t exp, uint16_t sig);
// exponent part of float 0511
uint16_t exp_f0511(f0511_t a);
// significand part of float 0511
uint16_t sig_f0511(f0511_t a);
// add float 0511
f0511_t add_f0511(f0511_t a, f0511_t b);
// subtract float 0511
f0511_t sub_f0511(f0511_t a, f0511_t b);
// negate float 0511
f0511_t neg_f0511(f0511_t a);
// multiply float 0511
f0511_t mul_f0511(f0511_t a, f0511_t b);
// divide float 0511
f0511_t div_f0511(f0511_t a, f0511_t b);
// equals float 0511
bool equ_f0511(f0511_t a, f0511_t b);
// compare float 0511
int com_f0511(f0511_t a, f0511_t b);

#endif // C_FLOAT_05_11_H

