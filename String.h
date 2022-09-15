#pragma once
class String
{
private:
     //���� ��� ����� ����� String
	char* str;                              //�������� �� ����� ���� char
	size_t length;                          //������� �����  
public:
  //������ ����� String 
	String();                               //����������� �� �������������
	String(const String& other);            //����������� ��ﳿ, ��� copy constructor
	String(String&& other)noexcept;         // ����������� ��������,��� move constructor
	String(const char* str);                //����������� ���� ������ ����� � ���� �
	String(const char array[], size_t size);//����������� ���� ������ ����� ������� � �� �����

	~String();                              //����������
	//������ ������ 
	const char* GetString() const { return  str ? str : "  "; }//����������� �����  ���� ��������, ���� ����� �� ���� �����,
															   //�� �� ��������� ����� ���� �  �� ��������� ������ �����
    size_t GetLength() const { return length; }                //����� ���� ������� �������
	bool IsEmply() const { return length == 0; }               //����� ���� �������� �� ����� ������
    //������ ������ ��ﳿ ������������ 
    void SetString(const char* str);                     //����� �� ������ � �����
    void SetString(const String& other);                 //����� �� ������ ����� ��'���
    void SetString(const char array[],size_t size);      //����� �� ������ ����� ������� 
};

