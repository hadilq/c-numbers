#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "c_float_57_07.h"

static void print_float_57_07(const char* label, f5707_t f) {
    if (C_FLOAT_57_07_DEBUG) {
        uint64_t exp = (f &EXPONENT_MASK_F_57_07) >> SIGNIFICAND_BITS_F_57_07;
        uint64_t sig = f & SIGNIFICAND_MASK_F_57_07;

        if ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 1) & sig)) {
            sig |= ((1ULL << EXPONENT_BITS_F_57_07) - 1) << SIGNIFICAND_BITS_F_57_07; // Fill the left with ones
        }
        if ((1ULL << (EXPONENT_BITS_F_57_07 - 1) & exp)) {
            exp |= ((1ULL << SIGNIFICAND_BITS_F_57_07) - 1) << EXPONENT_BITS_F_57_07; // Fill the left with ones
        }
        printf("%s: f5707: Exponent: %ld, Significand: 0x%lx, Full value: 0x%lx\n", label, exp, sig, f);
    }
}

static void assert_float_57_07(const char* label, f5707_t f, uint64_t expected_exp, uint64_t expected_sig) {
    if (C_FLOAT_57_07_DEBUG) {
        print_float_57_07(label, f);
        printf("expected exp: 0x%lx\n", expected_exp);
        printf("actual exp  : 0x%llx\n", (f & EXPONENT_MASK_F_57_07) >> SIGNIFICAND_BITS_F_57_07);
        printf("expected sig: 0x%lx\n", expected_sig);
        printf("actual sig  : 0x%llx\n", f & SIGNIFICAND_MASK_F_57_07);
    }
    assert((f & EXPONENT_MASK_F_57_07) == expected_exp << SIGNIFICAND_BITS_F_57_07);
    assert((f & SIGNIFICAND_MASK_F_57_07) == expected_sig);
}

static void test_constructor() {
    printf("Testing constructor...\n");

#ifdef __is_identifier
  #if !__is_identifier(_Float64)
    // Test case 1: Float64
    f5707_t a = new_f5707_from_float64(1.164);
    assert_float_57_07(
        "Constructor result 1", a,
        0,
        0xa7ef9db22d0e40ULL
    );
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
    // Test case 2: Float32
    f5707_t b = new_f5707_from_float32(1.164);
    assert_float_57_07(
        "Constructor result 2", b,
        0,
        0xa7efa000000000ULL
    );
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
    // Test case 3: Float16
    f5707_t c = new_f5707_from_float16(1.164);
    assert_float_57_07(
        "Constructor result 3", c,
        0,
        0xa8000000000000ULL
    );
  #endif
#endif
}

static void test_addition() {
    printf("Testing addition...\n");

    // Test case 1: Simple addition
    f5707_t a = new_f5707(2, 5ULL << (SIGNIFICAND_BITS_F_57_07 - 4)); // 0.1010...00 × 2^2
    f5707_t b = new_f5707(2, 6ULL << (SIGNIFICAND_BITS_F_57_07 - 4)); // 0.1100...00 × 2^2
    f5707_t result = add_f5707(a, b); // 0.10110...00 × 2^3
    assert_float_57_07(
        "Addition result 1", result,
        3ULL,
        0xbULL << (SIGNIFICAND_BITS_F_57_07 - 5)
    );

    // Test case 2: Addition on max positive significand
    a = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 1)) - 1); // 0.11111...11 × 2^2
    b = new_f5707(2, 1); // 0.00000...01 × 2^2
    result = add_f5707(a, b); // 0.1000..00 × 2^3
    assert_float_57_07(
        "Addition result 2", result,
        3ULL,
        1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)
    );

    // Test case 3: Addition with different exponents
    a = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_f5707(1, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = add_f5707(a, b); // 0.10100...01 × 2^3
    assert_float_57_07(
        "Addition result 3", result,
        3ULL,
        (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | (1ULL << (SIGNIFICAND_BITS_F_57_07 - 4)) | 1ULL
    );

    // Test case 4: Addition symmetry
    a = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_f5707(1, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = add_f5707(b, a); // 0.10100...01 × 2^3
    assert_float_57_07(
        "Addition result 4", result,
        3ULL,
        (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | (1ULL << (SIGNIFICAND_BITS_F_57_07 - 4)) | 1ULL
    );

    // Test case 5: One negative exponent
    a = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_f5707(-1, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^-1
    result = add_f5707(b, a); // 0.10000...00 × 2^3
    assert_float_57_07(
        "Addition result 5", result,
        3,
        ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 2))) | ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 6))) | 1ULL
    );

    // Test case 6: Two negative exponent
    a = new_f5707(-2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^-2
    b = new_f5707(-1, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^-1
    result = add_f5707(b, a); // 0.10000...00 × 2^-1
    assert_float_57_07(
        "Addition result 6", result,
        (1ULL << EXPONENT_BITS_F_57_07) - 1,
        ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 3))) | ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 2))) | 1ULL
    );
}

