# Задания к уроку "Марш-бросок по основам языка"
1. Написать программу, которая получает на вход возраст человека, и выводит, можно ли ему уже в РФ водить автомобиль
2. Дополнить первую программу и сделать так, чтобы она также определяла, можно ли человеку водить мопед.
3. Дополнить вторую программу с учётом того, что люди не могут быть старше 200 лет и не могут быть младше 0 лет. При вводе некорректного возраста нужно вывести ошибку.
4. **Бонус!** Реши [самую простую задачу задачу](https://codeforces.com/problemset/problem/4/A?locale=ru) с четвёртого соревнования по спортивному программированию на сайте `Codeforces`. Подсказка: для решения этой задачи можно обойтись только двумя переменными и одним `if`/`else`.
5. Написать программу, которая выводит первые 10 нечётных чисел через пробел на экран при помощи цикла `for`. Сделать отдельно ту же программу, но с использованием цикла `while`.
6. Напиши программу, которая выводит на экран ёлочку:
```
    *
   ***
  *****
```  
Конечно же, это надо сделать, не просто выводя заготовленную строчку :)  
Вывод ёлочки вынести в отдельную функцию.

7. **Бонус!** Сделать так, чтобы функция вывода ёлочки принимала один аргумент - нужную высоту ёлочки, и на основе этого аргумента выводила ёлочку заданной длины. Будем считать, что максимальная длина ёлочки - 15.
8. **Бонус!** Решить первые 2 задачи с сайта https://projecteuler.net/about (можно легко нагуглить версию сайта на русском языке). Если хочешь самостоятельно продвинуться чуть дальше по материалу - можешь решить первые 5 задач.

Вообще, `projecteuler` - это легендарный сайт с задачками по программированию с уклоном в математику. Многие используют этот сайт для подготовки к реальным собеседованиям.

9. **Ультрабонус!** Напиши программу, которая принимает на вход из терминала десятичное число, и выводит на экран то же число, но в шестнадцатеричной системе счисления. Для написания программы используй шаблон (обязательно):
```cpp
#include <iostream>

std::string dec_to_hex(int a)
{
	// ...
}

int main()
{
	int a; std::cin >> a;
	std::cout << dec_to_hex(a) << std::endl;
}
```

[Решения](https://github.com/dj1vs/cpp-course/tree/main/code/basics/bare_minimum)