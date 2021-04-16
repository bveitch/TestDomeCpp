#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>
#include <math.h> 
/**
Implement the function findRoots to find the roots of the quadratic equation: ax2 + bx + c = 0. 
If the equation has only one solution, the function should return that solution as both elements of the pair.
 The equation will always have at least one solution.

The roots of the quadratic equation can be found with the following formula: A quadratic equation.
For example, the roots of the equation 2x2 + 10x + 8 = 0 are -1 and -4.
*/
std::pair<double, double> findRoots(double a, double b, double c)
{
    auto d=sqrt(b*b-4*a*c); 
    auto r1=(-b+d)/(2*a);
    auto r2=(-b-d)/(2*a);
    return {std::move(r1),std::move(r2)};
}

#ifndef RunTests
int main()
{
    std::pair<double,double> roots = findRoots(2, 10, 8);
    std::cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second) << std::endl;;
    if(roots.first == -1.0 && roots.second == -4.0) std::cout << "test passed!" << std::endl;
    else std::cout << "test failed!" << std::endl;
}
#endif
//this = 100%