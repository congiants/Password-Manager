//*********************************************
//Created by Constantine Giantselidis
//Student of 
//Department of Information and Electronic Engineering
//International Hellenic University
//@ 2022
//*********************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include<time.h>
#include <fstream>

using namespace std;
const int MAX = 95;
const int MIN = 10;
const int MID = 29;
const int LMID = 30;

class Account{
	//Class variables
	private:
		std::string name;
		std::string email;
	    std::string password;
        std::string info;
        
    public:
    //Constructors
    	Account(){}
    	
    	Account(std::string n, std::string e, std::string p, std::string i){
    		name = n;
    		email = e;
    		password = p;
    		info = i;
		}
    	
    // Setter & Getters
    	void setName(std::string n){
            name = n;
        }
        std::string getName(){
            return name;
        }
    	
    	void setEmail(std::string e){
            email = e;
        }
        std::string getEmail(){
            return email;
        }
	
	    void setPassword(std::string p){
            password = p;
        }
        std::string getPassword(){
            return password;
        }
	
	    void setInfo(std::string i){
        	info = i;
        }
        std::string getInfo(){
            return info;
    	}
    	
	//To-String Method
    	void toString(){
    		cout << "================\nAccount Name : " << name << "\nAccount Email : " << email << "\nAccount Password : " << password <<  "\nAdditional info : " << info;
		}
	
	//Method that returns a string of all variables	
		string returnString(){
			string S = "Account Name : ";
			S = S + name;
			S = S + "\nAccount Email/Phone : ";
			S = S + email;
			S = S + "\nAccount Password : ";
			S = S + password;
			S = S + "\nAdditional Info : ";
			S = S + info;
			S = S + "\n================";
			return S;
		}
	//Method that creates a password with at least one ascii symbol, ascii uppercase, ascii lowercase, ascii number in it
		string passwordGenerator(){
		int n = 26;
	    srand(time(0));
  		char ascii[MAX] = { '!', '"', '#', '$', '%', '&',
                          '(', ')', '*', '+', ',', '-', '.',
                          '/', '0', '1', '2', '3', '4', '5',
                          '6', '7', '8', '9', ':', ';', '<',
						  '=', '>', '?', '@', 'A', 'B', 'C',
						  'D', 'E', 'F', 'G', 'H', 'I', 'J',
						  'K', 'L', 'M', 'N', 'O', 'P', 'Q',
						  'R', 'S', 'T', 'U', 'V', 'W', 'X',
						  'X', 'Y', 'Z', '[', ']', '^', '_',
						  '`', 'a', 'b', 'c', 'd', 'e', 'f',
						  'g', 'h', 'i', 'j', 'k', 'l', 'm',
						  'm', 'n', 'o', 'p', 'q', 's', 't', 'u', 'v', 'w', 'x',
						  'x', 'y', 'z', '{', '|', '}', '~'};
						  
    	char numbers [MIN] = {'0', '1', '2', '3', '4', 
							'5','6', '7', '8', '9'};
		                    
		char capitals [MID] = {'A', 'B', 'C',
						  'D', 'E', 'F', 'G', 'H', 'I', 'J',
						  'K', 'L', 'M', 'N', 'O', 'P', 'Q',
						  'R', 'S', 'T', 'U', 'V', 'W', 'X',
						  'X', 'Y', 'Z'};
						  
		char smallLetters[MID] = {'a', 'b', 'c', 'd', 'e', 'f',
						  'g', 'h', 'i', 'j', 'k', 'l', 'm',
						  'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
						  'x', 'y', 'z'};
						  
		char characters [LMID] = {'!', '"', '#', '$', '%', '&',
                          '(', ')', '*', '+', ',', '-', '.',
                          '/', ':', ';', '<',
						  '=', '>', '?', '@', '[', ']', '^', '_',
						  '`', '{', '|', '}', '~'};
						  
 		string password = "";
    
    	bool flag1 = false;
    	bool flag2 = false;
    	bool flag3 = false;
    	bool flag4 = false;
    
    //Creates password and makes sure there is at least one numbers, capitals, smallLetters and characters
		do{
			//Creates password
    		for (int i = 0; i < n; i++){
    			password = password + ascii[rand() % MAX];	
			}
		
			//Makes sure there is at least one numbers, capitals, smallLetters and characters
			for (int l = 0; l<sizeof password; l++){
				for (int k =0; k < MIN; k++){
					if(password[l] == numbers[k]){
				   		flag1 = true;
					}
				}
			}
			
			for (int l = 0; l<sizeof password; l++){
				for (int k =0; k < MID; k++){
					if(password[l] == capitals[k]){
				   		flag2 = true;
					}
				}
			}
			
			for (int l = 0; l<sizeof password; l++){
				for (int k =0; k < MID; k++){
					if(password[l] == smallLetters[k]){
				   		flag3 = true;
					}
				}
			}
			
			for (int l = 0; l<sizeof password; l++){
				for (int k =0; k < LMID; k++){
					if(password[l] == characters[k]){
				   		flag4 = true;
					}
				}
			}
		}while(flag1 == false && flag2 == false && flag3 == false && flag4 == false);
		return password;
		}
};

