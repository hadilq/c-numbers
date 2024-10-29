#ifndef C_FLOAT_09_07_H
#define C_FLOAT_09_07_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_09_07 9
#define EXPONENT_BITS_F_09_07 05
#define BITS_F_09_07 SIGNIFICAND_BITS_F_09_07 + EXPONENT_BITS_F_09_07

#define C_FLOAT_09_07_DEBUG true

typedef uint16_t f0907_t;

#define SIGNIFICAND_MASK_F_09_07 ((1U << SIGNIFICAND_BITS_F_09_07) - 1)
#define SIGNIFICAND_2_MASK_F_09_07 ((1UL << 2 * SIGNIFICAND_BITS_F_09_07) - 1)
#define EXPONENT_MASK_F_09_07 (((1U << EXPONENT_BITS_F_09_07) - 1) << SIGNIFICAND_BITS_F_09_07)
#define SIGNIFICAND_SIGN_MASK_F_09_07 (1U << (SIGNIFICAND_BITS_F_09_07 - 1))
#define EXPONENT_SIGN_MASK_F_09_07 (1U << (EXPONENT_BITS_F_09_07 - 1))
#define BITS_SIGN_MASK_F_09_07 (1U << (BITS_F_09_07 - 1))

#define MAX_VALUE_F_09_07 (((1U << (EXPONENT_BITS_F_09_07 - 2)) - 1) << SIGNIFICAND_BITS_F_09_07) | ((1U << (SIGNIFICAND_BITS_F_09_07 - 2)) - 1)
#define MIN_VALUE_F_09_07 (((1U << (EXPONENT_BITS_F_09_07 - 2)) - 1) << SIGNIFICAND_BITS_F_09_07) | (SIGNIFICAND_SIGN_MASK_F_09_07)

// construct float 0907
f0907_t new_f0907(int16_t exp, int16_t sig);
// construct float DDD32
f0907_t new_f0907_from_float16(_Float16 f);
// exponent part of float 0907
int16_t exp_f0907(f0907_t a);
// significand part of float 0907
int16_t sig_f0907(f0907_t a);
// add float 0907
f0907_t add_f0907(f0907_t a, f0907_t b);
// subtract float 0907
f0907_t sub_f0907(f0907_t a, f0907_t b);
// negate float 0907
f0907_t neg_f0907(f0907_t a);
// multiply float 0907
f0907_t mul_f0907(f0907_t a, f0907_t b);
// divide float 0907
f0907_t div_f0907(f0907_t a, f0907_t b);
// equals float 0907
bool equ_f0907(f0907_t a, f0907_t b);
// compare float 0907
int com_f0907(f0907_t a, f0907_t b);

#endif // C_FLOAT_09_07_H

