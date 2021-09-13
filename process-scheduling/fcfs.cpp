#include<windows.h>
#include<iostream>
#include<stdio.h>
using namespace std;

struct process {
    int id;
    int time;
    int waitingTime = 0;
};

int main() {
    int numberOfProcess;
    process processes[100];
    
    cout<<"Enter number of process: ";
    cin>>numberOfProcess;

    for(int i = 0 ; i < numberOfProcess ; i++) {
        cout<<"Enter process id: ";
        cin>>processes[i].id;
        cout<<"Enter process running time: ";
        cin>>processes[i].time;
    }

    //process[0].waitingTime = 0;
    int waitingTime = 0;

    for(int i = 1 ; i < numberOfProcess ; i++){
        processes[i].waitingTime = waitingTime + processes[i-1].time;
        waitingTime += processes[i].waitingTime;
        cout<<"Process " <<i<<" has to wait " << processes[i].waitingTime<<endl;
    }
    cout<<"Average of waiting time: " <<waitingTime/numberOfProcess<<endl;
}