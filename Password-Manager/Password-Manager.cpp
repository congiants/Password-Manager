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
			S = S + "\nAccount Email : ";
			S = S + email;
			S = S + "\nAccount Password : ";
			S = S + password;
			S = S + "\nAdditional info : ";
			S = S + info;
			S = S + "\n================";
			return S;
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

void createTxtFile(string fileName){
	fileName = fileName + ".txt";
	cout<<fileName;
	ofstream MyWriteFile(fileName);
	MyWriteFile.close();
}

void viewAccounts(string fileName){
	cout << "=========== " << fileName << " Contents =========== \n\n";
	
	fileName = fileName + ".txt";
	
	ifstream MyReadFile(fileName);
	string myText;
	string fileContent;
	while (getline (MyReadFile, myText)) {
   		fileContent = fileContent + myText +"\n";
  	}
    cout<<fileContent;
    cout<<"\n";
}

void addAccount(Account a){
	string fileName;
	string accountName;
	string accountEmail;
	string accountPassword;
	string accountInfo;
	
	cout<<"File name :";
	cout<<"\n> ";
	cin >> fileName;
	viewAccounts(fileName);

	
	cout<<"Account name (For example 'Facebook') :"; //Na valo na tsekari oti pragmati den yparxei allos lograriasmos me to idio onoma
	cout<<"\n> ";
	cin >> accountName;
	a.setName(accountName);
	
	cout<<"Account email or phone number : ";
	cout<<"\n> ";
	cin >> accountEmail;
	a.setEmail(accountEmail);
	
	int n = 0;
	do{
		a.setPassword(a.passwordGenerator());
		cout<<"Do you wish to keep this password : " << a.getPassword();
		cout<<"\n1. Yes 2. No 3. Set your own password";
		cout<<"\n> ";
		cin >> n;
		
		if (n == 3){
			cout << "Set your password :";
			cout << "\n> ";
			cin >> accountPassword;
			a.setPassword(accountPassword);
			cout<<"Do you wish to keep this password : " << a.getPassword();
			cout<<"\n1. Yes 2. No";
			cout<<"\n> ";
			cin >> n;
		}
		
	}while(n != 1 );
	
	cout<<"Any more info :";
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
    viewAccounts(fileName);
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
    
	while(flag != false){
        cout <<"\n\n**************** PASSWORD MANAGER ****************\n";
        cout <<"\n\t=========== MENU ===========";
        cout <<"\n\t1. View Accounts \n\t2. Add Account \n\t3. Edit Account \n\t4. Remove Account \n\t5. About \n\t6. Exit";
        cout<<"\n\t>";
        cin >>  choice;

        switch (choice){
            case 1:
            	cout<<"\nFile name :";
		cout<<"\n> ";
		cin >> fileName;				
		viewAccounts(fileName);
                break;
            case 2:
                addAccount(a1);
                break;
            case 3:
                cout<<"\nComing soon!";
                break;
            case 4:
            	cout<<"\nComing soon!";
                break;
            case 5:
            	about();
                break;
            case 6:
            	flag = false;
                break;
            default:
            	cout << "\nInvalid choice.\n";
            	cin.clear();
		cin.get();
        	menu();
            	break;
        }
    }
}

int main(){
	menu();
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
