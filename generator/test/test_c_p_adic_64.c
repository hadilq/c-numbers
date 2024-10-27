#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "c_p_adic_64.h"

static void print_p_adic_CCC_64(const char* label, pDDD64_t f) {
    if (C_P_ADIC_CCC_64_DEBUG) {
        uint64_t exp = (f & EXPONENT_MASK_P_CCC_64) >> SIGNIFICAND_BITS_P_CCC_64;
        uint64_t sig = f & SIGNIFICAND_MASK_P_CCC_64;

        if ((1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1) & sig)) {
            sig |= ((1ULL << EXPONENT_BITS_P_CCC_64) - 1) << SIGNIFICAND_BITS_P_CCC_64; // Fill the left with ones
        }
        if ((1ULL << (EXPONENT_BITS_P_CCC_64 - 1) & exp)) {
            exp |= ((1ULL << SIGNIFICAND_BITS_P_CCC_64) - 1) << EXPONENT_BITS_P_CCC_64; // Fill the left with ones
        }
        printf("%s: pDDD64: Exponent: %ld, Significand: 0x%lx, Full value: 0x%lx\n", label, exp, sig, f);
    }
}

static void assert_p_adic_CCC_64(const char* label, pDDD64_t f, uint64_t expected_exp, uint64_t expected_sig) {
    if (C_P_ADIC_CCC_64_DEBUG) {
        print_p_adic_CCC_64(label, f);
        printf("expected exp: 0x%lx\n", expected_exp << SIGNIFICAND_BITS_P_CCC_64);
        printf("actual exp  : 0x%llx\n", f & EXPONENT_MASK_P_CCC_64);
        printf("expected sig: 0x%lx\n", expected_sig);
        printf("actual sig  : 0x%llx\n", f & SIGNIFICAND_MASK_P_CCC_64);
    }
    assert((f & EXPONENT_MASK_P_CCC_64) == expected_exp << SIGNIFICAND_BITS_P_CCC_64);
    assert((f & SIGNIFICAND_MASK_P_CCC_64) == expected_sig);
}

