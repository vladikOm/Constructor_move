#include"String.h"
#include<iostream>

char ConvertDigitToChar(int digit);


String CreateStringWithNumbers(const int array[], size_t size);

using namespace std; 
int main()
{
	

	String str1{ "I have to create program" };

	String str2{ str1 }; 

	String str3; 

	const char* STR = "SOME C-interesting text";
	String str4{ STR };           

    const size_t size = 5;
	char someLetters[size] = { 'A','B','C','D','E' };
	String str5 { someLetters, size};


	cout << "\t  We get the created objects \n";      
	cout << "str1=[" << str1.GetString() << "]\n";
	cout << "str2=[" << str2.GetString() << "]\n";
	cout << "str3=[" << str3.GetString() << "]\n";
	cout << "str4=[" << str4.GetString() << "]\n";
	cout << "str5=[" << str5.GetString() << "]\n";

	cout  << "\t  We get the  length created objects \n";

	cout << "str1 lengh=[" << str1.GetLength() << "]\n";
	cout << "str2 lengh=[" << str2.GetLength() << "]\n";
	cout << "str3 lengh=[" << str3.GetLength() << "]\n";
	cout << "str4 lengh=[" << str4.GetLength() << "]\n";
	cout << "str5 lengh=[" << str5.GetLength() << "]\n";

	cout << "\t  We checking object emply Yes or No \n";

	cout << "Is str1 emply ? = " << (str1.IsEmply() ?"  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = " <<(str2.IsEmply() ?"  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = " << (str3.IsEmply() ? "  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = "<< (str4.IsEmply() ? "  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = "<< (str5.IsEmply() ? "  Yes  " : "  No  ") << endl;
	

	
	str3.SetString(STR); 
	cout << "str3=[" << str3.GetString() << "]\n";
	str3.SetString(someLetters, size); 
	cout << "str3=[" << str3.GetString() << "]\n";
	str3.SetString(str1);
	cout << "str3=[" << str3.GetString() << "]\n";


	int array[size] = { 1, 2, 3 }; 
	String str6  {  CreateStringWithNumbers ( array, size) };
	cout << "str6=[" << str6.GetString() << "]\n";
	return 0;
}

char ConvertDigitToChar(int digit)
{
	return digit>=0 && digit<= 9 ? digit+ '0'  :  '!';
}

String CreateStringWithNumbers(const int array[], size_t size) 
{
	if (array == nullptr || size == 0)
		return String();
	char* str = new char[size + 1]; 
	for (size_t i = 0; i<size; i++) 
	{
		 
		str[i] = ConvertDigitToChar(array[i]);
	}

	str[size] = '\0';
	String object{ str }; 
	delete[]str; 
	return object; 
}
