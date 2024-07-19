#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size;
    scanf("%d", &size);
    int arr[size]; 
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
  /*   ** First : Make a temp array O(n) space completixy
    int temp[size];
    int temp2;
    for(int i = 0; i < size; i++)
    {
        temp[i] = arr[size - i - 1];
    }  
    
    for(int i = 0; i < size; i++)
    {
        printf("%d ", temp[i]);
    }
*/

    // Or use in built function O(1) space complexity
    std::reverse(arr, arr + size);
    
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

