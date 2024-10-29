#ifndef C_FLOAT_06_10_H
#define C_FLOAT_06_10_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_06_10 6
#define EXPONENT_BITS_F_06_10 05
#define BITS_F_06_10 SIGNIFICAND_BITS_F_06_10 + EXPONENT_BITS_F_06_10

#define C_FLOAT_06_10_DEBUG true

typedef uint16_t f0610_t;

#define SIGNIFICAND_MASK_F_06_10 ((1U << SIGNIFICAND_BITS_F_06_10) - 1)
#define SIGNIFICAND_2_MASK_F_06_10 ((1UL << 2 * SIGNIFICAND_BITS_F_06_10) - 1)
#define EXPONENT_MASK_F_06_10 (((1U << EXPONENT_BITS_F_06_10) - 1) << SIGNIFICAND_BITS_F_06_10)
#define SIGNIFICAND_SIGN_MASK_F_06_10 (1U << (SIGNIFICAND_BITS_F_06_10 - 1))
#define EXPONENT_SIGN_MASK_F_06_10 (1U << (EXPONENT_BITS_F_06_10 - 1))
#define BITS_SIGN_MASK_F_06_10 (1U << (BITS_F_06_10 - 1))

#define MAX_VALUE_F_06_10 (((1U << (EXPONENT_BITS_F_06_10 - 2)) - 1) << SIGNIFICAND_BITS_F_06_10) | ((1U << (SIGNIFICAND_BITS_F_06_10 - 2)) - 1)
#define MIN_VALUE_F_06_10 (((1U << (EXPONENT_BITS_F_06_10 - 2)) - 1) << SIGNIFICAND_BITS_F_06_10) | (SIGNIFICAND_SIGN_MASK_F_06_10)

// construct float 0610
f0610_t new_f0610(int16_t exp, int16_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float DDD32
f0610_t new_f0610_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 0610
int16_t exp_f0610(f0610_t a);
// significand part of float 0610
int16_t sig_f0610(f0610_t a);
// add float 0610
f0610_t add_f0610(f0610_t a, f0610_t b);
// subtract float 0610
f0610_t sub_f0610(f0610_t a, f0610_t b);
// negate float 0610
f0610_t neg_f0610(f0610_t a);
// multiply float 0610
f0610_t mul_f0610(f0610_t a, f0610_t b);
// divide float 0610
f0610_t div_f0610(f0610_t a, f0610_t b);
// equals float 0610
bool equ_f0610(f0610_t a, f0610_t b);
// compare float 0610
int com_f0610(f0610_t a, f0610_t b);

#endif // C_FLOAT_06_10_H

