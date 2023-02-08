// Netology_Homework_IDE_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

void reverse(int* n, int* s) {
    if (n < s) {
        *n += *s;
        *s = *n - *s;
        *n -= *s;
        reverse(n + 1, s - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Привет мир!\n\n\n";
    
    ifstream f;

    f.open("in.txt");

    if (f) {
        cout << "File is open!\n";

        int a = 0, b = 0;
        
        f >> a;

        int* arr_1  = new int[a];

        for (int i = 0; i < a; i++) {
            f >> arr_1[i];
            //cout << arr_1[i] << "\t";
        }
        cout << endl;

        f >> b;

        int* arr_2 = new int[b];

        for (int i = 0; i < b; i++) {
            f >> arr_2[i];
            //cout << arr_2[i] << "\t";
        }
        cout << endl;

        for (int i = 0; i < a; i++) {
            for (int j = i + 1; j < a; j++) {
                if (arr_1[i] > arr_1[j]) {
                    int temp = arr_1[i];
                    arr_1[i] = arr_1[j];
                    arr_1[j] = temp;
                }
            }
        }

        for (int i = 0; i < b; i++) {
            for (int j = i + 1; j < b; j++) {
                if (arr_2[i] > arr_2[j]) {
                    int temp = arr_2[i];
                    arr_2[i] = arr_2[j];
                    arr_2[j] = temp;
                }
            }
        }
        reverse(arr_1, arr_1 + a - 1);
        for (int i = 0; i < a; i++) {
            cout << arr_1[i] << " ";
        }
        cout << endl;
        reverse(arr_2, arr_2 + b - 1);
        for (int i = 0; i < b; i++) {
            cout << arr_2[i] << " ";
            
        }
        cout << endl;
    }
    else {
        cout << "File is not open\n";
    }
}
