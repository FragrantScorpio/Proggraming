#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const auto PI = 3.141592653589793;
const double limit = 1e-10;

enum coord_system
{
    Cartesian,
    Polar
};

class Point {
private:
    double x, y;
public:
    string data;


    Point(double a1 = 0, double a2 = 0, coord_system syst= coord_system::Cartesian) 
    {
        if (syst == coord_system::Cartesian) { this->x = a1; this->y = a2; }
        else {
            x = a1 * cos(a2); y = a1 * sin(a2);
        }
    };

 
    double get_x() { return this->x; }
    double get_y() { return this->y; }
    double get_r() { return sqrt((pow(x, 2) + pow(y, 2))); }
    double get_phi() { return atan2(this->y, this->x); }
    
    void set_x(double a) { x = a; return; }
    void set_y(double a) { y = a; return; }
    void set_r(double r) { double f = (get_phi()); this->x = r * cos(f); this->y = r * sin(f); return; }
    void set_phi(double phi) {
        double buff = get_r(); x = buff * cos(phi); y = buff * sin(phi);
    return; }

    bool operator==(Point p2)
    {
        if ((abs(this->get_x() - p2.get_x()) <= limit) and (abs(this->get_y() - p2.get_y() <= limit))) return 1;
        else return 0;
    }
    bool operator!=(Point p2) { return *this != p2; };
 
    friend ostream& operator<<(ostream& output, Point& p)
    {
        output << "(" << p.get_x() << "," << p.get_y() << "), ";
        return output;
    }
    friend istream& operator>> (istream& input, Point& p)
    {
        string buf;
        input >> buf;
        if (buf[0] == '(') { buf = buf.substr(1); }

        auto fin = buf.find(')');
        buf = buf.substr(0, fin);
        auto x = buf.substr(0, buf.find(','));
        auto y = buf.substr(buf.find(',') + 1);

        p.x = stod(x);
        p.y = stod(y);

        return input;
    }
};



int main() {
    std::vector<Point> original;
    std::ifstream fin("data.txt");
    if (!fin.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    }
    else {
        while (!fin.eof()) {
            Point p;
            fin >> p;
            fin.ignore(2); // Точки разделены двумя символами ", "
            original.push_back(p);
           
        }
        fin.close();
    }

    std::vector<Point> simulacrum(original);
    for (auto& p : simulacrum) {
        
        std::cout << "before\n" << p << "\n";
        p.set_x(p.get_x() + 10);
        p.set_phi(p.get_phi() + 180 * PI / 180);
        p.set_y(-p.get_y());
        p.set_x(-p.get_x() - 10);
        //если убрать тут минус и удалить set_phi и set_y то будет выдавать it works, следовательно
        //мне надо было сделать так, чтобы при вызова phi или Y он менял значения из одной системы в другую
        //после всех вычислений все вернулрсь бы на исходную, но у меня это не вышло, я сделал все что в моих силах

        std::cout << "after\n" << p << std::endl;
        
        
    }

    if (std::equal(original.begin(), original.end(), simulacrum.begin()))
        std::cout << "\nIt works!\n";
    else
        std::cout << "\nIt not works!\n";
}
