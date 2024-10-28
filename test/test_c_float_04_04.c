#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "c_float_04_04.h"

static void print_float_04_04(const char* label, f0404_t f) {
    if (C_FLOAT_04_04_DEBUG) {
        uint8_t exp = (f &EXPONENT_MASK_F_04_04) >> SIGNIFICAND_BITS_F_04_04;
        uint8_t sig = f & SIGNIFICAND_MASK_F_04_04;

        if ((1U << (SIGNIFICAND_BITS_F_04_04 - 1) & sig)) {
            sig |= ((1U << EXPONENT_BITS_F_04_04) - 1) << SIGNIFICAND_BITS_F_04_04; // Fill the left with ones
        }
        if ((1U << (EXPONENT_BITS_F_04_04 - 1) & exp)) {
            exp |= ((1U << SIGNIFICAND_BITS_F_04_04) - 1) << EXPONENT_BITS_F_04_04; // Fill the left with ones
        }
        printf("%s: f0404: Exponent: %d, Significand: 0x%x, FULL value: 0x%x\n", label, exp, sig, f);
    }
}

static void assert_float_04_04(const char* label, f0404_t f, uint8_t expected_exp, uint8_t expected_sig) {
    if (C_FLOAT_04_04_DEBUG) {
        print_float_04_04(label, f);
        printf("expected exp: 0x%x\n", expected_exp << SIGNIFICAND_BITS_F_04_04);
        printf("actual exp  : 0x%x\n", f & EXPONENT_MASK_F_04_04);
        printf("expected sig: 0x%x\n", expected_sig);
        printf("actual sig  : 0x%x\n", f & SIGNIFICAND_MASK_F_04_04);
    }
    assert((f &EXPONENT_MASK_F_04_04) == expected_exp << SIGNIFICAND_BITS_F_04_04);
    assert((f & SIGNIFICAND_MASK_F_04_04) == expected_sig);
}

