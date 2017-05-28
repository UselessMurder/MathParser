#include <math.h>
#include <vector>
#include <process.h>
#include <complex>

std::complex<double> discrete_fourier_transform(std::vector< std::complex<double> > &values, unsigned int j);
std::vector< std::complex<double> > discrete_fourier_transform(std::vector< std::complex<double> > &values);
std::complex<double> inverse_fourier_transform(std::vector< std::complex<double> > &values, unsigned int j);
std::vector< std::complex<double> > inverse_fourier_transform(std::vector< std::complex<double> > &values);
double mod(std::complex<double> r);
std::vector<double> Bartlet_window(std::vector<double> n);
std::vector<double> Hann_window(std::vector<double> n);
std::vector<double> Hamming_window(std::vector<double> n);
std::vector<double> WeightCos_window(std::vector<double> n);
std::vector<double> BlackMan_window(std::vector<double> n);
std::vector<double> Natoll_window(std::vector<double> n);
std::vector<double> Gaus_window(std::vector<double> n);
std::vector<double> KaizerBessele_window(std::vector<double> n);

struct areaType {
	bool newArea;
	bool operation;
	bool function;
	bool variable;
	bool basicVariable;
	bool moreVariable;
	bool constVariable;
	unsigned int typeIndex;
};

struct variableType {
	std::basic_string<wchar_t> name;
	bool basicVariable;
	bool moreVariable;
	bool constVariable;
	double value;
	double step;
};

class area {
private:
	area *parent;
	area* left;
	area* right;
	std::vector<area *> descendants;
	std::vector<std::vector<wchar_t>> &knownSymbols;
	areaType thisType;
	std::basic_string<wchar_t> text;
	std::vector<int> acp;
	double value;
	double step;
	bool der;
	bool integ;
public:
	area(std::vector<std::vector<wchar_t>> &kS);
	~area();
	void areaAssembly(area *p, std::basic_string<wchar_t> txt, bool result);
	void operatorAssembly (bool &result,unsigned int position);
	void functionAssembly (bool &result, unsigned int position);
	void constAssembly (bool &result);
	void variableAssembly(bool &result);
	void newAreaAssembly(bool &result);
	void getVariables(std::vector<variableType> &variables);
	void setVariables(std::vector<variableType> &variables);
	area * getLeft();
	area * getRight();
	void setValue(double var);
	double getValue(double iter,bool d,double a,double b,double s,bool i);
	void clear();
};

class parser {
private:
	std::basic_string<wchar_t> text;
	std::vector<std::vector<wchar_t>> knownSymbols;
	bool goodText;
	area *root;
	std::vector <variableType> variables;
	bool build;
public:
	parser();
	~parser();
	bool checkText();
	void operator=(System::String^ txt);
	bool action();
	double run(double iter,double a, double  b,double s);
	void findVariables();
	System::String^ showVariable(unsigned int i);
	variableType parser::showVariableValue(unsigned int index);
	unsigned int numberVariables();
	void setVariable(variableType varType, unsigned int position);
	void setVariables();
	void clear();
};