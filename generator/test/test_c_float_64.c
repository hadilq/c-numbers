#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "c_float_64.h"

static void print_float_CCC_64(const char* label, fDDD64_t f) {
    if (C_FLOAT_CCC_64_DEBUG) {
        uint64_t exp = (f &EXPONENT_MASK_F_CCC_64) >> SIGNIFICAND_BITS_F_CCC_64;
        uint64_t sig = f & SIGNIFICAND_MASK_F_CCC_64;

        if ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1) & sig)) {
            sig |= ((1ULL << EXPONENT_BITS_F_CCC_64) - 1) << SIGNIFICAND_BITS_F_CCC_64; // Fill the left with ones
        }
        if ((1ULL << (EXPONENT_BITS_F_CCC_64 - 1) & exp)) {
            exp |= ((1ULL << SIGNIFICAND_BITS_F_CCC_64) - 1) << EXPONENT_BITS_F_CCC_64; // Fill the left with ones
        }
        printf("%s: fDDD64: Exponent: %ld, Significand: 0x%lx, Full value: 0x%lx\n", label, exp, sig, f);
    }
}

static void assert_float_CCC_64(const char* label, fDDD64_t f, uint64_t expected_exp, uint64_t expected_sig) {
    if (C_FLOAT_CCC_64_DEBUG) {
        print_float_CCC_64(label, f);
        printf("expected exp: 0x%lx\n", expected_exp << SIGNIFICAND_BITS_F_CCC_64);
        printf("actual exp  : 0x%llx\n", f &EXPONENT_MASK_F_CCC_64);
        printf("expected sig: 0x%lx\n", expected_sig);
        printf("actual sig  : 0x%llx\n", f & SIGNIFICAND_MASK_F_CCC_64);
    }
    assert((f &EXPONENT_MASK_F_CCC_64) == expected_exp << SIGNIFICAND_BITS_F_CCC_64);
    assert((f & SIGNIFICAND_MASK_F_CCC_64) == expected_sig);
}

static void test_addition() {
    printf("Testing addition...\n");

    // Test case 1: Simple addition
    fDDD64_t a = new_fDDD64(2, 5ULL << (SIGNIFICAND_BITS_F_CCC_64 - 4)); // 0.1010...00 × 2^2
    fDDD64_t b = new_fDDD64(2, 6ULL << (SIGNIFICAND_BITS_F_CCC_64 - 4)); // 0.1100...00 × 2^2
    fDDD64_t result = add_fDDD64(a, b); // 0.10110...00 × 2^3
    assert_float_CCC_64(
        "Addition result 1", result,
        3ULL,
        0xbULL << (SIGNIFICAND_BITS_F_CCC_64 - 5)
    );

    // Test case 2: Addition on max positive significand
    a = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)) - 1); // 0.11111...11 × 2^2
    b = new_fDDD64(2, 1); // 0.00000...01 × 2^2
    result = add_fDDD64(a, b); // 0.1000..00 × 2^3
    assert_float_CCC_64(
        "Addition result 2", result,
        3ULL,
        1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)
    );

    // Test case 3: Addition with different exponents
    a = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_fDDD64(1, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = add_fDDD64(a, b); // 0.10100...01 × 2^3
    assert_float_CCC_64(
        "Addition result 3", result,
        3ULL,
        (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 4)) | 1ULL
    );

    // Test case 4: Addition symmetry
    a = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_fDDD64(1, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = add_fDDD64(b, a); // 0.10100...01 × 2^3
    assert_float_CCC_64(
        "Addition result 4", result,
        3ULL,
        (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 4)) | 1ULL
    );

    // Test case 5: One negative exponent
    a = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_fDDD64(-1, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^-1
    result = add_fDDD64(b, a); // 0.10000...00 × 2^-1
    assert_float_CCC_64(
        "Addition result 5", result,
        (1ULL << EXPONENT_BITS_F_CCC_64) - 1,
        ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2))) | 1ULL
    );

    // Test case 6: Two negative exponent
    a = new_fDDD64(-2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^-2
    b = new_fDDD64(-1, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^-1
    result = add_fDDD64(b, a); // 0.10000...00 × 2^-1
    assert_float_CCC_64(
        "Addition result 6", result,
        (1ULL << EXPONENT_BITS_F_CCC_64) - 1,
        ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 3))) | ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2))) | 1ULL
    );
}

