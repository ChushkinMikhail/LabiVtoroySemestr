//
//  main.cpp
//  Laa1Class
//
//  Created by Михаил on 21.02.2024.
//

#include <iostream>

using namespace std;

class Vectors
    {
    private:
        string name;
        int x;
        int y;
        double length;
    public:
        Vectors (string n, int a, int b)
            {
            name = n;
            x = a;
            y = b;
            }
        void Vprint ();
        void LengthCount ();
        double Get_length ()
            {
            return length;
            }
    };

int main()
    {
    Vectors V1 {"Вектор1", 1, 1};
    Vectors V2 {"Вектор2", 2, 5};
    Vectors V3 {"Вектор3", 7, 3};
    
    vector <Vectors> v1v;
    vector <double> Vsize;
    
    v1v.push_back(V1);
    v1v.push_back(V2);
    v1v.push_back(V3);
    
    for (int i = 0; i < v1v.size(); i ++)
        {
        v1v[i].LengthCount();
        v1v[i].Vprint();
        }
    
    for (int i = 0; i < v1v.size(); i ++)
        {
        Vsize.push_back(v1v[i].Get_length());
        }
    double i = *max_element (Vsize.begin(), Vsize.end());
    cout << "Длина самого большого вектора = " << i <<"\n";
    }

void Vectors::Vprint ()
    {
    cout << "Вектор: " << name << " Икс: " << x << " игрик: " << y << " Длина: " << length <<"\n\n";
    }

void Vectors::LengthCount ()
    {
    length = sqrt (x * x + y * y);
    }
