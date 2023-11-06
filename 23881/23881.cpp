#include <iostream>
#include <vector>

std::vector <int> selection_sort;

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

int	find_maxmum(int arr_len)
{
	int maxmum, idx;

	maxmum = 0;
	// 최대값 찾기
	for (int i = 0; i < arr_len; i++)
	{
		if (selection_sort[i] > maxmum)
		{
			maxmum = selection_sort[i];
			idx = i;
		}
	}
	return (idx);
}

int main()
{
	int	arr_len, change_count, element, temp, maxmum, times;
	int	fir_out, sec_out;

	times = 0; // 교환 횟수
	std::cin >> arr_len >> change_count;
	// 배열 삽입
	for (int i = 0; i < arr_len; i++)
	{
		std::cin >> element;
		selection_sort.push_back(element);
	}
	// 최대값 찾기
	while (!check_asc(arr_len))
	{
		maxmum = find_maxmum(arr_len);
		// 만약 최대값이 제자리에 있다면 그냥 패스
		if (maxmum == arr_len - 1)
		{
			arr_len--;
			continue ;
		}
		// 자리변경과 함께 배열 길이 값 --
		temp = selection_sort[maxmum];
		selection_sort[maxmum] = selection_sort[arr_len - 1];
		selection_sort[arr_len - 1] = temp;
		times++;
		if (times == change_count)
		{
			fir_out = selection_sort[maxmum];
			sec_out = selection_sort[arr_len - 1];
		}
		arr_len--;
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