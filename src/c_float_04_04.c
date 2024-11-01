#include "c_float_04_04.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void log_debug_label(const char* label) {
    if (C_FLOAT_04_04_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_float(const char* label, int8_t f) {
    if (C_FLOAT_04_04_DEBUG) {
        printf("%s: %d, 0x%x\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_FLOAT_04_04_DEBUG) {
        assert(false);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index_positive(uint8_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint8_t copy = n & SIGNIFICAND_MASK_F_04_04;
    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_04_04; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for positive numbers for 16 digit numbers
static uint8_t get_msb_index_16(uint16_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint16_t copy = n & SIGNIFICAND_2_MASK_F_04_04;
    for (uint8_t i = 1; i <= 2 * SIGNIFICAND_BITS_F_04_04; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for negative numbers
static uint8_t get_msb_index_negative(uint8_t n) {
    uint8_t copy = ~n & SIGNIFICAND_MASK_F_04_04;
    if (copy == 0) return 0; // Handle -1 as a special case

    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_04_04; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// construct float 0404
f0404_t new_f0404(int8_t exp, int8_t sig) {
    return (exp << SIGNIFICAND_BITS_F_04_04) | (sig & SIGNIFICAND_MASK_F_04_04);
}

// exponent part of float 0404
int8_t exp_f0404(f0404_t a) {
    uint8_t exp_a = (a & EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;

    // Handle negatives exponents
    if (EXPONENT_SIGN_MASK_F_04_04 & exp_a) {
        exp_a |= SIGNIFICAND_MASK_F_04_04 << EXPONENT_BITS_F_04_04; // Fill the left with ones
    }
    return exp_a;
}

// significand part of float 0404
int8_t sig_f0404(f0404_t a) {
    uint8_t sig_a = a & SIGNIFICAND_MASK_F_04_04;

    // Handle negative numbers
    if (SIGNIFICAND_SIGN_MASK_F_04_04 & sig_a) {
        sig_a |= EXPONENT_MASK_F_04_04;
    }
    return sig_a;
}

// add float 0404
f0404_t add_f0404(f0404_t a, f0404_t b) {
    // Extract exponent and significand
    int8_t exp_a = (a & EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;
    int8_t exp_b = (b & EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;
    uint8_t sig_a = a & SIGNIFICAND_MASK_F_04_04;
    uint8_t sig_b = b & SIGNIFICAND_MASK_F_04_04;
    uint8_t result_exp = exp_a;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if (SIGNIFICAND_SIGN_MASK_F_04_04 & sig_a) {
        sig_a |= EXPONENT_MASK_F_04_04;
        posi_a = false;
        log_debug_label("a is negative");
    }
    if (SIGNIFICAND_SIGN_MASK_F_04_04 & sig_b) {
        sig_b |= EXPONENT_MASK_F_04_04;
        posi_b = false;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if (EXPONENT_SIGN_MASK_F_04_04 & exp_a) {
        exp_a |= SIGNIFICAND_MASK_F_04_04 << EXPONENT_BITS_F_04_04; // Fill the left with ones
    }
    if (EXPONENT_SIGN_MASK_F_04_04 & exp_b) {
        exp_b |= SIGNIFICAND_MASK_F_04_04 << EXPONENT_BITS_F_04_04; // Fill the left with ones
    }

    // Align significands and handle negatives
    if (exp_a > exp_b) {
        uint8_t diff = exp_a - exp_b;
        sig_b >>= diff;
        if (!posi_b) {
            sig_b |= ((1U << diff) - 1) << (BITS_F_04_04 - diff); // Fill the left with ones
            if ((sig_b & SIGNIFICAND_MASK_F_04_04) == SIGNIFICAND_MASK_F_04_04) {
                sig_b = 0;
            }
        }
        log_debug_float("diff 'exp_a > exp_b' is", diff);
        result_exp = exp_a;
    } else if (exp_b > exp_a) {
        uint8_t diff = exp_b - exp_a;
        sig_a >>= diff;
        if (!posi_a) {
            sig_a |= ((1U << diff) - 1) << (BITS_F_04_04 - diff); // Fill the left with ones
            if ((sig_a & SIGNIFICAND_MASK_F_04_04) == SIGNIFICAND_MASK_F_04_04) {
                sig_a = 0;
            }
        }
        log_debug_float("diff 'exp_b > exp_a' is", diff);
        result_exp = exp_b;
    }

    // Add significands
    uint8_t result_sig = sig_a + sig_b;
    bool posi_result = true;

    // Check for zero
    if (result_sig == 0) {
        return 0U;
    }

    log_debug_float("result significand", result_sig);
    log_debug_float("result exponent", result_exp);

    if (BITS_SIGN_MASK_F_04_04 & result_sig) {
       posi_result = false;
    }

    int8_t msb;
    if (posi_result) {
        msb = get_msb_index_positive(result_sig);
    } else {
        msb = get_msb_index_negative(result_sig);
    }
    msb -= SIGNIFICAND_BITS_F_04_04 - 1;
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
    return new_f0404(result_exp, result_sig);
}

f0404_t sub_f0404(f0404_t a, f0404_t b) {
    return add_f0404(a, neg_f0404(b));
}

f0404_t neg_f0404(f0404_t b) {
    // Negate b and add
    uint8_t exp_b = b & EXPONENT_MASK_F_04_04;
    uint8_t sig_b = b & SIGNIFICAND_MASK_F_04_04;

    // Flip all bits of significand for two's complement
    if ((1ULL << (SIGNIFICAND_BITS_F_04_04 - 1) & sig_b)) {
        // negative
        sig_b = (~sig_b + 1) & SIGNIFICAND_MASK_F_04_04;
    } else {
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_04_04;
    }

    return exp_b | sig_b;
}

f0404_t mul_f0404(f0404_t a, f0404_t b) {
    uint8_t exp_a = (a & EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;
    uint8_t exp_b = (b & EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;
    uint8_t sig_a = a & SIGNIFICAND_MASK_F_04_04;
    uint8_t sig_b = b & SIGNIFICAND_MASK_F_04_04;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if (SIGNIFICAND_SIGN_MASK_F_04_04 & sig_a) {
        sig_a |= EXPONENT_MASK_F_04_04;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_04_04;
        log_debug_label("a is negative");
    }
    if (SIGNIFICAND_SIGN_MASK_F_04_04 & sig_b) {
        sig_b |= EXPONENT_MASK_F_04_04;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_04_04;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if (EXPONENT_SIGN_MASK_F_04_04 & exp_a) {
        exp_a |= SIGNIFICAND_MASK_F_04_04 << EXPONENT_BITS_F_04_04; // Fill the left with ones
    }
    if (EXPONENT_SIGN_MASK_F_04_04 & exp_b) {
        exp_b |= SIGNIFICAND_MASK_F_04_04 << EXPONENT_BITS_F_04_04; // Fill the left with ones
    }

    // Multiply significands
    uint16_t temp_sig = (uint16_t)sig_a * sig_b;
    log_debug_float("result significand", temp_sig);

    // Adjust exponent
    uint8_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_16(temp_sig);
    msb -= SIGNIFICAND_BITS_F_04_04 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint8_t result_sig = (uint8_t)temp_sig & SIGNIFICAND_MASK_F_04_04;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    } else if (msb < 0) {
        result_sig = temp_sig << abs(msb);
    }
    log_debug_float("result exp", result_exp);
    result_exp += msb - SIGNIFICAND_BITS_F_04_04 + 1;
    log_debug_float("result significand", result_sig);
    log_debug_float("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_float("result significand", result_sig);
    }

    return new_f0404(result_exp, result_sig);
}

f0404_t div_f0404(f0404_t a, f0404_t b) {
    uint8_t exp_a = (a & EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;
    uint8_t exp_b = (b & EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;
    uint8_t sig_a = a & SIGNIFICAND_MASK_F_04_04;
    uint8_t sig_b = b & SIGNIFICAND_MASK_F_04_04;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_04_04 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_04_04;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_04_04;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_04_04 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_04_04;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_04_04;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_04_04 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_04_04 << EXPONENT_BITS_F_04_04; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_04_04 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_04_04 << EXPONENT_BITS_F_04_04; // Fill the left with ones
    }

    // Check for division by zero
    if (sig_b == 0U) {
        if (posi_a) {
            // Return max value as "infinity"
            return MAX_VALUE_F_04_04;
        } else {
            // Return min value as "-infinity"
            return MIN_VALUE_F_04_04;
        }
    }

    // Perform division
    uint16_t temp_sig = ((uint16_t)sig_a << SIGNIFICAND_BITS_F_04_04) / sig_b;

    // Adjust exponent
    uint8_t result_exp = exp_a - exp_b;

    int8_t msb = get_msb_index_16(temp_sig);
    msb -= SIGNIFICAND_BITS_F_04_04 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint8_t result_sig = (uint8_t)temp_sig & SIGNIFICAND_MASK_F_04_04;
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

    return new_f0404(result_exp, result_sig);
}

bool equ_f0404(f0404_t a, f0404_t b) {
    return a == b;
}

int com_f0404(f0404_t a, f0404_t b) {
    if (a == b) return 0;

    int8_t exp_a = (a & EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;
    int8_t exp_b = (b & EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;
    int8_t sig_a = a & SIGNIFICAND_MASK_F_04_04;
    int8_t sig_b = b & SIGNIFICAND_MASK_F_04_04;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}

