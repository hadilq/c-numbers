#ifndef C_FLOAT_03_29_H
#define C_FLOAT_03_29_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_03_29 3
#define EXPONENT_BITS_F_03_29 06
#define BITS_F_03_29 SIGNIFICAND_BITS_F_03_29 + EXPONENT_BITS_F_03_29

#define C_FLOAT_03_29_DEBUG true

typedef uint32_t f0329_t;

#define SIGNIFICAND_MASK_F_03_29 ((1UL << SIGNIFICAND_BITS_F_03_29) - 1)
#define SIGNIFICAND_2_MASK_F_03_29 ((1ULL << 2 * SIGNIFICAND_BITS_F_03_29) - 1)
#define EXPONENT_MASK_F_03_29 (((1UL << EXPONENT_BITS_F_03_29) - 1) << SIGNIFICAND_BITS_F_03_29)
#define SIGNIFICAND_SIGN_MASK_F_03_29 (1UL << (SIGNIFICAND_BITS_F_03_29 - 1))
#define EXPONENT_SIGN_MASK_F_03_29 (1UL << (EXPONENT_BITS_F_03_29 - 1))
#define BITS_SIGN_MASK_F_03_29 (1UL << (BITS_F_03_29 - 1))

// construct float 26 06
f0329_t new_f0329(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f0329(f0329_t a);
// significand part of float 26 06
uint32_t sig_f0329(f0329_t a);
// add float 26 06
f0329_t add_f0329(f0329_t a, f0329_t b);
// subtract float 26 06
f0329_t sub_f0329(f0329_t a, f0329_t b);
// negate float 26 06
f0329_t neg_f0329(f0329_t a);
// multiply float 26 06
f0329_t mul_f0329(f0329_t a, f0329_t b);
// divide float 26 06
f0329_t div_f0329(f0329_t a, f0329_t b);
// equals float 26 06
bool equ_f0329(f0329_t a, f0329_t b);
// compare float 26 06
int com_f0329(f0329_t a, f0329_t b);

#endif // C_FLOAT_03_29_H

