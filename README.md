# C Numbers
This is a collection of number types,
including floating numbers and p-adic numbers,
 to do simple arithmetic for all possible precision of their significand part
 in the 8, 16, 32, and 64 bit architectures.

The reason I chose C language to build this is that C is the most efficient language,
and most portable one, so you can build these for any hardware, such as CPU, GPU, TPU, etc.
I specially wanted it to be compatible with CUDA, Habana, etc.

The reason I implemented both float, and p-adic,
numbers is that nobody tried p-adic numbers on machine learning computations.
I want to try them in the future, but I needed to have a reliable and efficient implementation first.
The p-adic numbers are so promising, and looks like a missed puzzle piece of computation,
since they have more consistent properties.

Regarding the need to support different bits in significand,
I don't have much more to add right now,
but I can refer to people's need to have [bfloat16](https://en.wikipedia.org/wiki/Bfloat16_floating-point_format),
[BFloat16: The secret to high performance on Cloud TPUs](https://cloud.google.com/blog/products/ai-machine-learning/bfloat16-the-secret-to-high-performance-on-cloud-tpus),
and [Deep Learning with Limited Numerical Precision](https://arxiv.org/abs/1502.02551)
So having such a library in hand would make it easier for people to investigate their ideas.

Regarding the difference in the sign bit's position in this type collection respect to
what we have in the family of [IEEE 754 single-precision floating-point format](https://en.wikipedia.org/wiki/Single-precision_floating-point_format),
I always wanted to know why they have separated it from the significand's bits,
where it's more consistent to treat the most left bit as the sign bit.
Therefore, I just did that here! It made the implementation easier and more consistent.
I still couldn't find the problem though, so feel free to open an issue in this repository.

This implementation tried to avoid a common library among these types,
therefore they are independent/isolated implementations.
This is due to the fact that a common code would make it hard to hand-pick some of them,
and more importantly it would cost us on the runtime.
Thus, we lift the runtime cost to the compile-time.
To do so we have a small implementation,
where you can find in the `generator` directory, then by using `generate.sh` we generated the complete collection,
where you can find in the `src` directory.

It's not stable yet, so check the roadmap below for future changes.

# Usage
You can always check the test suite of any project for the usage,
but for summary if you like to have a p-adic number you can do

```
p5707_t a = new_p5707(2, 5ULL); // 000...0101. × 2^2
```

Where this p-adic number has 57 bits for keeping the significand, and 07 bits for exponent.
Here the exponent is `2` and the significand is `101`.
Both the significand and exponent on all implementations in this collection can be both positive and negative integer numbers.

Or imagine you want a float number with this capacity, then you can write

```
f5707_t a = new_f5707(2, 5ULL << (SIGNIFICAND_BITS_F_57_07 - 4)); // 0.1010...00 × 2^2
```
Here the exponent is `2` and the significand is `101` again, but you have to shift it to the left.
Adding more convenient functions to convert `floatN` types to these types is in the roadmap.
Again both the significand and exponent on all implementations in this collection can be both positive and negative integer numbers.

Where you can do basic arithmetic with them.

```
f5707_t result1 = add_f5707(a, b);
f5707_t result2 = sub_f5707(a, b);
f5707_t result3 = mul_f5707(a, b);
f5707_t result4 = div_f5707(a, b);
bool result5 = equ_f5707(a, b);
int result6 = com_f5707(a, b);
```

This set of operations is available for all the types in this collection.

# Roadmap
- Have some utility to convert `float8`, `float16`, `float32`, and `float64` into these types.
- Complete the test suite, and review the comments on the current tests.

# Cite
If you found this work useful, please consider citing:
```
@misc{hadilq2024CNum}
    author = {{Hadi Lashkari Ghouchani}},
    note = {Published electronically at \url{https://github.com/hadilq/c-numbers}},
    title = {C Numbers},
    year={2024}
}
```

