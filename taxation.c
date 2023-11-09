#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int car_type, seat_capacity, engine_capacity, year;
double CIF, gross_weight;

double ID, CIF, VAT, WHT;
int IL = 150000;
int SD = 35000;
int FF = 20000;
int ED = 200000;
int DPS = 700000;
int APS = 300000;

int car_age, transportation_mode, bond_duration, registration_type;


void carType(){
    scanf("%d", &car_type);
}

void userInput(){

    printf("1. Ambulance \n2. Estate \n3. Sedan \n4. SUV \n5. Trailer \n6. Other \n") ;
    printf("Enter a number that corresponds to the type of vehicle: ");
    scanf("%d", &car_type);
    
    // carType();
    // if(car_type > 0 && car_type <= 6){
    //     carType();
    // }else{
    //     printf("Invalid input! \n");
    // }


    printf("Enter the Cost Insurance and Freight: ");
    scanf("%lf", &CIF);

    printf("How many seats are in the car: ");
    scanf("%d", &seat_capacity);

    printf("What is the gross weight of the car: ");
    scanf("%lf", &gross_weight);

    printf("What is the engine capacity of the car: ");
    scanf("%d", &engine_capacity);

    printf("Enter the year of manufacture of the car: ");
    scanf("%d", &year);

    printf("1. Digital Plate System(DPS) \n2. Analog Plate System(APS)\n");

    printf("Whats your preferred registration type: ");
    scanf("%d", &registration_type);


    printf("1. Carrier bed vehicle. \n2. Driven the vehicle into the country. \n");
    printf("Which of the above forms did you use to get the vehicle into the country: ");
    scanf("%d", &transportation_mode);

    printf("Enter the number of days the car spent in the bond: ");
    scanf("%d", &bond_duration);

}

double transportation(){

    double roadtoll_tax;

    if(transportation_mode == 1){
        roadtoll_tax = 0.005 * CIF;
    }else if(transportation_mode == 2){
        roadtoll_tax = 0.015 * CIF;
    }else{
        printf("Invalid form of transportation entered!");
    }

    return roadtoll_tax;
}

double storage(){
    double storage_tax = 15000 * bond_duration;
    return storage_tax;
}

double registration(){

    double reg_tax;

     if(registration_type == 1){
        reg_tax = 700000;
    }else{
        reg_tax = 300000;
    }

    return reg_tax;
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
        netTax = tax1 + IL + transportation_tax + storage_tax;
    }else{
        double IL = 150000;
        netTax = tax1 + IL + transportation_tax + storage_tax;
    }
    

    return netTax;
}

double estate(){
   
   double ID = 0.25 * CIF, VAT = 0.18 * CIF, WHT = 0.06 * CIF;

   double seat_tax, car_weight_tax, engine_tax, car_age_tax;

   double reg_tax = registration();
   double storage_tax = storage();
   double roadtoll_tax = transportation();

    double tax1 = reg_tax + storage_tax + roadtoll_tax;
   
   int car_age = 2023 - year;

   double tax2 = ID + VAT + WHT + IL + SD + FF + ED;

   if(seat_capacity > 5){
         seat_tax = (seat_capacity - 5) * 250000;
   }else{
        seat_tax = 0.0;
   }


    if(gross_weight >= 1500 && gross_weight <= 2000){
        car_weight_tax = 0.05 * CIF;
    }else if(gross_weight > 2000){
        car_weight_tax = 0.1 * CIF;
    }else if(gross_weight < 1500){
        car_weight_tax = 0.02 * CIF;
    }else{}


   if(engine_capacity > 1800){
        engine_tax = 0.05 * CIF;
   }else{
        engine_tax = 0.025 * CIF;
   }

   if(car_age >= 1 && car_age <= 5){
        car_age_tax = 0.01 * CIF;
   }else if(car_age > 5 && car_age <= 10){
        car_age_tax = 0.05 * CIF;
   }else if(car_age > 10){
        car_age_tax = 0.15 * CIF;
   }else{
        car_age_tax = 0.0;
   }

    double tax3 = seat_tax + car_weight_tax + engine_tax + car_age_tax;

    double total_tax = tax1 + tax2 + tax3;
   
   return total_tax; 
}

