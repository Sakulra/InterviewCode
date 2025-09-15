#include <cmath>
#include <iostream>
using namespace std;

bool isPerfectNumber(int num) {
    if (num <= 1) {
        return false; // 完美数必须大于1
    }
    
    int sum = 1; // 1是所有大于1的数的因子
    int sqrtNum = static_cast<int>(std::sqrt(num));
    
    // 遍历可能的因子
    for (int i = 2; i <= sqrtNum; i++) {
        if (num % i == 0) {
            sum += i;
            int complement = num / i;
            if (complement != i) { // 避免重复添加平方根
                sum += complement;
            }
        }
    }
    
    return sum == num;
}

int main(){
    int num;
    cout<<"please input number";
    while (cin >> num)
    {
        if(isPerfectNumber(num)){
            cout<<num<<" is a perfect number:"<<endl;
        }
        else{
            cout<<num<<" is NOT a perfect number"<<endl;
        }
    }
    return 0;
    

}