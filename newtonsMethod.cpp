/* This program provides a standalone function for computing the approximate root a function using
Newton's Method. */

#include <cmath>    
#include <stdexcept>

/* newtonsMethod(func, derivFunc, initGuess epsilon) Returns an approximation to the root of the function func up to an 
   error tolerance epsilon. Provided the functions derivative derivFunc and an initial guess initGuess. */
// Requires: epsilon > 0
//           derivFunc is not too flat (approx = 0) near our guesses
long double newtonsMethod(
    long double (*func)(long double x), 
    long double (*derivFunc)(long double x), 
    long double initGuess, 
    long double epsilon
) {
    long double curGuess = initGuess;
    long double newGuess = initGuess;
    while(true) {
        long double derivVal = derivFunc(curGuess);
        if (std::abs(derivVal) <= 1e-11) {
            throw std::invalid_argument("Cannot apply Newton's Method to a function whose derivative is nearly flat near our guesses.");
        }
        newGuess = curGuess - (func(curGuess)/derivFunc(curGuess));
        if (std::abs(curGuess - newGuess) < epsilon) {
            break;
        } else {
            curGuess = newGuess;
        }
    }
    return newGuess;
}

// // A sample of how you may test such a program
// #include <iostream>
// long double testFunc(long double x) {
//     return x*x + 2*x - 8; // Roots at x = -4 and x = +2
// }

// long double testFuncDeriv(long double x) {
//     return 2*x + 2;
// }

// int main(void) {
//     long double root = newtonsMethod(testFunc, testFuncDeriv, -1.01, 1e-3);
// //  Guess at x = -0.99 should give root = -4, and x = 1.01 should give root = +2 
//     std::cout << "The estimated root of the provided function is x* = " << root << std::endl;
//     return 0;
// }
