#include <stdio.h>

int main() {
    int planTasks, doneTasks, postponed;
    int planHours, actualHours;
    int planBreak, actualBreak;
    int stressScore = 0;
    FILE *fp;
    int prevStress = 0;

    printf("SMART STRESS DETECTOR (Mismatch Based)\n");
    printf("--------------------------------------\n");

    printf("Planned tasks for today: ");
    scanf("%d", &planTasks);

    printf("Tasks completed: ");
    scanf("%d", &doneTasks);

    printf("Tasks postponed: ");
    scanf("%d", &postponed);

    printf("Planned work hours: ");
    scanf("%d", &planHours);

    printf("Actual work hours: ");
    scanf("%d", &actualHours);

    printf("Planned break time (minutes): ");
    scanf("%d", &planBreak);

    printf("Actual break time (minutes): ");
    scanf("%d", &actualBreak);

    if (planTasks > doneTasks)
        stressScore += (planTasks - doneTasks) * 3;

    if (actualHours > planHours)
        stressScore += (actualHours - planHours) * 2;

    if (actualBreak < planBreak)
        stressScore += (planBreak - actualBreak) * 2;

    stressScore += postponed * 3;

    fp = fopen("stress_log.txt", "r");
    if (fp != NULL) {
        fscanf(fp, "%d", &prevStress);
        fclose(fp);
    }

    fp = fopen("stress_log.txt", "w");
    fprintf(fp, "%d", stressScore);
    fclose(fp);

    printf("\nToday's Stress Score: %d\n", stressScore);

    if (stressScore < 10)
        printf("Stress Level: LOW 😊\n");
    else if (stressScore < 20)
        printf("Stress Level: MODERATE 😐\n");
    else
        printf("Stress Level: HIGH 😟\n");

    if (stressScore > prevStress)
        printf("Warning: Stress is increasing over days!\n");

    return 0;
}