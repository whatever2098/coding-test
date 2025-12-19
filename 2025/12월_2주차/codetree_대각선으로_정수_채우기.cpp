#include <iostream>
using namespace std;

int main() {
   int N, M;
   cin >> N >> M;

   int arr[101][101];
   int num = 1;

   for (int d{0};d < N + M - 1;d++){
      for (int i{0};i < N;i++){
         int j = d - i;
         if(0 <= j && j < M){
            arr[i][j] = num;
            num++;
         }
      }
      
   }

  for(int i{0};i < N;i++){
   for(int j{0};j < M;j++){
      cout << arr[i][j] << " ";
   }
   cout << "\n";
  }
}