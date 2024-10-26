#include "c_float_26_06.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void log_debug_label(const char* label) {
    if (C_FLOAT_26_06_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_float(const char* label, uint32_t f) {
    if (C_FLOAT_26_06_DEBUG) {
        printf("%s: %d, 0x%x\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_FLOAT_26_06_DEBUG) {
        assert(false);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index_positive(uint32_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint32_t copy = n;
    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_26_06; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for positive numbers for 64 digit numbers
static uint8_t get_msb_index_64(uint64_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    __uint64_t copy = n;
    for (uint8_t i = 1; i <= 2 * SIGNIFICAND_BITS_F_26_06; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for negative numbers
static uint8_t get_msb_index_negative(uint32_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint32_t copy = n;
    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_26_06; i++) {
        copy >>= 1;
        if (~copy == 0) {
            return i;
        }
    }

    if (C_FLOAT_26_06_DEBUG) {
        assert(false);
    }
    return 0; // This line should never be reached for non-zero input
}

// construct float 57 07
f2606_t new_f2606(uint32_t exp, uint32_t sig) {
    return (exp << SIGNIFICAND_BITS_F_26_06) | (sig & SIGNIFICAND_MASK_F_26_06);
}

// exponent part of float 57 07
uint32_t exp_f2606(f2606_t a) {
    uint32_t exp_a = (a & EXPONENT_MASK_F_26_06) >> SIGNIFICAND_BITS_F_26_06;

    // Handle negatives exponents
    if ((1U << (EXPONENT_BITS_F_26_06 - 1) & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_26_06 << EXPONENT_BITS_F_26_06; // Fill the left with ones
    }
    return exp_a;
}

// significand part of float 57 07
uint32_t sig_f2606(f2606_t a) {
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_26_06;

    // Handle negative numbers
    if ((1U << (SIGNIFICAND_BITS_F_26_06 - 1) & sig_a)) {
        sig_a |= EXPONENT_MASK_F_26_06;
    }
    return sig_a;
}

// add float 57 07
f2606_t add_f2606(f2606_t a, f2606_t b) {
    // Extract exponent and significand
    uint32_t exp_a = (a & EXPONENT_MASK_F_26_06) >> SIGNIFICAND_BITS_F_26_06;
    uint32_t exp_b = (b & EXPONENT_MASK_F_26_06) >> SIGNIFICAND_BITS_F_26_06;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_26_06;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_26_06;
    uint32_t result_exp = exp_a;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((1U << (SIGNIFICAND_BITS_F_26_06 - 1) & sig_a)) {
        sig_a |= EXPONENT_MASK_F_26_06;
        posi_a = false;
        log_debug_label("a is negative");
    }
    if ((1U << (SIGNIFICAND_BITS_F_26_06 - 1) & sig_b)) {
        sig_b |= EXPONENT_MASK_F_26_06;
        posi_b = false;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((1U << (EXPONENT_BITS_F_26_06 - 1) & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_26_06 << EXPONENT_BITS_F_26_06; // Fill the left with ones
    }
    if ((1U << (EXPONENT_BITS_F_26_06 - 1) & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_26_06 << EXPONENT_BITS_F_26_06; // Fill the left with ones
    }

    // Align significands and handle negatives
    if (exp_a > exp_b) {
        uint8_t diff = exp_a - exp_b;
        sig_b >>= diff;
        if (!posi_b) {
            sig_b |= ((1U << diff) - 1) << (BITS_F_26_06 - diff); // Fill the left with ones
        }
        log_debug_float("diff 'exp_a > exp_b' is", diff);
        result_exp = exp_a;
    } else if (exp_b > exp_a) {
        uint8_t diff = exp_b - exp_a;
        sig_a >>= diff;
        if (!posi_a) {
            sig_a |= ((1U << diff) - 1) << (BITS_F_26_06 - diff); // Fill the left with ones
        }
        log_debug_float("diff 'exp_b > exp_a' is", diff);
        result_exp = exp_b;
    }

    // Add significands
    uint32_t result_sig = sig_a + sig_b;
    bool posi_result = true;

    // Check for zero
    if (result_sig == 0) {
        return 0U;
    }

    log_debug_float("result significand", result_sig);
    log_debug_float("result exponent", result_exp);

    if (1U << (BITS_F_26_06 - 1) & result_sig) {
       posi_result = false;
    }

    int8_t msb = SIGNIFICAND_BITS_F_26_06 - 1;
    if (posi_result) {
        msb = get_msb_index_positive(result_sig);
    } else {
        msb = get_msb_index_negative(result_sig);
    }
    msb -= SIGNIFICAND_BITS_F_26_06 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    if (msb > 0) {
        result_sig >>= msb;
        result_exp += msb;
    } else if (msb < 0) {
        result_sig <<= abs(msb);
        result_exp += msb;
    }

    // Assemble result
    return new_f2606(result_exp, result_sig);
}

f2606_t sub_f2606(f2606_t a, f2606_t b) {
    return add_f2606(a, neg_f2606(b));
}

f2606_t neg_f2606(f2606_t b) {
    // Negate b and add
    uint32_t exp_b = b & EXPONENT_MASK_F_26_06;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_26_06;

    // Flip all bits of significand for two's complement
    if ((1ULL << (SIGNIFICAND_BITS_F_26_06 - 1) & sig_b)) {
        // negative
        sig_b = (~sig_b + 1) & SIGNIFICAND_MASK_F_26_06;
    } else {
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_26_06;
    }

    return exp_b | sig_b;
}

f2606_t mul_f2606(f2606_t a, f2606_t b) {
    uint32_t exp_a = (a & EXPONENT_MASK_F_26_06) >> SIGNIFICAND_BITS_F_26_06;
    uint32_t exp_b = (b & EXPONENT_MASK_F_26_06) >> SIGNIFICAND_BITS_F_26_06;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_26_06;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_26_06;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((1U << (SIGNIFICAND_BITS_F_26_06 - 1) & sig_a)) {
        sig_a |= EXPONENT_MASK_F_26_06;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_26_06;
        log_debug_label("a is negative");
    }
    if ((1U << (SIGNIFICAND_BITS_F_26_06 - 1) & sig_b)) {
        sig_b |= EXPONENT_MASK_F_26_06;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_26_06;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((1U << (EXPONENT_BITS_F_26_06 - 1) & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_26_06 << EXPONENT_BITS_F_26_06; // Fill the left with ones
    }
    if ((1U << (EXPONENT_BITS_F_26_06 - 1) & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_26_06 << EXPONENT_BITS_F_26_06; // Fill the left with ones
    }

    // Multiply significands
    uint64_t temp_sig = (__uint64_t)sig_a * sig_b;
    log_debug_float("result significand", temp_sig);

    // Adjust exponent
    uint32_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_64(temp_sig);
    msb -= SIGNIFICAND_BITS_F_26_06 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint32_t result_sig = (uint32_t)temp_sig & SIGNIFICAND_MASK_F_26_06;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    } else if (msb < 0) {
        result_sig = temp_sig << abs(msb);
    }
    result_exp += msb - SIGNIFICAND_BITS_F_26_06 + 1;
    log_debug_float("result significand", result_sig);
    log_debug_float("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_float("result significand", result_sig);
    }

    return new_f2606(result_exp, result_sig);
}

f2606_t div_f2606(f2606_t a, f2606_t b) {
    uint32_t exp_a = (a & EXPONENT_MASK_F_26_06) >> SIGNIFICAND_BITS_F_26_06;
    uint32_t exp_b = (b & EXPONENT_MASK_F_26_06) >> SIGNIFICAND_BITS_F_26_06;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_26_06;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_26_06;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((1U << (SIGNIFICAND_BITS_F_26_06 - 1) & sig_a)) {
        sig_a |= EXPONENT_MASK_F_26_06;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_26_06;
        log_debug_label("a is negative");
    }
    if ((1U << (SIGNIFICAND_BITS_F_26_06 - 1) & sig_b)) {
        sig_b |= EXPONENT_MASK_F_26_06;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_26_06;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((1U << (EXPONENT_BITS_F_26_06 - 1) & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_26_06 << EXPONENT_BITS_F_26_06; // Fill the left with ones
    }
    if ((1U << (EXPONENT_BITS_F_26_06 - 1) & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_26_06 << EXPONENT_BITS_F_26_06; // Fill the left with ones
    }

    // Check for division by zero
    if (sig_b == 0U) {
        if (posi_a) {
            return (((1U << (EXPONENT_BITS_F_26_06 - 2)) - 1) << SIGNIFICAND_BITS_F_26_06) | ((1U << (SIGNIFICAND_BITS_F_26_06 - 2)) - 1); // Return max value as "infinity"
        } else {
            return (((1U << (EXPONENT_BITS_F_26_06 - 2)) - 1) << SIGNIFICAND_BITS_F_26_06) | (1U << (SIGNIFICAND_BITS_F_26_06 - 1)); // Return min value as "-infinity"
        }
    }

    // Perform division
    uint64_t temp_sig = ((__uint64_t)sig_a << SIGNIFICAND_BITS_F_26_06) / sig_b;

    // Adjust exponent
    uint32_t result_exp = exp_a - exp_b;

    int8_t msb = get_msb_index_64(temp_sig);
    msb -= SIGNIFICAND_BITS_F_26_06 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint32_t result_sig = (uint32_t)temp_sig & SIGNIFICAND_MASK_F_26_06;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    } else if (msb < 0) {
        result_sig = temp_sig << abs(msb);
    }
    result_exp += msb - 1;
    log_debug_float("result significand", result_sig);
    log_debug_float("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_float("result significand", result_sig );
    }

    return new_f2606(result_exp, result_sig);
}

bool equ_f2606(f2606_t a, f2606_t b) {
    return a == b;
}

int com_f2606(f2606_t a, f2606_t b) {
    if (a == b) return 0;

    uint32_t exp_a = (a & EXPONENT_MASK_F_26_06) >> SIGNIFICAND_BITS_F_26_06;
    uint32_t exp_b = (b & EXPONENT_MASK_F_26_06) >> SIGNIFICAND_BITS_F_26_06;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_26_06;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_26_06;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}

