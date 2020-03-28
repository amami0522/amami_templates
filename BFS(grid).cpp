#include<bits/stdc++.h>
using namespace std;

int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};

int main()
{
    char c;
	int h,w,sx,sy;
	queue<pair<int,int>> q;
	cin >> h >> w >> sy >> sx;
	vector<vector<int>> v(h,vector<int>(w,-1));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> c;
			if(c=='#') v[i][j]=-2;
		}
	}
	v[sy-1][sx-1]=0;
	q.push(make_pair(sy-1,sx-1));
	while(!q.empty()){
		pair<int,int> tmp=q.front();
		q.pop();

		for(int i=0;i<4;i++){
			int yy=tmp.first+dy[i];
			int xx=tmp.second+dx[i];
			if(yy<0 || yy>=h || xx<0 || xx>=w) continue;
			if(v[yy][xx]==-1){
				v[yy][xx]=v[tmp.first][tmp.second]+1;
				q.push(make_pair(yy,xx));
			}
		}
	}
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
			if(v[i][j]==-2) cout << "# ";
			else cout << v[i][j] << " ";
		}
        cout << endl;
    }
	return 0;
}

/*
sample

input
5 8       //h w
3 6       //start_y start_x
########
#.#....#
#.###..#
#......#
########

output
# # # # # # # #
# 7 # 3 2 1 2 #
# 6 # # # 0 1 #
# 5 4 3 2 1 2 #
# # # # # # # #

 */
