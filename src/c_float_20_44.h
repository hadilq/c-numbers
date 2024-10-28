#ifndef C_FLOAT_20_44_H
#define C_FLOAT_20_44_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_20_44 20
#define EXPONENT_BITS_F_20_44 44
#define BITS_F_20_44 SIGNIFICAND_BITS_F_20_44 + EXPONENT_BITS_F_20_44

#define C_FLOAT_20_44_DEBUG true

typedef uint64_t f2044_t;

#define SIGNIFICAND_MASK_F_20_44 ((1ULL << SIGNIFICAND_BITS_F_20_44) - 1)
#define SIGNIFICAND_2_MASK_F_20_44 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_20_44) - 1)
#define EXPONENT_MASK_F_20_44 (((1ULL << EXPONENT_BITS_F_20_44) - 1) << SIGNIFICAND_BITS_F_20_44)
#define SIGNIFICAND_SIGN_MASK_F_20_44 (1ULL << (SIGNIFICAND_BITS_F_20_44 - 1))
#define EXPONENT_SIGN_MASK_F_20_44 (1ULL << (EXPONENT_BITS_F_20_44 - 1))
#define BITS_SIGN_MASK_F_20_44 (1ULL << (BITS_F_20_44 - 1))

// construct float 2044
f2044_t new_f2044(uint64_t exp, uint64_t sig);
// exponent part of float 2044
uint64_t exp_f2044(f2044_t a);
// significand part of float 2044
uint64_t sig_f2044(f2044_t a);
// add float 2044
f2044_t add_f2044(f2044_t a, f2044_t b);
// subtract float 2044
f2044_t sub_f2044(f2044_t a, f2044_t b);
// negate float 2044
f2044_t neg_f2044(f2044_t a);
// multiply float 2044
f2044_t mul_f2044(f2044_t a, f2044_t b);
// divide float 2044
f2044_t div_f2044(f2044_t a, f2044_t b);
// equals float 2044
bool equ_f2044(f2044_t a, f2044_t b);
// compare float 2044
int com_f2044(f2044_t a, f2044_t b);

#endif // C_FLOAT_20_44_H
