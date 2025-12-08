# Day 2: Gift Shop

## Description

Today we are asked to find numbers that are made up of repeating patterns of smaller numbers, inside a range. Read more about why we have to do this here: [Day 2](https://adventofcode.com/2025/day/2)

## Part 1

### Problem

In Part 1 we are to find numbers that are made up of some sequence of digits repeated twice within a set of given ranges. Some examples are `55` (`5` twice), `6464` (`64` twice), and `111111` (`111` twice). The answer is then the sum of all numbers with this property.

### Intuition

First, we may consider that we can manually check each number within the range, however this become extremeley inefficient. We can then consider an important property of these numbers - since the second sequence is a repetition of the first, we can instead generate them by creating all unique numbers within a reasonable range, and concatenating them. We can then check these generated numbers against the range and if they are out of bound, stop generating. 


## Part 2

### Problem

In Part 2 we are tasked with finding integers that contain a repeating subsequence of digits within a set of ranges. For example, `12121212` (`12` four times). The answer will then be again the sum of all numbers found

### Intuition

Following from the intuition of part 1, we can generate these numbers by simply repeating some sequence of digits i until it is greater than the upper limit, then moving on to i + 1 until some reasonable upper bound. 

For example, if we consider the range 1000 - 1500, we can start with i = 1, repeating this until we arrive at `1111` (`1` four times). We will do the same with `2`, however it will never be in range. This will be true for all other single digit numbers. Then we can consider the two digit numbers between `10` and `14`, which when repeated will yield `1010`, `1111`, `1212`, `1313`, `1414`. This completes the set of possible repeated numbers within range. You also may have noticed that `1111` was repeated. An easy way to check for this is to simply keep a set of found solutions, preventing from double counting.

## Files

- `part_1.cpp`
- `part_2.cpp`
- `text.txt`
- `input.txt`

## Usage

Compile with any C++17 compatible compiler: 

```c++
g++ -std=c++17 part_1.cpp -o part1
g++ -std=c++17 part_2.cpp -o part2
```

Run by piping in your input file like so:

```c++
./part1 < test.txt
./part2 < input.txt
```
