#ifndef C_FLOAT_52_12_H
#define C_FLOAT_52_12_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_52_12 52
#define EXPONENT_BITS_F_52_12 12
#define BITS_F_52_12 SIGNIFICAND_BITS_F_52_12 + EXPONENT_BITS_F_52_12

#define C_FLOAT_52_12_DEBUG true

typedef uint64_t f5212_t;

#define SIGNIFICAND_MASK_F_52_12 ((1ULL << SIGNIFICAND_BITS_F_52_12) - 1)
#define SIGNIFICAND_2_MASK_F_52_12 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_52_12) - 1)
#define EXPONENT_MASK_F_52_12 (((1ULL << EXPONENT_BITS_F_52_12) - 1) << SIGNIFICAND_BITS_F_52_12)
#define SIGNIFICAND_SIGN_MASK_F_52_12 (1ULL << (SIGNIFICAND_BITS_F_52_12 - 1))
#define EXPONENT_SIGN_MASK_F_52_12 (1ULL << (EXPONENT_BITS_F_52_12 - 1))
#define BITS_SIGN_MASK_F_52_12 (1ULL << (BITS_F_52_12 - 1))

// construct float 5212
f5212_t new_f5212(uint64_t exp, uint64_t sig);
// exponent part of float 5212
uint64_t exp_f5212(f5212_t a);
// significand part of float 5212
uint64_t sig_f5212(f5212_t a);
// add float 5212
f5212_t add_f5212(f5212_t a, f5212_t b);
// subtract float 5212
f5212_t sub_f5212(f5212_t a, f5212_t b);
// negate float 5212
f5212_t neg_f5212(f5212_t a);
// multiply float 5212
f5212_t mul_f5212(f5212_t a, f5212_t b);
// divide float 5212
f5212_t div_f5212(f5212_t a, f5212_t b);
// equals float 5212
bool equ_f5212(f5212_t a, f5212_t b);
// compare float 5212
int com_f5212(f5212_t a, f5212_t b);

#endif // C_FLOAT_52_12_H

