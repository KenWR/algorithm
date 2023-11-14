#include <vector>
#include <algorithm>
#include <stdio.h>

int	N, M, i;
std::vector<int>	A;

int		partition(int start_idx, int end_idx);
void	quick_sort(int start_idx, int end_idx);
bool	binary_search(int num);
bool	check(int idx, int num);

int main(){
	int	num;

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		A.push_back(num);
	}
	std::sort(A.begin(), A.end());
	scanf("%d", &M);
	for (int i = 0; i < M; i++){
		scanf("%d", &num);
		printf("%d ", binary_search(num));
	}
}

// void	quick_sort(int start_idx, int end_idx){
// 	int	mid_idx;

//     if (start_idx < end_idx){
//         mid_idx = partition(start_idx, end_idx); 
//         quick_sort(start_idx, mid_idx - 1); 
//         quick_sort(mid_idx + 1, end_idx); 
//     }
// }

// int	partition(int start_idx, int end_idx){
// 	int	pivot;

//     pivot = A[end_idx];       
//     for (int j = start_idx; j <= end_idx - 1; j++){
// 		if (A[j] <= pivot) {
// 			std::swap(A[start_idx], A[j]);
// 			start_idx++; 
// 		}
// 	}
//     if ((start_idx) != end_idx){
// 		std::swap(A[start_idx], A[end_idx]);
// 	} 
//     return (start_idx);
// }

bool    binary_search(int num){
	int	mid, left, right;

	left = 0;
	right = N;
	while (left + 1 < right){
		mid = (left + right) / 2;
		if (check(left, num) == check(mid, num)){
			left = mid;
		}
		else
			right = mid;
	}
	if (A[left] == num)
		return (true);
	return (false);
}

bool	check(int idx, int num){
	if (A[idx] <= num)
		return (true);
	return (false);
}