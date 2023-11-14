#include <iostream>
#include <vector>

int	N, M, i;
std::vector<int> A;

int		partition(int start_idx, int end_idx);
void	quick_sort(int start_idx, int end_idx);
void	swap(int idx_1, int idx_2);
int		binary_search(int n);

int main(){
	int	num;

	std::cin >> N;
	for (int i = 0; i < N; i++){
		std::cin >> num;
		A.push_back(num);
	}
	quick_sort(0, N - 1);
	std::cin >> M;
	for (int i = 0; i < M; i++){
		std::cin >> num;
		std::cout << binary_search(num);
		std::cout << ' ';
	}
}

void	quick_sort(int start_idx, int end_idx){
	int	mid_idx;

    if (start_idx < end_idx){
        mid_idx = partition(start_idx, end_idx); 
        quick_sort(start_idx, mid_idx - 1); 
        quick_sort(mid_idx + 1, end_idx); 
    }
}

int	partition(int start_idx, int end_idx){
	int	pivot;

    pivot = A[end_idx];       
    for (int j = start_idx; j <= end_idx - 1; j++){
		if (A[j] <= pivot) {
			swap(start_idx, j);
			start_idx++; 
		}
	}
    if ((start_idx) != end_idx){
		swap(start_idx, end_idx);
	} 
    return (start_idx);
}

void	swap(int idx_1, int idx_2){
	int	tmp;

	tmp = A[idx_1];
	A[idx_1] = A[idx_2];
	A[idx_2] = tmp;
}

int    binary_search(int num){
	int	mid, left, right;

	left = 0;
	right = N;
	while (left + 1 < right){
		mid = (left + right) / 2;
		if (A[left] == A[mid]){

		}
	}
	return (0);
}

bool	check(int idx){
	A[idx]
}