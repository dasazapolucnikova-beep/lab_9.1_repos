#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    n = 0;
    a = x; // перший доданок ряду при n = 0
    s = a;

    do {
        n++;
        dod(); // обчислення чергового доданку
        s += a; // накопичення суми
    } while (fabs(a) > e);
}