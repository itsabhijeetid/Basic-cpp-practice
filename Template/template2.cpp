#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair {
    private :
        T x;
        V y;
    public :
        void setX (T);
        T getX ();
        void setY (V y) {
            this->y = y;
        }
        V getY () {
            return y;
        }
};

template <typename T, typename V>
void Pair<T, V> :: setX (T x) {
    this->x = x;
}

template <typename T, typename V>
T Pair<T, V> :: getX () {
    return x;
}

int main() {
    Pair <int, double> p1;
    p1.setX(10);
    p1.setY(20.89);
    cout << "x = "<< p1.getX() << "\ny = " << p1.getY() << endl;
    return 0;
}