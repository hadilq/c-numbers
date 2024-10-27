#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "c_p_adic_11_05.h"

static void print_p_adic_11_05(const char* label, p1105_t f) {
    if (C_P_ADIC_11_05_DEBUG) {
        uint32_t exp = (f & EXPONENT_MASK_P_11_05) >> SIGNIFICAND_BITS_P_11_05;
        uint32_t sig = f & SIGNIFICAND_MASK_P_11_05;

        if ((1U << (SIGNIFICAND_BITS_P_11_05 - 1) & sig)) {
            sig |= ((1U << EXPONENT_BITS_P_11_05) - 1) << SIGNIFICAND_BITS_P_11_05; // Fill the left with ones
        }
        if ((1U << (EXPONENT_BITS_P_11_05 - 1) & exp)) {
            exp |= ((1U << SIGNIFICAND_BITS_P_11_05) - 1) << EXPONENT_BITS_P_11_05; // Fill the left with ones
        }
        printf("%s: p1105: Exponent: %ld, Significand: 0x%lx, FU value: 0x%lx\n", label, exp, sig, f);
    }
}

static void assert_p_adic_11_05(const char* label, p1105_t f, uint32_t expected_exp, uint32_t expected_sig) {
    if (C_P_ADIC_11_05_DEBUG) {
        print_p_adic_11_05(label, f);
        printf("expected exp: 0x%x\n", expected_exp << SIGNIFICAND_BITS_P_11_05);
        printf("actual exp  : 0x%x\n", f & EXPONENT_MASK_P_11_05);
        printf("expected sig: 0x%x\n", expected_sig);
        printf("actual sig  : 0x%x\n", f & SIGNIFICAND_MASK_P_11_05);
    }
    assert((f & EXPONENT_MASK_P_11_05) == expected_exp << SIGNIFICAND_BITS_P_11_05);
    assert((f & SIGNIFICAND_MASK_P_11_05) == expected_sig);
}

static void test_addition() {
    printf("Testing addition...\n");

    // Test case 1: Simple addition
    p1105_t a = new_p1105(2, 5U); // 000...0101. × 2^2
    p1105_t b = new_p1105(2, 6U); // 000...0110. × 2^2
    p1105_t result = add_p1105(a, b); // 00...010110. × 2^55
    assert_p_adic_11_05(
        "Addition result 1", result,
        2U,
        0xbU
    );

    // Test case 2: Addition on max positive significand
    a = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 1)) - 1); // 011111...11. × 2^2
    b = new_p1105(2, 1); // 000000...01. × 2^2
    result = add_p1105(a, b); // 0000...01. × 2^12
    assert_p_adic_11_05(
        "Addition result 2", result,
        12U,
        1U
    );

    // Test case 3: Addition with different exponents
    a = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^3
    b = new_p1105(1, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^1
    result = add_p1105(a, b); // 01000...0101. × 2^1
    assert_p_adic_11_05(
        "Addition result 3", result,
        1U,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 5U
    );

    // Test case 4: Addition symmetry
    a = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^3
    b = new_p1105(1, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^1
    result = add_p1105(b, a); // 01000...0101. × 2^1
    assert_p_adic_11_05(
        "Addition result 4", result,
        1U,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 5U
    );

    // Test case 5: Very big exponent
    a = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^3
    b = new_p1105(54, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^54
    result = add_p1105(b, a); // 01000010...001. × 2^3
    assert_p_adic_11_05(
        "Addition result 5", result,
        3U,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U
    );

    // Test case 6: Two big exponent
    a = new_p1105(41, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^41
    b = new_p1105(52, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^52
    result = add_p1105(b, a); // 010000...001. × 2^41
    assert_p_adic_11_05(
        "Addition result 6", result,
        9U,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U
    );
}

static void test_subtraction() {
    printf("Testing subtraction...\n");

    // Test case 1: Subtraction returns zero
    p1105_t a = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 4U); // 010000...100. × 2^2
    p1105_t b = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 4U); // 010000...100. × 2^2
    p1105_t result = sub_p1105(a, b); // 00000...00. × 2^0
    assert_p_adic_11_05(
        "Subtraction result 1", result,
        0U, 0U
    );

    // Test case 2: Simple subtraction
    a = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 4U); // 010000...100. × 2^2
    b = new_p1105(2, 1U); // 000000...001. × 2^2
    result = sub_p1105(a, b); // 010000...011. × 2^2
    assert_p_adic_11_05(
        "Subtraction result 2", result,
        2U,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 3U
    );

    // Test case 3: Subtraction requiring normalization
    a = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 4U); // 010000...100. × 2^2
    b = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 3U); // 010000...011. × 2^2
    result = sub_p1105(a, b); // 00000...0001. × 2^2
    assert_p_adic_11_05(
        "Subtraction result 3", result,
        2U,
        1U
    );

    // Test case 4: Subtraction with different exponents
    a = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 3)) | 1U); // 0010000...01. × 2^3
    b = new_p1105(1, (1U << (SIGNIFICAND_BITS_P_11_05 - 3)) | 1U); // 0010000...01. × 2^1
    result = sub_p1105(a, b); // 0110...011. × 2^1
    assert_p_adic_11_05(
        "Subtraction result 4", result,
        1U,
        (3U << (SIGNIFICAND_BITS_P_11_05 - 3)) | 3U
    );

    // Test case 5: Subtraction anti-symmetry
    a = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 3)) | 1U); // 0010000...01. × 2^3
    b = new_p1105(1, (1U << (SIGNIFICAND_BITS_P_11_05 - 3)) | 1U); // 0010000...01. × 2^1
    result = add_p1105(neg_p1105(b), a); // 0110...0011. × 2^1
    assert_p_adic_11_05(
        "Subtraction result 5", result,
        1U,
        (3U << (SIGNIFICAND_BITS_P_11_05 - 3)) | 3U
    );

    // Test case 6: Subtraction reverse of addition
    a = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^3
    b = new_p1105(1, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^1
    result = sub_p1105(add_p1105(b, a), a); // Should return b
    assert_p_adic_11_05(
        "Subtraction result 6", result,
        1U,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U
    );
}

