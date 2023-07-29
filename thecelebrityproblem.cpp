#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
    
   
    int p = 0, q = n-1; 

   
    while(p < q) {
        if(knows(p, q)) {
            
            p++;  
        }
        else {
           
            q--; 
        }
    }

    int celebrity = p;
    bool knowAny = false, knownToAll = true;

    
    for(int i = 0; i < n; i++) {
        if(knows(celebrity, i)) {
            knowAny = true;
            break;
        }
    }

    
    for(int i = 0; i < n; i++) {
        if(i != celebrity and !knows(i, celebrity)) {
            knownToAll = false;
            break;
        }
    }

    if(knowAny or !knownToAll) {
       
        celebrity = -1;
    }

    return celebrity;
}
