/** **********************************************************************
* @file
* @brief has the structure and the header file
*************************************************************************/

#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include<random>
#include<queue>

using namespace std;


/**
 * @brief Holds the face value and the suit of  the card
 */
struct card
{
    int faceValue; /**< Holds the face value */
    int suit;  /**<holds the suit of the card */
};


bool isOpen(ifstream& fin, string str);
bool readFile(ifstream& fin, queue<card>& player);
void generateDeck(queue<card>& player, unsigned int seed);
void playRound(queue<card>& player1, queue<card>& player2);
void play(queue<card>& player1, queue<card>& player2);
void printUsage();
bool checkArgs(int argc, char** argv);
void playGenerated(unsigned int seed1, unsigned int seed2);
void printResult(queue<card>& player);
void playFile(ifstream &fin1, string file1, ifstream& fin2, string file2);
ostream& operator<<(ostream& out, queue<card>& s1);
bool isOutOpen(ofstream& fout, string str);
void playTestFile(queue<card>& player1, queue<card>& player2, ofstream& fout);
