#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CAPACITY 100

struct Car {
    int carNumber;
    time_t entranceTime;
};


void carEntry(struct Car cars[], int *numCars) {
    if (*numCars < MAX_CAPACITY) {
        struct Car newCar;

        printf("Enter car number: ");
        scanf("%d", &newCar.carNumber);

        newCar.entranceTime = time(NULL);

        cars[*numCars] = newCar;
        (*numCars)++;

        printf("Car successfully entered the highway.\n");
    } else {
        printf("Highway capacity reached. Car cannot enter.\n");
    }
}

void displayCars(struct Car cars[], int numCars) {
    if (numCars == 0) {
        printf("No cars on the highway.\n");
    } else {
        printf("Cars on the highway:\n");
        for (int i = 0; i < numCars; i++) {
            printf("Car %d, Entrance Time: %s", cars[i].carNumber, ctime(&cars[i].entranceTime));
        }
    }
}

int main() {
    struct Car cars[MAX_CAPACITY];
    int numCars = 0;
    int choice;

    do {
        // Display menu
        printf("\nHighway Entrance System Menu:\n");
        printf("1. Car Entry\n");
        printf("2. Display Cars on the Highway\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                carEntry(cars, &numCars);
                break;
            case 2:
                displayCars(cars, numCars);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}
