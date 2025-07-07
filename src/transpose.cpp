#include "s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      result(i, j) = (*this)(j, i);
    }
  }
  return result;
}

}  // namespace s21