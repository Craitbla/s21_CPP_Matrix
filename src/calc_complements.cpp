#include "s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) {
    throw std::logic_error("The matrix is not square");
  }
  S21Matrix result(rows_, cols_);
  if (rows_ == 1 || cols_ == 1) {
    result(0, 0) = 0;
  } else {
    S21Matrix minor_mat;
    double det = 0;
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        minor_mat = CreateMinorMat((*this), i, j);
        det = minor_mat.Determinant();
        if ((i + j) % 2 == 1 && det != 0) det *= -1;
        result(i, j) = det;
      }
    }
  }
  return result;
}

S21Matrix CreateMinorMat(const S21Matrix &A, int i, int j) {
  S21Matrix minor_mat(A.getCols() - 1, A.getRows() - 1);
  int q = 0, w = 0;
  for (int p = 0; p < A.getRows(); p++) {
    if (p == i)
      continue;
    else {
      w = 0;
      for (int o = 0; o < A.getCols(); o++) {
        if (o == j)
          continue;
        else {
          minor_mat(q, w) = A(p, o);
          w++;
        }
      }
      q++;
    }
  }
  return minor_mat;
}

}  // namespace s21