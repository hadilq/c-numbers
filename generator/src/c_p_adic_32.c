#include "c_p_adic_32.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

static void log_debug_label(const char* label) {
    if (C_P_ADIC_CCC_32_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_p_adic(const char* label, uint32_t f) {
    if (C_P_ADIC_CCC_32_DEBUG) {
        printf("%s: %d, 0x%x\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_P_ADIC_CCC_32_DEBUG) {
        assert(false);
    }
}

static void let(bool assumption) {
    if (C_P_ADIC_CCC_32_DEBUG) {
        assert(assumption);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index(uint32_t n) {
    if (n == 0) return SIGNIFICAND_BITS_P_CCC_32 - 1; // Handle 0 as a special case

    uint32_t copy = n << EXPONENT_BITS_P_CCC_32;
    for (uint8_t i = SIGNIFICAND_BITS_P_CCC_32 - 1; i >= 0; i--) {
        copy <<= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for positive numbers for 64 digit numbers
static uint8_t get_msb_index_64(uint64_t n) {
    if (n == 0U) return 0; // Handle 0 as a special case

    uint64_t copy = n << (2 * EXPONENT_BITS_P_CCC_32);
    if (copy == 0U) return 0; // Handle 0 as a special case
    for (uint8_t i = 2 * SIGNIFICAND_BITS_P_CCC_32 - 1; i >= 0; i--) {
        copy <<= 1;
        if (copy == 0U) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// construct p-adic DDD32
pDDD32_t new_pDDD32(uint32_t exp, uint32_t sig) {
    return (exp << SIGNIFICAND_BITS_P_CCC_32) | (sig & SIGNIFICAND_MASK_P_CCC_32);
}

// exponent part of p-adic DDD32
uint32_t exp_pDDD32(pDDD32_t a) {
    uint32_t exp_a = (a & EXPONENT_MASK_P_CCC_32) >> SIGNIFICAND_BITS_P_CCC_32;

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_P_CCC_32 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_CCC_32 << EXPONENT_BITS_P_CCC_32; // Fill the left with ones
    }
    return exp_a;
}

// significand part of p-adic DDD32
uint32_t sig_pDDD32(pDDD32_t a) {
    uint32_t sig_a = a & SIGNIFICAND_MASK_P_CCC_32;

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_P_CCC_32 & sig_a)) {
        sig_a |= EXPONENT_MASK_P_CCC_32;
    }
    return sig_a;
}

// add p-adic DDD32
pDDD32_t add_pDDD32(pDDD32_t a, pDDD32_t b) {
    // Extract exponent and significand
    int32_t exp_a = (a & EXPONENT_MASK_P_CCC_32) >> SIGNIFICAND_BITS_P_CCC_32;
    int32_t exp_b = (b & EXPONENT_MASK_P_CCC_32) >> SIGNIFICAND_BITS_P_CCC_32;
    uint32_t sig_a = a & SIGNIFICAND_MASK_P_CCC_32;
    uint32_t sig_b = b & SIGNIFICAND_MASK_P_CCC_32;
    uint32_t result_exp = exp_a;
    log_debug_p_adic("exp_a", exp_a);
    log_debug_p_adic("exp_b", exp_b);
    log_debug_p_adic("sig_a", sig_a);
    log_debug_p_adic("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_P_CCC_32 & sig_a)) {
        sig_a |= EXPONENT_MASK_P_CCC_32;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_P_CCC_32 & sig_b)) {
        sig_b |= EXPONENT_MASK_P_CCC_32;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_P_CCC_32 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_CCC_32 << EXPONENT_BITS_P_CCC_32; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_P_CCC_32 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_P_CCC_32 << EXPONENT_BITS_P_CCC_32; // Fill the left with ones
    }

    // Align significands and handle negatives
    if (exp_a > exp_b) {
        uint8_t diff = exp_a - exp_b;
        sig_a <<= diff;
        log_debug_p_adic("diff 'exp_a > exp_b' is", diff);
        result_exp = exp_b;
    } else if (exp_b > exp_a) {
        uint8_t diff = exp_b - exp_a;
        sig_b <<= diff;
        log_debug_p_adic("diff 'exp_b > exp_a' is", diff);
        result_exp = exp_a;
    }

    // Add significands
    uint32_t result_sig = sig_a + sig_b;

    // Check for zero
    if (result_sig == 0) {
        return 0U;
    }

    log_debug_p_adic("result significand", result_sig);
    log_debug_p_adic("result exponent", result_exp);

    int8_t msb = get_msb_index(result_sig);
    log_debug_p_adic("msb", msb);

    // Normalize result
    if (msb > 0) {
        result_sig >>= msb;
        result_exp += msb;
    }

    // Assemble result
    return new_pDDD32(result_exp, result_sig);
}

pDDD32_t sub_pDDD32(pDDD32_t a, pDDD32_t b) {
    return add_pDDD32(a, neg_pDDD32(b));
}

pDDD32_t neg_pDDD32(pDDD32_t b) {
    // Negate b and add
    uint32_t exp_b = b & EXPONENT_MASK_P_CCC_32;
    uint32_t sig_b = b & SIGNIFICAND_MASK_P_CCC_32;

    // Flip all bits of significand for two's complement
    if ((1ULL << (SIGNIFICAND_BITS_P_CCC_32 - 1) & sig_b)) {
        // negative
        sig_b = (~sig_b + 1) & SIGNIFICAND_MASK_P_CCC_32;
    } else {
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_P_CCC_32;
    }

    return exp_b | sig_b;
}

pDDD32_t mul_pDDD32(pDDD32_t a, pDDD32_t b) {
    uint32_t exp_a = (a & EXPONENT_MASK_P_CCC_32) >> SIGNIFICAND_BITS_P_CCC_32;
    uint32_t exp_b = (b & EXPONENT_MASK_P_CCC_32) >> SIGNIFICAND_BITS_P_CCC_32;
    uint32_t sig_a = a & SIGNIFICAND_MASK_P_CCC_32;
    uint32_t sig_b = b & SIGNIFICAND_MASK_P_CCC_32;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_p_adic("exp_a", exp_a);
    log_debug_p_adic("exp_b", exp_b);
    log_debug_p_adic("sig_a", sig_a);
    log_debug_p_adic("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_P_CCC_32 & sig_a)) {
        sig_a |= EXPONENT_MASK_P_CCC_32;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_P_CCC_32;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_P_CCC_32 & sig_b)) {
        sig_b |= EXPONENT_MASK_P_CCC_32;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_P_CCC_32;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_P_CCC_32 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_CCC_32 << EXPONENT_BITS_P_CCC_32; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_P_CCC_32 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_P_CCC_32 << EXPONENT_BITS_P_CCC_32; // Fill the left with ones
    }

    // Multiply significands
    uint64_t temp_sig = (uint32_t)sig_a * sig_b;
    log_debug_p_adic("result significand", temp_sig);

    // Adjust exponent
    uint32_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_64(temp_sig);
    log_debug_p_adic("msb", msb);

    // Normalize result
    uint32_t result_sig = (uint32_t)temp_sig & SIGNIFICAND_MASK_P_CCC_32;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
        result_exp += msb;
    }
    log_debug_p_adic("result significand", result_sig);
    log_debug_p_adic("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_p_adic("result significand", result_sig);
    }

    return new_pDDD32(result_exp, result_sig);
}

pDDD32_t div_pDDD32(pDDD32_t a, pDDD32_t b) {
    uint32_t exp_a = (a & EXPONENT_MASK_P_CCC_32) >> SIGNIFICAND_BITS_P_CCC_32;
    uint32_t exp_b = (b & EXPONENT_MASK_P_CCC_32) >> SIGNIFICAND_BITS_P_CCC_32;
    uint32_t sig_a = a & SIGNIFICAND_MASK_P_CCC_32;
    uint32_t sig_b = b & SIGNIFICAND_MASK_P_CCC_32;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_p_adic("exp_a", exp_a);
    log_debug_p_adic("exp_b", exp_b);
    log_debug_p_adic("sig_a", sig_a);
    log_debug_p_adic("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_P_CCC_32 & sig_a)) {
        sig_a |= EXPONENT_MASK_P_CCC_32;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_P_CCC_32;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_P_CCC_32 & sig_b)) {
        sig_b |= EXPONENT_MASK_P_CCC_32;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_P_CCC_32;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_P_CCC_32 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_CCC_32 << EXPONENT_BITS_P_CCC_32; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_P_CCC_32 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_P_CCC_32 << EXPONENT_BITS_P_CCC_32; // Fill the left with ones
    }

    int8_t msb_b = get_msb_index(sig_b);
    log_debug_p_adic("msb_b", msb_b);

    // Normalize denominator
    if (msb_b > 0) {
        sig_b >>= msb_b;
        exp_b += msb_b;
    }

    // Check for division by zero
    if (sig_b == 0U) {
        if (posi_a) {
            // Return max value as "infinity"
            return (((1U << (EXPONENT_BITS_P_CCC_32 - 2)) - 1) << SIGNIFICAND_BITS_P_CCC_32)
                   | ((1U << (SIGNIFICAND_BITS_P_CCC_32 - 2)) - 1);
        } else {
            // Return min value as "-infinity"
            return (((1U << (EXPONENT_BITS_P_CCC_32 - 2)) - 1) << SIGNIFICAND_BITS_P_CCC_32)
                   | (SIGNIFICAND_SIGN_MASK_P_CCC_32);
        }
    }

    // Adjust exponent
    uint32_t result_exp = exp_a - exp_b;

    // Perform division
    uint32_t result_sig = 0U;

    uint32_t carry = 0U;
    uint32_t mask_r = 1U;
    let((sig_b | 1U) != 0U);
    for (int8_t i = 0; i < SIGNIFICAND_BITS_P_CCC_32; i++) {
        uint32_t mask_j = 2U;
        if (i > 0) {
            mask_r = 1U << (i - 1);
        }

        for (int8_t j = 0; j < i; j++) {
            carry += ((result_sig & mask_r) >> (i - j - 1)) * ((sig_b & mask_j) >> (j + 1));
            mask_j <<= 1;
            mask_r >>= 1;
        }
        uint32_t carry_0 = (carry & 1U) << i;
        uint32_t sig_a_i = sig_a & (1U << i);
        if (carry_0 > 0) {
            result_sig += carry_0 - sig_a_i;
        } else {
            result_sig += sig_a & (1U << i);
        }
        carry >>= 1;
    }


    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_p_adic("result significand", result_sig );
    }

    return new_pDDD32(result_exp, result_sig);
}

bool equ_pDDD32(pDDD32_t a, pDDD32_t b) {
    return a == b;
}

int com_pDDD32(pDDD32_t a, pDDD32_t b) {
    if (a == b) return 0;

    int32_t exp_a = (a & EXPONENT_MASK_P_CCC_32) >> SIGNIFICAND_BITS_P_CCC_32;
    int32_t exp_b = (b & EXPONENT_MASK_P_CCC_32) >> SIGNIFICAND_BITS_P_CCC_32;
    int32_t sig_a = a & SIGNIFICAND_MASK_P_CCC_32;
    int32_t sig_b = b & SIGNIFICAND_MASK_P_CCC_32;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}

