#ifndef S21MATRIX_OOP_H
#define S21MATRIX_OOP_H

#include <cmath>
#include <exception>
#include <iostream>
#include <utility>

#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-7

using namespace std;

namespace s21 {

enum ERROR { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

 public:
  double &operator()(int row, int col) const {
    if (rows_ < row || cols_ < col || row < 0 || col < 0) {
      throw std::out_of_range("Index is outside the matrix");
    }
    return matrix_[row][col];
  }

  S21Matrix &operator=(const S21Matrix &A) {
    if (this != &A) {
      if (rows_ != A.rows_ || cols_ != A.cols_) {
        rows_ = A.rows_;
        cols_ = A.cols_;
        delete[] matrix_;
        matrix_ = new double *[rows_] {};
        for (int i = 0; i < rows_; i++) {
          matrix_[i] = new double[cols_]{};
        }
      }
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          (*this)(i, j) = A(i, j);
        }
      }
    }
    return *this;
  }

  S21Matrix &operator+=(const S21Matrix &other) {
    (*this) = (*this) + other;
    return *this;
  }

  S21Matrix &operator-=(const S21Matrix &other) {
    (*this) = (*this) - other;
    return *this;
  }
  S21Matrix &operator*=(const S21Matrix &other) {
    (*this) = (*this) * other;
    return *this;
  }
  S21Matrix &operator*=(const double num) {
    (*this) = (*this) * num;
    return *this;
  }

  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  int getRows() const;
  int getCols() const;
  void setRows(int rows);
  void setCols(int cols);

  bool EqMatrix(const S21Matrix &other) { return (*this) == other; }
  void SumMatrix(const S21Matrix &other) { (*this) = (*this) + other; }
  void SubMatrix(const S21Matrix &other) { (*this) = (*this) - other; }
  void MulNumber(const double num) { (*this) = (*this) * num; }
  void MulMatrix(const S21Matrix &other) { (*this) = (*this) * other; }

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  friend S21Matrix operator+(const S21Matrix &A, const S21Matrix &B);
  friend S21Matrix operator-(const S21Matrix &A, const S21Matrix &B);
  friend S21Matrix operator*(const S21Matrix &A, const S21Matrix &B);
  friend S21Matrix operator*(const double num, const S21Matrix &A);
  friend S21Matrix operator*(const S21Matrix &A, const double num);
  friend bool operator==(const S21Matrix &A, const S21Matrix &B);

  int CheckMatPtr() const;
};

bool EqualSize(const S21Matrix &A, const S21Matrix &B);
bool CheckNanInfDouble(const double num);
int CheckDiagonalDigitToZero(S21Matrix &copy, int diagonal_digit, int n,
                             int main_gigit, int &sign);
void SwapRows(S21Matrix &copy, int a, int b);
S21Matrix CreateMinorMat(const S21Matrix &A, int i, int j);
}  // namespace s21

#endif  // S21MATRIX_OOP_H