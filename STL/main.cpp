﻿#include<iostream>
#include<array>
#include<vector>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR
//#define EXCEPTIONS_IN_VECTOR

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:    " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;//Вместительность - сколько элементов может вместить в себя вектор 
	cout << "MAXSize: " << vec.max_size() << endl;
}

template<typename T>void vector_print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

template<typename T>void vector_reverse_print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_reverse_iterator it = vec.crbegin(); it != vec.crend() ; it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STL_ARRAY
	const int n = 5;
	std::array<int, n>arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, };
	vector_properties(vec);
	vec.push_back(55);
	vector_properties(vec);
#ifdef EXCEPTIONS_IN_VECTOR
	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			//try...catch...
			//[] - index operator(subscript operator)
			//cout << vec[i] << tab;//Oператор [] НЕ бросает исключение при выходе за пределы вектора.
			cout << vec.at(i) << tab;//метод at() росает исключение(out of range exception) при выходе за пределы вектора.
		}
		cout << endl;
		//throw 123;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (int e)
	{
		std::cerr << "Error number: " << e << endl;
	}
#endif // EXCEPTIONS_IN_VECTOR

	int index;
	int value;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	
	std::vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, value);

	vector_print(vec);
	vector_reverse_print(vec);

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	vec.erase(vec.begin() + index);
	vector_print(vec);

#endif // STL_VECTOR

}