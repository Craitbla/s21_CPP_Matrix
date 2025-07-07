#include "s21_matrix_oop.h"

namespace s21 {

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

void S21Matrix::setRows(int rows) {  // проверка на отрицательность и тд
  if (rows < 0)
    throw std::length_error("Set the value of the rows to non-negative");
  if (rows < rows_) {  // уменьшение

    for (int i = rows + 1; i < rows_; i++) {
      delete[] matrix_[i];
    }
    rows_ = rows;
  } else if (rows > rows_) {  // увеличение
    S21Matrix mat(rows, cols_);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols_; j++) {
        if (i >= rows_) {
          mat(i, j) = 0;
        } else {
          mat(i, j) = (*this)(i, j);
        }
        cout << mat(i, j) << endl;
      }
    }
    *this = mat;
  }
}

void S21Matrix::setCols(int cols) {
  if (cols < 0)
    throw std::length_error("Set the value of the cols to non-negative");
  S21Matrix mat(rows_, cols);
  if (cols < cols_) {  // уменьшение
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        mat(i, j) = (*this)(i, j);
      }
    }
  } else if (cols > cols_) {  // увеличение
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (i >= cols_) {
          mat(i, j) = 0;
        } else {
          mat(i, j) = (*this)(i, j);
        }
      }
    }
  }
  *this = mat;
}

}  // namespace s21