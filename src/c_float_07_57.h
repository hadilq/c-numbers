#ifndef C_FLOAT_07_57_H
#define C_FLOAT_07_57_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_07_57 7
#define EXPONENT_BITS_F_07_57 57
#define BITS_F_07_57 SIGNIFICAND_BITS_F_07_57 + EXPONENT_BITS_F_07_57

#define C_FLOAT_07_57_DEBUG true

typedef uint64_t f0757_t;

#define SIGNIFICAND_MASK_F_07_57 ((1ULL << SIGNIFICAND_BITS_F_07_57) - 1)
#define SIGNIFICAND_2_MASK_F_07_57 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_07_57) - 1)
#define EXPONENT_MASK_F_07_57 (((1ULL << EXPONENT_BITS_F_07_57) - 1) << SIGNIFICAND_BITS_F_07_57)
#define SIGNIFICAND_SIGN_MASK_F_07_57 (1ULL << (SIGNIFICAND_BITS_F_07_57 - 1))
#define EXPONENT_SIGN_MASK_F_07_57 (1ULL << (EXPONENT_BITS_F_07_57 - 1))
#define BITS_SIGN_MASK_F_07_57 (1ULL << (BITS_F_07_57 - 1))

// construct float 0757
f0757_t new_f0757(uint64_t exp, uint64_t sig);
// exponent part of float 0757
uint64_t exp_f0757(f0757_t a);
// significand part of float 0757
uint64_t sig_f0757(f0757_t a);
// add float 0757
f0757_t add_f0757(f0757_t a, f0757_t b);
// subtract float 0757
f0757_t sub_f0757(f0757_t a, f0757_t b);
// negate float 0757
f0757_t neg_f0757(f0757_t a);
// multiply float 0757
f0757_t mul_f0757(f0757_t a, f0757_t b);
// divide float 0757
f0757_t div_f0757(f0757_t a, f0757_t b);
// equals float 0757
bool equ_f0757(f0757_t a, f0757_t b);
// compare float 0757
int com_f0757(f0757_t a, f0757_t b);

#endif // C_FLOAT_07_57_H
