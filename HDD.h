#pragma once
#include <iostream>
#include "IDataProcessing.h"

using namespace std;

class HDD : public IDataProcessing {
private:
	const double totalAmountOfinfomation = 1048576;
	double freeAmountOfInformation = 0;
	double occupiedAmountOfInformation = 0;
public:
	HDD() {}

	HDD(double occupiedAmountOfInformation) {
		try	{
			if (occupiedAmountOfInformation > totalAmountOfinfomation) {
				throw 2.0;
			} else if (occupiedAmountOfInformation < 0) {
				throw - 1;
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