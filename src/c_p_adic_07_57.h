#ifndef C_P_ADIC_07_57_H
#define C_P_ADIC_07_57_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_07_57 7
#define EXPONENT_BITS_P_07_57 57
#define BITS_P_07_57 SIGNIFICAND_BITS_P_07_57 + EXPONENT_BITS_P_07_57

#define C_P_ADIC_07_57_DEBUG true

typedef uint64_t p0757_t;

#define SIGNIFICAND_MASK_P_07_57 ((1ULL << SIGNIFICAND_BITS_P_07_57) - 1)
#define EXPONENT_MASK_P_07_57 (((1ULL << EXPONENT_BITS_P_07_57) - 1) << SIGNIFICAND_BITS_P_07_57)
#define SIGNIFICAND_SIGN_MASK_P_07_57 (1ULL << (SIGNIFICAND_BITS_P_07_57 - 1))
#define EXPONENT_SIGN_MASK_P_07_57 (1ULL << (EXPONENT_BITS_P_07_57 - 1))
#define BITS_SIGN_MASK_P_07_57 (1ULL << (BITS_P_07_57 - 1))

// construct p-adic 0757
p0757_t new_p0757(uint64_t exp, uint64_t sig);
// exponent part of p-adic 0757
uint64_t exp_p0757(p0757_t a);
// significand part of p-adic 0757
uint64_t sig_p0757(p0757_t a);
// add p-adic 0757
p0757_t add_p0757(p0757_t a, p0757_t b);
// subtract p-adic 0757
p0757_t sub_p0757(p0757_t a, p0757_t b);
// negate p-adic 0757
p0757_t neg_p0757(p0757_t a);
// multiply p-adic 0757
p0757_t mul_p0757(p0757_t a, p0757_t b);
// divide p-adic 0757
p0757_t div_p0757(p0757_t a, p0757_t b);
// equals p-adic 0757
bool equ_p0757(p0757_t a, p0757_t b);
// compare p-adic 0757
int com_p0757(p0757_t a, p0757_t b);

#endif //C_P_ADIC_07_57_H

