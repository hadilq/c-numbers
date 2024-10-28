#ifndef C_FLOAT_18_14_H
#define C_FLOAT_18_14_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_18_14 18
#define EXPONENT_BITS_F_18_14 06
#define BITS_F_18_14 SIGNIFICAND_BITS_F_18_14 + EXPONENT_BITS_F_18_14

#define C_FLOAT_18_14_DEBUG true

typedef uint32_t f1814_t;

#define SIGNIFICAND_MASK_F_18_14 ((1UL << SIGNIFICAND_BITS_F_18_14) - 1)
#define SIGNIFICAND_2_MASK_F_18_14 ((1ULL << 2 * SIGNIFICAND_BITS_F_18_14) - 1)
#define EXPONENT_MASK_F_18_14 (((1UL << EXPONENT_BITS_F_18_14) - 1) << SIGNIFICAND_BITS_F_18_14)
#define SIGNIFICAND_SIGN_MASK_F_18_14 (1UL << (SIGNIFICAND_BITS_F_18_14 - 1))
#define EXPONENT_SIGN_MASK_F_18_14 (1UL << (EXPONENT_BITS_F_18_14 - 1))
#define BITS_SIGN_MASK_F_18_14 (1UL << (BITS_F_18_14 - 1))

// construct float 26 06
f1814_t new_f1814(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f1814(f1814_t a);
// significand part of float 26 06
uint32_t sig_f1814(f1814_t a);
// add float 26 06
f1814_t add_f1814(f1814_t a, f1814_t b);
// subtract float 26 06
f1814_t sub_f1814(f1814_t a, f1814_t b);
// negate float 26 06
f1814_t neg_f1814(f1814_t a);
// multiply float 26 06
f1814_t mul_f1814(f1814_t a, f1814_t b);
// divide float 26 06
f1814_t div_f1814(f1814_t a, f1814_t b);
// equals float 26 06
bool equ_f1814(f1814_t a, f1814_t b);
// compare float 26 06
int com_f1814(f1814_t a, f1814_t b);

#endif // C_FLOAT_18_14_H

