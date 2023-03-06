#include <iostream>
#include <cmath>

struct QuadSolution 
{
    double x1;
    double x2;
};

QuadSolution solve_quadratic_equation(double a, double b, double c) 
{
    QuadSolution result;

    if (a == 0) 
    {
        // ���� ����������� ��� x^2 ����� ����, �� ��������� �� �������� ����������
        result.x1 = result.x2 = NAN;
    }
    else 
    {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            result.x1 = (-b + sqrt(discriminant)) / (2 * a);
            result.x2 = (-b - sqrt(discriminant)) / (2 * a);
        }
        else if (discriminant == 0) 
        {
            result.x1 = result.x2 = -b / (2 * a);
        }
        else 
        {
            // � ������, ���� ������������ ������ ����, ��������� �� ����� �������
            result.x1 = result.x2 = NAN;
        }
    }

    return result;
}

int main() 
{
    double a, b, c;
    std::cout << "Input a, b � c: ";
    std::cin >> a >> b >> c;

    QuadSolution solution = solve_quadratic_equation(a, b, c);

    if (std::isnan(solution.x1) || std::isnan(solution.x2)) {
        std::cout << "No roots" << std::endl;
    }
    else {
        std::cout << "Roots: " << solution.x1 << " and " << solution.x2 << std::endl;
    }

    return 0;
}
