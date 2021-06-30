#include <iostream>
#include <math.h>
#include <string>
#include  <ctime>

using namespace std;

void negativeNum()                                              // удаление отрицательный чисел из массива
{
    int* mas1;                                                  // оригинальный массив
    int* mas2;                                                  // массив только с положительными числами 
    int size = 20;                                              // размер массива
    int k = 0;                                                  // счетчик положительных чисел 
    mas1 = new int[size];
    for (int i = 0; i < size; i++)                              // заполнение массива случайными числами от -100 до 100
        mas1[i] = rand() % (100 - (-100) + 1) + (-100);

    for (int i = 0; i < size; i++)                              // вывод массива
        cout << mas1[i] << ' ';

    for (int i = 0; i < size; i++)                              // подсчёт положительных чисел
        if (mas1[i] > 0) k++;

    mas2 = new int[k];                                          // создание массива для положительных чисел

    int k1 = 0;                                                 // счётчик для заполнения 

    for (int i = 0; i < size; i++)                              // заполнение массива с положительными числами
        if (mas1[i] > 0)
        {
            mas2[k1] = mas1[i];                                 
            k1++;                                               // увеличение счётчика для полодительных чисел
        }

    delete[]mas1;                                               //удаление оригинального массива 

    cout << endl << endl;
    for (int i = 0; i < k; i++)                                 // вывод массива с положительными числами
        cout << mas2[i] << ' ';
}

void glas()
{
    
    string sTvowels;                                                   // строка в которой будут искаться гласные
    string alphabet;                                                   // алфавит для поиска
    alphabet = "aouieAOUIE";                                           // гласные буквы
    string vowels = "";                                                // пустая строка для гласных
    cout << "Введите строку (латиница): " << endl;
    cin >> sTvowels;                                                   // ввод строки, где будут искаться гласные
    

    for (int i = 0; i < sTvowels.length(); i++)                        // перемещение по буквам строки 
        for (int j = 0; j < alphabet.length(); j++)                    // пермещение по буквам алфавита
            if (alphabet[j] == sTvowels[i])                            // поиск соответствия
            {
                vowels += sTvowels[i];
            }

    cout << endl;
    cout << "Строка в которой искались гласные: " << sTvowels << endl;
    cout << "Найденные гласные: " << vowels << endl;                   //вывод гласных
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    negativeNum();
    cout << endl << endl;
    glas();
}