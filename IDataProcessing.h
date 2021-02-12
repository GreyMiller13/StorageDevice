#pragma once

class IDataProcessing {
public:
	virtual void Reading() = 0;
	virtual void Recording(double file) = 0;
	virtual void Search() = 0;
	virtual void AmountOfInformation() = 0;
	virtual void Formatting() = 0;
};