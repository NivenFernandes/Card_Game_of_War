/** **********************************************************************
* @file
* @brief contains the main functions and the functions that support main
*************************************************************************/


/** **************************************************************************
* @brief Includes catch to use test cases
*****************************************************************************/
#define CATCH_CONFIG_RUNNER
#include "card.h"
#include "mystack.h"
#include "catch.hpp"



/** **********************************************************************
* @mainpage CardWar - Card Game of War
*
* @author Niven Fernandes
*
* @section program_section Program Information
*
* @details
* This program plays the card game of war.
*
* We have two players in the game. each ones cards are either drawn from
* two separate files or generated with two different seed values
* by a random number generator.
*
* Thw two players put one card down. the one that has the highest value gets
* the opponents card and then his own card back. In case of a tie, they
* play three more cards. this continues till one player wins. Incase of a
* tie, one player has n cards(n<3), both players play n cards. the one with the
* highest face value wins. in case its a tie again, both players pick up their
* cards can the game continues
*
* @section compile_section Compiling and Usage
*
* @par Compiling Instructions:
*      none - a straight compile and link with no external libraries.
*
* @par Usage:
  @verbatim
      c:\> thpef.exe -s seed1 seed12

    seed1 - the seed value for the random generator for player 1
    seed2 - the seed value for the random generator for player 2


    or


      c:\> thpef.exe - f file1.txt file2.txt

    file1.txt - the file having the cards of player 1
    file2.txt - the file having the cards of player 2

  option:
           -f: input from a file
           -s: use seed value in the random number generator

           file1.txt: the name of the file to be read the first players cards
           file2.txt: the name of the file to be read the second players cards

           seed1: the seed to generate the cards of the first player
           seed2: the seed to generate the cards of the second player

  @endverbatim
*
* @section todo_bugs_modification_section Todo, Bugs, and Modifications
*
*************************************************************************/


/** **************************************************************************
* @brief A constant which enables catch when true
*****************************************************************************/
const bool RUNCATCH = false;



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  The main function of the program. Checks command line argumnets and runs
 *  the program appropriately depending on what was provided. Cleans up and
 *  exits if something goes wrong (invalid line arguments).
 *
 *  @param[in] argc and integer value, the number of command line arguments
 *  passed in
 *  @param[in] argv a 2D array containing all the command line arguments
 *
 *  @returns an integer value. 0 for success, anything else is failure.
 *
 *  @par Example
 *  @verbatim

    see usage statemnt

    @endverbatim
 ************************************************************************/

int main(int argc, char** argv)
{

    //catch setup
    Catch::Session session;
    int result;
    ifstream fin1;
    ifstream fin2;
    unsigned int seed1, seed2;

    //if RUNCATCH is true, it will test the cases
    if (RUNCATCH)
    {
        //reun
        result = session.run();
        //if result is 0, output error and return result
        if (result != 0)
        {
            cout << "Test Cases did not pass: " << endl;
            return result;
        }
    }

    //check if the arguments are valid
    if (!checkArgs(argc, argv))
    {
        //arguments not valid, output error message, exit
        printUsage();
        //return 0
        return 0;
    }

    // if argv at 1 is -s , conver to unsgned int
    if (strcmp(argv[1], "-s") == 0)
    {
        //call playGeneated and pass the seed to it
        seed1 = stoul(argv[2]);
        seed2 =stoul(argv[3]);
        playGenerated(seed1, seed2);
    }

        //else call playFile and pass the file names to it
    else
    {
        playFile(fin1, string(argv[2]), fin2, string(argv[3]));
    }
    //close both input files
    fin1.close();
    fin2.close();
    //return 0
    return 0;

}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  checks the command line arguments
 *
 *  @param[in] argc the integer value of the number of command line arguments
 *  @param[in] argv the 2 dimensional array having the command line
              arguments
 *
 *  @returns a boolean , true if valid, else false
 *
 *  @par Example
 *
 *  @verbatim

    int main(int argc, char** argv)
    {
        if(!checkArgs(argc, argv)
        {
            return 0;
        }
    }

    @endverbatim
 ************************************************************************/
bool checkArgs(int argc, char** argv)
{
    //if argc is not 4, its an invalid
    if (argc != 4)
    {
        return false;
    }

    //if argv at 1 is equal to -s or -f  return
    if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "-f") == 0)
    {
        return true;
    }

    //return false
    return false;
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  prints out the usage statement
 *
 *  @par Example
 *
 *  @verbatim

    int main(int argc, char** argv)
    {
        if(!checkArgs(argc, argv)
        {
        printUsage();
            return 0;
        }
    }

    @endverbatim
 ************************************************************************/
void printUsage()
{
    //print the usage statement
    cout << "main.exe -s seed1 seed12"<<endl<<endl;
    cout << "seed1 - the seed value for the random generator for player 1" << endl;
    cout << "seed2 - the seed value for the random generator for player 2" << endl<<endl;
    cout << "or" << endl<<endl;
    cout << "main.exe - f file1.txt file2.txt" << endl<<endl;
    cout << "file1.txt - the file having the cards of player 1" << endl;
    cout << "file2.txt - the file having the cards of player 2" << endl;
}

