#include <iostream>
#include <iomanip>
#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main() {
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "eps = "; cin >> e;
    cout << endl;

    // Перевірка області збіжності ряду |x| < 1
    if (fabs(x_p) >= 1.0 || fabs(x_k) >= 1.0 || dx <= 0 || e <= 0) {
        cout << "Pomylka! Dlia Arth(x) neobkhidno |x| < 1, dx > 0, eps > 0." << endl;
        return 1;
    }

    // Заголовок та шапка таблиці
    cout << "                Tablytsia znachen funktsii Arth(x)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x"
        << " |" << setw(16) << "Arth(x)"
        << " |" << setw(16) << "Suma riadu"
        << " |" << setw(14) << "K-st dodankiv" << " |" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    x = x_p;
    // Додаємо 1e-12 до x_k для уникнення похибки округлення чисел з рухомою комою
    while (x <= x_k + 1e-12) {
        sum(); // виклик функції обчислення суми ряду

        cout << "|" << setw(10) << fixed << setprecision(4) << x
            << " |" << setw(16) << setprecision(6) << atanh(x)
            << " |" << setw(16) << setprecision(6) << s
            << " |" << setw(14) << (n + 1) << " |" << endl;

        x += dx;
    }
    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}