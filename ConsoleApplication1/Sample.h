#pragma once

//���ۃN���X
class Sample {
public:
	//�������z�֐� pure virtual
	virtual int Add() const = 0;
	//���� Add �͔h���N���X���ɂ���
	//�������A�����ɂ͖���
};
void Print_Result_Of_Addition(const Sample&);