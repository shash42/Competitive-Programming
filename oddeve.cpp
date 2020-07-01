#include<bits/stdc++.h>

#define int long long

using namespace std;

int iterations = 1e5, score[2], chk=1e4;

int W = 1, N = 6;
int get0()
{
    return 1 + rand()%N;
}
int get1()
{
    return N;
}
void play(int plnum)
{
    int wickets=0;
    while(wickets<W)
    {
        int g[2] = {get0(), get1()};
        if(g[0]==g[1]) wickets++;
        else score[plnum]+=g[plnum];
    }
}
signed main()
{
    cout << setprecision(20);
    double avg = 0;
    int l2 = 0;
    srand(time(NULL));
    for(int i = 0; i < iterations; i++)
    {
        if(i && i%chk==0)
        {
            cout << 1 - (double) l2/chk << endl;
            l2=0;
        }
        score[0]=score[1]=0;
        play(0);
        play(1);
      //  cout << score[0] << " " << score[1] << " - " << (score[0]>score[1]) << endl;
        avg += (double) score[1]/score[0];
        if(score[0]>score[1]) l2++;
    }
    cout << avg/iterations;
}