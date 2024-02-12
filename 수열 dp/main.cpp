#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> narray;
vector<int> n_cnt(1000, 0);

int main() {
	int n, num, i, j, check, save_index;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> num;
		narray.push_back(num);
	}


	for (i = 0; i < n; i++) {
		check = 1;   // 현재 값보다 작은 값이 있었는지 체크
		save_index = 0;   //0으로 초기화
		for (j = 0; j < i; j++) {
			if (narray[j] < narray[i]) {
				if (n_cnt[j] >= n_cnt[save_index]) {
					save_index = j;    //작은 값중에 cnt가 가장큰 위치 저장
					check = 0;
				}
				
			}
		}
		if (check == 1) {   //현재 값보다 작은 값이 없었으므로 cnt 1로 저장
			n_cnt[i] = 1;
		}
		else
		    n_cnt[i] = n_cnt[save_index] +1;   //자기자신과 큰 위치 값의 cnt를 저장해 더해줌

	}

	auto iter = max_element(n_cnt.begin(), n_cnt.end());  //cnt가 가장 큰 값 찾기
	cout << *iter;

	
}