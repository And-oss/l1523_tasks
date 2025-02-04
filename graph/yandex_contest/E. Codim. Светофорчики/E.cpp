#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int> > lst (n , vector<int>(n , 0));

    for(int i = 0;i<m;i++){
        int top, rd;
        cin >> top >> rd;

        lst[top-1][rd-1] = 1;
        lst[rd-1][top-1] = 1;
    }

    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(lst[i][j] == 1) cnt++;
        }
        cout << cnt << ' ';
        cnt = 0;
    }


    return 0;
}
