#include <cassert>

bool palindrome(const char* str) {
    if (str == nullptr) return false;
    const char* end = str;
    while (*end != '\0') ++end;
    --end;
    while (str < end) {
        if (*str != *end) return false;
        ++str;
        --end;
    }
    return true;
}

int main() {
    assert(palindrome("aaaa") == true);
    assert(palindrome("abba") == true);
    assert(palindrome("cbc") == true);
    assert(palindrome("hello world") == false);
    assert(palindrome(nullptr) == false);
    return 0;
}
