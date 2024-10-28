#ifndef C_FLOAT_12_20_H
#define C_FLOAT_12_20_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_12_20 12
#define EXPONENT_BITS_F_12_20 06
#define BITS_F_12_20 SIGNIFICAND_BITS_F_12_20 + EXPONENT_BITS_F_12_20

#define C_FLOAT_12_20_DEBUG true

typedef uint32_t f1220_t;

#define SIGNIFICAND_MASK_F_12_20 ((1UL << SIGNIFICAND_BITS_F_12_20) - 1)
#define SIGNIFICAND_2_MASK_F_12_20 ((1ULL << 2 * SIGNIFICAND_BITS_F_12_20) - 1)
#define EXPONENT_MASK_F_12_20 (((1UL << EXPONENT_BITS_F_12_20) - 1) << SIGNIFICAND_BITS_F_12_20)
#define SIGNIFICAND_SIGN_MASK_F_12_20 (1UL << (SIGNIFICAND_BITS_F_12_20 - 1))
#define EXPONENT_SIGN_MASK_F_12_20 (1UL << (EXPONENT_BITS_F_12_20 - 1))
#define BITS_SIGN_MASK_F_12_20 (1UL << (BITS_F_12_20 - 1))

// construct float 26 06
f1220_t new_f1220(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f1220(f1220_t a);
// significand part of float 26 06
uint32_t sig_f1220(f1220_t a);
// add float 26 06
f1220_t add_f1220(f1220_t a, f1220_t b);
// subtract float 26 06
f1220_t sub_f1220(f1220_t a, f1220_t b);
// negate float 26 06
f1220_t neg_f1220(f1220_t a);
// multiply float 26 06
f1220_t mul_f1220(f1220_t a, f1220_t b);
// divide float 26 06
f1220_t div_f1220(f1220_t a, f1220_t b);
// equals float 26 06
bool equ_f1220(f1220_t a, f1220_t b);
// compare float 26 06
int com_f1220(f1220_t a, f1220_t b);

#endif // C_FLOAT_12_20_H

