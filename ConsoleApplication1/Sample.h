#pragma once

//抽象クラス
class Sample {
public:
	//純粋仮想関数 pure virtual
	virtual int Add() const = 0;
	//この Add は派生クラス内にある
	//しかし、ここには無い
};
void Print_Result_Of_Addition(const Sample&);