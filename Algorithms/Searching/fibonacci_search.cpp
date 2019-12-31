#include<iostream>
using namespace std;
void FibonacciSearch(int *a, int start, int end, int *fib, int index, int item) {
  int i, mid;
  mid = start+fib[index-2];
  if(item == a[mid]) {
      cout<<"\n item found at "<<mid<<" index.";
      return;
  } else if(item == a[start]) {
      cout<<"\n item found at "<<start<<" index.";
      return;
    } else if(item == a[end]) {
        cout<<"\n item found at "<<end<<" index.";
        return;
      } else if(mid == start || mid == end) {
          cout<<"\nElement not found";
          return;
        } else if(item > a[mid])
            FibonacciSearch(a, mid, end, fib, index-1, item);
          else
            FibonacciSearch(a, start, mid, fib, index-2, item);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
  int n, i;
  cout<<"Enter the length of array: ";
  cin>>n;

  int fib[n], a[n];

  cout<<"Enter the elements of array: \n";
  for(i = 0; i<n; i++){
    cin>>a[i];
  }
  cout<<"Entered Array: \n";
  printArray(a, n);

  char ch;
  fib[0] = 0;
  fib[1] = 1;
  i = 1;

  while(fib[i] < n) {
    i++;
    fib[i] = fib[i-1] + fib[i-2];
  }
  up:
  cout<<"\nEnter the Element to be searched: ";
  cin>>n;
  FibonacciSearch(a, 0, 9, fib, i, n);
  cout<<"\n\nDo you want to search more...enter choice(y/n)?";
  cin>>ch;
  if(ch == 'y' || ch == 'Y')
  goto up;
  return 0;

}
