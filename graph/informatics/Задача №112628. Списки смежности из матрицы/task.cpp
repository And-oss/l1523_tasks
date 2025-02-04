#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int> > arr(n , vector<int>(n , 0));


    vector<vector<int> > spisok(n);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;++j){
            cin >> arr[i][j];
        }
    }

    for(int i = 0;i<n;++i){
        bool flag=false;
        for(int j = 0;j<n;++j){
            if(arr[i][j] == 1){
                spisok[i].push_back(j+1);
                flag=true;
            }
        }
        if(!flag) spisok[i].push_back(0);

    }

    for(auto i: spisok){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}