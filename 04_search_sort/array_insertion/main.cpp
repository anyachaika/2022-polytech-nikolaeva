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

int search_position(int x, const int* arr, int n) {
    for (int i = 0; i < n; i++) if (arr[i] >= x) return i;
    return n;
}

void insert_sorted(int x, int*& arr, int &n) {
    insert(x, search_position(x, arr, n), arr, n);
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
    
    std::cout << "search_position function" << std::endl;
    std::cout << "Initial array: " << std::endl;
    for (int i = 0; i < N; i++)
        A[i] = i * 2;
    print(A, N);
    std::cout << "35 must be on position " << search_position(99, A, N) << std::endl;
    std::cout << "5 must be on position " << search_position(5, A, N) << std::endl;
    std::cout << std::endl;

    std::cout << "insert_sorted function" << std::endl;
    std::cout << "Initial array: " << std::endl;
    for (int i = 0; i < N; i++)
        A[i] = i * 2 + 1;
    print(A, N);
    insert_sorted(16, A, N);
    std::cout << "Array after insertion of " << 16 << ":" << std::endl;
    print(A, N);
    insert_sorted(6, A, N);
    std::cout << "Array after insertion of " << 6 << ":" << std::endl;
    print(A, N);
    return 0;
}