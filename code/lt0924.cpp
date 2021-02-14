// https://leetcode-cn.com/problems/minimize-malware-spread/
// minimize malware spread
class Solution {
public:

	int dfs(vector<vector<int>>& graph, vector<bool>& visited, int v) {
		
		int sum = 0;
		for (int i = 0; i < graph[v].size(); i++) {
			if (graph[v][i] && (!visited[i])) {
				visited[i] = true;
				sum = sum  + 1 + dfs(graph, visited, i);
			}
		}
		return  sum;
	}

	int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
	
		vector<bool> visited(graph.at(0).size(), false);
		
		int val = dfs(graph, visited, initial.at(0));
		int cur = initial.at(0);
		
		for (int i = 1; i < initial.size(); i++) {
			visited = vector<bool>(visited.size(), false);
			int nVal = dfs(graph, visited, initial.at(i));
			if (nVal >= val) {
				if (val == nVal) {
					if (cur > initial.at(i)) {
						cur = initial.at(i);
					}
				}else {
					cur = initial.at(i);
					val = nVal;
				}
			}
		}
		return cur;
	}
};