#include <iostream>
#include <cstdint>
#include <limits>
#include <vector>
#include <array>
#include <random>
#include <ctime>
int32_t constexpr MAX_NUMBER = 100;
int enter_size(int32_t& size,long double*& numbers)
{
	std::cout << "Enter the size (if you want to use static massive or array size must be less then 100 )\n";
	if (!(std::cin >> size))
	{
		std::cout << "Incorrect value, size it is a number\n";
		return 0;
	}
	if (size <= 0)
	{
		std::cout << "Incorrect value, size must be bigger then 0\n";
		return 0;
	}
	return 1;
}
int enter_array(int32_t size, long double*& numbers , size_t& stat, std::vector<long double>& num3, std::array<long double, MAX_NUMBER>& num2)
{
	
	
	std::cout << "Vector - 3, array - 2, static - 1, dinamic - 0\n";
	if (!(std::cin >> stat))
	{
		std::cout << "Incorrect value\n";
		return 0;
	}
	if (stat == 1)
	{
		
		if (size >= MAX_NUMBER)
		{
			std::cout << "Incorrect value,size must be less then 100\n";
			return 0;
		}
		static long double num[MAX_NUMBER];
		numbers = num;
	}
	else if (stat == 0)
	{
		numbers = new long double[size];
	}
	else if (stat == 2)
	{
		if (size >= MAX_NUMBER)
		{
			std::cout << "Incorrect value,size must be less then 100\n";
			return 0;
		}
		numbers = num2.data();
	}
	else if (stat == 3)
	{
		numbers = num3.data();
	}

	else
	{
		std::cout << "Incorrect value\n";
		return 0;
	}
	size_t m;
	std::cout << "Random - 1; enter - 0\n";
	if (!(std::cin >> m))
	{
		std::cout << "Incorrect value\n";
		return 0;
	}
	if (m == 1)
	{
		long double a;
		long double b;
		std::cout << "Enter borders\n";
		if (!(std::cin >> a))
		{
			std::cout << "Incorrect value\n";
			return 0;
		}
		if (!(std::cin >> b))
		{
			std::cout << "Incorrect value\n";
			return 0;
		}
		if (a > b)
		{
			std::swap(a, b);
		}
		//ввод случайного массива
		std::srand(time(0));
		for (size_t i = 0;i < size; ++i)
		{
			numbers[i] = static_cast<long double>(rand()) / RAND_MAX * (b - a) + a;
			std::cout << numbers[i] << ' ';
		}
		std::cout << '\n';
	}
	else if (m == 0)
	{
		std::cout << "Enter the massive\n";
		for (size_t i = 0; i < size; ++i)
		{
			if (!(std::cin >> numbers[i]))
			{
				std::cout << "Incorrect value\n";
				return 0;
			}
		}
	}
	else
	{
		std::cout << "Incorrect value\n";
		return 0;
	}
	return 1;
}
void enter_the_min_element_number(int32_t size, long double*& numbers)
{
	long double min_value = std::numeric_limits<long double>::max();//numbers[0];
	size_t number_min{};
	for (size_t i = 0; i < size; ++i)
	{
		if (min_value >= numbers[i])
		{
			min_value = numbers[i];
			number_min = i;
		}

	}
	std::cout << "Number of min element " << number_min + 1 << '\n';
}
void sum_between_two_elements_under_0(int32_t size, long double*& numbers)
{
	int x = -1;
	int y = -1;
	long double sum{};
	for (size_t i = 0; i < size; ++i)
	{

		if (numbers[i] < 0)
		{
			x = i;
			break;
		}
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (numbers[i] < 0)
		{
			y = i;
		}
	}
	if (x != -1 && y != -1 && x != y)
	{
		for (size_t i = x; i <= y; ++i)
		{
			sum += numbers[i];
		}
		std::cout << "Sum between two elements < 0\n" << sum << '\n';
	}
	else
	{
		std::cout << "There are no 2 elements < 0\n";
	}
}
int changing_array (int32_t size, long double*& numbers, size_t stat)
{
	long double pick;
	std::cout << "Enter value \n";
	if (!(std::cin >> pick))
	{
		std::cout << "Incorrect value\n";
		return 0;
	}
	size_t i = 0;
	size_t k = 0;

	while (k < size)
	{
		if (numbers[i] >= pick)
		{
			long double arr = numbers[i];
			for (size_t m = i; m < size - 1; ++m)
			{
				numbers[m] = numbers[m + 1];

			}
			numbers[size - 1] = arr;
			++k;
		}
		else
		{
			++i;
			++k;
		}
	}
	for (size_t i = 0;i < size; ++i)
	{
		std::cout << numbers[i] << ' ';
	}
	if (stat == 0 && numbers != nullptr)
	{
		delete[]numbers;
	}
	return 1;
}
int main()
{
	int32_t size{};
	long double* numbers = nullptr;
	if (!(enter_size(size, numbers)))
	{
		return 0;
	}
	size_t stat{};
	std::vector<long double> num3(size);
	int32_t constexpr MAX_NUMBER = 100;
	std::array<long double, MAX_NUMBER> num2 = {};
	if (!(enter_array(size, numbers, stat, num3, num2)))
	{
		return 0;
	}
	//выведение номера наименьшего элемента
	enter_the_min_element_number(size, numbers);
	//нахождение суммы элементов между первым и последним отрицательными элементами
	sum_between_two_elements_under_0( size, numbers);
	//преобразование массива
	if (!(changing_array(size, numbers, stat)))
	{
		return 0;
	}
	return 0;
}