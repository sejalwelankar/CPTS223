/***********************************************************************
 * Advantage Link List -
 * You can have as many commamnds as you want. We do not have a limit on the number of elements.
 *
 * Disadvantage Link List -
 * For generating random options, I have to traverse through the link list three times in the worst case scenario.
 *
 *
 * Advantage Array -
 * We can generate random options easily as we can just generate random indices. We do not need to traverse array to get to a random element
 *
 *
 * Disadvantage Array -
 * There is a limit to the number of users we can add. We  waste memory by creating a large array to fit all the potential users
 *****************************************************************************/
#include "header.h"
int main()
{
    srand(time(0)); // for random seed generation

    //First let us create the linked list and user array
    int User_Array_Count = 0;
    LinkedList <string, string>  Game; // This linkedList will be loaded with all the commands and descriptions
    ifstream fp;
    fp.open("./commands.csv");
    string name, buffer, description;
    if (fp.is_open())
    {
        while (!fp.eof())
        {
            getline(fp, name, ',');
            //getline(fp, buffer, '"');
            getline(fp, description, '\n');
            //getline(fp, buffer, '\n');
            Game.populate(name, description);

        }
    }
    //In case file isn't opened properly, end game.
    else
    {
        cout << "Error opening file please make sure the correct path is used. ";
        return 0;
    }
    fp.close();
    //Creating User Array
    Profiles Array[100];
    ifstream fptr2;
    fptr2.open("./profiles.csv");
    if (fptr2.is_open())
    {

        while (!fptr2.eof())
        {
            string name, num;
            getline(fptr2, name, ',');
            if (name != "\n")
            {
                getline(fptr2, num, '\n');
                int number = stoi(num);
                add_user(Array, User_Array_Count, name, number);

                /*if (User_Array_Count == 0)
                {
                    Array[0].Add(name, number);
                    User_Array_Count++;
                }
                else
                {
                    for (int i = User_Array_Count; i < 0; i--)
                    {
                        Array[i] = Array[i - 1];
                    }
                    Array[0].Add(name, number);
                    User_Array_Count++;
                }*/
            }
        }
       

    }
    else
    {
        cout << "\n\nError opening file. Please check the path";
    }
    fptr2.close();
    int choice;
    do
    {
       choice = menu();
        switch(choice)
        {
            case 1:
                print_rules();
                break;
            case 2:
                Game.new_round(Array, User_Array_Count);
                break;
            case 3:
                Game.load_old_user(Array, User_Array_Count);
                break;
            case 4:
                Game.add_to_list();
                break;
            case 5:
                Game.remove_command();
                break;

        }

    } while( choice != 6);

    ofstream filewrite("./profiles.csv");
    for (int i = 0; i < User_Array_Count; i++)
    {
        if (i == 0)
        {
            filewrite  << Array[i].return_name() << "," << Array[i].return_score();
            filewrite.flush();
        }
        else
        {
            filewrite << "\n" << Array[i].return_name() << "," << Array[i].return_score();
        }
    }
    Game.exit();
    return 0;
}


