#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int find_min_combination(size_t max_chicken, vector<pair<int, int> > &houses, vector<pair<int, int> > &chickens, int search_idx, vector<int> &selections);
int cal_dist(pair<int, int> position1, pair<int, int> position2);

int main(void){
	size_t len_arr, max_chicken;
	vector<pair<int, int> > houses, chickens;
	scanf("%zu %zu", &len_arr, &max_chicken);
	for(size_t i = 0; i < len_arr; i++){
		for(size_t j = 0; j < len_arr; j++){
			int tmp;
			scanf("%d", &tmp);
			switch(tmp){
				case 1:
					houses.push_back(make_pair(i, j));
					break;
				case 2:
					chickens.push_back(make_pair(i, j));
					break;
			}
		}
	}
	vector<int> selections;
	printf("%d\n",find_min_combination(max_chicken, houses, chickens, 0, selections));
	return 0;
}

int find_min_combination(size_t max_chicken, vector<pair<int, int> > &houses, vector<pair<int, int> > &chickens, int search_idx, vector<int> &selections){
	if(max_chicken == selections.size()){
		int total_dist_chicken = 0;
		for(vector<pair<int, int> >::iterator house = houses.begin(); house != houses.end(); house++){
			int dist_chicken = 987654321;
			for(vector<int>::iterator selection = selections.begin(); selection != selections.end(); selection++)
				dist_chicken = min(dist_chicken, cal_dist(*house, chickens[*selection]));
			total_dist_chicken += dist_chicken;
		}
		return total_dist_chicken;
	}
	int min_return = 987654321;
	for(size_t i = search_idx; selections.size() + chickens.size() - i >= max_chicken; i++){
		selections.push_back(i);
		min_return = min(min_return, find_min_combination(max_chicken, houses, chickens, i, selections));
		selections.pop_back();
	}
	return min_return;
}

int cal_dist(pair<int, int> position1, pair<int, int> position2){
	return abs(position1.first - position2.first) + abs(position1.second - position2.second);
}
