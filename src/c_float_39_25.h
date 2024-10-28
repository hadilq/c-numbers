#ifndef C_FLOAT_39_25_H
#define C_FLOAT_39_25_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_39_25 39
#define EXPONENT_BITS_F_39_25 25
#define BITS_F_39_25 SIGNIFICAND_BITS_F_39_25 + EXPONENT_BITS_F_39_25

#define C_FLOAT_39_25_DEBUG true

typedef uint64_t f3925_t;

#define SIGNIFICAND_MASK_F_39_25 ((1ULL << SIGNIFICAND_BITS_F_39_25) - 1)
#define SIGNIFICAND_2_MASK_F_39_25 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_39_25) - 1)
#define EXPONENT_MASK_F_39_25 (((1ULL << EXPONENT_BITS_F_39_25) - 1) << SIGNIFICAND_BITS_F_39_25)
#define SIGNIFICAND_SIGN_MASK_F_39_25 (1ULL << (SIGNIFICAND_BITS_F_39_25 - 1))
#define EXPONENT_SIGN_MASK_F_39_25 (1ULL << (EXPONENT_BITS_F_39_25 - 1))
#define BITS_SIGN_MASK_F_39_25 (1ULL << (BITS_F_39_25 - 1))

// construct float 3925
f3925_t new_f3925(uint64_t exp, uint64_t sig);
// exponent part of float 3925
uint64_t exp_f3925(f3925_t a);
// significand part of float 3925
uint64_t sig_f3925(f3925_t a);
// add float 3925
f3925_t add_f3925(f3925_t a, f3925_t b);
// subtract float 3925
f3925_t sub_f3925(f3925_t a, f3925_t b);
// negate float 3925
f3925_t neg_f3925(f3925_t a);
// multiply float 3925
f3925_t mul_f3925(f3925_t a, f3925_t b);
// divide float 3925
f3925_t div_f3925(f3925_t a, f3925_t b);
// equals float 3925
bool equ_f3925(f3925_t a, f3925_t b);
// compare float 3925
int com_f3925(f3925_t a, f3925_t b);

#endif // C_FLOAT_39_25_H
