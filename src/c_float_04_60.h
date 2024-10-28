#ifndef C_FLOAT_04_60_H
#define C_FLOAT_04_60_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_04_60 4
#define EXPONENT_BITS_F_04_60 60
#define BITS_F_04_60 SIGNIFICAND_BITS_F_04_60 + EXPONENT_BITS_F_04_60

#define C_FLOAT_04_60_DEBUG true

typedef uint64_t f0460_t;

#define SIGNIFICAND_MASK_F_04_60 ((1ULL << SIGNIFICAND_BITS_F_04_60) - 1)
#define SIGNIFICAND_2_MASK_F_04_60 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_04_60) - 1)
#define EXPONENT_MASK_F_04_60 (((1ULL << EXPONENT_BITS_F_04_60) - 1) << SIGNIFICAND_BITS_F_04_60)
#define SIGNIFICAND_SIGN_MASK_F_04_60 (1ULL << (SIGNIFICAND_BITS_F_04_60 - 1))
#define EXPONENT_SIGN_MASK_F_04_60 (1ULL << (EXPONENT_BITS_F_04_60 - 1))
#define BITS_SIGN_MASK_F_04_60 (1ULL << (BITS_F_04_60 - 1))

// construct float 0460
f0460_t new_f0460(uint64_t exp, uint64_t sig);
// exponent part of float 0460
uint64_t exp_f0460(f0460_t a);
// significand part of float 0460
uint64_t sig_f0460(f0460_t a);
// add float 0460
f0460_t add_f0460(f0460_t a, f0460_t b);
// subtract float 0460
f0460_t sub_f0460(f0460_t a, f0460_t b);
// negate float 0460
f0460_t neg_f0460(f0460_t a);
// multiply float 0460
f0460_t mul_f0460(f0460_t a, f0460_t b);
// divide float 0460
f0460_t div_f0460(f0460_t a, f0460_t b);
// equals float 0460
bool equ_f0460(f0460_t a, f0460_t b);
// compare float 0460
int com_f0460(f0460_t a, f0460_t b);

#endif // C_FLOAT_04_60_H

