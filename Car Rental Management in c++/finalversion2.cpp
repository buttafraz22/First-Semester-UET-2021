#include <iostream> // header files_________
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

// function prototypes_________
void header();                                                                                              // header
string loginMenu();                                                                                         // login menu
string menuadmin();                                                                                         // admin menu
char menucustomer();                                                                                        // customer menu
void clearScreen();                                                                                         // self explanatory
void starspaces();                                                                                          // to add spaces and stars after each heading
void Add_Car();                                                                                             // to add car
void AddCartoArray(string category, string licensePlate, string Engineno, string chassisno, int kmsdriven); // to add car to array
void SortCars(string category);                                                                             // sort function
void ViewCars();                                                                                            // to view car
void addnewUser();                                                                                          // to add new user
void addUser(string name, string pass, string role);                                                        // to add new user to array
void createMaintenance(string licensePlate, string category);                                               // to create maintenance schedule
void viewMaintenance(string licensePlate, string category);                                                 // to view maintenance schedule
void SortOil(string category);                                                                              // sort function (duplicate)
void addCustomer();                                                                                         // add new customer       // next function adds into array_______
void AddCustomertoArray(string name, string fathername, long int doB, string customernic, string customerphone, string dlno, long int dlexp, string address);
int getSum();                                         // sum of all rentals income
void viewCar(string category);                        // to view car in each category
void updatecar(string category, string licenseplate); // to update category
void StartRental();                                   // to start rental
void checkBookingStatus(string category);             // self explanatory
void addreviews();                                    // self explanatory
void updateRecords(string name);                      // self explanatory
void viewRecords(string name);                        // self explanatory
void deleteCar(string category);                      // self explanatory
void loadData();                                      // self explanatory
string ParseData(string row, int column);             // to parse CSV file for populating array with string type variables
int ParseValue(string row, int column);               // to parse CSV file for populating array with int type variables
void storeoil(string category);                       // self explanatory
void StoreRentPrices();                               // self explanatory
void loadUserData();                                  // self explanatory
void loadCarData();                                   // self explanatory
void loadMaintenanceData();                           // self explanatory
void loadCustomerData();                              // self explanatory
void loadRentalPrices();                              // self explanatory
void loadIncome();                                    // self explanatory
void loadStatus();                                    // self explanatory
// function prototypes end____________

// data structures to hold and store information____
const int TOTAL_LIMIT = 20;

int rent_econ = 0;
int rent_luxury = 0;
int rent_sedan = 0;
int rent_suv = 0;

int totalincome_Count = rent_econ + rent_luxury + rent_suv + rent_sedan;
int kmsEconA[TOTAL_LIMIT];
int kmsEconD[TOTAL_LIMIT];
int kmsSedanA[TOTAL_LIMIT];
int kmsSedanD[TOTAL_LIMIT];
int kmsLuxuryA[TOTAL_LIMIT];
int kmsLuxuryD[TOTAL_LIMIT];
int kmsSUV_A[TOTAL_LIMIT];
int kmsSUV_D[TOTAL_LIMIT];

string LicensePlateEcon[TOTAL_LIMIT];
bool checkEcon[TOTAL_LIMIT];
string LicensePlateSed[TOTAL_LIMIT];
bool checkSed[TOTAL_LIMIT];
string LicensePlateSUV[TOTAL_LIMIT];
bool checkSUV[TOTAL_LIMIT];
string LicensePlateLux[TOTAL_LIMIT];
bool checkLux[TOTAL_LIMIT];

string EngineEcon[TOTAL_LIMIT];
string EngineSed[TOTAL_LIMIT];
string EngineSUV[TOTAL_LIMIT];
string EngineLux[TOTAL_LIMIT];

string chassisEcon[TOTAL_LIMIT];
string chassisSed[TOTAL_LIMIT];
string chassisSUV[TOTAL_LIMIT];
string chassisLux[TOTAL_LIMIT];

int addcar_Econ = 0;
int addcar_Sed = 0;
int addcar_SUV = 0;
int addcar_Lux = 0;

int scheduleddatesE[TOTAL_LIMIT];
int dateEc = 0;
int scheduleddatesSE[TOTAL_LIMIT];
int dateSed = 0;
int scheduleddatesSUV[TOTAL_LIMIT];
int dateSUV = 0;
int scheduleddatesLUX[TOTAL_LIMIT];
int dateLux = 0;

int OC_Econ[TOTAL_LIMIT];
int OC_Sed[TOTAL_LIMIT];
int OC_SUV[TOTAL_LIMIT];
int OC_Lux[TOTAL_LIMIT];

string Radi_Econ[TOTAL_LIMIT];
string Radi_Sed[TOTAL_LIMIT];
string Radi_SUV[TOTAL_LIMIT];
string Radi_Lux[TOTAL_LIMIT];

string Brake_Econ[TOTAL_LIMIT];
string Brake_Sed[TOTAL_LIMIT];
string Brake_SUV[TOTAL_LIMIT];
string Brake_Lux[TOTAL_LIMIT];

string Tires_Econ[TOTAL_LIMIT];
string Tires_Lux[TOTAL_LIMIT];
string Tires_Sed[TOTAL_LIMIT];
string Tires_SUV[TOTAL_LIMIT];

int incomerentalA[4 * TOTAL_LIMIT];
int incomeC = 0;
char stars = '0';

string custName[TOTAL_LIMIT];
string custPat[TOTAL_LIMIT];
string custDoB[TOTAL_LIMIT];
string custnic[TOTAL_LIMIT];
string custPhone[TOTAL_LIMIT];
string custaddress[TOTAL_LIMIT];
string custdl[TOTAL_LIMIT];
string custdlexp[TOTAL_LIMIT];
int customer_count = 0;

string usernameA[TOTAL_LIMIT];
string passwordsA[TOTAL_LIMIT];
string rolesA[TOTAL_LIMIT];
int userCount = 0;
string check_username = " ";
int logincount = 0;
// end data structures____________

