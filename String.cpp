#include "String.h"
#include<cstring>
#include<iostream>
String::String(): 
	str(nullptr),length(0)
	
{
	std::cout << "\t Default Constructor |String()| \n\n";
}

String::String(const String& other):String() /
{
	std::cout << "\t Copy Constructor |String(const String& other)|\n\n";
	if (other.length != 0)  
	{   
		this->length = other.length;  
		str = new char[length + 1];
		strcpy_s(this->str,length + 1, other.str);

	}

}

String::String( String&& other)noexcept:
	str(other.str), length(other.length)
{
	std::cout << "\t Move Constructor |String( String&& other)noexcept|\n"<<std::endl;
	other.str = nullptr;
	other.length = 0;
}


 String::String(const char* str):String()
{
	 std::cout << "\t Constructor |String(const char* str)|\n" << std::endl;

	 if (str != nullptr && std::strlen(str) != 0)  
	 {
		 size_t length = std::strlen(str); 
		 this->length = length;          
		 this->str = new char [length+1];

         strcpy_s(this->str, length + 1, str);  
	 }

}
 String::String(const char array[], size_t size):String()
 {
	 std::cout << "\t Constructor |String(const char array[], size_t size)|\n" << std::endl;
	 if (array!= nullptr && size != 0)
	 {
		length = size;      
		 str = new char[length + 1];
		 for (size_t i = 0; i < length; i++)
			
			 str[i] = array[i];

		 str[length] = '\0';
		
		}
 }

 String::~String()
 {
	 std::cout << "\t Destructor |~String()|\n" << std::endl;
	 delete[] str;
	 str = nullptr; 
	 length = 0;
 }

 
 void String::SetString(const char* str)
 {

     if (str != nullptr && length != 0)
	 { size_t length = std::strlen(str);
		 delete[] this->str;
		 this->length = length;
		 this->str = new char[length + 1];

		 strcpy_s(this->str, length + 1, str);
	 }

 }

 void String::SetString(const String& other)
 {
	 if (other.length != 0)
	 {
		 delete[] str;
		 this->length = other.length;
		 str = new char[length + 1];
		 strcpy_s(this->str, length + 1, other.str);

	 }


 }

 void String::SetString(const char array[], size_t size)
 {

	 if (array != nullptr && size != 0)
	 {
		 delete[] str;
		 length = size;
		 str = new char[length + 1];
		 for (size_t i = 0; i < length; i++)
			 str[i] = array[i];

		 str[length] = '\0';

	 }
 }
