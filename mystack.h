/** **********************************************************************
* @file
* @brief contains the stack, member functions and the friend funtions
*************************************************************************/


#include "card.h"
using namespace std;



/**
 * @brief the template stack class
 */
template <class TY>
class mystack
{

public:
    mystack();
    mystack(mystack& stk);

    ~mystack();

    bool push(TY item);

    bool pop(TY & item);

    bool top(TY & item);

    bool isEmpty();

    int size();

    void print();

    bool clear();

    bool find(TY item);

    void swap(mystack<TY>& stk);

    bool operator==(const mystack<TY>& rhs) const;

    bool operator!=(const mystack<TY>& rhs) const;

    bool operator<(const mystack<TY>& rhs) const;

    friend ostream& operator<<(ostream& out, mystack<TY>& s1);


private:


    /**
     * @brief contains the node having the card details
     */
    struct node
    {
        TY theItem;  /**< the template item */
        node* next;  /**< The location to the next node */
    };
    node* headptr;    /**< The headptr of the calss object */
};



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *          Default constructor, this will create an empty stack by
 *          initializing headptr
 *
 *  @par Example
 *
 *  @verbatim

     mystack st;
     //it will create an empty stack and initialize the headptr

    @endverbatim
 ************************************************************************/

template <class TY>
mystack<TY>::mystack()
{
    headptr = nullptr;

}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *        Destructor, this called when an object goes out of
 *        scopeand will free all nodes int the stack
 *
 *  @par Example
 *
 *  @verbatim

     mystack st;
     //it willfree up all the nodes when it goes out of scope

    @endverbatim
 ************************************************************************/
template <class TY>
mystack<TY>::~mystack()
{
    clear();
}




/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this is a member function of the template stack class. it pushes an
 *  element to the stack at the front. outouts an error message if unable
 *  to push
 *
 *  @param[in] item the input template item
 *
 *  @returns a bool, true on success, false otherwise
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk;
    card acard;
    acard.faceValue=3;
    acard.suit=2;
    stk.push(aCard);
    //the first element of the stack will be aCard

    @endverbatim
 ************************************************************************/
template<class TY>
bool mystack<TY>::push(TY item)
{
    //create a node
    node* temp;
    //allocate memory
    temp = new(nothrow) node;
    //check for success
    if (temp == nullptr)
    {
        //unable to allocate memory
        cout << "unable to allocate memory";
        //exit
        exit(0);
    }
    //add the elemnt to the stack and change the headptr
    temp->theItem = item;
    temp->next = headptr;
    headptr = temp;
    //return true
    return true;
}




/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this is a member function of the template stack class.
 *   it clears the entire stack
 *
 *  @returns a bool, true on success, false otherwise
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk;
    card acard;
    acard.faceValue=3;
    acard.suit=2;
    stk.push(aCard);

    stk.clear();
    //stk will be empty

    @endverbatim
 ************************************************************************/
template<class TY>
bool mystack <TY>::clear()
{
    node* temp = headptr;
    //while headptr is not equal to nullptr
    while (headptr != nullptr)
    {
        //set temp to headptr
        temp = headptr;
        //update headptr
        headptr = headptr->next;
        //delete temp
        delete temp;
    }

    return true;
}




/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  this is a member function of the template stack class.
 * it checks if the stack is empty or not
 *
 *  @returns a bool, true if empty, false otherwise
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk;
    card acard;
    bool empty;
    acard.faceValue=3;
    acard.suit=2;
    stk.push(aCard);

    stk.clear();

    empty= stk.isEmpty();
    //empty will be true

    @endverbatim
 ************************************************************************/
