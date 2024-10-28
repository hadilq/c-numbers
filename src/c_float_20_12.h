#ifndef C_FLOAT_20_12_H
#define C_FLOAT_20_12_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_20_12 20
#define EXPONENT_BITS_F_20_12 06
#define BITS_F_20_12 SIGNIFICAND_BITS_F_20_12 + EXPONENT_BITS_F_20_12

#define C_FLOAT_20_12_DEBUG true

typedef uint32_t f2012_t;

#define SIGNIFICAND_MASK_F_20_12 ((1UL << SIGNIFICAND_BITS_F_20_12) - 1)
#define SIGNIFICAND_2_MASK_F_20_12 ((1ULL << 2 * SIGNIFICAND_BITS_F_20_12) - 1)
#define EXPONENT_MASK_F_20_12 (((1UL << EXPONENT_BITS_F_20_12) - 1) << SIGNIFICAND_BITS_F_20_12)
#define SIGNIFICAND_SIGN_MASK_F_20_12 (1UL << (SIGNIFICAND_BITS_F_20_12 - 1))
#define EXPONENT_SIGN_MASK_F_20_12 (1UL << (EXPONENT_BITS_F_20_12 - 1))
#define BITS_SIGN_MASK_F_20_12 (1UL << (BITS_F_20_12 - 1))

// construct float 26 06
f2012_t new_f2012(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f2012(f2012_t a);
// significand part of float 26 06
uint32_t sig_f2012(f2012_t a);
// add float 26 06
f2012_t add_f2012(f2012_t a, f2012_t b);
// subtract float 26 06
f2012_t sub_f2012(f2012_t a, f2012_t b);
// negate float 26 06
f2012_t neg_f2012(f2012_t a);
// multiply float 26 06
f2012_t mul_f2012(f2012_t a, f2012_t b);
// divide float 26 06
f2012_t div_f2012(f2012_t a, f2012_t b);
// equals float 26 06
bool equ_f2012(f2012_t a, f2012_t b);
// compare float 26 06
int com_f2012(f2012_t a, f2012_t b);

#endif // C_FLOAT_20_12_H

