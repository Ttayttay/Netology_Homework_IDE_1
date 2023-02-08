// Netology_Homework_IDE_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Привет мир!\n\n\n";
    
    ifstream f;

    f.open("in.txt");

    if (f) {
        cout << "File is open!\n";

        int* arr = new int[10];

        for (int i = 0; i < 10; i++) {
            f >> arr[i];
        }

        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            cout << arr[i] << " ";
        }
    }
    else {
        cout << "File is not open\n";
    }

    system("pause");
}