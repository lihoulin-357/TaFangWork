#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

//下面需要补充多个类的声明及实现代码
____qcodep____

//填空结束
 

int main()
{
    vector<Point> vertices;
    for (int i=0;i<4;i++){
        double x,y;
        cin>>x>>y;
        Point p(x,y);
        vertices.push_back(p);
    }

    Quadrilateral q(vertices);
    Parallelogram pa(vertices);
    Rectangle r(vertices);

    cout<<fixed<<setprecision(2);

    cout<<(q.verify()?1:0)<<endl;
    cout<<q.getArea()<<endl;
    cout<<q.getPerimeter()<<endl;

    cout<<(pa.verify()?1:0)<<endl;
    cout<<pa.getArea()<<endl;
    cout<<pa.getPerimeter()<<endl;

    cout<<(r.verify()?1:0)<<endl;
    cout<<r.getArea()<<endl;
    cout<<r.getPerimeter()<<endl;

    return 0;
}