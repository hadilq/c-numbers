#ifndef C_FLOAT_26_06_H
#define C_FLOAT_26_06_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_26_06 26
#define EXPONENT_BITS_F_26_06 06
#define BITS_F_26_06 SIGNIFICAND_BITS_F_26_06 + EXPONENT_BITS_F_26_06

#define C_FLOAT_26_06_DEBUG true

typedef uint32_t f2606_t;

#define SIGNIFICAND_MASK_F_26_06 ((1U << SIGNIFICAND_BITS_F_26_06) - 1)
#define EXPONENT_MASK_F_26_06 (((1U << EXPONENT_BITS_F_26_06) - 1) << SIGNIFICAND_BITS_F_26_06)

// construct float 57 07
f2606_t new_f2606(uint32_t exp, uint32_t sig);
// exponent part of float 57 07
uint32_t exp_f2606(f2606_t a);
// significand part of float 57 07
uint32_t sig_f2606(f2606_t a);
// add float 57 07
f2606_t add_f2606(f2606_t a, f2606_t b);
// subtract float 57 07
f2606_t sub_f2606(f2606_t a, f2606_t b);
// negate float 57 07
f2606_t neg_f2606(f2606_t a);
// multiply float 57 07
f2606_t mul_f2606(f2606_t a, f2606_t b);
// divide float 57 07
f2606_t div_f2606(f2606_t a, f2606_t b);
// equals float 57 07
bool equ_f2606(f2606_t a, f2606_t b);
// compare float 57 07
int com_f2606(f2606_t a, f2606_t b);

#endif // C_FLOAT_26_06_H

