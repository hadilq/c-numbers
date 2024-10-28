#ifndef C_FLOAT_04_28_H
#define C_FLOAT_04_28_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_04_28 4
#define EXPONENT_BITS_F_04_28 06
#define BITS_F_04_28 SIGNIFICAND_BITS_F_04_28 + EXPONENT_BITS_F_04_28

#define C_FLOAT_04_28_DEBUG true

typedef uint32_t f0428_t;

#define SIGNIFICAND_MASK_F_04_28 ((1UL << SIGNIFICAND_BITS_F_04_28) - 1)
#define SIGNIFICAND_2_MASK_F_04_28 ((1ULL << 2 * SIGNIFICAND_BITS_F_04_28) - 1)
#define EXPONENT_MASK_F_04_28 (((1UL << EXPONENT_BITS_F_04_28) - 1) << SIGNIFICAND_BITS_F_04_28)
#define SIGNIFICAND_SIGN_MASK_F_04_28 (1UL << (SIGNIFICAND_BITS_F_04_28 - 1))
#define EXPONENT_SIGN_MASK_F_04_28 (1UL << (EXPONENT_BITS_F_04_28 - 1))
#define BITS_SIGN_MASK_F_04_28 (1UL << (BITS_F_04_28 - 1))

// construct float 26 06
f0428_t new_f0428(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f0428(f0428_t a);
// significand part of float 26 06
uint32_t sig_f0428(f0428_t a);
// add float 26 06
f0428_t add_f0428(f0428_t a, f0428_t b);
// subtract float 26 06
f0428_t sub_f0428(f0428_t a, f0428_t b);
// negate float 26 06
f0428_t neg_f0428(f0428_t a);
// multiply float 26 06
f0428_t mul_f0428(f0428_t a, f0428_t b);
// divide float 26 06
f0428_t div_f0428(f0428_t a, f0428_t b);
// equals float 26 06
bool equ_f0428(f0428_t a, f0428_t b);
// compare float 26 06
int com_f0428(f0428_t a, f0428_t b);

#endif // C_FLOAT_04_28_H

