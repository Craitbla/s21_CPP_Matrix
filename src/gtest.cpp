#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

using namespace s21;

TEST(Matrices, ValidCreateMatrix) {
  S21Matrix obj(3, 3);
  obj(0, 0) = 0;
  EXPECT_EQ(obj(0, 0), 0);
}

TEST(Matrices, InvalidCreateMatrix) {
  EXPECT_THROW(S21Matrix obj(-1, 0), std::length_error);
}

TEST(Matrices, ValidCreateMatrixTransfer) {
  S21Matrix obj(3, 3);
  S21Matrix objTwo = std::move(obj);
  EXPECT_EQ(objTwo(0, 0), 0);
}

TEST(Matrices, ValidEqMatrix) {
  S21Matrix first_obj;
  S21Matrix second_obj;
  EXPECT_EQ(first_obj, second_obj);
}

TEST(Matrices, ValidNotEqMatrix) {
  S21Matrix first_obj(3, 3);
  S21Matrix second_obj(3, 3);
  first_obj(1, 1) = 9;
  EXPECT_EQ(first_obj.EqMatrix(second_obj), false);
}

TEST(Matrices, InvalidEqMatrix) {
  S21Matrix first_obj;
  S21Matrix second_obj(1, 1);
  bool result = first_obj == second_obj;
  EXPECT_EQ(result, true);
}

TEST(Matrices, ValidSumMatrix) {
  S21Matrix first_obj(3, 3);
  S21Matrix second_obj(3, 3);
  first_obj(0, 0) = 1;
  second_obj(0, 0) = 1;
  S21Matrix resultObj(3, 3);
  resultObj = first_obj + second_obj;
  EXPECT_EQ(resultObj(0, 0), 2);
}

TEST(Matrices, InvalidSumMatrix) {
  S21Matrix first_obj(5, 3);
  S21Matrix second_obj(3, 3);
  EXPECT_THROW(first_obj + second_obj, std::logic_error);
}

TEST(Matrices, CopyMatrix) {
  S21Matrix first_obj(5, 5);
  S21Matrix second_obj(first_obj);
  EXPECT_EQ(first_obj, second_obj);
}

TEST(Matrices, ValidsetRowsAndCols1) {
  S21Matrix obj;
  EXPECT_EQ(obj.getRows(), 1);
  EXPECT_EQ(obj.getCols(), 1);
  obj.setRows(10);
  EXPECT_EQ(obj.getRows(), 10);
  obj.setCols(15);
  EXPECT_EQ(obj.getCols(), 15);
}

TEST(Matrices, ValidsetRowsAndCols2) {
  S21Matrix obj(1, 1);
  EXPECT_EQ(obj.getRows(), 1);
  EXPECT_EQ(obj.getCols(), 1);
  obj.setRows(10);
  EXPECT_EQ(obj(8, 0), 0);
  obj.setCols(15);
  EXPECT_EQ(obj(8, 2), 0);
}

TEST(Matrices, InvalidsetRowsAndCols1) {
  S21Matrix obj;
  EXPECT_EQ(obj.getRows(), 1);
  EXPECT_EQ(obj.getCols(), 1);
  EXPECT_THROW(obj.setRows(-1), std::length_error);
  EXPECT_THROW(obj.setCols(-15), std::length_error);
}

TEST(Matrices, getRowsAndCols) {
  S21Matrix obj(5, 3);
  EXPECT_EQ(obj.getRows(), 5);
  EXPECT_EQ(obj.getCols(), 3);
}
/////////
TEST(Matrices, ValidSubMatrix) {
  S21Matrix first_obj(3, 3);
  S21Matrix second_obj(3, 3);
  S21Matrix result(3, 3);
  first_obj(0, 0) = 3;
  second_obj(0, 0) = 10;
  result = first_obj - second_obj;
  EXPECT_EQ(result(0, 0), -7);
}

TEST(Matrices, InvalidSubMatrix) {
  S21Matrix first_obj(3, 3);
  S21Matrix second_obj(1, 3);
  EXPECT_THROW(first_obj - second_obj, std::logic_error);
}