static void test_subtraction() {
    printf("Testing subtraction...\n");

    // Test case 1: Subtraction returns zero
    fDDD64_t a = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 4ULL); // 0.10000...100 × 2^2
    fDDD64_t b = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 4ULL); // 0.10000...100 × 2^2
    fDDD64_t result = sub_fDDD64(a, b); // 0.0000...00 × 2^0
    assert_float_CCC_64(
        "Subtraction result 1", result,
        0ULL, 0ULL
    );

    // Test case 2: Simple subtraction
    a = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 4ULL); // 0.10000...100 × 2^2
    b = new_fDDD64(2, 1ULL); // 0.00000...001 × 2^2
    result = sub_fDDD64(a, b); // 0.10000...011 × 2^2
    assert_float_CCC_64(
        "Subtraction result 2", result,
        2ULL,
        (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 3ULL
    );

    // Test case 3: Subtraction requiring normalization
    a = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 4ULL); // 0.10000...100 × 2^2
    b = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 3ULL); // 0.10000...011 × 2^2
    result = sub_fDDD64(a, b); // 0.10000...000 × 2^((sig_bits - 2)-(2 + 1))
    assert_float_CCC_64(
        "Subtraction result 3", result,
        (~(SIGNIFICAND_BITS_F_CCC_64 - 2) & ((1U << EXPONENT_BITS_F_CCC_64) - 1)) + 1U + 2U,
        1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)
    );

    // Test case 4: Subtraction with different exponents
    a = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_fDDD64(1, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = sub_fDDD64(a, b); // 0.110...00 × 2^2
    assert_float_CCC_64(
        "Subtraction result 4", result,
        2ULL,
        (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 3))
    );

    // Test case 5: Subtraction anti-symmetry
    a = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_fDDD64(1, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = add_fDDD64(neg_fDDD64(b), a); // 0.110...00 × 2^2
    assert_float_CCC_64(
        "Subtraction result 5", result,
        2ULL,
        (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 3))
    );

    // Test case 6: Subtraction reverse of addition
    a = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    b = new_fDDD64(1, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^1
    result = sub_fDDD64(add_fDDD64(b, a), a); // Should return b
    assert_float_CCC_64(
        "Subtraction result 6", result,
        1ULL,
        (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2))
    );
}

static void test_multiplication() {
    printf("Testing multiplication...\n");

    // Test case 1: Simple multiplication with inverse
    fDDD64_t a = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    fDDD64_t b = new_fDDD64(neg_fDDD64(2), (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)) - 1); // 0.1111...11 × 2^-2
    fDDD64_t result = mul_fDDD64(a, b); // 0.100000...00 × 2^1
    assert_float_CCC_64(
        "Multiplication result 1", result,
        1ULL,
        1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)
    );

    // Test case 2: Simple multiplication without normalization
    a = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^2
    b = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    result = mul_fDDD64(a, b); // 0.100000...010 × 2^4
    assert_float_CCC_64(
        "Multiplication result 2", result,
        4ULL,
        ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 2ULL)
    );

    // Test case 3: Multiplication both positive
    a = new_fDDD64(1, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)) - 1); // 0.11111...11 × 2^1
    b = new_fDDD64(1, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)) - 1); // 0.11111...11 × 2^1
    result = mul_fDDD64(a, b); // 0.111111...110 × 2^2
    assert_float_CCC_64(
        "Multiplication result 3", result,
        2ULL,
        ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)) - 1) - 1ULL
    );

    // Test case 4: Multiplication both negative
    a = new_fDDD64(1, neg_fDDD64(1)); // 1.11111...11 × 2^1
    b = new_fDDD64(1, ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 / 2)) - 1) << (SIGNIFICAND_BITS_F_CCC_64 /  2) ); // 1.11100...00 × 2^1
    result = mul_fDDD64(a, b); // 0.10...000 × 2^-54
    assert_float_CCC_64(
        "Multiplication result 4", result,
        neg_fDDD64(54),
        ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)) | (1ULL << (SIGNIFICAND_BITS_F_CCC_64 / 2)))
    );

    // Test case 5: Multiplication one negative
    a = new_fDDD64(1, neg_fDDD64(1)); // 1.11111...11 × 2^1
    b = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    result = mul_fDDD64(a, b); // 0.10...000 × 2^-52
    assert_float_CCC_64(
        "Multiplication result 5", result,
        neg_fDDD64(52),
        ((neg_fDDD64(5) << (SIGNIFICAND_BITS_F_CCC_64 - 1)) &  SIGNIFICAND_MASK_F_CCC_64) | ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) - 1)
    );

    // Test case 6: Multiplication symmetry
    a = new_fDDD64(1, neg_fDDD64(1)); // 1.11111...11 × 2^1
    b = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^3
    result = mul_fDDD64(b, a); // 0.10...000 × 2^-52
    assert_float_CCC_64(
        "Multiplication result 6", result,
        neg_fDDD64(52),
        ((neg_fDDD64(5) << (SIGNIFICAND_BITS_F_CCC_64 - 1)) &  SIGNIFICAND_MASK_F_CCC_64) | ((1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) - 1)
    );
}

