#include "..\head.h"

mutex mymutex;
condition_variable cv;
int flag = 0;

void printA() {
    unique_lock<mutex> lk(mymutex);
    int cnt = 0;
    while (cnt < 10) {
        while (flag != 0) {
            cv.wait(lk);
        }
        cout << "thread 1: A" << endl;
        flag = 1;
        cv.notify_all();
        cnt ++;
    }
    cout << "my thread 1 finish" << endl;
}

void printB() {
    unique_lock<mutex> lk(mymutex);
    int cnt = 0;
    for (int i = 0; i < 10; ++i) {
        while (flag != 1) {
            cv.wait(lk);
        }
        cout << "thread 2: B" << endl;
        flag = 2;
        cv.notify_all();
    }
    cout << "my thread 1 finish" << endl;
}

void printC() {
    unique_lock<mutex> lk(mymutex);
    int cnt = 0;
    for (int i = 0; i < 10; ++i) {
        while (flag != 2) {
            cv.wait(lk);
        }
        cout << "thread 3: C" << endl;
        flag = 0;
        cv.notify_all();
    }
    cout << "my thread 1 finish" << endl;
}

int main() {
    thread t2(printA);
    thread t1(printB);
    thread t3(printC);
    t1.join();
    t2.join();
    t3.join();
    cout << "main thread" << endl;

}