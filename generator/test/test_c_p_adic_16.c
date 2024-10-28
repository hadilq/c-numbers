#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "c_p_adic_16.h"

static void print_p_adic_CCC_16(const char* label, pDDD16_t f) {
    if (C_P_ADIC_CCC_16_DEBUG) {
        uint16_t exp = (f & EXPONENT_MASK_P_CCC_16) >> SIGNIFICAND_BITS_P_CCC_16;
        uint16_t sig = f & SIGNIFICAND_MASK_P_CCC_16;

        if ((1U << (SIGNIFICAND_BITS_P_CCC_16 - 1) & sig)) {
            sig |= ((1U << EXPONENT_BITS_P_CCC_16) - 1) << SIGNIFICAND_BITS_P_CCC_16; // Fill the left with ones
        }
        if ((1U << (EXPONENT_BITS_P_CCC_16 - 1) & exp)) {
            exp |= ((1U << SIGNIFICAND_BITS_P_CCC_16) - 1) << EXPONENT_BITS_P_CCC_16; // Fill the left with ones
        }
        printf("%s: pDDD16: Exponent: %ld, Significand: 0x%lx, FU value: 0x%lx\n", label, exp, sig, f);
    }
}

static void assert_p_adic_CCC_16(const char* label, pDDD16_t f, uint16_t expected_exp, uint16_t expected_sig) {
    if (C_P_ADIC_CCC_16_DEBUG) {
        print_p_adic_CCC_16(label, f);
        printf("expected exp: 0x%x\n", expected_exp << SIGNIFICAND_BITS_P_CCC_16);
        printf("actual exp  : 0x%x\n", f & EXPONENT_MASK_P_CCC_16);
        printf("expected sig: 0x%x\n", expected_sig);
        printf("actual sig  : 0x%x\n", f & SIGNIFICAND_MASK_P_CCC_16);
    }
    assert((f & EXPONENT_MASK_P_CCC_16) == (expected_exp << SIGNIFICAND_BITS_P_CCC_16));
    assert((f & SIGNIFICAND_MASK_P_CCC_16) == expected_sig);
}

