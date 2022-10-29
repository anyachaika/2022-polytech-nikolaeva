#include <random>
#include <iostream>
#include <chrono>

double selection_sort(int* arr, int size) {
    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;
    return time.count();
}

double quick_sort(int* arr, int size) {
    if (size <= 1) return 0.0;
    auto start = std::chrono::system_clock::now();
    
    int pivot = arr[size / 2];
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }
        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    quick_sort(arr, right + 1);
    quick_sort(arr + left, size - left);

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;
    return time.count();
}

int random(int min, int max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(min, max);
    return dist(rng);
}

void print_array(int* arr, int n, bool show_index = false) {
    std::cout << "{";
    for(int i=0; i<n; ++i) {
        if (show_index) std::cout << i << ": ";
        std::cout << arr[i];
        if (i != n-1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

void fill_array_random(int *arr, int n, int a, int b) {
    for(int i=0; i<n; ++i)
        arr[i] = random(a, b);
}

int main() {
    for (int i = 0; i < 10; i++) {
        int n = random(1000, 10000);
        int* arr = new int[n];
        fill_array_random(arr, n, 100, 10000);
        int* arr2 = new int[n];
        std::copy(arr, arr + n, arr2);

        std::cout << "1e" << n << ": " << selection_sort(arr, n) << " (ss), " << quick_sort(arr2, n) << " (qs)" << std::endl;

        delete[] arr;
        delete[] arr2;
    }
    return 0;
}