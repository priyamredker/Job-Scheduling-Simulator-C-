// Job Scheduling Simulator using Heap (without STL)
#include <iostream>
using namespace std;

#define MAX 50 // Maximum number of jobs

// Structure to store job info
struct Job {
    int id;
    int priority;
};

// Class for Job Scheduler using Max-Heap
class JobScheduler {
    Job heap[MAX];
    int size;

public:
    JobScheduler() { size = 0; }

    // Insert a new job into heap
    void addJob(int id, int priority) {
        if (size >= MAX) {
            cout << "Job queue full!\n";
            return;
        }
        heap[size].id = id;
        heap[size].priority = priority;
        int i = size;
        size++;

        // Move up (heapify-up)
        while (i > 0 && heap[(i - 1) / 2].priority < heap[i].priority) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        cout << "Added Job ID: " << id << " with Priority: " << priority << endl;
    }

    // Remove and run the job with highest priority
    void runNextJob() {
        if (size == 0) {
            cout << "No jobs to run.\n";
            return;
        }

        cout << "Running Job ID: " << heap[0].id
             << " with Priority: " << heap[0].priority << endl;

        heap[0] = heap[size - 1];
        size--;

        // Move down (heapify-down)
        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap[left].priority > heap[largest].priority)
                largest = left;
            if (right < size && heap[right].priority > heap[largest].priority)
                largest = right;

            if (largest == i)
                break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    // Display all jobs in heap
    void displayJobs() {
        if (size == 0) {
            cout << "No jobs in queue.\n";
            return;
        }
        cout << "\nCurrent Jobs:\n";
        for (int i = 0; i < size; i++)
            cout << "Job ID: " << heap[i].id
                 << "  Priority: " << heap[i].priority << endl;
    }
};

int main() {
    JobScheduler scheduler;
    int choice, id, priority;

    do {
        cout << "\n1. Add Job\n2. Run Next Job\n3. Display Jobs\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Job ID: ";
            cin >> id;
            cout << "Enter Job Priority: ";
            cin >> priority;
            scheduler.addJob(id, priority);
            break;

        case 2:
            scheduler.runNextJob();
            break;

        case 3:
            scheduler.displayJobs();
            break;

        case 4:
            cout << "Exiting...\n";
            break;
            
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
JnU9NDQ3MzA2OTY1MzEwMTYwODk3Jm49amFkaGF2aGFyc2guMjAyNCU0MGdtYWlsLmNvbSZlPWphZGhhdmhhcnNoLjIwMjQlNDBnbWFpbC5jb20meD0yMDI1MTIxMQDEdlOGgAhWADEAmO4tMYSl2aBNun9a8jPcpyMFlggty2jK0Tlq4uVhwkhFvaNwFvm_PVHeYjYRavjeKLfYPpflLXQWY3a9uCunGmhX_S77jlYcScSwFABwcoMsiQZR7EITX6rFpcijbm2KhFbVKCK4qlIYS1Lj26WWO_SXov3FZ5KyuDrjFEgejtuGyYAObV0OGedeY1CWrgWzTUMhCnLWAo83J3DYqo1xYdthIn3r0EfX6biavgd8eeknWGghiHZviUMWvYQjiMDXVXE0iyzK01ub5IuWFjShpoG5GqfSvFlayecNAmA6ttMQOi2GKwTG8BTNfdzr0XS0MIGKS7ndS2D