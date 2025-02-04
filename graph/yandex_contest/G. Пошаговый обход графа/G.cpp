#include <iostream>
#include <vector>
using namespace std;

int graph[100][100];
int visited[100];
vector<int> route;
int n;

void dfs(int v){
    visited[v] = 1;
    route.push_back(v);
    for(int i = 1;i<= n;++i){
        if(graph[v][i] == 1 && visited[i] == 0){
            dfs(i);
            route.push_back(v);
        }
    }
}


int main(){
    int m,v;
    cin >>n >> m >> v;

    int g,h;
    for(int i = 0;i<m;++i){
        cin >> g >> h;
        graph[g][h] = 1;
        graph[h][g] = 1;
    }


    dfs(v);

    cout << route.size() << endl;
    for(int i: route){
        cout << i << ' ';
    }


    return 0;
}
