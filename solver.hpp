#include <stdio.h>
#include <complex>

namespace solver{
class RealVariable{
public:
double re;
double x;
double x2;

RealVariable()=default;
RealVariable(double _x2,double _x,double _re){
re=_re;
x2=_x2;
x=_x;

}
RealVariable operator-(double a){
RealVariable temp(0,0,0);
return temp;

}
friend RealVariable operator*(double a,const RealVariable& f);
friend RealVariable operator*(const RealVariable& f,double a);
friend RealVariable operator-(const RealVariable& f,double a);
friend RealVariable operator-(const RealVariable& f,const RealVariable& e);
friend RealVariable operator/(const RealVariable& h,double e);
friend RealVariable operator^(const RealVariable& f,double a);
friend RealVariable operator+(const RealVariable& x,const RealVariable& f);
friend RealVariable operator+(const RealVariable& x,double a);
friend RealVariable operator+(double a,const RealVariable& x);
friend RealVariable operator==(const RealVariable& a,const RealVariable& b);
friend RealVariable operator==(const RealVariable& a,double e);

RealVariable operator=(const RealVariable& a){
RealVariable count(a.x2,a.x,a.re);
return count;
}
};

//-----------------------------------------------------------------------------------------------------------------------



class ComplexVariable{
public:
double re;
double img;
ComplexVariable()=default;
ComplexVariable(double _re,double _img){
re=_re;
img=_img;

}
ComplexVariable operator-(double e)
{
ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator==(const ComplexVariable& e){

ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator==(std::complex<double> yvalue){

ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator==(double e){

ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator^(double e){

ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator+(const ComplexVariable& e){

ComplexVariable temp(re+e.re,img+e.img);
return temp;
}
ComplexVariable operator+(double e){

ComplexVariable temp(re+e,img);
return temp;
}
ComplexVariable operator/(double e){
ComplexVariable temp(0,0);
return temp;
}
friend ComplexVariable operator+( const ComplexVariable& e,std::complex<double> yvalue){

ComplexVariable temp(0,0);
return temp;

}
friend ComplexVariable operator+(double e,const ComplexVariable& f);
friend ComplexVariable operator+(double ef,std::complex<double> e);
friend ComplexVariable operator-(const ComplexVariable& e,const ComplexVariable& f);
friend ComplexVariable operator*(double e,const ComplexVariable& f);

};


double solve(const RealVariable a);

std::complex<double> solve( const ComplexVariable b);

};
