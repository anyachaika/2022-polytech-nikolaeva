#include <cstring>
#include <cassert>
#include <iostream>

int length(const char * a) {
    if (a == nullptr) return 0;
    int len = 0;
    while (a[len] != '\0') ++len;
    return len;
}

const char* itos(int n) {
    if (!n) return "0";

    int m = n;
    int numofdigits = 0;
    while (m) {
        numofdigits++;
        m /= 10;
    }

    char* arr;
    arr = (char *)malloc(numofdigits + 1);
    arr[numofdigits] = '\0';
    while (n) {
        arr[--numofdigits] = n % 10 + '0';
        n /= 10;
    }
    return (const char *)arr;
}

const char* mul(const char* a, const char* b) {
    int lena = length(a);
    int lenb = length(b);
    int len = lena + lenb;
    char *arr;
    arr = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) arr[i] = '0';
    arr[len] = '\0';

    for (int i = lena - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = lenb - 1; j >= 0; j--) {
            int temp = (a[i] - '0') * (b[j] - '0') + carry + (arr[i + j + 1] - '0');
            arr[i + j + 1] = temp % 10 + '0';
            carry = temp / 10;
        }
        arr[i] += carry;
    }

    int i = 0;
    while (arr[i] == '0') {
        i++;
    }
    return (const char *)arr + i;
}

int main() {
    assert(strcmp(mul("12", "4"), "48") == 0);
    assert(strcmp(mul("2", "3"), "6") == 0);
    return 0;
}