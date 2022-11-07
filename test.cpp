#include "card.h"
#include "mystack.h"
#include "catch.hpp"


TEST_CASE("mystack push")
{
SECTION("empty")
{
card acard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;

REQUIRE(st.isEmpty());
REQUIRE(st.push(acard));
REQUIRE(st.size()==1);
REQUIRE_FALSE(st.isEmpty());
}

SECTION("no empty")
{
card acard, bcard;
mystack <card> st;
acard.faceValue = 10;
acard.suit = 1;
bcard.faceValue = 8;
bcard.suit = 3;

st.push(acard);

REQUIRE(st.push(bcard));
REQUIRE(st.size() == 2);
}
}

TEST_CASE("mystack clear")
{
SECTION("empty")
{
mystack <card> st;

REQUIRE(st.clear());
REQUIRE(st.isEmpty());
REQUIRE(st.size() == 0);
}

SECTION("one elemnt")
{
card acard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
st.push(acard);

REQUIRE(st.clear());
REQUIRE(st.isEmpty());
REQUIRE(st.size() == 0);
}

SECTION("more than one element")
{
card acard, bcard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
bcard.faceValue = 8;
bcard.suit = 3;

st.push(acard);
st.push(bcard);

REQUIRE(st.clear());
REQUIRE(st.isEmpty());
REQUIRE(st.size() == 0);
}
}


TEST_CASE("isEmpty")
{
SECTION("empty")
{
mystack <card> st;

REQUIRE(st.isEmpty());
REQUIRE(st.size() == 0);
}

SECTION("non empty")
{
card acard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;

st.push(acard);
REQUIRE_FALSE(st.isEmpty());
REQUIRE(st.size() == 1);
}

SECTION("non empty")
{
card acard, bcard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
bcard.faceValue = 8;
bcard.suit = 3;

st.push(acard);
st.push(bcard);
st.clear();
REQUIRE(st.isEmpty());
REQUIRE(st.size() == 0);
}
}

TEST_CASE("size")
{
SECTION("empty")
{
mystack <card> st;

REQUIRE(st.size()==0);
}

SECTION("one element")
{
card acard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
st.push(acard);

REQUIRE(st.size()==1);
}

SECTION(" 2 element")
{
card acard, bcard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
bcard.faceValue = 8;
bcard.suit = 3;

st.push(acard);
st.push(bcard);

REQUIRE(st.size()==2);
}


SECTION("5 elements")
{
card acard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
st.push(acard);

acard.faceValue = 9;
acard.suit = 3;
st.push(acard);

acard.faceValue = 9;
acard.suit = 2;
st.push(acard);

acard.faceValue = 5;
acard.suit = 0;
st.push(acard);

acard.faceValue = 2;
acard.suit = 0;
st.push(acard);

//  st.print();

REQUIRE(st.size() == 5);
}
}

TEST_CASE("pop")
{
SECTION("empty")
{
mystack <card> st;
card acard;
REQUIRE_FALSE(st.pop(acard));
}

SECTION("one element")
{
card acard, bcard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
st.push(acard);

REQUIRE(st.size() == 1);
REQUIRE(st.pop(bcard));
REQUIRE(st.size() == 0);
REQUIRE(acard.faceValue == bcard.faceValue);
REQUIRE(acard.suit == bcard.suit);

}

SECTION(" 2 element - popping 3")
{
card acard, bcard, ccard, dcard, ecard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
bcard.faceValue = 8;
bcard.suit = 3;

st.push(acard);
st.push(bcard);

REQUIRE(st.size() == 2);

REQUIRE(st.pop(ccard));
REQUIRE(st.pop(dcard));
REQUIRE_FALSE(st.pop(ecard));

REQUIRE(acard.faceValue == dcard.faceValue);
REQUIRE(acard.suit == dcard.suit);

REQUIRE(bcard.faceValue == ccard.faceValue);
REQUIRE(bcard.suit == ccard.suit);

REQUIRE(st.size() == 0);
}


SECTION("4 elements")
{
card acard, bcard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
st.push(acard);

acard.faceValue = 9;
acard.suit = 3;
st.push(acard);

acard.faceValue = 9;
acard.suit = 2;
st.push(acard);

acard.faceValue = 5;
acard.suit = 0;
st.push(acard);

acard.faceValue = 2;
acard.suit = 0;
st.push(acard);

//  st.print();

REQUIRE(st.size() == 5);
REQUIRE(st.pop(bcard));
REQUIRE(st.size() == 4);
REQUIRE(acard.faceValue == bcard.faceValue);
REQUIRE(acard.suit == bcard.suit);
}
}

