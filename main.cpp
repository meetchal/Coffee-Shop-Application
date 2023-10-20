// Mitchell Harrington

// This program acts like a coffee shop, with multiple commands made for the manager, and one for the cashier. You can buy coffee(cashier), see how many sizes were sold for the day(manager), see how many ounces of coffee were sold for the day(manager), and view revenue for the day(manager). You can quit to close the shop.


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


//Global variables for prices and ounces, as specified in the program instructions.
double largeCoffee = 2, mediumCoffee = 1.90, smallCoffee = 1.75;
int smlOz = 9, medOz = 12, lrgOz = 15;


//Function initialization.
void showMainMenu();
void buyCoffee(double &totSmall, double &totMedium, double &totLarge);
void cupsSold(double totalSmall, double totalMedium, double totalLarge);
void coffeeSold(double totalSmall, double totalMedium, double totalLarge);
void totalRevenue(double totalSmall, double totalMedium, double totalLarge);
void printReceipt(int am1, int am2, int am3);


//Main handles the users choice, with if-else statements, after mainmenu has been called.
int main() {
  
  //Variable declaration.
  double totalSmall = 0, totalMedium = 0, totalLarge = 0;
  double& totSmall = totalSmall;
  double& totMedium = totalMedium;
  double& totLarge = totalLarge;
  string choice;

  //Loop will run until user enters "quit" on the main menu, closing the shop. 
  bool quit = true;
  while (quit == true){
    
    //Main menu function is always called before receiving input in choice.
    showMainMenu();
    cin >> choice;

    //Calls buyCoffee function if the choice is buyCoffee. Clears the variable 'choice' after the function has been run, taking you back the to main menu.
    if (choice == "buyCoffee"){
      
      //Passes the total coffee cup sizes by reference, so the program can run multiple times and retain and update values until the shop is closed.
      buyCoffee(totSmall, totMedium, totLarge);
      cin.clear();
    }
      
    //Calls cupsSold function if the choice is cupsSold. Clears the variable 'choice' after the function has been run, taking you back to the main menu. Displays the cup sizes sold for the day.
    else if (choice == "cupsSold"){
      //Passes the coffee cup sizes sold by current values.
      cupsSold(totalSmall, totalMedium, totalLarge);
      cin.clear();
    }
    //Calls coffeeSold function if the choice is coffeeSold. Clears the variable 'choice' after the function has been run, taking you back to the main menu.
    else if (choice == "coffeeSold"){
      //Passes the total coffee cup sizes sold by current values, and passes the global oz variables by value. Calculates the coffee oz sold for the day.
      coffeeSold(totalSmall, totalMedium, totalLarge);
      cin.clear();
    }
      //Calls totalRevenue function if the choice is revenue. Clears the variable 'choice' after the function has been run, taking you back to main menu.
    else if (choice == "revenue"){
      //Passes the total cup sizes sold, and the price of each size of coffee to calculate the total revenue made for the day. 
      totalRevenue(totalSmall, totalMedium, totalLarge);
    }
      
    //Quits the program if the choice is 'quit'. Closes the shop.
    else if (choice == "quit"){
      cout << "The coffee shop is now closed. Run the program to open it again. Thank you!";
      //Exits the main menu loop since quit is now false.
      quit = false; 
    }
      
    //Will reject input if it's unknown. 
    else{
      cout << endl <<"Please input a valid command." << endl << endl;
    }  
  } 
}

