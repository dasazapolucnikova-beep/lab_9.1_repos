#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../Project 9.1/var.h"
#include "../Project 9.1/var.cpp"
#include "../Project 9.1/dod.h"
#include "../Project 9.1/dod.cpp"
#include "../Project 9.1/sum.h"
#include "../Project 9.1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nsVar;
using namespace nsDod;
using namespace nsSum;

namespace UnitTest91
{
	TEST_CLASS(UnitTest91)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Задаємо вхідні дані для тестування (|x| < 1)
			x = 0.5;
			e = 0.0001;

			// Викликаємо функцію обчислення суми ряду
			sum();

			// Очікуване точне значення функції Arth(0.5)
			double expected = atanh(0.5);

			// Перевіряємо, чи збігається обчислена сума 's' із точним значенням з точністю 'e'
			Assert::AreEqual(expected, s, e);
		}
	};
}