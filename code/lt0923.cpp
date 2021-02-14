// https://leetcode-cn.com/problems/3sum-with-multiplicity/
// 3sum with multiplicity
class Solution {
public:


	int threeSumMulti(vector<int>& A, int target) {
		
		long long sum = 0;
		long long r = pow(10, 9) + 7;
		int type = 0;
		int C[3] = { 1, 2, 6 };
		long long I, J, K;

		vector<int> record(101, 0);

		for (int i = 0; i < A.size(); i++) {
			record[A.at(i)]++;
		}
		

		for (int i = 0; i < record.size(); i++) {
			
			type = 0;

			if (i > target)
				break;
			
			if (record[i] == 0)
				continue;

			I = record[i];
			
			for (int j = i; j < record.size(); j++) {
				
				if (i + j > target)
					break;

				if (record[j] == 0)
					continue;

				if (i == j) {
					record[j]--;
					type++;
				}

				J = record[j];

				for (int k = j; k < record.size(); k++) {
					
					if (i + j + k > target)
						break;
					
					if (record[k] == 0)
						continue;

					if (k == j) {
						record[k]--;
						type++;
					}

					K = record[k];
					
					if (i + j + k == target) {
						cout << i << ends << j << ends << k << endl;
						cout << I << ends << J <<ends <<  K << endl;
						sum = (sum + (I * J * K)/C[type]) % r;
					}

					if (j == k) {
						type--;
						record[k]++;
					}
				}

				if (i == j) {
					type--;
					record[j]++;
				}
			}
		}
		return sum;
	}
};