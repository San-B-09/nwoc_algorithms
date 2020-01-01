#include<iostream>
using namespace std;
void FibonacciSearch(int *ip_arr, int start, int end, int *fib, int index, int item) {
  int mid;
  mid = start+fib[index-2];
  if(item == ip_arr[mid]) {
      cout<<"\n item found at "<<mid<<" index.";
      return;
  } else if(item == ip_arr[start]) {
      cout<<"\n item found at "<<start<<" index.";
      return;
    } else if(item == ip_arr[end]) {
        cout<<"\n item found at "<<end<<" index.";
        return;
      } else if(mid == start || mid == end) {
          cout<<"\nElement not found";
          return;
        } else if(item > ip_arr[mid])
            FibonacciSearch(ip_arr, mid, end, fib, index-1, item);
          else
            FibonacciSearch(ip_arr, start, mid, fib, index-2, item);
}

/* Function to print an array */
void printArray(int ip_arr[], int size)
{
    int arr_ind;
    for (arr_ind=0; arr_ind < size; arr_ind++)
        cout << ip_arr[arr_ind] << " ";
    cout << endl;
}

int main() {
  int arr_len, arr_ind, ele;
  cout<<"Enter the length of array: ";
  cin>>arr_len;

  int fib[arr_len], ip_arr[arr_len];

  cout<<"Enter the elements of array: \n";
  for(arr_ind = 0; arr_ind<arr_len; arr_ind++){
    cin>>ip_arr[arr_ind];
  }
  cout<<"Entered Array: \n";
  printArray(ip_arr, arr_len);

  char ch;
  fib[0] = 0;
  fib[1] = 1;
  arr_ind = 1;

  while(fib[arr_ind] < arr_len) {
    arr_ind++;
    fib[arr_ind] = fib[arr_ind-1] + fib[arr_ind-2];
  }
  up:
  cout<<"\nEnter the Element to be searched: ";
  cin>>ele;
  FibonacciSearch(ip_arr, 0, 9, fib, arr_ind, ele);
  cout<<"\n\nDo you want to search more...enter choice(y/n)?";
  cin>>ch;
  if(ch == 'y' || ch == 'Y')
  goto up;
  return 0;

}
