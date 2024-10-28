#ifndef C_FLOAT_10_22_H
#define C_FLOAT_10_22_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_10_22 10
#define EXPONENT_BITS_F_10_22 06
#define BITS_F_10_22 SIGNIFICAND_BITS_F_10_22 + EXPONENT_BITS_F_10_22

#define C_FLOAT_10_22_DEBUG true

typedef uint32_t f1022_t;

#define SIGNIFICAND_MASK_F_10_22 ((1UL << SIGNIFICAND_BITS_F_10_22) - 1)
#define SIGNIFICAND_2_MASK_F_10_22 ((1ULL << 2 * SIGNIFICAND_BITS_F_10_22) - 1)
#define EXPONENT_MASK_F_10_22 (((1UL << EXPONENT_BITS_F_10_22) - 1) << SIGNIFICAND_BITS_F_10_22)
#define SIGNIFICAND_SIGN_MASK_F_10_22 (1UL << (SIGNIFICAND_BITS_F_10_22 - 1))
#define EXPONENT_SIGN_MASK_F_10_22 (1UL << (EXPONENT_BITS_F_10_22 - 1))
#define BITS_SIGN_MASK_F_10_22 (1UL << (BITS_F_10_22 - 1))

// construct float 26 06
f1022_t new_f1022(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f1022(f1022_t a);
// significand part of float 26 06
uint32_t sig_f1022(f1022_t a);
// add float 26 06
f1022_t add_f1022(f1022_t a, f1022_t b);
// subtract float 26 06
f1022_t sub_f1022(f1022_t a, f1022_t b);
// negate float 26 06
f1022_t neg_f1022(f1022_t a);
// multiply float 26 06
f1022_t mul_f1022(f1022_t a, f1022_t b);
// divide float 26 06
f1022_t div_f1022(f1022_t a, f1022_t b);
// equals float 26 06
bool equ_f1022(f1022_t a, f1022_t b);
// compare float 26 06
int com_f1022(f1022_t a, f1022_t b);

#endif // C_FLOAT_10_22_H

