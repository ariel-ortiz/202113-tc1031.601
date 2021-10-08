#include <iostream>
#include <climits>

int main()
{
    int min = 1'000'000'000;
    int max = 2'000'000'000;
    int mid;

    std::cout << "min                 = " << min << '\n';
    std::cout << "max                 = " << max << '\n';

    mid = (min + max) / 2;
    std::cout << "mid (with overflow) = " << mid << '\n';

    mid = min + (max - min) / 2;
    std::cout << "mid (no overflow)   = " << mid << '\n';
}