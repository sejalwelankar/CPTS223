#include "header.h"

int check_user(Profiles* arr, int count, string user)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i].return_name() == user)
        {
            cout << "\nUser already exists.";
            cout << "\nPoints scored will be added to this player's score.";
            cout << "\n Current score is : " << arr[i].return_score();
            return i;

        }


    }
    return -1;
}

void add_user(Profiles arr[], int& count, string user, int score)
{
    if ((count) == 0)
    {
        arr[0].Add(user, score);
        (count)++;
    }

    else
    {
        int i;
        for (i = 0; i < count; i++)
        {
           /* string nm = arr[i - 1].return_name();
            int m = arr[i - 1].return_score();
            arr[i].Add(nm, m);
            arr[i].operator=*/
            arr[count - i] = arr[count - i -1];

        }
        arr[0].Add(user, score);
        (count)++;
    }

}



// This function prints the menu and prompts user for an input
int menu()
{
    cout << "1. Game Rules\n";
    cout << "2. Play Game\n";
    cout << "3. Load Previous Game\n";
    cout << "4. Add Command\n";
    cout << "5. Remove Command\n";
    cout << "6. Exit\n";
    
    int choice = 0;
    while (choice <= 0 || choice > 6)
    {
        cin >> choice;
        if (choice != 0)
        {
            cout << "\n Please choose a option - ";
        }
    }
    return choice;
}

//This function prints rules from a file called rules.txt HAVE TO FIGURE OUT HOW TO MAKE FILE
void print_rules()
{
    ifstream fp;
    fp.open("Rules.txt");
    string line;
    if (!fp.is_open())
    {
        cout << "\n Problem in opening file. Please make sure that the correct path is being used. ";
    }
    while (!fp.eof() && fp.is_open())
    {
        getline(fp, line);
        cout << line << endl;
    }
    fp.close();


}



