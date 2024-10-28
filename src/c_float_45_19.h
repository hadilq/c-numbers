#ifndef C_FLOAT_45_19_H
#define C_FLOAT_45_19_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_45_19 45
#define EXPONENT_BITS_F_45_19 19
#define BITS_F_45_19 SIGNIFICAND_BITS_F_45_19 + EXPONENT_BITS_F_45_19

#define C_FLOAT_45_19_DEBUG true

typedef uint64_t f4519_t;

#define SIGNIFICAND_MASK_F_45_19 ((1ULL << SIGNIFICAND_BITS_F_45_19) - 1)
#define SIGNIFICAND_2_MASK_F_45_19 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_45_19) - 1)
#define EXPONENT_MASK_F_45_19 (((1ULL << EXPONENT_BITS_F_45_19) - 1) << SIGNIFICAND_BITS_F_45_19)
#define SIGNIFICAND_SIGN_MASK_F_45_19 (1ULL << (SIGNIFICAND_BITS_F_45_19 - 1))
#define EXPONENT_SIGN_MASK_F_45_19 (1ULL << (EXPONENT_BITS_F_45_19 - 1))
#define BITS_SIGN_MASK_F_45_19 (1ULL << (BITS_F_45_19 - 1))

// construct float 4519
f4519_t new_f4519(uint64_t exp, uint64_t sig);
// exponent part of float 4519
uint64_t exp_f4519(f4519_t a);
// significand part of float 4519
uint64_t sig_f4519(f4519_t a);
// add float 4519
f4519_t add_f4519(f4519_t a, f4519_t b);
// subtract float 4519
f4519_t sub_f4519(f4519_t a, f4519_t b);
// negate float 4519
f4519_t neg_f4519(f4519_t a);
// multiply float 4519
f4519_t mul_f4519(f4519_t a, f4519_t b);
// divide float 4519
f4519_t div_f4519(f4519_t a, f4519_t b);
// equals float 4519
bool equ_f4519(f4519_t a, f4519_t b);
// compare float 4519
int com_f4519(f4519_t a, f4519_t b);

#endif // C_FLOAT_45_19_H
