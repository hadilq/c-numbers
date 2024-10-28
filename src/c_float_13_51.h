#ifndef C_FLOAT_13_51_H
#define C_FLOAT_13_51_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_13_51 13
#define EXPONENT_BITS_F_13_51 51
#define BITS_F_13_51 SIGNIFICAND_BITS_F_13_51 + EXPONENT_BITS_F_13_51

#define C_FLOAT_13_51_DEBUG true

typedef uint64_t f1351_t;

#define SIGNIFICAND_MASK_F_13_51 ((1ULL << SIGNIFICAND_BITS_F_13_51) - 1)
#define SIGNIFICAND_2_MASK_F_13_51 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_13_51) - 1)
#define EXPONENT_MASK_F_13_51 (((1ULL << EXPONENT_BITS_F_13_51) - 1) << SIGNIFICAND_BITS_F_13_51)
#define SIGNIFICAND_SIGN_MASK_F_13_51 (1ULL << (SIGNIFICAND_BITS_F_13_51 - 1))
#define EXPONENT_SIGN_MASK_F_13_51 (1ULL << (EXPONENT_BITS_F_13_51 - 1))
#define BITS_SIGN_MASK_F_13_51 (1ULL << (BITS_F_13_51 - 1))

// construct float 1351
f1351_t new_f1351(uint64_t exp, uint64_t sig);
// exponent part of float 1351
uint64_t exp_f1351(f1351_t a);
// significand part of float 1351
uint64_t sig_f1351(f1351_t a);
// add float 1351
f1351_t add_f1351(f1351_t a, f1351_t b);
// subtract float 1351
f1351_t sub_f1351(f1351_t a, f1351_t b);
// negate float 1351
f1351_t neg_f1351(f1351_t a);
// multiply float 1351
f1351_t mul_f1351(f1351_t a, f1351_t b);
// divide float 1351
f1351_t div_f1351(f1351_t a, f1351_t b);
// equals float 1351
bool equ_f1351(f1351_t a, f1351_t b);
// compare float 1351
int com_f1351(f1351_t a, f1351_t b);

#endif // C_FLOAT_13_51_H
