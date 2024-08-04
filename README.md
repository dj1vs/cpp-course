# Курс по C++
Этот курс я решил создать для того, чтобы поделиться с начинающими разработчиками знаниями о:
- Языке C++ и его основных концепциях
- О базовых вещах, которые должен знать каждый программист, но о которых слишком часто не говорится в аналогичных курсах

Все статьи и все материалы публикую абсолютно бесплатно.

Тексты пишу либо полностью с нуля, либо на основе существующих докладов/книг (все источники указываю).

Курс я создаю чисто от себя для заинтересованных людей и не претендую на идеальное излагание теории и практики. Возможно, тут будут какие-то неточности. Поэтому не стоит воспринимать это как академический учебник.

Курс планирую создавать, так сказать, в режиме `rolling-release`.
То есть, непосредственно база курса, тот набор статей, который реально необходим для старта, будет основным содержанием.
Но в дополнение к нему будут периодически добавляться дополнительные статьи, заготовки и так далее.
Таким образом, в прекрасном светлом будущем, проект может вылиться в полноценный образовательный ресурс.

## Для кого этот курс
Для тех, у кого уже есть небольшой опыт в программировании (например, из школьного курса Кумира, Pascal или Python), и кто хочет освоить C++.

А также для тех, кто хочет научиться применять базовые знания по C++ на практике, например:
- написать свою игру
- создать графическое приложение
- поделиться своей программой с сообществом
- выложить свой проект на Github
- ...

## Как внести свой вклад
Если вы найдёте какую-то неточность, или у вас есть предложения по улучшению материалов, вы можете добавить issue в Github-репозитории этого проекта.

## Технологии
Весь текст пишется и редактируется в формате `markdown`-файлов в `VSCode` и `Obsidian`. Исходный код всех уроков и статей лежит в [папке src](https://github.com/dj1vs/cpp-course/tree/main/src).

Графики и схемы генерируются через блоки кода [mermaid](https://mermaid.js.org/).

Для организации markdown-статей в цельный ресурс используется [mdBook](https://github.com/rust-lang/mdBook). Пока все используемые конфигурации и плагины `mdBook` укладываются в `book.toml`.