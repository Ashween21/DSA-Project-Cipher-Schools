#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

// Class representing a User
class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    User() {}
    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }
};

// Global maps for users and friendships
map<string, User> mapUserName;
map<string, set<string>> Friends;

// Function to add a user
void addUser() {
    string userName, firstName, lastName, gender;
    int age;

    cout << "Enter username: ";
    cin >> userName;

    if (mapUserName.find(userName) != mapUserName.end()) {
        cout << "Username already taken." << endl;
        return;
    }

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter gender: ";
    cin >> gender;

    User user(firstName, lastName, age, gender);
    mapUserName[userName] = user;
    cout << "User added successfully: " << userName << endl;
}

// Function to make two users friends
void makeThemFriend() {
    string userName1, userName2;

    cout << "Enter first user's username: ";
    cin >> userName1;
    cout << "Enter second user's username: ";
    cin >> userName2;

    if (mapUserName.find(userName1) == mapUserName.end() ||
        mapUserName.find(userName2) == mapUserName.end()) {
        cout << "One or both users do not exist." << endl;
        return;
    }

    Friends[userName1].insert(userName2);
    Friends[userName2].insert(userName1);
    cout << userName1 << " and " << userName2 << " are now friends." << endl;
}

// Function to display all registered users
void displayAllUsers() {
    cout << "All Registered Users:\n";
    for (auto& user : mapUserName) {
        cout << "Username: " << user.first << ", Name: " << user.second.firstName << " " << user.second.lastName << endl;
    }
}

// Function to display all friendships
void displayAllFriendships() {
    cout << "All Friendships:\n";
    for (auto& pair : Friends) {
        cout << pair.first << " -> ";
        for (auto& friendName : pair.second) {
            cout << friendName << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Add User\n";
        cout << "2. Make Friends\n";
        cout << "3. Display All Users\n";
        cout << "4. Display All Friendships\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                makeThemFriend();
                break;
            case 3:
                displayAllUsers();
                break;
            case 4:
                displayAllFriendships();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