//When the program starts, it shows the main menu, created in this function. Output is formatted with parameters left and right justified to view the commands easily on output.
void showMainMenu(){
  
  //The command output is left justified with 15 characters, and the description is right justified by 43 characters.
  cout << endl << setw(15) << left << "COMMAND";
  cout << setw(43) << right << "DESCRIPTION" << endl;
  cout << "==========================================================" << endl;

  cout << setw(15) << left << "buyCoffee";
  cout << setw(43) << right << "Buy coffee, and view the menu." << endl << endl;

  cout << setw(15) << left << "cupsSold";
  cout << setw(43) << right << "Coffee sizes sold for the day." << endl << endl;

  cout << setw(15) << left << "coffeeSold";
  cout << setw(43) << right << "View ounces of coffee sold for the day." << endl << endl;

  cout << setw(15) << left << "revenue";
  cout << setw(43) << right << "View revenue for the day." << endl << endl;

  cout << setw(15) << left << "quit";
  cout << setw(43) << right << "Close the shop for the day." << endl;

  cout << "==========================================================" << endl;
  //Command prompt.
  cout << "Enter Command: ";
}


//*totsmall, *totmedium, and *totallarge reference the cup sizes defined in main().
void buyCoffee(double &totSmall, double &totMedium, double &totLarge){
  //Variables initialized so the user can enter how many coffees they want to purchase.
  int numSmall = 0, numMedium = 0, numLarge = 0;
  string size;
  //Enters another loop for the coffee menu, until user exits.
  int am1 = 0, am2 = 0, am3 = 0;
  bool quit2 = true;
  while(quit2 == true){
    //Displays menu with the coffees justified on the left 15 characters, as well as prices and ounces of the coffee on the right, justified by 15 characters.
    cout << endl << "MENU" << endl;
    cout << "==============================" << endl;
    cout << setw(15) << left << "Small Coffee";
    cout << setw(15) << right << "9oz - 1.75$" << endl << endl;
      
    cout << setw(15) << left << "Medium Coffee";
    cout << setw(15) << right << "12oz - 1.90$" << endl << endl;

    cout << setw(15) << left << "Large Coffee";
    cout << setw(15) << right << "15oz - 2.00$" << endl;
    cout << "==============================" << endl;

    //User prompt.
    cout << "Enter small, medium, or large. Enter quit to view your receipt (if you purchased anything) and/or return to the main menu: ";
    cin >> size;
    cout << endl;
    
    //If the size is small, it enters another loop for how many the user would like to purchase. 
    if (size == "small"){
      bool quit3 = true;
      while (quit3 == true){
        
        //User prompt.
        cout << "How many would you like to purchase? ";
        cin >> numSmall;
        cout << endl;
        
        //if input is a positive number, it'll add it to the total cup count in main() and to the counter for the current receipt. If not a positive number, it asks again for correct input until it's correct. After the user quits, it sets quit2 to false to go to main menu after printing the receipt.
        if (numSmall > 0){
          
          totSmall += numSmall;
          am1 += numSmall;
          cout << "Anything else?" << endl;
          cin.clear();
          quit3 = false;
        }
        else if (numSmall != 0){
          cout << "Invalid input." << endl;
          cin.clear();
          cin.get();
        }
        else{
          cout << "Invalid input." << endl;
          cin.clear();
          cin.get();
        }
      }
    }
      
    //Another loop for the medium size. All three size loops work exactly the same.
    if (size == "medium"){
      bool quit3 = true;
      while (quit3 == true){
        cout << "How many would you like to purchase? ";
        cin >> numMedium;
        cout << endl;
        if (numMedium > 0){
          totMedium += numMedium;
          am2 += numMedium;
          cout << "Anything else?" << endl;
          cin.clear();
          quit3 = false;
        }
        else if (numMedium != 0){
          cout << "Invalid input." << endl;
          cin.clear();
          cin.get();
        }
        else{
          cout << "Invalid input." << endl;
          cin.clear();
          cin.get();
        }
      }
    }
      
    //Another loop for the large size. All three size loops work exactly the same.
    if (size == "large"){
      bool quit3 = true;
      while (quit3 == true){
        cout << "How many would you like to purchase? ";
        cin >> numLarge;
        cout << endl;
        if (numLarge > 0){
          totLarge += numLarge;
          am3 += numLarge;
          cout << "Anything else?" << endl;
          cin.clear();
          quit3 = false;
        }
        else if (numLarge != 0){
          cout << "Invalid input." << endl;
          cin.clear();
          cin.get();
        }
        else{
          cout << "Invalid input." << endl;
          cin.clear();
          cin.get();
        }
      }
    }
    else if (size == "quit"){
      if (numLarge > 0 || numMedium > 0 || numSmall > 0){
        printReceipt(am1, am2, am3);
        cin.clear();
        quit2 = false;
      }
      else{
        cin.clear();
        quit2 = false;
      }  
    }
  }
}


