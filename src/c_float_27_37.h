#ifndef C_FLOAT_27_37_H
#define C_FLOAT_27_37_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_27_37 27
#define EXPONENT_BITS_F_27_37 37
#define BITS_F_27_37 SIGNIFICAND_BITS_F_27_37 + EXPONENT_BITS_F_27_37

#define C_FLOAT_27_37_DEBUG true

typedef uint64_t f2737_t;

#define SIGNIFICAND_MASK_F_27_37 ((1ULL << SIGNIFICAND_BITS_F_27_37) - 1)
#define SIGNIFICAND_2_MASK_F_27_37 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_27_37) - 1)
#define EXPONENT_MASK_F_27_37 (((1ULL << EXPONENT_BITS_F_27_37) - 1) << SIGNIFICAND_BITS_F_27_37)
#define SIGNIFICAND_SIGN_MASK_F_27_37 (1ULL << (SIGNIFICAND_BITS_F_27_37 - 1))
#define EXPONENT_SIGN_MASK_F_27_37 (1ULL << (EXPONENT_BITS_F_27_37 - 1))
#define BITS_SIGN_MASK_F_27_37 (1ULL << (BITS_F_27_37 - 1))

// construct float 2737
f2737_t new_f2737(uint64_t exp, uint64_t sig);
// exponent part of float 2737
uint64_t exp_f2737(f2737_t a);
// significand part of float 2737
uint64_t sig_f2737(f2737_t a);
// add float 2737
f2737_t add_f2737(f2737_t a, f2737_t b);
// subtract float 2737
f2737_t sub_f2737(f2737_t a, f2737_t b);
// negate float 2737
f2737_t neg_f2737(f2737_t a);
// multiply float 2737
f2737_t mul_f2737(f2737_t a, f2737_t b);
// divide float 2737
f2737_t div_f2737(f2737_t a, f2737_t b);
// equals float 2737
bool equ_f2737(f2737_t a, f2737_t b);
// compare float 2737
int com_f2737(f2737_t a, f2737_t b);

#endif // C_FLOAT_27_37_H
