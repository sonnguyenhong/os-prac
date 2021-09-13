#include<iostream>
using namespace std;

typedef struct Process {
    int id;
    int time;
    int remainTime;
    //int runningTime[100];
}Process;

const int RUNNING_TIME = 4;

int main(){
    int numberOfProcess;
    Process processes[100];
    int completed = 0;
    int currentTime = 0;

    cout<<"Enter number of processes: ";
    cin>>numberOfProcess;

    for(int i = 0 ; i < numberOfProcess ; i++) {
        cout<<"Enter process id: ";
        cin>>processes[i].id;
        cout<<"Enter process running time: ";
        cin>>processes[i].time;
        processes[i].remainTime = processes[i].time;
    }

    while(completed != numberOfProcess) {
        for(int i = 0 ; i < numberOfProcess ; i++) {
            
            if(processes[i].remainTime < RUNNING_TIME && processes[i].remainTime > 0) {
                cout<<"P"<<processes[i].id<<" is running"<<endl;
                currentTime += processes[i].remainTime;
                completed++;
                cout<<"P"<<processes[i].id<<" finished"<<endl;
                processes[i].remainTime = 0;
            } else if(processes[i].remainTime > 0){
                cout<<"P"<<processes[i].id<<" is running"<<endl;
                processes[i].remainTime -= RUNNING_TIME;
                if(processes[i].remainTime == 0) {
                    cout<<"P"<<processes[i].id<<" finished"<<endl;
                    completed++;
                }
                currentTime += RUNNING_TIME;
            }
        }
    }
}