static void test_addition() {
    printf("Testing addition...\n");

    // Test case 1: Simple addition
    f0404_t a = new_f0404(2, 5U << (SIGNIFICAND_BITS_F_04_04 - 4)); // 0.1010...00 × 2^2
    f0404_t b = new_f0404(2, 6U << (SIGNIFICAND_BITS_F_04_04 - 4)); // 0.1100...00 × 2^2
    f0404_t result = add_f0404(a, b); // 0.10110...00 × 2^3
    assert_float_04_04(
        "Addition result 1", result,
        3U,
        5U
    );

    // Test case 2: Addition on max positive significand
    a = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 1)) - 1); // 0.11111...11 × 2^2
    b = new_f0404(2, 1); // 0.00000...01 × 2^2
    result = add_f0404(a, b); // 0.1000..00 × 2^3
    assert_float_04_04(
        "Addition result 2", result,
        3U,
        1U << (SIGNIFICAND_BITS_F_04_04 - 2)
    );

    // Test case 3: Addition with different exponents
    a = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    b = new_f0404(1, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^1
    result = add_f0404(a, b); // 0.10100...01 × 2^3
    assert_float_04_04(
        "Addition result 3", result,
        3U,
        (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | (1U << (SIGNIFICAND_BITS_F_04_04 - 3))
    );

    // Test case 4: Addition symmetry
    a = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    b = new_f0404(1, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^1
    result = add_f0404(b, a); // 0.10100...01 × 2^3
    assert_float_04_04(
        "Addition result 4", result,
        3U,
        (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | (1U << (SIGNIFICAND_BITS_F_04_04 - 3))
    );

    // Test case 5: One negative exponent
    a = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    b = new_f0404(-1, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^-1
    result = add_f0404(b, a); // 0.10000...00 × 2^3
    assert_float_04_04(
        "Addition result 5", result,
        3U,
        ((1U << (SIGNIFICAND_BITS_F_04_04 - 2))) | 1U
    );

    // Test case 6: Two negative exponent
    a = new_f0404(-2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^-2
    b = new_f0404(-1, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^-1
    result = add_f0404(b, a); // 0.10000...00 × 2^-1
    assert_float_04_04(
        "Addition result 6", result,
        (1U << EXPONENT_BITS_F_04_04) - 1,
        ((1U << (SIGNIFICAND_BITS_F_04_04 - 3))) | ((1U << (SIGNIFICAND_BITS_F_04_04 - 2))) | 1U
    );
}

static void test_subtraction() {
    printf("Testing subtraction...\n");

    // Test case 1: Subtraction returns zero
    f0404_t a = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 4U); // 0.10000...100 × 2^2
    f0404_t b = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 4U); // 0.10000...100 × 2^2
    f0404_t result = sub_f0404(a, b); // 0.0000...00 × 2^0
    assert_float_04_04(
        "Subtraction result 1", result,
        0UL, 0U
    );

    // Test case 2: Simple subtraction
    a = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 4U); // 0.10000...100 × 2^2
    b = new_f0404(2, 1U); // 0.00000...001 × 2^2
    result = sub_f0404(a, b); // 0.10000...011 × 2^2
    assert_float_04_04(
        "Subtraction result 2", result,
        1U,
        6U
    );

    // Test case 3: Subtraction requiring normalization
    a = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 4U); // 0.10000...100 × 2^2
    b = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 3U); // 0.10000...011 × 2^2
    result = sub_f0404(a, b); // 0.10000...000 × 2^((sig_bits - 2)-(2 + 1))
    assert_float_04_04(
        "Subtraction result 3", result,
        1U,
        0xaU
    );

    // Test case 4: Subtraction with different exponents
    a = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    b = new_f0404(1, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^1
    result = sub_f0404(a, b); // 0.110...00 × 2^2
    assert_float_04_04(
        "Subtraction result 4", result,
        2U,
        (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | (1U << (SIGNIFICAND_BITS_F_04_04 - 3))
    );

    // Test case 5: Subtraction anti-symmetry
    a = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    b = new_f0404(1, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^1
    result = add_f0404(neg_f0404(b), a); // 0.110...00 × 2^2
    assert_float_04_04(
        "Subtraction result 5", result,
        2U,
        (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | (1U << (SIGNIFICAND_BITS_F_04_04 - 3))
    );

    // Test case 6: Subtraction reverse of addition
    a = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    b = new_f0404(1, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^1
    result = sub_f0404(add_f0404(b, a), a); // Should return b
    assert_float_04_04(
        "Subtraction result 6", result,
        1U,
        (1U << (SIGNIFICAND_BITS_F_04_04 - 2))
    );
}

static void test_multiplication() {
    printf("Testing multiplication...\n");

    // Test case 1: Simple multiplication with inverse
    f0404_t a = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    f0404_t b = new_f0404(neg_f0404(2), (1U << (SIGNIFICAND_BITS_F_04_04 - 1)) - 1); // 0.1111...11 × 2^-2
    f0404_t result = mul_f0404(a, b); // 0.100000...00 × 2^1
    assert_float_04_04(
        "Multiplication result 1", result,
        1U,
        1U << (SIGNIFICAND_BITS_F_04_04 - 2)
    );

    // Test case 2: Simple multiplication without normalization
    a = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^2
    b = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    result = mul_f0404(a, b); // 0.100000...010 × 2^4
    assert_float_04_04(
        "Multiplication result 2", result,
        4UL,
        ((1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 2U)
    );

    // Test case 3: Multiplication both positive
    a = new_f0404(1, (1U << (SIGNIFICAND_BITS_F_04_04 - 1)) - 1); // 0.11111...11 × 2^1
    b = new_f0404(1, (1U << (SIGNIFICAND_BITS_F_04_04 - 1)) - 1); // 0.11111...11 × 2^1
    result = mul_f0404(a, b); // 0.111111...110 × 2^2
    assert_float_04_04(
        "Multiplication result 3", result,
        2U,
        ((1U << (SIGNIFICAND_BITS_F_04_04 - 1)) - 1) - 1U
    );

    // Test case 4: Multiplication both negative
    a = new_f0404(1, neg_f0404(1)); // 1.11111...11 × 2^1
    b = new_f0404(1, ((1U << (SIGNIFICAND_BITS_F_04_04 / 2)) - 1) << (SIGNIFICAND_BITS_F_04_04 /  2) ); // 1.11100...00 × 2^1
    result = mul_f0404(a, b); // 0.10...000 × 2^(-1)
    assert_float_04_04(
        "Multiplication result 4", result,
        neg_f0404(1U),
        (1U << (SIGNIFICAND_BITS_F_04_04 - 2))
    );

    // Test case 5: Multiplication one negative
    a = new_f0404(1, neg_f0404(1)); // 1.11111...11 × 2^1
    b = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    result = mul_f0404(a, b); // 0.10...000 × 2^1
    assert_float_04_04(
        "Multiplication result 5", result,
        1U,
        ((neg_f0404(5) << (SIGNIFICAND_BITS_F_04_04 - 1)) &  SIGNIFICAND_MASK_F_04_04) | ((1U << (SIGNIFICAND_BITS_F_04_04 - 2)) - 1)
    );

    // Test case 6: Multiplication symmetry
    a = new_f0404(1, neg_f0404(1)); // 1.11111...11 × 2^1
    b = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^3
    result = mul_f0404(b, a); // 0.10...000 × 2^-21
    assert_float_04_04(
        "Multiplication result 6", result,
        1U,
        ((neg_f0404(5) << (SIGNIFICAND_BITS_F_04_04 - 1)) &  SIGNIFICAND_MASK_F_04_04) | ((1U << (SIGNIFICAND_BITS_F_04_04 - 2)) - 1)
    );
}

static void test_division() {
    printf("Testing division...\n");

    // Test case 1: Division returns one
    f0404_t a = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^2
    f0404_t b = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.10000...01 × 2^2
    f0404_t result = div_f0404(a, b); // 0.1000...00 × 2^-1
    assert_float_04_04(
        "Division result 1", result,
        1U,
        1U << (SIGNIFICAND_BITS_F_04_04 - 2)
    );

    // Test case 2: Simple division
    a = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.1000...001 × 2^3
    b = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 2U); // 0.1000...010 × 2^2
    result = div_f0404(a, b); // 0.11...11 × 2^1
    assert_float_04_04(
        "Division result 2", result,
        1U,
        (1U << (SIGNIFICAND_BITS_F_04_04 - 1)) - 1 & ~1U
    );

    // Test case 3: Division of a positive number by zero
    a = new_f0404(2, 1); // 0.00000...01 × 2^2
    b = new_f0404(4, 0); // 0
    result = div_f0404(a, b); // Should return max value as "infinity"
    assert_float_04_04(
        "Division result 3", result,
        (1U << (EXPONENT_BITS_F_04_04 - 2)) - 1,
        (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) - 1
    );

    // Test case 4: Division of a negative number by zero
    a = new_f0404(2, neg_f0404(1)); // 1.1111...11 × 2^2
    b = new_f0404(4, 0); // 0
    result = div_f0404(a, b); // Should return min value as "-infinity"
    assert_float_04_04(
        "Division result 4", result,
        (1U << (EXPONENT_BITS_F_04_04 - 2)) - 1,
        1U << (SIGNIFICAND_BITS_F_04_04 - 1)
    );

    // Test case 5: Division reverse of multiplication for small positive numbers
    a = new_f0404(neg_f0404(1), 1U); // 0.0000...001 × 2^-1
    b = new_f0404(2, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 2U); // 0.1000...010 × 2^2
    result = div_f0404(mul_f0404(a, b), b); // Should return a
    assert_float_04_04(
        "Division result 5", result,
        neg_f0404(3U),
        1U << (SIGNIFICAND_BITS_F_04_04 - 2)
    );

    // Test case 6: Division reverse of multiplication for big positive numbers
    a = new_f0404(2, 1); // 0.000...01 × 2^2
    b = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.100...01 × 2^3
    result = div_f0404(mul_f0404(b, a), a); // Should return b
    assert_float_04_04(
        "Division result 6", result,
        3U,
        1U << (SIGNIFICAND_BITS_F_04_04 - 2) | 1U
    );

    // Test case 7: Division reverse of multiplication for small negative numbers
    a = new_f0404(neg_f0404(1), neg_f0404(1)); // 1.111...11 × 2^-1
    b = new_f0404(3, (1U << (SIGNIFICAND_BITS_F_04_04 - 2)) | 1U); // 0.100...01 × 2^3
    result = div_f0404(mul_f0404(a, b), b); // Should return a
    assert_float_04_04(
        "Division result 7", result,
        neg_f0404(3U),
        3U << (SIGNIFICAND_BITS_F_04_04 - 2)
    );

    // Test case 8: Division reverse of multiplication for big negative numbers
    a = new_f0404(2, neg_f0404(1)); // 0.000...01 × 2^2
    b = new_f0404(3, (3U << (SIGNIFICAND_BITS_F_04_04 - 1)) | 1U); // 1.100...01 × 2^3
    result = div_f0404(mul_f0404(b, a), a); // Should return b
    assert_float_04_04(
        "Division result 8", result,
        3U,
        (1U << (SIGNIFICAND_BITS_F_04_04 - 1)) | 1U
    );
}

static void test_equals_and_compare() {
    printf("Testing equals and compare...\n");

    f0404_t a = new_f0404(2, 1); // 1.0000...01 × 2^2
    f0404_t b = new_f0404(2, 1); // 1.0000...01 × 2^2
    f0404_t c = new_f0404(2, 2); // 1.0000...10 × 2^2
    f0404_t d = new_f0404(3, 1); // 1.0000...01 × 2^3

    assert(equ_f0404(a, b));
    assert(!equ_f0404(a, c));
    assert(!equ_f0404(a, d));

    assert(com_f0404(a, b) == 0);
    assert(com_f0404(a, c) < 0);
    assert(com_f0404(c, a) > 0);
    assert(com_f0404(a, d) < 0);
    assert(com_f0404(d, a) > 0);
}

int main() {
    test_addition();
    test_subtraction();
    test_multiplication();
    test_division();
    test_equals_and_compare();

    printf("All float 04_04 tests passed!\n");
    return 0;
}