template<class TY>
bool mystack<TY>::isEmpty()
{
    //if headptr==nullptr return true
    if (headptr == nullptr)
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
 *  This is a member function of the template stack class. it calculates
 *  the size of the stack
 *
 *  @returns an integer value the size of the stack
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk;
    card acard;
    bool empty;
    acard.faceValue=3;
    acard.suit=2;
    stk.push(aCard);

    stk.size();
    //size should be 1

    @endverbatim
 ************************************************************************/
template<class TY>
int mystack<TY>::size()
{
    int size = 0;
    //set temp t headptr
    node* temp = headptr;
    //while heamp is not equal to nullptr, increment size
    while (temp != nullptr)
    {
        size += 1;
        //increment temp
        temp = temp->next;
    }

    //return size
    return size;
}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is a member function of the template stack class. It prints the
 * stack to the screen
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk;

    stk.print();

    @endverbatim
 ************************************************************************/
template<class TY>
void mystack <TY>::print()
{
    //assign temp to headptr
    node* temp = headptr;
    //while temp is not equal to nullptr
    while (temp != nullptr)
    {
        //output the stack's facevalue+1
        //and output the suite
        cout << temp->theItem.suit;
        cout << " ";
        cout << (temp->theItem.faceValue) +1<< endl;
        //increment temp
        temp = temp->next;
    }
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is a member function of the template stack class. it pops the first
 * element from the stack and stores it to the variable passed to it.
 *  Checks for any error
 *
 *  @param[out] item the element to copy the template item being popped
 *
 * @returns a boolean result, true if an item was removed sucessfully
 *                false othewise
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk;
    card acard;
    acard.faceValue=2;
    acard.suit=1;
    stk.push(acard);

    stk.pop(acard);
    //it will remove the element from stk and store it in acard

    @endverbatim
 ************************************************************************/
template<class TY>
bool mystack<TY>::pop(TY& item)
{
    //set temp to headptr
    node* temp=headptr;

    //if headptr==nullptr, return false
    if (headptr == nullptr)
    {
        return false;
    }
    //otherwise, item is headptr of item
    item = headptr->theItem;
    //increment headptr
    headptr = headptr->next;
    //delete temp and return true
    delete temp;
    return true;
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is a member function of the template stack class. Stores the first
 * element fromm the stak to the variable passed to it.
 *
 *  @param[out] item the template element to copy the item first element
 *  of the stack to
 *
 * @returns a boolean result, true if an item was coppied successfully
 *                false othewise
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk;
    card acard;
    acard.faceValue=2;
    acard.suit=1;
    stk.push(acard);

    stk.top(acard);
    //the first elemnt of stk will be stored in acard

    @endverbatim
 ************************************************************************/
template<class TY>
bool mystack<TY>:: top(TY& item)
{
    //if headptr == nullptr, return false
    if (headptr == nullptr)
    {
        return false;
    }

    //store the item from the headptr to the variable passed to the
    //function call
    item = headptr->theItem;
    //return true
    return true;
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is a member function of the template stack class. It searches the
 *  element passed to it in the stack. This function only works for the card
 *  structure
 *
 *  @param[in] item the template element to be checked
 *
 * @returns a boolean result, true if an item was found
 *                false othewise
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk;
    card acard;
    bool found;
    acard.faceValue=2;
    acard.suit=1;
    stk.push(acard);

    found=stk.find(acard);
    //found should be true

    @endverbatim
 ************************************************************************/
template<class TY>
bool mystack<TY>::find(TY item)
{
    //set temp to headptr
    node* temp = headptr;
    //while temp is not equal to nullptr
    while (temp != nullptr)
    {
        //if temp of faceValue and SUit matches that of item, return true
        if (temp->theItem.faceValue == item.faceValue
            && temp->theItem.suit== item.suit)
        {
            return true;
        }
        //increment temp
        temp = temp->next;
    }
    //return false
    return false;
}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is a member function of the template stack class. It swaps the
 * headptr of the two stacks
 *
 *  @param[in, out] stk the second stack
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk1, stk2;
    card acard;
    acard.faceValue=2;
    acard.suit=1;
    stk1.push(acard);
    stk1.(stk2);
    // now stk1 will be empty and stk2 will have the acard element

    @endverbatim
 ************************************************************************/
template<class TY>
void mystack<TY>::swap(mystack<TY>& stk)
{
    node* temp;
    temp = stk.headptr;
    stk.headptr = headptr;
    headptr = temp;
}

/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is a member function of the template stack class. Its is copy
 *  constructor. it creats a copy
 *
 *  @param[in, out] stk the second stack
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk1, stk2;
    card acard;
    acard.faceValue=2;
    acard.suit=1;
    stk1.push(acard);
    stk2 (stk1)
    // now stk2 will be the copy of stk1

    @endverbatim
 ************************************************************************/
template<class TY>
mystack<TY>::mystack(mystack& stk)
{
    node* temp1;
    node* temp2;


    //headptr is equal to nullptr, return
    if (stk.headptr == nullptr)
    {
        //clear the stack
        clear();
        return;
    }

    //create a node and insert the data
    headptr = new (nothrow) node;
    headptr->theItem = stk.headptr->theItem;
    //headptr of next is nullptr
    headptr->next = nullptr;

    //set temp2 to stk.headptr of next and temp1 to headptr
    temp2 = stk.headptr->next;
    temp1 = headptr;

    //while temp != nullptr, keep copying elements from temp 2 to temp 1
    while (temp2 != nullptr)
    {
        temp1->next = new (nothrow) node;
        //increment temp1 and temp2
        temp1 = temp1->next;
        //copy the item
        temp1->theItem = temp2->theItem;
        temp1->next = nullptr;
        temp2 = temp2->next;
    }
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is an overloaded of the template stack class mystack. It checks
 * if the top elements of the stack are the same.
 *
 *  @param[in, out] rhs the second stack
 *
 * @returns a bool value, true if the top elements are the same, false
 *           otherwise
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk1, stk2;
    bool f1, f2;
    card acard;
    acard.faceValue=2;
    acard.suit=1;
    stk1.push(acard);
    f1= (stk1==stk2);
    //f1 will be false
    stk2 (stk1) // copy it
        f1= (stk1==stk2);
        //f1 will be true

    @endverbatim
 ************************************************************************/
template<class TY>
bool mystack<TY>::operator==(const mystack<TY>& rhs) const
{
    //have two temporary variables to store the headptr of each list
    node* tempRhs = rhs.headptr;
    node* temp = headptr;


    //if the headptrs are equal
    if (headptr == rhs.headptr)
    {
        //return true
        return true;
    }

    //if none of the headptr is nullptr and the other is not
    if (temp == nullptr && tempRhs != nullptr)
    {
        //return false
        return false;
    }

        //check if the other one is nullptr
    else if (temp != nullptr && tempRhs == nullptr)
    {
        //return false
        return false;
    }

    //else if the first element is same, return true
    if (temp->theItem.faceValue == tempRhs->theItem.faceValue)
    {
        return true;
    }

    return false;



    ////////////////== operator for the entire stack////////////////

    //while (tmp != nullptr && tmpRhs != nullptr)
    //{
    //    if (tmp->theItem.faceValue != tmpRhs->theItem.faceValue)
    //    {
    //        return false;
    //    }

    //    tmp = tmp->next;
    //    tmpRhs = tmpRhs->next;
    //}

    //if (tmp == nullptr && tmpRhs != nullptr)
    //{
    //    return false;
    //}

    //else if (tmpRhs == nullptr && tmp != nullptr)
    //{
    //    return false;
    //}

    //return true;

    ////////////////////////////////////////////////////////////////
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is an overloaded of the template stack class mystack. It checks
 * if the top elements of the stack are differenr
 *
 *  @param[in, out] rhs the second stack
 *
 * @returns a bool value, true if the top elements are different, false
 *           otherwise
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk1, stk2;
    bool f1, f2;
    card acard;
    acard.faceValue=2;
    acard.suit=1;
    stk1.push(acard);
    f1= (stk1!=stk2);
    //f1 will be true
    stk2 (stk1) // copy it
        f1= (stk1!=stk2);
        //f1 will be false

    @endverbatim
 ************************************************************************/
template<class TY>
inline bool mystack<TY>::operator!=(const mystack<TY>& rhs) const
{
    //have temparary variables for each headptr
    node* tmpRhs = rhs.headptr;
    node* tmp = headptr;

    //if the headptrs are equal
    if (headptr == rhs.headptr)
    {
        //return false
        return false;
    }

    //while both the headptrs are not equal to nullptrs, compare each element
    while (tmp != nullptr && tmpRhs != nullptr)
    {
        if (tmp->theItem.faceValue != tmpRhs->theItem.faceValue)
        {
            return true;
        }

        //increment both the temparary variables
        tmp = tmp->next;
        tmpRhs = tmpRhs->next;
    }

    //if one of them is nullptr and the other is not return true
    if (tmp == nullptr && tmpRhs != nullptr)
    {
        //return true
        return true;
    }
        //check the other way round
    else if (tmpRhs == nullptr && tmp != nullptr)
    {
        //return true
        return true;
    }

    //reutnr false
    return false;

}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is an overloaded of the template stack class mystack. It checks if
 *  the face value of top element is less than the other
 *
 *  @param[in, out] rhs the second stack
 *
 * @returns a bool value, true if the top element of stk1 < than that of stk2
          false otherwise
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk1, stk2;
    bool f1, f2;
    card acard;
    acard.faceValue=2;
    acard.suit=1;
    stk1.push(acard);

    if(stk2<stk1)
    {
         //it will enter this part
    }

    @endverbatim
 ************************************************************************/
template<class TY>
bool mystack<TY>::operator<(const mystack<TY>& rhs) const
{
    //have temporary variables for the headptrs
    node* temp=headptr;
    node* tempRhs = rhs.headptr;

    //check if the headptrs are the same
    if (headptr == rhs.headptr)
    {
        return false;
    }

    //check if one of them is a nullptr and the other is not
    if (temp == nullptr && tempRhs!=nullptr)
    {
        return true;
    }

        //check if one of them is a nullptr and the other is not
    else if (temp != nullptr && tempRhs == nullptr)
    {
        return false;
    }

    //compare the top elements
    if (temp->theItem.faceValue < tempRhs->theItem.faceValue)
    {
        //return true
        return true;
    }

    //return false
    return false;


    /////////////////for a general stack////////////////

    //while (temp != nullptr && tempRhs != nullptr)
    //{
    //    if (temp->theItem.faceValue < tempRhs->theItem.faceValue)
    //    {
    //        return true;
    //    }
    //    temp = temp->next;
    //    tempRhs = tempRhs->next;
    //}

    //if (temp == nullptr && tempRhs != nullptr)
    //{
    //    return true;
    //}

    //return false;

    /////////////////////////////////////////////////////////////////
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is an overloaded of the template stack class mystack. It prints
 *  the stack to the passd output stream
 *
 *  @param[in, out] out the putput file stream
 *  @param[in] s1 the stack to be outputted
 *
 * @returns an output stream
 *
 *  @par Example
 *  @verbatim

    mystack<card> stk1;
    ostringstream sout;
    card acard;
    acard.faceValue=2;
    acard.suit=1;
    stk1.push(acard);
    sout<<stk1;
    //it will output the stack

    @endverbatim
 ************************************************************************/
template<class TY>
ostream& operator<<(ostream& out, mystack<TY>& s1)
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
        acard = s1.front();
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

