#include <iostream>

using namespace std;

struct rectangle{
    int x,y;
    int length, width;
};

rectangle getRectangle(){
    rectangle r;
    cout<<"enter coordinates of rectangle(x,y): "<<endl;
    cin >>r.x>>r.y;
    cout <<"enter length : "<<endl;
    cin >>r.length;
    cout <<"enter width : "<<endl;
    cin >>r.width;
    return r;
}
int main(){
    rectangle rect1;
    rect1=getRectangle();
    cout<<"rectangle 1 : "<<rect1.x<<","<<rect1.y<<","<<rect1.length<<","<<rect1.width<<endl;
    return (0);
}
