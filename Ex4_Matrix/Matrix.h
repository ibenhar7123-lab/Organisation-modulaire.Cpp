#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

// Matrice de taille fixe N lignes x M colonnes, entièrement définie dans le header
template <typename T, std::size_t N, std::size_t M>
class Matrix {
private:
    T data[N][M];

public:
    Matrix() {
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < M; ++j) data[i][j] = T();
    }

    T& at(std::size_t i, std::size_t j) {
        if (i >= N || j >= M) throw std::out_of_range("Matrix::at : indice hors limites");
        return data[i][j];
    }
    const T& at(std::size_t i, std::size_t j) const {
        if (i >= N || j >= M) throw std::out_of_range("Matrix::at : indice hors limites");
        return data[i][j];
    }

    // Addition : mêmes dimensions
    Matrix operator+(const Matrix& autre) const {
        Matrix r;
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < M; ++j) r.data[i][j] = data[i][j] + autre.data[i][j];
        return r;
    }

    // Produit (N x M) * (M x P) = (N x P)
    template <std::size_t P>
    Matrix<T, N, P> operator*(const Matrix<T, M, P>& autre) const {
        Matrix<T, N, P> r;
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < P; ++j) {
                T somme = T();
                for (std::size_t k = 0; k < M; ++k) somme += data[i][k] * autre.at(k, j);
                r.at(i, j) = somme;
            }
        return r;
    }

    // Affichage (friend défini dans la classe)
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < M; ++j) os << m.data[i][j] << '\t';
            os << '\n';
        }
        return os;
    }
};

#endif // MATRIX_H
