#ifndef C_FLOAT_49_15_H
#define C_FLOAT_49_15_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_49_15 49
#define EXPONENT_BITS_F_49_15 15
#define BITS_F_49_15 SIGNIFICAND_BITS_F_49_15 + EXPONENT_BITS_F_49_15

#define C_FLOAT_49_15_DEBUG true

typedef uint64_t f4915_t;

#define SIGNIFICAND_MASK_F_49_15 ((1ULL << SIGNIFICAND_BITS_F_49_15) - 1)
#define SIGNIFICAND_2_MASK_F_49_15 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_49_15) - 1)
#define EXPONENT_MASK_F_49_15 (((1ULL << EXPONENT_BITS_F_49_15) - 1) << SIGNIFICAND_BITS_F_49_15)
#define SIGNIFICAND_SIGN_MASK_F_49_15 (1ULL << (SIGNIFICAND_BITS_F_49_15 - 1))
#define EXPONENT_SIGN_MASK_F_49_15 (1ULL << (EXPONENT_BITS_F_49_15 - 1))
#define BITS_SIGN_MASK_F_49_15 (1ULL << (BITS_F_49_15 - 1))

// construct float 4915
f4915_t new_f4915(uint64_t exp, uint64_t sig);
// exponent part of float 4915
uint64_t exp_f4915(f4915_t a);
// significand part of float 4915
uint64_t sig_f4915(f4915_t a);
// add float 4915
f4915_t add_f4915(f4915_t a, f4915_t b);
// subtract float 4915
f4915_t sub_f4915(f4915_t a, f4915_t b);
// negate float 4915
f4915_t neg_f4915(f4915_t a);
// multiply float 4915
f4915_t mul_f4915(f4915_t a, f4915_t b);
// divide float 4915
f4915_t div_f4915(f4915_t a, f4915_t b);
// equals float 4915
bool equ_f4915(f4915_t a, f4915_t b);
// compare float 4915
int com_f4915(f4915_t a, f4915_t b);

#endif // C_FLOAT_49_15_H
