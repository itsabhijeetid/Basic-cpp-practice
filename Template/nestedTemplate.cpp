#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair {
    private :
        T x;
        V y;
    public : 
        void setX(T x) {
            this->x = x;
        }
        T getX() {
            return x;
        }
        void setY(V);
        V getY();
};

template <typename T, typename V>
void Pair<T, V> :: setY (V y) {
    this->y = y;
}
template <typename T, typename V>
V Pair<T, V> :: getY () {
    return y;
}

int main () {
    Pair<int, int> p1;
    p1.setX(5);
    p1.setY(4);
    Pair<char,Pair<int,int>> p2;
    p2.setX (100);
    p2.setY (p1);
    cout << "value of x : "<< p2.getX() << "\n y / x : " <<p2.getY().getX() << "\ny/ y : " <<p2.getY().getY();
    // cout << "p1 y : " << p2.getY(); // error will occur as we are trying to print obj
    return 0;
}