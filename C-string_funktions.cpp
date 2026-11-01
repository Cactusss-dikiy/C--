#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
void enter(int lenght1,int lenght2)
{ 
	std::cout << lenght1 << '\n';
	std::cout << lenght2 << '\n';
}
int main ()
{
	char stroka1[255] = {};
	char stroka2[255] = {};
	std::cout << "Enter two strings\n";
	std::cin.getline(stroka1,255);
	std::cin.getline(stroka2,255);
	//длина
	int lenght1 = std::strlen(stroka1);
	int lenght2 = std::strlen(stroka2);
	enter(lenght1,lenght2);
	//копирование
	char stroka1_1[255] = {};
	std::strcpy(stroka1_1, stroka2);
	std::cout << stroka1 << '\n' << stroka1_1 << '\n' << stroka2 << '\n';
	int n = {};
	std::cout << "Enter number\n";
	std::cin >> n;
	std::strncpy(stroka1_1, stroka1, n);
	std::cout << stroka1 << '\n' << stroka1_1 << '\n' << stroka2 << '\n';
	//сравнение
	int comparison = std::strcmp(stroka1, stroka2);
	std::cout << comparison << '\n';
	std::cout << "Enter number\n";
	std::cin >> n;
	comparison = std::strncmp(stroka1, stroka2,n);
	std::cout << comparison << '\n';
	//символы
	//поиск
	char c;
	std::cout << "Enter char\n";
	std::cin >> c;
	char* founding = std::strchr(stroka1, c);
	int index = founding - stroka1;
	std::cout << index << '\n';
	founding = std::strchr(stroka1, c);
	index = founding - stroka1;
	std::cout << index << '\n';
	//длина  до символа 
	n = std::strcspn(stroka1,stroka2);
	std::cout << n << '\n';
	n = std::strspn(stroka1, stroka2);
	std::cout << n << '\n';
	founding = strpbrk(stroka1, stroka2);
	index = founding - stroka1;
	std::cout << index << '\n';
	std::cout << index << '\n';
	return 0;
}