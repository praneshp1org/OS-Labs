#include <stdio.h>

struct Process {
    int processID;
    int burstTime;
    int priority;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(struct Process* processes, int n) {
    int totalWaitingTime = 0;
    processes[0].waitingTime = 0;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = 0;

        for (int j = 0; j < i; j++) {
            processes[i].waitingTime += processes[j].burstTime;
        }

        totalWaitingTime += processes[i].waitingTime;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
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
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrivalTime);
        processes[i].processID = i + 1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    calculateTimes(processes, n);
    displayProcesses(processes, n);
    calculateAverageTimes(processes, n);

    return 0;
}
