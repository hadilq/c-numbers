#include "c_float_03_13.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void log_debug_label(const char* label) {
    if (C_FLOAT_03_13_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_float(const char* label, int16_t f) {
    if (C_FLOAT_03_13_DEBUG) {
        printf("%s: %d, 0x%x\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_FLOAT_03_13_DEBUG) {
        assert(false);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index_positive(uint16_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint16_t copy = n & SIGNIFICAND_MASK_F_03_13;
    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_03_13; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for positive numbers for 32 digit numbers
static uint8_t get_msb_index_32(uint32_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint32_t copy = n & SIGNIFICAND_2_MASK_F_03_13;
    for (uint8_t i = 1; i <= 2 * SIGNIFICAND_BITS_F_03_13; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// get most significant bit for negative numbers
static uint8_t get_msb_index_negative(uint16_t n) {
    uint16_t copy = ~n & SIGNIFICAND_MASK_F_03_13;
    if (copy == 0) return 0; // Handle -1 as a special case

    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_03_13; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// construct float 0313
f0313_t new_f0313(int16_t exp, int16_t sig) {
    return (exp << SIGNIFICAND_BITS_F_03_13) | (sig & SIGNIFICAND_MASK_F_03_13);
}

#ifdef __is_identifier
  #if __is_identifier(_Float16)
#define Float16_SIG 10
#define Float16_SIG_1 Float16_SIG + 1
#define Float16_EXP 5
typedef union {
  _Float16 f;
  struct {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        uint16_t significand : Float16_SIG;
        uint16_t exponent : Float16_EXP;
        uint16_t sign : 1;
#else
        uint16_t sign : 1;
        uint16_t exponent : Float16_EXP;
        uint16_t significand : Float16_SIG;
#endif
  } parts;
} float16_cast;


// construct float DDD32
f0313_t new_f0313_from_float16(_Float16 f) {
    float16_cast f1 = { .f = f };
    uint64_t significand = f1.parts.significand;
    uint64_t exponent = f1.parts.exponent - 15;  // Unbias the exponent (bias is 15 for float16)
    uint64_t sign = f1.parts.sign;

    // Handle subnormal numbers
    if (f1.parts.exponent == 0) {
        if (f1.parts.significand != 0) {
            exponent = -14;  // Minimum exponent for subnormal numbers
        } else {
            exponent = 0;    // Zero
        }
    }
    significand = significand | (1U << Float16_SIG) | (sign << (Float16_SIG_1));
    if (SIGNIFICAND_BITS_F_03_13 > Float16_SIG_1) {
        significand <<= SIGNIFICAND_BITS_F_03_13 - Float16_SIG_1;
    } else {
        significand >>= Float16_SIG_1 - SIGNIFICAND_BITS_F_03_13;
    }
    return new_f0313(exponent, significand);
}
  #endif
#endif

// exponent part of float 0313
int16_t exp_f0313(f0313_t a) {
    uint16_t exp_a = (a & EXPONENT_MASK_F_03_13) >> SIGNIFICAND_BITS_F_03_13;

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_03_13 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_03_13 << EXPONENT_BITS_F_03_13; // Fill the left with ones
    }
    return exp_a;
}

// significand part of float 0313
int16_t sig_f0313(f0313_t a) {
    uint16_t sig_a = a & SIGNIFICAND_MASK_F_03_13;

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_03_13 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_03_13;
    }
    return sig_a;
}

// add float 0313
f0313_t add_f0313(f0313_t a, f0313_t b) {
    // Extract exponent and significand
    int16_t exp_a = (a & EXPONENT_MASK_F_03_13) >> SIGNIFICAND_BITS_F_03_13;
    int16_t exp_b = (b & EXPONENT_MASK_F_03_13) >> SIGNIFICAND_BITS_F_03_13;
    uint16_t sig_a = a & SIGNIFICAND_MASK_F_03_13;
    uint16_t sig_b = b & SIGNIFICAND_MASK_F_03_13;
    uint16_t result_exp = exp_a;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_03_13 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_03_13;
        posi_a = false;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_03_13 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_03_13;
        posi_b = false;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_03_13 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_03_13 << EXPONENT_BITS_F_03_13; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_03_13 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_03_13 << EXPONENT_BITS_F_03_13; // Fill the left with ones
    }

    // Align significands and handle negatives
    if (exp_a > exp_b) {
        uint8_t diff = exp_a - exp_b;
        sig_b >>= diff;
        if (!posi_b) {
            sig_b |= ((1U << diff) - 1) << (BITS_F_03_13 - diff); // Fill the left with ones
            if ((sig_b & SIGNIFICAND_MASK_F_03_13) == SIGNIFICAND_MASK_F_03_13) {
                sig_b = 0;
            }
        }
        log_debug_float("diff 'exp_a > exp_b' is", diff);
        result_exp = exp_a;
    } else if (exp_b > exp_a) {
        uint8_t diff = exp_b - exp_a;
        sig_a >>= diff;
        if (!posi_a) {
            sig_a |= ((1U << diff) - 1) << (BITS_F_03_13 - diff); // Fill the left with ones
            if ((sig_a & SIGNIFICAND_MASK_F_03_13) == SIGNIFICAND_MASK_F_03_13) {
                sig_a = 0;
            }
        }
        log_debug_float("diff 'exp_b > exp_a' is", diff);
        result_exp = exp_b;
    }

    // Add significands
    uint16_t result_sig = sig_a + sig_b;
    bool posi_result = true;

    // Check for zero
    if (result_sig == 0) {
        return 0U;
    }

    log_debug_float("result significand", result_sig);
    log_debug_float("result exponent", result_exp);

    if (BITS_SIGN_MASK_F_03_13 & result_sig) {
       posi_result = false;
    }
    log_debug_float("positive result", posi_result);

    int8_t msb;
    if (posi_result) {
        msb = get_msb_index_positive(result_sig);
    } else {
        msb = get_msb_index_negative(result_sig);
    }
    log_debug_float("msb", msb);
    msb -= SIGNIFICAND_BITS_F_03_13 - 1;
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
    return new_f0313(result_exp, result_sig);
}

f0313_t sub_f0313(f0313_t a, f0313_t b) {
    return add_f0313(a, neg_f0313(b));
}

f0313_t neg_f0313(f0313_t b) {
    // Negate b and add
    uint16_t exp_b = b & EXPONENT_MASK_F_03_13;
    uint16_t sig_b = b & SIGNIFICAND_MASK_F_03_13;

    // Flip all bits of significand for two's complement
    if ((SIGNIFICAND_SIGN_MASK_F_03_13 & sig_b)) {
        // negative
        sig_b = (~sig_b + 1) & SIGNIFICAND_MASK_F_03_13;
    } else {
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_03_13;
    }

    return exp_b | sig_b;
}

f0313_t mul_f0313(f0313_t a, f0313_t b) {
    uint16_t exp_a = (a & EXPONENT_MASK_F_03_13) >> SIGNIFICAND_BITS_F_03_13;
    uint16_t exp_b = (b & EXPONENT_MASK_F_03_13) >> SIGNIFICAND_BITS_F_03_13;
    uint16_t sig_a = a & SIGNIFICAND_MASK_F_03_13;
    uint16_t sig_b = b & SIGNIFICAND_MASK_F_03_13;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_03_13 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_03_13;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_03_13;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_03_13 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_03_13;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_03_13;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_03_13 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_03_13 << EXPONENT_BITS_F_03_13; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_03_13 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_03_13 << EXPONENT_BITS_F_03_13; // Fill the left with ones
    }

    // Multiply significands
    uint32_t temp_sig = (uint32_t)sig_a * sig_b;
    log_debug_float("result significand", temp_sig);

    // Adjust exponent
    uint16_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_32(temp_sig);
    msb -= SIGNIFICAND_BITS_F_03_13 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint16_t result_sig = (uint16_t)temp_sig & SIGNIFICAND_MASK_F_03_13;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    } else if (msb < 0) {
        result_sig = temp_sig << abs(msb);
    }
    result_exp += msb - SIGNIFICAND_BITS_F_03_13 + 1;
    log_debug_float("result significand", result_sig);
    log_debug_float("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_float("result significand", result_sig);
    }

    return new_f0313(result_exp, result_sig);
}

f0313_t div_f0313(f0313_t a, f0313_t b) {
    uint16_t exp_a = (a & EXPONENT_MASK_F_03_13) >> SIGNIFICAND_BITS_F_03_13;
    uint16_t exp_b = (b & EXPONENT_MASK_F_03_13) >> SIGNIFICAND_BITS_F_03_13;
    uint16_t sig_a = a & SIGNIFICAND_MASK_F_03_13;
    uint16_t sig_b = b & SIGNIFICAND_MASK_F_03_13;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_03_13 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_03_13;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_03_13;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_03_13 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_03_13;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_03_13;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_03_13 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_03_13 << EXPONENT_BITS_F_03_13; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_03_13 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_03_13 << EXPONENT_BITS_F_03_13; // Fill the left with ones
    }

    // Check for division by zero
    if (sig_b == 0U) {
        if (posi_a) {
            // Return max value as "infinity"
            return MAX_VALUE_F_03_13;
        } else {
            // Return min value as "-infinity"
            return MIN_VALUE_F_03_13;
        }
    }

    // Perform division
    uint32_t temp_sig = ((uint32_t)sig_a << SIGNIFICAND_BITS_F_03_13) / sig_b;

    // Adjust exponent
    uint16_t result_exp = exp_a - exp_b;

    int8_t msb = get_msb_index_32(temp_sig);
    msb -= SIGNIFICAND_BITS_F_03_13 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint16_t result_sig = (uint16_t)temp_sig & SIGNIFICAND_MASK_F_03_13;
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

    return new_f0313(result_exp, result_sig);
}

bool equ_f0313(f0313_t a, f0313_t b) {
    return a == b;
}

int com_f0313(f0313_t a, f0313_t b) {
    if (a == b) return 0;

    int16_t exp_a = (a & EXPONENT_MASK_F_03_13) >> SIGNIFICAND_BITS_F_03_13;
    int16_t exp_b = (b & EXPONENT_MASK_F_03_13) >> SIGNIFICAND_BITS_F_03_13;
    int16_t sig_a = a & SIGNIFICAND_MASK_F_03_13;
    int16_t sig_b = b & SIGNIFICAND_MASK_F_03_13;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}