double sedan(){

    double storage_tax = storage();
    double roadtoll_tax = transportation();

    double car_weight_tax, engine_tax, car_age_tax, total_tax;
    double ID = 0.25 * CIF, VAT = 0.18 * CIF, WHT = 0.06 * CIF;
    double tax1 = ID + VAT + WHT + IL + SD + FF + ED + DPS;
    int car_age = 2023 - year; 

if(car_age < 15){
    if(gross_weight >= 1500 && gross_weight <= 2000){
        car_weight_tax = 0.1 * CIF;
    }else if(gross_weight > 2000){
        car_weight_tax = 0.15 * CIF;
    }else if(gross_weight < 1500){
        car_weight_tax = 0.02 * CIF;
    }else{}

    if(engine_capacity > 2000){
        engine_tax = 0.1 * CIF;
   }else if(engine_capacity >= 1500 && engine_capacity <= 2000){
        engine_tax = 0.05 * CIF;
   }else if(engine_capacity < 1500){
        engine_tax = 0.025 * CIF;
   }else{}

   if(car_age >= 10 && car_age <= 15){
        car_age_tax = 0.1 * CIF;
   }else if(car_age > 5 && car_age <= 10){
        car_age_tax = 0.05 * CIF;
   }else if(car_age > 10){
        car_age_tax = 0.15 * CIF;
   }else{
        car_age_tax = 0.0;
   }
double tax2 = car_weight_tax + engine_tax + car_age_tax + storage_tax + roadtoll_tax;

total_tax = tax1 + tax2;

}else{
    printf("Sedans older than 15years cannot be imported into the country! \n");
    total_tax = 0.0;
}

    return total_tax;
}

double SUV(){

    double storage_tax = storage();
    double roadtoll_tax = transportation();

    double seat_tax, car_weight_tax, car_age_tax;

    double ID = 0.25 * CIF, VAT = 0.18 * CIF, WHT = 0.06 * CIF;
    double tax1 = ID + VAT + WHT + IL + SD + FF + ED + APS;
    int car_age = 2023 - year;

    if(seat_capacity > 5){
         seat_tax = (seat_capacity - 5) * 350000;
   }else{
        seat_tax = 0.0;
   }

   if(gross_weight >= 5000){
        car_weight_tax = 0.15 * CIF;
    }else{
        car_weight_tax = 0.0;
    }

    //engine_tax doesn't apply in SUVs


    if(car_age >= 1 && car_age <= 5){
        car_age_tax = 0.1 * CIF;
        }else if(car_age > 5 && car_age <= 10){
        car_age_tax = 0.15 * CIF;
        }else if(car_age > 10){
        car_age_tax = 0.25 * CIF;
        }else{
        car_age_tax = 0.0;
     }

     double tax2 = seat_tax + car_weight_tax + car_age_tax + roadtoll_tax + storage_tax;

     double total_tax = tax1 + tax2;

        return total_tax;
}

double trailer(){

    double ID = 0.25 * CIF, VAT = 0.18 * CIF, WHT = 0.06 * CIF;
    double tax1 = ID + VAT + WHT + IL + SD + FF + ED;
    int car_age = 2023 - year;

    double reg_tax = registration();
    double storage_tax = storage();
    double roadtoll_tax = transportation();

    double car_weight_tax, engine_tax, car_age_tax;


    if(gross_weight >= 15000 && gross_weight <= 20000){
        car_weight_tax = 0.15 * CIF;
    }else if(gross_weight > 20000){
        car_weight_tax = 0.25 * CIF;
    }else if(gross_weight < 15000){
        car_weight_tax = 0.05 * CIF;
    }else{}

    if(engine_capacity > 20000){
        engine_tax = 0.1 * CIF;
   }else if(engine_capacity >= 15000 && engine_capacity <= 20000){
        engine_tax = 0.05 * CIF;
   }else if(engine_capacity < 15000){
        engine_tax = 0.025 * CIF;
   }else{}

   if(car_age >= 10 && car_age <= 15){
        car_age_tax = 0.1 * CIF;
   }else if(car_age > 5 && car_age < 10){
        car_age_tax = 0.05 * CIF;
   }else if(car_age < 5){
        car_age_tax = 0.015 * CIF;
   }else{
        car_age_tax = 0.0;
   }

    double tax2 = car_weight_tax + engine_tax + car_age_tax + reg_tax + storage_tax + roadtoll_tax;

    double total_tax = tax1 + tax2;

    return total_tax;
}

double other(){

    double ID = 0.25 * CIF, VAT = 0.18 * CIF, WHT = 0.06 * CIF;
    double tax1 = ID + VAT + WHT + IL + SD + FF + ED;

    double reg_tax = registration();
    double storage_tax = storage();
    double roadtoll_tax = transportation();

    double tax2 = tax1 + roadtoll_tax + storage_tax + reg_tax;

    return tax2;
}

int main(){
    
    userInput();

    

    if(car_type == 1){
        printf("Ambulance tax is: %.3lf", ambulance());
    }else if(car_type == 2){
        printf("Estate tax is: %.3lf", estate());
    }else if(car_type == 3){
        printf("Sedan tax is: %.3lf", sedan());
    }else if(car_type == 4){
        printf("SUV tax is: %.3lf", SUV());
    }else if(car_type == 5){
        printf("Trailer tax is: %.3lf", trailer());
    }else if(car_type == 6){
        printf("The tax on your vehicle is: %.3lf", other());
    }else{}



    return 0;
}