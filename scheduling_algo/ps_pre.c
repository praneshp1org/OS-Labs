#include <stdio.h>
#include <stdbool.h>

struct Process {
    int processID;
    int burstTime;
    int priority;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(struct Process* processes, int n) {
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int highestPriority = -1;
        int highestPriorityIndex = -1;

        // Find the process with the highest priority and not yet completed
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0 && processes[i].priority > highestPriority) {
                highestPriority = processes[i].priority;
                highestPriorityIndex = i;
            }
        }

        if (highestPriorityIndex == -1) {
            currentTime++;
            continue;
        }

        // Execute the process with the highest priority for 1 unit of time
        processes[highestPriorityIndex].remainingTime--;
        currentTime++;

        // If the process is completed, calculate waiting and turnaround time
        if (processes[highestPriorityIndex].remainingTime == 0) {
            completedProcesses++;
            processes[highestPriorityIndex].waitingTime = currentTime - processes[highestPriorityIndex].burstTime;
            processes[highestPriorityIndex].turnaroundTime = currentTime;
        }
    }
}

void displayProcesses(struct Process* processes, int n) {
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].burstTime,
               processes[i].priority, processes[i].waitingTime, processes[i].turnaroundTime);
    }
}

void calculateAverageTimes(struct Process* processes, int n) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Enter priority (lower value indicates higher priority): ");
        scanf("%d", &processes[i].priority);
        processes[i].processID = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    calculateTimes(processes, n);
    displayProcesses(processes, n);
    calculateAverageTimes(processes, n);

    return 0;
}
