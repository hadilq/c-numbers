#ifndef C_P_ADIC_02_62_H
#define C_P_ADIC_02_62_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_02_62 2
#define EXPONENT_BITS_P_02_62 62
#define BITS_P_02_62 SIGNIFICAND_BITS_P_02_62 + EXPONENT_BITS_P_02_62

#define C_P_ADIC_02_62_DEBUG true

typedef uint64_t p0262_t;

#define SIGNIFICAND_MASK_P_02_62 ((1ULL << SIGNIFICAND_BITS_P_02_62) - 1)
#define EXPONENT_MASK_P_02_62 (((1ULL << EXPONENT_BITS_P_02_62) - 1) << SIGNIFICAND_BITS_P_02_62)
#define SIGNIFICAND_SIGN_MASK_P_02_62 (1ULL << (SIGNIFICAND_BITS_P_02_62 - 1))
#define EXPONENT_SIGN_MASK_P_02_62 (1ULL << (EXPONENT_BITS_P_02_62 - 1))
#define BITS_SIGN_MASK_P_02_62 (1ULL << (BITS_P_02_62 - 1))

#define MAX_VALUE_P_02_62 (((1ULL << (EXPONENT_BITS_P_02_62 - 2)) - 1) << SIGNIFICAND_BITS_P_02_62) | ((1ULL << (SIGNIFICAND_BITS_P_02_62 - 2)) - 1)
#define MIN_VALUE_P_02_62 (((1ULL << (EXPONENT_BITS_P_02_62 - 2)) - 1) << SIGNIFICAND_BITS_P_02_62) | (SIGNIFICAND_SIGN_MASK_P_02_62)

// construct p-adic 0262
p0262_t new_p0262(int64_t exp, int64_t sig);
// exponent part of p-adic 0262
int64_t exp_p0262(p0262_t a);
// significand part of p-adic 0262
int64_t sig_p0262(p0262_t a);
// add p-adic 0262
p0262_t add_p0262(p0262_t a, p0262_t b);
// subtract p-adic 0262
p0262_t sub_p0262(p0262_t a, p0262_t b);
// negate p-adic 0262
p0262_t neg_p0262(p0262_t a);
// multiply p-adic 0262
p0262_t mul_p0262(p0262_t a, p0262_t b);
// divide p-adic 0262
p0262_t div_p0262(p0262_t a, p0262_t b);
// equals p-adic 0262
bool equ_p0262(p0262_t a, p0262_t b);
// compare p-adic 0262
int com_p0262(p0262_t a, p0262_t b);

#endif //C_P_ADIC_02_62_H

