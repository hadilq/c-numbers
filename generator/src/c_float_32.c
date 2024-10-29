#include "c_float_32.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void log_debug_label(const char* label) {
    if (C_FLOAT_CCC_32_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_float(const char* label, int32_t f) {
    if (C_FLOAT_CCC_32_DEBUG) {
        printf("%s: %d, 0x%x\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_FLOAT_CCC_32_DEBUG) {
        assert(false);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index_positive(uint32_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint32_t copy = n & SIGNIFICAND_MASK_F_CCC_32;
    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_CCC_32; i++) {
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

    uint64_t copy = n & SIGNIFICAND_2_MASK_F_CCC_32;
    for (uint8_t i = 1; i <= 2 * SIGNIFICAND_BITS_F_CCC_32; i++) {
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
    uint32_t copy = ~n & SIGNIFICAND_MASK_F_CCC_32;
    if (copy == 0) return 0; // Handle -1 as a special case

    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_CCC_32; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// construct float DDD32
fDDD32_t new_fDDD32(uint32_t exp, uint32_t sig) {
    return (exp << SIGNIFICAND_BITS_F_CCC_32) | (sig & SIGNIFICAND_MASK_F_CCC_32);
}

// exponent part of float DDD32
uint32_t exp_fDDD32(fDDD32_t a) {
    uint32_t exp_a = (a & EXPONENT_MASK_F_CCC_32) >> SIGNIFICAND_BITS_F_CCC_32;

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_CCC_32 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_CCC_32 << EXPONENT_BITS_F_CCC_32; // Fill the left with ones
    }
    return exp_a;
}

// significand part of float DDD32
uint32_t sig_fDDD32(fDDD32_t a) {
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_CCC_32;

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_CCC_32 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_CCC_32;
    }
    return sig_a;
}

// add float DDD32
fDDD32_t add_fDDD32(fDDD32_t a, fDDD32_t b) {
    // Extract exponent and significand
    int32_t exp_a = (a & EXPONENT_MASK_F_CCC_32) >> SIGNIFICAND_BITS_F_CCC_32;
    int32_t exp_b = (b & EXPONENT_MASK_F_CCC_32) >> SIGNIFICAND_BITS_F_CCC_32;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_CCC_32;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_CCC_32;
    uint32_t result_exp = exp_a;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_CCC_32 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_CCC_32;
        posi_a = false;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_CCC_32 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_CCC_32;
        posi_b = false;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_CCC_32 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_CCC_32 << EXPONENT_BITS_F_CCC_32; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_CCC_32 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_CCC_32 << EXPONENT_BITS_F_CCC_32; // Fill the left with ones
    }

    // Align significands and handle negatives
    if (exp_a > exp_b) {
        uint8_t diff = exp_a - exp_b;
        sig_b >>= diff;
        if (!posi_b) {
            sig_b |= ((1U << diff) - 1) << (BITS_F_CCC_32 - diff); // Fill the left with ones
            if ((sig_b & SIGNIFICAND_MASK_F_CCC_32) == SIGNIFICAND_MASK_F_CCC_32) {
                sig_b = 0;
            }
        }
        log_debug_float("diff 'exp_a > exp_b' is", diff);
        result_exp = exp_a;
    } else if (exp_b > exp_a) {
        uint8_t diff = exp_b - exp_a;
        sig_a >>= diff;
        if (!posi_a) {
            sig_a |= ((1U << diff) - 1) << (BITS_F_CCC_32 - diff); // Fill the left with ones
            if ((sig_a & SIGNIFICAND_MASK_F_CCC_32) == SIGNIFICAND_MASK_F_CCC_32) {
                sig_a = 0;
            }
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

    if (BITS_SIGN_MASK_F_CCC_32 & result_sig) {
       posi_result = false;
    }

    int8_t msb;
    if (posi_result) {
        msb = get_msb_index_positive(result_sig);
    } else {
        msb = get_msb_index_negative(result_sig);
    }
    msb -= SIGNIFICAND_BITS_F_CCC_32 - 1;
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
    return new_fDDD32(result_exp, result_sig);
}

fDDD32_t sub_fDDD32(fDDD32_t a, fDDD32_t b) {
    return add_fDDD32(a, neg_fDDD32(b));
}

fDDD32_t neg_fDDD32(fDDD32_t b) {
    // Negate b and add
    uint32_t exp_b = b & EXPONENT_MASK_F_CCC_32;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_CCC_32;

    // Flip all bits of significand for two's complement
    if ((SIGNIFICAND_SIGN_MASK_F_CCC_32 & sig_b)) {
        // negative
        sig_b = (~sig_b + 1) & SIGNIFICAND_MASK_F_CCC_32;
    } else {
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_CCC_32;
    }

    return exp_b | sig_b;
}

fDDD32_t mul_fDDD32(fDDD32_t a, fDDD32_t b) {
    uint32_t exp_a = (a & EXPONENT_MASK_F_CCC_32) >> SIGNIFICAND_BITS_F_CCC_32;
    uint32_t exp_b = (b & EXPONENT_MASK_F_CCC_32) >> SIGNIFICAND_BITS_F_CCC_32;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_CCC_32;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_CCC_32;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_CCC_32 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_CCC_32;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_CCC_32;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_CCC_32 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_CCC_32;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_CCC_32;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_CCC_32 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_CCC_32 << EXPONENT_BITS_F_CCC_32; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_CCC_32 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_CCC_32 << EXPONENT_BITS_F_CCC_32; // Fill the left with ones
    }

    // Multiply significands
    uint64_t temp_sig = (uint64_t)sig_a * sig_b;
    log_debug_float("result significand", temp_sig);

    // Adjust exponent
    uint32_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_64(temp_sig);
    msb -= SIGNIFICAND_BITS_F_CCC_32 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint32_t result_sig = (uint32_t)temp_sig & SIGNIFICAND_MASK_F_CCC_32;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    } else if (msb < 0) {
        result_sig = temp_sig << abs(msb);
    }
    result_exp += msb - SIGNIFICAND_BITS_F_CCC_32 + 1;
    log_debug_float("result significand", result_sig);
    log_debug_float("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_float("result significand", result_sig);
    }

    return new_fDDD32(result_exp, result_sig);
}

fDDD32_t div_fDDD32(fDDD32_t a, fDDD32_t b) {
    uint32_t exp_a = (a & EXPONENT_MASK_F_CCC_32) >> SIGNIFICAND_BITS_F_CCC_32;
    uint32_t exp_b = (b & EXPONENT_MASK_F_CCC_32) >> SIGNIFICAND_BITS_F_CCC_32;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_CCC_32;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_CCC_32;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_CCC_32 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_CCC_32;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_CCC_32;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_CCC_32 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_CCC_32;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_CCC_32;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_CCC_32 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_CCC_32 << EXPONENT_BITS_F_CCC_32; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_CCC_32 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_CCC_32 << EXPONENT_BITS_F_CCC_32; // Fill the left with ones
    }

    // Check for division by zero
    if (sig_b == 0U) {
        if (posi_a) {
            // Return max value as "infinity"
            return (((1U << (EXPONENT_BITS_F_CCC_32 - 2)) - 1) << SIGNIFICAND_BITS_F_CCC_32)
                   | ((1U << (SIGNIFICAND_BITS_F_CCC_32 - 2)) - 1);
        } else {
            // Return min value as "-infinity"
            return (((1U << (EXPONENT_BITS_F_CCC_32 - 2)) - 1) << SIGNIFICAND_BITS_F_CCC_32)
                   | (SIGNIFICAND_SIGN_MASK_F_CCC_32);
        }
    }

    // Perform division
    uint64_t temp_sig = ((uint64_t)sig_a << SIGNIFICAND_BITS_F_CCC_32) / sig_b;

    // Adjust exponent
    uint32_t result_exp = exp_a - exp_b;

    int8_t msb = get_msb_index_64(temp_sig);
    msb -= SIGNIFICAND_BITS_F_CCC_32 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint32_t result_sig = (uint32_t)temp_sig & SIGNIFICAND_MASK_F_CCC_32;
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

    return new_fDDD32(result_exp, result_sig);
}

bool equ_fDDD32(fDDD32_t a, fDDD32_t b) {
    return a == b;
}

int com_fDDD32(fDDD32_t a, fDDD32_t b) {
    if (a == b) return 0;

    int32_t exp_a = (a & EXPONENT_MASK_F_CCC_32) >> SIGNIFICAND_BITS_F_CCC_32;
    int32_t exp_b = (b & EXPONENT_MASK_F_CCC_32) >> SIGNIFICAND_BITS_F_CCC_32;
    int32_t sig_a = a & SIGNIFICAND_MASK_F_CCC_32;
    int32_t sig_b = b & SIGNIFICAND_MASK_F_CCC_32;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}

