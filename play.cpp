/** **********************************************************************
* @file
* @brief contains function that play the game
*************************************************************************/


#include "card.h"
#include "mystack.h"



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this function generates a valid hand according to the seed value
    and stores in a queue. it checks for double allocation
 *
 *  @param[out] player a stack that stores the hand
 *  @param[in] seed - the seed value for the random number generator
 *
 *
 *  @par Example
 *
 *  @verbatim

    unsigned int seed1=123;
    queue<card> player;
    generateDeck(player,  seed);
    //player will have a valid hand

    @endverbatim
 ************************************************************************/
void generateDeck(queue<card>& player, unsigned int seed)
{
    int i=0;
    //setup random engine
    default_random_engine generator(seed);
    //set range to 0 to 51
    uniform_int_distribution<int> distribution(0, 51);
    //create a lookup array to check for repetation
    //initialize it to 0
    int lookup[52] = {0};
    card acard;
    int cardValue;

    //while i is less than 52, keep drawing cards
    while(i<52)
    {
        //get a card value
        cardValue = distribution(generator);
        //if its not already stored
        if (lookup[cardValue] == 0)
        {
            //face value is cardValue % 13
            acard.faceValue = cardValue % 13;
            //suit is cardValue / 13
            acard.suit = cardValue / 13;
            //push the card in the queue
            player.push(acard);
            //update lookup array
            lookup[cardValue] = 1;
            //increment i
            i++;
        }
    }
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this function plays a single round and stores the result in the
 *  respective queue. it plays till one person wins the round or till
 *  one person has no cards and the last card is a draw, in this case both
 *  players pick up their cards
 *
 *  @param[in,out] player1 the queue of the hand of the first person
 *  @param[in, out] player2 - the queue of the hand of the second person
 *
 *  @par Example
 *
 *  @verbatim
    queue<card> p1, p2;
    //put some data in both the queues
    playRound(p1, p2);
    //it will play one round

    @endverbatim
 ************************************************************************/
void playRound(queue<card>& player1, queue<card>& player2)
{
    mystack<card> ply1, ply2;
    int count=0;
    card pl1, pl2;
    //solution is true
    bool solution = false;
    int i ;
    //remove one card from each queue and insert it in the respective stack
    ply1.push(player1.front());
    ply2.push(player2.front());
    player1.pop();
    player2.pop();
    //while we dont find a solution
    while (!solution)
    {
        //if the size of any players card is 0 and the top card is a tie
        if ((player1.size() == 0 || player2.size() == 0) && ply1 == ply2)
        {
            //both the players take their cards and place it in their queue
            while (ply1.size() != 0)
            {
                ply1.pop(pl1);
                player1.push(pl1);
                ply2.pop(pl2);
                player2.push(pl2);
            }
            //solution found
            solution = true;
        }
        //if solution is not found
        if (!solution)
        {
            //if the stack of player 1 has the same top card as player 2
            if (ply1 == ply2)
            {
                i = 0;
                //while i is less than 3 and either of their stack size is
                //not 0, draw 3 cards at max
                while (player1.size() != 0 && player2.size() != 0 && i < 3)
                {
                    //get the top cards in the queue and store it in pl1 and pl2
                    pl1 = player1.front();
                    pl2 = player2.front();
                    //remove the card from the queue
                    player1.pop();
                    player2.pop();
                    //push it to the stack increment i
                    ply1.push(pl1);
                    ply2.push(pl2);
                    i++;
                }
            }
                //if the top card in player1 stack > than that of player 2
            else if (ply1 < ply2)
            {
                //player 2 won the round
                while (ply1.size() != 0)
                {
                    //pop player 1's hand and store it in player 2's queue
                    ply1.pop(pl1);
                    player2.push(pl1);
                }
                while (ply2.size() != 0)
                {
                    //pop player 2's hand and store it in player 2's queue
                    ply2.pop(pl2);
                    player2.push(pl2);
                }
                //solution
                solution = true;
            }
            else
            {
                //player 1 won the round
                while (ply2.size() != 0)
                {
                    //pop players 2's hand in player 1's stack
                    ply2.pop(pl2);
                    player1.push(pl2);
                }
                while (ply1.size() != 0)
                {
                    //pop player1's stack in player 1's queue
                    ply1.pop(pl1);
                    player1.push(pl1);
                }
                //solution
                solution = true;
            }
        }
    }
}

/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this function calls the required functions to play the game and output
 *  the result to the screeen
 *
 *  @param[in, out] player1 the queue of the hand of the first person
 *  @param[in, out] player2 - the queue of the hand of the second person
 *
 *  @par Example
 *
 *  @verbatim
    queue<card> p1, p2;
    //put some data in both the queues
    play(p1, p2);
    //it will play othe entire game , output the wnner

    @endverbatim
 ************************************************************************/
void play(queue<card>& player1, queue<card>& player2)
{
    int count = 0;
    //call playRound till the size of one of the hand is not 0
    while (player1.size() != 0 && player2.size() != 0 ) // && count<1)
    {
        playRound(player1, player2);
        //increment count
        count++;
    }

    //if player 1's hand size is 0, player 2 wins
    if (player1.size() == 0)
    {
        cout << "Player 2 wins after " << count << " rounds." << endl;
        cout << "Player 1 hand: ";
        //print the hand
        printResult(player1);
        cout<<endl;
        cout << "Player 2 hand: ";
        //print the hand
        printResult(player2);
        cout<< endl;
    }

    else
    {
        // player 2 wins, output the message
        cout << "Player 1 wins after " << count << " rounds." << endl;
        cout << "Player 1 hand: ";
        //print the hand
        printResult(player1);
        cout << endl;
        cout << "Player 2 hand: ";
        //print the hand
        printResult(player2);
        cout << endl;
    }
}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this function calls generateDeck and pass both the seed values
 *  and calls play
 *
 *  @param[in] seed1 -  the unsigned int seed value for the first player
 *  @param[in] seed2 -  the unsigned int seed value for the second player
 *
 *  @par Example
 *
 *  @verbatim

    unsigned int seed1=123, seed2=454;
    playGenerated(seed1, seed2);
    //it will play the game

    @endverbatim
 ************************************************************************/
void playGenerated(unsigned int seed1, unsigned int seed2)
{
    //create two stacks
    queue<card> player1, player2;
    //generate player1's hand
    generateDeck(player1, seed1);
    //generate players's hand
    generateDeck(player2, seed2);
    //play
    play(player1, player2);
}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this function open file, if opened, calls read file, if valid, plays the
 * game
 *
 *  @param[in] fin1 -  the  input file stream of player 1
 *  @param[in] file1-  the name of the file of player 1
  *  @param[in] fin2 -  the  input file stream of player 2
 *  @param[in] file2-  the name of the file of player 2
 *
 *  @par Example
 *
 *  @verbatim

    string str1, str2;
    ifstream fin1, fin2;
    playFile(fin1, str1, fin2, str2);
    //it will play the game with the data from the two files

    @endverbatim
 ************************************************************************/
void playFile(ifstream &fin1, string file1, ifstream &fin2, string file2)
{
    queue<card> player1, player2;
    bool is1open;
    bool is2open;
    //open both the files
    is1open=isOpen(fin1, file1);
    is2open=isOpen(fin2, file2);

    //if atleast one of them is not opened, exit 0;
    if (!is1open || !is2open)
    {
        exit(0);
    }

    //read files
    readFile(fin1, player1);
    readFile(fin2, player2);
    //play game
    play(player1, player2);
}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this function prints the hand
 *
 *  @param[in] player - the hand to be outputted
 *
 *  @par Example
 *
 *  @verbatim

    queue<card> player;
    printResult(player);
    //it will print the output

    @endverbatim
 ************************************************************************/
void printResult(queue<card>& player)
{
    unsigned int i=0;
    card acard;
    unsigned int size = player.size();
    //hav an array of suits
    string suit[4] = { "H", "D", "C","S" };
    //array of face
    string face[14] = { "0","A","2","3","4","5","6","7","8","9","10"
            , "J", "Q","K" };
    //while i is less than size
    while (i <size)
    {
        //save front og the player stack in the temparary structure card
        acard=player.front();
        //pop the card
        player.pop();
        //output the (faceValue+1) and the suit
        cout << face[acard.faceValue+1] << suit[acard.suit];
        //output a space
        if (i != (size - 1))
        {
            cout << " ";

        }
        //push the card to the queue
        player.push(acard);
        i++;
    }
}




/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is an overloaded operator, it outputs the queue to the
 *  output stream
 *
 *  @param[out] out the output stream
 *  @param[in] s1 the hand of the player
 *
 *  @returns an output stream
 *  @par Example
 *  @verbatim

     queue<card>& p1;
     outputstring stream sout;
     sout<<p1;
     //it will output the queue to the output stream

    @endverbatim
 ************************************************************************/
ostream &operator<<(ostream& out, queue<card>& s1)
{
    unsigned int i = 0;
    card acard;
    //array of suits
    string suit[4] = { "H", "D", "C","S" };
    //array of face
    string face[14] = { "0","A","2","3","4","5","6","7","8","9","10"
            , "J", "Q","K" };
    //while i is less than size output
    while (i < s1.size())
    {
        out << " ";
        //get front of the queue
        acard=s1.front();
        //output face[acard.faceValue + 1] and suit[acard.suit];
        out << face[acard.faceValue + 1] << suit[acard.suit];
        //pop the card
        s1.pop();
        //push it behinf
        s1.push(acard);

        //incre,ent i
        i++;
    }
    // return the output
    return out;
}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this function calls the required functions to play the game and output
 *  the result to the screeen
 *
 *  @param[in, out] player1 the queue of the hand of the first person
 *  @param[in, out] player2 - the queue of the hand of the second person
 *  @param[in, out] fout output file stream
 *  @par Example
 *
 *  @verbatim
    queue<card> p1, p2;
    //put some data in both the queues
    play(p1, p2);
    //it will play othe entire game , output the wnner

    @endverbatim
 ************************************************************************/
void playTestFile(queue<card>& player1, queue<card>& player2, ofstream & fout)
{
    int count = 0;
    //call playRound till the size of one of the hand is not 0
    while (player1.size() != 0 && player2.size() != 0) // && count<1)
    {
        playRound(player1, player2);
        //increment count
        count++;
    }

    //if player 1's hand size is 0, player 2 wins
    if (player1.size() == 0)
    {
        fout << "Player 2 wins after " << count << " rounds." << endl;
        fout << "Player 1 hand: ";
        //print the hand
        fout << player1;
        fout<< endl;
        fout<< "Player 2 hand: ";
        //print the hand
        fout << player2;
        fout << endl;
    }

    else
    {
        // player 2 wins, output the message
        fout << "Player 1 wins after " << count << " rounds." << endl;
        fout << "Player 1 hand: ";
        //print the hand
        fout << player1;
        fout << endl;
        fout << "Player 2 hand: ";
        //print the hand
        fout << player2;
        fout << endl;
    }
}