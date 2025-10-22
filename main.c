#include <stdio.h>
#include "mylib.h"
#include "arraylib.h"



int main() {
    int choice, num;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Check Armstrong Number\n");
        printf("2. Check Adams Number\n");
        printf("3. Check Prime Palindrome Number\n");
        printf("4. Array Operations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        if (choice >= 1 && choice <= 3) {
            printf("Enter a number: ");
            scanf("%d", &num);
        }

        switch (choice) {
            case 1:
                if (isArmstrong(num))
                    printf("%d is an Armstrong number.\n", num);
                else
                    printf("%d is NOT an Armstrong number.\n", num);
                break;

            case 2:
                if (isAdams(num))
                    printf("%d is an Adams number.\n", num);
                else
                    printf("%d is NOT an Adams number.\n", num);
                break;

            case 3:
                if (isPrimePalindrome(num))
                    printf("%d is a Prime Palindrome number.\n", num);
                else
                    printf("%d is NOT a Prime Palindrome number.\n", num);
                break;

            case 4: {
                int arr[10], n;
                printf("Enter size of array: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);

                printf("\nArray Operations:\n");
                displayArray(arr, n);
                printf("Max Index: %d\n", findMaxIndex(arr, n));
                printf("Min Index: %d\n", findMinIndex(arr, n));
                printf("Average: %.2f\n", findAverage(arr, n));

                reverseArray(arr, n);
                printf("Reversed ");
                displayArray(arr, n);

                sortArray(arr, n);
                printf("Sorted ");
                displayArray(arr, n);

                int val;
                printf("Enter value to search: ");
                scanf("%d", &val);
                int pos = linearSearch(arr, n, val);
                if (pos != -1)
                    printf("Value found at index %d\n", pos);
                else
                    printf("Value not found.\n");
                break;
            }

            default:
                printf("Invalid choice! Please select between 1–5.\n");
        }

    } while (choice != 5);

    return 0;
}
