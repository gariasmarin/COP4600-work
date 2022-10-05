#include <thread>
#include <iostream>
#include <thread>
#include <random>
#include <array>
#include <cstdlib>


using std::cin;
using std::cout;


// code to give threads ID's and create random number to match cmd line number
void driverCode(int ID, int inputNumber)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,9999);
    
    int randomNumber = -1;
    while (inputNumber != randomNumber)
    {
        randomNumber = distribution(generator);
    }
    cout << "Thread " << ID << " completed.\n";
}

int main(int argc, char** argv) 
{
    // cmd line user input number
    int input = std::atoi(argv[1]);

    //create 10 threads
    std::array<std::thread, 10> threads;

    for(int i = 0; i < threads.size(); i++)
    {
        //loop threads calling the driver code
        threads[i] = std::thread(driverCode, i, input);
    }
    for(int i = 0; i < threads.size(); i++)
    {
        //threads wait for each other to finish
        threads[i].join();
    }
    
    return 0;

}