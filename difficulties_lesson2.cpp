#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string_view>
#include "Header.h"
using namespace std;

//==========================================================================================================================================================
/* Задание №1. Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами значения, 
на которые указывают эти указатели (нужно обменивать именно сами указатели, переменные должны оставаться в тех же адресах памяти).*/
//==========================================================================================================================================================

template<typename T>
void Swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

//==========================================================================================================================================================
/* Задание №2. Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и сортирует указатели по значениям, на которые они указывают.*/
//==========================================================================================================================================================

template<typename T>
void SortPointers(vector<T*>& vec)
{
    sort(vec.begin(), vec.end(), [](const auto& vec1, const auto& vec2)
        {
            return *vec1 < *vec2;
        });
}

template<typename T>
void print_pointers(vector<T*>& vec, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << *vec[i] << ' ';
    }
    cout << endl;
}

//=====================================================================================================================================================
/* Задание №3. Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4 способа:
○ count_if и find
○ count_if и цикл for
○ цикл for и find
○ 2 цикла for
Замерьте время каждого способа подсчета и сделайте выводы.*/
//=====================================================================================================================================================


const string_view vowels  { "AEIOUaeiou" };

void way_1(const string_view& str)
{
    Timer timer("Counting vowels 1st way:");
    int Vowel_Count = count_if(str.begin(), str.end(), [&](const auto& c) { return vowels.find(c) != string::npos;});
    cout << Vowel_Count << endl;
    timer.print();
}

void way_2(const string_view& str)
{
    Timer timer("Counting vowels 2nd way:");
    int Vowel_Count = count_if(str.begin(), str.end(), [&](const auto& c)
    {
        for (int i = 0; i < vowels.size(); ++i)
        {
            if (vowels[i] == c)
            return true;
        }
        return false;
    });
    cout << Vowel_Count << endl;
    timer.print();
}

void way_3(const string_view& str)
{
    Timer timer("Counting vowels 3rd way:");
    int Vowel_count = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (vowels.find(str[i]) != string::npos)
        {
            ++Vowel_count;
        }
    }
    cout << Vowel_count << endl;
    timer.print();
}

void way_4(const string_view& str)
{
    Timer timer("Counting vowels 4th way:");
    int Vowel_count = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        for (size_t j = 0; j < vowels.size(); ++j)
        {
            if (vowels[j] == str[i])
            ++Vowel_count;
        }
    }
    cout << Vowel_count << endl;
    timer.print();
}

int main()
{
    cout << "Task No.1" << endl;
    int a(5);
    int b(6);
    Swap(&a, &b);
    cout << a << ' ' << b << endl;

    cout << "Task No.2" << endl;
    int length = 10;
    vector<int*> vec;
    for (int i = 0; i < length; ++i)
    {
        int* a = new int;
        *a = rand() % 100;
        vec.push_back(a);
    }

    print_pointers(vec, 10);
    SortPointers(vec);
    print_pointers(vec, 10);

    cout << "Task No.3" << endl;
    ifstream file;
    file.open ("TextFile1.txt");
    file.seekg(0, ios::end);
    size_t find = file.tellg();
    file.seekg(0);
    string str(find, ' ');
    file.read(&str[0], find);

    way_1(str);              
    way_2(str);               
    way_3(str);               
    way_4(str);              
    
    return 0;
}

