#include "doctest.h"
#include "solver.hpp"

#include <complex>
//using namespace std;
using namespace std;
using namespace solver;
TEST_CASE("testing ") {
RealVariable xx(0,1,0);
RealVariable& x=xx;
CHECK((solve((x^2) == 16) == 4 || solve((x^2) == 16) == -4));
CHECK(solve(x + 2 == 16) == 14);
CHECK((solve((x^2)+1 == 26) == 5 || solve((x^2) + 1 == 26) == -5));
CHECK((solve((x^2)- 1 == 24) == 5 || solve((x^2) - 1 == 24) == -5));
CHECK(solve(15*x  + 15 == 30) == 14);
CHECK((solve(15*(x^2)  + 15 == 30) == 1 || solve(15*(x^2)  + 15 == 30) == -1));
CHECK((solve(4*(x^2) + 4*x  + 4 == 28) == 3 || solve(4*(x^2) + 4*x  + 4 == 28)== -2));
CHECK((solve((x^2) + x  - 24 == 0) == 3 || solve((x^2) + x  - 24 == 0)== -2));
CHECK(solve((x^2) -2*x +1== 0) == 1);
CHECK(solve(2*(x^2) -4*x +2== 0) == 1);
CHECK(solve(2*(x^2) -4*x == -2) == 1);
CHECK(solve(2*(x^2) -4*x + 8== 6) == 1); //12
CHECK((solve(x + 4*(x^2) == 0) == 0 || solve(x + 4*(x^2) == 0) == (-0.25)));
CHECK((solve(x + 5*(x^2) == 0) == 0 || solve(x + 5*(x^2) == 0) == (-0.2)));
CHECK((solve(x + 6*(x^2) == 0) == 0 || solve(x + 6*(x^2) == 0) == -(1.0/6)));
CHECK(solve(x*2 == 8) == 4);
CHECK(solve(x*2 == 6) == 3);
CHECK(solve(x*2 == 4) == 2);
CHECK(solve(x*2 == 2) == 1);
CHECK(solve(x*2 == 10) == 5);
CHECK(solve(x*2 == 12) == 6);
CHECK(solve(x*2 == 14) == 7);
CHECK(solve(x*2 == 18) == 9);
CHECK(solve(x*2 == 20) == 10);
CHECK( (solve(2*(x^2) == 72) == - 6|| solve(2*(x^2) == 72) == 6) );
CHECK( (solve(2*(x^2) == 50) == - 5|| solve(2*(x^2) == 50) == -5) );
CHECK( (solve(2*(x^2) == 200) == - 10 ||solve(2*(x^2) == 200) == -10) );
CHECK( (solve(8*(x^2) == 200) == - 5 ||solve(8*(x^2) == 200) == -5) );
CHECK( (solve(8*(x^2) +2 == 202) == - 5 || solve(8*(x^2) + 2 == 202) == -5));
CHECK(solve(x*2 + 3 == 29) == 13);



}


TEST_CASE( "testing throws for realvariable" ) {

RealVariable xx(0,1,0);
RealVariable& x=xx;
CHECK_THROWS(solve(x/0));
CHECK_THROWS(solve((x^2) == -1));
CHECK_THROWS(solve(2*(x^2) == -2));
CHECK_THROWS(solve((2*x^2) == -2));
CHECK_THROWS(solve(4*(x^2) == -1));
CHECK_THROWS(solve(5*(x^2) == -1));
CHECK_THROWS(solve(7*(x^2) == -1));
CHECK_THROWS(solve(4*(x^2) == -3));
CHECK_THROWS(solve(4*(x^2) == -5));
x= 3*(x^2) + 20*x + 1;
CHECK_THROWS(solve((x^3) == 2) );
CHECK_THROWS(solve((x^4) == 3) );
CHECK_THROWS(solve((x^6) == 3) );
CHECK_THROWS(solve((x^4) == 3) );
CHECK_THROWS(solve(((x*4 + 2*(x^2) + 5)^ 2) == 3) );
CHECK_THROWS(solve(((x*4 + 2*(x^2) + 5)^ 3) == 3) );
CHECK_THROWS(solve((x^2) + x + 1 == 0) );
CHECK_THROWS(solve(2*(x^2) + 2*x + 2 == 0) );
CHECK_THROWS(solve(3*(x^2) + 3*x + 3 == 0) );
CHECK_THROWS(solve(2*(x^2) + 2*x  == -2) );
CHECK_THROWS(solve(2*(x^2) + 2*x + 4 == 2) );
}


