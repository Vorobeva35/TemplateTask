using System;

namespace Task2_Light_
{
    class Node<T> //класс, который описывает вершину дерева
    {
        public Node<T> LeftNode { get; set; } //левое поддерево
        public Node<T> RightNode { get; set; } //правое поддерево
        public T Data { get; set; } //данные
    }
    class BinaryTree<T> where T : IComparable //generic-класс бинарного дерева
    {
        public Node<T> Root { get; set; } //вершина дерева 

        public bool Add(T value) //метод добавления новой вершины в дерево
        {
            Node<T> before = null, after = this.Root;

            while (after != null)                   //пока не найдем свободное место в дереве для вставки 
            {
                before = after;
                if (value.CompareTo(before.Data) < 0) //если новая вершина меньше  текущей вершины
                    after = after.LeftNode;           //идем в левое поддерево
                else if (value.CompareTo(before.Data) > 0) //если новая вершина больше текущей вершины
                    after = after.RightNode;          //идем в правое поддерево
                else //иначе
                {
                    //данное значение уже есть в дереве 
                    return false;
                }
            }

            Node<T> newNode = new Node<T>(); //создаем новую вершину
            newNode.Data = value; //присваиваем значение 

            if (this.Root == null)//если дерево пустое 
                this.Root = newNode; //новая вершина становится корнем дерева 
            else //иначе
            {
                if (value.CompareTo(before.Data) < 0) //если новое значение меньше значения его родителя 
                    before.LeftNode = newNode; //новая вершина будет левым поддеревом 
                else //иначе
                    before.RightNode = newNode; //новая вершина будет правым поддеревом 
            }

            return true; //новая вершина успешно вставлена 
        }


        public void Remove(T value) //функция-помощник для удаления вершины со значением value
        {
            Remove(this.Root, value); //вызываем рекурсивную функцию удаления вершины 
        }

        private Node<T> Remove(Node<T> parent, T key) //рекурсивная функция удаления вершины 
        {
            if (parent == null) return parent; //если родитель пустой, завершаем метод

            if (key.CompareTo(parent.Data) < 0) //если удаляемое значение меньше текущей вершины
                parent.LeftNode = Remove(parent.LeftNode, key); //вызываем рекурсивную функцию для левого поддерева 
            else if (key.CompareTo(parent.Data) > 0) //если удаляемое значение больше текущей вершины
                parent.RightNode = Remove(parent.RightNode, key); //вызываем рекурсивную функцию для правого поддерева 
            else //иначе, если найдена вершина для удаления 
            {
                //если текущая вершина не имеет детей или только одно поддерево
                if (parent.LeftNode == null)  //если эта вершина не имеет левого поддерева 
                    return parent.RightNode;  //возвращаем правое поддерево 
                else if (parent.RightNode == null) //иначе, если эта вершина не имеет правого поддерева 
                    return parent.LeftNode;   //возвращаем левое поддерево 

                //иначе, вершина имеет 2 детей, получаем минимальное значение из правого поддерева, оно станет новой вершиной
                parent.Data = MinValue(parent.RightNode);

                // удаляем перемещенную вершину
                parent.RightNode = Remove(parent.RightNode, parent.Data);
            }

            return parent;
        }

        private T MinValue(Node<T> node) //функция нахождения минимального значения в вершине и её потомках
        {
            T minv = node.Data; //минимальным становится текущая вершина 

            while (node.LeftNode != null) //если вершина имеет левое поддерево
            {
                minv = node.LeftNode.Data; //минимальным становится левое поддерево
                node = node.LeftNode; //переходим в левого поддерево
            }

            return minv; //возвращаем минимальное значение 
        }

        public void PrintLeaf() //функция-помощник для вывода всех листьев дерева 
        {
            this.PrintLeaf(this.Root); //вызываем рекурсивную функцию поиска и вывода листьев 
        }

        public void PrintLeaf(Node<T> parent) //метод вывода всех листьев дерева 
        {
            if (parent != null) //есть вершина непустая 
            {
                if (parent.LeftNode == null && parent.RightNode == null) //если вершина не имеет детей 
                {
                    Console.Write(parent.Data + " "); //выводим её значение, т.к. она и есть листом 
                    return; //завершаем метод 
                }
                PrintLeaf(parent.LeftNode); //заходим в левое поддерево
                PrintLeaf(parent.RightNode); //заходим в правое поддерево
            }
        }


        public Node<T> Find(T value) //функция-помощник для поиска вершины со значением value
        {
            return this.Find(value, this.Root); //вызываем рекурсивную функцию поиска вершины
        }

        private Node<T> Find(T value, Node<T> parent)  //рекурсивный метод поиска вершины
        {
            if (parent != null) //если вершина существует
            {
                if (value.CompareTo(parent.Data) == 0)
                    return parent; //если искомая вершина найдена 

                if (value.CompareTo(parent.Data) < 0)   //если искомая вершина меньше текущей вершины
                    return Find(value, parent.LeftNode); //заходим в левое поддерево
                else                                    //если искомая вершина больше текущей вершины
                    return Find(value, parent.RightNode); //заходим в правое поддерево
            }

            return null; //если искомая вершина не была найдена
        }

        public void TraversePreOrder(Node<T> parent) //метод прямого обхода дерева 
        {
            if (parent != null)
            {
                Console.Write(parent.Data + " ");
                TraversePreOrder(parent.LeftNode);
                TraversePreOrder(parent.RightNode);
            }
        }

        public void TraverseInOrder(Node<T> parent)  //метод центрированного обхода дерева 
        {
            if (parent != null)
            {
                TraverseInOrder(parent.LeftNode);
                Console.Write(parent.Data + " ");
                TraverseInOrder(parent.RightNode);
            }
        }

        public void TraversePostOrder(Node<T> parent) //метод обратного обхода дерева 
        {
            if (parent != null)
            {
                TraversePostOrder(parent.LeftNode);
                TraversePostOrder(parent.RightNode);
                Console.Write(parent.Data + " ");
            }
        }
    }
}

