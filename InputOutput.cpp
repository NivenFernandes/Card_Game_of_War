/** **********************************************************************
* @file
* @brief contains the input / output functions
*************************************************************************/

#include "card.h"
#include "mystack.h"


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  open input file. check if it was sucessful in opening it
 *
 *  @param[out] fin the input file stream
 *  @param[in] str the name of the input file to be opened
 *
 *  @returns a bool, true on success, false otherwise
 *
 *  @par Example
 *  @verbatim

    ifstream fin;
    string str="deck1.cards"
    bool success;
    success = isOpene(fin, str);
    //sucess should be true

    @endverbatim
 ************************************************************************/
bool isOpen(ifstream& fin, string str)
{
    //opening the file
    fin.open(str);
    //check for success
    if (!fin.is_open())
    {
        //output an error message
        cout << "Unable to open input file: " << str << endl;
        //return false if not opened
        return false;
    }

    //opened successfully
    return true;
}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  read the cards from the file to the queue (the players hand)
 *
 *
 *  @param[in] fin the input fil,e stream
 *  @param[out] player the queue to read to
 *
 *  @returns a bool, true on success, false otherwise
 *
 *  @par Example
 *  @verbatim

    ifstream fin;
    bool sucess;
    success = isOpene(fin, str);
    bool valid;
    queue<card> player;
    if(success)
    {
       valid=readFile(fin, player);
       //valid will be true if its a good read
    }


    @endverbatim
 ************************************************************************/
bool readFile(ifstream& fin, queue<card>& player)
{
    //set count to zero
    int count = 0;
    //declare other vaiables
    int cardValue;
    card acard;
    //keep reading in the queue till we have an input or we get 52 cards
    while (count < 52 && fin >> cardValue)
    {
        //faceValue is card value % 13
        acard.faceValue = cardValue % 13;
        //suit is card value divided by 13
        acard.suit = cardValue / 13;
        //push the card to the stack
        player.push(acard);
        //increment count
        count = count + 1;
    }

    //return true on success
    return true;
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  open output file. check if it was sucessful in opening it
 *
 *  @param[out] fout the output file stream
 *  @param[in] str the name of the input file to be opened
 *
 *  @returns a bool, true on success, false otherwise
 *
 *  @par Example
 *  @verbatim

    ofstream fout;
    string str="deck1.cards"
    bool success;
    success = isOpene(fin, str);
    //sucess should be true

    @endverbatim
 ************************************************************************/
bool isOutOpen(ofstream & fout, string str)
{
    //opening the file
    fout.open(str);
    //check for success
    if (!fout.is_open())
    {
        //output an error message
        cout << "Unable to open output file: " << str << endl;
        //return false if not opened
        return false;
    }

    //opened successfully
    return true;
}