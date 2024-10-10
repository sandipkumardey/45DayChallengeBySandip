#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 5

typedef struct {
    char category[20];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count);
void viewExpenses(Expense expenses[], int count);
void viewCategoryTotal(Expense expenses[], int count);

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Total by Category\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                viewCategoryTotal(expenses, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }

    printf("Enter expense category (e.g., food, transport, entertainment): ");
    scanf("%s", expenses[*count].category);
    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added successfully.\n");
}

void viewExpenses(Expense expenses[], int count) {
    printf("\nAll Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("Category: %s, Amount: %.2f\n", expenses[i].category, expenses[i].amount);
    }
}

void viewCategoryTotal(Expense expenses[], int count) {
    float categoryTotals[MAX_CATEGORIES] = {0};
    char categories[MAX_CATEGORIES][20] = {"food", "transport", "entertainment", "utilities", "others"};
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < MAX_CATEGORIES; j++) {
            if (strcmp(expenses[i].category, categories[j]) == 0) {
                categoryTotals[j] += expenses[i].amount;
                break;
            }
        }
    }

    printf("\nTotal Expenses by Category:\n");
    for (int j = 0; j < MAX_CATEGORIES; j++) {
        printf("%s: %.2f\n", categories[j], categoryTotals[j]);
    }
}
