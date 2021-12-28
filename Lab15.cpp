// Lab15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
unsigned long long compare_counter = 0;
unsigned long long copy_counter = 0;
struct Person
{
    string Last_Name;
    string Name;
    string Patronymic;
    int day;
    int month;
    int year;
    bool operator > (const Person& p) const {
        return this->day > p.day && this->month > p.month && this->year > p.year && this->Last_Name < p.Last_Name && this->Name < p.Name && this->Patronymic<p.Patronymic ;
    }
};


int FindMinimumIndex(int input_data[], int first_index, int last_index)
{
    int min = input_data[first_index];
    int  min_index = first_index;
    for (int i = first_index; i < last_index; ++i)
    {
        if (input_data[i] < min)
        {
            compare_counter++;
            min_index = i;
            min = input_data[i];
        }
    }
    return min_index;

}
void Swap(int& first_element, int& second_element)
{
    int temp = first_element;
    first_element = second_element;
    second_element = temp;
    copy_counter += 3;
}

void SelectionSort(int array[], int N)
{
    for (int i = 0; i < N; ++i) {
        int minimum_index = FindMinimumIndex(array, i, N - 1);
        Swap(array[i], array[minimum_index]);
    }


}

void BubbleUp(int input_data[], int start_index, int final_index, int& new_border)
{
    if (final_index + 1 <= start_index)
    {
        for (int i = start_index; i > final_index; --i)
        {
            if (input_data[i] < input_data[i - 1])
            {
                compare_counter++;
                Swap(input_data[i], input_data[i - 1]);
            }
        }
    }
    else
    {
        return;
    }
}
void BubbleSort(int array[], int N)
{
    int current_border = 0;
    while (current_border < N) {
        int new_border = N;
        BubbleUp(array, N - 1, current_border, new_border);
        current_border = new_border;
    }

}
void InsertionSort(int array[], int N)
{
    int i, key, j;
    for (i = 1; i < N; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            copy_counter++;
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
void InsertionPeopleSort(Person array[], int N)
{
    int j;
    Person key;
    for (int i = 1; i < N; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            copy_counter++;
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

int main()
{
    Person a;
    Person b;
    Person c;
    a.Last_Name = 'a';
    a.Name = 'a';
    a.Patronymic = 'a';
    a.day = 1;
    a.month = 1;
    a.year = 1;
    b.Last_Name = 'b';
    b.Name = 'b';
    b.Patronymic = 'b';
    b.day = 2;
    b.month = 2;
    b.year = 2;
    c.Last_Name = 'c';
    c.Name = 'c';
    c.Patronymic = 'c';
    c.day = 0;
    c.month = 0;
    c.year = 0;
    Person arr[3] = { a,b,c };
    InsertionPeopleSort(arr, 3);
    for (int i = 0; i < 3; ++i)
    {
        cout << arr[i].Name << ' ';
    }



    
    
}

