# Лямбда выражения [в разработке]

## Перевод в другую систему счисления
Представим, что строительная компания поставляет некие детали в разные страны.
И в одной из программ в этой компании требуется ей перевести длины деталей из одной системы счисления в другую.

Взгляните на следующий пример кода:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

float meters_to_feet(float meters)
{
    return meters * 3.28084;
}

float meters_to_sm(float meters)
{
    return meters * 100;
}

float meters_to_inches(float meters)
{
    return meters * 39.3701;
}

int main()
{
    std::vector <float> len_m = {1.84, 2.05, 2.09, 1.64};

    std::vector <float> len_f(len_m.size());
    std::vector <float> len_s(len_m.size());
    std::vector <float> len_i(len_m.size());

    std::transform(len_m.begin(), len_m.end(), len_f.begin(), meters_to_feet);
    std::transform(len_m.begin(), len_m.end(), len_s.begin(), meters_to_sm);
    std::transform(len_m.begin(), len_m.end(), len_i.begin(), meters_to_inches);
}
```
Здесь **без использования лямбда-выражений** производится перевод массива длин деталей в метрах в массивы длин деталей в футах, сантиметрах и дюймах.
С помощью метода [[std transform|std::transform]] мы обрабатываем начальный массив заданными функциями и записываем результаты работы функции по каждому элементу начального массива в новый массив.

Как итог, мы получили громоздкий и тяжело читаемый код, с большим количеством повторяющихся однотипных функций. Ради одной функции, которая просто умножает `float` на коэффициент, приходится писать очень много лишнего кода.

## На помощь приходят лямбда-выражения
Взглянем теперь как бы выглядел наш код с использованием лямбда-выражений:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_vector(const std::vector<T> &vec)
{
    for (const auto &x : vec)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector <float> len_m = {1.84, 2.05, 2.09, 1.64};

    std::vector <float> len_f(len_m.size());
    std::vector <float> len_s(len_m.size());
    std::vector <float> len_i(len_m.size());

	std::transform(len_m.begin(), len_m.end(), len_f.begin(),
	[](float m) {return m * 3.28084;});
	
    std::transform(len_m.begin(), len_m.end(), len_s.begin(),
    [](float m) {return m * 100;});
    
    std::transform(len_m.begin(), len_m.end(), len_i.begin(),
    [](float m) {return m * 39.3701;});

    print_vector(len_f);
    print_vector(len_s);
    print_vector(len_i);
}
```
Нужные нам функции мы "определили" прямо в функции `main`! Код стал намного более читаемым, мы избавились от лишних и ненужных повторений.
## Применяем для примера capture list
В нашем примере, все три используемых лямбды отличаются только коэффициентом, на который домножается m. Почему бы не вынести этот коэффициент как отдельную внешнюю переменную? Так можно достаточно стремительно расширить функционал программы и сделать её ещё более простой.
Сделать это нам помогает capture-list лямбда выражения:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_vector(const std::vector<T> &vec)
{
    for (const auto &x : vec)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector <float> len_m = {1.84, 2.05, 2.09, 1.64};

    std::vector <float> len_f(len_m.size());
    std::vector <float> len_s(len_m.size());
    std::vector <float> len_i(len_m.size());

    std::vector<std::pair<std::vector<float>, float>> coeff_to_vec 
        = {{len_f, 3.28084}, {len_s, 100}, {len_i, 39.3701}};

    for (auto&& [vec, coeff] : coeff_to_vec)
    {
        std::transform
        (
	        len_m.begin(),
	        len_m.end(),
	        vec.begin(),
	        [&coeff](float m) {return m * coeff;}
	    );
        print_vector(vec);
    }
}
```
В фигурных скобках для лямбда-выражения мы указываем, что лямбда-функция должна захватывать локальную переменную `coeff` и использовать её в своих вычислениях.
Как видим, код стал ещё понятнее и проще.
Ну а теперь поговорим более "официально" о том, что такое лямбда-выражение.
## Теория
> [!quote] cppreference.com
> Constructs a [closure](https://en.wikipedia.org/wiki/Closure_(computer_science) "enwiki:Closure (computer science)"): an unnamed function object capable of capturing variables in scope.

Синтаксис лямбда-выражения:
```cpp
[](){}
```
- В квадратных скобках указываются переменные для захвата
- В круглых скобках указываются аргументы лямбда-функции
- В фигурных скобках указывается само тело функции.
Что значит "захватить" переменные? Это значит, что лямбда может в теле функции использовать переменные из локальной области видимости, если задать, что мы действительно хотим их в ней использовать.
Захватить переменные можно несколькими способами:
- `[=]` - захват лямбдлй всех локальных переменных  по значению
- `[&]` - то же самое, но только по ссылке
- `[this]` - захват лямбдой текущего объекта класса (для методов класса). Так можно получить внутри лямбды доступ ко всем методам и полям класса
- `[value1, &value2]` - захват лямбдой конкретных переменных по значению/по ссылке (соответственно)
Внутри лямбды можно обращаться к глобальным переменным/статическим переменным какого-либо класса/`constexpr`-переменным.
## Дополнительные фишки
Можно явно задать тип возвращаемого лямбдой значения:
```cpp
[](int a) -> int {return a + 3};
```
Можно так же получить из лямбды указатель на функцию:
```cpp
+[](){}
```
Делается это с помощью `+` перед лямбдой.
## Использование лямбды
1. Можно объявить лямбду и сразу вызвать её:
   ```cpp
   [](){std::cout << "Hello world!\n";}();
```
2. Можно записать лямбду в локальную переменную:
   ```cpp
   auto lambda = [](){std::cout << "Hello world!\n";};
   lambda();
```
3. Поддерживается каст лямбды в указатель на функцию:
   ```cpp
   void (*f_ptr)() = lambda;
   f_ptr();
```
4. Лямбду, как и любой другой callable объект, можно "записать" в `std::function`:
   ```cpp
   std::function<void()> f = lambda;
```
5. Переменную с лямбдой нельзя перезаписывать