//Creates a txt file on the directory that the excecutable of the program is
void createTxtFile(string fileName){
	fileName = fileName + ".txt";
	cout<<fileName;
	ofstream MyWriteFile(fileName);
	MyWriteFile.close();
}

//Takes input the name of a txt file (i.e. testFile) and showcases the files content
void viewAccounts(string fileName, bool newFile){
	
	if(newFile == true){
		//Checks if file exists
		ifstream file(fileName + ".txt");
		if (file.is_open()) {
			file.close();
			
			cout << "=========== " << fileName << " Contents =========== \n\n";
			
			fileName = fileName + ".txt";
			
			//Goes line by line in the file and prints what is written
			ifstream MyReadFile(fileName);
			string myText;
			string fileContent;
			while (getline (MyReadFile, myText)) {
		   		fileContent = fileContent + myText +"\n";
		  	}
		    cout<<fileContent;
		    cout<<"\n";
			}
		else{
			cout << "\nCreating new file... \n";
		}
	}
	
	else{
		//Checks if file exists
		ifstream file(fileName + ".txt");
		if (file.is_open()) {
			file.close();
			
			cout << "=========== " << fileName << " Contents =========== \n\n";
			
			fileName = fileName + ".txt";
			
			//Goes line by line in the file and prints what is written
			ifstream MyReadFile(fileName);
			string myText;
			string fileContent;
			while (getline (MyReadFile, myText)) {
		   		fileContent = fileContent + myText +"\n";
		  	}
		    cout<<fileContent;
		    cout<<"\n";
			}
		else{
			cout << "\nNo such file found. \n";
		}
	}
}

//Auxiliary function that shows if a string exists in a txt file
bool findStringInFile(string filename, string str) {
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find(str) != string::npos) {
                file.close();
                return true;
            }
        }
        file.close();
    }
	else{
		//cout << "\nUnable to open file.";
	}
    return false;
}

