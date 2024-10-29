#ifndef C_P_ADIC_44_20_H
#define C_P_ADIC_44_20_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_44_20 44
#define EXPONENT_BITS_P_44_20 20
#define BITS_P_44_20 SIGNIFICAND_BITS_P_44_20 + EXPONENT_BITS_P_44_20

#define C_P_ADIC_44_20_DEBUG true

typedef uint64_t p4420_t;

#define SIGNIFICAND_MASK_P_44_20 ((1ULL << SIGNIFICAND_BITS_P_44_20) - 1)
#define EXPONENT_MASK_P_44_20 (((1ULL << EXPONENT_BITS_P_44_20) - 1) << SIGNIFICAND_BITS_P_44_20)
#define SIGNIFICAND_SIGN_MASK_P_44_20 (1ULL << (SIGNIFICAND_BITS_P_44_20 - 1))
#define EXPONENT_SIGN_MASK_P_44_20 (1ULL << (EXPONENT_BITS_P_44_20 - 1))
#define BITS_SIGN_MASK_P_44_20 (1ULL << (BITS_P_44_20 - 1))

#define MAX_VALUE_P_44_20 (((1ULL << (EXPONENT_BITS_P_44_20 - 2)) - 1) << SIGNIFICAND_BITS_P_44_20) | ((1ULL << (SIGNIFICAND_BITS_P_44_20 - 2)) - 1)
#define MIN_VALUE_P_44_20 (((1ULL << (EXPONENT_BITS_P_44_20 - 2)) - 1) << SIGNIFICAND_BITS_P_44_20) | (SIGNIFICAND_SIGN_MASK_P_44_20)

// construct p-adic 4420
p4420_t new_p4420(int64_t exp, int64_t sig);
// exponent part of p-adic 4420
int64_t exp_p4420(p4420_t a);
// significand part of p-adic 4420
int64_t sig_p4420(p4420_t a);
// add p-adic 4420
p4420_t add_p4420(p4420_t a, p4420_t b);
// subtract p-adic 4420
p4420_t sub_p4420(p4420_t a, p4420_t b);
// negate p-adic 4420
p4420_t neg_p4420(p4420_t a);
// multiply p-adic 4420
p4420_t mul_p4420(p4420_t a, p4420_t b);
// divide p-adic 4420
p4420_t div_p4420(p4420_t a, p4420_t b);
// equals p-adic 4420
bool equ_p4420(p4420_t a, p4420_t b);
// compare p-adic 4420
int com_p4420(p4420_t a, p4420_t b);

#endif //C_P_ADIC_44_20_H

