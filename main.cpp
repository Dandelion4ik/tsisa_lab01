#include <cmath>
#include <iomanip>
#include <iostream>

void print_min(const double &a, const double &b) {
  std::cout << "The minimum value of the function is reached when x = "
            << (a + b) / 2 << " +- " << (b - a) / 2;
}

void print_head() {
  std::cout << "---------------------------------------------------"
            << std::endl;
  std::cout << "|" << std::setw(9) << std::right << "ak"
            << "|" << std::setw(9) << "bk"
            << "|" << std::setw(9) << "l"
            << "|" << std::setw(9) << "f(ak)"
            << "|" << std::setw(9) << "f(bk)"
            << "|" << std::endl;
  std::cout << "---------------------------------------------------"
            << std::endl;
}

void print(const double &a, const double &b,const double &xr1, const double &xr2, const double &eps) {
  if (b - a >= eps) {
    std::cout << "|" << std::setw(9) << std::right << a << "|" << std::setw(9)
              << b << "|" << std::setw(9) << b - a << "|" << std::setw(9)
              << -sqrt(xr1) * sin(xr1) + 2 << "|" << std::setw(9)
              << -sqrt(xr1) * sin(xr2) + 2 << "|" << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
  } else {
    std::cout << "|" << std::setw(9) << std::right << a << "|" << std::setw(9)
              << b << "|" << std::setw(9) << b - a << "|" << std::setw(19)
              << "l < epsilon "
              << "|" << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
  }
}

void deleting_segment(double &a, double &b, double &xr1, double &xr2) {
  double fun_value_at_XR1 = -sqrt(xr1) * sin(xr1) + 2;
  double fun_value_at_XR2 = -sqrt(xr2) * sin(xr2) + 2;
  if (fun_value_at_XR1 < fun_value_at_XR2) {
    b = xr2;
  } else {
    a = xr1;
  }
}

void dihotomia(double &a, double &b, const double &sigma, const double &eps) {
  double lengh_segment = b - a;
  print_head();
  while (lengh_segment > eps) {
    double xr1 = ((a + b) / 2 - sigma);
    double xr2 = ((a + b) / 2 + sigma);
    print(a, b,xr1,xr2, eps);
    deleting_segment(a, b, xr1, xr2);
    lengh_segment = b - a;
  }
  print(a, b,0,0, eps);
  print_min(a, b);
}

int main() {
  double a = 1;
  double b = 4;
  const double sigma = 0.001;
  const double eps = 0.1;
  dihotomia(a, b, sigma, eps);
  return 0;
}
