
#include <stdio.h>

float sales[12];
char *monthNames[]={
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

void read_file(char *filename, char *monthNames[], float sales[], int numOfMonths){
    int monthIndex =0;
    FILE *file=fopen(filename, "r");
    printf("\nMonthly sales report for 2024: \n");
    printf("\nMonth     Sales\n");

    for (int i=0; i < 12; i++){
        fscanf(file, "%f", &sales[monthIndex]);
        monthIndex++;
    }
    int counter=0;
    for (int i=0; i < 12; i++){
        printf("%-9s $%.2f\n", monthNames[counter], sales[counter]);
        counter++;
    }
    fclose(file);
}

void calc_min(){
    float min_sales = sales[0];
    int lowest_sale_month = 0;
    for (int i=0; i < 12; i++){
        if (sales[i] < min_sales){
            min_sales = sales[i];
            lowest_sale_month = i;
        }
    }
    printf("\nSales summary report:\n");
    printf("\nMinimum sales: $%.2f (%s)\n", min_sales, monthNames[lowest_sale_month]);

}

void calc_max(){
    float max_sales = sales[0];
    int highest_sale_month = 0;
    for (int i = 0; i < 12; i++){
        if (sales[i] > max_sales){
            max_sales = sales[i];
            highest_sale_month = i;
        }
    }
    printf("Maximum sales: $%.2f (%s)\n", max_sales, monthNames[highest_sale_month]);
}

void calc_avg(){
    float total = 0;
    for (int i = 0; i < 12; i++){
        total += sales[i];
    }
    printf("Average sales: $%.2f\n", total/12);
}

void moving_avg(){
    printf("\nSix-Month moving average report:\n");
    int i;
    float total;
    for (int i = 5; i < 12; i++){
        float total = 0;
        for (int j = i-5; j<=i; j++)
            total += sales[j];
        printf("%-9s-%-9s $%.2f\n", monthNames[i-5], monthNames[i], total/6);
    }
}

void high_to_low(){
    printf("\nSales report (highest to lowest): \n");
    printf("\nMonth     Sales\n");
    float sortedSales[12];
    char* sortedMonths[12];
    int j;
    int i;
    for (i=0; i<12; i++){
        sortedSales[i] = sales[i];
        sortedMonths[i] = monthNames[i];
    }
    for (i=0; i<12-1; i++){
        for (j=i+1; j<12; j++){
            if (sortedSales[i] < sortedSales[j]){
                float tempSales = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSales;
                
                char* tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = tempMonth;
            }
        }
    }
    for (i=0; i<12; i++){
        printf("%-9s $%.2f\n", sortedMonths[i], sortedSales[i]);
    }
}

int main(){
    char user_file[256];
    printf("Enter the name of the input file: ");
    scanf("%255s", user_file);
    read_file(user_file, monthNames, sales, 12);
    calc_min();
    calc_max();
    calc_avg();
    moving_avg();
    high_to_low();
}