//Prints the receipt after purchasing coffee. Passes the the size purchased to calculate the total cost for the receipt.
void printReceipt(int am1, int am2, int am3){
  double orderTotal = 0;
  
  //Prints receipt for the large coffee bought.

  orderTotal += (am3 * largeCoffee);
  
  //Again, formats the output like the rest of the program. Same for the next 2 receipts.
  cout << "RECEIPT" << endl;
  cout << "==============================" << endl;
  cout << am3 << " Large Coffee";
  cout << setw(15) << right << "$2.00/each.";
  cout << endl;

  
//Prints receipt for the medium coffee bought. Same as the first one.

  orderTotal += (am2 * mediumCoffee);
  cout <<endl;
  cout << am2 << " Medium Coffee";
  cout << setw(15) << right << "$1.90/each.";
  cout << endl;


  
//Prints receipt for the small coffee bought. Same as the first one.

  orderTotal += (am1 * smallCoffee);
  cout << endl;
  cout << am1 << " Small Coffee";
  cout << setw(15) << right << "$1.75/each." << endl << endl;
  cout << "Order Total: ";
  cout << fixed << setprecision(2) << setw(12) << right << "$" << orderTotal << endl << endl;
  cout << "Thank you, please come again!" << endl;
  cout << "==============================" << endl << endl;

}


//Shows the cups sold for the day, passing the total cup sizes by value.
void cupsSold(double totalSmall, double totalMedium, double totalLarge){
  
  //Formatting like the rest of the program.
  cout << endl << "COFFEE SIZES SOLD TODAY:" << endl;
  cout << "========================" << endl;
  cout << setw(8) << left << "Small";
  cout << fixed << setprecision(0) << setw(16) << right << totalSmall << endl << endl;

  cout << setw(8) << left << "Medium";
  cout <<  fixed << setprecision(0) << setw(16) << right << totalMedium << endl << endl;

  cout << setw(8) << left << "Large";
  cout <<  fixed << setprecision(0) << setw(16) << right << totalLarge << endl;

  cout << "========================" << endl;
  }

//Calculates coffee sold in oz for the day. Passes the cup sizes sold, as well as the size oz amounts by value.
void coffeeSold(double totalSmall, double totalMedium, double totalLarge){
  int ozTotal = (totalSmall * smlOz) + (totalMedium * medOz) + (totalLarge * lrgOz);
  
  //Formatting like the rest of the program.
  cout << endl << "COFFEE OUNCES SOLD TODAY:" << endl;
  cout << "========================" << endl;
  
  cout << setw(16) << left << "Today's Total:";
  cout << fixed << setprecision(0) << setw(8) << right << ozTotal << endl;

  cout << "========================" << endl;
}

//Calculates the revenue (coffee sold) for the day and displays it.
void totalRevenue(double totalSmall, double totalMedium, double totalLarge){

  double totalRev = (totalSmall * smallCoffee) + (totalMedium * mediumCoffee) + (totalLarge * largeCoffee);
  
  //Formatting like the rest of the program.
  cout << endl << "TOTAL REVENUE TODAY" << endl;
  cout << "=============================" << endl;
  
  cout << setw(16) << left << "Today's Revenue:";
  cout << fixed << setprecision(2) << setw(8) << right << "$" << totalRev << endl;

  cout << "=============================" << endl;
  
}