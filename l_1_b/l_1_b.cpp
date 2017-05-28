#include "l_1_b.h"

const double negTwoPi = -6.283185307179586;
const double TwoPi = 6.283185307179586;

System::String^ stoS(std::basic_string<wchar_t> text)
{
	System::String^ tmp = L"";
	for (unsigned int i = 0;i < text.size();i++)
		tmp += text[i];
	return tmp;

}
std::basic_string<wchar_t> scissors(std::basic_string<wchar_t> text, unsigned int position, bool right)
{
	std::basic_string<wchar_t> half = L"";
	if (right)
	{
		for (unsigned int i = position + 1;i < text.size();i++)
			half.push_back(text[i]);
	}
	else
	{
		for (unsigned int i = 0;i < position;i++)
			half.push_back(text[i]);
	}
	return half;
}
std::basic_string<wchar_t> bracketFix(std::basic_string<wchar_t> text)
{
	std::basic_string<wchar_t> tmp = L"";
	for (unsigned int i = 1;i < text.size() - 1;i++)
	{
		tmp.push_back(text[i]);
	}
	return tmp;
}
double getVar(unsigned int number, double x,double y)
{
	switch (number)
	{
	case 0: return x + y;
	case 1: return x - y;
	case 2: return fmod(x, y);
	case 3: return x / y;
	case 4: return x * y;
	case 5: return pow(x, y);
	}
	return 0;
}
double getVar(unsigned int number, double x)
{
	switch (number)
	{
	case 6: return abs(x);
	case 7: return acosh(x);
	case 8: return acos(x);
	case 9: return asinh(x);
	case 10: return asin(x);
	case 11: return atanh(x);
	case 12: return atan(x);
	case 13: return cbrt(x);
	case 14: return cos(x);
	case 15: return x;
	case 16: return erfc(x);
	case 17: return erf(x);
	case 18: return exp2(x);
	case 19: return expm1(x);
	case 20: return exp(x);
	case 21: return x;
	case 22: return lgamma(x);
	case 23: return log(x);
	case 24: return log1p(x);
	case 25: return log2(x);
	case 26: return log10(x);
	case 27: return _j0(x);
	case 28: return _j1(x);
	case 29: return x*(-1);
	case 30: return sinh(x);
	case 31: return sin(x);
	case 32: return sqrt(x);
	case 33: return tanh(x);
	case 34: return tan(x);
	case 35: return tgamma(x);
	case 36: return _y0(x);
	case 37: return _y1(x);

	}
	return 0;
}
bool charCheck(System::String ^ txt, int position)
{
	bool r = true;
	System::String^ str = L"abcdefghijklmnopqrstuvwxyz0123456789,";
	for (int i = 0;i < str->Length;i++)
	{
		if (txt[position] == str[i])
		{
			r = false;
			break;
		}
	}
	return r;
}
bool charCheck(std::basic_string<wchar_t> text, unsigned int position)
{
	bool result = false;
	std::basic_string<wchar_t> tmp = L"abcdefghijklmnopqrstuvwxyz";
	for (unsigned int i = 0;i < tmp.size(); i++)
	{
		if (text[position] == tmp[i])
		{
			result = true;
			break;
		}
	}
	return result;
}
bool numberCheck(int position, System::String ^ txt)
{
	bool r = false;
	System::String^ tmp = L"0123456789";
	for (int i = 0;i < tmp->Length;i++)
	{
		if (txt[position] == tmp[i])
		{
			r = true;
			break;
		}
	}
	return r;
}
bool numberCheck(int position, std::basic_string<wchar_t> txt)
{
	bool r = false;
	std::basic_string<wchar_t> tmp = L"0123456789";
	for (unsigned int i = 0;i < tmp.size();i++)
	{
		if (txt[position] == tmp[i])
		{
			r = true;
			break;
		}
	}
	return r;
}
bool constRestriction(System::String^ txt, int position, bool left)
{
	bool result = true;
	System::String ^ symbolRestriction = L"ABSCONTEIXPLGMHQR";
	for (int i = 0; i < symbolRestriction->Length;i++)
	{
		{
			if (txt[position] == symbolRestriction[i])
			{
				result = false;
				break;
			}
			if (left&&txt[position] == L')')
			{
				result = false;
				break;
			}
			if (!left&&txt[position] == L'(')
			{
				result = false;
				break;
			}
		}
	}
	return result;
}
bool strComparison(std::basic_string<wchar_t> text, std::vector<wchar_t> functText)
{
	bool result = true;
	if (text.size() <= functText.size())
	{
		result = false;
	}
	else
	{
		for (unsigned int i = 0;i < functText.size();i++)
		{
			if (text[i] != functText[i])
			{
				result = false;
				break;
			}
		}
	}
	return result;
}
bool findSymbol(std::vector<variableType> & variable, std::basic_string<wchar_t> text)
{
	bool result = false;
	for (unsigned int i = 0;i < variable.size();i++)
	{
		if (text[0] == variable[i].name[0])
		{
			result = true;
			break;
		}
	}
	return result;
}
unsigned int returnSymbol(std::vector<variableType> & variable, std::basic_string<wchar_t> text)
{
	unsigned int result = 0;
	for (unsigned int i = 0;i < variable.size();i++)
	{
		if (text[0] == variable[i].name[0])
		{
			result = i;
			break;
		}
	}
	return result;
}
void PtoC(System::String^ &Ptext, System::String^ &Ctext)
{
	for (int i = 0;i < Ptext->Length;i++)
	{
		if (Ptext[i] == L'.')
			Ctext += L',';
		else
			Ctext += Ptext[i];
	}
}
void bracketCheck(bool back, System::String^ txt, bool &result, int position, int *&acp)
{
	if (!back)
	{
		int count = 0;
		for (int i = 0;i < txt->Length;i++)
		{
			if (txt[i] == L'(')
				count++;
			else if (txt[i] == L')')
				count--;
		}
		if (count != 0)
			result = false;
		for (int i = 0;i < txt->Length;i++)
		{
			if (!result)
				break;
			if (acp[i] == 1)
				continue;
			if (txt[i] == L'(')
				bracketCheck(true, txt, result, i, acp);

		}
	}
	else
	{
		acp[position] = 1;
		int count = 0;
		for (int i = position; i < txt->Length; i++)
		{
			if (txt[i] == L'(')
				count++;
			else if (txt[i] == L')')
				count--;
			if (count == 0 && txt[i] == L')' && i - position > 1)
			{
				acp[i] = 1;
				break;
			}
			else if (i == txt->Length - 1)
				result = false;
		}
	}
}
void operatorCheck(bool back, int position, System::String^ txt, std::vector<std::vector<wchar_t>> &knownSymbols, bool &result, int *&acp)
{
	if (!back)
	{
		for (int i = 0;i < txt->Length;i++)
		{
			if (!result)
				break;
			if (acp[i] == 1)
				continue;
			if (txt[i] == knownSymbols[0][0])
				operatorCheck(true, i, txt, knownSymbols, result,acp);
			else if (txt[i] == knownSymbols[1][0])
				operatorCheck(true, i, txt, knownSymbols, result,acp);
			else if (txt[i] == knownSymbols[2][0])
				operatorCheck(true, i, txt, knownSymbols, result,acp);
			else if (txt[i] == knownSymbols[3][0])
				operatorCheck(true, i, txt, knownSymbols, result,acp);
			else if (txt[i] == knownSymbols[4][0])
				operatorCheck(true, i, txt, knownSymbols, result,acp);
			else if (txt[i] == knownSymbols[5][0])
				operatorCheck(true, i, txt, knownSymbols, result,acp);
		}
	}
	else
	{
		acp[position] = 1;
		result = false;
		bool right = false;
		bool left = false;
		for (int i = 1, j = 1;((position + i) < txt->Length) && ((position - j) >= 0);i, j)
		{
			if (txt[position + i] == knownSymbols[0][0] || txt[position + i] == knownSymbols[1][0] || txt[position + i] == knownSymbols[2][0] || txt[position + i] == knownSymbols[3][0] || txt[position + i] == knownSymbols[4][0] || txt[position + i] == knownSymbols[5][0] || txt[position + i] == L',' || txt[position + i] == L')')
				break;
			if (txt[position - j] == knownSymbols[0][0] || txt[position - j] == knownSymbols[1][0] || txt[position - j] == knownSymbols[2][0] || txt[position - j] == knownSymbols[3][0] || txt[position - j] == knownSymbols[4][0] || txt[position - j] == knownSymbols[5][0] || txt[position - j] == L',' || txt[position - j] == L'(')
				break;
			if (txt[position + i] == L'('&&(position + i) < txt->Length)
				i++;
			else
				right = true;
			if (txt[position - j] == L')'&& (position - j) >= 0)
				j++;
			else
				left = true;
			if (left && right)
			{
				result = true;
				break;
			}
		}
	}
}
void strCheck(System::String^ txt, int &position, int number, std::vector<std::vector<wchar_t>> &knownSymbols, bool &result)
{
	bool r = true;
	if ((unsigned int)(txt->Length - (position + 1)) <= knownSymbols[number].size())
	{
		result = false;
		r = false;
	}
	else
	{
		for (unsigned int i = 0;i < knownSymbols[number].size();i++)
		{
			if (txt[position + i] != knownSymbols[number][i])
			{
				result = false;
				r = false;
				break;
			}
		}
			if (txt[position + knownSymbols[number].size()] == L'(' && r)
			{
				result = true;
				position = position + knownSymbols[number].size() - 1;
			}
	}
}
void functionCheck(bool back, int &position,int a, int b,System::String^ txt, std::vector<std::vector<wchar_t>> &knownSymbols, bool &result, int *&acp,int &intcount,int &dercount)
{
	if (!back)
	{
		for (int i = 0;i < txt->Length;i++)
		{
			if (!result)
				break;
			if (acp[i] == 1)
				continue;
			else if (txt[i] == L'A')
				functionCheck(true, i, 6, 12, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'C')
				functionCheck(true, i, 13, 14, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'D')
				functionCheck(true, i, 15, 15, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'E')
				functionCheck(true, i, 16, 20, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'I')
				functionCheck(true, i, 21, 21, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'L')
				functionCheck(true, i, 22, 26, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'J')
				functionCheck(true, i, 27, 28, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'N')
				functionCheck(true, i, 29, 29, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'S')
				functionCheck(true, i, 30, 32, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'T')
				functionCheck(true, i, 33, 35, txt, knownSymbols, result, acp,intcount,dercount);
			else if (txt[i] == L'Y')
				functionCheck(true, i, 36, 37, txt, knownSymbols, result, acp,intcount,dercount);
			else
			{
				System::String ^ tmp = "BOMXPGHQRFZ";
				for (int j = 0;j < tmp->Length;j++)
				{
					if (txt[i] == tmp[j])
					{
						result = false;
						break;
					}
				}
			}

		}
	}
	else
	{
		result = false;
		int l = position;
		for (int j = a;j <= b;j++)
		{
			if (result == true)
				break;
			else 
				strCheck(txt, position, j, knownSymbols, result);
		}
		if (result == true)
		{
			if (a == 15)
			{
				dercount++;
			}
			if (a == 21)
			{
				intcount++;
			}
			for (int i = l;l < position;l++)
				acp[i] = 1;
		}
	}
}
void varCheck(bool back, int position, System::String ^ txt, bool &result, int *&acp)
{
	if (!back)
	{
		System::String^ str = L"abcdefghijklmnopqrstuvwxyz";
		for (int i = 0;i < txt->Length;i++)
		{
			if (!result)
			{
				break;
			}
			if (acp[i] == 1)
			{
				continue;
			}
			for (int j = 0;j < str->Length;j++)
			{
				if (txt[i] == str[j])
				{
					varCheck(true, i, txt, result, acp);
					break;
				}
			}

		}
	}
	else
	{
		result = false;
		acp[position] = 1;
		bool right = false;
		bool left = false;
		if (position == 0)
			left = true;
		else if (txt[position - 1] == L'(')
			left = true;
		else if (charCheck(txt, position - 1) && txt[position - 1] != L')')
			left = true;
		if (position == (txt->Length - 1))
			right = true;
		else if (txt[position + 1] == L')')
			right = true;
		else if (charCheck(txt, position + 1) && txt[position + 1] != L'(')
			right = true;
		if (left&&right)
			result = true;
	}
}
void typeChange(areaType &type, int number, unsigned int index)
{
	switch (number)
	{
	case 0: type.newArea = true; break;
	case 1: type.operation = true; break;
	case 2: type.function = true; break;
	case 3: type.variable = true; break;
	case 4: type.basicVariable = true; break;
	case 5: type.moreVariable = true; break;
	case 6: type.constVariable = true; break;
	}
	type.typeIndex = index;
}
void typeNULL(areaType &type)
{
	type.newArea = false;
	type.operation = false;
	type.function = false;
	type.variable = false;
	type.basicVariable = false;
	type.moreVariable = false;
	type.constVariable = false;

}
void constCheck(bool back, int &position, System::String ^ txt, bool &result, int *&acp)
{
	if (!back)
	{
		for (int i = 0;i < txt->Length;i++)
		{
			if (!result)
				break;
			if (acp[i] == 1)
				continue;
			else if (numberCheck(i, txt))
				constCheck(true, i, txt, result, acp);
		}
	}
	else
	{
		acp[position] = 1;
		result = false;
		bool left = false;
		bool right = false;
		if (position == 0 && position == (txt->Length - 1))
		{
			left = true;
			right = true;
		}
		if (!left && position > 0)
		{
			if (constRestriction(txt, position - 1, true))
				left = true;
		}
		else
			left = true;
		if (!right && position < (txt->Length - 1))
		{
			if (txt[position] == L'0' && constRestriction(txt, (position + 1), false) && !numberCheck(position + 1, txt) && txt[position + 1] != L',')
				right = true;
			else if (txt[position] == L'0' && txt[position + 1] != L',')
				right = false;
			else
			{
				int count = 0;
				for (int i = position;i < txt->Length;i++)
				{
					count++;
					if (count <= 14)
					{
						if (numberCheck(i, txt))
							acp[i] = 1;
						else if (txt[i] == L',')
							continue;
						else if (constRestriction(txt, i, false))
						{
							right = true;
							break;
						}
						else
							break;
						if (i == (txt->Length - 1))
							right = true;
					}
					else
					{
						break;
					}
				}
				position = position + count - 1;
			}

		}
		else
			right = true;
		if (left&&right)
			result = true;
	}
}
void commaCheck(bool back, System::String^ txt, int position, bool &result, int *&acp)
{
	if (!back)
	{
		for (int i = 0;i < txt->Length;i++)
		{
			if (!result)
				break;
			else if (acp[i] == 1)
				continue;
			else if (txt[i] == L',')
				commaCheck(true, txt, i, result, acp);
		}
	}
	else
	{
		acp[position] = 1;
		bool left = false;
		bool right = false;
		if (position == 0 || position == (txt->Length - 1))
			result = false;
		else if (!(numberCheck(position - 1, txt)) || !(numberCheck(position + 1, txt)))
			result = false;
		else
		{
			for (int i = 1, j = 1; ((position + i) < txt->Length) && ((position - j) >= 0);i, j)
			{
				if ((position + i) > (txt->Length - 1) && (position - j) < 0)
					break;
				if (txt[position + i] == L',' || txt[position - j] == L',')
				{
					result = false;
					break;
				}
				if (!(numberCheck(position + i, txt)))
					right = true;
				else if ((position + i) < txt->Length)
					i++;
				if (!(numberCheck(position - j, txt)))
					left = true;
				else if ((position - j) >= 0)
					j++;
				if (right&&left)
					break;
			}
		}
	}
}
bool controlText(System::String ^ txt, std::vector<std::vector<wchar_t>> &knownSymbols)
{
	int pos;
	bool result = true;
	if (txt->Length == 0)
	{
		result = false;
	}
	int *acp = new int[txt->Length];
	for (int i = 0;i < txt->Length;i++)
		acp[i] = 0;
	if (result)
	{
		System::String^ permissibleSymbols = L"1234567890ABCDEFGHIJKLMNOPQRSTUWXYZabcdefghijklmnopqrstuvwxyz(),*/%^+-";
		for (int i = 0;i < txt->Length;i++)
		{
			for (int j = 0;j < permissibleSymbols->Length;j++)
			{
				if (txt[i] == permissibleSymbols[j])
					break;
				else if (j == (permissibleSymbols->Length - 1))
					result = false;
			}
			if (result == false)
				break;
		}
		if (result)
			bracketCheck(false, txt, result, 0, acp);
			if (result)
				operatorCheck(false, 0, txt, knownSymbols, result, acp);
			if (result)
			{
				int intcount = 0;
				int dercount = 0;
				functionCheck(false, pos, 0, 0, txt, knownSymbols, result, acp,intcount, dercount);
			}
			if (result)
				commaCheck(false, txt, 0, result, acp);
			if (result)
				constCheck(false, pos, txt, result, acp);
			if (result)
				varCheck(false, 0, txt, result, acp);
	}
	delete[] acp;
	return result;
}
area::area(std::vector<std::vector<wchar_t>> &kS) : knownSymbols(kS)
{
	parent = NULL;
	descendants.clear();
	typeNULL(thisType);
	left = NULL;
	right = NULL;
	text = L"";
	value = 0;
	step = 0;
	der = false;
	integ = false;
}
area::~area()
{

}
void area::areaAssembly(area *p, std::basic_string<wchar_t> txt, bool result)
{
	if (txt.size() == 0)
		result = true;
	if (!result)
	{
		parent = p;
		text = txt;
		for (unsigned int i = 0; i < 6;i++)
		{
			if (result)
				break;
			this->operatorAssembly(result, i);
		}
		for (unsigned int i = 6;i < 38; i++)
		{
			if (result)
				break;
			this->functionAssembly(result, i);
		}
		this->constAssembly(result);
		this->variableAssembly(result);
		this->newAreaAssembly(result);
	}
}
void area::operatorAssembly(bool &result, unsigned int position)
{
	if (!result)
	{
		int count = 0;
		for (unsigned int i = 0;i < text.size();i++)
		{
			if (text[i] == L'(')
				count++;
			else if (text[i] == L')')
				count--;
			if (text[i] == knownSymbols[position][0] && count == 0)
			{
				typeChange(thisType, 1, position);
				left = new area(knownSymbols);
				left->areaAssembly(this, scissors(text, i, false), false);
				right = new area(knownSymbols);
				right->areaAssembly(this, scissors(text, i, true), false);
				result = true;
				break;
			}
		}
	}
}
void area::functionAssembly(bool &result, unsigned int position)
{
	if (!result)
	{
		int count = 0;
		for (unsigned int i = 0;i < text.size();i++)
		{
			if (text[i] == L'(')
				count++;
			else if (text[i] == L')')
				count--;
			if (text[i] == knownSymbols[position][0] && count == 0)
			{
				if (strComparison(text, knownSymbols[position]))
				{
					if (position == 15)
						der = true;
					if (position == 21)
						integ = true;
					typeChange(thisType, 2, position);
					left = new area(knownSymbols);
					left->areaAssembly(this, scissors(text, i + knownSymbols[position].size() - 1, true), false);
					right = NULL;
					result = true;
					break;
				}
			}
		}
	}
}
void area::constAssembly(bool &result)
{
	if (!result)
	{
		int count = 0;
		for (unsigned int i = 0;i < text.size();i++)
		{
			if (text[i] == L'(')
				count++;
			else if (text[i] == L')')
				count--;
			if (numberCheck(i, text) && count == 0)
			{
				typeChange(thisType, 6, 0);
				left = NULL;
				value = System::Convert::ToDouble(stoS(text));
				right = NULL;
				result = true;
				break;
			}
		}
	}
}
void area::variableAssembly(bool &result)
{
	if (!result)
	{
		int count = 0;
		for (unsigned int i = 0;i < text.size();i++)
		{
			if (text[i] == L'(')
				count++;
			else if (text[i] == L')')
				count--;
			if (charCheck(text, i) && count == 0)
			{
				typeChange(thisType, 3, 0);
				left = NULL;
				right = NULL;
				result = true;
				break;
			}
		}
	}
}
void area::newAreaAssembly(bool &result)
{
	if (!result)
	{
		int count = 0;
		for (unsigned int i = 0;i < text.size();i++)
		{
			if (text[i] == L'(')
			{
				typeChange(thisType, 0, 0);
				left = new area(knownSymbols);
				left->areaAssembly(this, bracketFix(text), false);
				right = NULL;
				result = true;
				break;
			}
		}
	}
}
void area::setValue(double var)
{
	value = var;
}
void area::getVariables(std::vector<variableType> &variables)
{
	if (thisType.variable)
	{
		if (!findSymbol(variables, text))
		{
			variableType temp;
			temp.name = text;
			temp.basicVariable = thisType.basicVariable;
			temp.moreVariable = thisType.moreVariable;
			temp.constVariable = thisType.constVariable;
			temp.value = value;
			temp.step = step;
			variables.push_back(temp);
		}
	}
	else
	{
		if (left)
			left->getVariables(variables);
		if (right)
			right->getVariables(variables);
	}
}
void area::setVariables(std::vector<variableType> &variables)
{
	if (thisType.variable)
	{
		int i = returnSymbol(variables, text);
		text = variables[i].name;
		thisType.basicVariable = variables[i].basicVariable;
		thisType.moreVariable = variables[i].moreVariable;
		thisType.constVariable = variables[i].constVariable;
		value = variables[i].value;
		step = variables[i].step;
		
	}
	else
	{
		if (left)
			left->setVariables(variables);
		if (right)
			right->setVariables(variables);
	}
}
area * area::getLeft()
{
	return left;
}
area * area::getRight()
{
	return right;
}
double area::getValue(double iter, bool d, double a, double b, double s, bool i)
{
	double result = 0;
	if (thisType.operation)
		result = getVar(thisType.typeIndex, left->getValue(iter,d,a,b,s,i), right->getValue(iter,d,a,b,s,i));
	else if (thisType.function)
	{
		if (der)
		{
			result = ((left->getValue(iter,der, a, b,s + 0.001,i) - left->getValue(iter,der, a, b,s - 0.001,i)) / (2 * 0.001));
		}
		if (integ && a == 0 && b == 0)
		{
			double ax = 1;
			double bx = 0;
			result = ax / bx;
		}
		else if (integ)
		{
			int count = 0;
			double Y1 = 1;
			double Y2 = 0;
			double he = 0;
			double N = abs(b - a);
				while ((abs(Y1 - Y2)) > 0.001)
				{
					if (count > 1000)
						break;
					count++;
					he = (b - a) / N;
					Y1 = 0;
					for (double t = a, j = 0;t <= b;t += he, j++)
						Y1 += left->getValue(j, d, a, b,t,integ);
					Y1 = Y1*he;
					if (Y1 == 0)
					{
						break;
					}
					N += 2;
					he = (b - a) / N;
					Y2 = 0;
					for (double t = a, j = 0;t <= b;t += he, j++)
						Y2 += left->getValue(j, d, a, b,t,integ);
					Y2 = Y2*he;
				}
				result = Y2;
		}
		if(!der&&!integ)
		{
			result = getVar(thisType.typeIndex, left->getValue(iter,d,a,b,s,i));
		}
	}
	else if (thisType.constVariable)
		result = value;
	else if (thisType.newArea)
		result = left->getValue(iter,d,a,b,s,i);
	else if (thisType.basicVariable || thisType.moreVariable)
	{
		if ((i||d) && thisType.basicVariable)
			result = s;
		else
			result = value + step*iter;
	}
	return result;
}
void area::clear()
{
	if (left)
		left->clear();
	if (right)
		right->clear();
	delete this;
}
void fill(std::vector<std::vector<wchar_t>> &knownSymbols,std::basic_string<wchar_t> symbols,int position)
{
	std::vector<wchar_t> tmp;
	for (unsigned int i = 0;i < symbols.size();i++)
		tmp.push_back(symbols[i]);
	knownSymbols.push_back(tmp);
	
}
parser::parser()
{
	goodText = false;
	root = NULL;
	fill(knownSymbols, L"+", 0);
	fill(knownSymbols, L"-", 1);
	fill(knownSymbols, L"%", 2);
	fill(knownSymbols, L"/", 3);
	fill(knownSymbols, L"*", 4);
	fill(knownSymbols, L"^", 5);
	fill(knownSymbols, L"ABS", 6);
	fill(knownSymbols, L"ACOSH", 7);
	fill(knownSymbols, L"ACOS", 8);
	fill(knownSymbols, L"ASINH", 9);
	fill(knownSymbols, L"ASIN", 10);
	fill(knownSymbols, L"ATANH", 11);
	fill(knownSymbols, L"ATAN", 12);
	fill(knownSymbols, L"CBRT", 13);
	fill(knownSymbols, L"COS", 14);
	fill(knownSymbols, L"DER", 15);
	fill(knownSymbols, L"ERFC", 16);
	fill(knownSymbols, L"ERF", 17);
	fill(knownSymbols, L"EXPS", 18);
	fill(knownSymbols, L"EXPMF", 19);
	fill(knownSymbols, L"EXP", 20);
	fill(knownSymbols, L"INT", 21);
	fill(knownSymbols, L"LGAM", 22);
	fill(knownSymbols, L"LOGN", 23);
	fill(knownSymbols, L"LOGNF", 24);
	fill(knownSymbols, L"LOGS", 25);
	fill(knownSymbols, L"LOGT", 26);
	fill(knownSymbols, L"JZ", 27);
	fill(knownSymbols, L"JF", 28);
	fill(knownSymbols, L"NEG", 29);
	fill(knownSymbols, L"SINH", 30);
	fill(knownSymbols, L"SIN", 31);
	fill(knownSymbols, L"SQRT", 32);
	fill(knownSymbols, L"TANH", 33);
	fill(knownSymbols, L"TAN", 34);
	fill(knownSymbols, L"TGAM", 35);
	fill(knownSymbols, L"YZ", 36);
	fill(knownSymbols, L"YF", 37);
	build = false;
}
parser::~parser()
{
	if (build)
	{
		root->clear();
	}
}
bool parser::checkText()
{
	return goodText;
}
void parser::operator=(System::String^ txt)
{
	text = L"";
	System::String^ checkedText = "";
	PtoC(txt, checkedText);
	goodText = controlText(checkedText,knownSymbols);
	if (goodText)
	{
		for (int i = 0;i < checkedText->Length;i++)
		{
			if (txt[i] == L'.')
				text.push_back(L',');
			else
			    text.push_back(txt[i]);
		}
	}
}
bool parser::action()
{
	bool result = false;
	if (goodText&&!build)
	{
		root = new area(knownSymbols);
		root->areaAssembly(NULL, text,false);
		result = true;
		build = true;
	}
	return result;
}
double parser::run(double iter,double a, double  b,double s)
{
	double result = 0;
	if (root)
	{
		result = root->getValue(iter,0,a,b,s,0);
	}
	return result;
}
void parser::findVariables()
{
	variables.clear();
	if (root)
	{
		root->getVariables(variables);
	}
}
System::String^ parser::showVariable(unsigned int i)
{
	System::String^ tmp = L"";
	tmp += variables[i].name[0];
	return tmp;
}
variableType parser::showVariableValue(unsigned int index)
{
	variableType tmp;
	tmp = variables[index];
	return tmp;
}
unsigned int parser::numberVariables()
{
	return variables.size();
}
void parser::setVariable(variableType varType, unsigned int position)
{
			variables[position].basicVariable = varType.basicVariable ;
			variables[position].moreVariable = varType.moreVariable ;
			variables[position].constVariable = varType.constVariable ;
			variables[position].value = varType.value ;
			variables[position].step = varType.step; ;
}
void parser::setVariables()
{
	root->setVariables(variables);
}
void parser::clear()
{
	if (build)
	{
		variables.clear();
		root->clear();
	}
	build = false;
}

