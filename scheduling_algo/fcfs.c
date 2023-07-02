#include <stdio.h>

struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(struct Process* processes, int n) {
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime - processes[i].arrivalTime;

        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        
        if (processes[i].waitingTime < 0)
            processes[i].waitingTime = 0; 
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
    }

    calculateTimes(processes, n);
    displayProcesses(processes, n);
    calculateAverageTimes(processes, n);

    return 0;
}
