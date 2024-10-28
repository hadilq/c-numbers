#ifndef C_FLOAT_15_17_H
#define C_FLOAT_15_17_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_15_17 15
#define EXPONENT_BITS_F_15_17 06
#define BITS_F_15_17 SIGNIFICAND_BITS_F_15_17 + EXPONENT_BITS_F_15_17

#define C_FLOAT_15_17_DEBUG true

typedef uint32_t f1517_t;

#define SIGNIFICAND_MASK_F_15_17 ((1UL << SIGNIFICAND_BITS_F_15_17) - 1)
#define SIGNIFICAND_2_MASK_F_15_17 ((1ULL << 2 * SIGNIFICAND_BITS_F_15_17) - 1)
#define EXPONENT_MASK_F_15_17 (((1UL << EXPONENT_BITS_F_15_17) - 1) << SIGNIFICAND_BITS_F_15_17)
#define SIGNIFICAND_SIGN_MASK_F_15_17 (1UL << (SIGNIFICAND_BITS_F_15_17 - 1))
#define EXPONENT_SIGN_MASK_F_15_17 (1UL << (EXPONENT_BITS_F_15_17 - 1))
#define BITS_SIGN_MASK_F_15_17 (1UL << (BITS_F_15_17 - 1))

// construct float 26 06
f1517_t new_f1517(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f1517(f1517_t a);
// significand part of float 26 06
uint32_t sig_f1517(f1517_t a);
// add float 26 06
f1517_t add_f1517(f1517_t a, f1517_t b);
// subtract float 26 06
f1517_t sub_f1517(f1517_t a, f1517_t b);
// negate float 26 06
f1517_t neg_f1517(f1517_t a);
// multiply float 26 06
f1517_t mul_f1517(f1517_t a, f1517_t b);
// divide float 26 06
f1517_t div_f1517(f1517_t a, f1517_t b);
// equals float 26 06
bool equ_f1517(f1517_t a, f1517_t b);
// compare float 26 06
int com_f1517(f1517_t a, f1517_t b);

#endif // C_FLOAT_15_17_H

