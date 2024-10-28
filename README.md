# C Numbers
This is a collection of number types to do simple arithmetic,
including floating numbers and p-adic numbers,
for all possible precision of their significand part in the 8, 16, 32, and 64 bit capacities,
where the current computing technologies are built upon these capacities.

The reason I chose C language to build this is that c is the most efficient language,
and most portable one, so you can build these on any hardware, such as CPU, GPU, TPU, etc.
I specially want it to be compatible with CUDA, Habana, etc.

The reason I implemented both float, and p-adic,
numbers is that nobody tried p-adic numbers on machine learning computations.
I want to try them in the future, but I needed to have a reliable and efficient implementation first.
The p-adic numbers are so promising, and looks like a missed puzzle piece of computation,
since they have more consistent properties.

This implementation tried to avoid a common library among these types,
therefore they are independent implementations,
since it would make it hard to hand-pick some of them,
and more importantly it would cost us on the runtime.
Thus, we lift the runtime cost to the compile-time by having a small implementation,
where you can find in the `generator` directory, then by using `generate.sh` I generated the complete collection,
where you can find in the `src` directory.

I will add more tests and improve the implementation in the future iterations,
but for now I think it's ready to build something on top of it.

# Usage
You can always check the test of any project for usage,
but for instance if you like to have a p-adic number you can do

```
p5707_t a = new_p5707(2, 5ULL); // 000...0101. × 2^2
```

where this p-adic number has 57 digits for keeping the significand, and 07 digits for exponent.
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
- Have min and max value constants for each type.
- Complete the test suite, and review the comments on the current tests.


