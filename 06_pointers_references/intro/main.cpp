#include <cassert>

int length(const char* str) {
    if (str == nullptr) return 0;
    int len = 0;
    while (str[len] != '\0') ++len;
    return len;
}

int main() {
    assert(length("a") == 1);
    assert(length("ab") == 2);
    assert(length("") == 0);
    assert(length("hello world") == 11);
    assert(length(nullptr) == 0);
    return 0;
}
