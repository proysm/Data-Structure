//--------------------------------------------------------------------
//
//  Laboratory B, In-lab Exercise 1                       ossim.cs
//
//  컴퓨터공학과 2021111954 유수민
//  (Shell) Operating system task scheduling simulation
//
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>
#include "ptyqueue.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//

struct TaskData
{
    int priority,              // Task's priority
        arrived;               // Time when task was enqueued

    void setPty(int newPty)
        { priority = newPty; }   // Set the priority

    int pty () const
        { return priority; }   // Returns the priority
};

//--------------------------------------------------------------------

void main ()
{
    PtyQueue<TaskData> taskPQ;   // Priority queue of tasks
    TaskData task;               // Task
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        numPtyLevels,            // Number of priority levels
        numArrivals;             // Number of new tasks arriving
    
    
    int zeroLng = 0;
    int oneLng = 0;
    srand(500);

    cout << endl << "Enter the number of priority levels : ";
    cin >> numPtyLevels;

    cout << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    

    for ( minute = 0 ; minute < simLength ; minute++ )
    {
        
        cout << endl << "Current minute = " << minute << endl;

        // Dequeue the first task in the queue (if any).
        if (!taskPQ.isEmpty())
        {
            TaskData temp = taskPQ.dequeue();
            cout << "Task Dequeued" << endl;
            cout << "This task's priority: " << temp.pty() << endl;
            cout << "This task was arrived at " << temp.arrived
                << ", and waited for " << minute - temp.arrived << " minutes." << endl;
            if (temp.pty() == 1)
            {
                if (minute - temp.arrived > oneLng) oneLng = minute - temp.arrived;
            }
            else if(temp.pty() == 0)
            {
                if (minute - temp.arrived > zeroLng) zeroLng = minute - temp.arrived;
            }
        }

        // Determine the number of new tasks and add them to
        // the queue.
       
        if (!taskPQ.isFull())
        {
            numPtyLevels = rand() % 4; // 0 ~ 3

            if (numPtyLevels == 1 || numPtyLevels == 2)
            {
                
                for (int i = 0; i < numPtyLevels; i++)
                {
                    numArrivals = rand() % 2; // 0 or 1
                    task.arrived = minute;
                    task.setPty(numArrivals); 
                    taskPQ.enqueue(task);
                    //cout << "Here " << task.arrived << endl;
                    
                }
                cout << "Adding " << numPtyLevels << " task" << endl;
            }
            else
            {
                cout << "No task was added this time" << endl;
            }
        }
    
        taskPQ.showStructure();
    
    }
    cout << "Longest wait for any low-priority(0) task: " << zeroLng << endl;
    cout << "Longest wait for any high-priority(1) task: " << oneLng << endl;
    system("pause");
}
