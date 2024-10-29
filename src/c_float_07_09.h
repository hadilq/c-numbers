#ifndef C_FLOAT_07_09_H
#define C_FLOAT_07_09_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_07_09 7
#define EXPONENT_BITS_F_07_09 05
#define BITS_F_07_09 SIGNIFICAND_BITS_F_07_09 + EXPONENT_BITS_F_07_09

#define C_FLOAT_07_09_DEBUG true

typedef uint16_t f0709_t;

#define SIGNIFICAND_MASK_F_07_09 ((1U << SIGNIFICAND_BITS_F_07_09) - 1)
#define SIGNIFICAND_2_MASK_F_07_09 ((1UL << 2 * SIGNIFICAND_BITS_F_07_09) - 1)
#define EXPONENT_MASK_F_07_09 (((1U << EXPONENT_BITS_F_07_09) - 1) << SIGNIFICAND_BITS_F_07_09)
#define SIGNIFICAND_SIGN_MASK_F_07_09 (1U << (SIGNIFICAND_BITS_F_07_09 - 1))
#define EXPONENT_SIGN_MASK_F_07_09 (1U << (EXPONENT_BITS_F_07_09 - 1))
#define BITS_SIGN_MASK_F_07_09 (1U << (BITS_F_07_09 - 1))

#define MAX_VALUE_F_07_09 (((1U << (EXPONENT_BITS_F_07_09 - 2)) - 1) << SIGNIFICAND_BITS_F_07_09) | ((1U << (SIGNIFICAND_BITS_F_07_09 - 2)) - 1)
#define MIN_VALUE_F_07_09 (((1U << (EXPONENT_BITS_F_07_09 - 2)) - 1) << SIGNIFICAND_BITS_F_07_09) | (SIGNIFICAND_SIGN_MASK_F_07_09)

// construct float 0709
f0709_t new_f0709(int16_t exp, int16_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float DDD32
f0709_t new_f0709_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 0709
int16_t exp_f0709(f0709_t a);
// significand part of float 0709
int16_t sig_f0709(f0709_t a);
// add float 0709
f0709_t add_f0709(f0709_t a, f0709_t b);
// subtract float 0709
f0709_t sub_f0709(f0709_t a, f0709_t b);
// negate float 0709
f0709_t neg_f0709(f0709_t a);
// multiply float 0709
f0709_t mul_f0709(f0709_t a, f0709_t b);
// divide float 0709
f0709_t div_f0709(f0709_t a, f0709_t b);
// equals float 0709
bool equ_f0709(f0709_t a, f0709_t b);
// compare float 0709
int com_f0709(f0709_t a, f0709_t b);

#endif // C_FLOAT_07_09_H