// main function_____
main()
{
    loadData();
    system("cls");
    header();
    string who = " ";

    while (true) // start of main while loop
    {
        // header();
        cout << "LOGIN----" << endl;
        starspaces();
        who = loginMenu();
        system("cls");
        if (who == "ADMIN")
        {
            string option = " ";
            while (true)
            {
                system("cls");
                header();
                option = menuadmin();
                clearScreen();
                if (option == "1") // to add a car___________
                {
                    header();
                    cout << "ADD CAR------" << endl;
                    starspaces();
                    Add_Car();
                    clearScreen();
                }
                else if (option == "2") // to sort and view the cars__________
                {
                    header();
                    loadCarData();
                    cout << "VIEW CAR IN SORTED ORDER----" << endl;
                    starspaces();
                    cout << "Enter Category you want to see(Economical/Luxury/SUV/Sedan): ";
                    string op2category;
                    cin >> op2category;
                    SortCars(op2category);
                    viewCar(op2category);
                    clearScreen();
                }
                else if (option == "3") // To Create Maintenance Schedule____________
                {
                    header();
                    cout << "CREATE MAINTENANCE SCHEDULE---" << endl;
                    starspaces();
                    string op3category, op3licenseplate; // localized
                    cout << "Enter License Plate of the car in Question: " << endl;
                    cin >> op3licenseplate;
                    cout << "Enter Category of the car in question(Economical/Luxury/SUV/Sedan): " << endl;
                    cin >> op3category;
                    createMaintenance(op3licenseplate, op3category);
                    clearScreen();
                }
                else if (option == "4") // to view maintenance schedule of the car__________
                {
                    header();
                    cout << "VIEW MAINTENANCE SCHEDULE---" << endl;
                    starspaces();
                    string op4category, op4licenseplate;
                    cout << "Enter License Plate of the car in Question: " << endl;
                    cin >> op4licenseplate;
                    cout << "Enter Category of the car in question(Economical/Luxury/SUV/Sedan): " << endl;
                    cin >> op4category;
                    SortOil(op4category);
                    viewMaintenance(op4licenseplate, op4category);
                    clearScreen();
                }
                else if (option == "5") // to get cash reports__________________
                {
                    header();
                    cout << "CASH REPORTS:" << endl;
                    starspaces();
                    int netincome = getSum();
                    int miscexp = 0;
                    cout << "Enter Miscellenaeous Expenses: " << endl;
                    cin >> miscexp;
                    if (miscexp < 0)
                    {
                        while (miscexp < 0)
                        {
                            cout << "Value Can not be negative. Re-Enter the value: ";
                            cin >> miscexp;
                        }
                    }
                    int resoluteinc = netincome - miscexp;
                    cout << "Net Income is: " << netincome << endl;
                    cout << "After Expenses: " << resoluteinc << endl;
                    if (resoluteinc >= 0)
                    {
                        cout << "Profitability is in Progress.";
                    }
                    else
                    {
                        cout << "You have incurred Loss.";
                    }
                    cout << endl;
                    clearScreen();
                }
                else if (option == "6") // add customer records__________
                {
                    header();
                    cout << "ADD CUSTOMER---" << endl;
                    starspaces();
                    addCustomer();
                    clearScreen();
                }
                else if (option == "7") // to generate tax returns_________
                {
                    header();
                    cout << "TAX RETURNS---" << endl;
                    starspaces();
                    int days;
                    cout << "Enter Days: " << endl;
                    cin >> days;
                    if (days > 364)
                    {
                        float tax = getSum();
                        float tax1 = tax * 0.30;
                        cout << "Revenue Before Tax: " << tax << endl;
                        cout << "Your Tax Liable is : " << tax1 << endl;
                    }
                    else
                    {
                        cout << "One year has not passed since last tax return.";
                    }
                    clearScreen();
                }
                else if (option == "8") // add new user to system___________
                {
                    header();
                    cout << "ADD NEW USER TO THE SYSTEM-----" << endl;
                    starspaces();
                    addnewUser();
                    clearScreen();
                }
                else if (option == "9") // update car records__________-
                {
                    header();
                    cout << "UPDATE CAR RECORDS-------" << endl;
                    starspaces();
                    string op10category, op10licenseplate;
                    cout << "Enter Category of The Car: " << endl;
                    cin >> op10category;
                    cout << "Enter License Plate of the car: " << endl;
                    cin >> op10licenseplate;
                    updatecar(op10category, op10licenseplate);
                    clearScreen();
                }
                else if (option == "10")
                {
                    header();
                    cout << "RECOMMENDATIONS----" << endl;
                    starspaces();
                    if (stars == '1')
                    {
                        cout << "You must Apologize to the customer for shortcomings and rectify them." << endl;
                    }
                    else if (stars == '2')
                    {
                        cout << "You must assure the customer that the Service needs to be bettered,after asking the customer for comments." << endl;
                    }
                    else if (stars == '3')
                    {
                        cout << "Mediocre service" << endl;
                    }
                    else if (stars == '4')
                    {
                        cout << "You must  Thank the esteemed customer, and go for the best." << endl;
                    }
                    else if (stars == '5')
                    {
                        cout << "You must Thank the customer and promise him to strive for adding new features to the system." << endl;
                    }
                    else
                    {
                        cout << "Incorrect Parameter was passed as stars." << endl;
                    }
                    clearScreen();
                }
                else if (option == "11")
                {
                    header();
                    cout << "DELETE CAR------" << endl;
                    starspaces();
                    cout << "Enter the category of the car you want to delete (Economical/Luxury/Sedan/SUV): ";
                    string op12ct;
                    cin >> op12ct;
                    deleteCar(op12ct);
                    clearScreen();
                }
                else if (option == "12")
                {
                    header();
                    cout << "SET PRICES OF CAR RENTAL------" << endl;
                    starspaces();
                    cout << "Enter amount of rent per day of Economical Cars: ";
                    cin >> rent_econ;

                    cout << "Enter amount of rent per day of Sedan Cars: ";
                    cin >> rent_sedan;

                    cout << "Enter amount of rent per day of SUV Cars: ";
                    cin >> rent_suv;

                    cout << "Enter amount of rent per day of Luxury Cars: ";
                    cin >> rent_luxury;
                    StoreRentPrices();
                    clearScreen();
                }
                else if (option == "13")
                {
                    cout << "Thank you for using the system." << endl;
                    clearScreen();
                    break;
                }
                else
                {
                    cout << "You Enter Wrong Options. Choose Correct One.";
                }
            }
        }
        else if (who == "CUSTOMER")
        {
            system("cls");
            char option = ' ';
            while (true)
            {
                header();
                option = menucustomer();
                system("cls");
                if (option == '1') // initiate car rental_________
                {
                    header();
                    cout << "INITIATE CAR RENTAL-----" << endl;
                    starspaces();
                    StartRental();
                    clearScreen();
                }
                else if (option == '2') // check booking schedule________
                {
                    header();
                    cout << "CHECK BOOKING SCHEDULE-----" << endl;
                    starspaces();
                    string op2category;
                    cout << "Enter the category you want to see(Economical/Luxury/SUV/Sedan): ";
                    cin >> op2category;
                    checkBookingStatus(op2category);
                    clearScreen();
                }
                else if (option == '3') // manage multiple bookings______
                {
                    header();
                    cout << "MANAGE MULTIPLE BOOKINGS------" << endl;
                    starspaces();
                    StartRental();
                    clearScreen();
                }
                else if (option == '4') // adding reviews about previous experiences____
                {
                    header();
                    cout << "REVIEWS ABOUT PREVIOUS EXPERIENCES----" << endl;
                    starspaces();
                    addreviews();
                    clearScreen();
                }
                else if (option == '5') // view your records____
                {
                    header();
                    cout << "VIEW RECORDS------" << endl;
                    starspaces();
                    string op5name;
                    cout << "Enter your name: " << endl;
                    cin >> op5name;
                    viewRecords(op5name);
                    clearScreen();
                }
                else if (option == '6') // update personal records___-
                {
                    header();
                    cout << "UPDATE PERSONAL RECORDS-----" << endl;
                    starspaces();
                    string op6category;
                    cout << "Enter your name: " << endl;
                    cin >> op6category;
                    updateRecords(op6category);
                    clearScreen();
                }
                else if (option == '7') // exit prompt
                {
                    break;
                }
                else
                {
                    cout << "You Enter Wrong Option, Enter right one";
                }
            }
        }
        else
        {
            cout << "Wrong credentials." << endl;
            logincount++;
            if (logincount == 3)
            {
                cout << "Too many wrong Attempts, Program will now terminate." << endl;
                break;
            }
        }
    } // end main while loop

} // end main

// function definitions_________
void header() // void function to display header
{
    cout << "****************************************************************************************************************" << endl;
    cout << " **********************************   CAR RENTAL MANAGEMENT SYSTEM    *****************************************" << endl;
    cout << "****************************************************************************************************************" << endl;
}

string loginMenu()
{ //________Get user credentials and check whether user is present in
    string result;
    string username, password;
    cout << "Enter Username: " << endl;
    cin >> username;
    cout << "Enter Password: " << endl;
    cin >> password;

    for (int i = 0; i < TOTAL_LIMIT; i++)
    {
        if (username == usernameA[i] && password == passwordsA[i])
        {
            check_username = username;
            return rolesA[i];
        }
    }
    check_username = " ";
    return "Invalid Credentials,Try Again";
}

char menucustomer() // character function to display menu for customer
{
    char passop = ' ';
    cout << "MENU--Customer: " << endl;
    cout << "*****************" << endl;

    cout << "OPTIONS:" << endl;
    cout << "1. Initiate Car Rental." << endl;
    cout << "2. Check Booking Schedule." << endl;
    cout << "3. Manage Multiple Bookings." << endl;
    cout << "4. Add Reviews about previous Experience." << endl;
    cout << "5. View your Records." << endl;
    cout << "6. Update your Records." << endl;
    cout << "7. Exit." << endl;

    cout << "Please select your option: ";
    cin >> passop;

    return passop;
}
string menuadmin() // string function to display menu for admin
{
    string passopa = " ";
    cout << "MENU--Admin: " << endl;
    cout << "*****************" << endl;

    cout << "OPTIONS:" << endl;
    cout << "1. Add the Car." << endl;
    cout << "2. Sort and View the cars." << endl;
    cout << "3. Create Maintenace Schedule. " << endl;
    cout << "4. View Maintenance Schedule." << endl;
    cout << "5. Cash Reports." << endl;
    cout << "6. Add / Validate Customer Records." << endl;
    cout << "7. Generate Tax Returns." << endl;
    cout << "8. Add Users to System." << endl;
    cout << "9. Update Car Information." << endl;
    cout << "10. Recommendations ." << endl;
    cout << "11. Delete Car Details." << endl;
    cout << "12. Set Rent Of Cars,Category wise." << endl;
    cout << "13. Exit." << endl;
    cout << "Please Select your Option: " << endl;
    cin >> passopa;

    return passopa;
}

