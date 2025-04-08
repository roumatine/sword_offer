#include "..\head.h"

struct  Matrix2b2
{
    Matrix2b2 (
        long long m00 = 0,
        long long m01 = 0,
        long long m10 = 0,
        long long m11 = 0
    ): m_00(m00), m_01(m01), m_10(m10), m_11(m11) {}

    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2b2 MatrixMultiply(const Matrix2b2& m1, const Matrix2b2& m2) {
    return Matrix2b2(
        m1.m_00 * m2.m_00 + m1.m_01 * m2.m_10,
        m1.m_00 * m2.m_01 + m1.m_01 * m2.m_11,
        m1.m_10 * m2.m_00 + m1.m_11 * m2.m_10,
        m1.m_10 * m2.m_01 + m1.m_11 * m2.m_11
    );
}

Matrix2b2 MatrixPower(unsigned int n) {
    assert(n > 0);
    Matrix2b2 matrix;
    if (n == 1) {
        matrix = Matrix2b2(1, 1, 1, 0);
    } else if (n % 2 == 0) {
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    } else if (n % 2 == 1) {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2b2(1, 1, 1, 0));
    }
    return matrix;
}

long long Fibonacci_Solution3(unsigned int n ) {
    int result [2] = {0, 1};
    if (n < 2) {
        return result[n];
    }
    Matrix2b2 PowerMin2 = MatrixPower(n - 1);
    return PowerMin2.m_00;
}