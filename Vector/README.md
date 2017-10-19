# Implementation of mutable Vector in C (mutable array with automatic resizing):

    -  size() - number of items
    -  capacity() - number of maximum items vector can hold
    -  isEmpty() - returns true if vector is empty
    -  vectorGet(index) - returns item at index, exit with 1 otherwise
    -  push(item) - pushes item to the tail of vector
    -  insertElem(position, value) - inserts item at index, shifts that index's value and trailing elements to the right
    -  prepend(item) - can use insert above at index 0
    -  pop() - remove from end, return value
    -  deleteElem(index) - delete item at index, shifting all trailing elements left
    -  removeElem(value) - looks for value and removes index holding it (even if in multiple places)
    -  findElem(value) - looks for value and returns first index with that value, -1 if not found (for implementation)
    -  findElem2(value) - looks for value and returns first index with that value, -1 if not found (while implementation)
    -  resize(new_capacity) // private function
        - when you reach capacity, resize to double the size
        - when popping an item, if size is 1/4 of capacity, resize to half
-  Time
    - O(1) to add/remove at end (amortized for allocations for more space), index, or update
    - O(n) to insert/remove elsewhere
-  Space
    - contiguous in memory, so proximity helps performance
    - space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)

В отличие от динамических массивов существуют статические массивы и массивы переменной длины. Размер статического массива определяется на момент компиляции программы. Размер массива переменной длины определяется во время выполнения программы. 
Отличием динамического массива от массива переменной длины является автоматическое изменение размеров, что не трудно реализуется в случаях его отсутствия, поэтому часто не различают массивы переменной длины с динамическими массивами.

[WiKi](https://en.wikipedia.org/wiki/Dynamic_array)