TEST(Matrices, ValidMulMatrix_1) {
  S21Matrix first_obj(3, 3);
  S21Matrix second_obj(3, 3);
  S21Matrix result(3, 3);
  first_obj(0, 0) = 3;
  second_obj(0, 0) = 10;
  result = first_obj * second_obj;
  EXPECT_EQ(result(0, 0), 30);
}

TEST(Matrices, ValidMulMatrix_2) {
  S21Matrix first_obj(2, 4);
  S21Matrix second_obj(4, 2);
  S21Matrix result;
  first_obj(0, 0) = 3;
  first_obj(1, 0) = 2;
  first_obj(1, 1) = 5;
  second_obj(0, 0) = 10;
  second_obj(1, 1) = 5;
  result = first_obj * second_obj;
  EXPECT_EQ(result(0, 0), 30);
  EXPECT_EQ(result(0, 1), 0);
  EXPECT_EQ(result(1, 0), 20);
  EXPECT_EQ(result(1, 1), 25);

  EXPECT_EQ(result.getRows(), 2);
  EXPECT_EQ(result.getCols(), 2);
}

TEST(Matrices, InvalidMulMatrix_1) {
  S21Matrix first_obj(3, 3);
  S21Matrix second_obj(1, 3);
  EXPECT_THROW(first_obj * second_obj, std::logic_error);
}

TEST(Matrices, ValidMulNumber) {
  S21Matrix obj(3, 3);
  S21Matrix result(3, 3);
  obj(0, 0) = 3;
  result = obj * 3;
  EXPECT_EQ(result(0, 0), 9);
}

TEST(Matrices, InvalidMulNumber) {
  S21Matrix first_obj(3, 3);
  EXPECT_THROW(first_obj * NAN, std::invalid_argument);
}

TEST(Matrices, ValidSumEqMatrix) {
  S21Matrix first_obj(2, 2);
  S21Matrix second_obj(2, 2);
  first_obj(0, 0) = 3;
  second_obj(0, 0) = -6;
  first_obj += second_obj;
  EXPECT_EQ(first_obj(0, 0), -3);
}

TEST(Matrices, InvalidSumEqMatrix) {
  S21Matrix first_obj(2, 2);
  S21Matrix second_obj(4, 4);
  EXPECT_THROW(first_obj += second_obj, std::logic_error);
}

TEST(Matrices, ValidSubEqMatrix) {
  S21Matrix first_obj(3, 3);
  S21Matrix second_obj(3, 3);
  first_obj(0, 0) = 50;
  second_obj(0, 0) = 51;
  first_obj -= second_obj;
  EXPECT_EQ(first_obj(0, 0), -1);
}

TEST(Matrices, InvalidSubEqMatrix) {
  S21Matrix first_obj(2, 2);
  S21Matrix second_obj(4, 4);
  EXPECT_THROW(first_obj -= second_obj, std::logic_error);
}

TEST(Matrices, MulEqMatrix) {
  S21Matrix first_obj(5, 10);
  S21Matrix second_obj(10, 5);
  first_obj(0, 0) = 2;
  second_obj(0, 0) = 5;
  first_obj *= second_obj;
  EXPECT_EQ(first_obj(0, 0), 10);
  EXPECT_EQ(first_obj.getRows(), 5);
  EXPECT_EQ(first_obj.getCols(), 5);
}

TEST(Matrices, Transpose) {
  S21Matrix obj(3, 3);
  obj(0, 0) = 1;
  obj(0, 1) = 2;
  obj(0, 2) = 3;
  obj(1, 0) = 4;
  obj(1, 1) = 5;
  S21Matrix result;
  result = obj.Transpose();
  EXPECT_EQ(result(1, 0), 2);
}

TEST(Matrices, ValidDeterminant_1) {
  S21Matrix obj(3, 3);
  obj(0, 0) = 1;
  obj(0, 1) = 2;
  obj(0, 2) = 3;
  obj(1, 0) = 0;
  obj(1, 1) = 1;
  obj(1, 2) = 4;
  obj(2, 0) = 5;
  obj(2, 1) = 6;
  obj(2, 2) = 0;
  double det = obj.Determinant();
  EXPECT_EQ(det, 1.0);
}

