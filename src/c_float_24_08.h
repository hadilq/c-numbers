#ifndef C_FLOAT_24_08_H
#define C_FLOAT_24_08_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_24_08 24
#define EXPONENT_BITS_F_24_08 06
#define BITS_F_24_08 SIGNIFICAND_BITS_F_24_08 + EXPONENT_BITS_F_24_08

#define C_FLOAT_24_08_DEBUG true

typedef uint32_t f2408_t;

#define SIGNIFICAND_MASK_F_24_08 ((1UL << SIGNIFICAND_BITS_F_24_08) - 1)
#define SIGNIFICAND_2_MASK_F_24_08 ((1ULL << 2 * SIGNIFICAND_BITS_F_24_08) - 1)
#define EXPONENT_MASK_F_24_08 (((1UL << EXPONENT_BITS_F_24_08) - 1) << SIGNIFICAND_BITS_F_24_08)
#define SIGNIFICAND_SIGN_MASK_F_24_08 (1UL << (SIGNIFICAND_BITS_F_24_08 - 1))
#define EXPONENT_SIGN_MASK_F_24_08 (1UL << (EXPONENT_BITS_F_24_08 - 1))
#define BITS_SIGN_MASK_F_24_08 (1UL << (BITS_F_24_08 - 1))

// construct float 26 06
f2408_t new_f2408(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f2408(f2408_t a);
// significand part of float 26 06
uint32_t sig_f2408(f2408_t a);
// add float 26 06
f2408_t add_f2408(f2408_t a, f2408_t b);
// subtract float 26 06
f2408_t sub_f2408(f2408_t a, f2408_t b);
// negate float 26 06
f2408_t neg_f2408(f2408_t a);
// multiply float 26 06
f2408_t mul_f2408(f2408_t a, f2408_t b);
// divide float 26 06
f2408_t div_f2408(f2408_t a, f2408_t b);
// equals float 26 06
bool equ_f2408(f2408_t a, f2408_t b);
// compare float 26 06
int com_f2408(f2408_t a, f2408_t b);

#endif // C_FLOAT_24_08_H

