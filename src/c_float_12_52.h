#ifndef C_FLOAT_12_52_H
#define C_FLOAT_12_52_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_12_52 12
#define EXPONENT_BITS_F_12_52 52
#define BITS_F_12_52 SIGNIFICAND_BITS_F_12_52 + EXPONENT_BITS_F_12_52

#define C_FLOAT_12_52_DEBUG true

typedef uint64_t f1252_t;

#define SIGNIFICAND_MASK_F_12_52 ((1ULL << SIGNIFICAND_BITS_F_12_52) - 1)
#define SIGNIFICAND_2_MASK_F_12_52 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_12_52) - 1)
#define EXPONENT_MASK_F_12_52 (((1ULL << EXPONENT_BITS_F_12_52) - 1) << SIGNIFICAND_BITS_F_12_52)
#define SIGNIFICAND_SIGN_MASK_F_12_52 (1ULL << (SIGNIFICAND_BITS_F_12_52 - 1))
#define EXPONENT_SIGN_MASK_F_12_52 (1ULL << (EXPONENT_BITS_F_12_52 - 1))
#define BITS_SIGN_MASK_F_12_52 (1ULL << (BITS_F_12_52 - 1))

// construct float 1252
f1252_t new_f1252(uint64_t exp, uint64_t sig);
// exponent part of float 1252
uint64_t exp_f1252(f1252_t a);
// significand part of float 1252
uint64_t sig_f1252(f1252_t a);
// add float 1252
f1252_t add_f1252(f1252_t a, f1252_t b);
// subtract float 1252
f1252_t sub_f1252(f1252_t a, f1252_t b);
// negate float 1252
f1252_t neg_f1252(f1252_t a);
// multiply float 1252
f1252_t mul_f1252(f1252_t a, f1252_t b);
// divide float 1252
f1252_t div_f1252(f1252_t a, f1252_t b);
// equals float 1252
bool equ_f1252(f1252_t a, f1252_t b);
// compare float 1252
int com_f1252(f1252_t a, f1252_t b);

#endif // C_FLOAT_12_52_H

