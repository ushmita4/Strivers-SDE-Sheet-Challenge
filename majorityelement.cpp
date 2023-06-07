
int findMajorityElement(int arr[], int n) {    
    
    int majorityElement = -1;
    int count = 0;
    for(int i = 0; i < n; i++) {    
      
        if(count == 0) {
            majorityElement = arr[i];
            count = 1;
            continue;
        }

      
        if(arr[i] == majorityElement) {
            count++;
        }        
        else {
            count--;
        }
    }

    count = 0;

    
    for(int i = 0; i < n; i++) {
        if(arr[i] == majorityElement) {
            count++;
        }
    }

    
    if(count > n / 2) {
        return majorityElement;
    }

    // If no majority element found, return -1.
    return -1;    
}
