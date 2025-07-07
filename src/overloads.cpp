#include "s21_matrix_oop.h"

namespace s21 {

bool EqualSize(const S21Matrix &A, const S21Matrix &B) {
  return A.getRows() == B.getRows() && A.getCols() == B.getCols();
}

bool CheckNanInfDouble(const double num) { return (isnan(num) || isinf(num)); }

S21Matrix operator+(const S21Matrix &A, const S21Matrix &B) {
  if (!EqualSize(A, B)) {
    throw std::logic_error("Different matrix dimensions");
  }
  int new_rows = A.getRows(), new_cols = A.getCols();
  S21Matrix result(new_rows, new_cols);
  for (int i = 0; i < new_rows; i++) {
    for (int j = 0; j < new_cols; j++) {
      result(i, j) = A(i, j) + B(i, j);
    }
  }
  return result;
}

S21Matrix operator-(const S21Matrix &A, const S21Matrix &B) {
  if (!EqualSize(A, B)) {
    throw std::logic_error("Different matrix dimensions");
  }
  int new_rows = A.getRows(), new_cols = A.getCols();
  S21Matrix result(new_rows, new_cols);
  for (int i = 0; i < new_rows; i++) {
    for (int j = 0; j < new_cols; j++) {
      result(i, j) = A(i, j) - B(i, j);
    }
  }
  return result;
}

S21Matrix operator*(const S21Matrix &A, const double num) {
  if (CheckNanInfDouble(num)) throw std::invalid_argument("Incorrect num");
  int new_rows = A.getRows(), new_cols = A.getCols();
  S21Matrix result(new_rows, new_cols);
  for (int i = 0; i < new_rows; ++i) {
    for (int j = 0; j < new_cols; ++j) {
      result(i, j) = A(i, j) * num;
    }
  }
  return result;
}

S21Matrix operator*(const double num, const S21Matrix &A) { return A * num; }

S21Matrix operator*(const S21Matrix &A, const S21Matrix &B) {
  if (A.getCols() != B.getRows()) {
    throw std::logic_error(
        "The number of columns of the first matrix does not equal the number "
        "of rows of the second matrix");
  }
  int new_rows = A.getRows(), new_cols = B.getCols();
  S21Matrix result(new_rows, new_cols);
  for (int i = 0; i < A.getRows(); ++i) {
    for (int j = 0; j < B.getCols(); ++j) {
      for (int p = 0; p < A.getCols(); ++p) {
        result(i, j) += A(i, p) * B(p, j);
      }
    }
  }
  return result;
}

bool operator==(const S21Matrix &A, const S21Matrix &B) {
  if (!EqualSize(A, B)) {
    return FAILURE;
  }
  int err = SUCCESS;
  for (int i = 0; i < A.getRows(); i++) {
    for (int j = 0; j < A.getCols(); j++) {
      if (fabs(A(i, j) - B(i, j)) > EPS) {
        err = FAILURE;
        i = A.getRows();
        j = A.getCols();
      }
    }
  }
  return err;
}

}  // namespace s21