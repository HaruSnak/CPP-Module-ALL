#!/bin/bash

echo ""

# Compile the program
make clean && make
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed"
    exit 1
fi

echo "✅ Compilation successful"
echo ""

# Test function
run_test() {
    echo "🔸 Testing: '$1'"
    ./convert "$1"
    echo ""
}

echo "=== CHAR LITERAL TESTS ==="
echo "Expected: char: 'a', int: 97, float: 97.0f, double: 97.0"
run_test "'a'"

echo "Expected: char: 'Z', int: 90, float: 90.0f, double: 90.0"
run_test "'Z'"

echo "Expected: char: '0', int: 48, float: 48.0f, double: 48.0"
run_test "'0'"

echo "=== INT LITERAL TESTS ==="
echo "Expected: char: 'A', int: 65, float: 65.0f, double: 65.0"
run_test "65"

echo "Expected: char: Non displayable, int: 0, float: 0.0f, double: 0.0"
run_test "0"

echo "Expected: char: impossible, int: -42, float: -42.0f, double: -42.0"
run_test "-42"

echo "Expected: char: impossible, int: 2147483647, float: 2.14748e+09f, double: 2.14748e+09"
run_test "2147483647"

echo "Expected: char: impossible, int: impossible, float: impossible, double: impossible"
run_test "999999999999999999999"

echo "=== FLOAT LITERAL TESTS ==="
echo "Expected: char: Non displayable, int: 0, float: 0.0f, double: 0.0"
run_test "0.0f"

echo "Expected: char: impossible, int: -4, float: -4.2f, double: -4.2"
run_test "-4.2f"

echo "Expected: char: 'A', int: 65, float: 65.0f, double: 65.0"
run_test "65.0f"

echo "Expected: char: impossible, int: impossible, float: 42.42f, double: 42.42"
run_test "42.42f"

echo "Expected: char: impossible, int: impossible, float: -inff, double: -inf"
run_test "-inff"

echo "Expected: char: impossible, int: impossible, float: +inff, double: +inf"
run_test "+inff"

echo "Expected: char: impossible, int: impossible, float: nanf, double: nan"
run_test "nanf"

echo "=== DOUBLE LITERAL TESTS ==="
echo "Expected: char: Non displayable, int: 0, double: 0.0, double: 0.0"
run_test "0.0"

echo "Expected: char: impossible, int: -4, float: -4.2f, double: -4.2"
run_test "-4.2"

echo "Expected: char: 'A', int: 65, float: 65.0f, double: 65.0"
run_test "65.0"

echo "Expected: char: impossible, int: impossible, float: 42.42f, double: 42.42"
run_test "42.42"

echo "Expected: char: impossible, int: impossible, float: -inff, double: -inf"
run_test "-inf"

echo "Expected: char: impossible, int: impossible, float: +inff, double: +inf"
run_test "+inf"

echo "Expected: char: impossible, int: impossible, float: nanf, double: nan"
run_test "nan"

echo "=== EDGE CASE TESTS ==="
echo "Expected: char: impossible, int: 127, float: 127.0f, double: 127.0"
run_test "127"

echo "Expected: char: impossible, int: 128, float: 128.0f, double: 128.0"
run_test "128"

echo "Expected: char: impossible, int: -128, float: -128.0f, double: -128.0"
run_test "-128"

echo "Expected: char: impossible, int: -129, float: -129.0f, double: -129.0"
run_test "-129"

echo "Expected: char: impossible, int: 32, float: 32.0f, double: 32.0"
run_test "32"  # Space character - non-displayable

echo "Expected: char: impossible, int: impossible, float: impossible, double: impossible"
run_test "3.40282e+39"  # Float overflow

echo "=== INVALID INPUT TESTS ==="
echo "Expected: Error handling for invalid inputs"
run_test "abc"
run_test "42.42.42"
run_test "'ab'"
run_test "''"
run_test "42f42"
run_test "inf+"
run_test "++42"
run_test "--42"

echo "=== ARGUMENT TESTS ==="
echo "🔸 Testing: No arguments"
./convert
echo ""

echo "🔸 Testing: Too many arguments"
./convert "42" "43"
echo ""

echo "=== TEST BATTERY COMPLETED ==="