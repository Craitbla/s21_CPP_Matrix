#include "s21_matrix_oop.h"

namespace s21 {
S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix result(rows_, cols_);
  if (rows_ == 1 && cols_ == 1) {
    if ((*this)(0, 0) != 0) {
      result(0, 0) = 1.0 / (*this)(0, 0);
    } else
      throw std::logic_error("Matrix determinant is 0");
  } else {
    double det, factor;
    det = (*this).Determinant();
    if (det != 0) {
      factor = 1.0 / det;
      S21Matrix minor_mat;
      S21Matrix tr_minor_mat;
      minor_mat = (*this).CalcComplements();
      tr_minor_mat = minor_mat.Transpose();
      result = tr_minor_mat * factor;
    } else {
      throw std::logic_error("Matrix determinant is 0");
    }
  }
  return result;
}
}  // namespace s21