void clearScreen() // void function to clear screen
{
    cout << "Press any key to continue.";
    getch();
    system("cls");
}
void starspaces() // void function to display stars
{

    cout << "*********************************" << endl;
    cout << "                                 " << endl;
}

void Add_Car() // void function to take parameters and pass it to AddCartoArray()
{
    string category;
    cout << "Enter Category(Economical / Sedan / Luxury / SUV): ";
    cin >> category;

    cout << "Enter License Plate Of the Car : ";
    string licenseplate;
    cin >> licenseplate;

    cout << "Enter Engine no. Of the Car: ";
    string engineNo;
    cin >> engineNo;

    cout << "Enter Chassis No . of the Car: ";
    string chassisno;
    cin >> chassisno;

    cout << "Enter Kms Driven on the Car( Speedometer Guage Reading ): ";
    int kms;
    cin >> kms;
    if (kms < 0)
    {
        //   cout<<"W"<<endl;
        while (kms < 0)
        {
            cout << "You Enter Invalid kms Reading. Please Enter right One: ";
            cin >> kms;
        }
    }
    // passing parameters as a modular feature
    AddCartoArray(category, licenseplate, engineNo, chassisno, kms);
}

void AddCartoArray(string category, string licensePlate, string Engineno, string chassisno, int kmsdriven)
{                        // void function to add car into relevant arrays
    fstream fileAddCars; // implementing file storage operation in
    string item;         // append mode

    if (category == "Economical")
    {
        fileAddCars.open("DataEconomyCars.txt", ios::app);

        LicensePlateEcon[addcar_Econ] = licensePlate;
        EngineEcon[addcar_Econ] = Engineno;

        chassisEcon[addcar_Econ] = chassisno;
        kmsEconA[addcar_Econ] = kmsdriven;
        kmsEconD[addcar_Econ] = kmsdriven;
        addcar_Econ = addcar_Econ + 1;
        fileAddCars << licensePlate << "," << Engineno << "," << chassisno << "," << kmsdriven << endl;
        fileAddCars.close();
    }
    else if (category == "Sedan")
    {
        fileAddCars.open("DataSedan.txt", ios::app);
        LicensePlateSed[addcar_Sed] = licensePlate;
        EngineSed[addcar_Sed] = Engineno;
        chassisSed[addcar_Sed] = chassisno;
        kmsSedanA[addcar_Sed] = kmsdriven;
        kmsSedanD[addcar_Sed] = kmsdriven;
        addcar_Sed = addcar_Sed + 1;
        fileAddCars << licensePlate << "," << Engineno << "," << chassisno << "," << kmsdriven << endl;
        fileAddCars.close();
    }
    else if (category == "SUV")
    {
        fileAddCars.open("DataSUV.txt", ios::app);
        LicensePlateSUV[addcar_SUV] = licensePlate;
        EngineSUV[addcar_SUV] = Engineno;
        chassisSUV[addcar_SUV] = chassisno;
        kmsSUV_A[addcar_SUV] = kmsdriven;
        kmsSUV_D[addcar_SUV] = kmsdriven;
        fileAddCars << licensePlate << "," << Engineno << "," << chassisno << "," << kmsdriven << "\n";
        fileAddCars.close();
        addcar_SUV = addcar_SUV + 1;
    }
    else if (category == "Luxury")
    {
        fileAddCars.open("DataLuxury.txt", ios::app);
        LicensePlateLux[addcar_Lux] = licensePlate;
        EngineLux[addcar_Lux] = Engineno;
        chassisLux[addcar_Lux] = chassisno;
        kmsLuxuryA[addcar_Lux] = kmsdriven;
        kmsLuxuryD[addcar_Lux] = kmsdriven;
        addcar_Lux = addcar_Lux + 1;
        fileAddCars << licensePlate << "," << Engineno << "," << chassisno << "," << kmsdriven << "\n";
        fileAddCars.close();
    }
    else
    {
        cout << "You Enter Wrong Category. Please Enter Right One." << endl;
    }
}

void SortCars(string category)
{
    // void function to sort cars according to driven kilometers______________
    if (category == "Economical" && addcar_Econ > 1)
    {
        for (int i = 0; i <= addcar_Econ - 1; i++)
        {
            for (int j = i + 1; j < addcar_Econ; j++)
            {
                if (kmsEconA[j] < kmsEconA[i])
                {
                    int tempKM = kmsEconA[j];
                    kmsEconA[j] = kmsEconA[i];
                    kmsEconA[i] = tempKM;

                    string tempLICS = LicensePlateEcon[j];
                    LicensePlateEcon[j] = LicensePlateEcon[i];
                    LicensePlateEcon[i] = tempLICS;

                    string tempEng = EngineEcon[j];
                    EngineEcon[j] = EngineEcon[i];
                    EngineEcon[i] = tempEng;

                    string tempChassis = chassisEcon[j];
                    chassisEcon[j] = chassisEcon[i];
                    chassisEcon[i] = tempChassis;
                }
            }
        }
    }
    else if (category == "Sedan" && addcar_Sed > 1)
    {
        for (int i = 0; i <= addcar_Sed - 1; i++)
        {
            for (int j = i + 1; j < addcar_Sed; j++)
            {
                if (kmsSedanA[j] < kmsSedanA[i])
                {
                    int tempKM = kmsSedanA[j];
                    kmsSedanA[j] = kmsSedanA[i];
                    kmsSedanA[i] = tempKM;

                    string tempLICS = LicensePlateSed[j];
                    LicensePlateSed[j] = LicensePlateSed[i];
                    LicensePlateSed[i] = tempLICS;

                    string tempEng = EngineSed[j];
                    EngineSed[j] = EngineSed[i];
                    EngineSed[i] = tempEng;

                    string tempChassis = chassisSed[j];
                    chassisSed[j] = chassisSed[i];
                    chassisSed[i] = tempChassis;
                }
            }
        }
    }
    else if (category == "SUV" && addcar_SUV > 1)
    {
        for (int i = 0; i <= addcar_SUV - 1; i++)
        {
            for (int j = i + 1; j < addcar_SUV; j++)
            {
                if (kmsSUV_A[j] < kmsSUV_A[i])
                {
                    int tempKM = kmsSUV_A[j];
                    kmsSUV_A[j] = kmsSUV_A[i];
                    kmsEconA[i] = tempKM;

                    string tempLICS = LicensePlateSUV[j];
                    LicensePlateSUV[j] = LicensePlateSUV[i];
                    LicensePlateSUV[i] = tempLICS;

                    string tempEng = EngineSUV[j];
                    EngineSUV[j] = EngineSUV[i];
                    EngineSUV[i] = tempEng;

                    string tempChassis = chassisSUV[j];
                    chassisSUV[j] = chassisSUV[i];
                    chassisSUV[i] = tempChassis;
                }
            }
        }
    }
    else if (category == "Luxury" && addcar_Lux > 1)
    {
        for (int i = 0; i <= addcar_Lux - 1; i++)
        {
            for (int j = i + 1; j < addcar_Lux; j++)
            {
                if (kmsLuxuryA[j] < kmsLuxuryA[i])
                {
                    int tempKM = kmsLuxuryA[j];
                    kmsLuxuryA[j] = kmsLuxuryA[i];
                    kmsLuxuryA[i] = tempKM;

                    string tempLICS = LicensePlateLux[j];
                    LicensePlateLux[j] = LicensePlateLux[i];
                    LicensePlateLux[i] = tempLICS;

                    string tempEng = EngineLux[j];
                    EngineLux[j] = EngineLux[i];
                    EngineLux[i] = tempEng;

                    string tempChassis = chassisLux[j];
                    chassisLux[j] = chassisLux[i];
                    chassisLux[i] = tempChassis;
                }
            }
        }
    }
}

