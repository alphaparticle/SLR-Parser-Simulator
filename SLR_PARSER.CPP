#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <list>
#include <utility>
using namespace std ;

typedef pair < string , string > ss ;

map < ss , string > table ;  // example how the map is working here { I0 , ( } -> { S4 } 


string productions [100][2] ;



int main(){
 int i , j ;
map < ss , string > :: iterator it ;
 string temp1 , temp2 , temp3 ;
 int n , m , T ,NT; // n -> no. of productions
             // m -> no. of states in DFA
             // T -> no. of Terminal symbols
             // NT  -> no. of Non Terminal symbols
 cout << "Enter the no.of productions \n";
 cin >> n ;
 cout <<"Enter the no. of terminal and Non terminal symbols respectively\n";
 cin >> T >> NT ;
 cout <<"Please enter the production rules one in a line\n e.g E -> E+T\n" ;
 for (  i = 0 ; i < n ; i ++){
 	 cin >> productions[i][0] >> productions[i][1] ;
 }
 
  
 cout <<"Enter the total no. of states obtained while constructing the DFA\n";
 cin >> m ;
 cout <<"Enter the CLR Parser ACTION Table\n" ;
 cout <<"eg. State symbol action like : State Terminal_symbol Action\n";
 cout <<"If finish input type # # #\n" ;
 while ( cin >> temp1 >> temp2 >> temp3){
   if ( temp1 == temp2 && temp2 == temp3 && temp1 == "#")
   	break ;
   if ( table.count(ss (temp1,temp2)) == 0 )
    table [ ss (temp1 ,temp2) ] = temp3 ;
   else {
   	 printf("The grammar is ambigous\n") ; return 0 ; 
   }
 }

 

string buffer ,  action ;
stack < string > ST ;
cout <<"Enter the input string to be parsed and checked\n";
cin >> buffer ; 
ST.push ("0") ;
buffer += '$' ;
action = "" ;
vector < string > cc ;
cout <<"          STACK               BUFFER                     ACTION\n" ;
 printf("%25s %25s %25s\n", ST.top().c_str() ,buffer.c_str() , action.c_str());
			  
while (1) {
  cc.clear() ;
  
  if ( buffer == "$" && action == "acc" ){
  	printf("%25s %25s %25s\n", ST.top().c_str() ,buffer.c_str() , action.c_str());
			  
  	cout <<"\n The input string is successfully parsed\n"; return  0 ; 
  }   
    
  temp1 = ST.top() ; temp2 = buffer[0] ;
  temp3 = table [ ss(temp1 ,temp2)] ;
  

  if( temp3[0] == 'S'){
           ST.push(temp2) ; 
           string z ;
           for ( i = 1 ; i < temp3.size() ; i++){
  	        z += temp3[i] ;
            }
           //  cout << z << endl;
			  ST.push(z) ; 
			  buffer.erase ( buffer.begin());
			  action = "shift " ;
			  action += temp3 ;
			  int x = 0 ;
			    for ( i = 0 ; i < z.length() ; i++)
			    x = x*10 + z[i] -'0' ;
			  // action += productions[x-1][0] + "->" + productions[x-1][1] ;
			   cc.clear () ;
			   string s;
			   while ( !ST.empty() ){
			       s = ST.top() ; cc.push_back(s) ; ST.pop() ;
			   }
			   s = "" ;
			   for ( i = cc.size() -1 ; i >= 0 ; i--){
			   	 s += cc[i] ;
			   }
			   printf("%25s %25s %25s\n", s.c_str() ,buffer.c_str() , action.c_str());
			   for ( i = cc.size() -1 ; i >= 0 ; i--){
   	          ST.push(cc[i]) ;
              }
           cc.clear() ;
        //   return 0 ;
 }
 else if ( temp3[0] == 'R' ){
               
               			 	string z ;
			     for ( i = 1 ; i < temp3.size() ; i++){
			  	    z += temp3[i] ;
			    }

			    int x = 0 ;
			    for ( i = 0 ; i < z.length() ; i++)
			    x = x*10 + z[i]-'0' ;
			    z = "" ; z = ST.top() ;
			    while ( z[0] != productions[x-1][1][0] ){
			    	ST.pop() ; z = ST.top() ;
			    }
			    ST.pop() ;

			    action = "reduce " ; action += temp3 + " " ; 
			    action += productions[x-1][0] + "->" + productions[x-1][1] ;
               // cout <<"---> " << ST.top () <<" "<<productions[x-1][0]<<endl;
			    string s = table [ ss (ST.top() , productions[x-1][0] )] ;
			    //cout << s << endl;
			    
			    ST.push (productions[x-1][0])  ; ST.push (s) ;

			     while ( !ST.empty() ){
			       s = ST.top() ; cc.push_back(s) ; ST.pop() ;
			      }
			      s = "";
			      for ( i = cc.size() -1 ; i >= 0 ; i--){
			   	    s += cc[i] ;
			     }
			  printf("%25s %25s %25s\n", s.c_str() , buffer.c_str() , action.c_str());
			   for ( i = cc.size() -1 ; i >= 0 ; i--){
			   	  ST.push(cc[i]) ;
			   }
			  cc.clear() ;
          //return 0 ;
     }
     else if ( temp3 == "acc")
     action = temp3 ; 
  }


return 0 ; 

}
