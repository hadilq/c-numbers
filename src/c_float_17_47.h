#ifndef C_FLOAT_17_47_H
#define C_FLOAT_17_47_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_17_47 17
#define EXPONENT_BITS_F_17_47 47
#define BITS_F_17_47 SIGNIFICAND_BITS_F_17_47 + EXPONENT_BITS_F_17_47

#define C_FLOAT_17_47_DEBUG true

typedef uint64_t f1747_t;

#define SIGNIFICAND_MASK_F_17_47 ((1ULL << SIGNIFICAND_BITS_F_17_47) - 1)
#define SIGNIFICAND_2_MASK_F_17_47 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_17_47) - 1)
#define EXPONENT_MASK_F_17_47 (((1ULL << EXPONENT_BITS_F_17_47) - 1) << SIGNIFICAND_BITS_F_17_47)
#define SIGNIFICAND_SIGN_MASK_F_17_47 (1ULL << (SIGNIFICAND_BITS_F_17_47 - 1))
#define EXPONENT_SIGN_MASK_F_17_47 (1ULL << (EXPONENT_BITS_F_17_47 - 1))
#define BITS_SIGN_MASK_F_17_47 (1ULL << (BITS_F_17_47 - 1))

// construct float 1747
f1747_t new_f1747(uint64_t exp, uint64_t sig);
// exponent part of float 1747
uint64_t exp_f1747(f1747_t a);
// significand part of float 1747
uint64_t sig_f1747(f1747_t a);
// add float 1747
f1747_t add_f1747(f1747_t a, f1747_t b);
// subtract float 1747
f1747_t sub_f1747(f1747_t a, f1747_t b);
// negate float 1747
f1747_t neg_f1747(f1747_t a);
// multiply float 1747
f1747_t mul_f1747(f1747_t a, f1747_t b);
// divide float 1747
f1747_t div_f1747(f1747_t a, f1747_t b);
// equals float 1747
bool equ_f1747(f1747_t a, f1747_t b);
// compare float 1747
int com_f1747(f1747_t a, f1747_t b);

#endif // C_FLOAT_17_47_H

