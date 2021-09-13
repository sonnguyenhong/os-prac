#include<iostream>
using namespace std;

typedef struct process {
    int id;
    int time;
    int arrivedTime;
    int remainTime;
    int waitingTime = 0;
}process;

int main() {
    int numberOfProcess;
    process processes[100];

    int currentTime = 0;
    int completedProcess = 0;
    int minTime = INT_MAX;
    int minTimeIndex = 0;

    cout<<"Enter number of processes: ";
    cin>>numberOfProcess;

    for(int i = 0 ; i < numberOfProcess ; i++) {
        cout<<"Enter process id: ";
        cin>>processes[i].id;
        cout<<"Enter process running time: ";
        cin>>processes[i].time;
        cout<<"Enter arrived time: ";
        cin>>processes[i].arrivedTime;
        processes[i].remainTime = processes[i].time;    
    }

    cout<<"Process ---- Running time ---- Arrived time"<<endl;
    for(int i = 0 ; i < numberOfProcess ; i++) {
        cout<<"P"<<processes[i].id<<"             "<<processes[i].time<<"             "<<processes[i].arrivedTime<<endl;
    }
    
    while (completedProcess != numberOfProcess) {
        bool check = false;
        for(int i = 0 ; i < numberOfProcess ; i++) {
            if((processes[i].arrivedTime <= currentTime) && (processes[i].remainTime > 0) && processes[i].remainTime < minTime) {
                minTime = processes[i].remainTime;
                minTimeIndex = i;
                check = true;
            }
        }
        
        if(!check) {
            currentTime++;
            continue;
        }

        processes[minTimeIndex].remainTime--;
        cout<< "P" << processes[minTimeIndex].id << " is running..."<<endl;
        
        if(processes[minTimeIndex].remainTime == 0) {
            int finishTime = currentTime + 1;
            completedProcess++;
            minTime = INT_MAX;
            processes[minTimeIndex].waitingTime = finishTime - processes[minTimeIndex].time - processes[minTimeIndex].arrivedTime;
            cout<< "P" << processes[minTimeIndex].id << " finished and waiting time: " << processes[minTimeIndex].waitingTime<<endl;
        } 

        currentTime++;
    }
}