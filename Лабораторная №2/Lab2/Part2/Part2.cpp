#include <iostream>   
#include <thread>     
#include <ctime>     
#include <cmath>      
#include <vector>
#include <iomanip>
#include <cstdlib>

void PowArr(double* b, double* a, size_t start, size_t size, size_t step) {
	for (size_t i = start; i < size; i += step) {
		for (size_t j = 0; j < i; j++)
			b[i] += pow(a[i], 1.789);
	}
}

void RndArr(double* mas, size_t N, int a, int b) {
	for (size_t i = 0; i < N; i++)
		mas[i] = ((double)(a + rand() % (b - a + 1))) / 100;
}

int main() {
	size_t const size = 100000;
	size_t const N = 2250;
	std::vector<double> a(size);
	std::vector<double> b(size, 0.0);
	RndArr(a.data(), size, 1, 10);
	std::vector<std::thread> threads;
	clock_t start1 = clock();
	for (size_t t = 0; t < N; t++) {
		threads.push_back(std::thread(PowArr, b.data(), a.data(), t, size, N));
		std::cout << "Id thread t" << t + 1 << ": " << threads.back().get_id() << std::endl;
	}
	for (auto& t : threads) t.join();
	clock_t end1 = clock();
	std::cout << "The parallel time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << " seconds\n" << std::endl;
}






//void PowArr(double* b, double* a, size_t start, size_t size, size_t step) {
//	for (size_t i = start; i < size; i += step) {
//		for (size_t j = 0; j < i; j++)
//			b[i] += pow(a[i], 1.789);
//	}
//}

//int main() {
//	size_t const size = 100000;
//	size_t const N = 50;
//	std::vector<double> a(size);
//	std::vector<double> b(size, 0.0);
//	RndArr(a.data(), size, 1, 10);
//	std::vector<std::thread> threads;
//	clock_t start1 = clock();
//	for (size_t t = 0; t < N; t++) {
//		threads.push_back(std::thread(PowArr, b.data(), a.data(), t, size, N));
//		std::cout << "Id thread t" << t + 1 << ": " << threads.back().get_id() << std::endl;
//	}
//	for (auto& t : threads) t.join();
//	clock_t end1 = clock();
//	std::cout << "The parallel time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << " seconds\n" << std::endl;
//}




//void PowArr(double* b, double* a, size_t start, size_t end) {
//	for (size_t i = start; i < end; i++) {
//		for (size_t j = 0; j < i; j++)
//			b[i] += pow(a[i], 1.789);
//	}
//}

//int main() {
//	size_t const size = 100000;
//	size_t const N = 3000;
//	std::vector<double> a(size);
//	std::vector<double> b(size, 0.0);
//	RndArr(a.data(), size, 1, 10);
//	std::vector<std::thread> threads;
//	clock_t start1 = clock();
//	for (size_t i = 0; i < N; i++) {
//		size_t start = i * size / N;
//		size_t end = (i == (N - 1)) ? size : (i + 1) * size / N;
//		threads.push_back(std::thread(PowArr, b.data(), a.data(), start, end));
//		std::cout << "Id thread t" << i + 1 << ": " << threads.back().get_id() << std::endl;
//	}
//	for (auto& t : threads) t.join();
//	clock_t end1 = clock();
//	std::cout << "The parallel time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << " seconds\n" << std::endl;
//}

