static void test_addition() {
    printf("Testing addition...\n");

    // Test case 1: Simple addition
    pDDD16_t a = new_pDDD16(2, 5U); // 000...0101. × 2^2
    pDDD16_t b = new_pDDD16(2, 6U); // 000...0110. × 2^2
    pDDD16_t result = add_pDDD16(a, b); // 00...010110. × 2^55
    assert_p_adic_CCC_16(
        "Addition result 1", result,
        2U,
        0xbU
    );

    // Test case 2: Addition on max positive significand
    a = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 1)) - 1); // 011111...11. × 2^2
    b = new_pDDD16(2, 1); // 000000...01. × 2^2
    result = add_pDDD16(a, b); // 0000...01. × 2^12
    assert_p_adic_CCC_16(
        "Addition result 2", result,
        12U,
        1U
    );

    // Test case 3: Addition with different exponents
    a = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^3
    b = new_pDDD16(1, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^1
    result = add_pDDD16(a, b); // 01000...0101. × 2^1
    assert_p_adic_CCC_16(
        "Addition result 3", result,
        1U,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 5U
    );

    // Test case 4: Addition symmetry
    a = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^3
    b = new_pDDD16(1, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^1
    result = add_pDDD16(b, a); // 01000...0101. × 2^1
    assert_p_adic_CCC_16(
        "Addition result 4", result,
        1U,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 5U
    );

    // Test case 5: Very big exponent
    a = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^3
    b = new_pDDD16(-1, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^-1
    result = add_pDDD16(b, a); // 01000010...001. × 2^-1
    assert_p_adic_CCC_16(
        "Addition result 5", result,
        (1U << EXPONENT_BITS_P_CCC_16) - 1,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | (1U << 4) | 1U
    );

    // Test case 6: Two big exponent
    a = new_pDDD16(17, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^17
    b = new_pDDD16(30, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^30
    result = add_pDDD16(b, a); // 010000...001. × 2^17
    assert_p_adic_CCC_16(
        "Addition result 6", result,
        17U,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U
    );
}

static void test_subtraction() {
    printf("Testing subtraction...\n");

    // Test case 1: Subtraction returns zero
    pDDD16_t a = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 4U); // 010000...100. × 2^2
    pDDD16_t b = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 4U); // 010000...100. × 2^2
    pDDD16_t result = sub_pDDD16(a, b); // 00000...00. × 2^0
    assert_p_adic_CCC_16(
        "Subtraction result 1", result,
        0U, 0U
    );

    // Test case 2: Simple subtraction
    a = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 4U); // 010000...100. × 2^2
    b = new_pDDD16(2, 1U); // 000000...001. × 2^2
    result = sub_pDDD16(a, b); // 010000...011. × 2^2
    assert_p_adic_CCC_16(
        "Subtraction result 2", result,
        2U,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 3U
    );

    // Test case 3: Subtraction requiring normalization
    a = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 4U); // 010000...100. × 2^2
    b = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 3U); // 010000...011. × 2^2
    result = sub_pDDD16(a, b); // 00000...0001. × 2^2
    assert_p_adic_CCC_16(
        "Subtraction result 3", result,
        2U,
        1U
    );

    // Test case 4: Subtraction with different exponents
    a = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 3)) | 1U); // 0010000...01. × 2^3
    b = new_pDDD16(1, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 3)) | 1U); // 0010000...01. × 2^1
    result = sub_pDDD16(a, b); // 0110...011. × 2^1
    assert_p_adic_CCC_16(
        "Subtraction result 4", result,
        1U,
        (3U << (SIGNIFICAND_BITS_P_CCC_16 - 3)) | 3U
    );

    // Test case 5: Subtraction anti-symmetry
    a = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 3)) | 1U); // 0010000...01. × 2^3
    b = new_pDDD16(1, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 3)) | 1U); // 0010000...01. × 2^1
    result = add_pDDD16(neg_pDDD16(b), a); // 0110...0011. × 2^1
    assert_p_adic_CCC_16(
        "Subtraction result 5", result,
        1U,
        (3U << (SIGNIFICAND_BITS_P_CCC_16 - 3)) | 3U
    );

    // Test case 6: Subtraction reverse of addition
    a = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^3
    b = new_pDDD16(1, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^1
    result = sub_pDDD16(add_pDDD16(b, a), a); // Should return b
    assert_p_adic_CCC_16(
        "Subtraction result 6", result,
        1U,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U
    );
}

