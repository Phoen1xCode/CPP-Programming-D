#include<bits/stdc++.h>

using namespace std;

// num 表示移动圆盘的数量，source、target、auxiliary 分别表示起始柱、目标柱和辅助柱

void move(char source,char target){
    cout << source << "-->" << target << endl;
}


// hanoi() let num plates move from source to target by anxiliary
void hanoi(int num,char source,char anxiliary,char target){
    if(num==1)
        move(source,target);
    else{

        hanoi(num-1,source,target,anxiliary);

        move(source,target);

        hanoi(num-1,anxiliary,source,target);


    }
}

int main(){
    int num;

    cin >> num;

    hanoi(num,'A','B','C');

    return 0;
}