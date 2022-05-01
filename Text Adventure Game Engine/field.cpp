#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void testOtherFile(); //Used to test if I can access the other .cpp file.

void userInput(string userCommand, string currentRoom, string roomDescription, string roomUP, string roomBACK, string roomLEFT, string roomRIGHT, int playerHealthPoints, int suitPower) //Process user input.
{
    if (userCommand == "LOOK" || userCommand == "look" || userCommand == "Look") //Check if the player typed LOOK into the command line.
        {
            cout << roomDescription << endl; //Output description.
        }
    else if (userCommand == "HELP" || userCommand == "help" || userCommand == "Help") //Check if the player typed HELP into the command line.
        {
            cout << "LOOK: Describe your player's surroundings." << endl;
            cout << "MOVE <PARAMETER>: Move in the direction specified." << endl;
            cout << "CHECK <PARAMETER>: Check an object specified." << endl;
            cout << "TAKE <PARAMETER>: Take an object specified." << endl;
            cout << "HP: Display your HP (Health Points)." << endl;
            cout << "SUIT: Display your SP (Suit Power)." << endl;
            cout << "ITEMS: Display your inventory." << endl;
            cout << "EQUIP <PARAMETER>: Equip a specified item." << endl;
            cout << "HELP: Show a list of commands." << endl;
            cout << "QUIT or EXIT: Quits the game." << endl;
        }
    else if (userCommand == "CHECK") //User requests to check something.
        {
            cout << "Not yet implemented (lol)." << endl; //To do: implement check function.
        }
            else if (userCommand == "HP") //User requests to see HP.
        {
            cout << "Your current HP is " << playerHealthPoints << "/100" << endl; //Display HP.
        }
    else if (userCommand == "SUIT") //User requests to see SP.
        {
            cout << "Your suit's power level is at " << suitPower << "%" << endl; //Display SP.
        }
    else //If the player inputs an unrecognized command, the game will display an error message.
        {
            cout << "Unknown command. Type HELP for a list of commands." << endl;
        }
}

string movePlayer(string userCommand, string currentRoom, string roomUP, string roomBACK, string roomLEFT, string roomRIGHT) //Move the player based on user-defined direction.
{
    if (userCommand == "MOVE" || userCommand == "move" || userCommand == "Move") //Player does not specify a direction.
        {
            cout << "Please specify a direction." << endl; //Display error message.
            return currentRoom; //Return value of current room which should not have changed.
        }
    else if (userCommand == "MOVE UP" || userCommand == "move up" || userCommand == "Move up" || userCommand == "Move up" || userCommand == "move Up") //Player requested to move up.
        {
            currentRoom = roomUP; //Set current room to roomUP.
            return currentRoom; //Return the new value of the current room.
        }
    else if (userCommand == "MOVE LEFT") //Player requested to move left.
    {
        if (roomLEFT == "none") //If there is no room to the left.
        {
            cout << "You can't go that way." << endl; //Display error message.
            return currentRoom; //Return value of current room which should not have changed.
        }
    }
}

int main()
{
    string userCommand; //This variable stores the command that the player will input to control the game.
    string currentRoom; //The room that the character is currently in.
    string roomDescription; //Description of the room when entering the LOOK command.
    string roomUP; //The room the player will enter if he/she types "MOVE UP"
    string roomBACK; //The room the player will enter if he/she types "MOVE BACK"
    string roomLEFT; //The room the player will enter if he/she types "MOVE LEFT"
    string roomRIGHT; //The room the player will enter if he/she types "MOVE RIGHT"
    int playerHealthPoints; //The player's Health Points (HP).
    playerHealthPoints = 100;
    const int MAX_HP = 100; //Player's max HP is 100.
    int suitPower; //The player's suit power (if the player has suit power, the player will take less damage at the cost of suit power).
    suitPower = 0;
    const int MAX_SUIT_POWER = 100; //Player's max SP is 100;
    bool gameEnd = false; //The game will run as long as this variable is set to false.
    while (gameEnd == false) //Run the game while it's not over.
    {
        roomDescription = "This is the starting room."; //Set the room description.
        currentRoom = "START"; //Set the player to the starting room.
        roomUP = "SECOND"; //Sets the room the player will enter if he/she types "MOVE UP".
        roomBACK = "none"; //Sets the room the player will enter if he/she types "MOVE BACK".
        roomLEFT = "none"; //Sets the room the player will enter if he/she types "MOVE LEFT".
        roomRIGHT = "none"; //Sets the room the player will enter if he/she types "MOVE RIGHT".
        cout << "Welcome" << endl; //This is the message the player will see when he/she enters a new room.

        while (currentRoom == "START")
        {
            getline(cin, userCommand); //This is when the player inputs a command.
            if (userCommand == "MOVE" || userCommand == "move" || userCommand == "Move" || userCommand == "MOVE UP" || userCommand == "move up" || userCommand == "Move up" || userCommand == "Move up" || userCommand == "move Up" || userCommand == "MOVE BACK" || userCommand == "move back" || userCommand == "Move back" || userCommand == "Move back" || userCommand == "move Back" || userCommand == "MOVE LEFT" || userCommand == "move left" || userCommand == "Move left" || userCommand == "Move up" || userCommand == "move Up") //The user will move. There has to be a better way to do this.
            {
                currentRoom = movePlayer(userCommand, currentRoom, roomUP, roomBACK, roomLEFT, roomRIGHT); //Move the player.
            }
            else if (userCommand == "TEST") //Test command.
            {
                testOtherFile();
            }
            else if (userCommand == "QUIT" || userCommand == "Quit" || userCommand == "quit") //Quit the game.
            {
                return 0; //Jump out of the program.
            }
            else //Forward command to userInput.
            {
                userInput(userCommand, currentRoom, roomDescription, roomUP, roomBACK, roomLEFT, roomRIGHT, playerHealthPoints, suitPower);
            }
        }

    if (currentRoom == "SECOND")
    {
        roomDescription = "This is the second room."; //Set the room description.
        cout << "You move into the second room." << endl; //Tell the player that they're moving to the second room.
        while (currentRoom == "SECOND")
            {
                getline(cin, userCommand); //This is when the player inputs a command.
                if (userCommand == "MOVE" || userCommand == "move" || userCommand == "Move" || userCommand == "MOVE UP" || userCommand == "move up" || userCommand == "Move up" || userCommand == "Move up" || userCommand == "move Up" || userCommand == "MOVE BACK" || userCommand == "move back" || userCommand == "Move back" || userCommand == "Move back" || userCommand == "move Back" || userCommand == "MOVE LEFT" || userCommand == "move left" || userCommand == "Move left" || userCommand == "Move up" || userCommand == "move Up")
                    {
                        currentRoom = movePlayer(userCommand, currentRoom, roomUP, roomBACK, roomLEFT, roomRIGHT);
                    }
                else if (userCommand == "QUIT" || userCommand == "Quit" || userCommand == "quit") //Quit the game.
                    {
                        return 0; //Jump out of the program.
                    }
                else
                    {
                        userInput(userCommand, currentRoom, roomDescription, roomUP, roomBACK, roomLEFT, roomRIGHT, playerHealthPoints, suitPower);
                    }
            }
        }
    }
    return 0; //End program.
}