static void test_multiplication() {
    printf("Testing multiplication...\n");

    // Test case 1: Simple multiplication with inverse
    pDDD16_t a = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^3
    pDDD16_t b = new_pDDD16(2, (7U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 111000...01. × 2^2
    pDDD16_t result = mul_pDDD16(a, b); // 0.00000...001 × 2^1
    assert_p_adic_CCC_16(
        "Multiplication result 1", result,
        5U,
        1U
    );

    // Test case 2: Simple multiplication without normalization
    a = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^2
    b = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^3
    result = mul_pDDD16(a, b); // 0100000...01. × 2^5
    assert_p_adic_CCC_16(
        "Multiplication result 2", result,
        5U,
        ((1U << (SIGNIFICAND_BITS_P_CCC_16 - 1)) | 1U)
    );

    // Test case 3: Multiplication both positive
    a = new_pDDD16(1, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 1)) - 1); // 011111...11. × 2^1
    b = new_pDDD16(1, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 1)) - 1); // 011111...11. × 2^1
    result = mul_pDDD16(a, b); // 0.0000...001 × 2^2
    assert_p_adic_CCC_16(
        "Multiplication result 3", result,
        2U,
        1U
    );

    // Test case 4: Multiplication both negative
    a = new_pDDD16(1, neg_pDDD16(1)); // 111111...11. × 2^1
    b = new_pDDD16(1, ((1U << (SIGNIFICAND_BITS_P_CCC_16 / 2)) - 1) << (SIGNIFICAND_BITS_P_CCC_16 /  2) ); // 111100...00. × 2^1
    result = mul_pDDD16(a, b); // 01111...001. × 2^2
    assert_p_adic_CCC_16(
        "Multiplication result 4", result,
        7U,
        (((1U << 6) - 1) << 5) | 1U
    );

    // Test case 5: Multiplication one negative
    a = new_pDDD16(1, neg_pDDD16(1)); // 111111...11. × 2^1
    b = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^3
    result = mul_pDDD16(a, b); // 010...000. × 2^4
    assert_p_adic_CCC_16(
        "Multiplication result 5", result,
        4U,
        ((neg_pDDD16(5) << (SIGNIFICAND_BITS_P_CCC_16 - 1)) & SIGNIFICAND_MASK_P_CCC_16) | ((1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) - 1)
    );

    // Test case 6: Multiplication symmetry
    a = new_pDDD16(1, neg_pDDD16(1)); // 111111...11. × 2^1
    b = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 010000...01. × 2^3
    result = mul_pDDD16(b, a); // 010...000. × 2^4
    assert_p_adic_CCC_16(
        "Multiplication result 6", result,
        4U,
        ((neg_pDDD16(5) << (SIGNIFICAND_BITS_P_CCC_16 - 1)) &  SIGNIFICAND_MASK_P_CCC_16) | ((1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) - 1)
    );
}