void addUser(string name, string pass, string role) // void function to add new user to system ___________________
{                                                   //______Add user, only admin can add_________
    if (userCount <= TOTAL_LIMIT)
    {
        usernameA[userCount] = name;
        passwordsA[userCount] = pass;
        rolesA[userCount] = role;
        userCount = userCount + 1;
        fstream file;
        file.open("DataUser.txt", ios::app);
        file << name << "," << pass << "," << role << endl;
    }
    else
        cout << "No more space to store variables." << endl;
}

void addnewUser() // void function to take input from user and pass it to AddUser() function
{
    string username, password, role;
    cout << "Enter username: " << endl;
    cin >> username;

    cout << "Enter password: " << endl;
    cin >> password;

    cout << "Enter role (ADMIN/CUSTOMER) in uppercase letters: " << endl;
    cin >> role;

    addUser(username, password, role);
}
void createMaintenance(string licensePlate, string category) // void function to create maintenance schedule
{
    if (category == "Economical")
    {
        int tempval = -1; // temporary index value
        for (int i = 0; i < addcar_Econ; i++)
        {
            if (licensePlate == LicensePlateEcon[i])
                tempval = i;
            break;
        }

        if (tempval >= 0)
        {
            cout << "License Plate of the car: " << LicensePlateEcon[tempval] << endl;
            cout << "Oil Threshold: 3000" << endl;
            cout << "Enter Oil Change reading in KMs: " << endl;
            cin >> OC_Econ[tempval];
            cout << "Enter Radiator Checkup Date: " << endl;
            cin >> Radi_Econ[tempval];
            cout << "Enter Brake oil Checkup Date: " << endl;
            cin >> Brake_Econ[tempval];
            cout << "Enter Tires Checkup Date: " << endl;
            cin >> Tires_Econ[tempval];
        }
        else
        {
            cout << "No car with entered license plate is entered into the system, create maintenance operation cancelled.";
        }
    }
    else if (category == "Sedan")
    {
        int tempval = -1;
        for (int i = 0; i < TOTAL_LIMIT; i++)
        {
            if (licensePlate == LicensePlateEcon[i])
                tempval = i;
            break;
        }
        // tempval = tempval + 2;
        if (tempval >= 0)
        {
            cout << "License Plate of the car: " << LicensePlateSed[tempval] << endl;
            cout << "Oil Threshold: 3000" << endl;
            cout << "Enter Oil Change reading in KMs: " << endl;
            cin >> OC_Sed[tempval];
            cout << "Enter Radiator Checkup Date: " << endl;
            cin >> Radi_Sed[tempval];
            cout << "Enter Brake oil Checkup Date: " << endl;
            cin >> Brake_Sed[tempval];
            cout << "Enter Tires Checkup Date: " << endl;
            cin >> Tires_Sed[tempval];
        }
        else
        {
            cout << "No car with entered license plate is entered into the system, create maintenance operation cancelled.";
        }
    }
    else if (category == "SUV")
    {
        int tempval = -1;
        for (int i = 0; i < TOTAL_LIMIT; i++)
        {
            if (licensePlate == LicensePlateEcon[i])
                tempval = i;
            break;
        }
        // tempval = tempval + 2;
        if (tempval >= 0)
        {
            cout << "License Plate of the car: " << LicensePlateSUV[tempval] << endl;
            cout << "Oil Threshold: 3000" << endl;
            cout << "Enter Oil Change reading in KMs: " << endl;
            cin >> OC_SUV[tempval];
            cout << "Enter Radiator Checkup Date: " << endl;
            cin >> Radi_SUV[tempval];
            cout << "Enter Brake oil Checkup Date: " << endl;
            cin >> Brake_SUV[tempval];
            cout << "Enter Tires Checkup Date: " << endl;
            cin >> Tires_SUV[tempval];
        }
        else
        {
            cout << "No car with entered license plate is entered into the system, create maintenance operation cancelled.";
        }
    }
    else if (category == "Luxury")
    {
        int tempval = -1;
        for (int i = 0; i < TOTAL_LIMIT; i++)
        {
            if (licensePlate == LicensePlateLux[i])
                tempval = i;
            break;
        }
        // tempval = tempval + 2;
        if (tempval >= 0)
        {
            cout << "License Plate of the car: " << LicensePlateLux[tempval] << endl;
            cout << "Oil Threshold: 3000" << endl;
            cout << "Enter Oil Change reading in KMs: " << endl;
            cin >> OC_Lux[tempval];
            cout << "Enter Radiator Checkup Date: " << endl;
            cin >> Radi_Lux[tempval];
            cout << "Enter Brake oil Checkup Date: " << endl;
            cin >> Brake_Lux[tempval];
            cout << "Enter Tires Checkup Date: " << endl;
            cin >> Tires_Lux[tempval];
        }
        else
        {
            cout << "No car with entered license plate is entered into the system, create maintenance operation cancelled.";
        }
    }
}

void SortOil(string category) // void function to sort cars according to oil change
{
    if (category == "Economical" && addcar_Econ > 1)
    {
        for (int i = 0; i <= addcar_Econ - 1; i++)
        {
            for (int j = i + 1; j < addcar_Econ; j++)
            {
                if (kmsEconD[j] < kmsEconD[i])
                {
                    int tempOC = OC_Econ[j];
                    OC_Econ[j] = OC_Econ[i];
                    OC_Econ[i] = tempOC;
                }
            }
        }
        storeoil("Economical");
    }
    if (category == "Sedan" && addcar_Sed > 1)
    {
        for (int i = 0; i <= addcar_Sed - 1; i++)
        {
            for (int j = i + 1; j < addcar_Sed; j++)
            {
                if (kmsSedanD[j] < kmsSedanD[i])
                {
                    int tempOC = OC_Sed[j];
                    OC_Sed[j] = OC_Sed[i];
                    OC_Sed[i] = tempOC;
                }
            }
        }

        storeoil("Sedan");
    }
    if (category == "SUV" && addcar_SUV > 1)
    {
        for (int i = 0; i <= addcar_SUV - 1; i++)
        {
            for (int j = i + 1; j < addcar_SUV; j++)
            {
                if (kmsSUV_D[j] < kmsSUV_D[i])
                {
                    int tempOC = OC_SUV[j];
                    OC_SUV[j] = OC_SUV[i];
                    OC_SUV[i] = tempOC;
                }
            }
        }
        storeoil("SUV");
    }
    if (category == "Luxury" && addcar_Lux > 1)
    {
        for (int i = 0; i <= addcar_Lux - 1; i++)
        {
            for (int j = i + 1; j < addcar_Lux; j++)
            {
                if (kmsLuxuryD[j] < kmsLuxuryD[i])
                {
                    int tempOC = OC_Lux[j];
                    OC_Lux[j] = OC_Lux[i];
                    OC_Lux[i] = tempOC;
                }
            }
        }
        storeoil("Luxury");
    }
}

