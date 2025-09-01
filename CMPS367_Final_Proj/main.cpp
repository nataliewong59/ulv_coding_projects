#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct User {
    string fullName;
    string age;
    vector<string> interests;
    string major;
    string password;
};

// Function prototypes
void selectInterest(User &user);
void createProfile(User &user);
void retrieveProfiles(vector<User> &profiles);
User* login(vector<User> &profiles);
void displayProfile(const User &user);
void searchProfiles(const vector<User> &profiles);
void sortProfiles(vector<User> &profiles);

int main() {
    vector<User> profiles;
    retrieveProfiles(profiles); // Load profiles from file at the start
    
    
    while (true) {
        cout << "\nWelcome! Choose an option:\n";
        cout << "1. Sign Up\n";
        cout << "2. Log In\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        string choice;
        cin>>choice;
        cin.ignore();
        
        if (choice == "1") {
            User newUser;
            createProfile(newUser);
            profiles.push_back(newUser); // Add the new profile to the in-memory list
        } else if (choice == "2") {
            User* loggedInUser = login(profiles);
            if (loggedInUser) {
                cout << "\nLogin successful! Welcome, " << loggedInUser->fullName << ".\n";
                
                // Menu for logged-in users
                while (true) {
                    cout << "\nChoose an option:\n";
                    cout << "1. View Profile\n";
                    cout << "2. Search Profiles\n";
                    cout << "3. Sort Profiles\n";
                    cout << "4. Log Out\n";
                    cout << "Enter your choice: ";
                    
                    cin >> choice;
                    cin.ignore();
                    
                    if (choice == "1") {
                        displayProfile(*loggedInUser);
                    } else if (choice == "2"){
                        searchProfiles(profiles);
                    } else if (choice == "3"){
                        sortProfiles(profiles);
                    } else if (choice == "4") {
                        cout << "\nLogged out successfully.\n";
                        break;
                    } else {
                        cout << "\nInvalid choice. Please try again.\n";
                    }
                }
            } else {
                cout << "\nLogin failed. Please check your credentials.\n";
            }
        } else if (choice == "3") {
            cout << "\nExiting the program. Goodbye!\n";
            break;
        } else {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
    
    return 0;
}

void selectInterest(User &user) {
    string input;
    cout << "Select an interest (enter a number or more and press enter):\n";
    cout << "1. Art\n2. Music\n3. Gaming\n4. Sports\n5. Technology\n6. Other\n";
    cout << "Enter the number corresponding to your interest(s): ";
    
    cin.ignore();
    getline(cin, input);
    for (char &ch : input) {
        if (ch == ',') ch = ' ';
    }
    
    stringstream ss(input);
    int choice;
    while (ss >> choice) {
        switch (choice) {
            case 1: user.interests.push_back("Art"); break;
            case 2: user.interests.push_back("Music"); break;
            case 3: user.interests.push_back("Gaming"); break;
            case 4: user.interests.push_back("Sports"); break;
            case 5: user.interests.push_back("Technology"); break;
            case 6: user.interests.push_back("Other"); break;
            default: cout << "Invalid choice, skipping.\n"; break;
        }
    }
}

void createProfile(User &user) {
    cout << "Enter your full name: ";
    getline(cin, user.fullName);
    
    cout << "Enter your age: ";
    cin >> user.age;
    
    selectInterest(user);
    
    cout << "What is your major? ";
    getline(cin, user.major);
    
    cout << "Enter a password: ";
    cin >> user.password;
    
    ofstream outFile("user_profile.txt", ios::app);
    if (outFile.is_open()) {
        outFile << user.fullName << "\n";
        outFile << user.age << "\n";
        for (size_t i = 0; i < user.interests.size(); ++i) {
            outFile << user.interests[i] << (i < user.interests.size() - 1 ? "," : "");
        }
        outFile << "\n";
        outFile << user.major << "\n";
        outFile << user.password << "\n";
        outFile.close();
        cout << "Profile saved successfully.\n";
    } else {
        cout << "Error saving profile.\n";
    }
}

void retrieveProfiles(vector<User> &profiles) {
    ifstream inFile("user_profile.txt");
    if (!inFile.is_open()) return;
    
    string line;
    while (getline(inFile, line)) {
        User user;
        user.fullName = line;
        
        getline(inFile, line);
        user.age = line;
        
        getline(inFile, line);
        stringstream ss(line);
        string interest;
        while (getline(ss, interest, ',')) {
            user.interests.push_back(interest);
        }
        
        getline(inFile, line);
        user.major = line;
        
        getline(inFile, line);
        user.password = line;
        
        profiles.push_back(user);
    }
    inFile.close();
}

User* login(vector<User> &profiles) {
    string name, password;
    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Enter your password: ";
    cin >> password;
    
    for (User &user : profiles) {
        if (user.fullName == name && user.password == password) {
            return &user;
        }
    }
    return nullptr;
}

void displayProfile(const User &user) {
    cout << "\nUser Profile:\n";
    cout << "Name: " << user.fullName << "\n";
    cout << "Age: " << user.age << "\n";
    cout << "Interests: ";
    for (size_t i = 0; i < user.interests.size(); ++i) {
        cout << user.interests[i] << (i < user.interests.size() - 1 ? ", " : "\n");
    }
    cout << "Major: " << user.major << "\n";
}

void searchProfiles(const vector<User> &profiles) {
    string searchTerm;
    cout << "Enter a search term (e.g., name, major, interest): ";
    cin.ignore();
    getline(cin, searchTerm);
    
    cout << "\nSearch Results:\n";
    for (const User &user : profiles) {
        if (user.fullName.find(searchTerm) != string::npos || user.major.find(searchTerm) != string::npos) {
            displayProfile(user);
        } else {
            for (const string &interest : user.interests) {
                if (interest.find(searchTerm) != string::npos) {
                    displayProfile(user);
                    break;
                }
            }
        }
    }
}

void sortProfiles(vector<User> &profiles) {
    int sortChoice;
    cout << "\nHow would you like to sort the profiles?\n";
    cout << "1. By Name\n2. By Age\n3. By Major\n";
    cout << "Enter your choice: ";
    cin >> sortChoice;
    
    switch (sortChoice) {
        case 1:
            sort(profiles.begin(), profiles.end(), [](const User &a, const User &b) {
                return a.fullName < b.fullName;
            });
            break;
        case 2:
            sort(profiles.begin(), profiles.end(), [](const User &a, const User &b) {
                return a.age < b.age;
            });
            break;
        case 3:
            sort(profiles.begin(), profiles.end(), [](const User &a, const User &b) {
                return a.major < b.major;
            });
            break;
        default:
            cout << "Invalid choice. Profiles will not be sorted.\n";
            return;
    }
    
    cout << "\nProfiles sorted successfully.\n";
    for (const User &user : profiles) {
        displayProfile(user);
    }
}
