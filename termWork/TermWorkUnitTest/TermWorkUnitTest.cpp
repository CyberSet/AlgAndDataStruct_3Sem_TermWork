﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../termWork/postfix.h"
#include "../termWork/strl.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TermWorkUnitTest
{
	TEST_CLASS(TermWorkUnitTest)
	{
	public:
		strl infix;

		TEST_METHOD(СorrectTest1)
		{
			infix = ") 2 + 2";
			fstream f;
			Assert::IsFalse(infix.isCorrectInfix(f));
		}

		TEST_METHOD(СorrectTest2)
		{
			infix = "2+2";
			fstream f;
			Assert::IsFalse(infix.isCorrectInfix(f));
		}

		TEST_METHOD(СorrectTest3)
		{
			infix = "( ( 2 + 2 ) * 2 ) / 8";
			fstream f;
			Assert::IsTrue(infix.isCorrectInfix(f));
		}

		TEST_METHOD(ConversionTest1)
		{
			infix = "( ( 2 + 2 ) * 2 ) / 8";
			postfix pf(infix);
			Assert::IsTrue(pf.getStream() == "2 2 + 2 * 8 / ");
		}

		TEST_METHOD(ConversionTest2)
		{
			infix = "cos ( pi * 2 - ( 2 * pi ) )";
			postfix pf(infix);
			Assert::IsTrue(pf.getStream() == "pi 2 * 2 pi * - cos ");
		}

		TEST_METHOD(ConversionTest3)
		{
			infix = "10 + 3 * 5 / ( 16 - 4 )";
			postfix pf(infix);
			Assert::IsTrue(pf.getStream() == "10 3 5 * 16 4 - / + ");
		}

		TEST_METHOD(ConversionTest4)
		{
			infix = "5 * 3 ^ ( 4 - 2 )";
			postfix pf(infix);
			Assert::IsTrue(pf.getStream() == "5 3 4 2 - ^ * ");
		}

		TEST_METHOD(ConversionTest5)
		{
			infix = "( 2 + ( 3 + ( 4 + ( 5 + 6 * ( 7 + 8 ) ) ) ) )";
			postfix pf(infix);
			Assert::IsTrue(pf.getStream() == "2 3 4 5 6 7 8 + * + + + + ");
		}

		TEST_METHOD(CalculateTest1)
		{
			infix = "( 2 + ( 3 + ( 4 + ( 5 + 6 * ( 7 + 8 ) ) ) ) )";
			postfix pf(infix);
			Assert::IsTrue(pf.calculate() == (2 + (3 + (4 + (5 + 6 * (7 + 8))))));
		}

		TEST_METHOD(CalculateTest2)
		{
			infix = "cos ( pi * 2 - ( 2 * pi ) )";
			postfix pf(infix);
			Assert::IsTrue(pf.calculate() == cos(PI * 2 - (2 * PI)));
		}

		TEST_METHOD(CalculateTest3)
		{
			infix = "( 2 + 3 * ( 4 ^ cos ( pi / 4 ) ) )";
			postfix pf(infix);
			Assert::IsTrue(pf.calculate() == (2 + 3 * pow(4, cos(PI / 4))));
		}

		TEST_METHOD(CalculateTest4)
		{
			infix = "ln e";
			postfix pf(infix);
			Assert::IsTrue(pf.calculate() == log(E));
		}

		TEST_METHOD(CalculateTest5)
		{
			infix = "2382323.471247 * 35612731287312.415467126412";
			postfix pf(infix);
			Assert::IsTrue(pf.calculate() == 2382323.471247 * 35612731287312.415467126412);
		}

		TEST_METHOD(UnaryMinusCalculateTest1)
		{
			infix = "- ( 2 + 2 )";
			postfix pf(infix);
			Assert::IsTrue(pf.calculate() == -(2+2));
		}

		TEST_METHOD(UnaryMinusCalculateTest2)
		{
			infix = "tg ( - pi / 4 )";
			postfix pf(infix);
			Assert::IsTrue(pf.calculate() == tan(-PI/4));
		}

		TEST_METHOD(UnaryMinusCalculateTest3)
		{
			infix = "cos ( - ( pi / 4 ) + pi / 4 )";
			postfix pf(infix);
			Assert::IsTrue(pf.calculate() == cos(-(PI / 4) + PI / 4));
		}

		TEST_METHOD(UnaryMinusCalculateTest4)
		{
			infix = "2 / - ( 2 - 1 )";
			postfix pf(infix);
			Assert::IsTrue(pf.calculate() == 2 / -(2 - 1));
		}

		TEST_METHOD(isDigitTest1)
		{
			infix = "2";
			Assert::IsTrue(infix.isDigit());
		}

		TEST_METHOD(isDigitTest2)
		{
			infix = "-1";
			Assert::IsTrue(infix.isDigit());
		}

		TEST_METHOD(isDigitTest3)
		{
			infix = "-";
			Assert::IsFalse(infix.isDigit());
		}

		TEST_METHOD(isDigitTest4)
		{
			infix = ".0213123";
			Assert::IsFalse(infix.isDigit());
		}

		TEST_METHOD(isDigitTest5)
		{
			infix = "2.032363";
			Assert::IsTrue(infix.isDigit());
		}

		TEST_METHOD(isDigitTest6)
		{
			infix = "-2.3213713";
			Assert::IsTrue(infix.isDigit());
		}

		TEST_METHOD(isDigitTest7)
		{
			infix = "-2.3-213713";
			Assert::IsFalse(infix.isDigit());
		}

		TEST_METHOD(isDigitTest8)
		{
			infix = "-2.3.213713";
			Assert::IsFalse(infix.isDigit());
		}

		TEST_METHOD(isDigitTest9)
		{
			infix = "-.36712";
			Assert::IsFalse(infix.isDigit());
		}

		TEST_METHOD(isDigitTest10)
		{
			infix = "abrakadabra";
			Assert::IsFalse(infix.isDigit());
		}

		TEST_METHOD(isDigitTest11)
		{
			infix = "0.";
			Assert::IsTrue(infix.isDigit());
		}
	};
}
