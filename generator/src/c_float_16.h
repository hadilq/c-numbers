#ifndef C_FLOAT_CCC_16_H
#define C_FLOAT_CCC_16_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_CCC_16 11
#define EXPONENT_BITS_F_CCC_16 05
#define BITS_F_CCC_16 SIGNIFICAND_BITS_F_CCC_16 + EXPONENT_BITS_F_CCC_16

#define C_FLOAT_CCC_16_DEBUG true

typedef uint16_t fDDD16_t;

#define SIGNIFICAND_MASK_F_CCC_16 ((1U << SIGNIFICAND_BITS_F_CCC_16) - 1)
#define SIGNIFICAND_2_MASK_F_CCC_16 ((1UL << 2 * SIGNIFICAND_BITS_F_CCC_16) - 1)
#define EXPONENT_MASK_F_CCC_16 (((1U << EXPONENT_BITS_F_CCC_16) - 1) << SIGNIFICAND_BITS_F_CCC_16)
#define SIGNIFICAND_SIGN_MASK_F_CCC_16 (1U << (SIGNIFICAND_BITS_F_CCC_16 - 1))
#define EXPONENT_SIGN_MASK_F_CCC_16 (1U << (EXPONENT_BITS_F_CCC_16 - 1))
#define BITS_SIGN_MASK_F_CCC_16 (1U << (BITS_F_CCC_16 - 1))

#define MAX_VALUE_F_CCC_16 (((1U << (EXPONENT_BITS_F_CCC_16 - 2)) - 1) << SIGNIFICAND_BITS_F_CCC_16) | ((1U << (SIGNIFICAND_BITS_F_CCC_16 - 2)) - 1)
#define MIN_VALUE_F_CCC_16 (((1U << (EXPONENT_BITS_F_CCC_16 - 2)) - 1) << SIGNIFICAND_BITS_F_CCC_16) | (SIGNIFICAND_SIGN_MASK_F_CCC_16)

// construct float DDD16
fDDD16_t new_fDDD16(int16_t exp, int16_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float DDD32
fDDD16_t new_fDDD16_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float DDD16
int16_t exp_fDDD16(fDDD16_t a);
// significand part of float DDD16
int16_t sig_fDDD16(fDDD16_t a);
// add float DDD16
fDDD16_t add_fDDD16(fDDD16_t a, fDDD16_t b);
// subtract float DDD16
fDDD16_t sub_fDDD16(fDDD16_t a, fDDD16_t b);
// negate float DDD16
fDDD16_t neg_fDDD16(fDDD16_t a);
// multiply float DDD16
fDDD16_t mul_fDDD16(fDDD16_t a, fDDD16_t b);
// divide float DDD16
fDDD16_t div_fDDD16(fDDD16_t a, fDDD16_t b);
// equals float DDD16
bool equ_fDDD16(fDDD16_t a, fDDD16_t b);
// compare float DDD16
int com_fDDD16(fDDD16_t a, fDDD16_t b);

#endif // C_FLOAT_CCC_16_H

