

#ifndef COMPLEX_DIGITALS_COMPLEXDIGITAL_H
#define COMPLEX_DIGITALS_COMPLEXDIGITAL_H


class ComplexDigital{

public:
    inline ComplexDigital();
    explicit ComplexDigital(double a);
    ComplexDigital(double a, double b);


    friend ComplexDigital operator+(const ComplexDigital& a, const ComplexDigital& b);
    friend ComplexDigital operator+(const ComplexDigital& a,const double& b);
    friend ComplexDigital operator+(const double& a, const ComplexDigital& b);


    friend ComplexDigital operator*(const ComplexDigital& a, const ComplexDigital& b);
    friend ComplexDigital operator*(const ComplexDigital& a, const double& b);
    friend ComplexDigital operator*(const double& a, const ComplexDigital& b);


    friend ComplexDigital operator-(const ComplexDigital& a, const ComplexDigital& b);
    friend ComplexDigital operator-(const ComplexDigital& a, const double& b);
    friend ComplexDigital operator-(const double& a, const ComplexDigital& b);


    friend ComplexDigital operator/(const ComplexDigital& a, const ComplexDigital& b);
    friend ComplexDigital operator/(const ComplexDigital& a, const double& b);
    friend ComplexDigital operator/(const double& a, const ComplexDigital& b);


    ~ComplexDigital();


    friend bool operator==(const ComplexDigital& b, const ComplexDigital& a);
    friend bool operator!= (const ComplexDigital& b, const ComplexDigital& a);


    friend std::ostream & operator<< (std::ostream &, const ComplexDigital &);
    friend std::istream & operator>> (std::istream &, ComplexDigital &);

private:
    double re;
    double im;
};


#endif //COMPLEX_DIGITALS_COMPLEXDIGITAL_H
