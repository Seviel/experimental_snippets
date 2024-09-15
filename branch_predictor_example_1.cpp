#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <chrono>

constexpr int ARRAY_SIZE = 100000;

int main()
{
    srand(time(0));
    std::vector<int> numbers;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        int rand_num = rand() % ARRAY_SIZE;
        numbers.push_back(rand_num);
    }

    int count = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        if (numbers[i] > ARRAY_SIZE / 2)
            ++count;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Unsorted execution time: " << time << " us" << std::endl;

    std::cout << "Count: " << count << std::endl;

    count = 0;

    std::sort(numbers.begin(), numbers.end());

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        if (numbers[i] > ARRAY_SIZE / 2)
            ++count;
    }

    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Sorted execution time: " << time << " us" << std::endl;

    std::cout << "Count: " << count << std::endl;

    return 0;
}