static void test_subtraction() {
    printf("Testing subtraction...\n");

    // Test case 1: Subtraction returns zero
    f5707_t a = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 4ULL); // 0.10000...100 × 2^2
    f5707_t b = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 4ULL); // 0.10000...100 × 2^2
    f5707_t result = sub_f5707(a, b); // 0.0000...00 × 2^0
    assert_float_57_07(
        "Subtraction result 1", result,
        0ULL, 0ULL
    );

    // Test case 2: Simple subtraction
    a = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 4ULL); // 0.10000...100 × 2^2
    b = new_f5707(2, 1ULL); // 0.00000...001 × 2^2
    result = sub_f5707(a, b); // 0.10000...011 × 2^2
    assert_float_57_07(
        "Subtraction result 2", result,
        2ULL,
        (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 3ULL
    );

    // Test case 3: Subtraction requiring normalization
    a = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 4ULL); // 0.10000...100 × 2^2
    b = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 3ULL); // 0.10000...011 × 2^2
    result = sub_f5707(a, b); // 0.10000...000 × 2^((sig_bits - 2)-(2 + 1))
    assert_float_57_07(
        "Subtraction result 3", result,
        (~(SIGNIFICAND_BITS_F_57_07 - 2) & ((1U << EXPONENT_BITS_F_57_07) - 1)) + 1U + 2U,
        1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)
    );

    // Test case 4: Subtraction with different exponents
    a = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_f5707(1, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = sub_f5707(a, b); // 0.110...00 × 2^2
    assert_float_57_07(
        "Subtraction result 4", result,
        2ULL,
        (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | (1ULL << (SIGNIFICAND_BITS_F_57_07 - 3))
    );

    // Test case 5: Subtraction anti-symmetry
    a = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_f5707(1, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = add_f5707(neg_f5707(b), a); // 0.110...00 × 2^2
    assert_float_57_07(
        "Subtraction result 5", result,
        2ULL,
        (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | (1ULL << (SIGNIFICAND_BITS_F_57_07 - 3))
    );

    // Test case 6: Subtraction reverse of addition
    a = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_f5707(1, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = sub_f5707(add_f5707(b, a), a); // Should return b
    assert_float_57_07(
        "Subtraction result 6", result,
        1ULL,
        (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2))
    );
}

static void test_multiplication() {
    printf("Testing multiplication...\n");

    // Test case 1: Simple multiplication with inverse
    f5707_t a = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    f5707_t b = new_f5707(neg_f5707(2), (1ULL << (SIGNIFICAND_BITS_F_57_07 - 1)) - 1); // 0.1111...11 × 2^-2
    f5707_t result = mul_f5707(a, b); // 0.100000...00 × 2^1
    assert_float_57_07(
        "Multiplication result 1", result,
        1ULL,
        1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)
    );

    // Test case 2: Simple multiplication without normalization
    a = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^2
    b = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    result = mul_f5707(a, b); // 0.100000...010 × 2^4
    assert_float_57_07(
        "Multiplication result 2", result,
        4ULL,
        ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 2ULL)
    );

    // Test case 3: Multiplication both positive
    a = new_f5707(1, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 1)) - 1); // 0.11111...11 × 2^1
    b = new_f5707(1, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 1)) - 1); // 0.11111...11 × 2^1
    result = mul_f5707(a, b); // 0.111111...110 × 2^2
    assert_float_57_07(
        "Multiplication result 3", result,
        2ULL,
        ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 1)) - 1) - 1ULL
    );

    // Test case 4: Multiplication both negative
    a = new_f5707(1, neg_f5707(1)); // 1.11111...11 × 2^1
    b = new_f5707(1, ((1ULL << (SIGNIFICAND_BITS_F_57_07 / 2)) - 1) << (SIGNIFICAND_BITS_F_57_07 /  2) ); // 1.11100...00 × 2^1
    result = mul_f5707(a, b); // 0.10...000 × 2^-54
    assert_float_57_07(
        "Multiplication result 4", result,
        neg_f5707(54),
        ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 1)) | (1ULL << (SIGNIFICAND_BITS_F_57_07 / 2)))
    );

    // Test case 5: Multiplication one negative
    a = new_f5707(1, neg_f5707(1)); // 1.11111...11 × 2^1
    b = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    result = mul_f5707(a, b); // 0.10...000 × 2^-52
    assert_float_57_07(
        "Multiplication result 5", result,
        neg_f5707(52),
        ((neg_f5707(5) << (SIGNIFICAND_BITS_F_57_07 - 1)) &  SIGNIFICAND_MASK_F_57_07) | ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) - 1)
    );

    // Test case 6: Multiplication symmetry
    a = new_f5707(1, neg_f5707(1)); // 1.11111...11 × 2^1
    b = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^3
    result = mul_f5707(b, a); // 0.10...000 × 2^-52
    assert_float_57_07(
        "Multiplication result 6", result,
        neg_f5707(52),
        ((neg_f5707(5) << (SIGNIFICAND_BITS_F_57_07 - 1)) &  SIGNIFICAND_MASK_F_57_07) | ((1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) - 1)
    );
}

