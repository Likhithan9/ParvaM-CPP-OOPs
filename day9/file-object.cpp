#include<iostream>
#include<fstream>
using namespace std; 
class Car{
    private:
       string brand, model, variant, features[10];
       int year, price,featureCount;
    public:
       void addCarDetails(string CarBrand, string carModel, string carVariant, int year, int price){
           brand = CarBrand;
           model = carModel;
           variant = carVariant;
           this->year = year;
           this->price = price; 
       }

       void addCarFeatures(int count){
            featureCount = count;
            cin.ignore(); // Add the line
            cout << "Enter the " << count << " features of the car: ";
            for(int i = 0; i < count; i++){
                cin.ignore();
                getline(cin, features[i]); // can enter mutliple words along with spaces
           } 
           cout << "Click Enter Button for Next Input" << endl; // Add this line 
        }
        void storeCarDetails(){
            ofstream store("Car_details.txt", ios::app); // Append the content to the existing file
            store << "The Car Details are as follows:" << endl;
            store << "Car Brand:" << brand << endl;
            store << "Car Model:" << model << endl;
            store << "Car Variant:" << variant << endl;
            store << "Launch Year:" << year << endl;
            store << "Offer Price: Rs," << price << endl;
            store << "car has these features: " << endl;
            for(int i = 0; i < featureCount; i++){
                store << "\t" << i+1 << ". " << features[i] << endl;
            }
            store << "----------------------------------------";
        }
    
};
int main(){
    string car_brand, car_model, car_variant, car_features[10];
    int features_count, launch_year, launch_price;
    cout << "Enter the Car Details: " << endl;
    cout << "Brand Model, Variant, Launch Year, Launch Price: " << endl;
    cout << "Ex: Tata, curvv, (Petrol/Diesel/Ev), 2025, 150000" << endl;
    cin >> car_brand >> car_model >> car_variant >> launch_year >> launch_price;
    
    cout << "Enter the Number of features: " << endl;
    cin >> features_count;
    
    Car car1;
    car1.addCarDetails(car_brand, car_model, car_variant, launch_year, launch_price);
    car1.addCarFeatures(features_count);
    car1.storeCarDetails();

    Car car2;
    car2.addCarDetails("Audi","Q6","Petrol",2019,1200005);
    car2.addCarFeatures(4);
    car2.storeCarDetails();



}
