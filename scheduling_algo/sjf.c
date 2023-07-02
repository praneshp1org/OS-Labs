// Shortest Job First
#include <stdio.h>

struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
    int isCompleted;
};

void calculateTimes(struct Process* processes, int n) {
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int shortestIndex = -1;
        int shortestBurst = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted) {
                if (shortestIndex == -1 || processes[i].burstTime < shortestBurst) {
                    shortestIndex = i;
                    shortestBurst = processes[i].burstTime;
                }
            }
        }

        if (shortestIndex != -1) {
            struct Process* currentProcess = &processes[shortestIndex];

            currentProcess->waitingTime = currentTime - currentProcess->arrivalTime;
            currentProcess->turnaroundTime = currentProcess->waitingTime + currentProcess->burstTime;
            currentProcess->completionTime = currentTime + currentProcess->burstTime;
            currentProcess->isCompleted = 1;

            currentTime = currentProcess->completionTime;
            completedProcesses++;
        } else {
            currentTime++;
        }
    }
}

void displayProcesses(struct Process* processes, int n) {
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
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
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].processID = i + 1;
        processes[i].isCompleted = 0;
    }

    calculateTimes(processes, n);
    displayProcesses(processes, n);
    calculateAverageTimes(processes, n);

    return 0;
}
