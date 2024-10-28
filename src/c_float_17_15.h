#ifndef C_FLOAT_17_15_H
#define C_FLOAT_17_15_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_17_15 17
#define EXPONENT_BITS_F_17_15 06
#define BITS_F_17_15 SIGNIFICAND_BITS_F_17_15 + EXPONENT_BITS_F_17_15

#define C_FLOAT_17_15_DEBUG true

typedef uint32_t f1715_t;

#define SIGNIFICAND_MASK_F_17_15 ((1UL << SIGNIFICAND_BITS_F_17_15) - 1)
#define SIGNIFICAND_2_MASK_F_17_15 ((1ULL << 2 * SIGNIFICAND_BITS_F_17_15) - 1)
#define EXPONENT_MASK_F_17_15 (((1UL << EXPONENT_BITS_F_17_15) - 1) << SIGNIFICAND_BITS_F_17_15)
#define SIGNIFICAND_SIGN_MASK_F_17_15 (1UL << (SIGNIFICAND_BITS_F_17_15 - 1))
#define EXPONENT_SIGN_MASK_F_17_15 (1UL << (EXPONENT_BITS_F_17_15 - 1))
#define BITS_SIGN_MASK_F_17_15 (1UL << (BITS_F_17_15 - 1))

// construct float 26 06
f1715_t new_f1715(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f1715(f1715_t a);
// significand part of float 26 06
uint32_t sig_f1715(f1715_t a);
// add float 26 06
f1715_t add_f1715(f1715_t a, f1715_t b);
// subtract float 26 06
f1715_t sub_f1715(f1715_t a, f1715_t b);
// negate float 26 06
f1715_t neg_f1715(f1715_t a);
// multiply float 26 06
f1715_t mul_f1715(f1715_t a, f1715_t b);
// divide float 26 06
f1715_t div_f1715(f1715_t a, f1715_t b);
// equals float 26 06
bool equ_f1715(f1715_t a, f1715_t b);
// compare float 26 06
int com_f1715(f1715_t a, f1715_t b);

#endif // C_FLOAT_17_15_H

