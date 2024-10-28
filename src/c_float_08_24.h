#ifndef C_FLOAT_08_24_H
#define C_FLOAT_08_24_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_08_24 8
#define EXPONENT_BITS_F_08_24 06
#define BITS_F_08_24 SIGNIFICAND_BITS_F_08_24 + EXPONENT_BITS_F_08_24

#define C_FLOAT_08_24_DEBUG true

typedef uint32_t f0824_t;

#define SIGNIFICAND_MASK_F_08_24 ((1UL << SIGNIFICAND_BITS_F_08_24) - 1)
#define SIGNIFICAND_2_MASK_F_08_24 ((1ULL << 2 * SIGNIFICAND_BITS_F_08_24) - 1)
#define EXPONENT_MASK_F_08_24 (((1UL << EXPONENT_BITS_F_08_24) - 1) << SIGNIFICAND_BITS_F_08_24)
#define SIGNIFICAND_SIGN_MASK_F_08_24 (1UL << (SIGNIFICAND_BITS_F_08_24 - 1))
#define EXPONENT_SIGN_MASK_F_08_24 (1UL << (EXPONENT_BITS_F_08_24 - 1))
#define BITS_SIGN_MASK_F_08_24 (1UL << (BITS_F_08_24 - 1))

// construct float 26 06
f0824_t new_f0824(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f0824(f0824_t a);
// significand part of float 26 06
uint32_t sig_f0824(f0824_t a);
// add float 26 06
f0824_t add_f0824(f0824_t a, f0824_t b);
// subtract float 26 06
f0824_t sub_f0824(f0824_t a, f0824_t b);
// negate float 26 06
f0824_t neg_f0824(f0824_t a);
// multiply float 26 06
f0824_t mul_f0824(f0824_t a, f0824_t b);
// divide float 26 06
f0824_t div_f0824(f0824_t a, f0824_t b);
// equals float 26 06
bool equ_f0824(f0824_t a, f0824_t b);
// compare float 26 06
int com_f0824(f0824_t a, f0824_t b);

#endif // C_FLOAT_08_24_H
