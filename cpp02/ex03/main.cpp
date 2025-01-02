#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

/*
    This program checks if a point lies inside a triangle using the BSP (Binary Space Partitioning) algorithm.

    --- Program Overview ---
    1. **Classes Used:**
       - `Fixed`: A custom fixed-point number class that handles fractional values with precision.
       - `Point`: Represents a 2D point with `x` and `y` coordinates using `Fixed` numbers.

    2. **bsp Function:**
       - Implements the BSP algorithm to determine if a point is inside a triangle.
       - It uses the area method:
         - Computes the total area of the triangle.
         - Splits the triangle into three sub-triangles using the test point.
         - If the sum of the sub-triangle areas equals the total triangle area, the point is inside.

    3. **Code Flow:**
       - Three vertices of a triangle (`a`, `b`, `c`) are defined.
       - Three test points (`pointInside`, `pointOutside`, `pointOnEdge`) are created.
       - The `bsp` function is called for each test point to determine its relation to the triangle.
       - Results are printed to the console.

    --- Key Concepts ---
    - **Fixed-Point Arithmetic**:
      - The `Fixed` class handles numbers with fractional precision, simulating fixed-point arithmetic.
      - This ensures precision while performing operations like addition, subtraction, and comparison.

    - **Point Class**:
      - Represents a point with `Fixed` values for coordinates.
      - Enforces immutability of `x` and `y` by making them `const` and disabling assignment.

    - **Edge Cases**:
      - Points on the edges or vertices of the triangle return `false` from the `bsp` function.

    --- Output ---
    - The program prints whether each test point is inside, outside, or on the edge of the triangle.

    --- Example Output ---
    Given the triangle with vertices (0, 0), (10, 0), and (0, 10):
        - Point inside: 1
        - Point outside: 0
        - Point on edge: 0

    --- Notes ---
    - The `bsp` function relies on precise fixed-point arithmetic to handle fractional coordinates.
    - Ensure the `bsp` function correctly calculates areas and handles edge cases.

    
*/

void testPoint(const Point &a, const Point &b, const Point &c, const Point &point)
{
    bool result = bsp(a, b, c, point);
    std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is ";
    if (result)
        std::cout << "inside";
    else
        std::cout << "outside";
    std::cout << " the triangle formed by ";
    std::cout << "A(" << a.getX() << ", " << a.getY() << "), ";
    std::cout << "B(" << b.getX() << ", " << b.getY() << "), ";
    std::cout << "C(" << c.getX() << ", " << c.getY() << ")\n";
}

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point pointInside(2, 2);
    Point pointOutside(15, 5);
    Point pointOnEdge(0, 5);

    std::cout << "Point inside: " << bsp(a, b, c, pointInside) << std::endl;
    std::cout << "Point outside: " << bsp(a, b, c, pointOutside) << std::endl;
    std::cout << "Point on edge: " << bsp(a, b, c, pointOnEdge) << std::endl;

    return 0;
}
