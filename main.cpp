#include <iostream>
#include <fstream>

using namespace std;
class collection
{
public:
    int id;
    int length_of_film;
    int year;
    int star_rating;

    char name[1000];
    char genre[1000];

};

int i;
bool header_done;

collection DVD[100];
ofstream outputfile;
char filename[1000];

void data_input()
{
    DVD[i].id = i;
    cout << "what is the titles name?";
    cin >> DVD[i].name;
    cout << "what is the titles genre?";
    cin >> DVD[i].genre;

    cout << "what is the films runtime (in minutes)" << endl;
    cin >> DVD[i].length_of_film;
    cout << "films release year";
    cin >> DVD[i].year;
    cout << "what woul you rate this title (out of 5)?";
    cin >> DVD[i].star_rating;

    if(DVD[i].star_rating > 5)
    {
        DVD[i].star_rating = 5;

    }
    else
    {
        if(DVD[i].star_rating < 0)
        {
            DVD[i].star_rating = 0;
        }
    }
}

void data_out()
{
    cout << "^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "|^|dvd name: " << DVD[i].name << endl;
    cout << "|^|dvd id: " << DVD[i].id << endl;
    cout << "|^|dvd genre: " << DVD[i].genre << endl;
    cout << "|^|dvd runtime: " << DVD[i].length_of_film << endl;
    cout << "|^|dvd release year: " << DVD[i].year << endl;
    cout << "|^|dvd star rating: " << DVD[i].star_rating << "/5"<< endl;
}

void data_save_to_file()
{
    outputfile.open(filename);
    if(header_done == false)
    {
        header_done = true;
        outputfile << "DVD id" << " , " << "DVD name" << " , " << "DVD genre" << " , " << "DVD runtime" << " , " << "DVD release year" << " , " << "DVD rating" << "\n";

    }

    outputfile << DVD[i].id << " , " << DVD[i].name << " , " << DVD[i].genre << " , " << DVD[i].length_of_film << " , " << DVD[i].year << " , " << DVD[i].star_rating << "\n";

    outputfile.close();

}

int main()
{
    cout << "what would you like the filename to be? (be sure to include the file extension) ";
    cin >> filename;

    while(i < 100)
    {
        i++;
        data_input();
        data_out();
        data_save_to_file();
    }
    cout << "what DVD would you like to edit?" << endl;
    cin >> i;
    data_input();

    return 0;
}
