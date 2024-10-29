#ifndef C_P_ADIC_46_18_H
#define C_P_ADIC_46_18_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_46_18 46
#define EXPONENT_BITS_P_46_18 18
#define BITS_P_46_18 SIGNIFICAND_BITS_P_46_18 + EXPONENT_BITS_P_46_18

#define C_P_ADIC_46_18_DEBUG true

typedef uint64_t p4618_t;

#define SIGNIFICAND_MASK_P_46_18 ((1ULL << SIGNIFICAND_BITS_P_46_18) - 1)
#define EXPONENT_MASK_P_46_18 (((1ULL << EXPONENT_BITS_P_46_18) - 1) << SIGNIFICAND_BITS_P_46_18)
#define SIGNIFICAND_SIGN_MASK_P_46_18 (1ULL << (SIGNIFICAND_BITS_P_46_18 - 1))
#define EXPONENT_SIGN_MASK_P_46_18 (1ULL << (EXPONENT_BITS_P_46_18 - 1))
#define BITS_SIGN_MASK_P_46_18 (1ULL << (BITS_P_46_18 - 1))

#define MAX_VALUE_P_46_18 (((1ULL << (EXPONENT_BITS_P_46_18 - 2)) - 1) << SIGNIFICAND_BITS_P_46_18) | ((1ULL << (SIGNIFICAND_BITS_P_46_18 - 2)) - 1)
#define MIN_VALUE_P_46_18 (((1ULL << (EXPONENT_BITS_P_46_18 - 2)) - 1) << SIGNIFICAND_BITS_P_46_18) | (SIGNIFICAND_SIGN_MASK_P_46_18)

// construct p-adic 4618
p4618_t new_p4618(int64_t exp, int64_t sig);
// exponent part of p-adic 4618
int64_t exp_p4618(p4618_t a);
// significand part of p-adic 4618
int64_t sig_p4618(p4618_t a);
// add p-adic 4618
p4618_t add_p4618(p4618_t a, p4618_t b);
// subtract p-adic 4618
p4618_t sub_p4618(p4618_t a, p4618_t b);
// negate p-adic 4618
p4618_t neg_p4618(p4618_t a);
// multiply p-adic 4618
p4618_t mul_p4618(p4618_t a, p4618_t b);
// divide p-adic 4618
p4618_t div_p4618(p4618_t a, p4618_t b);
// equals p-adic 4618
bool equ_p4618(p4618_t a, p4618_t b);
// compare p-adic 4618
int com_p4618(p4618_t a, p4618_t b);

#endif //C_P_ADIC_46_18_H

