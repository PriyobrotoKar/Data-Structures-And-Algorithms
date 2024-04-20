#include <iostream>
#include <queue>
using namespace std;

queue<int> rev(queue<int>  q){
    if(q.size()==1){
        return q;
    }

    int front=q.front();
    q.pop();
    q=rev(q);
    q.push(front);

    return q;
}

int main(){
    queue<int> q;

    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    q=rev(q);

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}