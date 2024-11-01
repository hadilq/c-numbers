#include "c_p_adic_45_19.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

static void log_debug_label(const char* label) {
    if (C_P_ADIC_45_19_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_p_adic(const char* label, uint64_t f) {
    if (C_P_ADIC_45_19_DEBUG) {
        printf("%s: %ld, 0x%lx\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_P_ADIC_45_19_DEBUG) {
        assert(false);
    }
}

static void let(bool assumption) {
    if (C_P_ADIC_45_19_DEBUG) {
        assert(assumption);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index(uint64_t n) {
    if (n == 0) return SIGNIFICAND_BITS_P_45_19 - 1; // Handle 0 as a special case

    uint64_t copy = n << EXPONENT_BITS_P_45_19;
    for (uint8_t i = SIGNIFICAND_BITS_P_45_19 - 1; i >= 0; i--) {
        copy <<= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for positive numbers for 128 digit numbers
static uint8_t get_msb_index_128(__uint128_t n) {
    if (n == 0ULL) return 0; // Handle 0 as a special case

    __uint128_t copy = n << (2 * EXPONENT_BITS_P_45_19);
    if (copy == 0ULL) return 0; // Handle 0 as a special case
    for (uint8_t i = 2 * SIGNIFICAND_BITS_P_45_19 - 1; i >= 0; i--) {
        copy <<= 1;
        if (copy == 0ULL) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// construct p-adic 4519
p4519_t new_p4519(int64_t exp, int64_t sig) {
    return (exp << SIGNIFICAND_BITS_P_45_19) | (sig & SIGNIFICAND_MASK_P_45_19);
}

// exponent part of p-adic 4519
int64_t exp_p4519(p4519_t a) {
    uint64_t exp_a = (a & EXPONENT_MASK_P_45_19) >> SIGNIFICAND_BITS_P_45_19;

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_P_45_19 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_45_19 << EXPONENT_BITS_P_45_19; // Fill the left with ones
    }
    return exp_a;
}

// significand part of p-adic 4519
int64_t sig_p4519(p4519_t a) {
    uint64_t sig_a = a & SIGNIFICAND_MASK_P_45_19;

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_P_45_19 & sig_a)) {
        sig_a |= EXPONENT_MASK_P_45_19;
    }
    return sig_a;
}

// add p-adic 4519
p4519_t add_p4519(p4519_t a, p4519_t b) {
    // Extract exponent and significand
    int64_t exp_a = (a & EXPONENT_MASK_P_45_19) >> SIGNIFICAND_BITS_P_45_19;
    int64_t exp_b = (b & EXPONENT_MASK_P_45_19) >> SIGNIFICAND_BITS_P_45_19;
    uint64_t sig_a = a & SIGNIFICAND_MASK_P_45_19;
    uint64_t sig_b = b & SIGNIFICAND_MASK_P_45_19;
    uint64_t result_exp = exp_a;
    log_debug_p_adic("exp_a", exp_a);
    log_debug_p_adic("exp_b", exp_b);
    log_debug_p_adic("sig_a", sig_a);
    log_debug_p_adic("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_P_45_19 & sig_a)) {
        sig_a |= EXPONENT_MASK_P_45_19;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_P_45_19 & sig_b)) {
        sig_b |= EXPONENT_MASK_P_45_19;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_P_45_19 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_45_19 << EXPONENT_BITS_P_45_19; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_P_45_19 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_P_45_19 << EXPONENT_BITS_P_45_19; // Fill the left with ones
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
    uint64_t result_sig = sig_a + sig_b;

    // Check for zero
    if (result_sig == 0) {
        return 0ULL;
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
    return new_p4519(result_exp, result_sig);
}

p4519_t sub_p4519(p4519_t a, p4519_t b) {
    return add_p4519(a, neg_p4519(b));
}

p4519_t neg_p4519(p4519_t b) {
    // Negate b and add
    uint64_t exp_b = b & EXPONENT_MASK_P_45_19;
    uint64_t sig_b = b & SIGNIFICAND_MASK_P_45_19;

    // Flip all bits of significand for two's complement
    if ((SIGNIFICAND_SIGN_MASK_P_45_19 & sig_b)) {
        // negative
        sig_b = (~sig_b + 1) & SIGNIFICAND_MASK_P_45_19;
    } else {
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_P_45_19;
    }

    return exp_b | sig_b;
}

p4519_t mul_p4519(p4519_t a, p4519_t b) {
    uint64_t exp_a = (a & EXPONENT_MASK_P_45_19) >> SIGNIFICAND_BITS_P_45_19;
    uint64_t exp_b = (b & EXPONENT_MASK_P_45_19) >> SIGNIFICAND_BITS_P_45_19;
    uint64_t sig_a = a & SIGNIFICAND_MASK_P_45_19;
    uint64_t sig_b = b & SIGNIFICAND_MASK_P_45_19;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_p_adic("exp_a", exp_a);
    log_debug_p_adic("exp_b", exp_b);
    log_debug_p_adic("sig_a", sig_a);
    log_debug_p_adic("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_P_45_19 & sig_a)) {
        sig_a |= EXPONENT_MASK_P_45_19;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_P_45_19;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_P_45_19 & sig_b)) {
        sig_b |= EXPONENT_MASK_P_45_19;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_P_45_19;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_P_45_19 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_45_19 << EXPONENT_BITS_P_45_19; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_P_45_19 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_P_45_19 << EXPONENT_BITS_P_45_19; // Fill the left with ones
    }

    // Multiply significands
    __uint128_t temp_sig = (__uint128_t)sig_a * sig_b;
    log_debug_p_adic("result significand", temp_sig);

    // Adjust exponent
    uint64_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_128(temp_sig);
    log_debug_p_adic("msb", msb);

    // Normalize result
    uint64_t result_sig = (uint64_t)temp_sig & SIGNIFICAND_MASK_P_45_19;
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

    return new_p4519(result_exp, result_sig);
}

p4519_t div_p4519(p4519_t a, p4519_t b) {
    uint64_t exp_a = (a & EXPONENT_MASK_P_45_19) >> SIGNIFICAND_BITS_P_45_19;
    uint64_t exp_b = (b & EXPONENT_MASK_P_45_19) >> SIGNIFICAND_BITS_P_45_19;
    uint64_t sig_a = a & SIGNIFICAND_MASK_P_45_19;
    uint64_t sig_b = b & SIGNIFICAND_MASK_P_45_19;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_p_adic("exp_a", exp_a);
    log_debug_p_adic("exp_b", exp_b);
    log_debug_p_adic("sig_a", sig_a);
    log_debug_p_adic("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_P_45_19 & sig_a)) {
        sig_a |= EXPONENT_MASK_P_45_19;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_P_45_19;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_P_45_19 & sig_b)) {
        sig_b |= EXPONENT_MASK_P_45_19;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_P_45_19;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_P_45_19 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_45_19 << EXPONENT_BITS_P_45_19; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_P_45_19 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_P_45_19 << EXPONENT_BITS_P_45_19; // Fill the left with ones
    }

    int8_t msb_b = get_msb_index(sig_b);
    log_debug_p_adic("msb_b", msb_b);

    // Normalize denominator
    if (msb_b > 0) {
        sig_b >>= msb_b;
        exp_b += msb_b;
    }

    // Check for division by zero
    if (sig_b == 0ULL) {
        if (posi_a) {
            // Return max value as "infinity"
            return MAX_VALUE_P_45_19;
        } else {
            // Return min value as "-infinity"
            return MIN_VALUE_P_45_19;
        }
    }

    // Adjust exponent
    uint64_t result_exp = exp_a - exp_b;

    // Perform division
    uint64_t result_sig = 0ULL;

    uint64_t carry = 0ULL;
    uint64_t mask_r = 1ULL;
    let((sig_b | 1ULL) != 0ULL);
    for (int8_t i = 0; i < SIGNIFICAND_BITS_P_45_19; i++) {
        uint64_t mask_j = 2ULL;
        if (i > 0) {
            mask_r = 1ULL << (i - 1);
        }

        for (int8_t j = 0; j < i; j++) {
            carry += ((result_sig & mask_r) >> (i - j - 1)) * ((sig_b & mask_j) >> (j + 1));
            mask_j <<= 1;
            mask_r >>= 1;
        }
        uint64_t carry_0 = (carry & 1ULL) << i;
        uint64_t sig_a_i = sig_a & (1ULL << i);
        if (carry_0 > 0) {
            result_sig += carry_0 - sig_a_i;
        } else {
            result_sig += sig_a & (1ULL << i);
        }
        carry >>= 1;
    }


    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_p_adic("result significand", result_sig );
    }

    return new_p4519(result_exp, result_sig);
}

bool equ_p4519(p4519_t a, p4519_t b) {
    return a == b;
}

int com_p4519(p4519_t a, p4519_t b) {
    if (a == b) return 0;

    int64_t exp_a = (a & EXPONENT_MASK_P_45_19) >> SIGNIFICAND_BITS_P_45_19;
    int64_t exp_b = (b & EXPONENT_MASK_P_45_19) >> SIGNIFICAND_BITS_P_45_19;
    int64_t sig_a = a & SIGNIFICAND_MASK_P_45_19;
    int64_t sig_b = b & SIGNIFICAND_MASK_P_45_19;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}