static void test_division() {
    printf("Testing division...\n");

    // Test case 1: Division returns one
    f5707_t a = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^2
    f5707_t b = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.10000...01 × 2^2
    f5707_t result = div_f5707(a, b); // 0.1000...00 × 2^-1
    assert_float_57_07(
        "Division result 1", result,
        1ULL,
        1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)
    );

    // Test case 2: Simple division
    a = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.1000...001 × 2^3
    b = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 2ULL); // 0.1000...010 × 2^2
    result = div_f5707(a, b); // 0.11...11 × 2^1
    assert_float_57_07(
        "Division result 2", result,
        1ULL,
        (1ULL << (SIGNIFICAND_BITS_F_57_07 - 1)) - 1 & ~1ULL
    );

    // Test case 3: Division of a positive number by zero
    a = new_f5707(2, 1); // 0.00000...01 × 2^2
    b = new_f5707(4, 0); // 0
    result = div_f5707(a, b); // Should return max value as "infinity"
    assert_float_57_07(
        "Division result 3", result,
        (1ULL << (EXPONENT_BITS_F_57_07 - 2)) - 1,
        (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) - 1
    );

    // Test case 4: Division of a negative number by zero
    a = new_f5707(2, neg_f5707(1)); // 1.1111...11 × 2^2
    b = new_f5707(4, 0); // 0
    result = div_f5707(a, b); // Should return min value as "-infinity"
    assert_float_57_07(
        "Division result 4", result,
        (1ULL << (EXPONENT_BITS_F_57_07 - 2)) - 1,
        1ULL << (SIGNIFICAND_BITS_F_57_07 - 1)
    );

    // Test case 5: Division reverse of multiplication for small positive numbers
    a = new_f5707(neg_f5707(1), 1ULL); // 0.0000...001 × 2^-1
    b = new_f5707(2, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 2ULL); // 0.1000...010 × 2^2
    result = div_f5707(mul_f5707(a, b), b); // Should return a
    assert_float_57_07(
        "Division result 5", result,
        neg_f5707(56),
        1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)
    );

    // Test case 6: Division reverse of multiplication for big positive numbers
    a = new_f5707(2, 1); // 0.000...01 × 2^2
    b = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.100...01 × 2^3
    result = div_f5707(mul_f5707(b, a), a); // Should return b
    assert_float_57_07(
        "Division result 6", result,
        3ULL,
        1ULL << (SIGNIFICAND_BITS_F_57_07 - 2) | 1ULL
    );

    // Test case 7: Division reverse of multiplication for small negative numbers
    a = new_f5707(neg_f5707(1), neg_f5707(1)); // 1.111...11 × 2^-1
    b = new_f5707(3, (1ULL << (SIGNIFICAND_BITS_F_57_07 - 2)) | 1ULL); // 0.100...01 × 2^3
    result = div_f5707(mul_f5707(a, b), b); // Should return a
    assert_float_57_07(
        "Division result 7", result,
        neg_f5707(56),
        3ULL << (SIGNIFICAND_BITS_F_57_07 - 2)
    );

    // Test case 8: Division reverse of multiplication for big negative numbers
    a = new_f5707(2, neg_f5707(1)); // 0.000...01 × 2^2
    b = new_f5707(3, (3ULL << (SIGNIFICAND_BITS_F_57_07 - 1)) | 1ULL); // 1.100...01 × 2^3
    result = div_f5707(mul_f5707(b, a), a); // Should return b
    assert_float_57_07(
        "Division result 8", result,
        3ULL,
        (1ULL << (SIGNIFICAND_BITS_F_57_07 - 1)) | 1ULL
    );
}

static void test_equals_and_compare() {
    printf("Testing equals and compare...\n");

    f5707_t a = new_f5707(2, 1); // 1.0000...01 × 2^2
    f5707_t b = new_f5707(2, 1); // 1.0000...01 × 2^2
    f5707_t c = new_f5707(2, 2); // 1.0000...10 × 2^2
    f5707_t d = new_f5707(3, 1); // 1.0000...01 × 2^3

    assert(equ_f5707(a, b));
    assert(!equ_f5707(a, c));
    assert(!equ_f5707(a, d));

    assert(com_f5707(a, b) == 0);
    assert(com_f5707(a, c) < 0);
    assert(com_f5707(c, a) > 0);
    assert(com_f5707(a, d) < 0);
    assert(com_f5707(d, a) > 0);
}

int main() {
    test_constructor();
    test_addition();
    test_subtraction();
    test_multiplication();
    test_division();
    test_equals_and_compare();

    printf("All float 57_07 tests passed!\n");
    return 0;
}

