#include <iostream>
#include <thread>
#include <ctime>
#include <cmath>
#include <mutex>
#include <vector>
#include <fstream>
#include <algorithm>

std::mutex cout_mutex;
void examp() {
    double x = 12345.6789;
    for (int i = 0; i < 10000; i++){
        for (int j = 0; j < 10000; j++){
            x = sqrt(x);
            x = x + 0.000000001;
            x = pow(x, 2);
        }
    }
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "[A] examp: " << x << std::endl;
}
void taskWriteFile() {
    std::ofstream outFile("data.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < 1000; i++) {
            outFile << i * 2 << " ";
        }
        outFile.close();
    }
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "[B] The file data.txt is created" << std::endl;
}
void taskReadFile() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::ifstream inFile("data.txt");
    std::vector<int> numbers;
    int num;

    if (inFile.is_open()) {
        while (inFile >> num) {
            numbers.push_back(num);
        }
        inFile.close();
    }
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "[C] The numbers read from the file: " << numbers.size() << std::endl;
    if (!numbers.empty()) {
        std::cout << "[C] The first number: " << numbers[0]
            << ", The last number: " << numbers[numbers.size() - 1] << std::endl;
    }
}
void taskConsoleIO() {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Enter a number: " << std::flush;
    int userInput;  
    std::cin >> userInput;
    std::cout << "[D] A number was entered: " << userInput << std::endl;
}
void taskArray() {
    std::vector<int> arr = { 3, 38, 5, 25, 2365, 439, 8, 934, 57, 26 };
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int x : arr) {
        sum += x;
    }
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "[E] The array is sorted: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "[E] The sum of the array elements: " << sum << std::endl;
}
int main(){
    int N = std::thread::hardware_concurrency();
    std::vector<std::thread*> t(N + 1);
    clock_t start1 = clock();
    t[0] = new std::thread(examp);
    std::cout << "Id thread t1: " << t[0]->get_id() << std::endl;
    t[1] = new std::thread(taskWriteFile);
    std::cout << "Id thread t2: " << t[1]->get_id() << std::endl;
    t[2] = new std::thread(taskReadFile);
    std::cout << "Id thread t3: " << t[2]->get_id() << std::endl;
    t[3] = new std::thread(taskConsoleIO);
    std::cout << "Id thread t4: " << t[3]->get_id() << std::endl;
    t[4] = new std::thread(taskArray);
    std::cout << "Id thread t5: " << t[4]->get_id() << std::endl;
    for (int i = 0; i <N + 1; i++) {
        t[i]->join();
    }
    clock_t end1 = clock();
    std::cout << "The time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << " seconds\n" << std::endl;
    for (int i = 0; i < N + 1; i++) {
        delete t[i];
    }
}




    //int N = std::thread::hardware_concurrency();
    //std::vector <std::thread*>   t(N + 1);
    //char ch = 65;

    //clock_t   start1 = clock();
    //for (int i = 0; i < N + 1; i++) {
    //    t[i] = new std::thread(examp, ch + i);
    //    std::cout << "Id thread t" << i + 1 << ": " << t[i]->get_id() << std::endl;
    //}
    //for (int i = 0; i < N + 1; i++){
    //    t[i]->join();
    //}
    //clock_t end1 = clock();
    //std::cout << "The time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << " seconds\n" << std::endl;

    //for (int i = 0; i < N + 1; i++){
    //    delete t[i];
    //}







    //int N = std::thread::hardware_concurrency();

    //std::vector <std::thread>   t(N + 1);

    //char ch = 65;

    //clock_t start1 = clock();
    //for (int i = 0; i < N + 1; i++)
    //{
    //    t[i] = std::thread(examp, ch + i);
    //    std::cout << "Id thread t" << i + 1 << ": " << t[i].get_id() << std::endl;

    //}
    //for (int j = 0; j < N + 1; j++)
    //{
    //    t[j].join();
    //}
    //clock_t end1 = clock();
    //std::cout << "The time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << " seconds\n" << std::endl;







