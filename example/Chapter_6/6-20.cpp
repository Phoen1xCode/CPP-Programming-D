#include <iostream>
#include <vector>
using namespace std;

double average(const vector<double>&arr);

int main(){
    unsigned int n = 5;

    vector<double>arr(n);
    cout << "Please input " << n << "real numbers:" << endl;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Average = " << average(arr) << endl;    
    return 0;
}

double average(const vector<double>&arr){
    double sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }
    return sum/arr.size();
}