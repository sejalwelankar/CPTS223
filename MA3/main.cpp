#include <map>
#include "TwitterData.hpp"

using namespace std;

void print_map(map<std :: string, TwitterData> temp)
{
    map<std::string, TwitterData> :: iterator itr1;
    for(itr1 = temp.begin(); itr1 != temp.end();++itr1)
    {
        cout << "Key : " << itr1->first << "\n" ;
        cout <<  "Value : " << itr1->second.print() << endl;
    }
}
int main(int argc, char* argv[]) {
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit",     "Rick",    "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72",  "Smith",    "Kathryn", "kat@gmail.com",      "56",   "health"},
                             {"lexi5",       "Anderson", "Alexis",  "lexi5@gmail.com",    "900",  "education"},
                             {"savage1",     "Savage",   "Ken",     "ksavage@gmail.com",  "17",   "president"},
                             {"smithMan",    "Smith",    "Rick",    "rick@hotmail.com",   "77",   "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i) {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }
    cout << "\n------------------------------------------------------------------\n";
    cout << "SEARCH BASED ON USERNAME\n";
    map<std::string, TwitterData> MapTwitter;
    map<std::string, TwitterData> :: iterator itr1;
    map<std::string, TwitterData> :: iterator searchitr;
    for (int i = 0; i < 5; i++)
    {
        MapTwitter.insert(pair<std::string, TwitterData>(twitter_data[i].getUserName(),twitter_data[i]));
    }
    cout << "Printing key/value pairs of the map : \n";
    print_map(MapTwitter);
    cout << "\n------------------------------------------------------------------\n";
    cout << "Finding the person whose username is savage1 : \n";
    searchitr = MapTwitter.find("savage1");
    if(searchitr != MapTwitter.end())
    {
        cout << "savage1 found in map \n";
        cout<< "Details : \n";
        cout << "Key : " << searchitr->first << "\n" ;
        cout <<  "Value : " << searchitr->second.print() << endl;
    }
    else
    {
        cout << "savage1 not in map";
    }
    cout << "\n------------------------------------------------------------------\n";
    cout << "Removing savage1 from map.\n";
    MapTwitter.erase("savage1");
    cout << "Printing map key and value pairs after removal of savage1\n";
    print_map(MapTwitter);
    cout << "\n------------------------------------------------------------------\n";
    cout << "Search Based on email id\n";
    cout << "Creating a new map with email as the key\n";
    map<std :: string, TwitterData> MapEmail;
    for (int i = 0; i < 5; i++)
    {
        MapEmail.insert(pair<std::string, TwitterData>(twitter_data[i].getEmail(),twitter_data[i]));
    }
    cout << "Printing key/value pairs of the map : \n";
    print_map(MapEmail);
    cout << "\n------------------------------------------------------------------\n";
    cout << "Finding the person whose email is kat@gmail.com : \n";
    searchitr = MapEmail.find("kat@gmail.com");
    if(searchitr != MapEmail.end())
    {
        cout << "kat@gmail.com found in map \n";
        cout<< "Details : \n";
        cout << "Key : " << searchitr->first << "\n" ;
        cout <<  "Value : " << searchitr->second.print() << endl;
    }
    else
    {
        cout << "kat@gmail.com not in map";
    }
    cout << "Removing kat@gmail.com from map.\n";
    MapEmail.erase("kat@gmail.com");
    cout << "\n------------------------------------------------------------------\n";
    cout << "Printing map key and value pairs after removal of kat@gmail.com\n";
    print_map(MapEmail);
    return 0;
}