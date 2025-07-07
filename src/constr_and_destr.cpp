#include "s21_matrix_oop.h"

s21::S21Matrix::S21Matrix() : rows_(1), cols_(1) {
  matrix_ = new double *[rows_] {};
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
}

s21::S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 0 || cols < 0) {
    throw std::length_error("Incorrect rows or cols");
  }
  this->rows_ = rows;
  this->cols_ = cols;
  matrix_ = new double *[rows] {};
  for (int i = 0; i < rows; i++) {
    matrix_[i] = new double[cols]{};
  }
}

s21::S21Matrix::~S21Matrix() {
  if (matrix_ != NULL) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

s21::S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    std::copy(other.matrix_[i], other.matrix_[i] + cols_, matrix_[i]);
  }
}

s21::S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = std::exchange(other.rows_, 0);
  cols_ = std::exchange(other.cols_, 0);
  matrix_ = std::exchange(other.matrix_, nullptr);
}
