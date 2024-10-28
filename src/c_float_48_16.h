#ifndef C_FLOAT_48_16_H
#define C_FLOAT_48_16_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_48_16 48
#define EXPONENT_BITS_F_48_16 16
#define BITS_F_48_16 SIGNIFICAND_BITS_F_48_16 + EXPONENT_BITS_F_48_16

#define C_FLOAT_48_16_DEBUG true

typedef uint64_t f4816_t;

#define SIGNIFICAND_MASK_F_48_16 ((1ULL << SIGNIFICAND_BITS_F_48_16) - 1)
#define SIGNIFICAND_2_MASK_F_48_16 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_48_16) - 1)
#define EXPONENT_MASK_F_48_16 (((1ULL << EXPONENT_BITS_F_48_16) - 1) << SIGNIFICAND_BITS_F_48_16)
#define SIGNIFICAND_SIGN_MASK_F_48_16 (1ULL << (SIGNIFICAND_BITS_F_48_16 - 1))
#define EXPONENT_SIGN_MASK_F_48_16 (1ULL << (EXPONENT_BITS_F_48_16 - 1))
#define BITS_SIGN_MASK_F_48_16 (1ULL << (BITS_F_48_16 - 1))

// construct float 4816
f4816_t new_f4816(uint64_t exp, uint64_t sig);
// exponent part of float 4816
uint64_t exp_f4816(f4816_t a);
// significand part of float 4816
uint64_t sig_f4816(f4816_t a);
// add float 4816
f4816_t add_f4816(f4816_t a, f4816_t b);
// subtract float 4816
f4816_t sub_f4816(f4816_t a, f4816_t b);
// negate float 4816
f4816_t neg_f4816(f4816_t a);
// multiply float 4816
f4816_t mul_f4816(f4816_t a, f4816_t b);
// divide float 4816
f4816_t div_f4816(f4816_t a, f4816_t b);
// equals float 4816
bool equ_f4816(f4816_t a, f4816_t b);
// compare float 4816
int com_f4816(f4816_t a, f4816_t b);

#endif // C_FLOAT_48_16_H
