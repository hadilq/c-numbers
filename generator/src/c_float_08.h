#ifndef C_FLOAT_CCC_08_H
#define C_FLOAT_CCC_08_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_CCC_08 4
#define EXPONENT_BITS_F_CCC_08 4
#define BITS_F_CCC_08 SIGNIFICAND_BITS_F_CCC_08 + EXPONENT_BITS_F_CCC_08

#define C_FLOAT_CCC_08_DEBUG true

typedef uint8_t fDDD08_t;

#define SIGNIFICAND_MASK_F_CCC_08 ((1U << SIGNIFICAND_BITS_F_CCC_08) - 1)
#define SIGNIFICAND_2_MASK_F_CCC_08 ((1UL << 2 * SIGNIFICAND_BITS_F_CCC_08) - 1)
#define EXPONENT_MASK_F_CCC_08 (((1U << EXPONENT_BITS_F_CCC_08) - 1) << SIGNIFICAND_BITS_F_CCC_08)
#define SIGNIFICAND_SIGN_MASK_F_CCC_08 (1U << (SIGNIFICAND_BITS_F_CCC_08 - 1))
#define EXPONENT_SIGN_MASK_F_CCC_08 (1U << (EXPONENT_BITS_F_CCC_08 - 1))
#define BITS_SIGN_MASK_F_CCC_08 (1U << (BITS_F_CCC_08 - 1))

// construct float DDD08
fDDD08_t new_fDDD08(uint8_t exp, uint8_t sig);
// exponent part of float DDD08
uint8_t exp_fDDD08(fDDD08_t a);
// significand part of float DDD08
uint8_t sig_fDDD08(fDDD08_t a);
// add float DDD08
fDDD08_t add_fDDD08(fDDD08_t a, fDDD08_t b);
// subtract float DDD08
fDDD08_t sub_fDDD08(fDDD08_t a, fDDD08_t b);
// negate float DDD08
fDDD08_t neg_fDDD08(fDDD08_t a);
// multiply float DDD08
fDDD08_t mul_fDDD08(fDDD08_t a, fDDD08_t b);
// divide float DDD08
fDDD08_t div_fDDD08(fDDD08_t a, fDDD08_t b);
// equals float DDD08
bool equ_fDDD08(fDDD08_t a, fDDD08_t b);
// compare float DDD08
int com_fDDD08(fDDD08_t a, fDDD08_t b);

#endif // C_FLOAT_CCC_08_H

