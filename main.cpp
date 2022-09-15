#include"String.h"
#include<iostream>

char ConvertDigitToChar(int digit);//������� �������� ����� � ������


String CreateStringWithNumbers(const int array[], size_t size);//������� ������ ����� � ������� �������� ����� ����� � ���� ����� � �������� �����

using namespace std;//ϳ�������� ������ ���� std ��� ������������� ������� cout  
int main()
{
	

	String str1{ "I have to create program" }; //��������� 1- ��'��� �����, � � ��� �����������"String(const char* str)" ���������� ��� �����   

	String str2{ str1 }; //��������� 2 - ��'��� ����� ����������� ����������� ��ﳿ String(const String& other):String() 

	String str3; //��������� 3- ��'��� ����� ����������� ����������� �� �������������

	const char* STR = "SOME C-interesting text";//��������� ����� �� ���� ���� �
	String str4{ STR };//��������� 4- ��'��� �����, ���������� ����������� String(const char* str), ���� ������ ����� � ���� �                

    const size_t size = 5; //��������� ���������� ����� ��� ������� ������ ������
	char someLetters[size] = { 'A','B','C','D','E' };//��������� ����� ���� char ���������� ����
	String str5 { someLetters, size};//��������� 5- ��'��� �����, �������� ����������� String(const char array[], size_t size) �
	                                 //�������� ��� ����� � ��������� ����


	cout << "\t  We get the created objects \n";  //��� ������� ��'���� �������� ����� GetString()� ���� ����� �� �������� �� �� ���� ���������      
	cout << "str1=[" << str1.GetString() << "]\n";
	cout << "str2=[" << str2.GetString() << "]\n";
	cout << "str3=[" << str3.GetString() << "]\n";
	cout << "str4=[" << str4.GetString() << "]\n";
	cout << "str5=[" << str5.GetString() << "]\n";

	cout  << "\t  We get the  length created objects \n";//��� ������� ��'���� �������� ����� GetLength() � ���������  ������� �����

	cout << "str1 lengh=[" << str1.GetLength() << "]\n";
	cout << "str2 lengh=[" << str2.GetLength() << "]\n";
	cout << "str3 lengh=[" << str3.GetLength() << "]\n";
	cout << "str4 lengh=[" << str4.GetLength() << "]\n";
	cout << "str5 lengh=[" << str5.GetLength() << "]\n";

	cout << "\t  We checking object emply Yes or No \n";//��� ������� ��'���� �������� ����� IsEmply() � ��������� ����� ��� ������ "���" ��"Ͳ "

	cout << "Is str1 emply ? = " << (str1.IsEmply() ?"  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = " <<(str2.IsEmply() ?"  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = " << (str3.IsEmply() ? "  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = "<< (str4.IsEmply() ? "  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = "<< (str5.IsEmply() ? "  Yes  " : "  No  ") << endl;
	

	cout << "\n ";//��� �� �������������� ������ ������������ ��� �������� ��� ����� �3 ������� �� ��� ������� ������ SetString 
	             //������� ��������� �������� �������� �� ���� � ���'��
	str3.SetString(STR); //�������� � ������ ����� �� �3 ����� str4
	cout << "str3=[" << str3.GetString() << "]\n"; //�������� ����� � �������� ����
	str3.SetString(someLetters, size); // �������� � ��� ��  ����� �� �3  str5
	cout << "str3=[" << str3.GetString() << "]\n";//�������� ����� � �������� ����
	str3.SetString(str1);//�������� � ������ ����� �� �3 ����� str1
	cout << "str3=[" << str3.GetString() << "]\n";//�������� ����� � �������� ����


	int array[size] = { 1, 2, 3 }; //�������� ���'�� ��� ������ ���� int 
	String str6  {  CreateStringWithNumbers ( array, size) };//��������� 6 - ��'��� �����, �������� ���� ����� � ��������� ����� ������ ������������ ����������
	cout << "str6=[" << str6.GetString() << "]\n"; //�������� ��������� ����� � �������� ����
	return 0;
}

char ConvertDigitToChar(int digit)//������� ��� �������� ����� � ������� � �������� �������
{
	return digit>=0 && digit<= 9 ? digit+ '0'  :  '!';
}

String CreateStringWithNumbers(const int array[], size_t size) //������� ��� ������� � ������ ���� ����� 
{
	if (array == nullptr || size == 0)//�������� ���� �����  ������� nullptr ��� ����� ������  ������� ���� 
		                              //������������  ����������� �� �������������
		return String();
	char* str = new char[size + 1]; //�������� ������ ��� �����(������ �������)
	for (size_t i = 0; i<size; i++) // ��������� �� ������ � ���������� ����� ������� ������ int �  char
	{
		 
		str[i] = ConvertDigitToChar(array[i]);
	}

	str[size] = '\0';//����� ������ ����������� �����-����������� '\0'
	String object{ str }; //�������� �� ���� ��'��� ����� � �������� ���� ��� ����� ������� ���� �� ����������� � int � char
	delete[]str; //���������� ��'���� ��������� ������
	return object; //��������� ��'��� ��� ����������� ����������� ����������
}
