#ifndef C_FLOAT_03_61_H
#define C_FLOAT_03_61_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_03_61 3
#define EXPONENT_BITS_F_03_61 61
#define BITS_F_03_61 SIGNIFICAND_BITS_F_03_61 + EXPONENT_BITS_F_03_61

#define C_FLOAT_03_61_DEBUG true

typedef uint64_t f0361_t;

#define SIGNIFICAND_MASK_F_03_61 ((1ULL << SIGNIFICAND_BITS_F_03_61) - 1)
#define SIGNIFICAND_2_MASK_F_03_61 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_03_61) - 1)
#define EXPONENT_MASK_F_03_61 (((1ULL << EXPONENT_BITS_F_03_61) - 1) << SIGNIFICAND_BITS_F_03_61)
#define SIGNIFICAND_SIGN_MASK_F_03_61 (1ULL << (SIGNIFICAND_BITS_F_03_61 - 1))
#define EXPONENT_SIGN_MASK_F_03_61 (1ULL << (EXPONENT_BITS_F_03_61 - 1))
#define BITS_SIGN_MASK_F_03_61 (1ULL << (BITS_F_03_61 - 1))

// construct float 0361
f0361_t new_f0361(uint64_t exp, uint64_t sig);
// exponent part of float 0361
uint64_t exp_f0361(f0361_t a);
// significand part of float 0361
uint64_t sig_f0361(f0361_t a);
// add float 0361
f0361_t add_f0361(f0361_t a, f0361_t b);
// subtract float 0361
f0361_t sub_f0361(f0361_t a, f0361_t b);
// negate float 0361
f0361_t neg_f0361(f0361_t a);
// multiply float 0361
f0361_t mul_f0361(f0361_t a, f0361_t b);
// divide float 0361
f0361_t div_f0361(f0361_t a, f0361_t b);
// equals float 0361
bool equ_f0361(f0361_t a, f0361_t b);
// compare float 0361
int com_f0361(f0361_t a, f0361_t b);

#endif // C_FLOAT_03_61_H

