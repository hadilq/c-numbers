#ifndef C_FLOAT_11_21_H
#define C_FLOAT_11_21_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_11_21 11
#define EXPONENT_BITS_F_11_21 06
#define BITS_F_11_21 SIGNIFICAND_BITS_F_11_21 + EXPONENT_BITS_F_11_21

#define C_FLOAT_11_21_DEBUG true

typedef uint32_t f1121_t;

#define SIGNIFICAND_MASK_F_11_21 ((1UL << SIGNIFICAND_BITS_F_11_21) - 1)
#define SIGNIFICAND_2_MASK_F_11_21 ((1ULL << 2 * SIGNIFICAND_BITS_F_11_21) - 1)
#define EXPONENT_MASK_F_11_21 (((1UL << EXPONENT_BITS_F_11_21) - 1) << SIGNIFICAND_BITS_F_11_21)
#define SIGNIFICAND_SIGN_MASK_F_11_21 (1UL << (SIGNIFICAND_BITS_F_11_21 - 1))
#define EXPONENT_SIGN_MASK_F_11_21 (1UL << (EXPONENT_BITS_F_11_21 - 1))
#define BITS_SIGN_MASK_F_11_21 (1UL << (BITS_F_11_21 - 1))

// construct float 26 06
f1121_t new_f1121(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f1121(f1121_t a);
// significand part of float 26 06
uint32_t sig_f1121(f1121_t a);
// add float 26 06
f1121_t add_f1121(f1121_t a, f1121_t b);
// subtract float 26 06
f1121_t sub_f1121(f1121_t a, f1121_t b);
// negate float 26 06
f1121_t neg_f1121(f1121_t a);
// multiply float 26 06
f1121_t mul_f1121(f1121_t a, f1121_t b);
// divide float 26 06
f1121_t div_f1121(f1121_t a, f1121_t b);
// equals float 26 06
bool equ_f1121(f1121_t a, f1121_t b);
// compare float 26 06
int com_f1121(f1121_t a, f1121_t b);

#endif // C_FLOAT_11_21_H

