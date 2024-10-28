#ifndef C_FLOAT_19_13_H
#define C_FLOAT_19_13_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_19_13 19
#define EXPONENT_BITS_F_19_13 06
#define BITS_F_19_13 SIGNIFICAND_BITS_F_19_13 + EXPONENT_BITS_F_19_13

#define C_FLOAT_19_13_DEBUG true

typedef uint32_t f1913_t;

#define SIGNIFICAND_MASK_F_19_13 ((1UL << SIGNIFICAND_BITS_F_19_13) - 1)
#define SIGNIFICAND_2_MASK_F_19_13 ((1ULL << 2 * SIGNIFICAND_BITS_F_19_13) - 1)
#define EXPONENT_MASK_F_19_13 (((1UL << EXPONENT_BITS_F_19_13) - 1) << SIGNIFICAND_BITS_F_19_13)
#define SIGNIFICAND_SIGN_MASK_F_19_13 (1UL << (SIGNIFICAND_BITS_F_19_13 - 1))
#define EXPONENT_SIGN_MASK_F_19_13 (1UL << (EXPONENT_BITS_F_19_13 - 1))
#define BITS_SIGN_MASK_F_19_13 (1UL << (BITS_F_19_13 - 1))

// construct float 26 06
f1913_t new_f1913(uint32_t exp, uint32_t sig);
// exponent part of float 26 06
uint32_t exp_f1913(f1913_t a);
// significand part of float 26 06
uint32_t sig_f1913(f1913_t a);
// add float 26 06
f1913_t add_f1913(f1913_t a, f1913_t b);
// subtract float 26 06
f1913_t sub_f1913(f1913_t a, f1913_t b);
// negate float 26 06
f1913_t neg_f1913(f1913_t a);
// multiply float 26 06
f1913_t mul_f1913(f1913_t a, f1913_t b);
// divide float 26 06
f1913_t div_f1913(f1913_t a, f1913_t b);
// equals float 26 06
bool equ_f1913(f1913_t a, f1913_t b);
// compare float 26 06
int com_f1913(f1913_t a, f1913_t b);

#endif // C_FLOAT_19_13_H

