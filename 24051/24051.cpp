#include <iostream>

int	size_of_arr, save_times;
int	arr[10002];

int	selection_sort()
{
	int loc, new_item, count;

	count = 0;
	for (int i = 1; i < size_of_arr; i++)
	{
		loc = i - 1;
		new_item = arr[i];
		while (loc >= 0 && arr[loc] > new_item)
		{
			arr[loc + 1] = arr[loc];
			count++;
			if (count == save_times)
				return (arr[loc + 1]);
			loc--;
		}
		if (loc + 1 != i)
		{
			arr[loc + 1] = new_item;
			count++;
			if (count == save_times)
				return (arr[loc + 1]);
		}
	}
	return (-1);
}

int main()
{
	std::cin >> size_of_arr >> save_times;
	// 배열 삽입
	for (int i = 0; i < size_of_arr; i++)
		std::cin >> arr[i];
	std::cout << selection_sort();
	return (0);
}