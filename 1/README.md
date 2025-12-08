# Day 1: Secret Entrance

## Description

The first puzzle for Advent of Code 2025! In this challenge we are asked to track the number of times a dial on a lock will land on zero, and how many times it will pass zero. A full problem description can be found here: [Day 1](https://adventofcode.com/2025/day/1)

## Part 1

### Problem

In Part 1 we are tasked with counting the number of times a dial will end up at exactly 0 on a circular combination lock numbered 0 - 99. Our input consists of a number of lines with a direction of rotation and magnitude, in the form `L45`, representing a left turn of 45 points. Our dial begins at position 50.

### Intuition

Because we only have to track whether or not the dial ends on 0, the simplest and best solution is to track the dials final position after applying a rotation. To do this, we make use of the modulo operator. By adding the magnitude of the rotation to the current position and then taking the modulo, we get the dial's true position. 

Take for example a rotation of `R45` from position 90. After adding 45 to 90, we get 135. 135 % 100 = 35, which is now the dials true position. The only complication here is that a left turn, will require subtracting the magnitude of the rotation, and some languages do not handle negative values as we would like in this case. To circumvent this, we can add some multiple of 100 to the final value of the rotation such that it is positive, then take the modulo. Observe that a rotation of `L25` from a position of 3 will result in an initial value of -22. By adding 100, we get 78, 78 % 100 = 78, which is our true position.

## Part 2

### Problem

In Part 2 we are tasked with counting every time the dial moves past or finishes on 0. The input and lock remain the same.

### Intuition

There is some additional complexity compared to part 1, which boil down to keeping track of two things: How many complete rotations of the lock the rotation will cause us to make, and whether we will cross or arrive at 0 with the remainder of the rotation. This means that we can decompose a rotation into two sections: complete rotations (100) and the remainder (0 - 99).

##### Complete Rotations

This section is easy - rotation the dial 100 in either direction will result in exactly one pass of 0, and the dial being in the same position as where you started. Count the number of complete rotations and add them to the count

##### Remainder

While slightly trickier, this section can still be solved with some simple modulo arithmetic. To see if our dial passes 100, we convert our remaining rotation to a positive or negative value depending on direction, and add it to our position, unbounded, meaning it can drop below 0 and exceed 100. Then we check if the value is <= 0 or >= 100, which means that it has passed or finished on 0. After checking, we then add 100 and apply the modulo to get the true position.

One thing to be aware of is the edge case where the rotation starts at 0, and falls below 0. This will not result in the dial passing 0, to avoid double counting, we simply keep track of if the dial started at 0 or not.

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
