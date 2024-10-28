#ifndef C_FLOAT_02_30_H
#define C_FLOAT_02_30_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_02_30 2
#define EXPONENT_BITS_F_02_30 06
#define BITS_F_02_30 SIGNIFICAND_BITS_F_02_30 + EXPONENT_BITS_F_02_30

#define C_FLOAT_02_30_DEBUG true

typedef uint32_t f0230_t;

#define SIGNIFICAND_MASK_F_02_30 ((1UL << SIGNIFICAND_BITS_F_02_30) - 1)
#define SIGNIFICAND_2_MASK_F_02_30 ((1ULL << 2 * SIGNIFICAND_BITS_F_02_30) - 1)
#define EXPONENT_MASK_F_02_30 (((1UL << EXPONENT_BITS_F_02_30) - 1) << SIGNIFICAND_BITS_F_02_30)
#define SIGNIFICAND_SIGN_MASK_F_02_30 (1UL << (SIGNIFICAND_BITS_F_02_30 - 1))
#define EXPONENT_SIGN_MASK_F_02_30 (1UL << (EXPONENT_BITS_F_02_30 - 1))
#define BITS_SIGN_MASK_F_02_30 (1UL << (BITS_F_02_30 - 1))

// construct float 26 06
f0230_t new_f0230(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f0230(f0230_t a);
// significand part of float 26 06
uint32_t sig_f0230(f0230_t a);
// add float 26 06
f0230_t add_f0230(f0230_t a, f0230_t b);
// subtract float 26 06
f0230_t sub_f0230(f0230_t a, f0230_t b);
// negate float 26 06
f0230_t neg_f0230(f0230_t a);
// multiply float 26 06
f0230_t mul_f0230(f0230_t a, f0230_t b);
// divide float 26 06
f0230_t div_f0230(f0230_t a, f0230_t b);
// equals float 26 06
bool equ_f0230(f0230_t a, f0230_t b);
// compare float 26 06
int com_f0230(f0230_t a, f0230_t b);

#endif // C_FLOAT_02_30_H

