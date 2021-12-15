## not disgusting computer architecture assignment
### to build
```source build.sh```
binary stores in `build/`
### to run
```./source_binary arg1 arg2 arg2```, где `arg1`, `arg2`, `arg3`, `...` -- 
исходные данные энергии для каждого бойца.
### task

Задача   о   Пути   Кулака.  На седых склонах Гималаев стоит древний
буддистский монастырь: Гуань-Инь-Янь. Каждый год в день сошествия на
землю   боддисатвы   Монахи   монастыря   собираются   на   совместное
празднество и показывают свое совершенствование на Пути Кулака. Всех
соревнующихся монахов разбивают на пары, победители пар бьются затем
между собой и так далее, до финального поединка. Монах который победил в
финальном бою, забирает себе на хранение статую боддисатвы. Реализовать
многопоточное   приложение,   определяющего   победителя.   В   качестве
входных   данных   используется   массив,   в   котором   хранится   количество
энергии Ци каждого монаха. При победе монах забирает энергию Ци своего
противника. Разбивка на пары перед каждым сражением осуществляется
случайным образом. Монах, оставшийся без пары, удваивает свою энергию,
отдохнув от поединка.

### Реализация

Для реализации конкрутертности я использовал функцию `fight`, результаты выполнения которой были независимы,
а также, для того чтобы разбиение по парам было честным, я проводил битвы по раундам (параллельно выполнялись бои для конкретного раунда).
Для реализации задачи не понадобились никакие примитивы синхронизации, так как, повторюсь, раунды были независимы (так как участники соревновались по парам, и не было пересечений между парами).

Кажется, использованная модель построения многопоточного приложения является сетью слияния, так как каждый раунд выполнения зависит от предыдущего.




