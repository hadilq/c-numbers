#ifndef C_FLOAT_04_12_H
#define C_FLOAT_04_12_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_04_12 4
#define EXPONENT_BITS_F_04_12 05
#define BITS_F_04_12 SIGNIFICAND_BITS_F_04_12 + EXPONENT_BITS_F_04_12

#define C_FLOAT_04_12_DEBUG true

typedef uint16_t f0412_t;

#define SIGNIFICAND_MASK_F_04_12 ((1U << SIGNIFICAND_BITS_F_04_12) - 1)
#define SIGNIFICAND_2_MASK_F_04_12 ((1UL << 2 * SIGNIFICAND_BITS_F_04_12) - 1)
#define EXPONENT_MASK_F_04_12 (((1U << EXPONENT_BITS_F_04_12) - 1) << SIGNIFICAND_BITS_F_04_12)
#define SIGNIFICAND_SIGN_MASK_F_04_12 (1U << (SIGNIFICAND_BITS_F_04_12 - 1))
#define EXPONENT_SIGN_MASK_F_04_12 (1U << (EXPONENT_BITS_F_04_12 - 1))
#define BITS_SIGN_MASK_F_04_12 (1U << (BITS_F_04_12 - 1))

#define MAX_VALUE_F_04_12 (((1U << (EXPONENT_BITS_F_04_12 - 2)) - 1) << SIGNIFICAND_BITS_F_04_12) | ((1U << (SIGNIFICAND_BITS_F_04_12 - 2)) - 1)
#define MIN_VALUE_F_04_12 (((1U << (EXPONENT_BITS_F_04_12 - 2)) - 1) << SIGNIFICAND_BITS_F_04_12) | (SIGNIFICAND_SIGN_MASK_F_04_12)

// construct float 0412
f0412_t new_f0412(int16_t exp, int16_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float DDD32
f0412_t new_f0412_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 0412
int16_t exp_f0412(f0412_t a);
// significand part of float 0412
int16_t sig_f0412(f0412_t a);
// add float 0412
f0412_t add_f0412(f0412_t a, f0412_t b);
// subtract float 0412
f0412_t sub_f0412(f0412_t a, f0412_t b);
// negate float 0412
f0412_t neg_f0412(f0412_t a);
// multiply float 0412
f0412_t mul_f0412(f0412_t a, f0412_t b);
// divide float 0412
f0412_t div_f0412(f0412_t a, f0412_t b);
// equals float 0412
bool equ_f0412(f0412_t a, f0412_t b);
// compare float 0412
int com_f0412(f0412_t a, f0412_t b);

#endif // C_FLOAT_04_12_H

