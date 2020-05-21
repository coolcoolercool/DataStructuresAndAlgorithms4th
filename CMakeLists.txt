cmake_minimum_required(VERSION 3.14)
project(DataStructuresAndAlgorithms4th)


set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructuresAndAlgorithms4th main.cpp
        SourceCode/3th_LinkedList/intSLList/intSLList.h
        SourceCode/3th_LinkedList/intSLList/intSLList.cpp
        SourceCode/3th_LinkedList/genDLList/genDLLIst.h
        SourceCode/3th_LinkedList/genSkipList/genSkipList.h
        SourceCode/4th_StackAndQueue/genStack/genStack.h
        SourceCode/4th_StackAndQueue/genListStack/genListStack.h
        SourceCode/4th_StackAndQueue/genArrayQueue/genArrayQueue.h
        SourceCode/4th_StackAndQueue/genQueue/genQueue.h
        TestCode/priority_queue_test/priority_queue_1.cpp
        TestCode/priority_queue_test/priority_queue_2.cpp
        TestCode/priority_queue_test/priority_queue_3.cpp
        TestCode/priority_queue_test/priority_queue_4.cpp
        SourceCode/5th_Recursive/Fibonacci/Fibonacci.cpp SourceCode/5th_Recursive/EightQueue/ChessBoard.cpp SourceCode/6th_BinaryTree/BST/genBST.h TestCode/TravelBinaryTree/PreOrder/preOrder.cpp TestCode/TravelBinaryTree/inOrder/inOrder.cpp TestCode/TravelBinaryTree/PostOrder/postOrder.cpp SourceCode/6th_BinaryTree/ThreadTree/genThread.h SourceCode/9th_Sort/InsertSort/InsertSort.cpp SourceCode/9th_Sort/SelectSort/SelectSort.cpp SourceCode/9th_Sort/ToolClass.h SourceCode/9th_Sort/BubbleSort/BubbleSort.cpp SourceCode/9th_Sort/BubbleSort/CombSort/CombSort.cpp SourceCode/9th_Sort/ShellSort/ShellSort.cpp SourceCode/9th_Sort/HeapSort/HeapSort.cpp SourceCode/9th_Sort/QuickSort/QuickSort.cpp)