TEST_CASE("top")
{
SECTION("empty")
{
mystack <card> st;
card acard;
REQUIRE_FALSE(st.top(acard));
}

SECTION("one element")
{
card acard, bcard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
st.push(acard);

REQUIRE(st.size() == 1);
REQUIRE(st.top(bcard));
REQUIRE(st.size() == 1);
REQUIRE(acard.faceValue == bcard.faceValue);
REQUIRE(acard.suit == bcard.suit);

}

SECTION(" 2 element - popping 3")
{
card acard, bcard, ccard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
bcard.faceValue = 8;
bcard.suit = 3;

st.push(acard);
st.push(bcard);

REQUIRE(st.size() == 2);

REQUIRE(st.top(ccard));
REQUIRE(bcard.faceValue == ccard.faceValue);
REQUIRE(bcard.suit == ccard.suit);

st.pop(ccard);

REQUIRE(st.top(ccard));
REQUIRE(acard.faceValue == ccard.faceValue);
REQUIRE(acard.suit == ccard.suit);

REQUIRE(st.size() == 1);
}


SECTION("4 elements")
{
card acard, bcard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
st.push(acard);

acard.faceValue = 9;
acard.suit = 3;
st.push(acard);

acard.faceValue = 9;
acard.suit = 2;
st.push(acard);

acard.faceValue = 5;
acard.suit = 0;
st.push(acard);

acard.faceValue = 2;
acard.suit = 0;
st.push(acard);

//  st.print();

REQUIRE(st.size() == 5);
REQUIRE(st.top(bcard));
REQUIRE(st.size() == 5);
REQUIRE(acard.faceValue == bcard.faceValue);
REQUIRE(acard.suit == bcard.suit);
}
}

TEST_CASE("OpenFile")
{
//SECTION("invalid")
//{
//    string str = "data.txt";
//    ifstream fin;
//    REQUIRE_FALSE(isOpen(fin, str));
//}

//SECTION("invalid")
//{
//    string str = "data.txt";
//    ifstream fin;
//    REQUIRE_FALSE(isOpen(fin, str));
//}

}


TEST_CASE("Find")
{
SECTION("empty")
{
mystack <card> st;
card acard;
acard.faceValue = 2;
acard.suit = 2;
REQUIRE_FALSE(st.find(acard));
}

SECTION("one element")
{
card acard, bcard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
st.push(acard);
bcard.suit = 1;
bcard.faceValue = 10;

REQUIRE(st.find(bcard));

}


SECTION("one element")
{
card acard, bcard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
st.push(acard);
bcard.suit = 1;
bcard.faceValue = 9;

REQUIRE_FALSE(st.find(bcard));

}


SECTION(" 2 element - popping 3")
{
card acard, bcard, ccard;
mystack <card> st;

acard.faceValue = 10;
acard.suit = 1;
bcard.faceValue = 8;
bcard.suit = 3;

st.push(acard);
st.push(bcard);

ccard.faceValue = 10;
ccard.suit = 1;

REQUIRE(st.find(ccard));

ccard.faceValue = 8;
ccard.suit = 3;

REQUIRE(st.find(ccard));

ccard.faceValue = 8;
ccard.suit = 0;

REQUIRE_FALSE(st.find(ccard));
}

}


TEST_CASE("swap")
{
SECTION("one element")
{
card acard, bcard;
mystack <card> stk1;
mystack <card> stk2;

acard.faceValue = 10;
acard.suit = 1;
bcard.suit = 3;
bcard.faceValue = 9;

stk1.push(acard);
stk2.push(bcard);

stk1.swap(stk2);

REQUIRE(stk2.find(acard));
REQUIRE_FALSE(stk2.find(bcard));
REQUIRE(stk1.find(bcard));
REQUIRE_FALSE(stk1.find(acard));


}


SECTION("more than one element")
{
card acard, bcard;
mystack <card> stk1;
mystack <card> stk2;

acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 6;
bcard.suit = 3;

stk1.push(acard);
stk2.push(bcard);

acard.faceValue = 5;
acard.suit = 2;
bcard.faceValue = 4;
bcard.suit = 1;

stk1.push(acard);
stk2.push(bcard);;

stk1.swap(stk2);


REQUIRE(stk2.find(acard));
REQUIRE(stk1.find(bcard));


acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 6;
bcard.suit = 3;

REQUIRE(stk2.find(acard));
REQUIRE(stk1.find(bcard));
}
}

TEST_CASE("copy")
{
SECTION("empty")
{
mystack <card> stk2;

mystack<card> stk1 (stk2);

REQUIRE(stk1.size()==0);
}

SECTION("non empty")
{
card acard, bcard;
mystack <card> stk2;
acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 6;
bcard.suit = 3;
stk2.push(acard);
stk2.push(bcard);

mystack<card> stk1(stk2);

REQUIRE(stk1.size() == 2);
}
}

