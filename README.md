### FizzBuzz on Steroids: Code Capabilities
Date: Wed 19-Aug-2025 
3rd Semester 
3rd Lecture of CS-213: Reverse Engineering taken by Prof. VarunKumar Jayapaul

###### This program implements several variations of the FizzBuzz game, determined by user input. It can handle both integer and floating-point numbers. The core logic revolves around the numbers 3, 5, and 7, which are mapped to the words "Fizz", "Buzz", and "Boom" respectively.


#### Core Modes
###### The program prompts the user to select different modes of operation. The primary choice is between a standard output mode and a "Counter" mode.

##### Standard Mode (No Counter)
###### When not in Counter mode, the program produces classic FizzBuzz-style output.

###### **Divisibility Check (For integers only):**
###### If the user selects this option, the program iterates from 1 to the input integer. For each number, it checks for divisibility by 3, 5, and 7.
###### - If divisible by 3, it prints "Fizz".
###### - If divisible by 5, it prints "Buzz".
###### - If divisible by 7, it prints "Boom".
###### - If divisible by multiple, it prints a combination (e.g., "FizzBuzz").
###### - If divisible by none, it prints the number itself.

###### **Decimal Representation Check (For integers and decimals):**
###### If this option is chosen, the program inspects the digits of the input number.
###### - For each digit '3', it prints "Fizz".
###### - For each digit '5', it prints "Buzz".
###### - For each digit '7', it prints "Boom".
###### - The output is a concatenation of words corresponding to the digits found.

##### Counter Mode
###### When in Counter mode, the program counts occurrences instead of printing words directly.

###### **Prime Factor Counter (For integers only):**
###### This mode counts the number of times 3, 5, and 7 appear as prime factors for each integer from 1 up to the input number. It outputs the counts for "Fizz" (factor of 3), "Buzz" (factor of 5), and "Boom" (factor of 7) for each number in the range.

###### **Digit Occurrence Counter (For integers and decimals):**
###### This mode counts the occurrences of the digits 3, 5, and 7 within the input number's decimal representation. It then prints the total count for each:
###### - Fizz: [count of digit 3]
###### - Buzz: [count of digit 5]
###### - Boom: [count of digit 7]

#### Input Handling
###### The program's behavior changes based on whether the initial input is an integer or a decimal number.
###### - **Integer Input:** The user is presented with choices for all modes: Divisibility Check, Decimal Representation Check, Prime Factor Counter, and Digit Occurrence Counter. The program then iterates from 1 to the input number for the selected mode.
###### - **Decimal Input:** The options are limited to modes that operate on decimal representations (Decimal Representation Check and Digit Occurrence Counter). The program processes only the single decimal number provided as input.

#### Code Variations
##### Decimal Processing Modification
###### Within the `solve_decimal` and `solve_decimal_counter` functions, there are commented-out lines of code:
```cpp
// int temp = num;
// num -= temp;
```
###### By default, these functions process all digits of a given number (e.g., for 13.5, they would analyze '1', '3', and '5').
###### If you uncomment these two lines, the behavior changes. The code will first strip the integer part of the number, causing the functions to only analyze the digits in the fractional part (i.e., the digits after the decimal point). For example, with the code uncommented, an input of 13.5 would only result in "Buzz" (for the '5'), ignoring the '1' and '3'.
