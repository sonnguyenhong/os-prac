#include<iostream>
using namespace std;

typedef struct Process {
    int id;
    int time;
    int priority;
    int arrivalTime;
    int isFinish;
    int finishTime;
}Process;

// return true if a > b
// return false if a <= b
int compare(Process a, Process b) {
    if(a.priority == b.priority) {
        return a.arrivalTime < b.arrivalTime ? 1 : 0;
    } else {
        return a.priority < b.priority ? 1 : 0;
    }
}

int main() {
    int numberOfProcess;
    Process processes[100];
    cout<<"Enter number of processes: ";
    cin>>numberOfProcess;

    for(int i = 0 ; i < numberOfProcess ; i++) {
        cout<<"Enter process id: ";
        cin>>processes[i].id;
        cout<<"Enter process time: ";
        cin>>processes[i].time;
        cout<<"Enter process arrival time: ";
        cin>>processes[i].arrivalTime;
        cout<<"Enter process priority: ";
        cin>>processes[i].priority;
        processes[i].isFinish = 0;
        processes[i].finishTime = INT_MAX;
    }

    int currentTime = 0;
    int completed = 0;
    Process running;
    int runningIndex;
    
    while(completed != numberOfProcess){
        running.id = 0;
        running.time = 0;
        running.finishTime = INT_MAX;
        running.priority = INT_MAX;
        running.arrivalTime = INT_MAX;
        running.isFinish = 0;
        for(int i = 0 ; i < numberOfProcess ; i++) {
            if(compare(processes[i], running) && (currentTime >= processes[i].arrivalTime) && (processes[i].isFinish == 0)){
                running.id = processes[i].id;
                running.time = processes[i].time;
                running.finishTime = processes[i].time;
                running.arrivalTime = processes[i].arrivalTime;
                running.priority = processes[i].priority;
                running.isFinish = 0;
                runningIndex = i;
            }
        }
        
        processes[runningIndex].finishTime = currentTime + processes[runningIndex].time;
        completed++;
        currentTime = processes[runningIndex].finishTime;
        processes[runningIndex].isFinish = 1;
        cout<<"P"<<processes[runningIndex].id<<" finished at "<<processes[runningIndex].finishTime<<endl;
    }
}