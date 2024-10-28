#ifndef C_FLOAT_16_48_H
#define C_FLOAT_16_48_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_16_48 16
#define EXPONENT_BITS_F_16_48 48
#define BITS_F_16_48 SIGNIFICAND_BITS_F_16_48 + EXPONENT_BITS_F_16_48

#define C_FLOAT_16_48_DEBUG true

typedef uint64_t f1648_t;

#define SIGNIFICAND_MASK_F_16_48 ((1ULL << SIGNIFICAND_BITS_F_16_48) - 1)
#define SIGNIFICAND_2_MASK_F_16_48 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_16_48) - 1)
#define EXPONENT_MASK_F_16_48 (((1ULL << EXPONENT_BITS_F_16_48) - 1) << SIGNIFICAND_BITS_F_16_48)
#define SIGNIFICAND_SIGN_MASK_F_16_48 (1ULL << (SIGNIFICAND_BITS_F_16_48 - 1))
#define EXPONENT_SIGN_MASK_F_16_48 (1ULL << (EXPONENT_BITS_F_16_48 - 1))
#define BITS_SIGN_MASK_F_16_48 (1ULL << (BITS_F_16_48 - 1))

// construct float 1648
f1648_t new_f1648(uint64_t exp, uint64_t sig);
// exponent part of float 1648
uint64_t exp_f1648(f1648_t a);
// significand part of float 1648
uint64_t sig_f1648(f1648_t a);
// add float 1648
f1648_t add_f1648(f1648_t a, f1648_t b);
// subtract float 1648
f1648_t sub_f1648(f1648_t a, f1648_t b);
// negate float 1648
f1648_t neg_f1648(f1648_t a);
// multiply float 1648
f1648_t mul_f1648(f1648_t a, f1648_t b);
// divide float 1648
f1648_t div_f1648(f1648_t a, f1648_t b);
// equals float 1648
bool equ_f1648(f1648_t a, f1648_t b);
// compare float 1648
int com_f1648(f1648_t a, f1648_t b);

#endif // C_FLOAT_16_48_H

