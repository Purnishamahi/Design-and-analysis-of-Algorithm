#include <stdio.h>

#define MAX 100

struct Job
{
    int profit;
    int deadline;
};

// Sort jobs by profit (descending)
void sortJobs(struct Job jobs[], int n)
{
    struct Job temp;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(jobs[j].profit < jobs[j + 1].profit)
            {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int main()
{
    struct Job jobs[MAX];
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    // Input profits
    printf("\nEnter profits of %d jobs:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &jobs[i].profit);

    // Input deadlines
    printf("\nEnter deadlines of %d jobs:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &jobs[i].deadline);

    // Sort by profit
    sortJobs(jobs, n);

    // Find maximum deadline
    int maxDeadline = 0;
    for(int i = 0; i < n; i++)
        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int slots[MAX] = {0};   // stores profit in slot
    int totalProfit = 0;

    // Greedy scheduling
    for(int i = 0; i < n; i++)
    {
        for(int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if(slots[j] == 0)
            {
                slots[j] = jobs[i].profit;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output sequence
    printf("\nScheduled Slots:\n");
    for(int i = 0; i < maxDeadline; i++)
    {
        if(slots[i] == 0)
            printf("_ ");
        else
            printf("%d ", slots[i]);
    }

    printf("\n\nTotal Profit = %d\n", totalProfit);

    return 0;
}
