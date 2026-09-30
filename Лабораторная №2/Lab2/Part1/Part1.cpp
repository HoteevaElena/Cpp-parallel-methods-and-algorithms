#include <iostream>   
#include <thread>     
#include <ctime>     
#include <cmath>      
#include <vector>
#include <iomanip>
#include <cstdlib>

void RndArr(double* mas, size_t N, int a, int b) {
    for (size_t i = 0; i < N; i++)
        mas[i] = ((double)(a + rand() % (b - a + 1))) / 100;
}

void OutArray(double* arr, size_t N){
    std::cout << std::endl;
    for (size_t i = 0; i < N; i++) {
        std::cout << std::setw(10) << arr[i];
    }
    std::cout << std::endl;
}

void PowArr(double* b, double* a, size_t beg, size_t end, int K) {
    for (size_t i = beg; i < end; i++) {
        for (int j = 0; j < K; j++)
            b[i] += pow(a[i], 1.789);
    }
}

int main()
{
    size_t const size = 5000;
    std::vector<double> a(size);
    std::vector<double> b(size, 0.0);
    RndArr(a.data(), size, 1, 10);
    /*OutArray(a.data(), size);*/
    clock_t start1 = clock();
    PowArr(b.data(), a.data(), 0, size, 500000);
    clock_t end1 = clock();
    std::cout << "The time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << " seconds\n" << std::endl;
    /*OutArray(b.data(), size);*/
}