static void test_division() {
    printf("Testing division...\n");

    // Test case 1: Division returns one
    pDDD16_t a = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 0.10000...01 × 2^2
    pDDD16_t b = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 0.10000...01 × 2^2
    pDDD16_t result = div_pDDD16(a, b); // 0000...01. × 2^0
    assert_p_adic_CCC_16(
        "Division result 1", result,
        0U,
        1U
    );

    // Test case 2: Simple division
    a = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 01000...001. × 2^3
    b = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 2U); // 01000...010. × 2^2
    result = div_pDDD16(a, b); // 011...11. × 2^1
    assert_p_adic_CCC_16(
        "Division result 2", result,
        0U,
        (3U << (SIGNIFICAND_BITS_P_CCC_16 - 3)) | 1U
    );

    // Test case 3: Division of a positive number by zero
    a = new_pDDD16(2, 1); // 000000...01. × 2^2
    b = new_pDDD16(4, 0); // 0
    result = div_pDDD16(a, b); // Should return max value as "infinity"
    assert_p_adic_CCC_16(
        "Division result 3", result,
        (1U << (EXPONENT_BITS_P_CCC_16 - 2)) - 1,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) - 1
    );

    // Test case 4: Division of a negative number by zero
    a = new_pDDD16(2, neg_pDDD16(1)); // 11111...11. × 2^2
    b = new_pDDD16(4, 0); // 0
    result = div_pDDD16(a, b); // Should return min value as "-infinity"
    assert_p_adic_CCC_16(
        "Division result 4", result,
        (1U << (EXPONENT_BITS_P_CCC_16 - 2)) - 1,
        1U << (SIGNIFICAND_BITS_P_CCC_16 - 1)
    );

    // Test case 5: Division reverse of multiplication for small positive numbers
    a = new_pDDD16(0, 1U); // 00000...001. × 2^0
    b = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 2U); // 01000...010. × 2^2
    result = div_pDDD16(mul_pDDD16(a, b), b); // Should return a
    assert_p_adic_CCC_16(
        "Division result 5", result,
        0U,
        1U
    );

    // Test case 6: Division reverse of multiplication for big positive numbers
    a = new_pDDD16(2, 1); // 0000...01. × 2^2
    b = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 0100...01. × 2^3
    result = div_pDDD16(mul_pDDD16(b, a), a); // Should return b
    assert_p_adic_CCC_16(
        "Division result 6", result,
        3U,
        1U << (SIGNIFICAND_BITS_P_CCC_16 - 2) | 1U
    );

    // Test case 7: Division reverse of multiplication for small negative numbers
    a = new_pDDD16(1, neg_pDDD16(1)); // 1111...1. × 2^0
    b = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 0100...01. × 2^3
    result = div_pDDD16(mul_pDDD16(a, b), b); // Should return a
    assert_p_adic_CCC_16(
        "Division result 7", result,
        1U,
        neg_pDDD16(1)
    );

    // Test case 8: Division reverse of multiplication for big negative numbers
    a = new_pDDD16(2, neg_pDDD16(1)); // 0000...01. × 2^2
    b = new_pDDD16(3, (3U << (SIGNIFICAND_BITS_P_CCC_16 - 1)) | 1U); // 1100...01. × 2^3
    result = div_pDDD16(mul_pDDD16(b, a), a); // Should return b
    assert_p_adic_CCC_16(
        "Division result 8", result,
        3U,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 1)) | 1U
    );

    // Test case 9: Division reverse of multiplication for small positive numbers
    a = new_pDDD16(0, 1U); // 00000...001. × 2^0
    b = new_pDDD16(2, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 2U); // 01000...010. × 2^2
    result = mul_pDDD16(div_pDDD16(a, b), b); // Should return a
    assert_p_adic_CCC_16(
        "Division result 9", result,
        0U,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U
    );

    // Test case 10: Division reverse of multiplication for big positive numbers
    a = new_pDDD16(2, 1); // 0000...01. × 2^2
    b = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 0100...01. × 2^3
    result = mul_pDDD16(div_pDDD16(b, a), a); // Should return b
    assert_p_adic_CCC_16(
        "Division result 10", result,
        3U,
        1U << (SIGNIFICAND_BITS_P_CCC_16 - 2) | 1U
    );

    // Test case 11: Division reverse of multiplication for small negative numbers
    a = new_pDDD16(1, neg_pDDD16(1)); // 1111...1. × 2^0
    b = new_pDDD16(3, (1U << (SIGNIFICAND_BITS_P_CCC_16 - 2)) | 1U); // 0100...01. × 2^3
    result = mul_pDDD16(div_pDDD16(a, b), b); // Should return a
    assert_p_adic_CCC_16(
        "Division result 11", result,
        1U,
        neg_pDDD16(1) >> 1
    );

    // Test case 12: Division reverse of multiplication for big negative numbers
    a = new_pDDD16(2, neg_pDDD16(1)); // 0000...01. × 2^2
    b = new_pDDD16(3, (3U << (SIGNIFICAND_BITS_P_CCC_16 - 1)) | 1U); // 1100...01. × 2^3
    result = mul_pDDD16(div_pDDD16(b, a), a); // Should return b
    assert_p_adic_CCC_16(
        "Division result 12", result,
        3U,
        (1U << (SIGNIFICAND_BITS_P_CCC_16 - 1)) | 1U
    );
}

static void test_equals_and_compare() {
    printf("Testing equals and compare...\n");

    pDDD16_t a = new_pDDD16(2, 1); // 1.0000...01 × 2^2
    pDDD16_t b = new_pDDD16(2, 1); // 1.0000...01 × 2^2
    pDDD16_t c = new_pDDD16(2, 2); // 1.0000...10 × 2^2
    pDDD16_t d = new_pDDD16(3, 1); // 1.0000...01 × 2^3

    assert(equ_pDDD16(a, b));
    assert(!equ_pDDD16(a, c));
    assert(!equ_pDDD16(a, d));

    assert(com_pDDD16(a, b) == 0);
    assert(com_pDDD16(a, c) < 0);
    assert(com_pDDD16(c, a) > 0);
    assert(com_pDDD16(a, d) < 0);
    assert(com_pDDD16(d, a) > 0);
}

int main() {
    test_addition();
    test_subtraction();
    test_multiplication();
    test_division();
    test_equals_and_compare();

    printf("All p-adic CCC_16 tests passed!\n");
    return 0;
}

