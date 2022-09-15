#include"String.h"
#include<iostream>

char ConvertDigitToChar(int digit);//Функція конвертує цифру в символ


String CreateStringWithNumbers(const int array[], size_t size);//Функція сворює рядок з числами приймаємо масив чисел і його розмір і виводимо рядок

using namespace std;//Підключаємо простір імен std щоб користуватись спокійно cout  
int main()
{
	

	String str1{ "I have to create program" }; //Створюємо 1- об'єкт класу, і в цей конструктор"String(const char* str)" передається наш рядок   

	String str2{ str1 }; //Створюємо 2 - об'єкт класу викликається конструктор копії String(const String& other):String() 

	String str3; //Створюємо 3- об'єкт класу викликається конструктор за замовчуванням

	const char* STR = "SOME C-interesting text";//створюємо рядок на кучі типу С
	String str4{ STR };//Створюємо 4- об'єкт класу, визивається конструктор String(const char* str), який приймає рядок в стилі С                

    const size_t size = 5; //створюємо константну змінну для задання розміру масиву
	char someLetters[size] = { 'A','B','C','D','E' };//створюємо масив типу char ініціалізуємо його
	String str5 { someLetters, size};//Створюємо 5- об'єкт класу, визиваємо конструктор String(const char array[], size_t size) і
	                                 //передаємо наш масив і розмірність його


	cout << "\t  We get the created objects \n";  //Для кожного об'єкта визиваємо метод GetString()і якщо рядок не нульовий то ми його повертаємо      
	cout << "str1=[" << str1.GetString() << "]\n";
	cout << "str2=[" << str2.GetString() << "]\n";
	cout << "str3=[" << str3.GetString() << "]\n";
	cout << "str4=[" << str4.GetString() << "]\n";
	cout << "str5=[" << str5.GetString() << "]\n";

	cout  << "\t  We get the  length created objects \n";//Для кожного об'єкта визиваємо метод GetLength() і повертаємо  довжину рядка

	cout << "str1 lengh=[" << str1.GetLength() << "]\n";
	cout << "str2 lengh=[" << str2.GetLength() << "]\n";
	cout << "str3 lengh=[" << str3.GetLength() << "]\n";
	cout << "str4 lengh=[" << str4.GetLength() << "]\n";
	cout << "str5 lengh=[" << str5.GetLength() << "]\n";

	cout << "\t  We checking object emply Yes or No \n";//Для кожного об'єкта визиваємо метод IsEmply() і повертаємо Рядок наш пустий "ТАК" чи"НІ "

	cout << "Is str1 emply ? = " << (str1.IsEmply() ?"  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = " <<(str2.IsEmply() ?"  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = " << (str3.IsEmply() ? "  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = "<< (str4.IsEmply() ? "  Yes  " : "  No  ") << endl;
	cout << "Is str1 emply ? = "<< (str5.IsEmply() ? "  Yes  " : "  No  ") << endl;
	

	cout << "\n ";//Далі ми використовуючи сетери встановлюємо нові значення для рядка №3 памятай під час виклику метода SetString 
	             //постійно очищується попередні значення що були в пам'яті
	str3.SetString(STR); //передаємо в пустий рядок під №3 рядок str4
	cout << "str3=[" << str3.GetString() << "]\n"; //отримуємо рядок і виводимо його
	str3.SetString(someLetters, size); // передаємо в цей же  рядок під №3  str5
	cout << "str3=[" << str3.GetString() << "]\n";//отримуємо рядок і виводимо його
	str3.SetString(str1);//передаємо в пустий рядок під №3 рядок str1
	cout << "str3=[" << str3.GetString() << "]\n";//отримуємо рядок і виводимо його


	int array[size] = { 1, 2, 3 }; //виділяємо пам'ть для масиву типу int 
	String str6  {  CreateStringWithNumbers ( array, size) };//Створюємо 6 - об'єкт класу, передаємо сюди масив і повертаємо рядок виклик конструктора переміщення
	cout << "str6=[" << str6.GetString() << "]\n"; //отримуємо отриманий рядок і виводимо його
	return 0;
}

char ConvertDigitToChar(int digit)//функція яка конвертує цифри в символи і виводить символи
{
	return digit>=0 && digit<= 9 ? digit+ '0'  :  '!';
}

String CreateStringWithNumbers(const int array[], size_t size) //функція яка створює з масива цифр рядок 
{
	if (array == nullptr || size == 0)//перевірка якщо масив  дорівнює nullptr або розмір масива  дорівнює нулю 
		                              //тодіповертаємо  конструктор за замовчуванням
		return String();
	char* str = new char[size + 1]; //виділяємо память для рядка(масива символів)
	for (size_t i = 0; i<size; i++) // проходимо по масиву і конвертуємо кожен елемент масиув int в  char
	{
		 
		str[i] = ConvertDigitToChar(array[i]);
	}

	str[size] = '\0';//Розмір масиву визначається нулем-термінатором '\0'
	String object{ str }; //Створюмо ще один об'єкт класу і передаємо туди наш масив символів який ми перетворили з int в char
	delete[]str; //Вивільнюємо па'мять свореного масиву
	return object; //Повертаємо об'єкт тут викликається конструктор переміщення
}
