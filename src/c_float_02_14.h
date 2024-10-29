#ifndef C_FLOAT_02_14_H
#define C_FLOAT_02_14_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_02_14 2
#define EXPONENT_BITS_F_02_14 05
#define BITS_F_02_14 SIGNIFICAND_BITS_F_02_14 + EXPONENT_BITS_F_02_14

#define C_FLOAT_02_14_DEBUG true

typedef uint16_t f0214_t;

#define SIGNIFICAND_MASK_F_02_14 ((1U << SIGNIFICAND_BITS_F_02_14) - 1)
#define SIGNIFICAND_2_MASK_F_02_14 ((1UL << 2 * SIGNIFICAND_BITS_F_02_14) - 1)
#define EXPONENT_MASK_F_02_14 (((1U << EXPONENT_BITS_F_02_14) - 1) << SIGNIFICAND_BITS_F_02_14)
#define SIGNIFICAND_SIGN_MASK_F_02_14 (1U << (SIGNIFICAND_BITS_F_02_14 - 1))
#define EXPONENT_SIGN_MASK_F_02_14 (1U << (EXPONENT_BITS_F_02_14 - 1))
#define BITS_SIGN_MASK_F_02_14 (1U << (BITS_F_02_14 - 1))

#define MAX_VALUE_F_02_14 (((1U << (EXPONENT_BITS_F_02_14 - 2)) - 1) << SIGNIFICAND_BITS_F_02_14) | ((1U << (SIGNIFICAND_BITS_F_02_14 - 2)) - 1)
#define MIN_VALUE_F_02_14 (((1U << (EXPONENT_BITS_F_02_14 - 2)) - 1) << SIGNIFICAND_BITS_F_02_14) | (SIGNIFICAND_SIGN_MASK_F_02_14)

// construct float 0214
f0214_t new_f0214(int16_t exp, int16_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float DDD32
f0214_t new_f0214_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 0214
int16_t exp_f0214(f0214_t a);
// significand part of float 0214
int16_t sig_f0214(f0214_t a);
// add float 0214
f0214_t add_f0214(f0214_t a, f0214_t b);
// subtract float 0214
f0214_t sub_f0214(f0214_t a, f0214_t b);
// negate float 0214
f0214_t neg_f0214(f0214_t a);
// multiply float 0214
f0214_t mul_f0214(f0214_t a, f0214_t b);
// divide float 0214
f0214_t div_f0214(f0214_t a, f0214_t b);
// equals float 0214
bool equ_f0214(f0214_t a, f0214_t b);
// compare float 0214
int com_f0214(f0214_t a, f0214_t b);

#endif // C_FLOAT_02_14_H

