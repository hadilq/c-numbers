#ifndef C_P_ADIC_CCC_64_H
#define C_P_ADIC_CCC_64_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_CCC_64 57
#define EXPONENT_BITS_P_CCC_64 7
#define BITS_P_CCC_64 SIGNIFICAND_BITS_P_CCC_64 + EXPONENT_BITS_P_CCC_64

#define C_P_ADIC_CCC_64_DEBUG true

typedef uint64_t pDDD64_t;

#define SIGNIFICAND_MASK_P_CCC_64 ((1ULL << SIGNIFICAND_BITS_P_CCC_64) - 1)
#define EXPONENT_MASK_P_CCC_64 (((1ULL << EXPONENT_BITS_P_CCC_64) - 1) << SIGNIFICAND_BITS_P_CCC_64)
#define SIGNIFICAND_SIGN_MASK_P_CCC_64 (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1))
#define EXPONENT_SIGN_MASK_P_CCC_64 (1ULL << (EXPONENT_BITS_P_CCC_64 - 1))
#define BITS_SIGN_MASK_P_CCC_64 (1ULL << (BITS_P_CCC_64 - 1))

#define MAX_VALUE_P_CCC_64 (((1ULL << (EXPONENT_BITS_P_CCC_64 - 2)) - 1) << SIGNIFICAND_BITS_P_CCC_64) | ((1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) - 1)
#define MIN_VALUE_P_CCC_64 (((1ULL << (EXPONENT_BITS_P_CCC_64 - 2)) - 1) << SIGNIFICAND_BITS_P_CCC_64) | (SIGNIFICAND_SIGN_MASK_P_CCC_64)

// construct p-adic DDD64
pDDD64_t new_pDDD64(uint64_t exp, uint64_t sig);
// exponent part of p-adic DDD64
uint64_t exp_pDDD64(pDDD64_t a);
// significand part of p-adic DDD64
uint64_t sig_pDDD64(pDDD64_t a);
// add p-adic DDD64
pDDD64_t add_pDDD64(pDDD64_t a, pDDD64_t b);
// subtract p-adic DDD64
pDDD64_t sub_pDDD64(pDDD64_t a, pDDD64_t b);
// negate p-adic DDD64
pDDD64_t neg_pDDD64(pDDD64_t a);
// multiply p-adic DDD64
pDDD64_t mul_pDDD64(pDDD64_t a, pDDD64_t b);
// divide p-adic DDD64
pDDD64_t div_pDDD64(pDDD64_t a, pDDD64_t b);
// equals p-adic DDD64
bool equ_pDDD64(pDDD64_t a, pDDD64_t b);
// compare p-adic DDD64
int com_pDDD64(pDDD64_t a, pDDD64_t b);

#endif //C_P_ADIC_CCC_64_H

