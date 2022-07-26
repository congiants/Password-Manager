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
		
	//Method that creates a password with at least one ascii symbol, ascii uppercase, ascii lowercase, ascii number in it
		std::string passwordGenerator(){
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
						  
    	char numbers [MIN] = {'0', '1', '2', '3', '5',
		                    '6', '7', '8', '9'};
		                    
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
    
		do{
    		for (int i = 0; i < n; i++){
    			password = password + ascii[rand() % MAX];	
			}
		
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

void createTxtFile(){
	std::string fileName;
	
	cout<<"Name of the new file (For example 'TestFile1') : ";
	cout <<"\n> ";
	cin >> fileName;
	fileName = fileName + ".txt";
	
	ofstream MyWriteFile(fileName);
}

void viewAccount(string fileName){
	//std::string fileName;
	
	cout<<"Name of the file to see the accounts (For example 'TestFile1') : ";
	cout <<"\n> ";
	cin >> fileName;
	fileName = fileName + ".txt";
	
	ifstream MyReadFile(fileName);
	string myText;
	cout << "===========" << fileName << " Contents=========== \n\n";
	while (getline (MyReadFile, myText)) {
    cout<< myText;
    cout<<"\n";
	}
}

void addAccount(Account a){
//Account a();
	
	string fileName;
	string accountName;
	string accountEmail;
	string accountPassword;
	string accountInfo;
	
	cout<<"Name of the file the account info will be stored (For example 'TestFile1') :";
	cout<<"\n> ";
	cin >> fileName;
	viewAccount(fileName);
	
	cout<<"Account name (Make sure to name different accounts on the same service with different names for example 'Twitter2' if you already have stored another Twitter account stored) :"; //Na valo na tsekari oti pragmati den yparxei allos lograriasmos me to idio onoma
	cout<<"\n> ";
	cin >> accountName;
	
	cout<<"Account email or phone number : ";
	cout<<"\n> ";
	cin >> accountEmail;
	
	int n;
	do{
		accountPassword = a.passwordGenerator();
		cout<<"Do you wish to keep this password : " << accountPassword;
		cout<<"\n 1. Yes 2. No 3. Set your own password";
		cout<<"\n> ";
		cin >> n;
		
		if (n = 3){
			cout << "\nSet your password :";
			cout << "\n> ";
			cin >> accountPassword;
			cout<<"Do you wish to keep this password : " << accountPassword;
			cout<<"\n 1. Yes 2. No";
			cout<<"\n> ";
			cin >> n;
		}
		
	}while(n != 1 );
	
	cout<<"Any more info :";
	cout<<"\n> ";
	cin >> accountInfo;
	
	ifstream MyReadFile(fileName);
	string myText;
	string fileContent;
	while (getline (MyReadFile, myText)) {
   		 fileContent = fileContent + myText +"\n";
  	}
  	fileContent = fileContent + a.toString();
	MyWriteFile (fileContent);
	MyWriteFile.close();
}

int main(){
	Account a();
	addAccount();
	return 0;
}

/*Account a1("name", "email", "password", "info");
	a1.toString();
	printf("\n\n");
	a1.setPassword(a1.passwordGenerator());
	a1.toString();
	cout<<"\n";
	createTxtFile();
	viewAccount();*/
