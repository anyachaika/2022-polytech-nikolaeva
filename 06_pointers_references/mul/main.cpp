#include <cassert>
#include <iostream>

void matmul(int** a, int m_a, int n_a, int** b, int m_b, int n_b, int** c) {
    assert(n_a == m_b);
    for (int i = 0; i < m_a; ++i) {
        for (int j = 0; j < n_b; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n_a; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

bool mateq(int** a, int m_a, int n_a, int** b, int m_b, int n_b) {
    if (m_a != m_b || n_a != n_b) return false;
    for (int i = 0; i < m_a; i++) {
        for (int j = 0; j < n_a; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int a_row0[3] = {3, 1, 6};
    int a_row1[3] = {2, 0, 5};
    int a_row2[3] = {1, 3, 2};
    int *a[3] = {a_row0, a_row1, a_row2};

    int b_row0[3] = {9, 3, 7};
    int b_row1[3] = {7, 1, 5};
    int b_row2[3] = {1, 4, 5};
    int *b[3] = {b_row0, b_row1, b_row2};

    int c_row0[3] = {40, 34, 56};
    int c_row1[3] = {23, 26, 39};
    int c_row2[3] = {32, 14, 32};
    int *expected_c[3] = {c_row0, c_row1, c_row2};

    int **c = new int *[3];
    for (int i = 0; i < 3; i++)
        c[i] = new int[3];

    matmul(a, 3, 3, b, 3, 3, c);
    assert(mateq(c, 3, 3, expected_c, 3, 3) == true);
    return 0;
}