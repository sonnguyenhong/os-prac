#include<iostream>
#include<windows.h>

using namespace std;

const int BUFFER_SIZE = 5;
const int PRODUCER_WAITING_LIMIT = 2;
const int CONSUMER_WAITING_LIMIT = 10;

int currentSize = 0;

int i = 0; //consumer
int j = 1; //producer
int turn = 0;
bool flag[2];

void init_flag() {
    flag[i] = false;
    flag[j] = false;
}

int random_time(int time) {
    return (rand() % (time+1)); 
}

void producer() {
    while(true) {
        flag[j] = true;
        cout<<"Producer is ready ... "<<endl;
        while(flag[i] == true && turn == i);

        // CRITICAL SECTION - BEGIN
        if(currentSize < BUFFER_SIZE) {
            currentSize++;
            cout<<"Producer is producing ..."<<endl;
            cout<<"Produced "<<currentSize<<" in buffer"<<endl;
        }
        if(currentSize == BUFFER_SIZE) {
            cout<<"Buffer is FULL with size: "<<BUFFER_SIZE<<" CANNOT PRODUCT ANYMORE"<<endl;
        }
        // CRITICAL SECTION - END
        flag[j] = false;
        int wait = random_time(PRODUCER_WAITING_LIMIT);
        Sleep(wait);
    }
}

void consumer() {
    while(true) {
        flag[i] = true;
        cout<<"Consumer is ready ..."<<endl;
        while(flag[j] == true && turn == j);
        
        //CRITICAL SECTION - BEGIN
        if(currentSize > 0) {
            currentSize--;
            cout<<"Consumer is consumming ..."<<endl;
            cout<<"Consumed ..."<<endl;
        }
        if(currentSize == 0) {
            cout<<"Buffer is empty. CANNOT CONSUMED ANYMORE"<<endl;
        }
        //CRITICAL SECTION - END
        flag[i] = false;
        int wait = random_time(CONSUMER_WAITING_LIMIT);
        Sleep(wait);
    }
}

int main() {
    init_flag();
    HANDLE h1, h2;
    DWORD Id;
    h1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) producer, NULL, 0, &Id);
    h2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) consumer, NULL, 0, &Id);
    WaitForSingleObject(h1, INFINITE);
    WaitForSingleObject(h2, INFINITE);
    return 0;
}