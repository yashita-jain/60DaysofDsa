//Time complexity
//Space Complexity
//Asymptotic Notations
//Comparision of Functions

//Some Basic Starter Preblems

#include <stdio.h>
int main()
{

        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);

        int rem;
        rem = (a * x) + (b * y);
        printf("%d", rem);
   

    return 0;
}





#include <stdio.h>

int main()

{
    int N;
    scanf("%d", &N);
    if (N % 5 != 0 && N % 11 != 0)
    {
        printf("NONE");
    }
    if (N % 5 == 0 && N % 11 != 0)
    {
        printf("ONE");
    }
    if (N % 5 != 0 && N % 11 == 0)
    {
        printf("ONE");
    }

    if (N % 5 == 0 && N % 11 == 0)
    {
        printf("BOTH");
    }

    return 0;
}



#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int k=0; 
	for(int i=1;i<=n;i++){
	    if(n%i==0){
	       k=k+1 ;
	       
	    }
	}
	cout<<k<<endl;
		for(int i=1;i<=n;i++){
	    if(n%i==0){
	        cout<<i<<" ";
	    }
	}
	return 0;
}


#include <iostream>
using namespace std;

int main() {
	int arr[3];
	cin>>arr[1];cin>>arr[2];cin>>arr[3];
   if(arr[1]>arr[2]){
       swap(arr[1],arr[2]);
   }
	 if(arr[1]>arr[3]){
       swap(arr[1],arr[3]);
   } 
   if(arr[2]>arr[3]){
       swap(arr[2],arr[3]);
   }
   
   cout<<arr[2];
	return 0;
}


#include <iostream>
using namespace std;

int main() {
	int l,r;
	cin>>l>>r;
   if(l%2==0){
     for(int i=l+1;i<=r;i=i+2){
         cout<<i<<" " ;
     }
   }
   else{
       for(int i=l;i<=r;i=i+2){
         cout<<i<<" " ;
     }
   }
	return 0;
}



#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
   if(n%5==0){
      cout<<"YES";
   }
   else if(n%6==0){cout<<"YES";}
   else {cout<<"NO";}
return 0;
}


#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];
 for(int i=0;i<n;i++) 
 {cin>>a[i];
  }
  
  for(int i=n-1;i>=0;i--) 
 {cout<<a[i]<<" ";
  }
  
	return 0;
}


#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	int a[n],num=0;
    for(int i=0;i<n;i++) 
    {cin>>a[i];
    if(a[i]==k){
     cout<<"1";
     num++;
     break;
 }
 }
  
if(num==0){
    cout<<"-1";
}
  	return 0;
}



#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	int num=0;
if(a+b>c){
  num++;
}
if(b+c>a){
    num++;
}
 if(a+c>b){
    num++;
}
if(num==3){cout<<"YES";}
else{cout<<"NO";}
	return 0;
}



#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int num=0;

for(int i=1;i<=n;i++){
     for(int k=n;k>i;k--){
    cout<<" ";
} 
    
 for(int j=1;j<=i;j++){
    cout<<"*";
}   cout<<endl;
}


	return 0;
}

