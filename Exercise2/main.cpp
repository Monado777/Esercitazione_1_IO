#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    std::ofstream outFile("results.csv");
    ifstream inFile;
    inFile.open("data.csv");
    if(inFile.fail())
    {
        std::cerr << "The file does not exist." << std::endl;
        exit(1);
    }

    int a = 1; int a_ = -1;
    int b = 5; int b_ = 2;
    double sum = 0; double mean = 0; double val = 0;
    double n; int N = 1;
    while(inFile >> n)
    {
        val = (n - a)*(b_ - a_)/(b-a) + a_;
        sum += val;
        mean = sum/N;
        N += 1;
        outFile << mean << std::endl;
    }
    outFile.close();
    inFile.close();
    return 0;
}
