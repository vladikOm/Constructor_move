#include "String.h"
#include<cstring>
#include<iostream>
String::String(): //Конструктор за замовчуванням він встановлює через список ініціалізації вказівнику  nullptr i  length = 0
	str(nullptr),length(0)
	
{
	std::cout << "\t Default Constructor |String()| \n\n";
}

String::String(const String& other):String() //Конструктор копії перед тим як викликати його ми викликаємо коструктор за замовчуванням
{
	std::cout << "\t Copy Constructor |String(const String& other)|\n\n";
	if (other.length != 0)  //Перевіряємо якщо довжина рядка в іншому обєкті не дорівнює нулю
	{   //Тоді копіюємо довжину, виділяємо пам'ять для рядка і визиваємо функцію strcpy_s -> функцію копіювання
		this->length = other.length;  
		str = new char[length + 1];
		strcpy_s(this->str,length + 1, other.str);

	}

}

String::String( String&& other)noexcept://Конструктор переносу 
	str(other.str), length(other.length)
{
	std::cout << "\t Move Constructor |String( String&& other)noexcept|\n"<<std::endl;
	other.str = nullptr;
	other.length = 0;
}


 String::String(const char* str):String()//Конструктор який приймає рядок в стилі С, спочатку ми викликаємо конструктор за замовчуванням
{
	 std::cout << "\t Constructor |String(const char* str)|\n" << std::endl;

	 if (str != nullptr && std::strlen(str) != 0)  //Перевіряємо якщо вказівник на рядок не дорівнює нулю і довжина не дорівнює нулю
	 {
		 size_t length = std::strlen(str); //Знаходимо довжину рядка 
		 this->length = length;          //Копіємо довжину 
		 this->str = new char [length+1];//Виділяємо пам'ять

         strcpy_s(this->str, length + 1, str);   //Копіюємо рядок 
	 }

}
 String::String(const char array[], size_t size):String()//конструктор який приймає масив і його розмір  
 {
	 std::cout << "\t Constructor |String(const char array[], size_t size)|\n" << std::endl;
	 if (array!= nullptr && size != 0)//перевірка якщо масив не дорівнює nullptr або розмір масива не дорівнює нулю 
	 {
		length = size;      //ініціалізуємо поле класу  копіюємо довжину  
		 str = new char[length + 1]; //виділяємо пам'ять для зберігання
		 for (size_t i = 0; i < length; i++)//проходимось по масиву 
			
			 str[i] = array[i];// копіюємо кожен елемент масиву

		 str[length] = '\0';
		
		}
 }

 String::~String()//Деструктор 
 {
	 std::cout << "\t Destructor |~String()|\n" << std::endl;
	 delete[] str;//видаляє пам'ять 
	 str = nullptr; //присвоює нульовий вказівник для рядка
	 length = 0;//присвоює довжині нуль
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
