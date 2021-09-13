// Trong đoạn code này, chương trình chạy không được liên tục vì đoạn TestAndSet không phải là đoạn xử lý không tách rời (atomically)
// Do vậy, có thể rơi vào trường hợp cả producer và consumer check lock mà lock = true => chương trình bị lặp vô hạn, không đoạn nào
// có thể vào CRITICAL SECTION

// ==> Mấu chốt ở đây, đoạn TestAndSet phải là đoạn xử lý không tách rời (Khi chạy thì chạy hết mới dừng, không bị interupt bởi tt khác)

#include<iostream>
#include<windows.h>

using namespace std;

const int PRODUCER_WAITING_LIMIT = 2;
const int CONSUMER_WAITING_LIMIT = 5;

bool lock = false; // 0 - unlocked 1 - locked
const int BUFFER_SIZE = 6;
int currentSize = 0;

int random_time(int time) {
    return (rand() % (time+1)); 
}

bool TestAndSet(bool *target) {
    bool rv = *target;
    *target = true;
    return rv;
}

void producer() {
    while(true) {
        cout<<"Producer is ready ..."<<endl;
        while(TestAndSet(&lock));
        
        // CRITICAL SECTION - BEGIN
        while(currentSize < BUFFER_SIZE) {
            currentSize++;
            cout<<"Producing ..."<<endl;
            cout<<"Produce "<<currentSize<<" in buffer"<<endl;
        }
        if(currentSize == BUFFER_SIZE) {
            cout<<"Buffer is FULL"<<endl;
            cout<<"CAN NOT PRODUCE ANYMORE"<<endl;
        }
        // CRITICAL SECTION - END
        lock = false;
        int time = random_time(PRODUCER_WAITING_LIMIT);
        Sleep(time);
    }
}

void consumer() {
    while(true) {
        cout<<"Consumer is ready ..."<<endl;
        while(TestAndSet(&lock));
        
        // CRITICAL SECTION - BEGIN
        while(currentSize > 0) {
            currentSize--;
            cout<<"Consuming ..."<<endl;
            cout<<"Buffer has "<<currentSize<<" left"<<endl;
        }
        if(currentSize == 0) {
            cout<<"Buffer is EMPTY"<<endl;
            cout<<"CAN NOT CONSUME ANYMORE"<<endl;
        }
        // CRITICAL SECTION - END
        lock = false;
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