# Первая программа четвёртой лекции

Сначала программа получает сигнал от пользователя и обрабатывает его.
В шестой строчке задаётся глобальная переменная-счётчик counter. Также в программе присутствуют две обрабатывающие функции - handler1(8-14 строчки) и handler2 (16-20 строчки). Они принимают агрумент типа int.
Handler1 увеличивает счётчик на 1 и отправляет сигнал дочернему.
Обработка выглядит следующим образом:
Программа привязывает первую функцию обработки к текущему процессу. Далее если процесс окажется дочерним, сигнал будет обрабатывать функция handler2.

## Скриншот
![4](4.png)

