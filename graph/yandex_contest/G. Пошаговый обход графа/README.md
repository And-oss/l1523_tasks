G. Пошаговый обход графа

Пошаговым обходом графа из вершины v назовём последовательность вершин u1,   u2,   …,   ur такую, что:

u1 = ur = v,

Каждая вершина графа, достижимая из v, встречается в ней хотя бы один раз, и

Между любыми двумя соседними вершинами последовательности в графе существует ребро. Задан связный неориентированный граф и его вершина v. Выведите любой пошаговый обход этого графа.

Формат ввода\
В первой строке входного файла заданы числа N, M и v через пробел — количество вершин и рёбер в графе и начальная вершина обхода (, , ). Следующие M строк содержат по два числа ui и vi через пробел (); каждая такая строка означает, что в графе существует ребро между вершинами ui и vi.

Формат вывода\
В первой строке входного файла выведите число r — количество вершин в найденном пошаговом обходе (; гарантируется, что обход, удовлетворяющий этим ограничениям, существует). Во второй строке выведите сами числа u1,   u2,   …,   ur через пробел.


Пример 1\
Ввод 

3 2 1\
1 2\
2 3\
Вывод\
5\
1 2 3 2 1