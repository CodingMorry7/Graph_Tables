// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.

/*

int main()
{ 0.Declare table object
  1.fillTable()
  2.displayGraph()
  while (the user does not want to stop)
    a.the user will specify which vertex     
    b.findOutDegree of the vertex and display the result
    c.catch exception but do not exit

  while (the user does not want to stop)
    a.the user will specify which vertex
    b.findAdjacency of the vertex and display the result (see Hint)
    c.catch exception but do not exit
}


Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/

/*
Name: Chris Morikawa
HW#: HW6
Complier: g++
File: Client for HW6
*/
#include <iostream>
#include "dgraph.cpp"
#include "hw3p3.h"
#include "llist.h"
using namespace std;
int main()
{
 //.Declare table object
 dgraph TheGraph;
 // .fillTable()
 cout << "Grabbing the data from table.txt" << endl;
 TheGraph.fillTable();

 //displayGraph()
 cout << "Displaying the graph" << endl;
 TheGraph.displayGraph();
 
 char d;
 int degree;
 while(true) //Keep going till the user wants to leave
 {
 try
  {
  cout << "****Enter the a Capital letter, and not a lowercase letter****" << endl; 
  cout << "What vertex do you want to view to get out degree?(Enter 0 to exit): " << endl;
  cin >> d;
  if (d == '0')//If the User enters 0, then leave the loop.
  {
   cout << "On to adjacent vertices. Exiting on finding degree" << endl;
   break;
  }
  degree = TheGraph.findOutDegree(d);
  cout << "Vertex found: " << degree << endl;
  }
  catch (dgraph::BadVertex)
  {
   cout << "Wrong Vertex!!!!" << endl;
  }
 }

 char s;
 slist sGraph;
 while (true)//Keep going till the user wants to leave
 {
  try
  {
   cout << "What vertex do you want to view to get adajecent vertices?(Enter 0 to exit): " << endl;
   cin >> s;
   if (s == '0')//If the User enters 0, then leave the loop.
   {
    cout << "Exiting out of Adajecnt vertices!" << endl;
    break;
   }
    sGraph = TheGraph.findAdjacency(s);//Enter the user's character, and retunr back to find the adajecent vertices.
     sGraph.displayAll();
   }
  catch (dgraph::BadVertex)
  {
   cout << "Wrong Vertex!!!!" << endl;
  }
}
return 0;
}

