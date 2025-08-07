#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    //통분 :   a/b + c/d = (a*d + b*c) / (b*d)
    int numerator = a * d + b * c;  //분자
    int denominator = b * d;  //분모

    //최대공약수로 기약분수 만들기
    int gcd_value = gcd(numerator,  denominator);
    cout << numerator / gcd_value << " " << denominator / gcd_value << "\n";
    return 0;
}