#ifndef C_FLOAT_22_10_H
#define C_FLOAT_22_10_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_22_10 22
#define EXPONENT_BITS_F_22_10 06
#define BITS_F_22_10 SIGNIFICAND_BITS_F_22_10 + EXPONENT_BITS_F_22_10

#define C_FLOAT_22_10_DEBUG true

typedef uint32_t f2210_t;

#define SIGNIFICAND_MASK_F_22_10 ((1UL << SIGNIFICAND_BITS_F_22_10) - 1)
#define SIGNIFICAND_2_MASK_F_22_10 ((1ULL << 2 * SIGNIFICAND_BITS_F_22_10) - 1)
#define EXPONENT_MASK_F_22_10 (((1UL << EXPONENT_BITS_F_22_10) - 1) << SIGNIFICAND_BITS_F_22_10)
#define SIGNIFICAND_SIGN_MASK_F_22_10 (1UL << (SIGNIFICAND_BITS_F_22_10 - 1))
#define EXPONENT_SIGN_MASK_F_22_10 (1UL << (EXPONENT_BITS_F_22_10 - 1))
#define BITS_SIGN_MASK_F_22_10 (1UL << (BITS_F_22_10 - 1))

// construct float 26 06
f2210_t new_f2210(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f2210(f2210_t a);
// significand part of float 26 06
uint32_t sig_f2210(f2210_t a);
// add float 26 06
f2210_t add_f2210(f2210_t a, f2210_t b);
// subtract float 26 06
f2210_t sub_f2210(f2210_t a, f2210_t b);
// negate float 26 06
f2210_t neg_f2210(f2210_t a);
// multiply float 26 06
f2210_t mul_f2210(f2210_t a, f2210_t b);
// divide float 26 06
f2210_t div_f2210(f2210_t a, f2210_t b);
// equals float 26 06
bool equ_f2210(f2210_t a, f2210_t b);
// compare float 26 06
int com_f2210(f2210_t a, f2210_t b);

#endif // C_FLOAT_22_10_H

