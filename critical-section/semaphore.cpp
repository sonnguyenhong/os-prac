#include<iostream>
#include<windows.h>

using namespace std;

int semaphore = 1;
int BUFFER_SIZE = 5;
int currentSize = 0;

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
        wait(semaphore);
        // CRITICAL SECTION - BEGIN

        if(currentSize < BUFFER_SIZE) {
            currentSize++;
            cout<<"Producer is producing ..."<<endl;
            cout<<"Produced "<<currentSize<<" in buffer"<<endl;
        }
        if(currentSize == BUFFER_SIZE) {
            cout<<"Buffer is FULL"<<endl;
            cout<<"CANNOT PRODUCE ANYMORE"<<endl;
        }

        // CRITICAL SECTION - END
        signal(semaphore);
        int time = random_time(PRODUCER_WAITING_LIMIT);
        Sleep(time);
    }
}

void consumer() {
    while(true) {
        cout<<"Consumer is ready ..."<<endl;
        wait(semaphore);
        // CRITICAL SECTION - BEGIN

        if(currentSize > 0) {
            currentSize--;
            cout<<"Consumer is consuming ..."<<endl;
            cout<<"Buffer has "<<currentSize<<" left"<<endl;
        }
        if(currentSize == 0) {
            cout<<"Buffer is EMPTY"<<endl;
            cout<<"CANNOT CONSUME ANYMORE"<<endl;
        }

        // CRITICAL SECTION - END
        signal(semaphore);
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