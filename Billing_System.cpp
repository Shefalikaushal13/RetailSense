#include <iostream>  
#include <fstream>   
#include <sstream>   
#include <windows.h> 


using namespace std;

class Bill;

void addItem(Bill b);
void printBill();


class Bill {
private:
    string Item;   
    int Rate;     
    int Quantity;  

public:
    
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void setItem(string item) {
        Item = item;
    }

    void setRate(int rate) {
        Rate = rate;
    }

    void setQuant(int quant) {
        Quantity = quant;
    }

    string getItem() {
        return Item;
    }

    int getRate() {
        return Rate;
    }

    int getQuant() {
        return Quantity;
    }
};

void addItem(Bill b) {
    bool close_add_menu = false; // Flag to control the loop for adding items
    while (!close_add_menu) {
        system("cls"); 
        int choice;
        cout << "\t1.Add Item." << endl;
        cout << "\t2.Back To Main Menu." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            string item_name;
            int item_rate, item_quant;

            cout << "\tEnter Item Name (no spaces): "; 
            cin >> item_name;
            b.setItem(item_name);

            cout << "\tEnter Rate Of Item: ";
            cin >> item_rate;
            b.setRate(item_rate);

            cout << "\tEnter Quantity Of Item: ";
            cin >> item_quant;
            b.setQuant(item_quant);

            ofstream out("Bill.txt", ios::app);
            if (!out.is_open()) { 
                cout << "\tError: File 'Bill.txt' cannot be opened or created!" << endl;
                cout << "\tPlease check permissions or disk space." << endl;
            } else {
                
                out << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl;
                out.close(); 
                cout << "\tItem Added Successfully!" << endl;
            }
            Sleep(2000); // Pause for 2 seconds to show message
        } else if (choice == 2) {
            system("cls");
            close_add_menu = true; 
            cout << "\tReturning To Main Menu!" << endl;
            Sleep(2000); 
        } else {
            cout << "\tInvalid Choice! Please try again." << endl;
            Sleep(2000);
        }
    }
}


void printBill() {
    system("cls");
    int total_bill_amount = 0; 

    bool close_billing_session = false; 
    while (!close_billing_session) {
        system("cls"); 
        int choice;
        cout << "\tCurrent Total Bill: " << total_bill_amount << endl;
        cout << "\t--------------------------------------" << endl;
        cout << "\t1. Add Item to Current Bill." << endl;
        cout << "\t2. End Billing Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            string item_to_buy_name;
            int quantity_to_buy;
            cout << "\tEnter Item Name: ";
            cin >> item_to_buy_name;
            cout << "\tEnter Quantity: ";
            cin >> quantity_to_buy;
            
            ifstream in_file("Bill.txt");
            ofstream out_temp_file("Bill Temp.txt");

            if (!in_file.is_open()) {
                cout << "\tError: Inventory file 'Bill.txt' not found or cannot be opened!" << endl;
                Sleep(2000);
                continue; 
            }
            if (!out_temp_file.is_open()) {
                cout << "\tError: Temporary file 'Bill Temp.txt' cannot be created or opened!" << endl;
                in_file.close(); 
                Sleep(2000);
                continue; 
            }

            string line;
            bool item_found = false;
            bool item_billed = false;

            
            while (getline(in_file, line)) {
                stringstream ss;
                ss << line;
                string stored_itemName;
                int stored_itemRate, stored_itemQuant;
                char delimiter1, delimiter2;

                if (!(ss >> stored_itemName >> delimiter1 >> stored_itemRate >> delimiter2 >> stored_itemQuant)) {
                    out_temp_file << line << endl;
                    continue;
                }

                if (item_to_buy_name == stored_itemName) {
                    item_found = true;
                    if (quantity_to_buy <= stored_itemQuant) {
                        int current_item_amount = stored_itemRate * quantity_to_buy;
                        cout << "\t--------------------------------------" << endl;
                        cout << "\t Item   | Rate   | Quantity | Amount" << endl;
                        cout << "\t" << stored_itemName << "\t " << stored_itemRate << "\t " << quantity_to_buy << "\t " << current_item_amount << endl;
                        cout << "\t--------------------------------------" << endl;

                        int new_quantity_in_stock = stored_itemQuant - quantity_to_buy;
                        stored_itemQuant = new_quantity_in_stock; 

                        total_bill_amount += current_item_amount;
                        item_billed = true; 
                    } else {
                        cout << "\tSorry, " << item_to_buy_name << " is out of stock or quantity requested is too high!" << endl;
                        cout << "\tAvailable Quantity: " << stored_itemQuant << endl;
                    }
                }
                out_temp_file << stored_itemName << " : " << stored_itemRate << " : " << stored_itemQuant << endl;
            }

            in_file.close();      
            out_temp_file.close(); 

            if (!item_found) {
                cout << "\tItem '" << item_to_buy_name << "' not found in inventory!" << endl;
            } else if (!item_billed) {
                cout << "\tCould not add " << item_to_buy_name << " to bill due to quantity issue." << endl;
            } else {
                cout << "\tItem(s) added to bill. Inventory updated." << endl;
            }

        
            if (remove("Bill.txt") != 0) {
                perror("\tError deleting old inventory file (Bill.txt)");
            }
            if (rename("Bill Temp.txt", "Bill.txt") != 0) {
                perror("\tError renaming temporary file to Bill.txt");
            }
            Sleep(2000); 

        } else if (choice == 2) {
            close_billing_session = true; 
            cout << "\tEnding Billing Session. Finalizing Bill..." << endl;
            Sleep(2000);
        } else {
            cout << "\tInvalid Choice! Please try again." << endl;
            Sleep(2000);
        }
    }

    
    system("cls");
    cout << endl << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\t Total Bill: " << total_bill_amount << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\tThanks For Shopping!" << endl;
    Sleep(5000); 
}


int main() {
    Bill b; 

    bool exit_program_flag = false; 
    while (!exit_program_flag) {
        system("cls"); 
        int main_menu_choice;

        cout << "\tWelcome To Super Market Billing System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t\t1. Add New Item to Inventory." << endl;
        cout << "\t\t2. Start New Customer Bill." << endl;
        cout << "\t\t3. Exit Program." << endl;
        cout << "\t\tEnter Choice: ";
        cin >> main_menu_choice;

        if (main_menu_choice == 1) {
            addItem(b); 
        } else if (main_menu_choice == 2) {
            printBill(); 
        } else if (main_menu_choice == 3) {
            system("cls");
            exit_program_flag = true; 
            cout << "\tExiting Super Market Billing System." << endl;
            cout << "\tGood Luck!" << endl;
            Sleep(2000); 
        } else {
            cout << "\tInvalid Choice! Please enter 1, 2, or 3." << endl;
            Sleep(2000);
        }
    }
    return 0; 
}
