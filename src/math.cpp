#include "math.h"
#include <Eigen/Dense>
#include <iostream>

// using Eigen::MatrixXd;
using namespace std;

int add(int a, int b)
{
  return a + b;
}

int add_use_eigen()
{
  // 初始化两个3x3的矩阵
  Eigen::Matrix3f matrixA; // 3x3的浮点数矩阵
  Eigen::Matrix3f matrixB;
  Eigen::Matrix3f result;

  // 填充矩阵A和B
  matrixA << 1, 2, 3,
      4, 5, 6,
      7, 8, 9;

  matrixB << 10, 11, 12,
      13, 14, 15,
      16, 17, 18;

  // 矩阵相加
  result = matrixA + matrixB;

  // 输出结果
  std::cout << "矩阵A + 矩阵B 的结果是:\n"
            << result << std::endl;

  return 0;
}