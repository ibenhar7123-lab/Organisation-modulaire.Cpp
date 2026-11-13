#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    // Matrices 2x2 d'entiers
    Matrix<int, 2, 2> A, B;
    A.at(0, 0) = 1; A.at(0, 1) = 2; A.at(1, 0) = 3; A.at(1, 1) = 4;
    B.at(0, 0) = 5; B.at(0, 1) = 6; B.at(1, 0) = 7; B.at(1, 1) = 8;

    cout << "A =\n" << A << "B =\n" << B;
    cout << "A + B =\n" << (A + B);
    cout << "A * B =\n" << (A * B);

    // Matrices 3x3 de réels
    Matrix<double, 3, 3> I, D;
    for (size_t i = 0; i < 3; ++i) {
        I.at(i, i) = 1.0;                // identité
        for (size_t j = 0; j < 3; ++j) D.at(i, j) = 0.5 * (i + j);
    }
    cout << "\nD =\n" << D;
    cout << "D * I =\n" << (D * I);
    cout << "D + I =\n" << (D + I);

    try {
        A.at(5, 5);
    } catch (const out_of_range& e) {
        cout << "\nException : " << e.what() << endl;
    }
    return 0;
}
