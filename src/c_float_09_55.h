#ifndef C_FLOAT_09_55_H
#define C_FLOAT_09_55_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_09_55 9
#define EXPONENT_BITS_F_09_55 55
#define BITS_F_09_55 SIGNIFICAND_BITS_F_09_55 + EXPONENT_BITS_F_09_55

#define C_FLOAT_09_55_DEBUG true

typedef uint64_t f0955_t;

#define SIGNIFICAND_MASK_F_09_55 ((1ULL << SIGNIFICAND_BITS_F_09_55) - 1)
#define SIGNIFICAND_2_MASK_F_09_55 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_09_55) - 1)
#define EXPONENT_MASK_F_09_55 (((1ULL << EXPONENT_BITS_F_09_55) - 1) << SIGNIFICAND_BITS_F_09_55)
#define SIGNIFICAND_SIGN_MASK_F_09_55 (1ULL << (SIGNIFICAND_BITS_F_09_55 - 1))
#define EXPONENT_SIGN_MASK_F_09_55 (1ULL << (EXPONENT_BITS_F_09_55 - 1))
#define BITS_SIGN_MASK_F_09_55 (1ULL << (BITS_F_09_55 - 1))

// construct float 0955
f0955_t new_f0955(uint64_t exp, uint64_t sig);
// exponent part of float 0955
uint64_t exp_f0955(f0955_t a);
// significand part of float 0955
uint64_t sig_f0955(f0955_t a);
// add float 0955
f0955_t add_f0955(f0955_t a, f0955_t b);
// subtract float 0955
f0955_t sub_f0955(f0955_t a, f0955_t b);
// negate float 0955
f0955_t neg_f0955(f0955_t a);
// multiply float 0955
f0955_t mul_f0955(f0955_t a, f0955_t b);
// divide float 0955
f0955_t div_f0955(f0955_t a, f0955_t b);
// equals float 0955
bool equ_f0955(f0955_t a, f0955_t b);
// compare float 0955
int com_f0955(f0955_t a, f0955_t b);

#endif // C_FLOAT_09_55_H

