using System;

namespace Task2_Light_
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTree<string> binaryTree = new BinaryTree<string>(); //созаем дерево из строк

            //добавляем элементы в дерево
            binaryTree.Add("F");
            binaryTree.Add("B");
            binaryTree.Add("G");
            binaryTree.Add("A");
            binaryTree.Add("D");
            binaryTree.Add("I");
            binaryTree.Add("C");
            binaryTree.Add("E");
            binaryTree.Add("H");

            Console.WriteLine("Поиск вершин в дереве:");

            Node<string> node = binaryTree.Find("K");
            if (node != null)
                Console.WriteLine("Вершина К найдена");
            else
                Console.WriteLine("Вершина К не найдена");
            node = binaryTree.Find("C");
            if (node != null)
                Console.WriteLine("Вершина C найдена");
            else
                Console.WriteLine("Вершина C не найдена");

            Console.WriteLine("\nОбходы дерева:");
            Console.WriteLine("Прямой обход дерева:");
            binaryTree.TraversePreOrder(binaryTree.Root);
            Console.WriteLine();

            Console.WriteLine("Центрированный обход дерева:");
            binaryTree.TraverseInOrder(binaryTree.Root);
            Console.WriteLine();

            Console.WriteLine("Обратный обход дерева: ");
            binaryTree.TraversePostOrder(binaryTree.Root);
            Console.WriteLine();

            Console.WriteLine("Вывод списка листьев");
            binaryTree.PrintLeaf();
            Console.WriteLine();

            binaryTree.Remove("D");
            binaryTree.Remove("H");

            Console.WriteLine("Центрированный обход после операции удаления:");
            binaryTree.TraverseInOrder(binaryTree.Root);
            Console.WriteLine();
            Console.WriteLine("Вывод списка листьев после операции удаления:");
            binaryTree.PrintLeaf();
            Console.WriteLine();

            Console.ReadKey();
        }
    }
}
