#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class DiningPhilosophers {
private:
    mutex mtx[5];                     // Mutex per fork
    mutex queue_mutex;               // Protects access to the queue
    condition_variable cv;
    queue<int> wait_queue;           // Queue to ensure fairness

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left = philosopher;
        int right = (philosopher + 1) % 5;

        {
            unique_lock<mutex> qlock(queue_mutex);
            wait_queue.push(philosopher);
        }

        // Wait until this philosopher is at the front of the queue
        unique_lock<mutex> qlock(queue_mutex);
        cv.wait(qlock, [&]() {
            return wait_queue.front() == philosopher;
        });

        // Lock both forks
        unique_lock<mutex> leftLock(mtx[left]);
        unique_lock<mutex> rightLock(mtx[right]);

        // Perform eating steps
        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();

        // Done eating, remove from queue
        wait_queue.pop();
        qlock.unlock();
        cv.notify_all(); // Wake up other waiting philosophers
    }
};