#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = {1,-1,0,0,1,1,-1,-1};
int dy[] = {0,0,1,-1,1,-1,-1,1};

void print_board(char board[11][11])
{
    for(int y=1; y<=10;y++){
        for(int x=1; x<=10;x++)
        {
            cout<<board[y][x]<<' ';
        }
        cout<<std::endl;
    }
}

int main()
{
    char board [11][11];
    for(int i = 1; i<=10;i++){
        for(int j = 1; j<=10;j++){
            board[i][j] = '+';
        }
    }


    bool is_that_win = false;
    int count =0;

    while(!is_that_win)
    {
        print_board(board);
        int x,y;
        cout<<'x :';
        cin>>x;
        cout<<'y :';
        cin>>y;
        while(board[y][x]!='+')
        {
            cout<<"This is already placed"<<endl;
            cout<<'x :';
            cin>>x;
            cout<<'y :';
            cin>>y;
        }

        if(count%2==0)
        {
            board[y][x] = 'B';
        }

        else
        {
            board[y][x] = 'Y';
        }

        print_board(board);
        
        for(int y=1;y<=10;y++)
        {
            for(int x=1;x<=10;x++)
            {
                if(board[y][x]=='+')continue;
                bool visited [11][11] = {false};
                char now_color = board[y][x];
                visited[y][x] = true;

                /*
                int dx[] = {1,-1,0,0,1,1,-1,-1};
                int dy[] = {0,0,1,-1,1,-1,-1,1};
                */

                int direction[8] = {1,1,1,1,1,1,1,1};
                queue<pair<pair<int,int>,int>> haha;
                for(int i =0; i<8;i++)
                {
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];

                    if(new_x<1||new_x>10||new_y<1||new_y>10)continue;
                    if(visited[new_y][new_x])continue;
                    if(board[new_y][new_x]!=now_color)continue;

                    visited[new_y][new_x] = true;
                    direction[i]++;
                    haha.push({{new_x,new_y},i});
                }

                while(!haha.empty())
                {
                    auto now = haha.front();
                    haha.pop();

                    int NX = now.first.first + dx[now.second];
                    int NY = now.first.second + dy[now.second];

                    if(NX<1||NX>10||NY<1||NY>10)continue;
                    if(visited[NY][NX])continue;
                    if(board[NY][NX]!=now_color)continue;

                    visited[NY][NX] = true;
                    int vector = now.second;
                    direction[vector]++;
                    if(direction[vector]==5)
                    {
                        cout<<now_color<<" wins"<<endl;
                        is_that_win = true;
                        break;
                    }
                    haha.push({{NX,NY},vector});
                }
                if(is_that_win)break;
            }
            if(is_that_win)break;
        }
        if(count==100){
            cout<<"Not Wineer"<<endl;
            break;
        }
        count++;
    }
    return 0;
}
