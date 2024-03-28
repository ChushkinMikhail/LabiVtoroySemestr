//
//  main.cpp
//  Sem2Laba3
//
//  Created by Михаил on 27.03.2024.
//

#include <iostream>

using namespace std;

class Rectangle 
    {
protected:
    double A, B;

public:
    Rectangle (double a, double b) : A(a), B (b) {}

    double Area()
        {
        return A*B;
        }

    virtual void print()
        {
        cout << endl;
        cout << "Side a: " << A << "\n";
        cout << "Side b: " << B << "\n";
        cout << "Area: " << Area() << "\n";
        }
    };

class PryamoPiped: public Rectangle
    {
    protected:
    double H;

    public:
        
    PryamoPiped (double a, double b, double h) : Rectangle (a, b), H(h) {}

    double Vol()
        {
        return H * Area ();
        }

    void print() override
        {
        Rectangle::print();
        cout << "Hieght: " << H << "\n";
        cout << "Vol: " << Vol () << "\n";
        }
    };

int main() {
    Rectangle Rec (5, 7);
    PryamoPiped Pip (1, 6, 10);

    Rec.print();
    cout << "\n";
    Pip.print();
    cout << "\n";

    Rectangle* RecP = new Rectangle (4, 8);
    PryamoPiped* PipP = new PryamoPiped(6, 9, 8);

    RecP->print();
    cout << "\n";
    PipP->print();
    cout << "\n";
    return 0;
}
