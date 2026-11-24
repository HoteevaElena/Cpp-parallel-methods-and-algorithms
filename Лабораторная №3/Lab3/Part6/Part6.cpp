#include <chrono>
#include <future>
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>

//Задача по вариантам
constexpr long long size = 1000000;
constexpr long long fir = 250000;
constexpr long long sec = 500000;
constexpr long long thi = 750000;
constexpr long long fou = 1000000;
void sumUp(std::promise<unsigned long long>&& prom, const std::vector<int>& val1, const std::vector<int>& val2,
	unsigned long long beg, unsigned long long end) {
	unsigned long long sum = 0;
	for (auto i = beg; i < end; ++i) {
		sum += val1[i] * val2[i];
	}
	prom.set_value(sum);
}
int main() {
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
	std::promise<unsigned long long> prom1;
	std::promise<unsigned long long> prom2;
	std::promise<unsigned long long> prom3;
	std::promise<unsigned long long> prom4;
	auto fut1 = prom1.get_future();
	auto fut2 = prom2.get_future();
	auto fut3 = prom3.get_future();
	auto fut4 = prom4.get_future();
	auto sta = std::chrono::system_clock::now();
	std::thread t1(sumUp, std::move(prom1), std::ref(randValuesA), std::ref(randValuesB), 0, fir);
	std::thread t2(sumUp, std::move(prom2), std::ref(randValuesA), std::ref(randValuesB), fir, sec);
	std::thread t3(sumUp, std::move(prom3), std::ref(randValuesA), std::ref(randValuesB), sec, thi);
	std::thread t4(sumUp, std::move(prom4), std::ref(randValuesA), std::ref(randValuesB), thi, fou);
	auto sum = fut1.get() + fut2.get() + fut3.get() + fut4.get();
	const std::chrono::duration<double> dur = std::chrono::system_clock::now() - sta;
	std::cout << "Time for addition " << dur.count() << " seconds " << std::endl;
	std::cout << "Result: " << sum << std::endl;
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}


































////Учебный пример
//constexpr long long size = 100000000;
//constexpr long long fir = 25000000;
//constexpr long long sec = 50000000;
//constexpr long long thi = 75000000;
//constexpr long long fou = 100000000;
//void sumUp(std::promise<unsigned long long>&& prom, const std::vector<int>& val,
//	unsigned long long beg, unsigned long long end) {
//	unsigned long long sum = {};
//	for (auto i = beg; i < end; ++i) {
//		sum += val[i];
//	}
//	prom.set_value(sum);
//}
//int main() {
//	std::cout << std::endl;
//	std::vector<int> randValues;
//	randValues.reserve(size);
//	std::mt19937 engine;
//	std::uniform_int_distribution<> uniformDist(1, 10);
//	for (long long i = 0; i < size; ++i) randValues.push_back(uniformDist(engine));
//	std::promise<unsigned long long> prom1;
//	std::promise<unsigned long long> prom2;
//	std::promise<unsigned long long> prom3;
//	std::promise<unsigned long long> prom4;
//	auto fut1 = prom1.get_future();
//	auto fut2 = prom2.get_future();
//	auto fut3 = prom3.get_future();
//	auto fut4 = prom4.get_future();
//	auto sta = std::chrono::system_clock::now();
//	std::thread t1(sumUp, std::move(prom1), std::ref(randValues), 0, fir);
//	std::thread t2(sumUp, std::move(prom2), std::ref(randValues), fir, sec);
//	std::thread t3(sumUp, std::move(prom3), std::ref(randValues), sec, thi);
//	std::thread t4(sumUp, std::move(prom4), std::ref(randValues), thi, fou);
//	auto sum = fut1.get() + fut2.get() + fut3.get() + fut4.get();
//	const std::chrono::duration<double> dur = std::chrono::system_clock::now() - sta;
//	std::cout << "Time for addition " << dur.count() << " seconds " << std::endl;
//	std::cout << "Result: " << sum << std::endl;
//	t1.join();
//	t2.join();
//	t3.join();
//	t4.join();
//	std::cout << std::endl;
//}


















































//Учебный пример
//constexpr long long size = 100000000;
//constexpr long long fir = 25000000;
//constexpr long long sec = 50000000;
//constexpr long long thi = 75000000;
//constexpr long long fou = 100000000;
//void sumUp(std::promise<unsigned long long>&& prom, const std::vector<int>& val,
//	unsigned long long beg, unsigned long long end) {
//	unsigned long long sum = {};
//	for (auto i = beg; i < end; ++i) {
//		sum += val[i];
//	}
//	prom.set_value(sum);
//}
//int main() {
//	std::cout << std::endl;
//	std::vector<int> randValues;
//	randValues.reserve(size);
//	std::mt19937 engine;
//	std::uniform_int_distribution<> uniformDist(1, 10);
//	for (long long i = 0; i < size; ++i) randValues.push_back(uniformDist(engine));
//	std::promise<unsigned long long> prom1;
//	std::promise<unsigned long long> prom2;
//	std::promise<unsigned long long> prom3;
//	std::promise<unsigned long long> prom4;
//	auto fut1 = prom1.get_future();
//	auto fut2 = prom2.get_future();
//	auto fut3 = prom3.get_future();
//	auto fut4 = prom4.get_future();
//	auto sta = std::chrono::system_clock::now();
//	std::thread t1(sumUp, std::move(prom1), std::ref(randValues), 0, fir);
//	std::thread t2(sumUp, std::move(prom2), std::ref(randValues), fir, sec);
//	std::thread t3(sumUp, std::move(prom3), std::ref(randValues), sec, thi);
//	std::thread t4(sumUp, std::move(prom4), std::ref(randValues), thi, fou);
//	auto sum = fut1.get() + fut2.get() + fut3.get() + fut4.get();
//	const std::chrono::duration<double> dur = std::chrono::system_clock::now() - sta;
//	std::cout << "Time for addition " << dur.count() << " seconds " << std::endl;
//	std::cout << "Result: " << sum << std::endl;
//	t1.join();
//	t2.join();
//	t3.join();
//	t4.join();
//	std::cout << std::endl;
//}