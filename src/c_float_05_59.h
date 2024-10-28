#ifndef C_FLOAT_05_59_H
#define C_FLOAT_05_59_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_05_59 5
#define EXPONENT_BITS_F_05_59 59
#define BITS_F_05_59 SIGNIFICAND_BITS_F_05_59 + EXPONENT_BITS_F_05_59

#define C_FLOAT_05_59_DEBUG true

typedef uint64_t f0559_t;

#define SIGNIFICAND_MASK_F_05_59 ((1ULL << SIGNIFICAND_BITS_F_05_59) - 1)
#define SIGNIFICAND_2_MASK_F_05_59 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_05_59) - 1)
#define EXPONENT_MASK_F_05_59 (((1ULL << EXPONENT_BITS_F_05_59) - 1) << SIGNIFICAND_BITS_F_05_59)
#define SIGNIFICAND_SIGN_MASK_F_05_59 (1ULL << (SIGNIFICAND_BITS_F_05_59 - 1))
#define EXPONENT_SIGN_MASK_F_05_59 (1ULL << (EXPONENT_BITS_F_05_59 - 1))
#define BITS_SIGN_MASK_F_05_59 (1ULL << (BITS_F_05_59 - 1))

// construct float 0559
f0559_t new_f0559(uint64_t exp, uint64_t sig);
// exponent part of float 0559
uint64_t exp_f0559(f0559_t a);
// significand part of float 0559
uint64_t sig_f0559(f0559_t a);
// add float 0559
f0559_t add_f0559(f0559_t a, f0559_t b);
// subtract float 0559
f0559_t sub_f0559(f0559_t a, f0559_t b);
// negate float 0559
f0559_t neg_f0559(f0559_t a);
// multiply float 0559
f0559_t mul_f0559(f0559_t a, f0559_t b);
// divide float 0559
f0559_t div_f0559(f0559_t a, f0559_t b);
// equals float 0559
bool equ_f0559(f0559_t a, f0559_t b);
// compare float 0559
int com_f0559(f0559_t a, f0559_t b);

#endif // C_FLOAT_05_59_H

