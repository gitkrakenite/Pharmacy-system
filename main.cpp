#include <iostream>
#include <ctime>

using namespace std;

class Pharmacy {

    int branchID;

    public:
        string bname;
        void pharmacyDetails();
};

void Pharmacy :: pharmacyDetails() {

    cout<<"CREATE NEW PHARMACY"<<endl;
    cout<<"----------------------------------"<<endl;

    cout<<"Enter the pharmacy name: ";
    cin>>bname;

    cout<<"Enter the pharmacy branch ID: ";
    cin>>branchID;

    cout<<"++++++++++++++++---+++++"<<endl;
    cout<<bname<<" Pharmacy, ID number "<<branchID<<" was successfully created."<<endl;
};


//Login

class CreateStaff : public Pharmacy {
 public:
     string username;
     bool isAdmin;
     string category;
     int staffId;
     int confirmstaffId;
     string branchName = bname;

     void formStaff();
     void login();

};


void CreateStaff :: formStaff() {

    cout<<"CREATE STAFF PAGE: "<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<""<<endl;

    cout<<"Create the staff username: ";
    cin>>username;

    cout<<"Create staff ID. MUST be unique: ";
    cin>>staffId;

    cout<<"Create staff category: ";
    cin>>category;

    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    //cout << "The local date and time is: " << dt << endl;

    cout<<"======================================================"<<endl;

    cout<<"At "<< dt <<" Staff was created successfully"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
};

void CreateStaff :: login() {

    int guessCount = 1;
    int guessLimit = 4;

    cout<<"LOGIN PAGE"<<endl;
    cout<<""<<endl;
    cout<<"You must login to continue"<<endl;
    cout<<"======================================================="<<endl;
    cout<<""<<endl;

    cout<<"Enter your staff ID: ";
    cin>>confirmstaffId;


    while(guessCount < guessLimit && confirmstaffId != staffId) {

        int guesses = guessLimit - guessCount;
        cout<<"OOPs we can't find such a staff."<<endl;
        cout<<"Please confirm your ID. You have "<<guesses<<" attempts remaining."<<endl;


        cout<<"Enter your staff ID: ";
        cin>>confirmstaffId;

         guessCount++;
    }



    if(confirmstaffId == staffId) {
        cout<<""<<endl;
        cout<<"++++++++++++++++++++++++++"<<endl;
        cout<<"Welcome @"<<username<<endl;
    }

    else {
        cout<<"You failed to login successfully. Create a new account and keep track of your ID. "<<endl;
    }

}


//Sales

class Sales {

public:


    int buyingPrice;
    string item;
    int numberofItem;
    int initialStock;
    int sellingPrice;

    void getsaleDetails();
    void salesReport();



};

void Sales :: getsaleDetails() {

    cout<<"<<<<<< SALES PAGE >>>>>>"<<endl;

    cout<<"---------------------------------------------------"<<endl;

    cout<<"Item of sale: ";
    cin>> item;

    cout<<"How many packs ??: ";
    cin>> numberofItem;

    cout<<"What was the buying price per pack ??: ";
    cin>> buyingPrice;

    cout<<"What was initial stock ";
    cin>> initialStock;

    cout<<"What is selling price per pack ?? ";
    cin>> sellingPrice;

};


void Sales :: salesReport() {

    int leftStock = initialStock - numberofItem;
    int totalSP = sellingPrice * numberofItem;
    int totalBP = buyingPrice * numberofItem;

    int profitLoss = totalSP - totalBP;

    cout<<""<<endl;

    cout<<"---------------------------------------------------"<<endl;

    cout<<"SALES REPORT"<<endl;
    cout<<""<<endl;

     // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    //cout << "The local date and time is: " << dt << endl;

    cout<<"At "<< dt <<numberofItem<<" packs of "<<item<<" was sold. The total selling price was Ksh."<<totalSP<<endl;
    cout<<"Total number of "<<item<<" left in the inventory is, "<< leftStock <<endl;
    cout<<"The price margin is: Ksh."<<profitLoss<<" ::NOTE<< If its '-' you suffered that much loss. \nOtherwise you got that much profit >>"<<endl;



}




int main()

{
    char choice ;

    CreateStaff obj2;
    obj2.formStaff();

    obj2.login();

    cout<<""<<endl;
    cout<<"YOU ARE HIGHLY ADVISED TO CREATE YOUR PHARMACY PAGE...>>> 'R' <<< to register" <<endl;





    int userCount=1;
    int userLimit=1000;

    while (userCount < userLimit) {

        cout<<"====================================================="<<endl;
        cout<<""<<endl;
        cout<<"What do you want to do next ?? "<<endl;
        cout<<"'O' to logout of your account"<<endl;
        cout<<"'R' to register a new pharmacy"<<endl;
        cout<<"'S' for sales:: ";
        cin >>choice;

        cout<<""<<endl;
        cout<<"====================================================="<<endl;
        cout<<""<<endl;

        switch (choice) {

        case 'C': {
            obj2.formStaff();
            break;
        }

        case 'R': {
            Pharmacy obj1;
            obj1.pharmacyDetails();
            break;
        }

        case 'L': {
            obj2.login();
            break;
        }


        case 'S': {
            Sales obj3;
            obj3.getsaleDetails();
            obj3.salesReport();
            break;
        }

        case 'O':
            cout<<"logging out ... "<<endl;
            userCount = 1000;
        default:
            cout<<"You logged out successfully. See you next time."<<endl;
        }

        userCount ++;
    }





    return 0;
}
