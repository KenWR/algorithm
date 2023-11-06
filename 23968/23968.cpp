#include <iostream>
#include <vector>

int selection_sort[10000];

	//	오름차순인지 확인
int	check_asc(int arr_len)
{
	for (int i = 1; i < arr_len; i++)
	{
		if (selection_sort[i - 1] > selection_sort[i])
			return (0);
	}
	return (1);
}

int main()
{
	int	arr_len, change_count, element, temp, times;
	int	fir_out, sec_out;

	times = 0; // 교환 횟수
	std::cin >> arr_len >> change_count;
	// 배열 삽입
	for (int i = 0; i < arr_len; i++)
	{
		std::cin >> element;
		selection_sort[i] = element;
	}
	// 최대값 찾기
	while (!check_asc(arr_len)) // 오름차순 될 때 까지
	{
		for (int i = 0; (i + 1) < arr_len; i++)
		{
			if (selection_sort[i] > selection_sort[i + 1])
			{
				temp = selection_sort[i];
				selection_sort[i] = selection_sort[i + 1];
				selection_sort[i + 1] = temp;
				times++;
				if (times == change_count)
				{
					fir_out = selection_sort[i];
					sec_out = temp;
				}
			}
		}
	}
	if (times < change_count)
	{
		std::cout << -1;
		return (0);
	}
	std::cout << fir_out;
	std::cout << ' ';
	std::cout << sec_out;
	return (0);
}