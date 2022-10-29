#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

void get_cpuinfo(unsigned long long &total, unsigned long long &idle) {
    char line[3];
    std::ifstream in("/proc/stat", std::ios_base::in);
    in >> line;

    total = 0;
    unsigned long long param;
    for (int i = 0; i != 10; ++i)
        if (in.is_open()) {
            in >> param;
            total += param;
            if (i == 3) idle = param;
        } else exit(0);
}

int main() {
    unsigned long long total, total2, idle, idle2, delta_total, delta_idle;
    get_cpuinfo(total, idle);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    get_cpuinfo(total2, idle2);
    delta_total = total2 - total;
    delta_idle = idle2 - idle;
    int percent_usage = (int)(((double)(delta_total - delta_idle) / (double)delta_total) * 100);
    std::cout << "CPU usage: " << percent_usage << "%" << std::endl;
    return 0;
}
