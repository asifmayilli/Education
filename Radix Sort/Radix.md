# Radix Sort

Применение поразрядной сортировки имеет одно ограничение: перед началом сортировки необходимо знать
`length` - максимальное количество разрядов в сортируемых величинах (например, при сортировке слов необходимо знать максимальное количество букв в слове),
`base` - количество возможных значений одного разряда (при сортировке слов - количество букв в алфавите).
Количество проходов равно числу `length`.

### Пошаговое описание алгоритма

Допустим у нас есть числа: 39, 47, 54, 59, 34, 41, 32 (length = 2, range = 10)

1. Создаем пустые списки, количество которых равно числу range.

2. Распределяем исходные числа по этим спискам в зависимости от величины младшего разряда (по возрастанию).
    
    Для нашего примера получим:
        
        41
        32
        54, 34
        47
        59, 39

    (Вообще надо создать 10 списков, но некоторые из них оказались пустыми)

3. Собираем числа в той последовательности, в которой они находятся после распределения по спискам.

    Получим:
    
        41, 32, 54, 34, 47, 59, 39

4. Повторяем пункты 2 и 3 для всех более старших разрядов поочередно.

    Для двузначных чисел мы должны сделать еще один проход. Распределение по спискам будет выглядеть так:
            
        32, 34, 39
        41, 47
        54, 59
    Объединив числа в последовательность, получим отсортированный массив.

# Реализация на C#

В качестве примера приведем реализацию функции поразрядной сортировки для целых чисел любой длины. Однако максимальная длина числа должна быть известна заранее. Она передается функции сортировки в качестве аргумента.

Класс RadixSorting, содержащий функцию быстрой сортировки, и класс Test для тестирования этой функции:

```
class RadixSorting {
   public static void sorting(int[] arr, int range, int length) {
      ArrayList[] lists = new ArrayList[range];
      for(int i = 0; i < range; ++i)
         lists[i] = new ArrayList();
			  
      for(int step = 0; step < length; ++step) {
         //распределение по спискам
         for(int i = 0; i < arr.Length; ++i) {
            int temp = (arr[i] % (int)Math.Pow(range, step + 1)) /
                                          (int)Math.Pow(range, step);
            lists[temp].Add(arr[i]);
         }
         //сборка
         int k = 0;
         for(int i = 0; i < range; ++i) {
            for(int j = 0; j < lists[i].Count; ++j) {
               arr[k++] = (int)lists[i][j];
            }
         }
         for(int i = 0; i < range; ++i)
            lists[i].Clear();
      }
   }
}
class Test {
   static void Main(string[] args) {
      int[] arr = new int[100];
      //fill the array with random numbers
      Random rd = new Random();
      for(int i = 0; i < arr.Length; ++i) {
         arr[i] = rd.Next(0, 100);
      }
      System.Console.WriteLine("The array before sorting:");
      foreach(double x in arr) {
         System.Console.Write(x + " ");
      }
      RadixSorting.sorting(arr, 10, 2);
      System.Console.WriteLine("\n\nThe array after sorting:");
      foreach(double x in arr) {
         System.Console.Write(x + " ");
      }
      System.Console.WriteLine("\n\nPress the <Enter> key");
      System.Console.ReadLine();
   }
}
```