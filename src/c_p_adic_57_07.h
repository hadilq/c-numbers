#ifndef C_P_ADIC_57_07_H
#define C_P_ADIC_57_07_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_57_07 57
#define EXPONENT_BITS_P_57_07 07
#define BITS_P_57_07 SIGNIFICAND_BITS_P_57_07 + EXPONENT_BITS_P_57_07

#define C_P_ADIC_57_07_DEBUG true

typedef uint64_t p5707_t;

#define SIGNIFICAND_MASK_P_57_07 ((1ULL << SIGNIFICAND_BITS_P_57_07) - 1)
#define EXPONENT_MASK_P_57_07 (((1ULL << EXPONENT_BITS_P_57_07) - 1) << SIGNIFICAND_BITS_P_57_07)

// construct p-adic 57 07
p5707_t new_p5707(uint64_t exp, uint64_t sig);
// exponent part of p-adic 57 07
uint64_t exp_p5707(p5707_t a);
// significand part of p-adic 57 07
uint64_t sig_p5707(p5707_t a);
// add p-adic 57 07
p5707_t add_p5707(p5707_t a, p5707_t b);
// subtract p-adic 57 07
p5707_t sub_p5707(p5707_t a, p5707_t b);
// negate p-adic 57 07
p5707_t neg_p5707(p5707_t a);
// multiply p-adic 57 07
p5707_t mul_p5707(p5707_t a, p5707_t b);
// divide p-adic 57 07
p5707_t div_p5707(p5707_t a, p5707_t b);
// equals p-adic 57 07
bool equ_p5707(p5707_t a, p5707_t b);
// compare p-adic 57 07
int com_p5707(p5707_t a, p5707_t b);

#endif //C_P_ADIC_57_07_H

