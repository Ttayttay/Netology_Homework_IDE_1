#include <iostream>
#include <fstream>

using namespace std;

void move_right(int* array, int num_array);
void move_left(int* array, int num_array);

int main()
{
    setlocale(LC_ALL, "Russian");
    
    ifstream f;

    f.open("in.txt");

    if (f) {
        cout << "File is open!\n";
        cout << endl;

        int a = 0, b = 0;

        f >> a;
        int* arr_1 = new int[a];
        for (int i = 0; i < a; i++) {
            f >> arr_1[i];
        }

        f >> b;
        int* arr_2 = new int[b];
        for (int i = 0; i < b; i++) {
            f >> arr_2[i];
        }

        move_right(arr_2, b);
        move_left(arr_1, a);

        ofstream fout("out.txt");
        fout << b << endl;
        for (int i = 0; i < b; i++) {
            fout << arr_2[i] << ' ';
        }
        fout << endl;
        fout << a << endl;
        for (int i = 0; i < a; i++) {
            fout << arr_1[i] << ' ';
        }
        fout << endl;

        //print_array(arr_2, b);
        //print_array(arr_1, a);

        delete[] arr_1;
        delete[] arr_2;
    }
    else {
        cout << "File is not open\n";
    }
    cout << "Данные записаны в out.txt" << endl << endl;
    system("pause");
}

void move_right(int* array, int num){
    int l_arr = array[num - 1];
    for (int i = num-1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = l_arr;
}
void move_left(int* array, int num){
    int f_arr = array[0];
    for (int i = 0; i < num - 1; i++) {
        array[i] = array[i + 1];
    }
    array[num - 1] = f_arr;
}