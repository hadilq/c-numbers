#include "c_float_45_19.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void log_debug_label(const char* label) {
    if (C_FLOAT_45_19_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_float(const char* label, int64_t f) {
    if (C_FLOAT_45_19_DEBUG) {
        printf("%s: %ld, 0x%lx\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_FLOAT_45_19_DEBUG) {
        assert(false);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index_positive(uint64_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint64_t copy = n & SIGNIFICAND_MASK_F_45_19;
    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_45_19; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for positive numbers for 128 digit numbers
static uint8_t get_msb_index_128(__uint128_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    __uint128_t copy = n & SIGNIFICAND_2_MASK_F_45_19;
    for (uint8_t i = 1; i <= 2 * SIGNIFICAND_BITS_F_45_19; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for negative numbers
static uint8_t get_msb_index_negative(uint64_t n) {
    uint64_t copy = ~n & SIGNIFICAND_MASK_F_45_19;
    if (copy == 0) return 0; // Handle -1 as a special case

    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_45_19; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// construct float 4519
f4519_t new_f4519(uint64_t exp, uint64_t sig) {
    return (exp << SIGNIFICAND_BITS_F_45_19) | (sig & SIGNIFICAND_MASK_F_45_19);
}

// exponent part of float 4519
uint64_t exp_f4519(f4519_t a) {
    uint64_t exp_a = (a & EXPONENT_MASK_F_45_19) >> SIGNIFICAND_BITS_F_45_19;

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_45_19 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_45_19 << EXPONENT_BITS_F_45_19; // Fill the left with ones
    }
    return exp_a;
}

// significand part of float 4519
uint64_t sig_f4519(f4519_t a) {
    uint64_t sig_a = a & SIGNIFICAND_MASK_F_45_19;

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_45_19 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_45_19;
    }
    return sig_a;
}

// add float 4519
f4519_t add_f4519(f4519_t a, f4519_t b) {
    // Extract exponent and significand
    int64_t exp_a = (a & EXPONENT_MASK_F_45_19) >> SIGNIFICAND_BITS_F_45_19;
    int64_t exp_b = (b & EXPONENT_MASK_F_45_19) >> SIGNIFICAND_BITS_F_45_19;
    uint64_t sig_a = a & SIGNIFICAND_MASK_F_45_19;
    uint64_t sig_b = b & SIGNIFICAND_MASK_F_45_19;
    uint64_t result_exp = exp_a;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_45_19 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_45_19;
        posi_a = false;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_45_19 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_45_19;
        posi_b = false;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_45_19 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_45_19 << EXPONENT_BITS_F_45_19; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_45_19 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_45_19 << EXPONENT_BITS_F_45_19; // Fill the left with ones
    }

    // Align significands and handle negatives
    if (exp_a > exp_b) {
        uint8_t diff = exp_a - exp_b;
        sig_b >>= diff;
        if (!posi_b) {
            sig_b |= ((1ULL << diff) - 1) << (BITS_F_45_19 - diff); // Fill the left with ones
            if ((sig_b & SIGNIFICAND_MASK_F_45_19) == SIGNIFICAND_MASK_F_45_19) {
                sig_b = 0;
            }
        }
        log_debug_float("diff 'exp_a > exp_b' is", diff);
        result_exp = exp_a;
    } else if (exp_b > exp_a) {
        uint8_t diff = exp_b - exp_a;
        sig_a >>= diff;
        if (!posi_a) {
            sig_a |= ((1ULL << diff) - 1) << (BITS_F_45_19 - diff); // Fill the left with ones
            if ((sig_a & SIGNIFICAND_MASK_F_45_19) == SIGNIFICAND_MASK_F_45_19) {
                sig_a = 0;
            }
        }
        log_debug_float("diff 'exp_b > exp_a' is", diff);
        result_exp = exp_b;
    }

    // Add significands
    uint64_t result_sig = sig_a + sig_b;
    bool posi_result = true;

    // Check for zero
    if (result_sig == 0) {
        return 0ULL;
    }

    log_debug_float("result significand", result_sig);
    log_debug_float("result exponent", result_exp);

    if (BITS_SIGN_MASK_F_45_19 & result_sig) {
       posi_result = false;
    }

    int8_t msb;
    if (posi_result) {
        msb = get_msb_index_positive(result_sig);
    } else {
        msb = get_msb_index_negative(result_sig);
    }
    msb -= SIGNIFICAND_BITS_F_45_19 - 1;
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
    return new_f4519(result_exp, result_sig);
}

f4519_t sub_f4519(f4519_t a, f4519_t b) {
    return add_f4519(a, neg_f4519(b));
}

f4519_t neg_f4519(f4519_t b) {
    // Negate b and add
    uint64_t exp_b = b & EXPONENT_MASK_F_45_19;
    uint64_t sig_b = b & SIGNIFICAND_MASK_F_45_19;

    // Flip all bits of significand for two's complement
    if ((SIGNIFICAND_SIGN_MASK_F_45_19 & sig_b)) {
        // negative
        sig_b = (~sig_b + 1) & SIGNIFICAND_MASK_F_45_19;
    } else {
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_45_19;
    }

    return exp_b | sig_b;
}

f4519_t mul_f4519(f4519_t a, f4519_t b) {
    uint64_t exp_a = (a & EXPONENT_MASK_F_45_19) >> SIGNIFICAND_BITS_F_45_19;
    uint64_t exp_b = (b & EXPONENT_MASK_F_45_19) >> SIGNIFICAND_BITS_F_45_19;
    uint64_t sig_a = a & SIGNIFICAND_MASK_F_45_19;
    uint64_t sig_b = b & SIGNIFICAND_MASK_F_45_19;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_45_19 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_45_19;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_45_19;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_45_19 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_45_19;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_45_19;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_45_19 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_45_19 << EXPONENT_BITS_F_45_19; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_45_19 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_45_19 << EXPONENT_BITS_F_45_19; // Fill the left with ones
    }

    // Multiply significands
    __uint128_t temp_sig = (__uint128_t)sig_a * sig_b;
    log_debug_float("result significand", temp_sig);

    // Adjust exponent
    uint64_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_128(temp_sig);
    msb -= SIGNIFICAND_BITS_F_45_19 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint64_t result_sig = (uint64_t)temp_sig & SIGNIFICAND_MASK_F_45_19;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    } else if (msb < 0) {
        result_sig = temp_sig << abs(msb);
    }
    result_exp += msb - SIGNIFICAND_BITS_F_45_19 + 1;
    log_debug_float("result significand", result_sig);
    log_debug_float("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_float("result significand", result_sig);
    }

    return new_f4519(result_exp, result_sig);
}

f4519_t div_f4519(f4519_t a, f4519_t b) {
    uint64_t exp_a = (a & EXPONENT_MASK_F_45_19) >> SIGNIFICAND_BITS_F_45_19;
    uint64_t exp_b = (b & EXPONENT_MASK_F_45_19) >> SIGNIFICAND_BITS_F_45_19;
    uint64_t sig_a = a & SIGNIFICAND_MASK_F_45_19;
    uint64_t sig_b = b & SIGNIFICAND_MASK_F_45_19;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_45_19 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_45_19;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_45_19;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_45_19 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_45_19;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_45_19;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_45_19 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_45_19 << EXPONENT_BITS_F_45_19; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_45_19 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_45_19 << EXPONENT_BITS_F_45_19; // Fill the left with ones
    }

    // Check for division by zero
    if (sig_b == 0ULL) {
        if (posi_a) {
            // Return max value as "infinity"
            return (((1ULL << (EXPONENT_BITS_F_45_19 - 2)) - 1) << SIGNIFICAND_BITS_F_45_19)
                   | ((1ULL << (SIGNIFICAND_BITS_F_45_19 - 2)) - 1);
        } else {
            // Return min value as "-infinity"
            return (((1ULL << (EXPONENT_BITS_F_45_19 - 2)) - 1) << SIGNIFICAND_BITS_F_45_19)
                   | (SIGNIFICAND_SIGN_MASK_F_45_19);
        }
    }

    // Perform division
    __uint128_t temp_sig = ((__uint128_t)sig_a << SIGNIFICAND_BITS_F_45_19) / sig_b;

    // Adjust exponent
    uint64_t result_exp = exp_a - exp_b;

    int8_t msb = get_msb_index_128(temp_sig);
    msb -= SIGNIFICAND_BITS_F_45_19 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint64_t result_sig = (uint64_t)temp_sig & SIGNIFICAND_MASK_F_45_19;
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

    return new_f4519(result_exp, result_sig);
}

bool equ_f4519(f4519_t a, f4519_t b) {
    return a == b;
}

int com_f4519(f4519_t a, f4519_t b) {
    if (a == b) return 0;

    uint64_t exp_a = (a & EXPONENT_MASK_F_45_19) >> SIGNIFICAND_BITS_F_45_19;
    uint64_t exp_b = (b & EXPONENT_MASK_F_45_19) >> SIGNIFICAND_BITS_F_45_19;
    uint64_t sig_a = a & SIGNIFICAND_MASK_F_45_19;
    uint64_t sig_b = b & SIGNIFICAND_MASK_F_45_19;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}

