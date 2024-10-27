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
#define EXPONENT_MASK_F_CCC_16 (((1U << EXPONENT_BITS_F_CCC_16) - 1) << SIGNIFICAND_BITS_F_CCC_16)
#define SIGNIFICAND_SIGN_MASK_F_CCC_16 (1U << (SIGNIFICAND_BITS_F_CCC_16 - 1))
#define EXPONENT_SIGN_MASK_F_CCC_16 (1U << (EXPONENT_BITS_F_CCC_16 - 1))

// construct float DDD16
fDDD16_t new_fDDD16(uint16_t exp, uint16_t sig);
// exponent part of float DDD16
uint16_t exp_fDDD16(fDDD16_t a);
// significand part of float DDD16
uint16_t sig_fDDD16(fDDD16_t a);
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

