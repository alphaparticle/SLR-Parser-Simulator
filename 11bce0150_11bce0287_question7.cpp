#include <bits/stdc++.h>
using namespace std ;

#define LIM 5000000

char line [1000] ;

typedef vector  < string > vs ;
typedef pair < int , vs > ivs ;

typedef vector <char> vc ;
typedef pair <int , vc > ivc ;

vector< ivs > The;
vector < ivc > Such ;

vector < ivc > An ;

vector <string> Words ;
vector <string> Sentences ;


int main(){

 freopen ( "input.txt" , "r" , stdin) ;
 string temp ; 
 int i , j, sz , no = 0 ;
 bool f = false ;
 int  k = 0 ;
 while ( gets (line) ){
    no++;
    temp . clear() ;
    // Checking For I'st TASK
    f = false ;
    for ( i = 0 ; i < strlen(line) ; i++)
    {
    	 if (line[i] == ' ' ){
    	 	
    	 	if ( temp == "The" )
    	 	{
    	 		 The.push_back ( ivs(no , vs()) ) ;
    	 		 f = true ; 
    	 	}

    	 	if (f){
    	 		 sz = The.size() ;
    	 		 The[sz-1].second.push_back(temp) ;
    	 		 temp.clear() ;
    	 	}
    	 	else
    	 	 temp.clear() ;
    	 }
    	 else 
    		temp += line[i] ;

    }
    if (f && temp.size() > 0)
    {
    	 sz = The.size () ;
    	 The[sz-1].second.push_back(temp) ;
    }

   // CHECKING FOR SECOND TASK

    temp.clear() ;
    f = false ;
    for ( i = 0 ; i < strlen(line) ; i++){
         
         if ( !f ){
         	 if ( line[i] == ' ' && (temp == "Such" )){//|| temp == "such" )){
         	                                           // Can include "such" & "Such" both 
         	    f = true ;
         	    Such.push_back ( ivc (no ,vc() )) ;
         	    sz = Such.size() ;
         	    
         	    for ( j = 0 ; j < 4 ; j++)
         	    Such[sz-1] . second . push_back ( temp[j] );
         	    Such[sz-1] . second . push_back ( ' ' );
                
                continue ;
         	 }
         	 else if ( line[i] == ' ' )
         	 temp.clear() ;
         	else
         	   temp += line[i] ;	
         }

        if ( f ) {
             Such[sz-1].second.push_back (line[i]) ; 
             if ( line[i] == '.' )
             break ; 
        }
    }
    
    // THIRD TASK 

                    temp.clear() ;
				    f = false ;

				    for ( i = 0 ; i < strlen(line) ; i++){
				         
				         if ( !f ){
				         	 if ( line[i] == ' ' && (temp == "An")){//}  || temp == "an" )){
				         	                                           // Can include "an" & "An" both 
				         	    f = true ;
				         	    An.push_back ( ivc (no ,vc() )) ;
				         	    sz = An.size() ;
				         	    
				         	    for ( j = 0  ; j < 2 ; j++)
				         	    An[sz-1] . second . push_back ( temp[j] );

				         	    An[sz-1] . second . push_back ( ' ' );
				                
				                continue ;
				         	 }
				         	 else if ( line[i] == ' ' )
				         	 temp.clear() ;
				         	else
				         	   temp += line[i] ;	
				         }

				        if ( f ) {
				        	 if ( isalnum (line[i]) || line[i] == ' ')
				             An[sz-1].second.push_back (line[i]) ; 
				             else{
				                          An[sz-1].second.push_back (line[i]) ; 
				                          break ;
				             } 
				        }
                    }

              
 }

cout << "I'st Task result ::   No.of results -> " << The.size() << endl;
cout << "II nd Task Result ::  No.of results -> "<< Such.size() << endl;
cout << "IIIrd Task Result ::  No.of results -> "<< An.size() << endl; 

// TASK 4 
 freopen ( "input.txt" , "r" , stdin) ;
 char c ; string s ;
 string  p = "@#$%^&*()_+{}[]:<>=.|/" ;
 set < char > dic ;
 for ( i = 0 ;  i < p.length() ; i++)
 dic.insert(p[i]) ;
  while ( scanf("%c",&c) != EOF ) {
       
        if ( isalpha(c))
        if ( isupper(c))
        do {
        	s += c ;
            if ( dic.find(c) != dic.end() )
            break ;
            if ( c == '\n')
            break ;
        }
         while ( scanf("%c",&c) != EOF ) ;
       //s += '.' ;
       sz = s.length() ;

       if ( sz == 20)
       if ( isalpha(s[0]) && s[sz-1] == '.' )
       {
       	Sentences.push_back(s) ;
       	//cout << "----"<<s <<"<<<"<< endl ;
       	s .clear () ; 
       }
    s.clear() ;
 }

cout << "IVth Task Result ::   No.of results -> "<< Sentences.size() << endl;

// TASK 5

freopen ( "input.txt" , "r" , stdin) ;
string word ;
while ( cin >> word ){
	 sz = word.length() ;
	 sz -= 1 ;
	 if ( word[0] == 't' )
	 if ( word[sz] == 'o' || word[sz] == 'e' || word[sz] == 'l' ){
	 	Words.push_back(word) ;
	 	//cout << word <<" ";
	 }
	 
}

cout <<"Vth TASK  :: No. of words starting with 't' and ending with 'o' || 'e' || 'l' are -> "<<Words.size()<<"\n";



freopen ("task1.txt" , "w" , stdout) ;
cout << "I'st Task result ::   No.of results -> " << The.size() << endl;
for ( i = 0 ; i < The.size() ; i++){
	 ivs u = The[i] ;
	 cout << u.first <<" ";
	 for ( j = 0 ; j < (int) u.second.size() ; j++ )
	 cout << u.second[j]<<" ";
	cout << "\n";
}

freopen ("task2.txt" , "w" ,stdout) ;
cout << "II nd Task Result ::  No.of results -> "<< Such.size() << endl;
for ( i = 0 ; i < Such.size() ; i++ ){
	 ivc u = Such[i] ;
	 cout << u.first <<" -> " ;
	 for (j = 0 ; j < u.second.size() ; j++)
	 cout <<u.second[j] ;
	cout <<"\n" ;
}
freopen ("task3.txt" , "w" , stdout) ;
cout << "IIIrd Task Result ::  No.of results -> "<< An.size() << endl;
for ( i = 0 ; i < An.size() ; i++ ){
	 ivc u = An[i] ;
	 cout << u.first <<" -> " ;
	 for (j = 0 ; j < u.second.size() ; j++)
	 cout <<u.second[j] ;
	cout <<"\n" ;
}
 
freopen("task4.txt" , "w" ,stdout);
cout << "IVth Task Result ::   No.of results -> "<< Sentences.size() << endl;
for ( i = 0 ; i < Sentences.size() ; i++){
	printf("%s\n",Sentences[i].c_str());
}

freopen("task5.txt" , "w" ,stdout);
cout << "IVth Task Result ::   No.of results -> "<< Sentences.size() << endl;
for ( i = 0 ; i < Words.size() ; i++){
	printf("%s\n",Words[i].c_str());
}

  
	return 0 ;
}