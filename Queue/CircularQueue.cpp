#include <iostream>
#define MAX_SIZE 10;
using namespace std;

class CircularQueue{
    int front,rear;
    int *arr;
public:
    CircularQueue(){
        int size=MAX_SIZE;
        this->front=-1;
        this->rear=-1;
        this->arr=new int[size];
    }

    bool enqueue(int data){
        if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[rear]=data;
            return true;
        }      

        rear=(rear+1)%MAX_SIZE;
        if(rear==front){
            return false;
        }
        arr[rear]=data;
        return true;
    }

    int dequeue(){
        if(front==-1 && rear==-1){
            return -1;
        }
        if(rear==front){
            int temp=arr[front];
            front=rear=-1;
            return temp;
        }

        int temp=arr[front];
        front=(front+1)%MAX_SIZE;
        return temp;
    }

};

int main(){
    CircularQueue q;

    q.enqueue(3);
    q.enqueue(10);
    q.enqueue(1);
    cout<<q.dequeue()<<endl;;
    cout<<q.dequeue()<<endl;;
    cout<<q.dequeue()<<endl;;
    cout<<q.dequeue()<<endl;;
    
}