#include <stdio.h>

#define MAX_PROCESS 10

struct Process {
    int processID;
    int burstTime;
    int remainingTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(struct Process* processes, int n, int quantum) {
    int completedProcesses = 0;
    int currentTime = 0;
    int i;

    while (completedProcesses < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (processes[i].remainingTime <= quantum) {
                    currentTime += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                    processes[i].turnaroundTime = currentTime - processes[i].arrivalTime;
                    processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
                    completedProcesses++;
                } else {
                    currentTime += quantum;
                    processes[i].remainingTime -= quantum;
                }
            }
        }
    }
}

void displayProcesses(struct Process* processes, int n) {
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
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
    int quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESS) {
        printf("Invalid number of processes... Exiting.\n");
        return 1;
    }

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].processID = i + 1;
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);

    calculateTimes(processes, n, quantum);
    displayProcesses(processes, n);
    calculateAverageTimes(processes, n);

    return 0;
}
