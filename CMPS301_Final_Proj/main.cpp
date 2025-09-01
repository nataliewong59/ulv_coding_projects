//
//  main.cpp
//  finalProject
//
//  Created by Natalie Wong on 30/3/2024.
//

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//function to write food items and ratings to current menu text file
    void writeToTextFile(string food, string date, string rating, string totalRating, string numOfRatings, int count){
        ofstream file;
        if (count == 0){
            file.open("currentMenu.txt", ios::out);
            file<<food<<","<<date<<","<<rating<<","<<totalRating<<","<<numOfRatings<<"\n";
        }
        else{
            file.open("currentMenu.txt", ios::app);
            file<<food<<","<<date<<","<<rating<<","<<totalRating<<","<<numOfRatings<<"\n";
        }
        file.close();
    }

//function to write food items to past menu text file
    void writeToMenuHistory(string food, string date, string rating, string totalRating, string numOfRatings){
        ofstream file;
        file.open("menuHistory.txt", ios::app);
        file<<food<<","<<date<<","<<rating<<","<<totalRating<<","<<numOfRatings<<"\n";
        file.close();
    }

//function for staff to view current menu and change menu items
    void changeMenuFunc(){
        string staffResponse;
        string date;
        string foodName;
        bool valid = false;
        int menuLength;
        
        //declare food item structure
            struct foodItem{
                string food;
                string date;
                string rating;
                string totalRatings;
                string numOfRatings;
            }foodArray[100];
        
            cout<<"Here is the current menu and ratings:"<<endl;
        
        //read and print menu from text file
            string textLine;
            fstream file;
            file.open("currentMenu.txt");
            
            //split read lines into their respective structure components
                int i = 0;
                while (getline(file, textLine)){
                    stringstream text(textLine);
                    getline(text,foodArray[i].food,',');
                    getline(text,foodArray[i].date,',');
                    getline(text,foodArray[i].rating,',');
                    getline(text,foodArray[i].totalRatings,',');
                    text >> foodArray[i].numOfRatings;
                    i++;
                }
            file.close();
            
            for (int n = 0; n<i; n++)
            {
                cout << "\nFood = " << foodArray[n].food;
                cout << "\nDate = " << foodArray[n].date;
                cout << "\nAverage Rating = " << foodArray[n].rating;
                cout << "\nTotal Rating = " << foodArray[n].totalRatings;
                cout << "\nNumber Of Ratings = " << foodArray[n].numOfRatings<< '\n';
            }
        
        //conditional to ask if staff wants to change current menu
            cout<<"Would you like to change the menu items?"<<endl;
            cin>>staffResponse;
            
            while (valid == false){
                if (staffResponse == "yes" || staffResponse == "Yes"){
                    valid = true;
                
                //save old menu data to menu history text file
                    for (int j = 0; j < i; j++){
                        writeToMenuHistory(foodArray[j].food, foodArray[j].date, foodArray[j].rating, foodArray[j].totalRatings, foodArray[j].numOfRatings);
                    }
                
                //initialize and print new food array (updated menu)
                    cout<<"Please enter the date and number of menu items you would like to have:"<<endl;
                    cin>>date>>menuLength;
                    
                    for (int j = 0; j < menuLength; j++){
                        cout<<"Please enter the name of item "<<j+1<<endl;
                        cin.ignore();
                        getline(cin,foodName);
                        
                        writeToTextFile(foodName, date, "0", "0", "0", j);
                    }
                    
                    cout<<"Here is the updated menu:"<<endl;
                    
                //read and print new menu from text file
                    string textLine;
                    fstream file;
                    file.open("currentMenu.txt");
                    
                    i = 0;
                    while (getline(file, textLine)){
                        stringstream text(textLine);
                        getline(text,foodArray[i].food,',');
                        getline(text,foodArray[i].date,',');
                        getline(text,foodArray[i].rating,',');
                        getline(text,foodArray[i].totalRatings,',');
                        text >> foodArray[i].numOfRatings;
                        i++;
                    }
                    file.close();
                    
                    for (int n = 0; n<i; n++)
                    {
                        cout << "\nFood = " << foodArray[n].food;
                        cout << "\nDate = " << foodArray[n].date;
                        cout << "\nAverage Rating = " << foodArray[n].rating;
                        cout << "\nTotal Rating = " << foodArray[n].totalRatings;
                        cout << "\nNumber Of Ratings = " << foodArray[n].numOfRatings<< '\n';
                    }
                }
                else if (staffResponse == "no" || staffResponse == "No"){
                    valid = true;
                }
                else {
                    cout<<"The answer you entered was invalid. please enter yes or no"<<endl;
                    cin >> staffResponse;
                }
            }
        }

