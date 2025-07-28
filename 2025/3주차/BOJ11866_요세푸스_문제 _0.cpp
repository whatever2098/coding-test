#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int arr[1001];


int main(){
    int N, K;
    cin >> N >> K;
    for (int i { 1 };i <= N;i++){
        q.push(i);
    }

    for(int i { 0 };i < N;i++){
        for(int j{ 0 };j < K - 1;j++){
           q.push(q.front());
           q.pop();
        }
        arr[i] = q.front();
        q.pop();

    }

    cout << "<" ;
    for(int i { 0 };i < N;i++){
        cout << arr[i];
        if(i != N - 1) cout << ", ";
    }
    cout << ">" << "\n";
}
