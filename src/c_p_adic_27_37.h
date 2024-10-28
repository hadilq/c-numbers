#ifndef C_P_ADIC_27_37_H
#define C_P_ADIC_27_37_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_27_37 27
#define EXPONENT_BITS_P_27_37 37
#define BITS_P_27_37 SIGNIFICAND_BITS_P_27_37 + EXPONENT_BITS_P_27_37

#define C_P_ADIC_27_37_DEBUG true

typedef uint64_t p2737_t;

#define SIGNIFICAND_MASK_P_27_37 ((1ULL << SIGNIFICAND_BITS_P_27_37) - 1)
#define EXPONENT_MASK_P_27_37 (((1ULL << EXPONENT_BITS_P_27_37) - 1) << SIGNIFICAND_BITS_P_27_37)
#define SIGNIFICAND_SIGN_MASK_P_27_37 (1ULL << (SIGNIFICAND_BITS_P_27_37 - 1))
#define EXPONENT_SIGN_MASK_P_27_37 (1ULL << (EXPONENT_BITS_P_27_37 - 1))
#define BITS_SIGN_MASK_P_27_37 (1ULL << (BITS_P_27_37 - 1))

// construct p-adic 2737
p2737_t new_p2737(uint64_t exp, uint64_t sig);
// exponent part of p-adic 2737
uint64_t exp_p2737(p2737_t a);
// significand part of p-adic 2737
uint64_t sig_p2737(p2737_t a);
// add p-adic 2737
p2737_t add_p2737(p2737_t a, p2737_t b);
// subtract p-adic 2737
p2737_t sub_p2737(p2737_t a, p2737_t b);
// negate p-adic 2737
p2737_t neg_p2737(p2737_t a);
// multiply p-adic 2737
p2737_t mul_p2737(p2737_t a, p2737_t b);
// divide p-adic 2737
p2737_t div_p2737(p2737_t a, p2737_t b);
// equals p-adic 2737
bool equ_p2737(p2737_t a, p2737_t b);
// compare p-adic 2737
int com_p2737(p2737_t a, p2737_t b);

#endif //C_P_ADIC_27_37_H

