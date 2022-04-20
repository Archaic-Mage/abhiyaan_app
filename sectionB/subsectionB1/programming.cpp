#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) 
{

    int n, m; cin >> n >> m;                //we take the size of the 2D matrix

    int k; cin >> k;                        //we take the element to find

    int arr[n][m];                          //we declare our matrix here 

    for(int i = 0; i<n; i++) 
    {
        for(int j = 0; j<m; j++) cin >> arr[i][j];
    }

    //since the matrix is sorted row and column wise, also first element of next row is larger than
    //the last element in previous row
    //the algorithm is as follows ;;;
    //---1/ We first Binary Search the column 0 to find the row in which the number might belong 
    //---2/ After finding the row, we BS the row to find the column the element is in
    //---3/ we consider cases if element is not in the matrix
    

    int l = 0, h = n-1;
    int row;

    //we want to find the lower bound of k, in the first column of all the rows
    //this ensures that the element we want to find is present in that row

    while(l < h) 
    {
        int mid = (l+h)/2;

        if(arr[mid][0] == k) {
            row = mid;
            break;
        }

        if(arr[mid][0] < k) l = mid + 1;
        else h = mid-1;
    }

    if(l == h) { //this part ensures that row (element) is always the lower bound
        if(arr[l][0] > k) row = l-1;
        else row = l;
    }

    l = 0, h = m-1;
    int col;

    //this BS, the row to find the element if present 

    while(l <= h) 
    {
        int mid = (l+h)/2;

        if(arr[row][mid] == k) {
            col = mid;
            break;
        }

        if(arr[row][mid] > k) h = mid-1;
        else l = mid+1;

    }

    if(l > h) col = h;

    //checking the condition if present 

    if(arr[row][col] == k) 
    {
        cout << "True\n";
        cout << row << " " << col << "\n";
    }
    else cout << "False\n";

    return 0;
}