static void test_addition() {
    printf("Testing addition...\n");

    // Test case 1: Simple addition
    pDDD64_t a = new_pDDD64(2, 5ULL); // 000...0101. × 2^2
    pDDD64_t b = new_pDDD64(2, 6ULL); // 000...0110. × 2^2
    pDDD64_t result = add_pDDD64(a, b); // 00...010110. × 2^55
    assert_p_adic_CCC_64(
        "Addition result 1", result,
        2ULL,
        0xbULL
    );

    // Test case 2: Addition on max positive significand
    a = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1)) - 1); // 011111...11. × 2^2
    b = new_pDDD64(2, 1); // 000000...01. × 2^2
    result = add_pDDD64(a, b); // 0000...01. × 2^58
    assert_p_adic_CCC_64(
        "Addition result 2", result,
        58ULL,
        1ULL
    );

    // Test case 3: Addition with different exponents
    a = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^3
    b = new_pDDD64(1, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^1
    result = add_pDDD64(a, b); // 01000...0101. × 2^1
    assert_p_adic_CCC_64(
        "Addition result 3", result,
        1ULL,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 5ULL
    );

    // Test case 4: Addition symmetry
    a = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^3
    b = new_pDDD64(1, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^1
    result = add_pDDD64(b, a); // 01000...0101. × 2^1
    assert_p_adic_CCC_64(
        "Addition result 4", result,
        1ULL,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 5ULL
    );

    // Test case 5: Very big exponent
    a = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^3
    b = new_pDDD64(54, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^54
    result = add_pDDD64(b, a); // 0100010...001. × 2^3
    assert_p_adic_CCC_64(
        "Addition result 5", result,
        3ULL,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 6)) | 1ULL
    );

    // Test case 6: Two big exponent
    a = new_pDDD64(41, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^41
    b = new_pDDD64(52, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^52
    result = add_pDDD64(b, a); // 010000...001. × 2^41
    assert_p_adic_CCC_64(
        "Addition result 6", result,
        41ULL,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | (1ULL << 11) | 1ULL
    );
}

static void test_subtraction() {
    printf("Testing subtraction...\n");

    // Test case 1: Subtraction returns zero
    pDDD64_t a = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 4ULL); // 010000...100. × 2^2
    pDDD64_t b = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 4ULL); // 010000...100. × 2^2
    pDDD64_t result = sub_pDDD64(a, b); // 00000...00. × 2^0
    assert_p_adic_CCC_64(
        "Subtraction result 1", result,
        0ULL, 0ULL
    );

    // Test case 2: Simple subtraction
    a = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 4ULL); // 010000...100. × 2^2
    b = new_pDDD64(2, 1ULL); // 000000...001. × 2^2
    result = sub_pDDD64(a, b); // 010000...011. × 2^2
    assert_p_adic_CCC_64(
        "Subtraction result 2", result,
        2ULL,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 3ULL
    );

    // Test case 3: Subtraction requiring normalization
    a = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 4ULL); // 010000...100. × 2^2
    b = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 3ULL); // 010000...011. × 2^2
    result = sub_pDDD64(a, b); // 00000...0001. × 2^2
    assert_p_adic_CCC_64(
        "Subtraction result 3", result,
        2ULL,
        1ULL
    );

    // Test case 4: Subtraction with different exponents
    a = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 3)) | 1ULL); // 0010000...01. × 2^3
    b = new_pDDD64(1, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 3)) | 1ULL); // 0010000...01. × 2^1
    result = sub_pDDD64(a, b); // 0110...011. × 2^1
    assert_p_adic_CCC_64(
        "Subtraction result 4", result,
        1ULL,
        (3ULL << (SIGNIFICAND_BITS_P_CCC_64 - 3)) | 3ULL
    );

    // Test case 5: Subtraction anti-symmetry
    a = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 3)) | 1ULL); // 0010000...01. × 2^3
    b = new_pDDD64(1, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 3)) | 1ULL); // 0010000...01. × 2^1
    result = add_pDDD64(neg_pDDD64(b), a); // 0110...0011. × 2^1
    assert_p_adic_CCC_64(
        "Subtraction result 5", result,
        1ULL,
        (3ULL << (SIGNIFICAND_BITS_P_CCC_64 - 3)) | 3ULL
    );

    // Test case 6: Subtraction reverse of addition
    a = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^3
    b = new_pDDD64(1, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^1
    result = sub_pDDD64(add_pDDD64(b, a), a); // Should return b
    assert_p_adic_CCC_64(
        "Subtraction result 6", result,
        1ULL,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL
    );
}

