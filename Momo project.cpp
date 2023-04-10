#include <iostream> 

using namespace std;

int main() {
    const string DEFAULT_PIN = "0000";
    const int DEFAULT_BALANCE = 1000;
    string pin;
    int balance = DEFAULT_BALANCE;
    int attempts = 0;
    int menuSelection;
    int amount;
    string Phone_number;
    string newPin;
    bool isAuthenticated = false;

    // Ask user for pin code
    while(!isAuthenticated && attempts < 3){
    	cout << "Please enter your PIN: ";
    	cin >> pin;

    if(pin == DEFAULT_PIN) {
    isAuthenticated = true;
    } else{
    attempts++;
    cout << "Wrong pin, please try again." << endl;
    }
}

    // Menu is displayed only if user is authenticated
    if(isAuthenticated){
        do{
    	cout << endl
        << "1. Check balance" << endl
        << "2. Send money" << endl
        << "3. Change/reset PIN" << endl
        << "4. Exit" << endl;

    cout << "Select an option: ";
    cin >> menuSelection;

		
	 switch(menuSelection){

    case 1: // Checking balance
    cout << "Your current balance is: " << balance << endl;
    break;

    // Sending money
    case 2:
    cout<<"Enter  Phone number: ";
    cin >> Phone_number;
    while(Phone_number.size() != 10){
        cout <<"Invalid number"<<endl;
        cout <<"Re-enter phone number: ";
        cin >> Phone_number;
    } 
    cout << "Enter amount to send: ";
    cin >> amount;
    if(amount <= balance){
    	cout <<"Successfully sent"<<endl;
    	
    	 balance = balance - amount;
    	 cout << "Your balance is " << balance;
    }

 	else {
    cout << "Insufficient funds." << endl;
    }
    cout << "**************************************"<<endl;
    break;

    // Changing/resetting PIN
    case 3:
    cout << "Enter new PIN: ";
    cin >> newPin;
    for(int i = 0; i < 2; i++){
        if(newPin.size() != 4){
            cout << "Invalid pin" << endl;
            cout << "Re-enter pin: ";
            cin >> newPin;
        } else{
            pin = newPin;
            cout << "Your PIN has been successfully reset." << endl;
            cout << "**************************************"<<endl;
            break;
    }
        
}
    // Exiting the program
    case 4:
    cout << "Exiting program..." << endl;
    break;

    // Invalid selection
    default:
    cout << "Invalid selection." << endl;
    }
	  } while (menuSelection != 4);
	  
	  // Exit program if user is not authenticated after 3 attempts
    } else { 
        cout << "Too many attempts. Exiting program..." << endl;
    }
    return 0;
}