void viewMaintenance(string licensePlate, string category) // void function to view maintenance status of the car
{
    if (category == "Economical")
    {
        int tempval = -1;
        for (int i = 0; i < addcar_Econ; i++)
        {
            if (licensePlate == LicensePlateEcon[i])
                tempval = i;
            break;
        }
        tempval = tempval + 2;
        cout << "License Plate Of the car: " << licensePlate << endl;

        if (kmsEconD[tempval] - OC_Econ[tempval] < 3000)
        {
            cout << "Good To go." << endl;
        }
        else
        {
            cout << "Oil Change is Required. " << endl;
        }
    }
    else if (category == "Sedan")
    {
        int tempval = 0;
        for (int i = 0; i < TOTAL_LIMIT; i++)
        {
            if (licensePlate == LicensePlateSed[i])
                tempval = i;
            break;
        }
        cout << "License Plate Of the Car: " << licensePlate << endl;

        if (kmsSedanD[tempval] - OC_Sed[tempval] < 3000)
        {
            cout << "Good To Go. " << endl;
        }
        else
        {
            cout << "Oil Change Required." << endl;
        }
    }
    else if (category == "SUV")
    {
        int tempval = 0;
        for (int i = 0; i < TOTAL_LIMIT; i++)
        {
            if (licensePlate == LicensePlateSUV[i])
                tempval = i;
            break;
        }
        cout << "License Plate Of The Car: " << licensePlate << endl;

        if (kmsSUV_D[tempval] - OC_SUV[tempval] < 3000)
        {
            cout << "Good to go. " << endl;
        }
        else
        {
            cout << "Require Oil Change. " << endl;
        }
    }
    else if (category == "Luxury")
    {
        int tempval = 0;
        for (int i = 0; i < TOTAL_LIMIT; i++)
        {
            if (licensePlate == LicensePlateLux[i])
                tempval = i;
            break;
        }
        cout << "License Plate Of the car: " << licensePlate << endl;

        if (kmsLuxuryD[tempval] - OC_Lux[tempval] < 3000)
        {
            cout << "Good To go." << endl;
        }
        else
        {
            cout << "Require Oil Change. " << endl;
        }
    }
    else
    {
        cout << "Error, wrong category / License Plate entered." << endl;
    }
}

int getSum() // integer function to return sum___________
{
    int sum = 0;
    for (int i = 0; i < totalincome_Count; i++)
    {
        sum = sum + incomerentalA[i];
    }
    return sum;
}

void addCustomer() // void function to add customer to records________
{
    string name, fname, dlno, address;
    string phoneno, customernic;
    long int dlexp, doB;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Father name: ";
    cin >> fname;
    cout << "Enter Date Of Birth: ";
    cin >> doB;
    if (doB < 0)
    {
        while (doB < 0)
        {
            cout << "You Enter Wrong Date Of Birth, Please Enter Right One: ";
            cin >> doB;
        }
    }
    cout << "Enter ID Card no.";
    cin >> customernic;
    if (customernic.length() != 13)
    {
        cout << "You Enter Wrong NIC number: " << endl;
        while (customernic.length() != 13)
        {
            cout << "You Enter Wrong ID Card, Please Enter Right ID Card no.";
            cin >> customernic;
        }
    }
    cout << "Enter Phone Number: ";
    cin >> phoneno;
    int flag2 = 0;
    // Checking if number is correct
    for (int i = 0; i < phoneno.length(); i++)
    {
        if (phoneno[i] - 48 >= 0 && phoneno[i] - 48 <= 9)
        {
            flag2 = 1;
            continue;
        }
        else
        {
            flag2 = 0;
            break;
        }
    }
    if (flag2 == 1 && phoneno.length() == 11)
    {
        cout << "You have entered right number.\n";
    }
    else if (flag2 == 0)
    {
        cout << "You have entered wrong number.\n";
    }
    else if (phoneno.length() != 11)
    {
        while (phoneno.length() != 11)
        {
            cout << "You have entered wrong number.\n";
            cout << "Enter Number: " << endl;
            cin >> phoneno;
        }
    }
    cout << "Enter Driver License no: ";
    cin >> dlno;
    if (dlno.length() < 11)
    {
        cout << "w";
        while (dlno.length() < 11)
        {
            cout << "You Enter Wrong Number, Please Enter Right One: ";
            cin >> dlno;
        }
    }
    cout << "Enter Driver's License Expiry: ";
    cin >> dlexp;
    if (dlexp < 0)
    {
        while (dlexp < 0)
        {
            cout << "You Enter Wrong Date Of Expiry, Please Enter Right One: ";
            cin >> dlexp;
        }
    }
    cout << "Enter Address: " << endl;
    cin >> address;

    AddCustomertoArray(name, fname, doB, customernic, phoneno, dlno, dlexp, address);
}

void AddCustomertoArray(string name, string fathername, long int doB, string customernic, string customerphone, string dlno, long int dlexp, string address)
{ // void function to add customer to array_______
    if (customer_count < TOTAL_LIMIT)
    {
        custName[customer_count] = name;
        custPat[customer_count] = fathername;
        custDoB[customer_count] = doB;
        custPhone[customer_count] = customerphone;
        custaddress[customer_count] = address;
        custdl[customer_count] = dlno;
        custdlexp[customer_count] = dlexp;
        custnic[customer_count] = customernic;
        customer_count = customer_count + 1;
        fstream file;
        file.open("DataCustomer.txt", ios::out | ios::app);
        file << name << "," << fathername << "," << doB << "," << customernic << "," << customerphone << "," << dlno
             << "," << dlexp << "," << address << endl;
    }
    else
    {
        cout << "No more Space to Store the data.";
    }
}

void updatecar(string category, string licenseplate) // void function to update car information
{
    if (category == "Economical")
    {
        int temp = 0;
        for (int i = 0; i < addcar_Econ; i++)
        {
            if (licenseplate == LicensePlateEcon[i])
            {
                temp = i;
                break;
            }
        }
        cout << "Update:" << endl;
        cout << "Update Kms Reading: " << endl;
        cin >> kmsEconA[temp];
    }
    if (category == "Sedan")
    {
        int temp = 0;
        for (int i = 0; i < addcar_Sed; i++)
        {
            if (licenseplate == LicensePlateSed[i])
            {
                temp = i;
                break;
            }
        }
        cout << "Update:" << endl;
        cout << "Update Kms Reading: " << endl;
        cin >> kmsSedanA[temp];
    }
    if (category == "SUV")
    {
        int temp = 0;
        for (int i = 0; i < addcar_SUV; i++)
        {
            if (licenseplate == LicensePlateSUV[i])
            {
                temp = i;
                break;
            }
        }
        cout << "Update:" << endl;
        cout << "Update Kms Reading: " << endl;
        cin >> kmsSUV_A[temp];
    }
    if (category == "Luxury")
    {
        int temp = 0;
        for (int i = 0; i < addcar_Lux; i++)
        {
            if (licenseplate == LicensePlateLux[i])
            {
                temp = i;
                break;
            }
        }
        cout << "Update:" << endl;
        cout << "Update Kms Reading: " << endl;
        cin >> kmsLuxuryA[temp];
    }
}

