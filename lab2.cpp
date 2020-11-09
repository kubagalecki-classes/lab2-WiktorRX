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

    int  getDlugosc() { return dlugosc; };
    void print()
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
            else if (x > dlugosc) {
                dlugosc = x;
            }
        }
        else {
            cout << "dupa\n";
            cout << "\n stworzono temp";
            for (int i = 0; i < dlugosc; i++) {
                temp[i] = A[i];
            }

            delete[] A;

            cout << "\n usunieto stare A fff";
            cout << "\n stary A";

            // A = new double[x];

            cout << "\n nwy A 1";
            cout << "\n nwy A 2";
            for (int i = 0; i < dlugosc; i++) {
                A[i] = temp[i];
                cout << "bla";
            }
            for (int i = dlugosc; i < x; dlugosc++) {
                A[i] = 0.;
            }
            delete[] temp;
            dlugosc   = x;
            pojemnosc = x;
        }
    }
    double* A;

private:
    int     dlugosc;
    int     pojemnosc;
    double* temp;
};
int main()
{
    Wektor Jessica{4};
    Jessica.A[2] = 6969;
    cout << Jessica.A[2] << Jessica.A[3] << endl;
    cout << Jessica.getDlugosc() << endl;
    Jessica.print();
    Jessica.zmienDlugosc(3);
    Jessica.print();
    Jessica.zmienDlugosc(5);

    for (int i = 0; i < Jessica.getDlugosc(); i++) {
        cout << "bla";
        Jessica.A[i] = i;
    }
    Jessica.print();
    Jessica.zmienDlugosc(3);
    Jessica.print();
}