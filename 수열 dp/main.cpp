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
		check = 1;   // ���� ������ ���� ���� �־����� üũ
		save_index = 0;   //0���� �ʱ�ȭ
		for (j = 0; j < i; j++) {
			if (narray[j] < narray[i]) {
				if (n_cnt[j] >= n_cnt[save_index]) {
					save_index = j;    //���� ���߿� cnt�� ����ū ��ġ ����
					check = 0;
				}
				
			}
		}
		if (check == 1) {   //���� ������ ���� ���� �������Ƿ� cnt 1�� ����
			n_cnt[i] = 1;
		}
		else
		    n_cnt[i] = n_cnt[save_index] +1;   //�ڱ��ڽŰ� ū ��ġ ���� cnt�� ������ ������

	}

	auto iter = max_element(n_cnt.begin(), n_cnt.end());  //cnt�� ���� ū �� ã��
	cout << *iter;

	
}