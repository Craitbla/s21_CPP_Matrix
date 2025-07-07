#include "s21_matrix_oop.h"

namespace s21 {

double S21Matrix::Determinant() {
  if (cols_ != rows_) {
    throw std::logic_error("The matrix is not square");
  }
  double result;
  bool err_flag = 0;
  double factor;
  int main_gigit = 1, sign = 1, diagonal_digit;
  S21Matrix copy(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      copy(i, j) = (*this)(i, j);
    }
  }
  for (int n = 0; n < cols_; n++) {
    diagonal_digit = main_gigit - 1;
    if (CheckDiagonalDigitToZero(copy, diagonal_digit, n, main_gigit, sign)) {
      err_flag = 1;
      break;
    }
    for (int i = rows_ - 1; i >= main_gigit; i--) {
      if (copy(diagonal_digit, n) != 0)
        factor = copy(i, n) / copy(diagonal_digit, n);
      for (int j = 0; j < cols_; j++) {
        copy(i, j) -= copy(diagonal_digit, j) * factor;
      }
    }
    main_gigit++;
  }
  result = 1;
  if (err_flag) {
    result = 0;
  } else {
    result = 1;
    for (int j = 0; j < rows_; j++) result *= copy(j, j);
    if (sign == -1) result *= -1;
  }
  return result;
}

int CheckDiagonalDigitToZero(S21Matrix &copy, int diagonal_digit, int n,
                             int main_gigit, int &sign) {
  int flag_null_row = 1;
  if (copy(diagonal_digit, n) == 0) {
    for (int k = main_gigit; k < copy.getRows(); k++) {
      if (copy(k, n) != 0) {
        flag_null_row = 0;
        SwapRows(copy, diagonal_digit, k);
        sign *= -1;
        break;
      }
    }
  } else
    flag_null_row = 0;
  return flag_null_row;
}

void SwapRows(S21Matrix &copy, int a, int b) {
  double tmp = 0;
  for (int i = 0; i < copy.getCols(); i++) {
    tmp = copy(a, i);
    copy(a, i) = copy(b, i);
    copy(b, i) = tmp;
  }
}

}  // namespace s21