#include <stdio.h>
#include<string.h>
#define PHONE 12
#define SIZE 1000
#define MAX 100

struct Member {
    int id;
    char name[SIZE];
    char phoneNumber[PHONE];
};
struct Book {
    int bookID;
    char title[SIZE];
    char author[SIZE];
    int year;
    int memberID;
};
int bookCount = 0;
int memberCount = 0;
void displayMenu();
void addMember(Member members[]);
void addBook(Book books[], Member members[]);
void displayMembers(Member members[]);
void displayBooks(Book books[]);
int main()
{
    struct Member members[MAX];
    struct Book books[MAX];
    int choice, con = 1;

    while (con == 1) {
        displayMenu();
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            addMember(members);
            break;
        case 2:
            addBook(books, members);
            break;
        case 3:
            displayMembers(members);
            break;
        case 4:
            displayBooks(books);
            break;
        case 5:
            printf("Exiting the program.\n");
            con = 0;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void displayMenu() {
    printf("\nChoose one of the following option:\n");
    printf("1. to add new member\n");
    printf("2. to add new book\n");
    printf("3. to print all members\' information\n");
    printf("4. to print all books\' information\n");
    printf("5. to quit\n");
}

void addMember(Member members[]) {
    if (memberCount >= MAX) {
        printf("Member list is full!\n");
        return;
    }
    int memberID, flag = 1;
    while (1) {
        printf("Enter Member ID: ");
        scanf_s("%d%*c", &memberID);
        for (int i = 0; i < memberCount; i++) {
            if (members[i].id == memberID) {
                printf("Member ID already exists. Try again.\n");
                flag = 0;
                break;
            }
        }
        if (flag != 0) {
            break;
        }
        flag = 1;
    }
    members[memberCount].id = memberID;
    printf("Enter Name: ");
    fgets(members[memberCount].name, SIZE, stdin);
    char* current_pos = strchr(members[memberCount].name, '\n');
    *current_pos = '\0';
    printf("Enter Phone Number: ");
    scanf_s("%s", members[memberCount].phoneNumber, PHONE - 1);
    memberCount++;
    printf("Member added successfully!\n");
}
void addBook(Book books[], Member members[]) {
    if (bookCount >= MAX) {
        printf("Book limit reached.\n");
        return;
    }
    int memberID, bookID, flag = 1;
    while (1) {
        printf("Enter Book ID: ");
        scanf_s("%d%*c", &bookID);
        for (int i = 0; i < bookCount; i++) {
            if (books[i].bookID == bookID) {
                printf("Book ID already exists. Try again.\n");
                flag = 0;
                break;
            }
        }
        if (flag != 0) {
            break;
        }
        flag = 1;

    }
    books[bookCount].bookID = bookID;
    printf("Enter Title: ");
    fgets(books[bookCount].title, SIZE, stdin);// starting out with C\0
    char* current_pos = strchr(books[bookCount].title, '\n');
    *current_pos = '\0';
    printf("Enter Author: ");
    fgets(books[bookCount].author, SIZE, stdin);
    current_pos = strchr(books[bookCount].author, '\n');
    *current_pos = '\0';
    printf("Enter Year of Publication: ");
    scanf_s("%d", &books[bookCount].year);
    printf("Enter member id who borrowed book or 0 if not borrowed");
    scanf_s("%d", &memberID);
    while (memberID != 0) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i].id == memberID) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            break;
        }
        else {
            printf("Try again,Enter member id who borrowed book or 0 if not borrowed");
            scanf_s("%d", &memberID);
        }

    }
    books[bookCount].memberID = memberID;
    bookCount++;
    printf("Book added successfully!\n");
}
void displayMembers(Member members[]) {
    printf("%s%20s%20s%20s\n", "NO.", "Memeber ID", "Memeber Name", "Memeber Phone");
    for (int i = 0; i < memberCount; i++) {
        printf("%-12d%-19d%-20s%s\n", i + 1, members[i].id, members[i].name, members[i].phoneNumber);
        printf("-----------------------------------------------------------------\n");
    }
}
void displayBooks(Book books[]) {
    printf("|%s|%20s|%20s|%20s|%25s|%20s|\n", "NO.", "Book ID", "Book Title", "Book Author", "Publication Year", "Member ID");
    for (int i = 0; i < bookCount; i++) {
        printf("%-18d%-18d%-20s%-21s%-28d", i + 1, books[i].bookID, books[i].title, books[i].author, books[i].year);
        if (books[i].memberID == 0) {
            printf("Available\n");
        }
        else {
            printf("%d\n", books[i].memberID);
        }
        printf("--------------------------------------------------------------------------------------------------------------\n");
    }

}