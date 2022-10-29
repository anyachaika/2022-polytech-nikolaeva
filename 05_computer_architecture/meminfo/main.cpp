#include <iostream>
#include <fstream>
#include <cmath>

void show_meminfo() {
    char parameter[20];
    char unit[3];
    int total, free, avail;

    std::ifstream in("/proc/meminfo", std::ios_base::in);
    if (in.is_open()) {
        in >> parameter >> total >> unit;
        in >> parameter >> free >> unit;
        in >> parameter >> avail >> unit;
    } else exit(1);

    int percent = (int)((total - avail) / (float)total * 100);
    int bars_count = (int)round(percent / 5);

    for (int i = 0; i != bars_count; i++) std::cout << "$";
    for (int i = 0; i != 20 - bars_count; i++) std::cout << ".";
    std::cout << " " << percent << "%" << std::endl;
}

int main() {
    show_meminfo();
    return 0;
}