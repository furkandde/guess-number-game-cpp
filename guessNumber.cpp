// guessNumber.cpp
// Furkan Dede,18015010

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	const int minvalue = 1023, maxvalue = 9876; 
    
	int targetNumber, guessNumber, nDigitsAtRightPlace = 0, nDigitsAtWrongPlace, guessAttemps = 0, guessedDigits = 0;
    int guessNumberDigits[4] = {0, 0, 0, 0};
    int targetNumberDigits[4] = {0, 0, 0, 0};
	
	cout << "\nWelcome to 'Guess the number game'\n\n";
    cout << "Task: Enter a 4-digit number, in a range of [1023 - 9876] having each of the digits\n";
    cout << "different from others to guess the random target number given by the computer\n" << endl;

    Start:
    srand(time(0));
    
    targetNumber = (rand() % ( maxvalue-minvalue+1)) +minvalue; //Create a random target number
    
	// Aimed to seperate targetnumber to digits.
    int digit = targetNumber;  
    int c = 3;
    while (digit > 0)
	{
        targetNumberDigits[c] = digit % 10;
        digit /= 10;
        c--;
    } 
	
	//We are checking digits are same or not.
    for (int n = 0; n < 4; n++)  
        for (int m = n + 1; m < 4; m++)
            if (targetNumberDigits[n] == targetNumberDigits[m])
                goto Start;

 
    //cout << targetNumber<< endl; 
    while (!(nDigitsAtRightPlace == 4)){
        Repeat:
        nDigitsAtRightPlace = 0;
        guessedDigits = 0;
        cout << "Enter a 4-digit number:" <<endl;
        cin >> guessNumber;
		
		//We are checking guessNumber is 4-digit number or not.
		if(!(guessNumber<=9999 && guessNumber>=1000)){
			cout << "Enter a suitable number! Your number is not available. "<< endl;
            goto Repeat;
			
		}

        //Aimed to seperate guessNumber to digits.
        digit = guessNumber;
        c = 3;
        while (digit > 0){
            guessNumberDigits[c] = digit % 10;
            digit /= 10;
            c--;
        }
        
        //we are checking digits are same or not.
        for (int n = 0; n < 4; n++)
        {
            for (int m = n + 1; m < 4; m++)
            {
                if (guessNumberDigits[n] == guessNumberDigits[m])
                {
                    cout << "Enter a suitable number! Your number is not available. "<< endl;
                    goto Repeat;
                }
            }
        }
        
        //We are checking guessed digits
        for (int n = 0; n < 4; n++)
            for (int m = 0; m < 4; m++)
                if (guessNumberDigits[n] == targetNumberDigits[m])
					
                    guessedDigits++;

        //We are checking the places of guessed digits
        for (int m = 0; m < 4; m++)
            if (guessNumberDigits[m] == targetNumberDigits[m])
                nDigitsAtRightPlace++;
    
   
    nDigitsAtWrongPlace = guessedDigits -  nDigitsAtRightPlace;
	
	//Display the comparison result
	if(nDigitsAtRightPlace == 0){
		cout<< "-" << nDigitsAtWrongPlace << endl;
	}else if(nDigitsAtWrongPlace == 0){
		cout<< "+" << nDigitsAtRightPlace << endl;	
	}else{
		cout << "+" << nDigitsAtRightPlace << "  -" << nDigitsAtWrongPlace << endl;
	}
     
    guessAttemps++;
    } 
    cout << "Congratulations! You've found the target number in " << guessAttemps << " attempts." << endl;
    return 0;
}
