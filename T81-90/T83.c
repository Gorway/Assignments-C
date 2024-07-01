#include <stdio.h>


double convert_units(double value, char from_unit, char to_unit) {
    if (from_unit == 'k' && to_unit == 'g') {
       
        return value * 1000.0;
    } else if (from_unit == 'm' && to_unit == 'k') {
       
       return value * 0.001;
    } else {
        
        printf("Wrong action\n");
        return -1.0;
    }
}

int main() {
    double value;
    char from_unit, to_unit;

    printf("Enter value and unit(Example.՝ 10 kg): ");
    scanf("%lf %c", &value, &from_unit);

    printf("Enter unit you want to calculate(Example.՝ g): ");
    scanf(" %c", &to_unit);


    double result = convert_units(value, from_unit, to_unit);
    if (result != -1.0) {
        printf("%lf %c =  %lf %c\n", value, from_unit, result, to_unit);
    }

    return 0;
}

