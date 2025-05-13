#include <iostream>

using namespace std;
// تعریف یک نوع به نام rectangle
struct rectangle{
    int x,y;
    int length, width;
};
// تابع بدست اوردن مساحت  مستطیل
int S(rectangle r){
    return(r.length*r.width);
}
//تابع بدست اوردن محیط مستطیل
int P(rectangle r){
    return(2*(r.length+r.width));
}
int print (rectangle r){
    for(int i=0;i<r.length;i++){
        cout<<"- ";
    }
    cout<<endl;
    for(int i=0;i<r.width;i++){
        cout<<"| ";
            for(int j=0;j<r.length-2;j++){
                cout<<"  ";
            }
            cout<<"| "<<endl;
    }
    for(int i=0;i<r.length;i++){
        cout<<"- ";
    }
    cout<<endl;
}

int main()
{
    rectangle M;
    cout << "enter length: " ;
    cin>>M.length;
    cout<<"enter width: ";
    cin>>M.width;
    cout<<"S: "<<S(M)<<endl;
    cout<<"P: "<<P(M)<<endl;
    cout<<print(M);
    return 0;
}
