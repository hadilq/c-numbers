#include "c_float_41_23.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void log_debug_label(const char* label) {
    if (C_FLOAT_41_23_DEBUG) {
        printf("%s\n", label);
    }
}

static void log_debug_float(const char* label, int64_t f) {
    if (C_FLOAT_41_23_DEBUG) {
        printf("%s: %ld, 0x%lx\n", label, f, f);
    }
}

static void not_reachable() {
    if (C_FLOAT_41_23_DEBUG) {
        assert(false);
    }
}

// get most significant bit for positive numbers
static uint8_t get_msb_index_positive(uint64_t n) {
    if (n == 0) return 0; // Handle 0 as a special case

    uint64_t copy = n & SIGNIFICAND_MASK_F_41_23;
    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_41_23; i++) {
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

    __uint128_t copy = n & SIGNIFICAND_2_MASK_F_41_23;
    for (uint8_t i = 1; i <= 2 * SIGNIFICAND_BITS_F_41_23; i++) {
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
    uint64_t copy = ~n & SIGNIFICAND_MASK_F_41_23;
    if (copy == 0) return 0; // Handle -1 as a special case

    for (uint8_t i = 1; i <= SIGNIFICAND_BITS_F_41_23; i++) {
        copy >>= 1;
        if (copy == 0) {
            return i;
        }
    }

    not_reachable();
    return 0; // This line should never be reached for non-zero input
}

// construct float 4123
f4123_t new_f4123(int64_t exp, int64_t sig) {
    return (exp << SIGNIFICAND_BITS_F_41_23) | (sig & SIGNIFICAND_MASK_F_41_23);
}

#ifdef __is_identifier
  #if __is_identifier(_Float64)

#define Float64_SIG 52
#define Float64_SIG_1 Float64_SIG + 1
#define Float64_EXP 11
typedef union {
  _Float64 f;
  struct {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        uint64_t significand : Float64_SIG;
        uint64_t exponent : Float64_EXP;
        uint64_t sign : 1;
#else
        uint64_t sign : 1;
        uint64_t exponent : Float64_EXP;
        uint64_t significand : Float64_SIG;
#endif
  } parts;
} float64_cast;

// construct float 4123
f4123_t new_f4123_from_float64(_Float64 f) {
    float64_cast f1 = { .f = f };
    uint64_t significand = f1.parts.significand;
    uint64_t sign = f1.parts.sign;
    uint64_t exponent = f1.parts.exponent- 1023;  // Unbias the exponent;

    // Handle subnormal numbers
    if (f1.parts.exponent == 0) {
        if (f1.parts.significand != 0) {
            exponent = -1022;  // Minimum exponent for subnormal numbers
        } else {
            exponent = 0;      // Zero
        }
    }
    log_debug_float("significand", significand);
    log_debug_float("exponent", exponent);
    significand = significand | (1ULL << Float64_SIG) | (sign << (Float64_SIG_1));
    if (SIGNIFICAND_BITS_F_41_23 > Float64_SIG_1) {
        significand <<= (SIGNIFICAND_BITS_F_41_23 - Float64_SIG_1);
    } else {
        significand >>= Float64_SIG_1 - SIGNIFICAND_BITS_F_41_23;
    }
    return new_f4123(exponent, significand);

}
  #endif
#endif

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

// construct float 4123
f4123_t new_f4123_from_float32(_Float32 f) {
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
    log_debug_float("significand:", significand);
    log_debug_float("exponent:", f1.parts.exponent);
    if (SIGNIFICAND_BITS_F_41_23 > Float32_SIG_1) {
        significand <<= SIGNIFICAND_BITS_F_41_23 - Float32_SIG_1;
    } else {
        significand >>= Float32_SIG_1 - SIGNIFICAND_BITS_F_41_23;
    }
    return new_f4123(exponent, significand);
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

// construct float 4123
f4123_t new_f4123_from_float16(_Float16 f) {
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
    if (SIGNIFICAND_BITS_F_41_23 > Float16_SIG_1) {
        significand <<= SIGNIFICAND_BITS_F_41_23 - Float16_SIG_1;
    } else {
        significand >>= Float16_SIG_1 - SIGNIFICAND_BITS_F_41_23;
    }
    return new_f4123(exponent, significand);
}
  #endif
#endif


// exponent part of float 4123
int64_t exp_f4123(f4123_t a) {
    uint64_t exp_a = (a & EXPONENT_MASK_F_41_23) >> SIGNIFICAND_BITS_F_41_23;

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_41_23 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_41_23 << EXPONENT_BITS_F_41_23; // Fill the left with ones
    }
    return exp_a;
}

// significand part of float 4123
int64_t sig_f4123(f4123_t a) {
    uint64_t sig_a = a & SIGNIFICAND_MASK_F_41_23;

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_41_23 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_41_23;
    }
    return sig_a;
}

