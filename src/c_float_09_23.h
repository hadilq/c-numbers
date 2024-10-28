#ifndef C_FLOAT_09_23_H
#define C_FLOAT_09_23_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_09_23 9
#define EXPONENT_BITS_F_09_23 06
#define BITS_F_09_23 SIGNIFICAND_BITS_F_09_23 + EXPONENT_BITS_F_09_23

#define C_FLOAT_09_23_DEBUG true

typedef uint32_t f0923_t;

#define SIGNIFICAND_MASK_F_09_23 ((1UL << SIGNIFICAND_BITS_F_09_23) - 1)
#define SIGNIFICAND_2_MASK_F_09_23 ((1ULL << 2 * SIGNIFICAND_BITS_F_09_23) - 1)
#define EXPONENT_MASK_F_09_23 (((1UL << EXPONENT_BITS_F_09_23) - 1) << SIGNIFICAND_BITS_F_09_23)
#define SIGNIFICAND_SIGN_MASK_F_09_23 (1UL << (SIGNIFICAND_BITS_F_09_23 - 1))
#define EXPONENT_SIGN_MASK_F_09_23 (1UL << (EXPONENT_BITS_F_09_23 - 1))
#define BITS_SIGN_MASK_F_09_23 (1UL << (BITS_F_09_23 - 1))

// construct float 26 06
f0923_t new_f0923(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f0923(f0923_t a);
// significand part of float 26 06
uint32_t sig_f0923(f0923_t a);
// add float 26 06
f0923_t add_f0923(f0923_t a, f0923_t b);
// subtract float 26 06
f0923_t sub_f0923(f0923_t a, f0923_t b);
// negate float 26 06
f0923_t neg_f0923(f0923_t a);
// multiply float 26 06
f0923_t mul_f0923(f0923_t a, f0923_t b);
// divide float 26 06
f0923_t div_f0923(f0923_t a, f0923_t b);
// equals float 26 06
bool equ_f0923(f0923_t a, f0923_t b);
// compare float 26 06
int com_f0923(f0923_t a, f0923_t b);

#endif // C_FLOAT_09_23_H

