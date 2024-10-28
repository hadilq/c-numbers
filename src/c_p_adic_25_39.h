#ifndef C_P_ADIC_25_39_H
#define C_P_ADIC_25_39_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_25_39 25
#define EXPONENT_BITS_P_25_39 39
#define BITS_P_25_39 SIGNIFICAND_BITS_P_25_39 + EXPONENT_BITS_P_25_39

#define C_P_ADIC_25_39_DEBUG true

typedef uint64_t p2539_t;

#define SIGNIFICAND_MASK_P_25_39 ((1ULL << SIGNIFICAND_BITS_P_25_39) - 1)
#define EXPONENT_MASK_P_25_39 (((1ULL << EXPONENT_BITS_P_25_39) - 1) << SIGNIFICAND_BITS_P_25_39)
#define SIGNIFICAND_SIGN_MASK_P_25_39 (1ULL << (SIGNIFICAND_BITS_P_25_39 - 1))
#define EXPONENT_SIGN_MASK_P_25_39 (1ULL << (EXPONENT_BITS_P_25_39 - 1))
#define BITS_SIGN_MASK_P_25_39 (1ULL << (BITS_P_25_39 - 1))

// construct p-adic 2539
p2539_t new_p2539(uint64_t exp, uint64_t sig);
// exponent part of p-adic 2539
uint64_t exp_p2539(p2539_t a);
// significand part of p-adic 2539
uint64_t sig_p2539(p2539_t a);
// add p-adic 2539
p2539_t add_p2539(p2539_t a, p2539_t b);
// subtract p-adic 2539
p2539_t sub_p2539(p2539_t a, p2539_t b);
// negate p-adic 2539
p2539_t neg_p2539(p2539_t a);
// multiply p-adic 2539
p2539_t mul_p2539(p2539_t a, p2539_t b);
// divide p-adic 2539
p2539_t div_p2539(p2539_t a, p2539_t b);
// equals p-adic 2539
bool equ_p2539(p2539_t a, p2539_t b);
// compare p-adic 2539
int com_p2539(p2539_t a, p2539_t b);

#endif //C_P_ADIC_25_39_H

