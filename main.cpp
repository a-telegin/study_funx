#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <exception>

bool equals(double, double, uint8_t precision);
void setBit(int& src, uint8_t bit);
void revertBit(int& src, uint8_t bit);
bool addVector(const int* src1, const int* src2, int* dst, std::size_t size); 
void printDemo1(double x, double y, uint8_t prec);
void printArray(const int* array, std::size_t size);

int main()
{
    // Demo1
    std::cout << "--------- Demo1 --------" << std::endl; 
    double x = 0.100000000009;
    double y = 0.1;
    uint8_t prec = 11;
    printDemo1(x, y, prec);
    prec += 2; 
    printDemo1(x, y, prec);
    std::cout << std::endl;   
    
    //Demo2
    std::cout << "--------- Demo2 ---------" << std::endl;
    int number = 32;
    const uint8_t digits = 4;
    for (int i = 0; i < digits; ++i)
    {
        setBit(number, i);
        std::bitset<8> b(number);
        std::cout << number << '\t' << b << std::endl; 
    }
    std::cout << std::endl;
    
    //Demo3
    std::cout << "--------- Demo3 ---------" << std::endl;
    number = 31;
    for (int i = 0; i < digits; ++i)
    {
        revertBit(number, i);
        std::bitset<8> b(number);
        std::cout << number << '\t' << b << std::endl; 
    }
    std::cout << std::endl;

    //Demo4
    std::cout << "--------- Demo4 ---------" << std::endl;

    const std::size_t size = 10;
    int arrayEven [] {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int arrayOdd [] {9, 7, 5, 3, 1, -1, -3, -5, -7, -9};
    int arraySum [size];
    printArray(arrayEven, size);
    printArray(arrayOdd, size);
    if (addVector(arrayEven, arrayOdd, arraySum, size))
        printArray(arraySum, size);
    std::cout << std::endl;
}

bool equals(double a, double b, uint8_t precision)
{
    return fabs(a - b) <= pow(0.1, precision);
}

void setBit(int& src, uint8_t bit)
{
    src |= (1 << bit);
}

void revertBit(int& src, uint8_t bit)
{
    src &= (~1 << bit);
}

void printDemo1(double x, double y, uint8_t prec)
{
    std::cout << std::setprecision(prec) << "x: " << x << ", y: " << y << std::endl;
    std::cout << "precision: " << static_cast<int>(prec) << ", x equal y? " << 
        equals(x, y, prec) << std::endl;
}
 
bool addVector(const int* src1, const int* src2, int* dst, std::size_t size)
{
    bool result = true;
    const int size_c = static_cast<int>(size);
    try
    {
        if (!(src1 && src2))
             throw "Null pointer exception!";
        for(int i = 0; i < size_c; ++i)
        {
            dst[i] = src1[i] + src2[i];
        }
    }
    catch (std::exception& e)
    {
        result = false;
    }
    return result;
}

void printArray(const int* array, std::size_t size)
{
    try
    {
        if (!array)
            throw "Null pointer exception!"
        const int size_c = static_cast<int>(size);
        std::cout << "{ "; 
        for (int i = 0; i < size_c; ++i) 
        {
            std::cout << array[i] << " ";
        }
        std::cout << "}" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception!" << std::endl;
    }
}