//Either creates a new txt file or on an already existing txt file, it adds a new account
void addAccount(Account a){
	string fileName;
	string accountName;
	string accountEmail;
	string accountPassword;
	string accountInfo;
	bool newFile = true;
	
	//Input of the account variables
	cout<<"\nFile name (For example 'fileName'):";
	cout<<"\n> ";
	cin >> fileName;
	cout<<"\n";
	
	//Checks if file exists
	ifstream file(fileName + ".txt");
	if (file.is_open()) {
		file.close();
		newFile = false;
	}
	
	viewAccounts(fileName, newFile);
	
	cout<<"\nAccount name (For example 'Facebook') :";
	cout<<"\n> ";
	cin >> accountName;
	string txtLine = "Account Name : " + accountName;
	string txtFileName = fileName + ".txt";
	//If there isnt an account with the same name then proceed
	if (findStringInFile(txtFileName, txtLine) == false){
		a.setName(accountName);
		cout<<"\nAccount email or phone number : ";
		cout<<"\n> ";
		cin >> accountEmail;
		a.setEmail(accountEmail);
		
		int n = 0;
		do{
			a.setPassword(a.passwordGenerator());
			cout<<"\nDo you wish to keep this password : " << a.getPassword();
			cout<<"\n1. Yes 2. No 3. Set your own password";
			cout<<"\n> ";
			cin >> n;
			
			if (n == 3){
				cout << "\nSet your password :";
				cout << "\n> ";
				cin >> accountPassword;
				a.setPassword(accountPassword);
				cout<<"\nDo you wish to keep this password : " << a.getPassword();
				cout<<"\n1. Yes 2. No";
				cout<<"\n> ";
				cin >> n;
			}
		}while(n != 1 );
		
		cout<<"\nAny more info :";
		cout<<"\n> ";
		cin >> accountInfo;
		a.setInfo(accountInfo);
		
		//Read from file and copy its contents on fileContent string
		fileName = fileName + ".txt";
		ifstream MyReadFile(fileName);
		string myText;
		string fileContent;
		while (getline (MyReadFile, myText)) {
	   		fileContent = fileContent + myText +"\n";
	  	}
	  	MyReadFile.close();
	  	
	  	//Add on fileContent the account variables
	  	fileContent = fileContent + a.returnString();
	  	
	  	//Write on file the fileContent
	  	ofstream MyWriteFile(fileName);
		MyWriteFile << fileContent;
		MyWriteFile.close();
		
		//Remove .txt from fileName so I can use viewAccounts function again cause viewAccounts adds .txt at the end of fileName
		if (!fileName.empty()) {
	        fileName.resize(fileName.size() - 4);
	    }
	    cout<<"\n";
	    viewAccounts(fileName, newFile);
}
	else{
		cout<<"\nAccount name already exists. \n";
	}
	
}

//Finds if a string is inside a txt file and then skips this line and the next 3
bool deleteLines(string filename, string str) {
    ifstream inFile(filename);
    ofstream outFile("temp.txt");
    string line;

    bool foundString = false;

    while (getline(inFile, line)) {
        if (line.find(str) != string::npos) {
            foundString = true;

            // Skip current and next 3 lines
            for (int i = 0; i < 4; i++) {
                if (getline(inFile, line)) {
                    continue;
                } else {
                    break;
                }
            }
        } else {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();

    if (foundString) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        return true;
    } else {
        remove("temp.txt");
        return false;
    }
}

void removeAccount(Account a){
	string fileName;
	string accountName;
	string accountEmail;
	string accountPassword;
	string accountInfo;
	
	//Input of the account variables
	cout<<"\nFile name (For example 'fileName'):";
	cout<<"\n> ";
	cin >> fileName;
	cout<<"\n";
	
	//Checks if file exists
	ifstream file(fileName + ".txt");
	if (file.is_open()) {
		file.close();
		
		//Shows all acounts
		viewAccounts(fileName, false);
		//Choose which account should be deleted
		cout<<"\nAccount name (For example 'Facebook') :";
		cout<<"\n> ";
		cin >> accountName;
		string txtLine = "Account Name : " + accountName;
		string txtFileName = fileName + ".txt";
		//If there isnt an account with the same name then proceed
		if (findStringInFile(txtFileName, txtLine) == true){
			deleteLines(txtFileName, txtLine);
			cout<<"\n";
			viewAccounts(fileName, false);
		}
		else{
			cout<< "\nNo such account to delete. \n";
		}	
	}
	
	else{
		cout << "\nNo such file found. \n";
	}
}

bool swapLines(string filename, string str, string str1, string str2, string str3, string str4, string str5) {
    ifstream inFile(filename);
    ofstream outFile("temp.txt");
    string line;

    bool foundString = false;

    while (getline(inFile, line)) {
        if (line.find(str) != string::npos) {
            foundString = true;
			
            // Skip current and next 3 lines
            for (int i = 0; i < 4; i++) {
                if (getline(inFile, line)) {
                    continue;
                } else {
                    break;
                }
            }
            
            // Write the 4 new strings to the output file
        	outFile << str1 << endl;
        	outFile << str2 << endl;
        	outFile << str3 << endl;
        	outFile << str4 << endl;
        	outFile << str5 << endl;
        }
		 
		else {
            outFile << line << endl;
        }
    }
    
    inFile.close();
    outFile.close();

    if (foundString) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        return true;
    } else {
        remove("temp.txt");
        return false;
    }
}

