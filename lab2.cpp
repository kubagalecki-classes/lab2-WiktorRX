#include <iostream>
using namespace std;

class Wektor
{
public:
    Wektor(int n)
    {
        dlugosc   = n;
        pojemnosc = n;
        A         = new double[n];
        for (int i = 0; i < dlugosc; i++) {
            A[i] = 0.;
        }
    }

    double* A;
    int     getDlugosc() { return dlugosc; };
    void    print()
    {
        cout << "[ ";
        int i = 0;
        do {
            cout << A[i] << ", ";
            i++;
        } while (i < dlugosc);
        cout << A[i] << "]" << endl;
    }

    void zmienDlugosc(int x)
    {
        if (x <= pojemnosc) {
            if (x < dlugosc)
                do {
                    dlugosc--;
                    A[dlugosc] = 0.;
                  } while (dlugosc > x);
            else if (x > dlugosc) {dlugosc = x;}
        }
        else
        {
          Wektor()
        }

        
    }

private:
    int dlugosc;
    int pojemnosc;
};

int main()
{
    Wektor Jessica{4};
    Jessica.A[2] = 5;
    cout << Jessica.A[2] << Jessica.A[3] << endl;
    cout << Jessica.getDlugosc() << endl;
    Jessica.print();
    Jessica.zmienDlugosc(3);
    Jessica.print();
    Jessica.zmienDlugosc(4);
    Jessica.print();
}