TEST_CASE("== operator")
{
SECTION("empty")
{
mystack <card> stk2;

mystack<card> stk1;

REQUIRE(stk1==stk2);
}

SECTION("non empty")
{
card acard, bcard;
mystack <card> stk2, stk1;
acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 6;
bcard.suit = 3;
stk2.push(acard);
stk2.push(bcard);

REQUIRE_FALSE(stk1==stk2);
}

SECTION("non empty equal")
{
card acard, bcard;
mystack <card> stk2, stk1;
acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 6;
bcard.suit = 3;
stk2.push(acard);
stk1.push(bcard);

acard.faceValue = 5;
acard.suit = 1;
bcard.faceValue = 5;
bcard.suit = 3;
stk2.push(acard);
stk1.push(bcard);

REQUIRE(stk1 == stk2);
}
}


TEST_CASE("!= operator")
{
SECTION("empty")
{
mystack <card> stk2;

mystack<card> stk1;

REQUIRE_FALSE(stk1 != stk2);
}

SECTION("non empty")
{
card acard, bcard;
mystack <card> stk2, stk1;
acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 6;
bcard.suit = 3;
stk2.push(acard);
stk2.push(bcard);

REQUIRE(stk1 != stk2);
}

SECTION("non empty")
{
card acard, bcard;
mystack <card> stk2;
acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 6;
bcard.suit = 3;
stk2.push(acard);
stk2.push(bcard);

mystack<card> stk1(stk2);

REQUIRE_FALSE(stk1 != stk2);
}
}


TEST_CASE("< operator")
{
SECTION("empty")
{
mystack <card> stk2;

mystack<card> stk1;

REQUIRE_FALSE(stk1 < stk2);
}

SECTION("non empty")
{
card acard, bcard;
mystack <card> stk2, stk1;
acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 6;
bcard.suit = 3;
stk2.push(acard);
stk2.push(bcard);

REQUIRE(stk1 < stk2);
}

SECTION("non empty")
{
card acard, bcard;
mystack <card> stk2, stk1;
acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 6;
bcard.suit = 3;
stk1.push(acard);
stk1.push(bcard);

REQUIRE_FALSE(stk1 < stk2);
}

SECTION("non empty equal")
{
card acard, bcard;
mystack <card> stk2, stk1;
acard.faceValue = 7;
acard.suit = 1;
bcard.faceValue = 7;
bcard.suit = 1;

stk1.push(acard);
stk2.push(bcard);

acard.faceValue = 6;
acard.suit = 1;
bcard.faceValue = 8;
bcard.suit = 3;

stk1.push(acard);
stk2.push(bcard);

REQUIRE(stk1< stk2);
}
}



TEST_CASE("playRound screen")
{
card aCard, bcard;
int i;
ostringstream sout1, sout2;
queue<card> p1, p2;


SECTION("Single Card win")
{
int p1cards[2] = { 4, 8 };
int p2cards[2] = { 2, 7 };
for (i = 0; i < 2; i++)
{
aCard.faceValue = p1cards[i];
aCard.suit = 0; // gave it a suit of hearts
p1.push(aCard);
}
for (i = 0; i < 2; i++)
{
aCard.faceValue = p2cards[i];
aCard.suit = 0; // gave it a suit of hearts
p2.push(aCard);
}

playRound(p1, p2);
sout1 << p1; // I overloaded the << operator to make this work
sout2 << p2;

REQUIRE(sout1.str() == " 9H 3H 5H");
REQUIRE(sout2.str() == " 8H");
}


SECTION(" last ")
{
aCard.faceValue = 6;
aCard.suit = 3;
bcard.faceValue = 4;
bcard.suit = 1;

p1.push(bcard);
p1.push(aCard);
p2.push(aCard);
playRound(p1, p2);
sout1 << p1; // I overloaded the << operator to make this work
sout2 << p2;

REQUIRE(sout1.str() == " 7S");
REQUIRE(sout2.str() == " 5D 7S");
}

SECTION(" last  draw")
{
aCard.faceValue = 6;
aCard.suit = 3;
bcard.faceValue = 4;
bcard.suit = 1;

p1.push(aCard);
p1.push(bcard);
p2.push(aCard);
playRound(p1, p2);
sout1 << p1; // I overloaded the << operator to make this work
sout2 << p2;

REQUIRE(sout1.str() == " 5D 7S");
REQUIRE(sout2.str() == " 7S");
}
}

TEST_CASE("playgamefile")
{

ifstream fin1, fin2;
ofstream fout;
queue<card> p1, p2;
isOpen(fin1, "d.cards");
isOpen(fin2, "d2.cards");
readFile(fin1, p1);
readFile(fin2, p2);

isOutOpen(fout, "card.rst");

playTestFile(p1, p2, fout);
fin1.close();
fin2.close();
fout.close();
}

TEST_CASE("playround file")
{

ifstream fin1, fin2;
ofstream fout;
queue<card> p1, p2;
isOpen(fin1, "d.cards");
isOpen(fin2, "d2.cards");
readFile(fin1, p1);
readFile(fin2, p2);

isOutOpen(fout, "card2.rst");

playRound(p1,p2);
fout << "Player 1 hand :";
fout << p1;
fout << endl;
fout << "Player 2 hand :";
fout << p2;

fin1.close();
fin2.close();
fout.close();
}
