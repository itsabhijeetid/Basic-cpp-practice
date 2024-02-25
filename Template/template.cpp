#include <iostream>
using namespace std;

template <typename T>
class Pair {
    private :
        T x;
        T y;
    public :
        // void setX(T x) {
        //     this->x = x;
        // }
        void setX (T);
        void setY(T y) {
            this->y = y;
        }
        T getX() {
            return x;
        }
        T getY() {
            return y;
        }
};

template <typename T>
void Pair <T> :: setX(T x) {
    this->x = x;
}

int main () {
    Pair <int> p1;
    Pair <double> p2;
    p2.setY(20.34);
    p2.setX(10.23);
    p1.setX(10);
    p1.setY(20);
    cout << "x = "<< p1.getX() << "\ny = " << p1.getY() << endl;
    cout << "x = "<< p2.getX() << "\ny = " << p2.getY() << endl;
    return 0;
}