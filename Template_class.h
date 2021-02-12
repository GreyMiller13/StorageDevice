#pragma once

template <class T>
class StorageDevice {
private:
	T totalAmountOfInfomation = 0;
	T freeAmountOfInformation = 0;
	T occupiedAmountOfInformation = 0;
public:
	StorageDevice() {}
	StorageDevice(T totalAmountOfInformation, T occupiedAmountOfInformation) {
		try	{
			if (totalAmountOfInformation < 0) {
				throw -1;
			} else if (occupiedAmountOfInformation > totalAmountOfInformation) {
				throw -2;
			} else if (occupiedAmountOfInformation < 0) {
				throw -3;
			} else {
				this->totalAmountOfInfomation = totalAmountOfInformation;
				this->occupiedAmountOfInformation = occupiedAmountOfInformation;
				freeAmountOfInformation = totalAmountOfInfomation - occupiedAmountOfInformation;
			}
		} catch (int) {
			cout << "Некорректно задан объем информации" << endl;
		}
	}

	void SetTotalAmountOfInformation(T totalAmountOfInformation) {
		try	{
			totalAmountOfInfomation < 0 ? throw - 1 : this->totalAmountOfInfomation = totalAmountOfInformation;
		} catch (int) {
			cout << "Некорректно задан объем информации" << endl;
		}
	}

	void SetOccupiedAmountOfInformation(T occupiedAmountOfInformation) {
		try	{
			if (occupiedAmountOfInformation > totalAmountOfInfomation) {
				throw -1;
			} else if (occupiedAmountOfInformation < 0) {
				throw -2;
			} else {
				this->occupiedAmountOfInformation = occupiedAmountOfInformation;
			}
		} catch (int) {
			cout << "Некорректно задан объем информации" << endl;
		}
	}

	void SetFreeAmountOfInformation() { 
		this->freeAmountOfInformation = totalAmountOfInfomation - occupiedAmountOfInformation; 
	}

	T GetTotalAmountOfInformation() { return totalAmountOfInfomation; }
	T GetOccupiedAmountOfInformation() { return occupiedAmountOfInformation; }
	T GetFreeAmountOfInformation() { return freeAmountOfInformation; }

	void Reading();
	void Recording(T file);
	void Search();
	void AmountOfInformation();
	void Formatting();
};

template <class T>
void StorageDevice<T>::Reading() {
	(occupiedAmountOfInformation == 0) ? cout << "Носитель не содержит информации" << endl :
										 cout << "Вывелась информация содержащаяся на носителе" << endl;
}

template <class T>
void StorageDevice<T>::Recording(T file) {
	(freeAmountOfInformation - file >= 0) ? cout << "Записана информация на носитель" << endl :
											cout << "Недостаточно свободного места для записи" << endl;
}

template <class T>
void StorageDevice<T>::Search() {
	cout << "Вывод результата поиска" << endl;
}

template <class T>
void StorageDevice<T>::AmountOfInformation() {
	cout << "Общий объем накопителя информации:\t" << totalAmountOfInfomation << endl
		 << "Занято информацией:\t\t\t" << occupiedAmountOfInformation << endl
		 << "Свободно для записи информации:\t\t" << freeAmountOfInformation << endl;
}

template <class T>
void StorageDevice<T>::Formatting() {
	occupiedAmountOfInformation = 0;
	freeAmountOfInformation = totalAmountOfInfomation;
	cout << "Носитель успешно отформатирован" << endl;
}