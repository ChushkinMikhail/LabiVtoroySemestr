//
//  main.cpp
//  Sem1
//
//  Created by Михаил on 28.02.2024.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Vector 
    {
    double* Chleni = nullptr;
    int size = 0;

    public:

    Vector(double* Mass, int n) //конструктор создания вектора значений с заданным размеровм
        {
        size = n;
        Chleni = new double [size];
            
        for (int i = 0; i < size; ++i)
            {
            Chleni [i] = Mass [i];
            }
        }
        
    Vector(int n) //конструктор созданя пустого вектора с заданной длинной
        {
        size = n;
        Chleni = new double[size];
        }

    Vector(Vector& V1) //конструктор копированя
        {
        size = V1.size;
        Chleni = new double[size];
        
        for (int i = 0; i < size; ++i)
            {
            Chleni [i] = V1.Chleni [i];
            }
        }

    Vector(Vector&& V2) //конструктор перемещения
        {
        swap (Chleni, V2.Chleni); //меняются указатели на массив
        swap (size, V2.size); //меняются размерности
        }

    double& operator [] (int i) //перегрузка операци доступа к элементу по индексу
        {
        return Chleni [i];
        }

    Vector& operator = (Vector& V3) //перегрузка оператора прсваивания с копированиием
        {
        if (this != &V3)
            {
            size = V3.size;
                
            if (Chleni == nullptr)
                {
                delete[] Chleni;
                }
        
            Chleni = new double[size];
                
            for (int i = 0; i < size; ++i)
                {
                Chleni[i] = V3.Chleni[i];
                }
            }
        return *this;
        }

    Vector& operator = (Vector&& V3) //перегрузка оператора прсваивания с перемещением
        {
        if (this != &V3)
            {
            swap (Chleni, V3.Chleni);  //меняются указатели на массив
            swap (size, V3.size); //меняются размерности
            }
        return *this;
        }

    friend ostream& operator << (ostream& out, Vector& V) //перегрузка ввода
        {
        for (int i = 0; i < V.size; ++i)
            {
            out << V.Chleni [i] << " ";
            }
        return out;
        }

    friend istream& operator >> (istream& in, Vector& V) //перегрузка вывода
        {
        for (int i = 0; i < V.size; ++i)
            {
            in >> V.Chleni [i];
            }
        return in;
        }

    friend Vector operator + (Vector& V1, Vector& V2) //перегрузка операции сложения
        {
        Vector V3 (V1.size + V2.size); //прсваивание длине нового вектора сумму длинн двух заданных
        
        for (int i = 0; i < V1.size; ++i)
            {
            V3 [i] = V1.Chleni [i]; //первые элементы нового вектора - все элементы первого вектора
            }
        
        for (int i = 0; i < V2.size; ++i)
            {
            V3 [i + V1.size] = V2.Chleni [i]; //все последюзие элементы - все элемеенты второго вектора
            }
        
        return V3;
        }
        
    ~Vector() //диструктор класса
        {
        delete [] Chleni;
        }
    };

int main() 
    {
    ifstream inputFile ("in.txt");
    
    if (!inputFile.is_open())
        {
        cout << "Файл не открыт" << endl;
        return 1;
        }

    int a;
    int b;
    inputFile >> a >> b;

    Vector V1 (a);
    Vector V2 (b);
    inputFile >> V1  >> V2;
    
    inputFile.close();

    Vector V3 = V1 + V2;

    ofstream outputFile ("out.txt");
    
    if (!outputFile.is_open())
        {
        cout << "файл не открыт 1111" <<"\n";
        return 1;
        }

    outputFile << "Vector 1: " << V1 <<"\n";
    outputFile << "Vector 2: " << V2 <<"\n";
    outputFile << "Sum: " << V3 <<"\n";
    
    outputFile.close();

    return 0;
    }
