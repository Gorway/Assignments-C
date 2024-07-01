#include <stdio.h>


// Структура для представления 2D координат точки с float значениями x и y
typedef struct {
    float x;
    float y;
} Point;

// Функция для вычисления расстояния между двумя точками
float calculate_distance(Point p1, Point p2) {
  
    float dx = p2.x - p1.x;
    
    float dy = p2.y - p1.y;
    
    return dx * dx + dy * dy;
}
// Рекурсивная функция для нахождения наибольшего общего делителя (НОД)
int find_gcd(int a, int b) {
   
    while (b != 0) {
    
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Создаем две точки
    Point point1, point2;

    // Вводим координаты первой точки
    printf("Введите координаты первой точки (x y): ");
    scanf("%f %f", &point1.x, &point1.y);

    // Вводим координаты второй точки
    printf("Введите координаты второй точки (x y): ");
    scanf("%f %f", &point2.x, &point2.y);

    // Вычисляем НОД координат x точек
    int gcd_result = find_gcd((int)point1.x, (int)point2.x);

    // Выводим расстояние между точками и НОД координат x
    printf("Расстояние между точками: %.2f\n", calculate_distance(point1, point2));
    printf("НОД координат x: %d\n", gcd_result);

    return 0;
}

