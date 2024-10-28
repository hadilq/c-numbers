#ifndef C_FLOAT_21_43_H
#define C_FLOAT_21_43_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_21_43 21
#define EXPONENT_BITS_F_21_43 43
#define BITS_F_21_43 SIGNIFICAND_BITS_F_21_43 + EXPONENT_BITS_F_21_43

#define C_FLOAT_21_43_DEBUG true

typedef uint64_t f2143_t;

#define SIGNIFICAND_MASK_F_21_43 ((1ULL << SIGNIFICAND_BITS_F_21_43) - 1)
#define SIGNIFICAND_2_MASK_F_21_43 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_21_43) - 1)
#define EXPONENT_MASK_F_21_43 (((1ULL << EXPONENT_BITS_F_21_43) - 1) << SIGNIFICAND_BITS_F_21_43)
#define SIGNIFICAND_SIGN_MASK_F_21_43 (1ULL << (SIGNIFICAND_BITS_F_21_43 - 1))
#define EXPONENT_SIGN_MASK_F_21_43 (1ULL << (EXPONENT_BITS_F_21_43 - 1))
#define BITS_SIGN_MASK_F_21_43 (1ULL << (BITS_F_21_43 - 1))

// construct float 2143
f2143_t new_f2143(uint64_t exp, uint64_t sig);
// exponent part of float 2143
uint64_t exp_f2143(f2143_t a);
// significand part of float 2143
uint64_t sig_f2143(f2143_t a);
// add float 2143
f2143_t add_f2143(f2143_t a, f2143_t b);
// subtract float 2143
f2143_t sub_f2143(f2143_t a, f2143_t b);
// negate float 2143
f2143_t neg_f2143(f2143_t a);
// multiply float 2143
f2143_t mul_f2143(f2143_t a, f2143_t b);
// divide float 2143
f2143_t div_f2143(f2143_t a, f2143_t b);
// equals float 2143
bool equ_f2143(f2143_t a, f2143_t b);
// compare float 2143
int com_f2143(f2143_t a, f2143_t b);

#endif // C_FLOAT_21_43_H

