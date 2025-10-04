#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Feedback {
    int studentID;
    char courseCode[20];
    int rating;
    char comments[100];
    struct Feedback *next;
};

struct Feedback *head = NULL;

void addFeedback(int studentID, char courseCode[], int rating, char comments[]) {
    struct Feedback *newnode = (struct Feedback*)malloc(sizeof(struct Feedback));
    newnode->studentID = studentID;
    strcpy(newnode->courseCode, courseCode);
    newnode->rating = rating;
    strcpy(newnode->comments, comments);
    newnode->next = head;
    head = newnode;
    printf("\nFeedback added successfully!\n");
}


void searchByCourse(char courseCode[]) {
    struct Feedback *temp = head;
    int found = 0;
    printf("\nFeedback for Course %s:\n", courseCode);
    while (temp != NULL) {
        if (strcmp(temp->courseCode, courseCode) == 0) {
            printf("StudentID: %d | Rating: %d | Comments: %s\n",
            temp->studentID, temp->rating, temp->comments);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("No feedback found for this course.\n");
}

void searchByStudent(int studentID) {
    struct Feedback *temp = head;
    int found = 0;
    printf("\nFeedback by Student %d:\n", studentID);
    while (temp != NULL) {
        if (temp->studentID == studentID) {
            printf("Course: %s | Rating: %d | Comments: %s\n",
            temp->courseCode, temp->rating, temp->comments);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("No feedback found for this student.\n");
}


void averageRating(char courseCode[]) {
    struct Feedback *temp = head;
    int total = 0, count = 0;
    while (temp != NULL) {
        if (strcmp(temp->courseCode, courseCode) == 0) {
            total += temp->rating;
            count++;
        }
        temp = temp->next;
    }
    if (count == 0) {
        printf("\nNo feedback for this course.\n");
    } else {
        printf("\nAverage Rating for %s: %.2f\n", courseCode, (float)total / count);
    }
}


void displayAll() {
    struct Feedback *temp = head;
    if (temp == NULL) {
        printf("\nNo feedback records available.\n");
        return;
    }
    printf("\nAll Feedback Entries:\n");
    while (temp != NULL) {
        printf("StudentID: %d | Course: %s | Rating: %d | Comments: %s\n",
        temp->studentID, temp->courseCode, temp->rating, temp->comments);
        temp = temp->next;
    }
}

int main() {
    int choice, studentID, rating;
    char courseCode[20], comments[100];

    do {
        printf("\n--- Student Feedback Tracking System ---\n");
        printf("1. Add Feedback\n");
        printf("2. Search by Course\n");
        printf("3. Search by Student\n");
        printf("4. Calculate Average Rating\n");
        printf("5. Display All Feedback\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Student ID: ");
            scanf("%d", &studentID);
            printf("Enter Course Code: ");
            scanf("%s", courseCode);
            printf("Enter Rating (1-5): ");
            scanf("%d", &rating);
            printf("Enter Comments: ");
            scanf(" %[^\n]", comments);
            addFeedback(studentID, courseCode, rating, comments);
            break;

        case 2:
            printf("Enter Course Code: ");
            scanf("%s", courseCode);
            searchByCourse(courseCode);
            break;

        case 3:
            printf("Enter Student ID: ");
            scanf("%d", &studentID);
            searchByStudent(studentID);
            break;

        case 4:
            printf("Enter Course Code: ");
            scanf("%s", courseCode);
            averageRating(courseCode);
            break;

        case 5:
            displayAll();
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}