static void test_multiplication() {
    printf("Testing multiplication...\n");

    // Test case 1: Simple multiplication with inverse
    p1105_t a = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^3
    p1105_t b = new_p1105(2, (7U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 111000...01. × 2^2
    p1105_t result = mul_p1105(a, b); // 0.00000...001 × 2^1
    assert_p_adic_11_05(
        "Multiplication result 1", result,
        5U,
        1U
    );

    // Test case 2: Simple multiplication without normalization
    a = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^2
    b = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^3
    result = mul_p1105(a, b); // 0100000...01. × 2^5
    assert_p_adic_11_05(
        "Multiplication result 2", result,
        5U,
        ((1U << (SIGNIFICAND_BITS_P_11_05 - 1)) | 1U)
    );

    // Test case 3: Multiplication both positive
    a = new_p1105(1, (1U << (SIGNIFICAND_BITS_P_11_05 - 1)) - 1); // 011111...11. × 2^1
    b = new_p1105(1, (1U << (SIGNIFICAND_BITS_P_11_05 - 1)) - 1); // 011111...11. × 2^1
    result = mul_p1105(a, b); // 0.0000...001 × 2^2
    assert_p_adic_11_05(
        "Multiplication result 3", result,
        2U,
        1U
    );

    // Test case 4: Multiplication both negative
    a = new_p1105(1, neg_p1105(1)); // 111111...11. × 2^1
    b = new_p1105(1, ((1U << (SIGNIFICAND_BITS_P_11_05 / 2)) - 1) << (SIGNIFICAND_BITS_P_11_05 /  2) ); // 111100...00. × 2^1
    result = mul_p1105(a, b); // 01111...001. × 2^2
    assert_p_adic_11_05(
        "Multiplication result 4", result,
        7U,
        (((1U << 6) - 1) << 5) | 1U
    );

    // Test case 5: Multiplication one negative
    a = new_p1105(1, neg_p1105(1)); // 111111...11. × 2^1
    b = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^3
    result = mul_p1105(a, b); // 010...000. × 2^4
    assert_p_adic_11_05(
        "Multiplication result 5", result,
        4U,
        ((neg_p1105(5) << (SIGNIFICAND_BITS_P_11_05 - 1)) & SIGNIFICAND_MASK_P_11_05) | ((1U << (SIGNIFICAND_BITS_P_11_05 - 2)) - 1)
    );

    // Test case 6: Multiplication symmetry
    a = new_p1105(1, neg_p1105(1)); // 111111...11. × 2^1
    b = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 010000...01. × 2^3
    result = mul_p1105(b, a); // 010...000. × 2^4
    assert_p_adic_11_05(
        "Multiplication result 6", result,
        4U,
        ((neg_p1105(5) << (SIGNIFICAND_BITS_P_11_05 - 1)) &  SIGNIFICAND_MASK_P_11_05) | ((1U << (SIGNIFICAND_BITS_P_11_05 - 2)) - 1)
    );
}

static void test_division() {
    printf("Testing division...\n");

    // Test case 1: Division returns one
    p1105_t a = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 0.10000...01 × 2^2
    p1105_t b = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 0.10000...01 × 2^2
    p1105_t result = div_p1105(a, b); // 0000...01. × 2^0
    assert_p_adic_11_05(
        "Division result 1", result,
        0U,
        1U
    );

    // Test case 2: Simple division
    a = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 01000...001. × 2^3
    b = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 2U); // 01000...010. × 2^2
    result = div_p1105(a, b); // 011...11. × 2^1
    assert_p_adic_11_05(
        "Division result 2", result,
        0U,
        (3U << (SIGNIFICAND_BITS_P_11_05 - 3)) | 1U
    );

    // Test case 3: Division of a positive number by zero
    a = new_p1105(2, 1); // 000000...01. × 2^2
    b = new_p1105(4, 0); // 0
    result = div_p1105(a, b); // Should return max value as "infinity"
    assert_p_adic_11_05(
        "Division result 3", result,
        (1U << (EXPONENT_BITS_P_11_05 - 2)) - 1,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) - 1
    );

    // Test case 4: Division of a negative number by zero
    a = new_p1105(2, neg_p1105(1)); // 11111...11. × 2^2
    b = new_p1105(4, 0); // 0
    result = div_p1105(a, b); // Should return min value as "-infinity"
    assert_p_adic_11_05(
        "Division result 4", result,
        (1U << (EXPONENT_BITS_P_11_05 - 2)) - 1,
        1U << (SIGNIFICAND_BITS_P_11_05 - 1)
    );

    // Test case 5: Division reverse of multiplication for small positive numbers
    a = new_p1105(0, 1U); // 00000...001. × 2^0
    b = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 2U); // 01000...010. × 2^2
    result = div_p1105(mul_p1105(a, b), b); // Should return a
    assert_p_adic_11_05(
        "Division result 5", result,
        0U,
        1U
    );

    // Test case 6: Division reverse of multiplication for big positive numbers
    a = new_p1105(2, 1); // 0000...01. × 2^2
    b = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 0100...01. × 2^3
    result = div_p1105(mul_p1105(b, a), a); // Should return b
    assert_p_adic_11_05(
        "Division result 6", result,
        3U,
        1U << (SIGNIFICAND_BITS_P_11_05 - 2) | 1U
    );

    // Test case 7: Division reverse of multiplication for small negative numbers
    a = new_p1105(1, neg_p1105(1)); // 1111...1. × 2^0
    b = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 0100...01. × 2^3
    result = div_p1105(mul_p1105(a, b), b); // Should return a
    assert_p_adic_11_05(
        "Division result 7", result,
        1U,
        neg_p1105(1)
    );

    // Test case 8: Division reverse of multiplication for big negative numbers
    a = new_p1105(2, neg_p1105(1)); // 0000...01. × 2^2
    b = new_p1105(3, (3U << (SIGNIFICAND_BITS_P_11_05 - 1)) | 1U); // 1100...01. × 2^3
    result = div_p1105(mul_p1105(b, a), a); // Should return b
    assert_p_adic_11_05(
        "Division result 8", result,
        3U,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 1)) | 1U
    );

    // Test case 9: Division reverse of multiplication for small positive numbers
    a = new_p1105(0, 1U); // 00000...001. × 2^0
    b = new_p1105(2, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 2U); // 01000...010. × 2^2
    result = mul_p1105(div_p1105(a, b), b); // Should return a
    assert_p_adic_11_05(
        "Division result 9", result,
        0U,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U
    );

    // Test case 10: Division reverse of multiplication for big positive numbers
    a = new_p1105(2, 1); // 0000...01. × 2^2
    b = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 0100...01. × 2^3
    result = mul_p1105(div_p1105(b, a), a); // Should return b
    assert_p_adic_11_05(
        "Division result 10", result,
        3U,
        1U << (SIGNIFICAND_BITS_P_11_05 - 2) | 1U
    );

    // Test case 11: Division reverse of multiplication for small negative numbers
    a = new_p1105(1, neg_p1105(1)); // 1111...1. × 2^0
    b = new_p1105(3, (1U << (SIGNIFICAND_BITS_P_11_05 - 2)) | 1U); // 0100...01. × 2^3
    result = mul_p1105(div_p1105(a, b), b); // Should return a
    assert_p_adic_11_05(
        "Division result 11", result,
        1U,
        neg_p1105(1) >> 1
    );

    // Test case 12: Division reverse of multiplication for big negative numbers
    a = new_p1105(2, neg_p1105(1)); // 0000...01. × 2^2
    b = new_p1105(3, (3U << (SIGNIFICAND_BITS_P_11_05 - 1)) | 1U); // 1100...01. × 2^3
    result = mul_p1105(div_p1105(b, a), a); // Should return b
    assert_p_adic_11_05(
        "Division result 12", result,
        3U,
        (1U << (SIGNIFICAND_BITS_P_11_05 - 1)) | 1U
    );
}

static void test_equals_and_compare() {
    printf("Testing equals and compare...\n");

    p1105_t a = new_p1105(2, 1); // 1.0000...01 × 2^2
    p1105_t b = new_p1105(2, 1); // 1.0000...01 × 2^2
    p1105_t c = new_p1105(2, 2); // 1.0000...10 × 2^2
    p1105_t d = new_p1105(3, 1); // 1.0000...01 × 2^3

    assert(equ_p1105(a, b));
    assert(!equ_p1105(a, c));
    assert(!equ_p1105(a, d));

    assert(com_p1105(a, b) == 0);
    assert(com_p1105(a, c) < 0);
    assert(com_p1105(c, a) > 0);
    assert(com_p1105(a, d) < 0);
    assert(com_p1105(d, a) > 0);
}

int main() {
    test_addition();
    test_subtraction();
    test_multiplication();
    test_division();
    test_equals_and_compare();

    printf("All p-adic 11_05 tests passed!\n");
    return 0;
}

