#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
    //declare the map that uses a person's name as a key, and looks
    //up a map that stores the person's weight and height
    std::map< std::string, std::map<std::string,int> > database;

    //let's first put the data in three vectors
    std::vector<std::string> names = { "Person", "Handbag"};
    std::vector<int> min_heights = { 100, 10};
    std::vector<int> min_widthes = { 120, 20};
    std::vector<int> max_heights = { 200, 20};
    std::vector<int> max_widthes = { 240, 40};

    //now put all of the data into the database
    for (int i=0; i<names.size(); ++i)
    {
        std::map<std::string,int> data;

        data["min_height"] = min_heights[i];
        data["min_width"] = min_widthes[i];
        data["max_height"] = max_heights[i];
        data["max_width"] = max_widthes[i];
        database[names[i]] = data;
    }

    //now print out the entire database
    for ( auto item : database )
    {
        //print out the name
        std::cout << item.first << " : ";

        //now print out all of the data about the person
        for ( auto data : item.second )
        {
            std::cout << data.first << "=" << data.second << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