TEST(Matrices, ValidDeterminant_2) {
  S21Matrix obj(3, 3);
  obj(0, 0) = 0;
  obj(0, 1) = 2;
  obj(0, 2) = 3;
  obj(1, 0) = 0;
  obj(1, 1) = 4;
  obj(1, 2) = 1;
  obj(2, 0) = 0;
  obj(2, 1) = 2;
  obj(2, 2) = 3;
  double det = obj.Determinant();
  EXPECT_EQ(det, 0.0);
}

TEST(Matrices, ValidDeterminant_3) {
  S21Matrix obj(3, 3);
  obj(0, 0) = 5;
  obj(0, 1) = 2;
  obj(0, 2) = 3;
  obj(1, 0) = 0;
  obj(1, 1) = 0;
  obj(1, 2) = 10;
  obj(2, 0) = 10;
  obj(2, 1) = 2;
  obj(2, 2) = 3;
  double det = obj.Determinant();
  EXPECT_EQ(det, 100.0);
}

TEST(Matrices, InvalidDeterminant) {
  S21Matrix obj(3, 5);
  EXPECT_THROW(obj.Determinant(), std::logic_error);
}

TEST(Matrices, ValidCalcComplements_1) {
  S21Matrix obj(3, 3);
  obj(0, 0) = 10;
  obj(1, 1) = 15;
  obj(2, 2) = 30;
  S21Matrix result(3, 3);
  result = obj.CalcComplements();
  EXPECT_EQ(result(0, 0), 450);
  EXPECT_EQ(result(1, 1), 300);
  EXPECT_EQ(result(2, 2), 150);
}

TEST(Matrices, InvalidCalcComplements) {
  S21Matrix obj(1, 3);
  EXPECT_THROW(obj.CalcComplements(), std::logic_error);
}

TEST(Matrices, ValidMulEqNumberOper) {
  S21Matrix obj(2, 2);
  obj(0, 0) = 1.0;
  obj(0, 1) = 2.0;
  obj(1, 0) = 3.0;
  obj(1, 1) = 4.0;

  obj *= 2.0;

  EXPECT_EQ(obj(0, 0), 2.0);
  EXPECT_EQ(obj(0, 1), 4.0);
  EXPECT_EQ(obj(1, 0), 6.0);
  EXPECT_EQ(obj(1, 1), 8.0);
}

TEST(Matrices, ValidInverseMatrix) {
  S21Matrix obj(2, 2);
  obj(0, 0) = 0;
  obj(0, 1) = -1;
  obj(1, 0) = -1;
  obj(1, 1) = 2;
  S21Matrix inverse = obj.InverseMatrix();
  EXPECT_EQ(inverse(0, 0), -2);
  EXPECT_EQ(inverse(0, 1), -1);
  EXPECT_EQ(inverse(1, 0), -1);
  EXPECT_EQ(inverse(1, 1), 0);
}

TEST(Matrices, ValidInverseMatrix1) {
  S21Matrix obj(1, 1);
  obj(0, 0) = 2;
  S21Matrix inverse = obj.InverseMatrix();
  EXPECT_EQ(inverse(0, 0), 0.5);
}

TEST(Matrices, InvalidElementAccess1) {
  S21Matrix obj(2, 2);
  obj(0, 0) = 1.0;
  obj(0, 1) = 2.0;
  obj(1, 0) = 3.0;
  obj(1, 1) = 4.0;

  EXPECT_EQ(obj(0, 0), 1.0);
  EXPECT_EQ(obj(0, 1), 2.0);
  EXPECT_EQ(obj(1, 0), 3.0);
  EXPECT_EQ(obj(1, 1), 4.0);

  EXPECT_THROW(obj(-1, 0), std::out_of_range);
  EXPECT_THROW(obj(0, -1), std::out_of_range);
}

TEST(Matrices, InvalidInverseMatrix) {
  S21Matrix obj(3, 3);
  EXPECT_THROW(obj.InverseMatrix(), std::logic_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
