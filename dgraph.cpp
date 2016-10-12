// ====   For the dgraph.cpp file ====================================
// INSTRUCTION:
// Complete all the functions you listed in dgraph.h
// Comment the file completely using How to Comment file.
//=====================================

/* note that Gtable[i].adjacnentOnes is a slist, so you can use
   any slist function on it

Hint on filltable::

Set up fin stream to read from table.txt
while (fin >> Gtable[countUsed].vertexName)  // if I can read the name
{ fin >> Gtable[coutUsed].outDegree;
  // Then for the outDegree times do the following: (use a for-loop)
  {
     fin >> X;
     (Gtable[coutUsed].adjacentOnes).addRear(x); 
                      // this uses a slist function from HW3
  }//end of for
  // increment the countUsed
}//end of while
close fin

Hint on displaygraph::

Make the following couts better with labels.
for (int i = 0; i < coutUsed; i++}
{  
    cout << Gtable[i].vertexname << endl;
    cout << Gtable[i].outdegree << endl;
    (Gtable[i].adjacentOnes).displayAll();
}  

Instruction on findOutDegree and findAdjacency::

For this HW, you must use a loop.
Do not go through all the slots of the table
Just go through the used slots.

*/


#include "dgraph.h"
/*
Name: Chris Morikawa
HW: HW6
Complier: g++
File Type: Dgraph implementation file
/*
Purpose: initializes the table entries
Local Varialbes: int i
*/

dgraph::dgraph()
{
 this->countUsed = 0;
 for(int i = 0; i < SIZE; i++)
 {
 	this->Gtable[i].vertexName = ' ';
	this->Gtable[i].outDegree = 0;
	this->Gtable[i].visit = 0;
 }
}

/*
Purpose: To destory the table when its done.

*/
dgraph::~dgraph()
{
cout << "Destroying the Table!!!!!!" << endl;
}

/*
Purpose: reads the input file table.txt to fill the table
Open and close the input file table.txt in here
Algorithm: Read the text file, then read the vertex names and read out the degree times using the for loop. In the for loop, add the degree into the Graph using addRear function. 
Local Variable: char x, int x
*/
void dgraph::fillTable()
{
 ifstream fin;
 fin.open("table.txt");
 char x;
 while (fin >> Gtable[countUsed].vertexName)   // if I can read the name
	{  
	  fin >> Gtable[countUsed].outDegree;
          // Then for the outDegree times do the following: (use a for-loop)  	  
	  for (int i = 0; i < Gtable[countUsed].outDegree; i++)
	   {
             fin >> x;
	     cout << "Degree: " << x << endl;
     	    (Gtable[countUsed].adjacentOnes).addRear(x);
            // this uses a slist function from HW3
	   }
	  countUsed++;
  	 // increment the countUsed
	}//end of while
 fin.close();
}

/*
Purpose: displays the table content in a very readable format, but make sure you do not display unused slots
Algorithm: Using a for loop, read out the vertex name. If the visit number is not zero then read out the visit number and the degree. Also if the 
AdjacentsOnes is not empty then display it.
Local Variable: int i 
*/
void dgraph::displayGraph()
{
 //Make the following couts better with labels.
cout << "_______THE GRAPH TABLE_______" << endl; 
 for (int i = 0; i < countUsed; i++)
 {
    cout << "Vertex Name: " << Gtable[i].vertexName << " ";
    cout << "Out-Degree: " << Gtable[i].outDegree << endl;
    cout << Gtable[i].vertexName << " "; 
    (Gtable[i].adjacentOnes).displayAll();
    cout << "------------------" << endl;
 }
cout << "_____________________________" << endl;
}

/*
Purpose:returns the out degree of the vertex
whose name is given as an argument
Use a loop but search through used slots only. 
May throw an exception.
Local Variables: int i
Parameters: char x
*/
int dgraph::findOutDegree(char x)
{
 for (int i = 0; i < countUsed; i++)
 {
  if (x == Gtable[i].vertexName)
   {
    return Gtable[i].outDegree;
   }
 }
 throw BadVertex();
}

/*
Purpose: Returns the linked list of adjacent vertices of 
the vertex whose name is given as an argument
Use a loop but search through used slots only.
May throw an exception.
Local Variables: int i
Parameters: char y
*/
slist dgraph::findAdjacency(char y)
{
 for (int i = 0; i < countUsed; i++)
 {
  if (y == Gtable[i].vertexName)
  {
   return Gtable[i].adjacentOnes;
  }
 }
 throw BadVertex();
}