//function for staff to view menu history and oragnize it
    void sortArray(){
        
        //declare food item structure
            struct foodItem{
                string food;
                string date;
                string rating;
                string totalRatings;
                string numOfRatings;
            }foodArray[100];
        
        cout<<"Here is every past dish served and ratings sorted by date:"<<endl;
        
        //read and print menu from text file
            string textLine;
            fstream file;
            file.open("menuHistory.txt");
            
            //split read lines into their respective structure components
                int i = 0;
                while (getline(file, textLine)){
                    stringstream text(textLine);
                    getline(text,foodArray[i].food,',');
                    getline(text,foodArray[i].date,',');
                    getline(text,foodArray[i].rating,',');
                    getline(text,foodArray[i].totalRatings,',');
                    text >> foodArray[i].numOfRatings;
                    i++;
                }
            file.close();
            
            for (int n = 0; n<i; n++)
            {
                cout << foodArray[n].food << ", " << foodArray[n].date << ", Average Rating = " << foodArray[n].rating << ", Total Rating = " << foodArray[n].totalRatings << " Number Of Ratings = " << foodArray[n].numOfRatings<< '\n';
            }
        
        //ask staff if they want to organize the information differently
        string sortType;
        bool valid = false;
        cout<<"Would you like to sort the menu in alphabetical or rating order? Or type 'exit' to exit"<<endl;
        
        while(valid == false){
            cin>>sortType;
            //rearrange alphabetically
            if (sortType == "alphabetical" || sortType == "Alphabetical"){
                valid = true;
                for (int j = i; j > 0; j--){
                    for (int k = 0; k < j-1; k++){
                        if (foodArray[k].food > foodArray[k+1].food){
                            foodItem temp = foodArray[k];
                            foodArray[k] = foodArray[k+1];
                            foodArray[k+1] = temp;
                            
                        }
                    }
                }
                for (int n = 0; n<i; n++)
                {
                    cout << foodArray[n].food << ", " << foodArray[n].date << ", Average Rating = " << foodArray[n].rating << ", Total Rating = " << foodArray[n].totalRatings << " Number Of Ratings = " << foodArray[n].numOfRatings<< '\n';
                }
            }
            //rearrange by rating
            else if (sortType == "rating" || sortType == "Rating"){
                valid = true;
                for (int j = i; j > 0; j--){
                    for (int k = 0; k < j-1; k++){
                        if (foodArray[k].rating < foodArray[k+1].rating){
                            foodItem temp = foodArray[k];
                            foodArray[k] = foodArray[k+1];
                            foodArray[k+1] = temp;
                            
                        }
                    }
                }
                for (int n = 0; n<i; n++)
                {
                    cout << foodArray[n].food << ", " << foodArray[n].date << ", Average Rating = " << foodArray[n].rating << ", Total Rating = " << foodArray[n].totalRatings << " Number Of Ratings = " << foodArray[n].numOfRatings<< '\n';
                }
            }
            else if (sortType == "exit" || sortType == "Exit"){
                valid = true;
            }
            if (valid == false){
                cout<<"\nThe answer you entered is invalid. Please input 'alphabetical', 'rating', or 'exit'."<<endl;
            }
        }
        
    }

//function to verify staff password
    void staffPasswordFunc(){
        string password;
        bool valid = false;
        
        cout<<"Please enter the password to make changes to the daily menu:"<<endl;
        cin>>password;
        
        while (valid == false){
            if (password == "password"){
                valid = true;
                changeMenuFunc();
                sortArray();
            }
            else if (password == "exit" || password == "Exit"){
                valid = true;
            }
            else{
                cout<<"The password you entered was incorrect, please try again or type \"exit\" to exit the program"<<endl;
                cin>>password;
            }
        }
    }


//function for customer to rate food
    void customerRateFunc(){
        
        string foodName;
        bool valid = false;
        int customerRating = 0;
        
        //food item structure
            struct foodItem{
                string food;
                string date;
                string rating;
                string totalRatings;
                string numOfRatings;
            }foodArray[100];
        
        //read menu from text file
            cout<<"Here is a list of foods being served today: "<<endl;
            
            string textLine;
            fstream file;
            file.open("currentMenu.txt");
            
            int i = 0;
            while (getline(file, textLine)){
                stringstream text(textLine);
                getline(text,foodArray[i].food,',');
                getline(text,foodArray[i].date,',');
                getline(text,foodArray[i].rating,',');
                getline(text,foodArray[i].totalRatings,',');
                text >> foodArray[i].numOfRatings;
                i++;
            }
            file.close();
            
            for (int n = 0; n<i; n++)
            {
                cout<<foodArray[n].food<<endl;
            }
        
        //user enters a food item that was displayed in the list above and then rates it
        cin.ignore();
        while (valid == false){
            cout<<"\nPlease enter the food item you would like to rate: "<<endl;
                getline(cin,foodName);
                
                for (int n = 0; n < i; n++){
                    if (foodName == foodArray[n].food){
                        valid = true;
                        
                        while (customerRating < 1 || customerRating > 5){
                            cout<<"Please enter your rating from 1-5 for "<<foodName<<endl;
                            cin>>customerRating;
                            
                            if (customerRating >= 1 && customerRating <=5){
                                cout<<"You rated "<<foodName<<" "<<customerRating<<" out of 5. Thank you for your feedback"<<endl;
                                
                                foodArray[n].totalRatings = to_string(stoi(foodArray[n].totalRatings) + customerRating);
                                foodArray[n].numOfRatings = to_string(stoi(foodArray[n].numOfRatings) + 1);
                            
                            //calculate average rating
                                string avgRating = to_string(stod(foodArray[n].totalRatings)/stod(foodArray[n].numOfRatings));
                                foodArray[n].rating = avgRating;
                            }
                        //write to text file
                            for (int j = 0; j < i; j++){
                                writeToTextFile(foodArray[j].food, foodArray[j].date, foodArray[j].rating, foodArray[j].totalRatings, foodArray[j].numOfRatings, j);
                            }
                    }
                    
                }
            }
            if (valid == false){
                cout<<"\nThe food you entered is not on the menu"<<endl;
            }
        }
}

int main() {
    //declare and initialize variables
        bool valid = false;
        string identity;
    
    //determine whether user is staff or customer
        cout<<"Welcome to The Spot Dining Hall's Feedback Form"<<endl;
        cout<<"Are you a customer or staff?"<<endl;
        cin>>identity;
        
        while (valid == false){
            if (identity == "customer" || identity == "Customer"){
                valid = true;
                customerRateFunc();
            }
            else if (identity == "staff" || identity == "Staff"){
                valid = true;
                staffPasswordFunc();
            }
            else {
                cout<<"The answer you entered was invalid. please enter if you are a customer or staff"<<endl;
                cin >> identity;
            }
        }
    
    
    return 0;
}


