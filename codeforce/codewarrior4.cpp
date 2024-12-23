#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double r1, r2, h;
    double a, b, c;
    cin >> r1 >> r2 >> h;
    cin >> a >> b >> c;
    double rmax = max(r1, r2);
    double rmin= r1+r2-rmax;
    double min1= min(a,b);
    double min2=min(min1,c);
    double max1= max(a,b);
    double max2=max(max1,c);
    double tb=a+b+c-min2-max2;
    double x=2min2(rmax-rmin)/h+4rmax+2rmin;
    int sovien=ceil((x+tb)/max2);
    double du=sovienmax2-(x+tb);
    int sovienc=ceil((x+tb-3du)/max2);
    int sv=sovien3+sovienc;
    double sto=(x+2tb)(x+2tb)-xx;
    double volume=stomin2;
    cout << sv <<" "<<fixed << setprecision(2) << volume<< endl;
}