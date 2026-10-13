#include <stdio.h>  
#include <math.h>   
#include <locale.h> 

int main() {
    double x, y, z;
    double h; // результат
    double numerator, denominator; // числитель и знаменатель
    double term1, term2, term3; // 3 части выражения
    x = 2.444;
    y = 0.869e-2;  // 0.869 * 10^-2 
    z = -0.13e3;   // -0.13 * 10^3
    // вычисление x ^ (y + 1) + e ^ (y - 1)
    numerator = pow(x, y + 1.0) + exp(y - 1.0); // Pow - возводит в степень, exp вычисляет экспоненту
    // вычисление 1 + x * |y - tg(z)|
    denominator = 1.0 + x * fabs(y - tan(z)); // fabs для модуля числа, tan - тангенс
    // (1 + |y - x|)
    // Собираем первую часть целиком
    term1 = (numerator / denominator) * (1.0 + fabs(y - x));

    // |y - x|^2 / 2
    term2 = pow(fabs(y - x), 2.0) / 2.0;

    // |y - x|^3 / 3
    term3 = pow(fabs(y - x), 3.0) / 3.0;
    h = term1 + term2 - term3;
    printf("Result h = %.5f\n", h); // %.5f означает вывод числа с плавающей точкой и 5 знаками после запятой

    return 0; 
}