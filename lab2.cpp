#include <iostream>
using namespace std;

class Wektor
{
public:
    Wektor(int n) : dlugosc{n}, pojemnosc{n}
    {
        A = new double[n];
        for (int i = 0; i < dlugosc; i++) {
            A[i] = 0.;
        }
    }

    int  getDlugosc() { return dlugosc; };
    void print()
    {
        cout << "[ ";
        for (int i = 0; i < dlugosc; i++) {
            cout << " " << A[i] << ",";
        }
        cout << "]" << endl;
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
            temp = new double[x];

            for (int i = 0; i < dlugosc; i++) {
                temp[i] = A[i];
            }

            delete[] A;

            A = new double[x];

            for (int i = 0; i < dlugosc; i++) {
                A[i] = temp[i];
            }

            for (int i = dlugosc; i < x; i++) {
                A[i] = 0.;
            }

            delete[] temp;

            dlugosc   = x;
            pojemnosc = x;
        }
    }

    double& operator[](int ind)
    {
        if (ind >= dlugosc)
            zmienDlugosc(ind + 1);
        return A[ind];
    }

private:
    int     dlugosc;
    int     pojemnosc;
    double* temp;
    double* A;
};
int main()
{
    Wektor Jessica{4};
    Jessica.print();
    Jessica.zmienDlugosc(3);
    Jessica.print();
    Jessica.zmienDlugosc(6);
    Jessica.print();
    Jessica.zmienDlugosc(3);
    Jessica.print();
    Jessica[2] = 42.;
    double& a  = Jessica[5];
    a++;
    Jessica.print();
    cout << a;
}