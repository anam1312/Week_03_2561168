#include <stdio.h>
#include <string.h>

#define STUDENTS 10
#define SUBJECTS 5

struct Student {
    int roll;
    char name[50];
    int marks[SUBJECTS];
    int total;
    float average;
};

int main() {
    struct Student s[STUDENTS];
    int i, j;

    // Input
    for (i = 0; i < STUDENTS; i++) {
        printf("\nEnter details of Student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;
        for (j = 0; j < SUBJECTS; j++) {
            printf("Marks of Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }
        s[i].average = s[i].total / (float)SUBJECTS;
    }

    // Display Result
    printf("\n\n--- Student Result ---\n");
    printf("Roll\tName\t\tTotal\tAverage\n");
    for (i = 0; i < STUDENTS; i++) {
        printf("%d\t%-10s\t%d\t%.2f\n",
               s[i].roll, s[i].name, s[i].total, s[i].average);
    }

    // Top 3 Rank Students
    printf("\n--- Top 3 Rank Students ---\n");
    for (i = 0; i < 3; i++) {
        int maxIndex = i;
        for (j = i + 1; j < STUDENTS; j++) {
            if (s[j].average > s[maxIndex].average) {
                maxIndex = j;
            }
        }
        struct Student temp = s[i];
        s[i] = s[maxIndex];
        s[maxIndex] = temp;

        printf("Rank %d: %s (Average: %.2f)\n",
               i + 1, s[i].name, s[i].average);
    }

    // Highest marks in each subject
    printf("\n--- Highest Marks in Each Subject ---\n");
    for (j = 0; j < SUBJECTS; j++) {
        int maxMarks = s[0].marks[j];
        int index = 0;
        for (i = 1; i < STUDENTS; i++) {
            if (s[i].marks[j] > maxMarks) {
                maxMarks = s[i].marks[j];
                index = i;
            }
        }
        printf("Subject %d: %s (%d marks)\n",
               j + 1, s[index].name, maxMarks);
    }

    return 0;
}
