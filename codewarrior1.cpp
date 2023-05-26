#include <bits/stdc++.h>
using namespace std;
double r1,r2,h,a,b,c;
int main(){
    cin>>r1>>r2>>h>>a>>b>>c;
    double x=min(a,min(b,c));
    double y=max(r1,r2);
    int ans=ceil((y*4+8*x)/x);
    printf("%d %.2lf",ans,(ans*x*x*x));
}