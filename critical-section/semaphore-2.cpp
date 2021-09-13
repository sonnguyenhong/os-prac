#include<iostream>
#include<windows.h>

using namespace std;

int semaphore = 1;
int full = 0;   //Initailly, no slot is full
int empty = 5;  //Initially, all slot is empty

const int PRODUCER_WAITING_LIMIT = 2;
const int CONSUMER_WAITING_LIMIT = 10;

int random_time(int time) {
    return (rand() % (time+1)); 
}

// p(s)
void wait(int s) {
    while(s <= 0);
    s--;
}

// v(s)
void signal(int s) {
    s++;
}

void producer(){
    while(true){
        cout<<"Producer is ready ..."<<endl;
        wait(empty);
        //wait(semaphore);
        // CRITICAL SECTION - BEGIN
        cout<<"Produced ..."<<endl;
        // CRITICAL SECTION - END
        //signal(semaphore);
        signal(full);
        int time = random_time(PRODUCER_WAITING_LIMIT);
        Sleep(time);
    }
}

void consumer() {
    while(true) {
        cout<<"Consumer is ready ..."<<endl;
        wait(full);
        //wait(semaphore);
        // CRITICAL SECTION - BEGIN
        cout<<"Consumed ..."<<endl;
        // CRITICAL SECTION - END
        //signal(semaphore);
        signal(empty);
        int time = random_time(CONSUMER_WAITING_LIMIT);
        Sleep(time);
    }
}

int main() {
    HANDLE h1, h2;
    DWORD Id;
    h1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) producer, NULL, 0, &Id);
    h2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) consumer, NULL, 0, &Id);
    WaitForSingleObject(h1, INFINITE);
    WaitForSingleObject(h2, INFINITE);
    return 0;
}