#include <iostream>

bool isEven(long long number){
  return number & 1;
}

int main (){
  std::cout << isEven(9223372036854775807);
}

/*Рабатает корректно для всех чисел, которые принадлежат диапозону long long
  Не работает корректно с числами, которые попадают в unsigned long long 
  Решает проблему работы с отрицательными числами
*/