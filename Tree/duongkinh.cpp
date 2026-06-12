#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m,x,y,frt,ans,cnt[100005],deg[100005];
queue<int>qe;
vector<int>dske[100005];
int bfs(int x)
{
    queue<int> qe;
    int frt,nhat=-1,nhi=-1,mx=-1;
    cnt[x]=0;
    qe.push(x);
    while(!qe.empty())
    {
        frt=qe.front();
        for(int i:dske[frt])
        {
            if(cnt[i]==-1)//nhieu cai && qua thi if chung luon.
            {
                cnt[i]=cnt[frt]+1;
                if(deg[i]==2)
                {
                    qe.push(i);
                }
                else if(deg[i]==1)
                {
                    if(cnt[i]>nhat) nhi=nhat,nhat=cnt[i];
                    else if(cnt[i]>nhi) nhi=cnt[i];
                }
                else
                {
                    mx=bfs(i)+cnt[frt]+1;
                    if(mx>nhat) nhi=nhat,nhat=mx;
                    else if(mx>nhi) nhi=mx;
                }
            }
        }
        qe.pop();
    }
    ans=max(ans,nhat+nhi);
    return nhat;
}
int main()
{
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        cout<<1;
        return 0;
    }
    fill(cnt+1,cnt+n+1,-1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        dske[x].push_back(y);
        dske[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]>1)
        {
            bfs(i);
            cout<<ans;
            return 0;
        }
    }
}