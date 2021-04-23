
#include <iostream>
#include "DSLL.h"

using namespace std;

class piece_of_art
{
    
    string name;
    int ID;
    double price; 
    
    public:
    piece_of_art() {};
    piece_of_art( string name, int ID, double price)
    {
        this->name = name;
        this->ID = ID;
        this->price = price;
    }
    void set_base( string name, int ID, double price)
    {
        this->name = name;
        this->ID = ID;
        this->price = price;
    }
    void set_name( string name )
    {
        this->name = name;
    }
    void set_ID( int ID )
    {
        this->ID = ID;
    }
    void set_price( double price )
    {
        this->price = price;
    }
    string get_name( )
    {
        return this->name ;
    }
    int get_ID( )
    {
        return this->ID ;
    }
    double get_price( )
    {
        return this->price ;
    }
};

class painting : public piece_of_art
{
    
    int height;
    int width;
    public:
    painting() {};
    painting( int height, int width )
    {
        this->height = height;
        this->width = width;
    }
};

class sculpture : public piece_of_art
{
    
    int weight;
    
    public: 
    sculpture() {};
    sculpture( int weight )
    {
        this->weight = weight;
    }
};

class furniture: public piece_of_art
{
    
    char condition; 
    
    public:
    furniture() {};
    furniture( char condition )
    {
        this->condition = condition;
    }
};


int main()
{
    
    painting myPainting( 0, 0 );
    myPainting.set_base( "myPainting", 0123, 100);
    furniture myFuriture( 'a' );
    myFuriture.set_base( "myFuriture", 0124, 200);
    sculpture mySculpture( 1 );
    mySculpture.set_base("mySculpture", 0125, 300);
    
    DSLinkedList<piece_of_art> myList;
    myList.append(myPainting);
    myList.append(myFuriture);
    myList.append(mySculpture);
    
    double accumulator = 0;
    auto itr = myList.front();
    while( itr != NULL )
    {
        accumulator += itr->get_price();
        itr = myList.next();
        // cout<< "called" ;
        
    }
    cout<< accumulator << endl;
    
    
    
    int action = 0;
    DSLinkedList<painting> paintList;
    while( action != 3)
    {
    cout<< endl << endl << "Welcome to question three of DS1 - 12. " << endl;
    cout<< "Options as follows : " << endl;
    cout<< " 1 - add painting, 2 - get number of paintings, 3 - quit." <<endl;
    cout<< "Please enter your action : ";
    cin >> action;
        if ( action == 1)
        {
            string iput;
            cout << "Please enter the price and the name of the painting. like : 600000 Degas: Dancers" << endl;
            cin.ignore();
            getline(cin, iput);
            //cout<< "past getline"<< endl;
            int parser = 0;
           // cout<< "past parser"<< endl;
            string value1Found = "";
            double value1 = 0;
            string iName = "";
            while( iput[parser] >= 48 && iput[parser] <= 57 || iput[parser] == 46)
            {
                value1Found = value1Found + iput[parser];
               // cout<< value1Found << "while loop " << endl;
                parser++;
            }
            value1 = stod(value1Found);
            auto parser2 = iput.find( ":") + 1;
            cout<< "past parser"<< endl;
            while( iput[parser2] != std::string::npos)
            {
                iName = iName + iput[parser2];
                parser2++;
                cout<< iName << endl;
            }
            painting newPainting;
            newPainting.set_price(value1);
            newPainting.set_name(iName);
            paintList.append( newPainting );
            cout<< "Sucessfully added!" << endl;
        }
    
        if ( action == 2)
        {
            double accumulator = 0;
            auto itr = paintList.front();
            while( itr != NULL )
            {
                accumulator += 1;
                itr = paintList.next();
                // cout<< "called" ;
                
            }
            cout<< "Number of paintings is : " << accumulator << endl;
        }
    
    }
    
    cout<< "Thank you";
    
    
    
    
    return 0;
}








