#ifndef C_FLOAT_43_21_H
#define C_FLOAT_43_21_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_43_21 43
#define EXPONENT_BITS_F_43_21 21
#define BITS_F_43_21 SIGNIFICAND_BITS_F_43_21 + EXPONENT_BITS_F_43_21

#define C_FLOAT_43_21_DEBUG true

typedef uint64_t f4321_t;

#define SIGNIFICAND_MASK_F_43_21 ((1ULL << SIGNIFICAND_BITS_F_43_21) - 1)
#define SIGNIFICAND_2_MASK_F_43_21 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_43_21) - 1)
#define EXPONENT_MASK_F_43_21 (((1ULL << EXPONENT_BITS_F_43_21) - 1) << SIGNIFICAND_BITS_F_43_21)
#define SIGNIFICAND_SIGN_MASK_F_43_21 (1ULL << (SIGNIFICAND_BITS_F_43_21 - 1))
#define EXPONENT_SIGN_MASK_F_43_21 (1ULL << (EXPONENT_BITS_F_43_21 - 1))
#define BITS_SIGN_MASK_F_43_21 (1ULL << (BITS_F_43_21 - 1))

// construct float 4321
f4321_t new_f4321(uint64_t exp, uint64_t sig);
// exponent part of float 4321
uint64_t exp_f4321(f4321_t a);
// significand part of float 4321
uint64_t sig_f4321(f4321_t a);
// add float 4321
f4321_t add_f4321(f4321_t a, f4321_t b);
// subtract float 4321
f4321_t sub_f4321(f4321_t a, f4321_t b);
// negate float 4321
f4321_t neg_f4321(f4321_t a);
// multiply float 4321
f4321_t mul_f4321(f4321_t a, f4321_t b);
// divide float 4321
f4321_t div_f4321(f4321_t a, f4321_t b);
// equals float 4321
bool equ_f4321(f4321_t a, f4321_t b);
// compare float 4321
int com_f4321(f4321_t a, f4321_t b);

#endif // C_FLOAT_43_21_H

