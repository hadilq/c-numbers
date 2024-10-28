#ifndef C_FLOAT_05_27_H
#define C_FLOAT_05_27_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_05_27 5
#define EXPONENT_BITS_F_05_27 06
#define BITS_F_05_27 SIGNIFICAND_BITS_F_05_27 + EXPONENT_BITS_F_05_27

#define C_FLOAT_05_27_DEBUG true

typedef uint32_t f0527_t;

#define SIGNIFICAND_MASK_F_05_27 ((1UL << SIGNIFICAND_BITS_F_05_27) - 1)
#define SIGNIFICAND_2_MASK_F_05_27 ((1ULL << 2 * SIGNIFICAND_BITS_F_05_27) - 1)
#define EXPONENT_MASK_F_05_27 (((1UL << EXPONENT_BITS_F_05_27) - 1) << SIGNIFICAND_BITS_F_05_27)
#define SIGNIFICAND_SIGN_MASK_F_05_27 (1UL << (SIGNIFICAND_BITS_F_05_27 - 1))
#define EXPONENT_SIGN_MASK_F_05_27 (1UL << (EXPONENT_BITS_F_05_27 - 1))
#define BITS_SIGN_MASK_F_05_27 (1UL << (BITS_F_05_27 - 1))

// construct float 26 06
f0527_t new_f0527(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f0527(f0527_t a);
// significand part of float 26 06
uint32_t sig_f0527(f0527_t a);
// add float 26 06
f0527_t add_f0527(f0527_t a, f0527_t b);
// subtract float 26 06
f0527_t sub_f0527(f0527_t a, f0527_t b);
// negate float 26 06
f0527_t neg_f0527(f0527_t a);
// multiply float 26 06
f0527_t mul_f0527(f0527_t a, f0527_t b);
// divide float 26 06
f0527_t div_f0527(f0527_t a, f0527_t b);
// equals float 26 06
bool equ_f0527(f0527_t a, f0527_t b);
// compare float 26 06
int com_f0527(f0527_t a, f0527_t b);

#endif // C_FLOAT_05_27_H