void viewCar(string category) // void function to view cars
{
    if (category == "Economical")
    {
        SortCars("Economical");
        cout << "License Plate"
             << "\t"
             << "Engine"
             << "\t"
             << "Chassis"
             << "\t"
             << "KMS Driven" << endl;
        for (int i = 0; i < addcar_Econ; i++)
        {
            cout << LicensePlateEcon[i] << "\t\t" << EngineEcon[i] << "\t" << chassisEcon[i] << "\t" << kmsEconA[i] << endl;
        }
    }
    if (category == "Luxury")
    {
        SortCars("Luxury");
        cout << "License Plate"
             << "\t"
             << "Engine"
             << "\t"
             << "Chassis"
             << "\t"
             << "KMS Driven" << endl;
        for (int i = 0; i < addcar_Lux; i++)
        {
            cout << LicensePlateLux[i] << "\t\t" << EngineLux[i] << "\t" << chassisLux[i] << "\t" << kmsLuxuryA[i] << endl;
        }
    }
    if (category == "Sedan")
    {
        SortCars("Sedan");
        cout << "License Plate"
             << "\t"
             << "Engine"
             << "\t"
             << "Chassis"
             << "\t"
             << "KMS Driven" << endl;
        for (int i = 0; i < addcar_Sed; i++)
        {
            cout << LicensePlateSed[i] << "\t\t" << EngineSed[i] << "\t" << chassisSed[i] << "\t" << kmsSedanA[i] << endl;
        }
    }
    if (category == "SUV")
    {
        SortCars("SUV");
        cout << "License Plate"
             << "\t"
             << "Engine"
             << "\t"
             << "Chassis"
             << "\t"
             << "KMS Driven" << endl;
        for (int i = 0; i < addcar_SUV; i++)
        {
            cout << LicensePlateSUV[i] << "\t\t" << EngineSUV[i] << "\t" << chassisSUV[i] << "\t" << kmsSUV_A[i] << endl;
        }
    }
}
void StartRental() // void function to initiate a car rental
{
    string name, fname, dlno, address, paymentmode, rentalissue;
    string phoneno, customernic;
    long int doB, dlexp;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Father name: ";
    cin >> fname;
    cout << "Enter Date Of Birth: ";
    cin >> doB;
    if (doB < 0)
    {
        while (doB < 0)
        {
            cout << "You Enter Wrong Date Of Birth, Please Enter Right One: ";
            cin >> doB;
        }
    }
    cout << "Enter ID Card no.";
    cin >> customernic;
    if (customernic.length() != 13)
    {
        cout << "You Enter Wrong NIC number: " << endl;
        while (customernic.length() != 13)
        {
            cout << "Enter ID Card no.";
            cin >> customernic;
        }
    }
    cout << "Enter Phone Number: " << endl;
    cin >> phoneno;
    int flag2 = 0;
    // Checking if number is correct
    for (int i = 0; i < phoneno.length(); i++)
    {
        if (phoneno[i] - 48 >= 0 && phoneno[i] - 48 <= 9)
        {
            flag2 = 1;
            continue;
        }
        else
        {
            flag2 = 0;
            break;
        }
    }
    if (flag2 == 1 && phoneno.length() == 11)
    {
        cout << "You have entered right number.\n";
    }
    else if (flag2 == 0)
    {
        cout << "You have entered wrong number.\n";
    }
    else if (phoneno.length() != 11)
    {
        while (phoneno.length() != 11)
        {
            cout << "You have entered wrong number.\n";
            cout << "Enter Number: " << endl;
            cin >> phoneno;
        }
    }
    cout << "Enter Driver License no: " << endl;
    cin >> dlno;
    if (dlno.length() < 11)
    {
        while (dlno.length() < 11)
        {
            cout << "You Enter wrong Driver's License Number. Please Enter Right One: ";
            cin >> dlno;
        }
    }
    cout << "Enter Driver's License Expiry: " << endl;
    cin >> dlexp;
    if (dlexp < 0)
    {
        while (dlexp < 0)
        {
            cout << "You Enter Wrong Date Of Birth, Please Enter Right One: ";
            cin >> dlexp;
        }
    }
    cout << "Enter Address: " << endl;
    cin >> address;
    cout << "Expenses Detail: " << endl;
    starspaces();
    int rangeRent, rangeInsurance, daysRent;
    string carCategory;
    cout << "Enter Range Of Rent: " << endl;
    cin >> rangeRent;
    cout << "Enter Range Of Insurance(Enter 0 if not Required.): " << endl;
    cin >> rangeInsurance;
    cout << "Enter mode of payment: " << endl;
    cin >> paymentmode;
    cout << "Enter days Of Rent you Want the car for: " << endl;
    cin >> daysRent;
    cout << "Enter Category Of the car you want to rent(Economical/Luxury/SUV/Sedan): " << endl;
    cin >> carCategory;
    int res;
    if (carCategory == "Economical")
    {
        res = daysRent * rent_econ;
        cout << "Total rent for " << daysRent << " days is: " << res;
    }

    else if (carCategory == "Sedan")
    {
        res = daysRent * rent_sedan;
        cout << "Total rent for " << daysRent << " days is: " << res;
    }
    else if (carCategory == "SUV")
    {
        res = daysRent * rent_suv;
        cout << "Total rent for " << daysRent << " days is: " << res;
    }
    else if (carCategory == "Luxury")
    {
        res = daysRent * rent_luxury;
        cout << "Total rent for " << daysRent << " days is: " << res;
    }
    string choice1;
    cout << endl;
    cout << "Enter any custom choice: ";
    cin >> choice1;
    cout << "Proceed with rental issue?(yes/no): ";
    cin >> rentalissue;

    if (rentalissue == "yes")
    {
        if (carCategory == "Economical")
        {
            cout << "Enter schedule of date(DDMMYYYY): ";
            cin >> scheduleddatesE[dateEc];
            checkEcon[dateEc] = 1;
            cout << "This car is assigned to you for this rent: " << endl;
            cout << LicensePlateEcon[dateEc] << endl;

            fstream file1;
            file1.open("StatusEcon.txt", ios::app);
            file1 << scheduleddatesE[dateEc] << "," << checkEcon[dateEc] << endl;
            file1.close();
            dateEc++;
        }
        else if (carCategory == "Sedan")
        {
            cout << "Enter schedule of date(DDMMYYYY): ";
            cin >> scheduleddatesSE[dateSed];
            checkSed[dateSed] = 1;
            cout << "This car is assigned to you for this rent: " << endl;
            cout << LicensePlateSed[dateSed] << endl;
            fstream file1;
            file1.open("StatusSedan.txt", ios::app);
            file1 << scheduleddatesSE[dateSed] << "," << checkSed[dateSed] << endl;
            file1.close();
            dateSed++;
        }
        else if (carCategory == "SUV")
        {
            cout << "Enter schedule of date(DDMMYYYY): ";
            cin >> scheduleddatesSUV[dateSUV];
            checkSUV[dateSUV] = 1;
            cout << "This car is assigned to you for this rent: " << endl;
            cout << LicensePlateSUV[dateSUV] << endl;
            fstream file1;
            file1.open("StatusSUV.txt", ios::app);
            file1 << scheduleddatesSUV[dateSUV] << "," << checkSed[dateSUV] << endl;
            file1.close();
            dateSUV++;
        }
        else if (carCategory == "Luxury")
        {
            cout << "Enter schedule of dates(DDMMYYYY): ";
            cin >> scheduleddatesLUX[dateLux];
            checkLux[dateLux] = 1;
            fstream file1;
            file1.open("StatusLux.txt", ios::app);
            file1 << scheduleddatesLUX[dateLux] << "," << checkLux[dateLux] << endl;
            file1.close();
            cout << "This car is assigned to you for this rent: " << endl;
            cout << LicensePlateLux[dateLux] << endl;
            dateLux++;
        }

        clearScreen();

        cout << "CustomerName"
             << "\t"
             << "NIC"
             << "\t\t"
             << "RANGORENT"
             << "\t"
             << "Insurance"
             << "\t"
             << "PayMode"
             << "\t"
             << "CategoryofCar"
             << "\t"
             << "CustomRequests" << endl;
        cout << name << "\t\t" << customernic << "\t" << rangeRent << "\t\t" << rangeInsurance << "\t\t" << paymentmode << "\t" << carCategory << "\t\t" << choice1 << endl;

        cout << "--------" << endl;
        cout << "Add comments: " << endl;
        string bookingcomments;
        cin >> bookingcomments;

        incomerentalA[incomeC] = res;
        fstream file;
        file.open("RentalIncome.txt", ios::app);
        file << res << ",";
        file.close();
        incomeC++;
    }
}
void checkBookingStatus(string category) // to check booking status of the cars
{
    if (category == "Economical")
    {
        for (int i = 0; i < addcar_Econ; i++)
        {
            if (checkEcon[i] != 1)
            {
                cout << LicensePlateEcon[i] << "Is free." << endl;
            }
        }
    }
    else if (category == "Luxury")
    {
        for (int i = 0; i < addcar_Lux; i++)
        {
            if (checkLux[i] != 1)
            {
                cout << LicensePlateLux[i] << " is free." << endl;
            }
        }
    }
    else if (category == "SUV")
    {
        for (int i = 0; i < addcar_SUV; i++)
        {
            if (checkSUV[i] != 1)
            {
                cout << LicensePlateSUV[i] << " is free." << endl;
            }
        }
    }
    else if (category == "Sedan")
    {
        for (int i = 0; i < addcar_Sed; i++)
        {
            if (checkSed[i] != 1)
            {
                cout << LicensePlateSed[i] << " is free." << endl;
            }
        }
    }
    else
        cout << "You Enter Wrong Category,NO Data to display." << endl;
}
void addreviews() // to generate rcommendations for admin
{
    cout << "Add no. Of stars (integer value as parameter of 5) as review: ";
    cin >> stars;
    if (stars == '1' || stars == '2')
    {
        string comments;
        cout << "Enter comments: ";
        cin >> comments;
    }
}
void viewRecords(string name) // to view records of a particular customer
{
    int tempval = -1;
    for (int i = 0; i < TOTAL_LIMIT; i++)
    {
        if (name == custName[i])
        {
            tempval = i;
            break;
        }
    }
    if (tempval == -1)
    {
        cout << "No Customer with Such Record Exist In the System." << endl;
    }
    else
    {
        cout << "Customer Name is: " << custName[tempval] << endl;
        cout << "Customer is S/D of: " << custPat[tempval] << endl;
        cout << "Customer date Of Birth: " << custDoB[tempval] << endl;
        cout << "Customer NIC no: " << custnic[tempval] << endl;
        cout << "Customer Phone Number: " << custPhone[tempval] << endl;
        cout << "Customer Address: " << custaddress[tempval] << endl;
        cout << "Customer Driving License: " << custdl[tempval] << endl;
        cout << "Customer Driving License Expiry Date: " << custdlexp[tempval] << endl;
    }
}
void updateRecords(string name) // to update customer personal records
{
    cout << "You can Only Edit your Personal Records in this Section. " << endl;
    int tempval;
    for (int i = 0; i < TOTAL_LIMIT; i++)
    {
        if (name == custName[i])
        {
            tempval = i;
            break;
        }
    }
    cout << "Enter new Phone Number: ";
    cin >> custPhone[tempval];
    cout << "Enter new Address: ";
    cin >> custaddress[tempval];
    cout << "Enter Driving License Expiry Date: ";
    cin >> custdlexp[tempval];
}
void deleteCar(string category) // to delete car
{
    string licsp;
    cout << "Enter license plate: ";
    cin >> licsp;
    if (category == "Economical")
    {
        int tempval = -1;
        for (int i = 0; i < addcar_Econ; i++)
        {
            if (licsp == LicensePlateEcon[i])
            {
                tempval = i;
                break;
            }
        }
        if (tempval >= 0)
        {
            LicensePlateEcon[tempval] = "0";
            EngineEcon[tempval] = "0";
            chassisEcon[tempval] = "0";
            kmsEconA[tempval] = 0;
            kmsEconD[tempval] = 0;
            fstream file;
            file.open("DataEconomyCars.txt", ios::out);
            for (int i = 0; i < addcar_Econ; i++)
            {
                if (i == tempval)
                    continue;
                file << LicensePlateEcon[i] << "," << EngineEcon[i] << "," << chassisEcon[i] << "," << kmsEconA[i] << "," << kmsEconD[i] << endl;
            }
            file.close();
        }
        else
        {
            cout << "No car exists with such license plate in the system.";
        }
    }
    else if (category == "Sedan")
    {
        int tempval = -1;
        for (int i = 0; i < addcar_Sed; i++)
        {
            if (licsp == LicensePlateSed[i])
            {
                tempval = i;
                break;
            }
        }
        if (tempval >= 0)
        {
            LicensePlateSed[tempval] = "0";
            EngineSed[tempval] = "0";
            chassisSed[tempval] = "0";
            kmsSedanA[tempval] = 0;
            kmsSedanD[tempval] = 0;
            fstream file;
            file.open("DataSedan.txt", ios::out);
            for (int i = 0; i < addcar_Sed; i++)
            {
                if (i == tempval)
                    continue;
                file << LicensePlateSed[i] << "," << EngineSed[i] << "," << chassisSed[i] << "," << kmsSedanA[i] << "," << kmsSedanD[i] << endl;
            }
            file.close();
        }
        else
        {
            cout << "No car exists with such license plate in the system.";
        }
    }
    else if (category == "SUV")
    {
        int tempval = -1;
        for (int i = 0; i < addcar_SUV; i++)
        {
            if (licsp == LicensePlateSUV[i])
            {
                tempval = i;
                break;
            }
        }
        if (tempval >= 0)
        {
            LicensePlateSUV[tempval] = "0";
            EngineSUV[tempval] = "0";
            chassisSed[tempval] = "0";
            kmsSUV_A[tempval] = 0;
            kmsSUV_D[tempval] = 0;
            fstream file;
            file.open("DataSUV.txt", ios::out);
            for (int i = 0; i < addcar_SUV; i++)
            {
                if (i == tempval)
                    continue;
                file << LicensePlateSUV[i] << "," << EngineSUV[i] << "," << chassisSUV[i] << "," << kmsSUV_A[i] << "," << kmsSUV_D[i] << endl;
            }
            file.close();
        }
        else
        {
            cout << "No car exists with such license plate in the system.";
        }
    }
    else if (category == "Luxury")
    {
        int tempval = -1;
        for (int i = 0; i < addcar_Lux; i++)
        {
            if (licsp == LicensePlateLux[i])
            {
                tempval = i;
                break;
            }
        }
        if (tempval >= 0)
        {
            LicensePlateLux[tempval] = "0";
            EngineLux[tempval] = "0";
            chassisLux[tempval] = "0";
            kmsLuxuryA[tempval] = 0;
            kmsLuxuryD[tempval] = 0;
            fstream file;
            file.open("DataLuxury.txt", ios::out);
            for (int i = 0; i < addcar_Lux; i++)
            {
                if (i == tempval)
                    continue;
                file << LicensePlateLux[i] << "," << EngineLux[i] << "," << chassisLux[i] << "," << kmsLuxuryA[i] << "," << kmsLuxuryD[i] << endl;
            }
            file.close();
        }
        else
        {
            cout << "No car exists with such license plate in the system.";
        }
    }
}
string parseData(string row, int column) // to parse comma separated file for loading file into relevant array
{
    int commansCount = 1;
    string item;
    int index = 0;
    while (true)
    {
        char ch = row[index];
        if (ch == '\0')
            return item;
        if (ch == ',')
        {
            commansCount++;
        }
        else if (commansCount == column)
        {
            item = item + ch;
        }
        index++;
    }
    return item;
}
int ParseValue(string row, int field)
{
    int commansCount = 1;
    string item;
    int index = 0;
    while (true)
    {

        char ch = row[index];
        if (ch == '\0')
            return stoi(item);
        if (ch == ',')
        {
            commansCount++;
        }
        else if (commansCount == field)
        {
            item = item + ch;
        }
        index++;
    }
    int itemInt = ::atoi(item.c_str());
    return itemInt;
}
void storeoil(string category)
{
    if (category == "Economical")
    {
        fstream file;
        file.open("MaintenanceEcon.txt", ios::app);
        for (int i = 0; i <= addcar_Econ; i++)
        {
            file << OC_Econ[i] << ",";
        }
        file.close();
    }
    else if (category == "Sedan")
    {
        fstream file;
        file.open("MaintenanceSedan.txt", ios::app);
        for (int i = 0; i <= addcar_Sed; i++)
        {
            file << OC_Sed[i] << ",";
        }
        file.close();
    }
    else if (category == "SUV")
    {
        fstream file;
        file.open("MaintenanceSUV.txt", ios::app);
        for (int i = 0; i <= addcar_SUV; i++)
        {
            file << OC_SUV[i] << ",";
        }
        file.close();
    }
    else if (category == "Luxury")
    {
        fstream file;
        file.open("MaintenanceLuxury.txt", ios::app);
        for (int i = 0; i < addcar_Lux; i++)
        {
            file << OC_Lux[i] << ",";
        }
        file.close();
    }
}
void StoreRentPrices()
{
    fstream file;
    file.open("RentPrices.txt", ios::out);
    file << rent_econ << "," << rent_sedan << "," << rent_suv << "," << rent_luxury;
}
void loadData() // to load data from file to array every time program starts
{
    loadUserData();
    loadCarData();
    loadMaintenanceData();
    loadCustomerData();
    loadRentalPrices();
    loadIncome();
    loadStatus();
}
void loadUserData() // to load user data from file to array everytime program starts
{
    fstream file;
    string item;
    int count = 0;
    file.open("DataUser.txt", ios::in);
    while (!file.eof())
    {
        getline(file, item);
        if (item == " " || item == "\0") // the loop will break after encountering
            continue;                    // last line due to endl manipulator

        usernameA[count] = parseData(item, 1);
        passwordsA[count] = parseData(item, 2);
        rolesA[count] = parseData(item, 3);
        count++;
    }
    userCount = count;
    file.close();
}
void loadCarData() // to load cars data from file to array
{
    fstream file;
    string item;
    int countE = 0;
    file.open("DataEconomyCars.txt", ios::in);
    while (!file.eof())
    {
        getline(file, item);
        if (item == " " || item == "\0") // the loop will break after encountering the last line
            break;                       // due to endl manipulator

        LicensePlateEcon[countE] = parseData(item, 1);
        EngineEcon[countE] = parseData(item, 2);
        chassisEcon[countE] = parseData(item, 3);
        kmsEconA[countE] = stoi(parseData(item, 4));
        kmsEconD[countE] = stoi(parseData(item, 4));
        countE++;
    }
    addcar_Econ = countE;
    file.close();

    fstream file2;
    string item2;
    int countSed = 0;
    file2.open("DataSedan.txt", ios::in);
    while (!file2.eof())
    {
        getline(file2, item2);
        if (item2 == " " || item2 == "\0")
            break;

        LicensePlateSed[countSed] = parseData(item2, 1);
        EngineSed[countSed] = parseData(item2, 2);
        chassisSed[countSed] = parseData(item2, 3);
        kmsSedanA[countSed] = ParseValue(item2, 4);
        kmsSedanD[countSed] = ParseValue(item2, 4);
        countSed++;
    }
    addcar_Sed = countSed;
    file.close();

    fstream file3;
    string item3;
    int countSUV = 0;
    file3.open("DataSUV.txt", ios::in);
    while (!file3.eof())
    {
        getline(file3, item3);
        if (item3 == " " || item3 == "\0")
            break;

        LicensePlateSUV[countSUV] = parseData(item3, 1);
        EngineSUV[countSUV] = parseData(item3, 2);
        chassisSUV[countSUV] = parseData(item3, 3);
        kmsSUV_A[countSUV] = ParseValue(item3, 4);
        kmsSUV_D[countSUV] = ParseValue(item3, 4);
        countSUV++;
    }
    addcar_SUV = countSUV;
    file3.close();

    fstream file4;
    string item4;
    int countLux = 0;
    file4.open("DataLuxury.txt", ios::in);
    while (!file4.eof())
    {
        getline(file4, item4);
        if (item4 == " " || item4 == "\0")
            break;
        LicensePlateLux[countLux] = parseData(item4, 1);
        EngineLux[countLux] = parseData(item4, 2);
        chassisLux[countLux] = parseData(item4, 3);
        kmsLuxuryA[countLux] = ParseValue(item4, 4);
        kmsLuxuryD[countLux] = ParseValue(item4, 4);
        countLux++;
    }
    addcar_Lux = countLux;
    file4.close();
}
void loadMaintenanceData() // to load rental prices from file to array
{
    fstream file, file2, file3, file4;
    string item, item2, item3, item4;

    file.open("MaintenanceEcon.txt", ios::in);
    while (!file.eof())
    {
        getline(file, item);
        if (item == " " || item == "\0") // the loop will break after encountering the
            break;                       // last line due to endl manipulator.

        for (int i = 0; i < addcar_Econ + 1; i++)
        {

            string par = parseData(item, i);
            if (par == " " || par == "\0")
                break;
            OC_Econ[i] = stoi(par);
        }
    }
    file.close();

    file2.open("MaintenanceSedan.txt", ios::in);
    while (!file2.eof())
    {
        getline(file2, item2);
        if (item2 == " " || item2 == "\0")
            break;

        for (int i = 0; i < addcar_Sed + 1; i++)
        {
            string par = parseData(item2, i);
            if (par == " " || par == "\0")
                break;

            OC_Sed[i] = stoi(par);
        }
    }
    file2.close();

    file3.open("MaintenanceSUV.txt", ios::in);
    while (!file3.eof())
    {
        getline(file3, item3);
        if (item3 == " " || item3 == "\0")
            break;

        for (int i = 0; i < addcar_SUV + 1; i++)
        {
            string par = parseData(item3, i);
            if (par == " " || par == "\0")
                break;
            OC_SUV[i] = stoi(par);
        }
    }
    file3.close();

    file4.open("MaintenanceLuxury.txt", ios::in);
    while (!file4.eof())
    {
        getline(file4, item4);
        if (item4 == " " || item4 == "\0")
            break;

        for (int i = 0; i < addcar_Lux + 1; i++)
        {
            string par = parseData(item4, i);
            if (par == " " || par == "\0")
                break;
            OC_Lux[i] = stoi(par);
        }
    }
    file4.close();
}
void loadCustomerData() // to load Customer Data from file to array
{
    fstream file;
    string item;
    int count = 0;
    file.open("DataCustomer.txt", ios::in);
    while (!file.eof())
    {
        getline(file, item);
        if (item == " " || item == "\0") // the loop will break after encountering the
        {                                // last line due to endl manipulator
            break;
        }
        string temp = parseData(item, 5);
        custName[count] = parseData(item, 1);
        custPat[count] = parseData(item, 2);
        custDoB[count] = ParseValue(item, 3);
        custnic[count] = parseData(item, 4);
        custPhone[count] = parseData(item, 5);
        custdl[count] = parseData(item, 6);
        custdlexp[count] = parseData(item, 7);
        custaddress[count] = parseData(item, 8);
        count++;
        //   cout<<temp<<endl;
    }
    customer_count = count;
    file.close();
}
void loadRentalPrices() // to load Rental Prices from file to global variables
{
    fstream file;
    string item;
    file.open("RentPrices.txt", ios::in);
    getline(file, item);
    rent_econ = ParseValue(item, 1);
    rent_luxury = ParseValue(item, 4);
    rent_sedan = ParseValue(item, 2);
    rent_suv = ParseValue(item, 3);
    file.close();
}
void loadIncome() // to populate income array with data from file
{
    fstream file;
    string item;
    int count = 0;
    file.open("RentalIncome.txt", ios::in);
    while (!file.eof())
    {
        getline(file, item);
        if (item == " " || item == "\0") // the loop will break after encountering
            break;                       // last line due to endl manipulator.
        for (int i = 0; i < incomeC; i++)
            incomerentalA[count] = ParseValue(item, i);
        count++;
    }
    file.close();
    customer_count = count;
}
void loadStatus() // to load booking status of each car from
{                 // file to array
    fstream file;
    string item;
    int count = 0;
    file.open("StatusEcon.txt", ios::in);
    while (!file.eof())
    {
        getline(file, item);
        if (item == " " || item == "\0") // at last line,the loop will break.
            break;

        scheduleddatesE[count] = ParseValue(item, 1);
        checkEcon[count] = ParseValue(item, 2);
        count++;
    }
    file.close();
    dateEc = count;

    fstream file2;
    string item2;
    int count2 = 0;
    file2.open("StatusSedan.txt", ios::in);
    while (!file2.eof())
    {
        getline(file2, item2);
        if (item2 == " " || item2 == "\0")
            break;

        scheduleddatesSE[count2] = ParseValue(item2, 1);
        checkSed[count2] = ParseValue(item2, 2);
        count2++;
    }
    file2.close();
    dateSed = count2;

    fstream file3;
    string item3;
    int count3 = 0;
    file3.open("StatusSUV.txt", ios::in);
    while (!file3.eof())
    {
        getline(file3, item3);
        if (item3 == " " || item3 == "\0")
            break;

        scheduleddatesSUV[count3] = ParseValue(item3, 1);
        checkSUV[count3] = ParseValue(item3, 2);
        count3++;
    }
    file3.close();
    dateSUV = count3;

    fstream file4;
    string item4;
    int count4 = 0;
    file4.open("StatusEcon.txt", ios::in);
    while (!file4.eof())
    {
        getline(file4, item4);
        if (item4 == " " || item4 == "\0")
            break;

        scheduleddatesLUX[count4] = ParseValue(item4, 1);
        checkLux[count4] = ParseValue(item4, 2);
        count4++;
    }
    file4.close();
    dateLux = count4;
}