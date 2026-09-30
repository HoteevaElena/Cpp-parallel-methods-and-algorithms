#include <iostream>
#include <thread>
#include <ctime>
#include <cmath>
#include <mutex>

std::mutex cout_mutex;
int main()
{ 
    class functioObject_class { 
    public:
        void operator()(char str)
        {
            double x = 12345.6789;
            for (int i = 0; i < 10000; i++) 
            {
                for (int j = 0; j < 10000; j++)
                {
                    x = sqrt(x);
                    x = x + 0.000000001;
                    x = pow(x, 2);
                }
            }
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << str << "=" << x << std::endl;
        }
    };
    functioObject_class functor_obj;
    clock_t   start1 = clock();
    std::thread t1(functor_obj, 'A');
    std::cout << "Id thread t1: " << t1.get_id() << std::endl;
    std::thread t2(functor_obj, 'B');
    std::cout << "Id thread t2: " << t2.get_id() << std::endl;
    std::thread t3(functor_obj, 'C');
    std::cout << "Id thread t3: " << t3.get_id() << std::endl;
    std::thread t4(functor_obj, 'D');
    std::cout << "Id thread t4: " << t4.get_id() << std::endl;
    std::thread t5(functor_obj, 'E');
    std::cout << "Id thread t5: " << t5.get_id() << std::endl;
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    clock_t end1 = clock();
    std::cout << "The time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << " seconds\n" << std::endl;
}

    



//std::mutex cout_mutex;
//auto f = [](char str) {
//    double x = 12345.6789;
//    for (int i = 0; i < 10000; i++) 
//    {
//        for (int j = 0; j < 10000; j++)
//        {
//            x = sqrt(x);
//            x = x + 0.000000001;
//            x = pow(x, 2);
//        }
//    }
//    std::lock_guard<std::mutex> lock(cout_mutex);
//    std::cout << str << "=" << x << std::endl;
//};


    //std::thread t1(examp, 'A');
    //std::cout << "Id thread t1: " << t1.get_id() << std::endl;
    //std::thread t2(examp, 'B');
    //std::cout << "Id thread t2: " << t2.get_id() << std::endl;
    //std::thread t3(examp, 'C');
    //std::cout << "Id thread t3: " << t3.get_id() << std::endl;
    //std::thread t4(examp, 'D');
    //std::cout << "Id thread t4: " << t4.get_id() << std::endl;
    //std::thread t5(examp, 'E');
    //std::cout << "Id thread t5: " << t5.get_id() << std::endl;
    //t1.join();
    //t2.join();
    //t3.join();
    //t4.join();
    //t5.join();

    //examp('A');
    //examp('B');
    //examp('C');
    //examp('D');
    //examp('E');

//void examp(char str) {
//    double x = 12345.6789;
//    for (int i = 0; i < 10000; i++)
//        for (int j = 0; j < 10000; j++)
//        {
//            x = sqrt(x);
//            x = x + 0.000000001;
//            x = pow(x, 2);
//        }
//    std::cout << str << "=" << x << std::endl;
//
//}