std::complex<double> discrete_fourier_transform(std::vector< std::complex<double> > &values, unsigned int j)
{
	std::complex<double> result = std::complex<float>(0, 0);
	unsigned int N = values.size();
	for (unsigned int i = 0; i < N; i++)
		result += values[i] * exp(std::complex<double>(0, (j * i * negTwoPi) / N));
	return result;
}
std::vector< std::complex<double> > discrete_fourier_transform(std::vector< std::complex<double> > &values)
{
	std::vector< std::complex<double> > result;
	unsigned int N = values.size();
	for (unsigned int i = 0; i < N; i++)
		result.push_back(discrete_fourier_transform(values, i));
	return result;
}
std::complex<double> inverse_fourier_transform(std::vector< std::complex<double> > &values, unsigned int j)
{
	std::complex<double> result = std::complex<float>(0, 0);
	unsigned int N = values.size();
	std::complex<double> cN = N;
	for (unsigned int i = 0; i < N; i++)
		result += values[i] * exp(std::complex<double>(0, (j * i * TwoPi) / N));
	return result / cN;
}
std::vector< std::complex<double> > inverse_fourier_transform(std::vector< std::complex<double> > &values)
{
	std::vector< std::complex<double> > result;
	unsigned int N = values.size();
	for (unsigned int i = 0; i < N; i++)
		result.push_back(inverse_fourier_transform(values, i));
	return result;
}
double mod(std::complex<double> r)
{
	return sqrt(pow(real(r), 2) + pow(imag(r), 2));
}
std::vector<double> Bartlet_window(std::vector<double> n)
{
	for (unsigned int i = 0;i < n.size()-1;i++)
		n[i] = 1 - abs((2 * n[i] / (n.size() - 1)) - 1);
	return n;
}
std::vector<double> Hann_window(std::vector<double> n)
{
	for (unsigned int i = 0;i < n.size() - 1;i++)
		n[i] = 0.5 - (0.5 * cos((TwoPi * n[i]) / (n.size() - 1)));
	return n;
}
std::vector<double> Hamming_window(std::vector<double> n)
{
	for (unsigned int i = 0;i < n.size() - 1;i++)
		n[i] = 0.54 - 0.46 * cos(TwoPi * n[i] / (n.size() - 1));
	return n;
}
double Ar(double n, unsigned int size)
{
	for (unsigned int i = 0;i < 10;i++)
		n += 0.1 * cos(TwoPi*n*i / (size - 0.1));
	return n;
}
std::vector<double> WeightCos_window(std::vector<double> n)
{
	for (unsigned int i = 0;i < n.size() - 1;i++)
		n[i] = Ar(n[i], n.size());
	return n;
}
std::vector<double> BlackMan_window(std::vector<double> n)
{
	for (unsigned int i = 0;i < n.size() - 1;i++)
		n[i] = 0.42 - 0.5 * cos(TwoPi*n[i] / (n.size() - 1)) + 0.08 * cos(2*TwoPi*n[i] / (n.size() - 1));
	return n;
}
std::vector<double> Natoll_window(std::vector<double> n)
{
	for (unsigned int i = 0;i < n.size() - 1;i++)
		n[i] = 0.3635819 - 0.4891775 * cos(TwoPi*n[i] / (n.size() - 1)) + 0.1365995 * cos(2 * TwoPi*n[i] / (n.size() - 1)) - 0.0106411 * cos(3 * TwoPi*n[i] / (n.size() - 1));
	return n;
}
std::vector<double> Gaus_window(std::vector<double> n)
{
	double a = 5;
	for (unsigned int i = 0;i < n.size() - 1;i++)
		n[i] = exp(-0.5 * pow(((2 * n[i] * a) / (n.size() - 1)) - a ,2));
	return n;
}
double fact(int N)
{
	if (N < 0) 
		return 0; 
	if (N == 0) 
		return 1; 
	else 
		return N * fact(N - 1); 
}
double I0(double x)
{
	double result = 0;
	for (unsigned int k = 0; k < 32;k++)
		result += pow(pow(x / 2, k) / fact(k), 2);
	return result;
}
std::vector<double> KaizerBessele_window(std::vector<double> n)
{
	double a = 97;
	for (unsigned int i = 0;i < n.size();i++)
		n[i] = I0(3.1415926535 * a * pow(1 - pow((n[i] - n.size() / 2) / n.size() / 2, 2), 0.5)) / I0(3.1415926535 * a);
	return n;
}
