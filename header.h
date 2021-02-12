//
// Created by seal on 2/6/21.
//

#ifndef PA1_HEADER_H
#define PA1_HEADER_H

#include <iostream>
#include <fstream>
#include<string>
#include<ctime>
#include <vector>
//#include"Profiles.h"
using namespace std;


class Profiles
{
private:
    string name;
    int score;

public:
    Profiles()
    {
        score = 0;
    }
    Profiles(string n, int b)
    {
        name = n;
        score = b;
    }
    void Add(string n, int b)
    {
        name = n;
        score = b;
    }

    string return_name()
    {
        return name;
    }
    int return_score()
    {
        return score;
    }
    void update_score(int k)
    {
        score = score + k;

    }


    void operator = (const Profiles& a)
    {
        this->name = a.name;
        this->score = a.score;
    }
    //~Profiles();

};

void print_rules();
int menu();
void add_user(Profiles arr[], int& count, string user, int score);
int check_user(Profiles* arr, int count, string user);

//The template class and it's member functions.
template <class T, class U>
class LinkedList
{
private:
    struct ListNode
    {
        T name;
        U description;
        int used = 0;
        ListNode* next;
    };
    ListNode* Headpointer;
    int number_of_nodes = 0;

public:
    //default constructor
    LinkedList()
    {
        Headpointer = nullptr;
    }

    LinkedList(T n, U d)
    {
        Headpointer = nullptr;

    }
    //function to load
    void populate(T n, U d);
    bool isEmpty();
    void print_command(int k);
    void print_description(int k);
    int question_generator();
    bool check_availability(int k);
    void add_to_list();
    void change_count(int k)
    {
        number_of_nodes = number_of_nodes + k;
    }
    void remove_command();
    bool find_command(T find);
    bool check_existence(T find);
    void round(Profiles* ptr)
    {
        string buffer;
        do{
            cout << "\n Press any key to continue";
        }while(buffer != "\0");


        //system("clear");
        int score = 0;
        int repetitions = 0;
       
        do 
        {
            cout << "\nEnter the number of questions you want to attempt. Choose a number between 5 - 30  :  ";
            cin >> repetitions;
        } while (repetitions < 5 || repetitions >30);
        for (int i = 0; i < repetitions; i++)
        {
            score = score + question_generator();
        }
        ptr->update_score(score);
        cout << "\nYour point total is " << ptr->return_score() << endl;




    }
    void exit()
    {
       ;
        ofstream ptr("./commands.csv");
        ListNode *temp = Headpointer;
        ptr << temp->name << "," << temp->description;
        temp = temp->next;
        while (temp != nullptr)
        {
            ptr << "\n" << temp->name << "," << temp->description  ;
            temp = temp->next;
        }
        ptr.close();
       
    };    
    void new_round(Profiles *Arr, int& user_count);
    void load_old_user(Profiles *Arr, int& user_count);
    ~LinkedList()
    {
        if (!isEmpty())
        {
            ListNode *temp = Headpointer;
            temp = Headpointer;

            while (temp != nullptr)
            {
                ListNode* nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;
            }
        }
        cout << "\nList destroyed";
    }





};

template <class T, class U>
void LinkedList <T, U>::populate(T n, U d)
{
    ListNode* newNode = nullptr;

    newNode = new ListNode;

    newNode->name = n;
    newNode->description = d;
    newNode->next = nullptr;
    ListNode* tempNode = Headpointer;
    newNode->next = Headpointer;
    Headpointer = newNode;
    number_of_nodes++;


}

template <class T, class U>
bool LinkedList <T, U> ::isEmpty()
{
    if (Headpointer == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }

}

template <class T, class U>
void LinkedList <T, U>::print_command(int k)
{
    ListNode* tempNode = Headpointer;
    while (k != 0)
    {
        tempNode = tempNode->next;
        k--;
    }
    cout << tempNode->name << endl;


}

template <class T, class U>
void LinkedList <T, U>::print_description(int k)
{
    ListNode* tempNode = Headpointer;
    while (k != 0)
    {
        tempNode = tempNode->next;
        k--;
    }
    cout << tempNode->description << endl;


}

