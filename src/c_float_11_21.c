#include "c_float_11_21.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void log_debug_label(const char* label) {
    if (C_FLOAT_11_21_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_float(const char* label, int32_t f) {
    if (C_FLOAT_11_21_DEBUG) {
        printf("%s: %d, 0x%x\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_FLOAT_11_21_DEBUG) {
        assert(false);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index_positive(uint32_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint32_t copy = n & SIGNIFICAND_MASK_F_11_21;
    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_11_21; i++) {
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

    uint64_t copy = n & SIGNIFICAND_2_MASK_F_11_21;
    for (uint8_t i = 1; i <= 2 * SIGNIFICAND_BITS_F_11_21; i++) {
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
    uint32_t copy = ~n & SIGNIFICAND_MASK_F_11_21;
    if (copy == 0) return 0; // Handle -1 as a special case

    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_11_21; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// construct float 1121
f1121_t new_f1121(int32_t exp, int32_t sig) {
    return (exp << SIGNIFICAND_BITS_F_11_21) | (sig & SIGNIFICAND_MASK_F_11_21);
}

#ifdef __is_identifier
  #if __is_identifier(_Float32)
#define Float32_SIG 23
#define Float32_SIG_1 Float32_SIG + 1
#define Float32_EXP 8
typedef union {
  _Float32 f;
  struct {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        uint32_t significand : Float32_SIG;
        uint32_t exponent : Float32_EXP;
        uint32_t sign : 1;
#else
        uint32_t sign : 1;
        uint32_t exponent : Float32_EXP;
        uint32_t significand : Float32_SIG;
#endif
    } parts;
} float32_cast;


// construct float 1121
f1121_t new_f1121_from_float32(_Float32 f) {
    float32_cast f1 = { .f = f };
    uint64_t significand = f1.parts.significand;
    uint64_t sign = f1.parts.sign;
    uint64_t exponent = f1.parts.exponent - 127;  // Unbias the exponent (bias is 127 for float32)

    // Handle subnormal numbers
    if (f1.parts.exponent == 0) {
        if (f1.parts.significand != 0) {
            exponent = -126;  // Minimum exponent for subnormal numbers
        } else {
            exponent = 0;     // Zero
        }
    }
    significand = significand | (1U << Float32_SIG) | (sign << (Float32_SIG_1));
    if (SIGNIFICAND_BITS_F_11_21 > Float32_SIG_1) {
        significand <<= SIGNIFICAND_BITS_F_11_21 - Float32_SIG_1;
    } else {
        significand >>= Float32_SIG_1 - SIGNIFICAND_BITS_F_11_21;
    }
    return new_f1121(exponent, significand);
}
  #endif
#endif

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

// construct float 1121
f1121_t new_f1121_from_float16(_Float16 f) {
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
    if (SIGNIFICAND_BITS_F_11_21 > Float16_SIG_1) {
        significand <<= SIGNIFICAND_BITS_F_11_21 - Float16_SIG_1;
    } else {
        significand >>= Float16_SIG_1 - SIGNIFICAND_BITS_F_11_21;
    }
    return new_f1121(exponent, significand);
}
  #endif
#endif

// exponent part of float 1121
int32_t exp_f1121(f1121_t a) {
    uint32_t exp_a = (a & EXPONENT_MASK_F_11_21) >> SIGNIFICAND_BITS_F_11_21;

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_11_21 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_11_21 << EXPONENT_BITS_F_11_21; // Fill the left with ones
    }
    return exp_a;
}

// significand part of float 1121
int32_t sig_f1121(f1121_t a) {
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_11_21;

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_11_21 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_11_21;
    }
    return sig_a;
}

// add float 1121
f1121_t add_f1121(f1121_t a, f1121_t b) {
    // Extract exponent and significand
    int32_t exp_a = (a & EXPONENT_MASK_F_11_21) >> SIGNIFICAND_BITS_F_11_21;
    int32_t exp_b = (b & EXPONENT_MASK_F_11_21) >> SIGNIFICAND_BITS_F_11_21;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_11_21;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_11_21;
    uint32_t result_exp = exp_a;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_11_21 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_11_21;
        posi_a = false;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_11_21 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_11_21;
        posi_b = false;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_11_21 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_11_21 << EXPONENT_BITS_F_11_21; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_11_21 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_11_21 << EXPONENT_BITS_F_11_21; // Fill the left with ones
    }

    // Align significands and handle negatives
    if (exp_a > exp_b) {
        uint8_t diff = exp_a - exp_b;
        sig_b >>= diff;
        if (!posi_b) {
            sig_b |= ((1U << diff) - 1) << (BITS_F_11_21 - diff); // Fill the left with ones
            if ((sig_b & SIGNIFICAND_MASK_F_11_21) == SIGNIFICAND_MASK_F_11_21) {
                sig_b = 0;
            }
        }
        log_debug_float("diff 'exp_a > exp_b' is", diff);
        result_exp = exp_a;
    } else if (exp_b > exp_a) {
        uint8_t diff = exp_b - exp_a;
        sig_a >>= diff;
        if (!posi_a) {
            sig_a |= ((1U << diff) - 1) << (BITS_F_11_21 - diff); // Fill the left with ones
            if ((sig_a & SIGNIFICAND_MASK_F_11_21) == SIGNIFICAND_MASK_F_11_21) {
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

    if (BITS_SIGN_MASK_F_11_21 & result_sig) {
       posi_result = false;
    }

    int8_t msb;
    if (posi_result) {
        msb = get_msb_index_positive(result_sig);
    } else {
        msb = get_msb_index_negative(result_sig);
    }
    msb -= SIGNIFICAND_BITS_F_11_21 - 1;
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
    return new_f1121(result_exp, result_sig);
}

f1121_t sub_f1121(f1121_t a, f1121_t b) {
    return add_f1121(a, neg_f1121(b));
}

f1121_t neg_f1121(f1121_t b) {
    // Negate b and add
    uint32_t exp_b = b & EXPONENT_MASK_F_11_21;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_11_21;

    // Flip all bits of significand for two's complement
    if ((SIGNIFICAND_SIGN_MASK_F_11_21 & sig_b)) {
        // negative
        sig_b = (~sig_b + 1) & SIGNIFICAND_MASK_F_11_21;
    } else {
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_11_21;
    }

    return exp_b | sig_b;
}

f1121_t mul_f1121(f1121_t a, f1121_t b) {
    uint32_t exp_a = (a & EXPONENT_MASK_F_11_21) >> SIGNIFICAND_BITS_F_11_21;
    uint32_t exp_b = (b & EXPONENT_MASK_F_11_21) >> SIGNIFICAND_BITS_F_11_21;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_11_21;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_11_21;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_11_21 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_11_21;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_11_21;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_11_21 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_11_21;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_11_21;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_11_21 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_11_21 << EXPONENT_BITS_F_11_21; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_11_21 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_11_21 << EXPONENT_BITS_F_11_21; // Fill the left with ones
    }

    // Multiply significands
    uint64_t temp_sig = (uint64_t)sig_a * sig_b;
    log_debug_float("result significand", temp_sig);

    // Adjust exponent
    uint32_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_64(temp_sig);
    msb -= SIGNIFICAND_BITS_F_11_21 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint32_t result_sig = (uint32_t)temp_sig & SIGNIFICAND_MASK_F_11_21;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    } else if (msb < 0) {
        result_sig = temp_sig << abs(msb);
    }
    result_exp += msb - SIGNIFICAND_BITS_F_11_21 + 1;
    log_debug_float("result significand", result_sig);
    log_debug_float("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_float("result significand", result_sig);
    }

    return new_f1121(result_exp, result_sig);
}

f1121_t div_f1121(f1121_t a, f1121_t b) {
    uint32_t exp_a = (a & EXPONENT_MASK_F_11_21) >> SIGNIFICAND_BITS_F_11_21;
    uint32_t exp_b = (b & EXPONENT_MASK_F_11_21) >> SIGNIFICAND_BITS_F_11_21;
    uint32_t sig_a = a & SIGNIFICAND_MASK_F_11_21;
    uint32_t sig_b = b & SIGNIFICAND_MASK_F_11_21;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_11_21 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_11_21;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_11_21;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_11_21 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_11_21;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_11_21;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_11_21 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_11_21 << EXPONENT_BITS_F_11_21; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_11_21 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_11_21 << EXPONENT_BITS_F_11_21; // Fill the left with ones
    }

    // Check for division by zero
    if (sig_b == 0U) {
        if (posi_a) {
            // Return max value as "infinity"
            return MAX_VALUE_F_11_21;
        } else {
            // Return min value as "-infinity"
            return MIN_VALUE_F_11_21;
        }
    }

    // Perform division
    uint64_t temp_sig = ((uint64_t)sig_a << SIGNIFICAND_BITS_F_11_21) / sig_b;

    // Adjust exponent
    uint32_t result_exp = exp_a - exp_b;

    int8_t msb = get_msb_index_64(temp_sig);
    msb -= SIGNIFICAND_BITS_F_11_21 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint32_t result_sig = (uint32_t)temp_sig & SIGNIFICAND_MASK_F_11_21;
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

    return new_f1121(result_exp, result_sig);
}

bool equ_f1121(f1121_t a, f1121_t b) {
    return a == b;
}

int com_f1121(f1121_t a, f1121_t b) {
    if (a == b) return 0;

    int32_t exp_a = (a & EXPONENT_MASK_F_11_21) >> SIGNIFICAND_BITS_F_11_21;
    int32_t exp_b = (b & EXPONENT_MASK_F_11_21) >> SIGNIFICAND_BITS_F_11_21;
    int32_t sig_a = a & SIGNIFICAND_MASK_F_11_21;
    int32_t sig_b = b & SIGNIFICAND_MASK_F_11_21;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}

