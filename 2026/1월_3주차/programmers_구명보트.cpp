#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int ans{ 0 };
    int light_idx{0};
    int heavy_idx = (int)people.size() - 1;
    while(light_idx <= heavy_idx){
        if(people[light_idx] + people[heavy_idx] <= limit){
            light_idx++;
            heavy_idx--;
        }
        else{
            heavy_idx--;
        }
        ans++;
    }

    return ans;
    
}#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int ans{ 0 };
    int light_idx{0};
    int heavy_idx = (int)people.size() - 1;
    while(light_idx <= heavy_idx){
        if(people[light_idx] + people[heavy_idx] <= limit){
            light_idx++;
            heavy_idx--;
        }
        else{
            heavy_idx--;
        }
        ans++;
    }

    return ans;
    
}