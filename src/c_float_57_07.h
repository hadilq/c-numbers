#ifndef C_FLOAT_57_07_H
#define C_FLOAT_57_07_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_57_07 57
#define EXPONENT_BITS_F_57_07 7
#define BITS_F_57_07 SIGNIFICAND_BITS_F_57_07 + EXPONENT_BITS_F_57_07

#define C_FLOAT_57_07_DEBUG true

typedef uint64_t f5707_t;

#define SIGNIFICAND_MASK_F_57_07 ((1ULL << SIGNIFICAND_BITS_F_57_07) - 1)
#define EXPONENT_MASK_F_57_07 (((1ULL << EXPONENT_BITS_F_57_07) - 1) << SIGNIFICAND_BITS_F_57_07)
#define SIGNIFICAND_SIGN_MASK_F_57_07 (1ULL << (SIGNIFICAND_BITS_F_57_07 - 1))
#define EXPONENT_SIGN_MASK_F_57_07 (1ULL << (EXPONENT_BITS_F_57_07 - 1))

// construct float 5707
f5707_t new_f5707(uint64_t exp, uint64_t sig);
// exponent part of float 5707
uint64_t exp_f5707(f5707_t a);
// significand part of float 5707
uint64_t sig_f5707(f5707_t a);
// add float 5707
f5707_t add_f5707(f5707_t a, f5707_t b);
// subtract float 5707
f5707_t sub_f5707(f5707_t a, f5707_t b);
// negate float 5707
f5707_t neg_f5707(f5707_t a);
// multiply float 5707
f5707_t mul_f5707(f5707_t a, f5707_t b);
// divide float 5707
f5707_t div_f5707(f5707_t a, f5707_t b);
// equals float 5707
bool equ_f5707(f5707_t a, f5707_t b);
// compare float 5707
int com_f5707(f5707_t a, f5707_t b);

#endif // C_FLOAT_57_07_H

