#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

//Задача по вариантам
int main()
{
	constexpr long long size = 1000000;
	std::vector<int> randValuesA;
	std::vector<int> randValuesB;
	randValuesA.reserve(size);
	randValuesB.reserve(size); 
	std::mt19937 engine; 
	std::uniform_int_distribution<> uniformDist(1, 10);
	for (long long i = 0; i < size; ++i) {
		randValuesA.push_back(uniformDist(engine));
		randValuesB.push_back(uniformDist(engine));
	} 
	unsigned long long sum = 0;
	const auto sta = std::chrono::steady_clock::now();
	for (long long i = 0; i < size; ++i) {
		sum = sum + (randValuesA[i] * randValuesB[i]);
	}
	const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
	std::cout << "Time for addition " << dur.count() << " seconds" << std::endl;
	std::cout << "Result:" << sum << std::endl;
}








////Учебный пример
//using namespace std;
//int main()
//{
//	constexpr long long size = 100000000;
//	cout << std::endl;
//	vector<int> randValues;
//	randValues.reserve(size);
//	random_device seed; 
//	mt19937 engine(seed()); 
//	uniform_int_distribution<> uniformDist(1, 10);
//	for (long long i = 0; i < size; ++i) randValues.push_back(uniformDist(engine));
//	const auto sta = std::chrono::steady_clock::now();
//	unsigned long long sum = { 0 };
//	for (auto n : randValues) sum += n;
//	const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
//	std::cout << "Time for addition " << dur.count() << " seconds" << std::endl;
//	std::cout << "Result:" << sum << std::endl;
//	std::cout << std::endl;
//}
