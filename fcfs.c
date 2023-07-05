#include <stdio.h>

void calculateWaitingTime(int processes[], int n, int burst_time[], int waiting_time[])
{
    waiting_time[0] = 0; // Waiting time for  first process is always 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }
}

void calculateTurnaroundTime(int processes[], int n, int burst_time[], int waiting_time[], int turnaround_time[])
{
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
}

void calculateAverageTimes(int processes[], int n, int burst_time[])
{
    int waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0;

 calculateWaitingTime(processes, n, burst_time, waiting_time);
    calculateTurnaroundTime(processes, n, burst_time, waiting_time, turnaround_time);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++)
    {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];

        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2lf", avg_waiting_time);
    printf("\nAverage TurnAround Time: %.2lf", avg_turnaround_time);
}
void main()
{
    int n; // Number of processes

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    // Input burst time for each process
    printf("\nEnter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }

    calculateAverageTimes(processes, n, burst_time);
}
