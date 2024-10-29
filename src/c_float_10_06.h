#ifndef C_FLOAT_10_06_H
#define C_FLOAT_10_06_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_10_06 10
#define EXPONENT_BITS_F_10_06 05
#define BITS_F_10_06 SIGNIFICAND_BITS_F_10_06 + EXPONENT_BITS_F_10_06

#define C_FLOAT_10_06_DEBUG true

typedef uint16_t f1006_t;

#define SIGNIFICAND_MASK_F_10_06 ((1U << SIGNIFICAND_BITS_F_10_06) - 1)
#define SIGNIFICAND_2_MASK_F_10_06 ((1UL << 2 * SIGNIFICAND_BITS_F_10_06) - 1)
#define EXPONENT_MASK_F_10_06 (((1U << EXPONENT_BITS_F_10_06) - 1) << SIGNIFICAND_BITS_F_10_06)
#define SIGNIFICAND_SIGN_MASK_F_10_06 (1U << (SIGNIFICAND_BITS_F_10_06 - 1))
#define EXPONENT_SIGN_MASK_F_10_06 (1U << (EXPONENT_BITS_F_10_06 - 1))
#define BITS_SIGN_MASK_F_10_06 (1U << (BITS_F_10_06 - 1))

#define MAX_VALUE_F_10_06 (((1U << (EXPONENT_BITS_F_10_06 - 2)) - 1) << SIGNIFICAND_BITS_F_10_06) | ((1U << (SIGNIFICAND_BITS_F_10_06 - 2)) - 1)
#define MIN_VALUE_F_10_06 (((1U << (EXPONENT_BITS_F_10_06 - 2)) - 1) << SIGNIFICAND_BITS_F_10_06) | (SIGNIFICAND_SIGN_MASK_F_10_06)

// construct float 1006
f1006_t new_f1006(int16_t exp, int16_t sig);
// construct float DDD32
f1006_t new_f1006_from_float16(_Float16 f);
// exponent part of float 1006
int16_t exp_f1006(f1006_t a);
// significand part of float 1006
int16_t sig_f1006(f1006_t a);
// add float 1006
f1006_t add_f1006(f1006_t a, f1006_t b);
// subtract float 1006
f1006_t sub_f1006(f1006_t a, f1006_t b);
// negate float 1006
f1006_t neg_f1006(f1006_t a);
// multiply float 1006
f1006_t mul_f1006(f1006_t a, f1006_t b);
// divide float 1006
f1006_t div_f1006(f1006_t a, f1006_t b);
// equals float 1006
bool equ_f1006(f1006_t a, f1006_t b);
// compare float 1006
int com_f1006(f1006_t a, f1006_t b);

#endif // C_FLOAT_10_06_H

