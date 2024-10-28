#ifndef C_FLOAT_25_39_H
#define C_FLOAT_25_39_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_25_39 25
#define EXPONENT_BITS_F_25_39 39
#define BITS_F_25_39 SIGNIFICAND_BITS_F_25_39 + EXPONENT_BITS_F_25_39

#define C_FLOAT_25_39_DEBUG true

typedef uint64_t f2539_t;

#define SIGNIFICAND_MASK_F_25_39 ((1ULL << SIGNIFICAND_BITS_F_25_39) - 1)
#define SIGNIFICAND_2_MASK_F_25_39 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_25_39) - 1)
#define EXPONENT_MASK_F_25_39 (((1ULL << EXPONENT_BITS_F_25_39) - 1) << SIGNIFICAND_BITS_F_25_39)
#define SIGNIFICAND_SIGN_MASK_F_25_39 (1ULL << (SIGNIFICAND_BITS_F_25_39 - 1))
#define EXPONENT_SIGN_MASK_F_25_39 (1ULL << (EXPONENT_BITS_F_25_39 - 1))
#define BITS_SIGN_MASK_F_25_39 (1ULL << (BITS_F_25_39 - 1))

// construct float 2539
f2539_t new_f2539(uint64_t exp, uint64_t sig);
// exponent part of float 2539
uint64_t exp_f2539(f2539_t a);
// significand part of float 2539
uint64_t sig_f2539(f2539_t a);
// add float 2539
f2539_t add_f2539(f2539_t a, f2539_t b);
// subtract float 2539
f2539_t sub_f2539(f2539_t a, f2539_t b);
// negate float 2539
f2539_t neg_f2539(f2539_t a);
// multiply float 2539
f2539_t mul_f2539(f2539_t a, f2539_t b);
// divide float 2539
f2539_t div_f2539(f2539_t a, f2539_t b);
// equals float 2539
bool equ_f2539(f2539_t a, f2539_t b);
// compare float 2539
int com_f2539(f2539_t a, f2539_t b);

#endif // C_FLOAT_25_39_H