//Needs some fixxing
void editAccount(Account a){
	string fileName;
	string accountName;
	string accountEmail;
	string accountPassword;
	string accountInfo;
	
	//Input of the account variables
	cout<<"\nFile name (For example 'fileName'):";
	cout<<"\n> ";
	cin >> fileName;
	cout<<"\n";
	
	//Checks if file exists
	ifstream file(fileName + ".txt");
	if (file.is_open()) {
		file.close();
		
		//Shows all accounts in file
		viewAccounts(fileName, false);
		cout<<"\nAccount name (For example 'Facebook') :";
		cout<<"\n> ";
		cin >> accountName;
		string txtLine = "Account Name : " + accountName;
		string txtFileName = fileName + ".txt";
		//If there is an account with the same name then proceed
		if (findStringInFile(txtFileName, txtLine) == true){	
			cout<<"\nNew account name : ";
			cout<<"\n> ";
			cin >> accountName;
			a.setName(accountName);
			cout<<"\nNew Account email or phone number : ";
			cout<<"\n> ";
			cin >> accountEmail;
			a.setEmail(accountEmail);
			
			int n = 0;
			do{
				a.setPassword(a.passwordGenerator());
				cout<<"\nDo you wish to keep this password : " << a.getPassword();
				cout<<"\n1. Yes 2. No 3. Set your own password";
				cout<<"\n> ";
				cin >> n;
				
				if (n == 3){
					cout << "\nSet your password :";
					cout << "\n> ";
					cin >> accountPassword;
					a.setPassword(accountPassword);
					cout<<"\nDo you wish to keep this password : " << a.getPassword();
					cout<<"\n1. Yes 2. No";
					cout<<"\n> ";
					cin >> n;
				}
			}while(n != 1 );
			
			cout<<"\nAny more info :";
			cout<<"\n> ";
			cin >> accountInfo;
			a.setInfo(accountInfo);
			
			string str1 = "Account Name : " + accountName;
			string str2 = "Account Email/Phone : " + accountEmail;
			string str3 = "Account Password : " + a.getPassword();
			string str4 = "Account Info : " + accountInfo;
			string str5 = "================";
			cout << str1;
			cout << str2;
			cout << str3;
			cout << str4;
			cout << str5;
			swapLines(txtFileName, txtLine, str1, str2, str3, str4, str5);
			cout<<"\n";
			viewAccounts(fileName, false);
		}
		else{
			cout<< "\nNo such account to edit. \n";
		}
	}
	else{
		cout << "\nNo such file found. \n";
	}
}

void about(){
	cout << "\n\n";
	cout <<"\n+----------------------------------------------------------+";
	cout <<"\n\t\t\t -ABOUT-\n";
	cout <<"\n\t   Created by Constantine Giantselidis";
	cout <<"\n";
	cout <<"\n\t\t       Student of";
	cout <<"\n\t     Department of Information and";
    cout <<"\n\t     Electronic Engineering | IHU";
    cout << "\n\t\t\t @2022";
	cout <<"\n+----------------------------------------------------------+";
    cout << "\n\n";
}

void menu(){
    int choice = 0;
    bool flag = true;
    string fileName;
    Account a1;
    bool newFile = false;
    ifstream file;
    
	while(flag != false){
        cout <<"\n\n**************** PASSWORD MANAGER ****************\n";
        cout <<"\n\t=========== MENU ===========";
        cout <<"\n\t1. View Accounts \n\t2. Add Account \n\t3. Edit Account \n\t4. Remove Account \n\t5. About \n\t6. Exit";
        cout<<"\n\t> ";
        cin >>  choice;

        switch (choice){
            case 1:
            	cout<<"\nFile name :";
				cout<<"\n> ";
				cin >> fileName;
				cout<<"\n";
				//Checks if file exists
				file.open(fileName + ".txt");
				if (file.is_open()) {
					file.close();
					newFile = false;
				}				
				viewAccounts(fileName, newFile);
                break;
            case 2:
                addAccount(a1);
                break;
            case 3:
                editAccount(a1);
                break;
            case 4:
            	removeAccount(a1);
                break;
            case 5:
            	about();
                break;
            case 6:
            	flag = false;
                break;
            default:
            	cout <<"\nInvalid choice.\n";
            	cin.clear();
				cin.get();
	        	menu();
            	break;
        }
    }
}

int main (int argc, char*argv[]){
	menu();
	return 0;
}
