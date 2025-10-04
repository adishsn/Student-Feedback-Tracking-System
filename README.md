# Student-Feedback-Tracking-System

Description:
This C program manages student feedback for courses using a singly linked list. It allows adding feedback, searching by course or student, calculating average ratings for a course, and displaying all feedback. Each feedback record contains Student ID, Course Code, Rating, and Comments.

Features:
1. Add Feedback – Add a feedback entry with Student ID, Course Code, Rating, and Comments.
2. Search by Course – View all feedback for a specific course.
3. Search by Student – View all feedback given by a specific student.
4. Calculate Average Rating – Compute the average rating for a course.
5. Display All Feedback – Show all feedback records.
6. Exit – Close the program.

How it Works:
- Uses a struct Feedback with fields: Student ID, Course Code, Rating, Comments, and a pointer to the next node.
- Linked list dynamically stores feedback records.
- New feedback entries are added to the head of the list.
- Provides a menu-driven interface for easy operation.

Compilation and Execution:
gcc studentsrecord_feedback.c -o studentsrecord_feedback
./studentsrecord_feedback

Sample Input/Output:
Enter choice: 1
Enter Student ID: 101
Enter Course Code: CS101
Enter Rating (1-5): 5
Enter Comments: Excellent course
Feedback added successfully!

Enter choice: 5
All Feedback Entries:
StudentID: 101 | Course: CS101 | Rating: 5 | Comments: Excellent course
