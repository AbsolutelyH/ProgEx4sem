#include <iostream>

using namespace std;

int max(int x, int y, int z)                            // функция, которая возвращает наибольший из трех целочисленных аргументов;
{
    int max = x;
    if (y > max) max = y;
    if (z > max) max = z;
    return max;
}

int borders(int bottom, int top)                        //  ввод числа и проверка его на попадание в границы
{
    double x;
    cout << "Введите число: ";
    cin >> x;
    if (x == int(x)) 
    {
        if (x >= bottom && x <= top)
        {
            return x;
        }
        else
        {
            return -9999;
        }
    }
    else 
    {
        return 0;
    }
}

void menu()                                                             // функция вызова меню
{
    bool x = true;
    int bottom = -9990, top = -9990, var, result;
    while (x)
    {
        cout << "1) Ввод верхнего предела" << endl;
        cout << "2) Ввод нижнего предела" << endl;
        cout << "3) Ввести число" << endl;
        cout << "4) Выход" << endl;
        int choice;
        do
        {
           cin >> choice;
        } 
        while (choice < 1 || choice > 4);

        switch (choice)
        {
        case 1:
            cout << "Введите верхний предел: ";
            cin >> top;
            break;
        case 2:
            cout << "Введите нижний предел: ";
            cin >> bottom;
            break;
        case 3:
            if (bottom == -9990 || top == -9990) { cout << "Сначала введите пределы " << endl;  break; }
            else
            {
                result = borders(bottom, top);
                if (result == 0) x = false;
                if (result == -9999) continue;
            }
       
        case 4: x = false;
            break;
        }


    }
}

void mas()                                             // сортировка вставками 
{
    int t;
    int arr[10];
    cout << "Введите массив для сортировки" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        
    }

    cout << endl;

    for (int i = 1; i < 10; i++)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) 
        {
            t = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = t;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

}


int main()
{
    setlocale(LC_ALL, "RUS");

    cout << max(1, 2, 3) << endl;
    cout << endl;
    menu();
    cout << endl;
    mas();
}
