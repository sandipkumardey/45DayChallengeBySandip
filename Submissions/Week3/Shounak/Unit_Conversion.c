#include <stdio.h>

void lengthConversion();
void weightConversion();
void temperatureConversion();

int main() {
    int choice;

    while (1) {
        printf("\nUnit Conversion Menu:\n");
        printf("1. Length Conversion\n");
        printf("2. Weight Conversion\n");
        printf("3. Temperature Conversion\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void lengthConversion() {
    int choice;
    double value, convertedValue;

    printf("\nLength Conversion Menu:\n");
    printf("1. Meters to Centimeters (MKS to CGS)\n");
    printf("2. Centimeters to Meters (CGS to MKS)\n");
    printf("3. Feet to Meters (FPS to MKS)\n");
    printf("4. Meters to Feet (MKS to FPS)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            convertedValue = value * 100;  // Meters to Centimeters
            printf("%.2lf meters = %.2lf centimeters\n", value, convertedValue);
            break;
        case 2:
            convertedValue = value / 100;  // Centimeters to Meters
            printf("%.2lf centimeters = %.2lf meters\n", value, convertedValue);
            break;
        case 3:
            convertedValue = value * 0.3048;  // Feet to Meters
            printf("%.2lf feet = %.2lf meters\n", value, convertedValue);
            break;
        case 4:
            convertedValue = value / 0.3048;  // Meters to Feet
            printf("%.2lf meters = %.2lf feet\n", value, convertedValue);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void weightConversion() {
    int choice;
    double value, convertedValue;

    printf("\nWeight Conversion Menu:\n");
    printf("1. Kilograms to Grams (MKS to CGS)\n");
    printf("2. Grams to Kilograms (CGS to MKS)\n");
    printf("3. Pounds to Kilograms (FPS to MKS)\n");
    printf("4. Kilograms to Pounds (MKS to FPS)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            convertedValue = value * 1000;  
            printf("%.2lf kilograms = %.2lf grams\n", value, convertedValue);
            break;
        case 2:
            convertedValue = value / 1000;  
            printf("%.2lf grams = %.2lf kilograms\n", value, convertedValue);
            break;
        case 3:
            convertedValue = value * 0.453592;  
            printf("%.2lf pounds = %.2lf kilograms\n", value, convertedValue);
            break;
        case 4:
            convertedValue = value / 0.453592;  
            printf("%.2lf kilograms = %.2lf pounds\n", value, convertedValue);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void temperatureConversion() {
    int choice;
    double value, convertedValue;

    printf("\nTemperature Conversion Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the temperature: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            convertedValue = (value * 9/5) + 32;  
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, convertedValue);
            break;
        case 2:
            convertedValue = (value - 32) * 5/9;  
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, convertedValue);
            break;
        case 3:
            convertedValue = value + 273.15;  
            printf("%.2lf Celsius = %.2lf Kelvin\n", value, convertedValue);
            break;
        case 4:
            convertedValue = value - 273.15;  
            printf("%.2lf Kelvin = %.2lf Celsius\n", value, convertedValue);
            break;
        default:
            printf("Invalid choice!\n");
    }
}
