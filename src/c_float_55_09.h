#ifndef C_FLOAT_55_09_H
#define C_FLOAT_55_09_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_55_09 55
#define EXPONENT_BITS_F_55_09 9
#define BITS_F_55_09 SIGNIFICAND_BITS_F_55_09 + EXPONENT_BITS_F_55_09

#define C_FLOAT_55_09_DEBUG true

typedef uint64_t f5509_t;

#define SIGNIFICAND_MASK_F_55_09 ((1ULL << SIGNIFICAND_BITS_F_55_09) - 1)
#define SIGNIFICAND_2_MASK_F_55_09 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_55_09) - 1)
#define EXPONENT_MASK_F_55_09 (((1ULL << EXPONENT_BITS_F_55_09) - 1) << SIGNIFICAND_BITS_F_55_09)
#define SIGNIFICAND_SIGN_MASK_F_55_09 (1ULL << (SIGNIFICAND_BITS_F_55_09 - 1))
#define EXPONENT_SIGN_MASK_F_55_09 (1ULL << (EXPONENT_BITS_F_55_09 - 1))
#define BITS_SIGN_MASK_F_55_09 (1ULL << (BITS_F_55_09 - 1))

// construct float 5509
f5509_t new_f5509(uint64_t exp, uint64_t sig);
// exponent part of float 5509
uint64_t exp_f5509(f5509_t a);
// significand part of float 5509
uint64_t sig_f5509(f5509_t a);
// add float 5509
f5509_t add_f5509(f5509_t a, f5509_t b);
// subtract float 5509
f5509_t sub_f5509(f5509_t a, f5509_t b);
// negate float 5509
f5509_t neg_f5509(f5509_t a);
// multiply float 5509
f5509_t mul_f5509(f5509_t a, f5509_t b);
// divide float 5509
f5509_t div_f5509(f5509_t a, f5509_t b);
// equals float 5509
bool equ_f5509(f5509_t a, f5509_t b);
// compare float 5509
int com_f5509(f5509_t a, f5509_t b);

#endif // C_FLOAT_55_09_H

