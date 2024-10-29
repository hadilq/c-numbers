#ifndef C_P_ADIC_19_13_H
#define C_P_ADIC_19_13_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_19_13 19
#define EXPONENT_BITS_P_19_13 06
#define BITS_P_19_13 SIGNIFICAND_BITS_P_19_13 + EXPONENT_BITS_P_19_13

#define C_P_ADIC_19_13_DEBUG true

typedef uint32_t p1913_t;

#define SIGNIFICAND_MASK_P_19_13 ((1ULL << SIGNIFICAND_BITS_P_19_13) - 1)
#define EXPONENT_MASK_P_19_13 (((1ULL << EXPONENT_BITS_P_19_13) - 1) << SIGNIFICAND_BITS_P_19_13)
#define SIGNIFICAND_SIGN_MASK_P_19_13 (1U << (SIGNIFICAND_BITS_P_19_13 - 1))
#define EXPONENT_SIGN_MASK_P_19_13 (1U << (EXPONENT_BITS_P_19_13 - 1))
#define BITS_SIGN_MASK_P_19_13 (1U << (BITS_P_19_13 - 1))

#define MAX_VALUE_P_19_13 (((1U << (EXPONENT_BITS_P_19_13 - 2)) - 1) << SIGNIFICAND_BITS_P_19_13) | ((1U << (SIGNIFICAND_BITS_P_19_13 - 2)) - 1)
#define MIN_VALUE_P_19_13 (((1U << (EXPONENT_BITS_P_19_13 - 2)) - 1) << SIGNIFICAND_BITS_P_19_13) | (SIGNIFICAND_SIGN_MASK_P_19_13)

// construct p-adic 1913
p1913_t new_p1913(int32_t exp, int32_t sig);
// exponent part of p-adic 1913
int32_t exp_p1913(p1913_t a);
// significand part of p-adic 1913
int32_t sig_p1913(p1913_t a);
// add p-adic 1913
p1913_t add_p1913(p1913_t a, p1913_t b);
// subtract p-adic 1913
p1913_t sub_p1913(p1913_t a, p1913_t b);
// negate p-adic 1913
p1913_t neg_p1913(p1913_t a);
// multiply p-adic 1913
p1913_t mul_p1913(p1913_t a, p1913_t b);
// divide p-adic 1913
p1913_t div_p1913(p1913_t a, p1913_t b);
// equals p-adic 1913
bool equ_p1913(p1913_t a, p1913_t b);
// compare p-adic 1913
int com_p1913(p1913_t a, p1913_t b);

#endif //C_P_ADIC_19_13_H

