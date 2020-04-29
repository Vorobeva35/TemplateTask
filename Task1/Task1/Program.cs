using System;

namespace Task1
{
    public class MyStack<T>
    {
        private T[] items; // элементы стека
        private int count;  // количество элементов
        const int n = 10;   // количество элементов в стеке по умолчанию
        public MyStack() //конструктор по умолчанию
        {
            items = new T[n]; //создаем массив на n элементов типа T
        }
        public MyStack(int length) //конструктор с параметром (максимальный размер стека)
        {
            items = new T[length]; //создаем массив на length элементов типа T
        }

        // пуст ли стек
        public bool IsEmpty ()
        {
            return count == 0; 
        }
        // размер стека
        public int Count ()
        {
            return count; 
        }
        // добвление элемента
        public void Push(T item)
        {
            // если стек заполнен, выводим ошибку
            if (count == items.Length)
            {
                Console.WriteLine("Ошибка добавления! Переполнение стека");
                return; //завершаем метод
            }
            items[count++] = item; //добавляем в конец массива элемент и ув. размер стека на 1
        }
        // извлечение элемента
        public T Pop()
        {
            // если стек пуст, выводим ошибку
            if (IsEmpty())
            {
                Console.Write("Ошибка извлечения! Стек пуст!");
                return default(T); //возвращаем значение по умолчанию для данного типа T
            }
  
            T item = items[--count]; //получаем элемент на вершине стека и уменьшаем размер стека на 1
            items[count] = default(T); // сбрасываем элемент на значение по умолчанию
            return item; //возвращаем извлеченный элемент 
        }

        public MyStack<T> Merge(MyStack<T> stack) //метод слияния стеков в новый стек
        {
            MyStack<T> newStack = new MyStack<T>(Count() + stack.Count()); //создаем новый стек на размер 2 стеков

            while (!stack.IsEmpty()) //пока второй стек для слияния не пустой 
            {
                newStack.Push(stack.Pop()); //добавляем верхний элемент из второго стека на вершину 
            }
            while (!IsEmpty()) //пока первый стек для слияния не пустой 
            {
                newStack.Push(Pop()); //добавляем верхний элемент из первого стека на вершину 
            }
            return newStack; //возвращаем новый стек
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Стек целых чисел:");
            MyStack<int> stack1 = new MyStack<int>(5);
            for (int i=1;i<=5;++i)
                stack1.Push(i);
            stack1.Push(6);
            Console.Write("Извлечение стека: ");
            for (int i = 1; i <= 6; ++i)
                Console.Write(stack1.Pop()+" ");

            Console.WriteLine("\n\nСтек строк:");
            MyStack<string> stack2 = new MyStack<string>(5);
            for (int i = 1; i <= 5; ++i)
                stack2.Push("Слово"+ i);
            stack2.Push("Еще одно слово");
            Console.Write("Извлечение стека: ");
            for (int i = 1; i <= 6; ++i)
                Console.Write(stack2.Pop() + " ");

            MyStack<double> stack3 = new MyStack<double>(3);
            stack3.Push(1.2);
            stack3.Push(5.64);
            stack3.Push(2.38);

            MyStack<double> stack4 = new MyStack<double>(2);
            stack4.Push(5.236);
            stack4.Push(4.12);
     

            Console.WriteLine("\n\nОбъединенный стек вещественных чисел: ");
            MyStack<double> stack5 = stack4.Merge(stack3);
            while (!stack5.IsEmpty())
                Console.Write(stack5.Pop() + " ");

            Console.ReadKey();
        }
    }
}
