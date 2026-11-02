#include <iostream>
#include <vector>
int enter_rows_and_calls(size_t &rows,size_t &cals)
{
	std::cout << "Enter rows and calls\n";
	if (!(std::cin >> rows >> cals))
	{
		std::cout << "Rows and calls must be numbers\n";
		return 0;
	}
	if (rows <= 0 || cals <= 0)
	{
		std::cout << "Incorrect value\n";
		return 0;
	}
	return 1;
}
int enter_matrix(std::vector<std::vector<long long>>& matrix, size_t& rows, size_t& cals)
{
	size_t random_enter = {};
	std::cout << "Random - 1, enter - 0\n";
	if (!(std::cin >> random_enter))
	{
		std::cout << "It must be a number\n";
		return 0;
	}
	if (random_enter == 1)
	{
		long long a, b;
		std::cout << "Enter borders\n";
		if (!(std::cin >> a >> b))
		{
			std::cout << "Rows and calls must be numbers\n";
			return 0;
		}
		if (a > b)
		{
			std::swap(a, b);
		}
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < cals; ++j)
			{
				matrix[i][j] = a + rand() % static_cast<long long>(b - a + 1);
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << '\n';

		}
	}
	else if (random_enter == 0)
	{

		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < cals; ++j)
			{
				if (!(std::cin >> matrix[i][j]))
				{
					std::cout << "Elements must be numbers\n";
					return 0;
				}
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}
	else
	{
		std::cout << "Incorrect value\n";
		return 0;
	}
	return 1;
}
void sum_calls_with_0(std::vector<std::vector<long long>>& matrix, size_t& rows, size_t& cals)
{
	long long sum = {};
	size_t y = {};
	for (size_t j = 0; j < cals;++j)
	{
		size_t x = {};
		for (size_t i = 0; i < rows;++i)
		{
			if (matrix[i][j] == 0)
			{
				++x;
				++y;
			}
		}
		if (x != 0)
		{
			for (size_t i = 0; i < rows;++i)
			{
				sum += matrix[i][j];
			}
		}
	}
	if (y != 0)
	{
		std::cout << "Sum of calls with 0 " << sum << "\n";
	}
	else
	{
		std::cout << "There are no calls with 0\n";
	}

}
void sort_matrix(std::vector<std::vector<long long>>& matrix, size_t& rows, size_t& cals)
{
	for (size_t i = 0; i < rows; ++i)
	{
		if (i % 2 == 0)
		{
			for (size_t j = 0; j < cals; ++j)
			{
				for (size_t k = 0; k + 1 < cals - j; ++k)
				{
					if (matrix[i][k] > matrix[i][k + 1])
					{
						std::swap(matrix[i][k], matrix[i][k + 1]);
					}
				}
			}
		}
		else
		{
			for (size_t j = 0; j < cals; ++j)
			{
				for (size_t k = 0; k + 1 < cals - j; ++k)
				{
					if (matrix[i][k] < matrix[i][k + 1])
					{
						std::swap(matrix[i][k], matrix[i][k + 1]);
					}
				}
			}
		}

	}
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cals; ++j)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';

	}
}
int main()
{
	size_t rows = {};
	size_t cals = {};
	if (!(enter_rows_and_calls(rows, cals)))
	{
		return 0;
	}
	std::vector<std::vector<long long>> matrix(rows, std::vector<long long>(cals));
	if (!(enter_matrix(matrix, rows, cals)))
	{
		return 0;
	}
	sum_calls_with_0(matrix, rows, cals);
	sort_matrix(matrix, rows, cals);	
	return 0;
}