static void test_multiplication() {
    printf("Testing multiplication...\n");

    // Test case 1: Simple multiplication with inverse
    pDDD64_t a = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^3
    pDDD64_t b = new_pDDD64(2, (7ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 111000...01. × 2^2
    pDDD64_t result = mul_pDDD64(a, b); // 0.00000...001 × 2^1
    assert_p_adic_CCC_64(
        "Multiplication result 1", result,
        5ULL,
        1ULL
    );

    // Test case 2: Simple multiplication without normalization
    a = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^2
    b = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^3
    result = mul_pDDD64(a, b); // 0100000...01. × 2^5
    assert_p_adic_CCC_64(
        "Multiplication result 2", result,
        5ULL,
        ((1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1)) | 1ULL)
    );

    // Test case 3: Multiplication both positive
    a = new_pDDD64(1, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1)) - 1); // 011111...11. × 2^1
    b = new_pDDD64(1, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1)) - 1); // 011111...11. × 2^1
    result = mul_pDDD64(a, b); // 0.0000...001 × 2^2
    assert_p_adic_CCC_64(
        "Multiplication result 3", result,
        2ULL,
        1ULL
    );

    // Test case 4: Multiplication both negative
    a = new_pDDD64(1, neg_pDDD64(1)); // 111111...11. × 2^1
    b = new_pDDD64(1, ((1ULL << (SIGNIFICAND_BITS_P_CCC_64 / 2)) - 1) << (SIGNIFICAND_BITS_P_CCC_64 /  2) ); // 111100...00. × 2^1
    result = mul_pDDD64(a, b); // 01111...001. × 2^2
    assert_p_adic_CCC_64(
        "Multiplication result 4", result,
        30ULL,
        ((1ULL << (SIGNIFICAND_BITS_P_CCC_64 / 2 + 1)) - 1) << (SIGNIFICAND_BITS_P_CCC_64 /  2) | 1ULL
    );

    // Test case 5: Multiplication one negative
    a = new_pDDD64(1, neg_pDDD64(1)); // 111111...11. × 2^1
    b = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^3
    result = mul_pDDD64(a, b); // 010...000. × 2^4
    assert_p_adic_CCC_64(
        "Multiplication result 5", result,
        4ULL,
        ((neg_pDDD64(5) << (SIGNIFICAND_BITS_P_CCC_64 - 1)) & SIGNIFICAND_MASK_P_CCC_64) | ((1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) - 1)
    );

    // Test case 6: Multiplication symmetry
    a = new_pDDD64(1, neg_pDDD64(1)); // 111111...11. × 2^1
    b = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 010000...01. × 2^3
    result = mul_pDDD64(b, a); // 010...000. × 2^4
    assert_p_adic_CCC_64(
        "Multiplication result 6", result,
        4ULL,
        ((neg_pDDD64(5) << (SIGNIFICAND_BITS_P_CCC_64 - 1)) &  SIGNIFICAND_MASK_P_CCC_64) | ((1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) - 1)
    );
}

