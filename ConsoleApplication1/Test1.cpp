#include <stdio.h>
#include "Sample.h"
class Sample1 : public Sample {
public:
	int a;
	int b;
	int Add() const override
	{
		return a + b;
	}
};
class Sample2 : public Sample1 {
	//Sample2 は Sample1 から派生したクラス
public:
	int c; //Sample2 に固有
	int Add() const override
	{
		return a + b + c;
	}
};

int main()
{
	Sample1 x;
	x.a = 500;
	x.b = 300;
	Print_Result_Of_Addition(x);

	Sample2 y;
	y.a = 10;
	y.b = 20;
	y.c = 30;
	Print_Result_Of_Addition(y);
}
