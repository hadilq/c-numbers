#include "c_p_adic_57_07.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#define _GNU_SOURCE

static void log_debug_label(const char* label) {
    if (C_P_ADIC_57_07_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_p_adic(const char* label, uint64_t f) {
    if (C_P_ADIC_57_07_DEBUG) {
        printf("%s: %ld, 0x%lx\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_P_ADIC_57_07_DEBUG) {
        assert(false);
    }
}

static void let(bool assumption) {
    if (C_P_ADIC_57_07_DEBUG) {
        assert(assumption);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index(uint64_t n) {
    if (n == 0) return SIGNIFICAND_BITS_P_57_07 - 1; // Handle 0 as a special case

    uint64_t copy = n << EXPONENT_BITS_P_57_07;
    for (uint8_t i = SIGNIFICAND_BITS_P_57_07 - 1; i >= 0; i--) {
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

    __uint128_t copy = n << (2 * EXPONENT_BITS_P_57_07);
    if (copy == 0ULL) return 0; // Handle 0 as a special case
    for (uint8_t i = 2 * SIGNIFICAND_BITS_P_57_07 - 1; i >= 0; i--) {
        copy <<= 1;
        if (copy == 0ULL) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// construct p-adic 57 07
p5707_t new_p5707(uint64_t exp, uint64_t sig) {
    return (exp << SIGNIFICAND_BITS_P_57_07) | (sig & SIGNIFICAND_MASK_P_57_07);
}

// exponent part of p-adic 57 07
uint64_t exp_p5707(p5707_t a) {
    uint64_t exp_a = (a & EXPONENT_MASK_P_57_07) >> SIGNIFICAND_BITS_P_57_07;

    // Handle negatives exponents
    if ((1ULL << (EXPONENT_BITS_P_57_07 - 1) & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_57_07 << EXPONENT_BITS_P_57_07; // Fill the left with ones
    }
    return exp_a;
}

// significand part of p-adic 57 07
uint64_t sig_p5707(p5707_t a) {
    uint64_t sig_a = a & SIGNIFICAND_MASK_P_57_07;

    // Handle negative numbers
    if ((1ULL << (SIGNIFICAND_BITS_P_57_07 - 1) & sig_a)) {
        sig_a |= EXPONENT_MASK_P_57_07;
    }
    return sig_a;
}

// add p-adic 57 07
p5707_t add_p5707(p5707_t a, p5707_t b) {
    // Extract exponent and significand
    uint64_t exp_a = (a & EXPONENT_MASK_P_57_07) >> SIGNIFICAND_BITS_P_57_07;
    uint64_t exp_b = (b & EXPONENT_MASK_P_57_07) >> SIGNIFICAND_BITS_P_57_07;
    uint64_t sig_a = a & SIGNIFICAND_MASK_P_57_07;
    uint64_t sig_b = b & SIGNIFICAND_MASK_P_57_07;
    uint64_t result_exp = exp_a;
    log_debug_p_adic("exp_a", exp_a);
    log_debug_p_adic("exp_b", exp_b);
    log_debug_p_adic("sig_a", sig_a);
    log_debug_p_adic("sig_b", sig_b);

    // Handle negative numbers
    if ((1ULL << (SIGNIFICAND_BITS_P_57_07 - 1) & sig_a)) {
        sig_a |= EXPONENT_MASK_P_57_07;
        log_debug_label("a is negative");
    }
    if ((1ULL << (SIGNIFICAND_BITS_P_57_07 - 1) & sig_b)) {
        sig_b |= EXPONENT_MASK_P_57_07;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((1ULL << (EXPONENT_BITS_P_57_07 - 1) & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_57_07 << EXPONENT_BITS_P_57_07; // Fill the left with ones
    }
    if ((1ULL << (EXPONENT_BITS_P_57_07 - 1) & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_P_57_07 << EXPONENT_BITS_P_57_07; // Fill the left with ones
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
    return new_p5707(result_exp, result_sig);
}

p5707_t sub_p5707(p5707_t a, p5707_t b) {
    return add_p5707(a, neg_p5707(b));
}

p5707_t neg_p5707(p5707_t b) {
    // Negate b and add
    uint64_t exp_b = b & EXPONENT_MASK_P_57_07;
    uint64_t sig_b = b & SIGNIFICAND_MASK_P_57_07;

    // Flip all bits of significand for two's complement
    sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_P_57_07;

    return exp_b | sig_b;
}

p5707_t mul_p5707(p5707_t a, p5707_t b) {
    uint64_t exp_a = (a & EXPONENT_MASK_P_57_07) >> SIGNIFICAND_BITS_P_57_07;
    uint64_t exp_b = (b & EXPONENT_MASK_P_57_07) >> SIGNIFICAND_BITS_P_57_07;
    uint64_t sig_a = a & SIGNIFICAND_MASK_P_57_07;
    uint64_t sig_b = b & SIGNIFICAND_MASK_P_57_07;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_p_adic("exp_a", exp_a);
    log_debug_p_adic("exp_b", exp_b);
    log_debug_p_adic("sig_a", sig_a);
    log_debug_p_adic("sig_b", sig_b);

    // Handle negative numbers
    if ((1ULL << (SIGNIFICAND_BITS_P_57_07 - 1) & sig_a)) {
        sig_a |= EXPONENT_MASK_P_57_07;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_P_57_07;
        log_debug_label("a is negative");
    }
    if ((1ULL << (SIGNIFICAND_BITS_P_57_07 - 1) & sig_b)) {
        sig_b |= EXPONENT_MASK_P_57_07;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_P_57_07;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((1ULL << (EXPONENT_BITS_P_57_07 - 1) & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_57_07 << EXPONENT_BITS_P_57_07; // Fill the left with ones
    }
    if ((1ULL << (EXPONENT_BITS_P_57_07 - 1) & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_P_57_07 << EXPONENT_BITS_P_57_07; // Fill the left with ones
    }

    // Multiply significands
    __uint128_t temp_sig = (__uint128_t)sig_a * sig_b;
    log_debug_p_adic("result significand", temp_sig);

    // Adjust exponent
    uint64_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_128(temp_sig);
    log_debug_p_adic("msb", msb);

    // Normalize result
    uint64_t result_sig = (uint64_t)temp_sig & SIGNIFICAND_MASK_P_57_07;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    }
    log_debug_p_adic("result significand", result_sig);
    log_debug_p_adic("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_p_adic("result significand", result_sig);
    }

    return new_p5707(result_exp, result_sig);
}

p5707_t div_p5707(p5707_t a, p5707_t b) {
    uint64_t exp_a = (a & EXPONENT_MASK_P_57_07) >> SIGNIFICAND_BITS_P_57_07;
    uint64_t exp_b = (b & EXPONENT_MASK_P_57_07) >> SIGNIFICAND_BITS_P_57_07;
    uint64_t sig_a = a & SIGNIFICAND_MASK_P_57_07;
    uint64_t sig_b = b & SIGNIFICAND_MASK_P_57_07;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_p_adic("exp_a", exp_a);
    log_debug_p_adic("exp_b", exp_b);
    log_debug_p_adic("sig_a", sig_a);
    log_debug_p_adic("sig_b", sig_b);

    // Handle negative numbers
    if ((1ULL << (SIGNIFICAND_BITS_P_57_07 - 1) & sig_a)) {
        sig_a |= EXPONENT_MASK_P_57_07;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_P_57_07;
        log_debug_label("a is negative");
    }
    if ((1ULL << (SIGNIFICAND_BITS_P_57_07 - 1) & sig_b)) {
        sig_b |= EXPONENT_MASK_P_57_07;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_P_57_07;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((1ULL << (EXPONENT_BITS_P_57_07 - 1) & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_P_57_07 << EXPONENT_BITS_P_57_07; // Fill the left with ones
    }
    if ((1ULL << (EXPONENT_BITS_P_57_07 - 1) & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_P_57_07 << EXPONENT_BITS_P_57_07; // Fill the left with ones
    }

    // Check for division by zero
    if (sig_b == 0) {
        if (posi_a) {
            return (((1ULL << (EXPONENT_BITS_P_57_07 - 1)) - 1) << SIGNIFICAND_BITS_P_57_07) | ((1ULL << (SIGNIFICAND_BITS_P_57_07 - 2)) - 1); // Return max value as "infinity"
        } else {
            return (((1ULL << (EXPONENT_BITS_P_57_07 - 1)) - 1) << SIGNIFICAND_BITS_P_57_07) | (1ULL << (SIGNIFICAND_BITS_P_57_07 - 1)); // Return min value as "-infinity"
        }
    }

    // Perform division
    __uint128_t temp_sig = ((__uint128_t)sig_a << SIGNIFICAND_BITS_P_57_07) / sig_b;
    log_debug_p_adic("result significand", temp_sig);

    // Adjust exponent
    uint64_t result_exp = exp_a - exp_b;

    int8_t msb = get_msb_index_128(temp_sig);
    log_debug_p_adic("msb", msb);

    // Normalize result
    uint64_t result_sig = (uint64_t)temp_sig & SIGNIFICAND_MASK_P_57_07;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    }
    log_debug_p_adic("result significand", result_sig);
    log_debug_p_adic("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_p_adic("result significand", result_sig );
    }

    return new_p5707(result_exp, result_sig);
}

bool equ_p5707(p5707_t a, p5707_t b) {
    return a == b;
}

int com_p5707(p5707_t a, p5707_t b) {
    if (a == b) return 0;

    uint64_t exp_a = (a & EXPONENT_MASK_P_57_07) >> SIGNIFICAND_BITS_P_57_07;
    uint64_t exp_b = (b & EXPONENT_MASK_P_57_07) >> SIGNIFICAND_BITS_P_57_07;
    uint64_t sig_a = a & SIGNIFICAND_MASK_P_57_07;
    uint64_t sig_b = b & SIGNIFICAND_MASK_P_57_07;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}