static void test_division() {
    printf("Testing division...\n");

    // Test case 1: Division returns one
    pDDD64_t a = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^2
    pDDD64_t b = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 0.10000...01 × 2^2
    pDDD64_t result = div_pDDD64(a, b); // 0000...01. × 2^0
    assert_p_adic_CCC_64(
        "Division result 1", result,
        0ULL,
        1ULL
    );

    // Test case 2: Simple division
    a = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 01000...001. × 2^3
    b = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 2ULL); // 01000...010. × 2^2
    result = div_pDDD64(a, b); // 011...11. × 2^1
    assert_p_adic_CCC_64(
        "Division result 2", result,
        0ULL,
        (3ULL << (SIGNIFICAND_BITS_P_CCC_64 - 3)) | 1ULL
    );

    // Test case 3: Division of a positive number by zero
    a = new_pDDD64(2, 1); // 000000...01. × 2^2
    b = new_pDDD64(4, 0); // 0
    result = div_pDDD64(a, b); // Should return max value as "infinity"
    assert_p_adic_CCC_64(
        "Division result 3", result,
        (1ULL << (EXPONENT_BITS_P_CCC_64 - 2)) - 1,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) - 1
    );

    // Test case 4: Division of a negative number by zero
    a = new_pDDD64(2, neg_pDDD64(1)); // 11111...11. × 2^2
    b = new_pDDD64(4, 0); // 0
    result = div_pDDD64(a, b); // Should return min value as "-infinity"
    assert_p_adic_CCC_64(
        "Division result 4", result,
        (1ULL << (EXPONENT_BITS_P_CCC_64 - 2)) - 1,
        1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1)
    );

    // Test case 5: Division reverse of multiplication for small positive numbers
    a = new_pDDD64(0, 1ULL); // 00000...001. × 2^0
    b = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 2ULL); // 01000...010. × 2^2
    result = div_pDDD64(mul_pDDD64(a, b), b); // Should return a
    assert_p_adic_CCC_64(
        "Division result 5", result,
        0ULL,
        1ULL
    );

    // Test case 6: Division reverse of multiplication for big positive numbers
    a = new_pDDD64(2, 1); // 0000...01. × 2^2
    b = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 0100...01. × 2^3
    result = div_pDDD64(mul_pDDD64(b, a), a); // Should return b
    assert_p_adic_CCC_64(
        "Division result 6", result,
        3ULL,
        1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2) | 1ULL
    );

    // Test case 7: Division reverse of multiplication for small negative numbers
    a = new_pDDD64(1, neg_pDDD64(1)); // 1111...1. × 2^0
    b = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 0100...01. × 2^3
    result = div_pDDD64(mul_pDDD64(a, b), b); // Should return a
    assert_p_adic_CCC_64(
        "Division result 7", result,
        1ULL,
        neg_pDDD64(1)
    );

    // Test case 8: Division reverse of multiplication for big negative numbers
    a = new_pDDD64(2, neg_pDDD64(1)); // 0000...01. × 2^2
    b = new_pDDD64(3, (3ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1)) | 1ULL); // 1100...01. × 2^3
    result = div_pDDD64(mul_pDDD64(b, a), a); // Should return b
    assert_p_adic_CCC_64(
        "Division result 8", result,
        3ULL,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1)) | 1ULL
    );

    // Test case 9: Division reverse of multiplication for small positive numbers
    a = new_pDDD64(0, 1ULL); // 00000...001. × 2^0
    b = new_pDDD64(2, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 2ULL); // 01000...010. × 2^2
    result = mul_pDDD64(div_pDDD64(a, b), b); // Should return a
    assert_p_adic_CCC_64(
        "Division result 9", result,
        0ULL,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL
    );

    // Test case 10: Division reverse of multiplication for big positive numbers
    a = new_pDDD64(2, 1); // 0000...01. × 2^2
    b = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 0100...01. × 2^3
    result = mul_pDDD64(div_pDDD64(b, a), a); // Should return b
    assert_p_adic_CCC_64(
        "Division result 10", result,
        3ULL,
        1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2) | 1ULL
    );

    // Test case 11: Division reverse of multiplication for small negative numbers
    a = new_pDDD64(1, neg_pDDD64(1)); // 1111...1. × 2^0
    b = new_pDDD64(3, (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 2)) | 1ULL); // 0100...01. × 2^3
    result = mul_pDDD64(div_pDDD64(a, b), b); // Should return a
    assert_p_adic_CCC_64(
        "Division result 11", result,
        1ULL,
        neg_pDDD64(1) >> 1
    );

    // Test case 12: Division reverse of multiplication for big negative numbers
    a = new_pDDD64(2, neg_pDDD64(1)); // 0000...01. × 2^2
    b = new_pDDD64(3, (3ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1)) | 1ULL); // 1100...01. × 2^3
    result = mul_pDDD64(div_pDDD64(b, a), a); // Should return b
    assert_p_adic_CCC_64(
        "Division result 12", result,
        3ULL,
        (1ULL << (SIGNIFICAND_BITS_P_CCC_64 - 1)) | 1ULL
    );
}

static void test_equals_and_compare() {
    printf("Testing equals and compare...\n");

    pDDD64_t a = new_pDDD64(2, 1); // 1.0000...01 × 2^2
    pDDD64_t b = new_pDDD64(2, 1); // 1.0000...01 × 2^2
    pDDD64_t c = new_pDDD64(2, 2); // 1.0000...10 × 2^2
    pDDD64_t d = new_pDDD64(3, 1); // 1.0000...01 × 2^3

    assert(equ_pDDD64(a, b));
    assert(!equ_pDDD64(a, c));
    assert(!equ_pDDD64(a, d));

    assert(com_pDDD64(a, b) == 0);
    assert(com_pDDD64(a, c) < 0);
    assert(com_pDDD64(c, a) > 0);
    assert(com_pDDD64(a, d) < 0);
    assert(com_pDDD64(d, a) > 0);
}

int main() {
    test_addition();
    test_subtraction();
    test_multiplication();
    test_division();
    test_equals_and_compare();

    printf("All p-adic CCC_64 tests passed!\n");
    return 0;
}