//THis question presents the options in a random order and checks whether the correct answer was picked. +1 for correct answer -1 for wrong answer.
template <class T, class U>
int LinkedList <T, U>::question_generator()
{
    int number = rand() % number_of_nodes;
    while (!check_availability(number))
    {
        number = rand() % number_of_nodes;
    }
    cout << endl;
    print_command(number);
    
    int choice2 = -1, choice3 = -1;
    do
    {
        choice2 = rand() % number_of_nodes;

        choice3 = rand() % number_of_nodes;

    } while (choice2 == number || choice3 == number || choice2 == choice3);
    int order = rand() % 6 + 1;
    /*Three lines can be arranged in 6 ways. so let us set up a switch case system.
    Suppose our lines are a, b,c then the six positions are -
    a,b,c
    a,c,b
    b,a,c
    b,c,a
    c,b,a
    c,a,b
    Here a corresponds to the number line, b corresponds to choice 1 and c corresponds to choice 2*/
    int correct_answer = 0;

    switch (order)
    {
    case 1:
        cout << "\n1. "; print_description(number);
        cout << "2. "; print_description(choice3);
        cout << "3. "; print_description(choice2);
        correct_answer = 1;
        break;

    case 2:
        cout << "\n1. "; print_description(number);
        cout << "2. "; print_description(choice2);
        cout << "3. "; print_description(choice3);
        correct_answer = 1;
        break;
    case 3:
        cout << "\n1. "; print_description(choice3);
        cout << "2. "; print_description(number);
        cout << "3. "; print_description(choice2);
        correct_answer = 2;
        break;
    case 4:
        cout << "\n1. "; print_description(choice3);
        cout << "2. "; print_description(choice2);
        cout << "3. "; print_description(number);
        correct_answer = 3;
        break;
    case 5:
        cout << "\n1. "; print_description(choice2);
        cout << "2. "; print_description(number);
        cout << "3. "; print_description(choice3);
        correct_answer = 2;
        break;
    case 6:
        cout << "\n1. "; print_description(choice2);
        cout << "2. "; print_description(choice3);
        cout << "3. "; print_description(number);
        correct_answer = 3;
        break;
    }

    cout << endl << "Enter your answer - ";
    int choice = 0;
    while (choice <= 0 || choice > 3)
    {
        cout << endl << "Your answer must be either 1, 2 or 3";
        cin >> choice;

    }

    if (choice == correct_answer)
    {
        cout << "\nCorrect!";
        cout << "\nThe correct answer is - \n";
        print_description(number);
        cout << "You gained 1 point ";
        return 1;
    }
    else
    {
        cout << "\nIncorrect :(";
        cout << "\nThe correct answer is - \n";
        print_description(number);
        cout << "You lost 1 point ";
        return -1;
    }






}

template <class T, class U>
bool LinkedList <T, U>::check_availability(int k)
{
    ListNode *tempNode = Headpointer;
    while (k != 0)
    {
        tempNode = tempNode->next;
        k = k -1;
    }
    if (tempNode->used == -1)
    {
        return false;
    }
    else
    {
        tempNode->used = -1;
        return true;
    }
}

template <class T, class U>
void LinkedList <T, U>::add_to_list()
{
    //system("cls");

    cout << "Enter the command name \n";
    T nm;
    cin >> nm;
    while (check_existence(nm) == true)
    {
        cout << "\nEnter a unique command";
        cin >> nm;
    }
    cout << "Enter the description \n";
    U dsp;
    cin >> dsp;
    populate(nm, dsp);
    number_of_nodes++;



}

template <class T, class U>
void LinkedList <T, U> ::remove_command()
{
    //system("cls");
    T com;
    cout << "Please enter the command you wish to remove\n";
    cin >> com;
    if (!find_command(com))
    {
        cout << "COMMAND NOT FOUND\n";
    }
    else
    {
        cout << "Command removed\n ";
        number_of_nodes--;
    }

}

template <class T, class U>
bool LinkedList <T, U>::find_command(T find)
{
    ListNode* tempNode = Headpointer;
    while (tempNode->name != find && tempNode->next != nullptr)
    {
        tempNode = tempNode->next;

    }
    if (tempNode->next == nullptr)
    {
        return false;
    }
    else
    {

        ListNode* temp = Headpointer;
        while (temp->next != tempNode)
        {
            temp = temp->next;
        }
        temp->next = tempNode->next;
        free(tempNode);
       

        return true;
    }

}

template <class T, class U>
bool LinkedList <T, U>::check_existence(T find)
{
    ListNode *tempNode = Headpointer;
    while ( tempNode != nullptr)
    {
        if (tempNode->name == find)
        {
            return true;
        }
        tempNode = tempNode->next;

    }
    if (tempNode == nullptr)
    {
        return false;
    }
  /*  else
    {
        return true;
    }*/

}

template <class T, class U>
void LinkedList <T, U> ::new_round(Profiles *Arr, int& user_count)
{
    cout << "\n\nEnter name";
    string name;
    cin >> name;
    add_user(Arr, user_count, name, 0);
    this->round(Arr);

}

template <class T, class U>
void LinkedList <T, U> ::load_old_user(Profiles *Arr ,int& user_count) 
{
    cout << "\nEnter name of the user ";
    string name;
    cin >> name;
    int user_no = check_user(Arr, user_count, name);
    if (user_no == -1)
    {
        cout << "\nThe name you have entered doesn't exist in our records. ";
        cout << "\nCreating a new profile ";
        add_user(Arr, user_count, name, 0);
        this->round(Arr);


    }
    else 
    {
        this->round(&Arr[user_no]);

    }


}
//game functions

#endif //PA1_HEADER_H

