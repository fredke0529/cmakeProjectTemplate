// src/main.cpp
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <Eigen/Dense>
#include "math.h"

using namespace std;
using namespace Eigen;
__thread int i = 1;

void *thread1(void *arg);
void *thread2(void *arg);
void *cal(void *arg);

int main()
{
    pthread_t pthread1;
    pthread_t pthread2;
    pthread_create(&pthread1, NULL, thread1, NULL);
    pthread_create(&pthread2, NULL, thread2, NULL);
    pthread_join(pthread1, NULL);
    pthread_join(pthread2, NULL);
    cal(NULL);
    cout << "math add result: " << add(1, 1) << endl;
    return 0;
}
void *thread1(void *arg)
{
    cout << ++i << endl; // 输出 2
    return NULL;
}
void *thread2(void *arg)
{
    sleep(1);            // 等待thread1完成更新
    cout << ++i << endl; // 输出 2，而不是3
    return NULL;
}
void *cal(void *arg)
{
    Vector4d v1;
    v1 << 1, 2, 3, 4;
    cout << "v1=\n"
         << v1 << endl;
    return NULL;
}