#include "dod.h"
#include "var.h"

using namespace nsVar;

void nsDod::dod() {
    // Домнoжуємо попередній доданок на коефіцієнт рекурентності: x^2 * (2n - 1) / (2n + 1)
    a *= (x * x * (2.0 * n - 1.0)) / (2.0 * n + 1.0);
}