// add float 4123
f4123_t add_f4123(f4123_t a, f4123_t b) {
    // Extract exponent and significand
    int64_t exp_a = (a & EXPONENT_MASK_F_41_23) >> SIGNIFICAND_BITS_F_41_23;
    int64_t exp_b = (b & EXPONENT_MASK_F_41_23) >> SIGNIFICAND_BITS_F_41_23;
    uint64_t sig_a = a & SIGNIFICAND_MASK_F_41_23;
    uint64_t sig_b = b & SIGNIFICAND_MASK_F_41_23;
    uint64_t result_exp = exp_a;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_41_23 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_41_23;
        posi_a = false;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_41_23 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_41_23;
        posi_b = false;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_41_23 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_41_23 << EXPONENT_BITS_F_41_23; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_41_23 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_41_23 << EXPONENT_BITS_F_41_23; // Fill the left with ones
    }

    // Align significands and handle negatives
    if (exp_a > exp_b) {
        uint8_t diff = exp_a - exp_b;
        sig_b >>= diff;
        if (!posi_b) {
            sig_b |= ((1ULL << diff) - 1) << (BITS_F_41_23 - diff); // Fill the left with ones
            if ((sig_b & SIGNIFICAND_MASK_F_41_23) == SIGNIFICAND_MASK_F_41_23) {
                sig_b = 0;
            }
        }
        log_debug_float("diff 'exp_a > exp_b' is", diff);
        result_exp = exp_a;
    } else if (exp_b > exp_a) {
        uint8_t diff = exp_b - exp_a;
        sig_a >>= diff;
        if (!posi_a) {
            sig_a |= ((1ULL << diff) - 1) << (BITS_F_41_23 - diff); // Fill the left with ones
            if ((sig_a & SIGNIFICAND_MASK_F_41_23) == SIGNIFICAND_MASK_F_41_23) {
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

    if (BITS_SIGN_MASK_F_41_23 & result_sig) {
       posi_result = false;
    }

    int8_t msb;
    if (posi_result) {
        msb = get_msb_index_positive(result_sig);
    } else {
        msb = get_msb_index_negative(result_sig);
    }
    msb -= SIGNIFICAND_BITS_F_41_23 - 1;
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
    return new_f4123(result_exp, result_sig);
}

f4123_t sub_f4123(f4123_t a, f4123_t b) {
    return add_f4123(a, neg_f4123(b));
}

f4123_t neg_f4123(f4123_t b) {
    // Negate b and add
    uint64_t exp_b = b & EXPONENT_MASK_F_41_23;
    uint64_t sig_b = b & SIGNIFICAND_MASK_F_41_23;

    // Flip all bits of significand for two's complement
    if ((SIGNIFICAND_SIGN_MASK_F_41_23 & sig_b)) {
        // negative
        sig_b = (~sig_b + 1) & SIGNIFICAND_MASK_F_41_23;
    } else {
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_41_23;
    }

    return exp_b | sig_b;
}

f4123_t mul_f4123(f4123_t a, f4123_t b) {
    uint64_t exp_a = (a & EXPONENT_MASK_F_41_23) >> SIGNIFICAND_BITS_F_41_23;
    uint64_t exp_b = (b & EXPONENT_MASK_F_41_23) >> SIGNIFICAND_BITS_F_41_23;
    uint64_t sig_a = a & SIGNIFICAND_MASK_F_41_23;
    uint64_t sig_b = b & SIGNIFICAND_MASK_F_41_23;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_41_23 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_41_23;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_41_23;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_41_23 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_41_23;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_41_23;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_41_23 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_41_23 << EXPONENT_BITS_F_41_23; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_41_23 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_41_23 << EXPONENT_BITS_F_41_23; // Fill the left with ones
    }

    // Multiply significands
    __uint128_t temp_sig = (__uint128_t)sig_a * sig_b;
    log_debug_float("result significand", temp_sig);

    // Adjust exponent
    uint64_t result_exp = exp_a + exp_b;

    int8_t msb = get_msb_index_128(temp_sig);
    msb -= SIGNIFICAND_BITS_F_41_23 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint64_t result_sig = (uint64_t)temp_sig & SIGNIFICAND_MASK_F_41_23;
    if (msb > 0) {
        result_sig = temp_sig >> msb;
    } else if (msb < 0) {
        result_sig = temp_sig << abs(msb);
    }
    result_exp += msb - SIGNIFICAND_BITS_F_41_23 + 1;
    log_debug_float("result significand", result_sig);
    log_debug_float("result exp", result_exp);

    if (posi_a ^ posi_b) {
        result_sig = ~(result_sig - 1);
        log_debug_float("result significand", result_sig);
    }

    return new_f4123(result_exp, result_sig);
}

f4123_t div_f4123(f4123_t a, f4123_t b) {
    uint64_t exp_a = (a & EXPONENT_MASK_F_41_23) >> SIGNIFICAND_BITS_F_41_23;
    uint64_t exp_b = (b & EXPONENT_MASK_F_41_23) >> SIGNIFICAND_BITS_F_41_23;
    uint64_t sig_a = a & SIGNIFICAND_MASK_F_41_23;
    uint64_t sig_b = b & SIGNIFICAND_MASK_F_41_23;
    bool posi_a = true;
    bool posi_b = true;
    log_debug_float("exp_a", exp_a);
    log_debug_float("exp_b", exp_b);
    log_debug_float("sig_a", sig_a);
    log_debug_float("sig_b", sig_b);

    // Handle negative numbers
    if ((SIGNIFICAND_SIGN_MASK_F_41_23 & sig_a)) {
        sig_a |= EXPONENT_MASK_F_41_23;
        posi_a = false;
        sig_a = (~(sig_a - 1)) & SIGNIFICAND_MASK_F_41_23;
        log_debug_label("a is negative");
    }
    if ((SIGNIFICAND_SIGN_MASK_F_41_23 & sig_b)) {
        sig_b |= EXPONENT_MASK_F_41_23;
        posi_b = false;
        sig_b = (~(sig_b - 1)) & SIGNIFICAND_MASK_F_41_23;
        log_debug_label("b is negative");
    }

    // Handle negatives exponents
    if ((EXPONENT_SIGN_MASK_F_41_23 & exp_a)) {
        exp_a |= SIGNIFICAND_MASK_F_41_23 << EXPONENT_BITS_F_41_23; // Fill the left with ones
    }
    if ((EXPONENT_SIGN_MASK_F_41_23 & exp_b)) {
        exp_b |= SIGNIFICAND_MASK_F_41_23 << EXPONENT_BITS_F_41_23; // Fill the left with ones
    }

    // Check for division by zero
    if (sig_b == 0ULL) {
        if (posi_a) {
            // Return max value as "infinity"
            return MAX_VALUE_F_41_23;
        } else {
            // Return min value as "-infinity"
            return MIN_VALUE_F_41_23;
        }
    }

    // Perform division
    __uint128_t temp_sig = ((__uint128_t)sig_a << SIGNIFICAND_BITS_F_41_23) / sig_b;

    // Adjust exponent
    uint64_t result_exp = exp_a - exp_b;

    int8_t msb = get_msb_index_128(temp_sig);
    msb -= SIGNIFICAND_BITS_F_41_23 - 1;
    log_debug_float("msb", msb);

    // Normalize result
    uint64_t result_sig = (uint64_t)temp_sig & SIGNIFICAND_MASK_F_41_23;
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

    return new_f4123(result_exp, result_sig);
}

bool equ_f4123(f4123_t a, f4123_t b) {
    return a == b;
}

int com_f4123(f4123_t a, f4123_t b) {
    if (a == b) return 0;

    int64_t exp_a = (a & EXPONENT_MASK_F_41_23) >> SIGNIFICAND_BITS_F_41_23;
    int64_t exp_b = (b & EXPONENT_MASK_F_41_23) >> SIGNIFICAND_BITS_F_41_23;
    int64_t sig_a = a & SIGNIFICAND_MASK_F_41_23;
    int64_t sig_b = b & SIGNIFICAND_MASK_F_41_23;

    if (exp_a > exp_b) return 1;
    if (exp_a < exp_b) return -1;
    if (sig_a > sig_b) return 1;
    return -1;
}

