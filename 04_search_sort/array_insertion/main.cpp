#include <iostream>

int N = 5;
int* A = new int[5];

void insert(int x, int p, int*& arr, int &n) {
    int* tmp = new int[n + 1];
    std::copy(arr, arr + n, tmp);
    delete[] arr;
    for (int i = n; i > p; i--)
        tmp[i] = tmp[i - 1];
    tmp[p] = x;
    arr = tmp;
    n++;
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << "insert function" << std::endl;
    std::cout << "Initial array: " << std::endl;
    for (int i = 0; i < N; i++)
        A[i] = i;
    print(A, N);
    insert(99, 4, A, N);
    std::cout << "Array after insertion: " << std::endl;
    print(A, N);
    std::cout << std::endl;
    return 0;
}