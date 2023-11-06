#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int car_type, seat_capacity, engine_capacity, year;
double CIF, gross_weight;

double ID, VAT, WHT;
int IL = 150000;
int SD = 35000;
int FF = 20000;
int ED = 200000;
int DPS = 700000;
int APS = 300000;

int car_age, transportation_mode, bond_duration, registration;


void userInput(){

    printf("1. Ambulance \n2. Estate \n3. Sedan \n4. SUV \n5. Trailer \n6. Other \n") ;
    
    printf("Enter a number that corresponds to the type of vehicle: ");
    scanf("%d", &car_type);

    printf("Enter the Cost Insurance and Freight: ");
    scanf("%lf", &CIF);

    // printf("How many seats are in the car: ");
    // scanf("%d", &seat_capacity);

    // printf("What is the gross weight of the car; ");
    // scanf("%lf", &gross_weight);

    // printf("What is the engine capacity of the car: ");
    // scanf("%d", &engine_capacity);

    printf("Enter the year of manufacture of the car: ");
    scanf("%d", &year);

    Printf("1. Digital Plate System(DPS) \n2. Analog Plate System(APS)\n");
    printf("Whats your preferred registration type: ");
    scanf("%d", &registration);


    printf("1. Carrier bed vehicle. \n2. Driven the vehicle into the country. \n");
    printf("Which of the above forms did you use to get the vehicle into the country: ");
    scanf("%d", &transportation_mode);

    printf("Enter the number of days the car spent in the bond: ");
    scanf("%d", &bond_duration);

}

double transportation(){
    if(transportation_mode == 1){
        double roadtoll_tax = 0.005 * CIF;
        return roadtoll_tax;
    }else if(transportation_mode == 2){
        double roadtoll_tax = 0.015 * CIF;
        return roadtoll_tax;
    }else{
        printf("Invalid form of transportation entered!");
    }

    return 0;
}

double storage(){
    double storage_tax = 15000 * bond_duration;
    return storage_tax;
}

double registration(){

     if(registration == 1){
        double DPS_tax = 700000;
        return DPS_tax;
    }else{
        double APS_tax = 300000;
        return APS_tax;
    }

    return 0;
}

double ambulance(){

    //Ambulances are exempted from paying ID, VAT, WHT

    int car_age = 2023 - year;
    double tax1 = ((double)SD + FF + ED + DPS);
    double netTax;
    double transportation_tax = transportation();
    double storage_tax = storage();

    if(car_age > 10){
        double IL = 0.15 * CIF;
        double netTax = tax1 + IL + transportation_tax + storage_tax;
        return netTax;
    }else{
        double IL = 150000;
        double netTax = tax1 + IL + transportation_tax + storage_tax;
        return netTax;
    }
    

    return netTax;
}

double estate(){
   
   double reg_tax = registration();
   double storage_tax = storage();
   double roadtoll_tax = transportation();
   
   double tax = ID + VAT + WHT + IL + SD + FF + ED;

   
   
   

    
}


int main(){
    
    userInput();

    printf("Ambulance tax is: %.3lf", ambulance());



    return 0;
}