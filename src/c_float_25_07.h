#ifndef C_FLOAT_25_07_H
#define C_FLOAT_25_07_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_25_07 25
#define EXPONENT_BITS_F_25_07 06
#define BITS_F_25_07 SIGNIFICAND_BITS_F_25_07 + EXPONENT_BITS_F_25_07

#define C_FLOAT_25_07_DEBUG true

typedef uint32_t f2507_t;

#define SIGNIFICAND_MASK_F_25_07 ((1UL << SIGNIFICAND_BITS_F_25_07) - 1)
#define SIGNIFICAND_2_MASK_F_25_07 ((1ULL << 2 * SIGNIFICAND_BITS_F_25_07) - 1)
#define EXPONENT_MASK_F_25_07 (((1UL << EXPONENT_BITS_F_25_07) - 1) << SIGNIFICAND_BITS_F_25_07)
#define SIGNIFICAND_SIGN_MASK_F_25_07 (1UL << (SIGNIFICAND_BITS_F_25_07 - 1))
#define EXPONENT_SIGN_MASK_F_25_07 (1UL << (EXPONENT_BITS_F_25_07 - 1))
#define BITS_SIGN_MASK_F_25_07 (1UL << (BITS_F_25_07 - 1))

// construct float 26 06
f2507_t new_f2507(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f2507(f2507_t a);
// significand part of float 26 06
uint32_t sig_f2507(f2507_t a);
// add float 26 06
f2507_t add_f2507(f2507_t a, f2507_t b);
// subtract float 26 06
f2507_t sub_f2507(f2507_t a, f2507_t b);
// negate float 26 06
f2507_t neg_f2507(f2507_t a);
// multiply float 26 06
f2507_t mul_f2507(f2507_t a, f2507_t b);
// divide float 26 06
f2507_t div_f2507(f2507_t a, f2507_t b);
// equals float 26 06
bool equ_f2507(f2507_t a, f2507_t b);
// compare float 26 06
int com_f2507(f2507_t a, f2507_t b);

#endif // C_FLOAT_25_07_H

