#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  while (cin>>a>>b>>c){
    int determinant = b*b-4*a*c;
    if (determinant<0){
      cout<< "No real root"<<endl;
      continue;
    }
    int root1 = ((-1)*b + sqrt(b*b-4*a*c))/(2*a);
    int root2 = ((-1)*b - sqrt(b*b-4*a*c))/(2*a);
    if (root1 == root2){
      cout<<"Two same roots x="<< root1<< endl;
    }else{
      cout<< "Two different roots x1="<< root1<<" , x2="<<root2<<endl;
    }
  }
}
