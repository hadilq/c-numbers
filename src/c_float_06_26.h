#ifndef C_FLOAT_06_26_H
#define C_FLOAT_06_26_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_06_26 6
#define EXPONENT_BITS_F_06_26 06
#define BITS_F_06_26 SIGNIFICAND_BITS_F_06_26 + EXPONENT_BITS_F_06_26

#define C_FLOAT_06_26_DEBUG true

typedef uint32_t f0626_t;

#define SIGNIFICAND_MASK_F_06_26 ((1UL << SIGNIFICAND_BITS_F_06_26) - 1)
#define SIGNIFICAND_2_MASK_F_06_26 ((1ULL << 2 * SIGNIFICAND_BITS_F_06_26) - 1)
#define EXPONENT_MASK_F_06_26 (((1UL << EXPONENT_BITS_F_06_26) - 1) << SIGNIFICAND_BITS_F_06_26)
#define SIGNIFICAND_SIGN_MASK_F_06_26 (1UL << (SIGNIFICAND_BITS_F_06_26 - 1))
#define EXPONENT_SIGN_MASK_F_06_26 (1UL << (EXPONENT_BITS_F_06_26 - 1))
#define BITS_SIGN_MASK_F_06_26 (1UL << (BITS_F_06_26 - 1))

// construct float 26 06
f0626_t new_f0626(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f0626(f0626_t a);
// significand part of float 26 06
uint32_t sig_f0626(f0626_t a);
// add float 26 06
f0626_t add_f0626(f0626_t a, f0626_t b);
// subtract float 26 06
f0626_t sub_f0626(f0626_t a, f0626_t b);
// negate float 26 06
f0626_t neg_f0626(f0626_t a);
// multiply float 26 06
f0626_t mul_f0626(f0626_t a, f0626_t b);
// divide float 26 06
f0626_t div_f0626(f0626_t a, f0626_t b);
// equals float 26 06
bool equ_f0626(f0626_t a, f0626_t b);
// compare float 26 06
int com_f0626(f0626_t a, f0626_t b);

#endif // C_FLOAT_06_26_H

