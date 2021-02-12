#pragma once
#include <iostream>
#include "IDataProcessing.h"

using namespace std;

class Floppy : public IDataProcessing {
private:
	const double totalAmountOfinfomation = 2.88;
	double freeAmountOfInformation = 0;
	double occupiedAmountOfInformation = 0;
public:

	Floppy() {}

	Floppy(double occupiedAmountOfInformation) {
		try	{
			if (occupiedAmountOfInformation > totalAmountOfinfomation) {
				throw 2.0;
			} else if (occupiedAmountOfInformation < 0) {
				throw -1;
			} else {
				this->occupiedAmountOfInformation = occupiedAmountOfInformation;
			}
		} catch (double) {
			cout << "�������� �� ����� ������� ������" << endl;
		} catch (int) {
			cout << "������������ ����� ������" << endl;
		}
	}

	void Reading() override { 
		(occupiedAmountOfInformation == 0) ? cout << "�������� �� �������� ����������" << endl :
											 cout << "�������� ���������� ������������ �� ��������" << endl;
	}
	
	void Recording(double file) override {
		(freeAmountOfInformation - file >= 0) ? cout << "�������� ���������� �� ��������" << endl :
												cout << "������������ ���������� ����� ��� ������" << endl;
	}
	
	void Search() override { cout << "����� ���������� ������" << endl; }
	
	void AmountOfInformation() override { 
		cout << "����� ����� ���������� ��������: " << totalAmountOfinfomation << endl;
		cout << "�������� ���������� ����� �� ��������: " << totalAmountOfinfomation - occupiedAmountOfInformation << endl;
	}
	
	void Formatting() override {
		occupiedAmountOfInformation = 0;
		freeAmountOfInformation = totalAmountOfinfomation;
		cout << "�������� ������� ��������������" << endl;
	}
};