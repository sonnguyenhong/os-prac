#include<bits/stdc++.h>

using namespace std;

const int NUMBER_OF_PROCESSES = 5;
const int NUMBER_OF_RESOURCES = 3;
vector<int> safeChain;
int Available[NUMBER_OF_RESOURCES] = {3, 3, 2};
int Max[NUMBER_OF_PROCESSES][NUMBER_OF_RESOURCES] = { {7, 5, 3},
                                                        {3, 2, 2},
                                                        {9, 0, 2},
                                                        {2, 2, 2},
                                                        {4, 3, 3} };
int Allocation[NUMBER_OF_PROCESSES][NUMBER_OF_RESOURCES] = { {0, 1, 0},
                                                            {2, 0, 0},
                                                            {3, 0, 2},
                                                            {2, 1, 1},
                                                            {0, 0, 2} };
int Need[NUMBER_OF_PROCESSES][NUMBER_OF_RESOURCES];

typedef struct Process {
    int id;
    bool isFinish;
}Process;

vector<Process> processes;

void init() {
    for(int i = 0 ; i < NUMBER_OF_PROCESSES ; i++) {
        Process p = {i, false};
        processes.push_back(p);
    }
    
    for(int i = 0 ; i < NUMBER_OF_PROCESSES ; i++) {
        for(int j = 0 ; j < NUMBER_OF_RESOURCES ; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    for(int i = 0 ; i < NUMBER_OF_PROCESSES ; i++) {
        for(int j = 0 ; j < NUMBER_OF_RESOURCES ; j++) {
            cout<<Need[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i = 0; i < NUMBER_OF_PROCESSES ; i++) {
        cout<<processes[i].id<<" + "<<processes[i].isFinish<<endl;
    }
}

bool check() {
    int finished = 0;
    
    int prevSafeSize = 0;
    while(true) {
        for(int i = 0 ; i < NUMBER_OF_PROCESSES ; i++) {
            if(processes[i].isFinish) {
                continue;
            }
            int counter = 0;
            for(int j = 0 ; j < NUMBER_OF_RESOURCES ; j++) {
                if(Available[j] - Need[i][j] >= 0) {
                    counter++;
                }
            }
            if(counter == NUMBER_OF_RESOURCES) {
                finished++;
                processes[i].isFinish = true;
                safeChain.push_back(i);
                for(int k = 0 ; k < NUMBER_OF_RESOURCES ; k++) {
                    Available[k] += Allocation[i][k];
                }
            }
        }
        if(prevSafeSize == safeChain.size()) {
            break;
        } else {
            prevSafeSize = safeChain.size();
        }
    }
    if(finished == NUMBER_OF_PROCESSES) {
        return true;
    } else {
        return false;
    }
}


int main() {
    init();
    if(check()){
        cout<<"OK day"<<endl;
    }else {
        cout<<"VL roi"<<endl;
    }
    for(int i = 0; i < safeChain.size() ; i++){
        cout<<safeChain[i]<<endl;
    }
}