TEST_CASE("testing complexVariable") {
    ComplexVariable y;
    std::complex<double> yvalue = solve(2*y-4 == 10);
    CHECK(yvalue == 7.0 + 0i);
    yvalue = solve((y^2) == 16);
     CHECK((yvalue == 4.0 + 0i || yvalue== -4.0 + 0i));   // 4+0i or -4+0i
   CHECK((solve((y^2) == -16) == 0.0 + 4i || solve((y^2) == -16) == 0.0 - 4i));
    CHECK((solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) == 4.0+0i ||solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y)==  -4.0+0i )) ;   // 4+0i or -4+0i
   CHECK(solve(y+5i == 2*y+3i)  == 0.0 +2i);   // 0+2i
    CHECK(solve(y+7i == 2.0+5i)  == 2.0-2i);
   CHECK(solve(y+8i == 2.0+5i)  == 2.0 -3i);
   CHECK(solve(y+9i == 2.0+5i)  == 2.0 -4i);
   CHECK(solve(y+10i == 2.0+5i)  == 2.0 -5i);
   CHECK(solve(y+8i == 3.0+5i)  == 3.0 -3i);
 CHECK(solve(y+8i == 4.0+5i)  == 4.0 -3i);
  CHECK(solve(y+6i == 2.0+5i)  == 2.0 -1i); //12
 CHECK(solve(y+6i == 2*y+6i)  == 0.0 +0i);
 CHECK(solve(y+6i == 3*y+6i)  == 0.0 +0i);
 CHECK(solve(y+6i == 4*y+6i)  == 0.0 +0i);
 CHECK(solve(y+6i == 5*y+6i)  == 0.0 +0i);
 CHECK(solve(y+6i == 6*y+6i)  == 0.0 +0i);
 CHECK(solve(y+6i == 7*y+6i)  == 0.0 +0i);
 CHECK(solve(y+6i == 8*y+6i)  == 0.0 +0i);
 CHECK(solve(y+6i == 9*y+6i)  == 0.0 +0i);//20


 CHECK(solve(y+5i == 2*y+6i)  == 0.0 -1i);
 CHECK(solve(y+4i == 2*y+6i)  == 0.0 -2i);

 CHECK(solve(y+5i == 2*y+5i)  == 0.0 +0i);
 CHECK(solve(y+5i == 3*y+5i)  == 0.0 +0i);
 CHECK(solve(y+5i == 4*y+5i)  == 0.0 +0i);
 CHECK(solve(y+5i == 5*y+5i)  == 0.0 +0i);
 CHECK(solve(y+5i == 6*y+5i)  == 0.0 +0i);
 CHECK(solve(y+5i == 7*y+5i)  == 0.0 +0i);
 CHECK(solve(y+5i == 8*y+5i)  == 0.0 +0i);
 CHECK(solve(y+5i == 9*y+5i)  == 0.0 +0i);//30
 CHECK(solve(y+2i == 4.0+5i)  == 4.0 +3i);
CHECK(solve(y+2i == 6.0+5i)  == 6.0 +3i);

CHECK(solve(y+2i == 7.0+5i)  == 7.0 +3i);
CHECK(solve(2*y+1i == 4.0+5i)  == 2.0 +2i);
CHECK(solve(y+3i == 4.0+5i)  == 4.0 +2i);
CHECK(solve(y+2i == 4.0+6i)  == 4.0 +4i);
CHECK(solve(y+4i == 4.0+5i)  == 4.0 +1i);
CHECK(solve(2*y+4i == 4.0+6i)  == 2.0 +0i);
CHECK(solve(2*y+2i == 4.0+4i)  == 2.0 +0i);
CHECK(solve(3*y+4i == 12.0+19i)  == 4.0 +5i);
 CHECK(solve(y +2i==4.0 -3i)  == 4.0 -1i);

CHECK_THROWS(solve(y/0));
CHECK_THROWS(solve(2*y/0));
CHECK_THROWS(solve(3*y/0));
CHECK_THROWS(solve(4*y/0));
CHECK_THROWS(solve(5*y/0));
CHECK_THROWS(solve(3*(y^2)/0));
CHECK_THROWS(solve((3*y/2)^3));
CHECK_THROWS(solve(0*y +22i==4.0 -3i));

CHECK_THROWS(solve(9*y/0));









}


