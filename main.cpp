#include "Matrix.h"

int main(){
    Vector<int> arr(5, 0);
    for (int i = 0; i < 5; i++) arr[i] = i;
    Vector<int> arr2(arr);
    cout << arr << endl << arr2 << endl;
    Vector<int> arr3(move(arr));
    cout << arr3 << "\n";
    // Matrix<int> x(3);
    // Matrix<int> y(3);
    // cin >> x;
    // cin >> y;
    // cout << x << endl << y << endl;
    // cout << x * y;
    Matrix<int> ar1(3, 3);
    Matrix<int> ar2(3, 5);
    cin >> ar1;
    cin >> ar2;
    cout << ar1 << endl << ar2 << endl ;
    cout << ar1.concatHorizontally(ar2);
    return 0;
}