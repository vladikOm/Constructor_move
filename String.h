#pragma once
class String
{
private:
     //ПОЛЯ або ЧЛЕНИ класу String
	char* str;                              //Вказівник на рядок типу char
	size_t length;                          //Довжина рядка  
public:
  //МЕТОДИ Класу String 
	String();                               //Конструктор за замовчуванням
	String(const String& other);            //Конструктор копії, або copy constructor
	String(String&& other)noexcept;         // Конструктор переносу,або move constructor
	String(const char* str);                //Конструктор який приймає рядок в стилі С
	String(const char array[], size_t size);//Конструктор який приймає масив символів і їх розмір

	~String();                              //Деструктор
	//Методи гетери 
	const char* GetString() const { return  str ? str : "  "; }//Константний метод  який перевіряє, якщо рядок на щось вказує,
															   //то ми повертаємо рядок якщо ні  то повертаємо пустий рядок
    size_t GetLength() const { return length; }                //Метод який повертає довжину
	bool IsEmply() const { return length == 0; }               //Метод який перевіряє чи рядок пустий
    //Сетери методи копії конструкторів 
    void SetString(const char* str);                     //Метод що приймає С рядок
    void SetString(const String& other);                 //Метод що приймає інший об'єкт
    void SetString(const char array[],size_t size);      //Метод що приймає масив символів 
};