static void test_division() {
    printf("Testing division...\n");

    // Test case 1: Division returns one
    fDDD64_t a = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^2
    fDDD64_t b = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^2
    fDDD64_t result = div_fDDD64(a, b); // 0.1000...00 × 2^-1
    assert_float_CCC_64(
        "Division result 1", result,
        1ULL,
        1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)
    );

    // Test case 2: Simple division
    a = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.1000...001 × 2^3
    b = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 2ULL); // 0.1000...010 × 2^2
    result = div_fDDD64(a, b); // 0.11...11 × 2^1
    assert_float_CCC_64(
        "Division result 2", result,
        1ULL,
        (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)) - 1 & ~1ULL
    );

    // Test case 3: Division of a positive number by zero
    a = new_fDDD64(2, 1); // 0.00000...01 × 2^2
    b = new_fDDD64(4, 0); // 0
    result = div_fDDD64(a, b); // Should return max value as "infinity"
    assert_float_CCC_64(
        "Division result 3", result,
        (1ULL << (EXPONENT_BITS_F_CCC_64 - 2)) - 1,
        (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) - 1
    );

    // Test case 4: Division of a negative number by zero
    a = new_fDDD64(2, neg_fDDD64(1)); // 1.1111...11 × 2^2
    b = new_fDDD64(4, 0); // 0
    result = div_fDDD64(a, b); // Should return min value as "-infinity"
    assert_float_CCC_64(
        "Division result 4", result,
        (1ULL << (EXPONENT_BITS_F_CCC_64 - 2)) - 1,
        1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)
    );

    // Test case 5: Division reverse of multiplication for small positive numbers
    a = new_fDDD64(neg_fDDD64(1), 1ULL); // 0.0000...001 × 2^-1
    b = new_fDDD64(2, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 2ULL); // 0.1000...010 × 2^2
    result = div_fDDD64(mul_fDDD64(a, b), b); // Should return a
    assert_float_CCC_64(
        "Division result 5", result,
        neg_fDDD64(56),
        1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)
    );

    // Test case 6: Division reverse of multiplication for big positive numbers
    a = new_fDDD64(2, 1); // 0.000...01 × 2^2
    b = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.100...01 × 2^3
    result = div_fDDD64(mul_fDDD64(b, a), a); // Should return b
    assert_float_CCC_64(
        "Division result 6", result,
        3ULL,
        1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2) | 1ULL
    );

    // Test case 7: Division reverse of multiplication for small negative numbers
    a = new_fDDD64(neg_fDDD64(1), neg_fDDD64(1)); // 1.111...11 × 2^-1
    b = new_fDDD64(3, (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)) | 1ULL); // 0.100...01 × 2^3
    result = div_fDDD64(mul_fDDD64(a, b), b); // Should return a
    assert_float_CCC_64(
        "Division result 7", result,
        neg_fDDD64(56),
        3ULL << (SIGNIFICAND_BITS_F_CCC_64 - 2)
    );

    // Test case 8: Division reverse of multiplication for big negative numbers
    a = new_fDDD64(2, neg_fDDD64(1)); // 0.000...01 × 2^2
    b = new_fDDD64(3, (3ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)) | 1ULL); // 1.100...01 × 2^3
    result = div_fDDD64(mul_fDDD64(b, a), a); // Should return b
    assert_float_CCC_64(
        "Division result 8", result,
        3ULL,
        (1ULL << (SIGNIFICAND_BITS_F_CCC_64 - 1)) | 1ULL
    );
}

static void test_equals_and_compare() {
    printf("Testing equals and compare...\n");

    fDDD64_t a = new_fDDD64(2, 1); // 1.0000...01 × 2^2
    fDDD64_t b = new_fDDD64(2, 1); // 1.0000...01 × 2^2
    fDDD64_t c = new_fDDD64(2, 2); // 1.0000...10 × 2^2
    fDDD64_t d = new_fDDD64(3, 1); // 1.0000...01 × 2^3

    assert(equ_fDDD64(a, b));
    assert(!equ_fDDD64(a, c));
    assert(!equ_fDDD64(a, d));

    assert(com_fDDD64(a, b) == 0);
    assert(com_fDDD64(a, c) < 0);
    assert(com_fDDD64(c, a) > 0);
    assert(com_fDDD64(a, d) < 0);
    assert(com_fDDD64(d, a) > 0);
}

int main() {
    test_addition();
    test_subtraction();
    test_multiplication();
    test_division();
    test_equals_and_compare();

    printf("All float CCC_64 tests passed!\n");
    return 0;
}

