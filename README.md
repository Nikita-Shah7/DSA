# BinaryExpressionTree.cpp

```
Enter the postfix expression : 
NOTE :: Enter '0' to exit.
a b - m n ^ o p + * + s r s ^ / t * - z +
Prefix Expression :: + - + - a b * ^ m n + o p * / s ^ r s t z 
Infix Expression :: a - b + m ^ n * o + p - s / r ^ s * t + z 
Postfix Expression :: a b - m n ^ o p + * + s r s ^ / t * - z +
```

# HashMap.cpp

``` 
***** HASH TABLE DATA STRUCTURE MENU DRIVEN *****
0: Display Hash Table
2: Insert a key-value pair in Hash Table.
3: Delete a key-value pair in Hash Table.
4: Search for a key-value pair in Hash Table.
-1: Quit
Enter your choice : 2
Enter the data to be inserted : 
Key : nik
Value : 12
Enter your choice : 2
Enter the data to be inserted : 
Key : mok  
Value : 23
Enter your choice : 2
Enter the data to be inserted : 
Key : rohan
Value : 11
Enter your choice : 2    
Enter the data to be inserted :
Key : mihir
Value : 44
Enter your choice : 2   
Enter the data to be inserted :
Key : keni
Value : 89
Enter your choice : 2    
Enter the data to be inserted :
Key : mokshi
Value : 24
Enter your choice : 0
Index     Key-Value Pairs
  0 --->  rohan->11 ; mihir->44 ;
Enter the key : nik
Data found.
nik->12
Enter your choice : 4
Enter the key : nikki
No relevant data found!
Enter your choice : 3
Enter the key : rohan
Enter your choice : 0
Index     Key-Value Pairs
  0 --->  mihir->44 ;
  1 --->  mokshi->24 ;
  2 --->
  3 --->
  4 --->
  5 --->  nik->12 ; mok->23 ;
  6 --->  keni->89 ;
Enter your choice : -1
***** THANK YOU *****
```

# InfixToPostfix
```
1. Create a stack.
2. Print the operands as they arrive.
3. If the stack is empty, then push the incoming operator 
    onto the stack.
4. If you encounter '(', then push the it onto the stack.
5. If you encounter ')', pop the stack and print the 
    operators until '(' is found on the top of stack.
6. If incoming operator has higher precedence than that 
    on the top of stack, then simply push the operator 
    onto stack.
7. If incoming operator has lower precedence than that 
    on the top of stack, then pop out from stack and 
    print it. Then test the condition for new top 
    of the stack.
8. If incoming operator has same precedence as that 
    of the top of stack, then use associativity rule.
        a. if incoming operator has L to R associativity, 
           then pop and print the top of the stack and 
           push the incoming operator onto the stack.
        b. if incoming operator has R to L associativity,
           then simply push the incoming operator.
9. At the end of expression, pop and print all operators 
    in the stack.
```

# UnidirectedGraph.cpp
```
 index ---> (index,weight)
 1 ---> (2,7) -> (3,8)
 2 ---> (1,7) -> (3,3) -> (4,6)
 3 ---> (1,8) -> (2,3) -> (4,4) -> (5,3)
 4 ---> (2,6) -> (3,4) -> (5,2) -> (6,5)
 5 ---> (3,3) -> (4,2) -> (6,2)
 6 ---> (4,5) -> (5,2)

           6
      2 --------- 4
   7 /|         / |\ 5
   / |3      /   | \
   1  |   4 /     |  6
    \ |   /     2 | / 2
   8 \| /         |/
      3 --------- 5
           3

Enter number of verties : 6
Enter number of edges : 9

Enter Details of all vertices : 
Vertex 0 :: 
Data : 1
Degree of this vertex : 2

Vertex 1 :: 
Data : 2
Degree of this vertex : 3

Vertex 2 :: 
Data : 3
Degree of this vertex : 4

Vertex 3 ::
Data : 4
Degree of this vertex : 4

Vertex 4 ::
Data : 5
Degree of this vertex : 3

Vertex 5 ::
Data : 6
Degree of this vertex : 2


Details of all Vertices (index, data, degree) ::
(0,1,2)  (1,2,3)  (2,3,4)  (3,4,4)  (4,5,3)  (5,6,2)

Enter details for Vertex 0 ::
        Adjacent vertex 1 :
        Data : 2
        Weight of the edge connecting this vertex to vertex 1 : 7

        Adjacent vertex 2 :
        Data : 3
        Weight of the edge connecting this vertex to vertex 2 : 8

Enter details for Vertex 1 ::
        Adjacent vertex 1 :
        Data : 1
        Weight of the edge connecting this vertex to vertex 1 : 7

        Adjacent vertex 2 :
        Data : 3
        Weight of the edge connecting this vertex to vertex 2 : 3

        Adjacent vertex 3 :
        Data : 4
        Weight of the edge connecting this vertex to vertex 3 : 6

Enter details for Vertex 2 ::
        Adjacent vertex 1 :
        Data : 1
        Weight of the edge connecting this vertex to vertex 1 : 8

        Adjacent vertex 2 :
        Data : 2
        Weight of the edge connecting this vertex to vertex 2 : 3

        Adjacent vertex 3 :
        Data : 4
        Weight of the edge connecting this vertex to vertex 3 : 4

        Adjacent vertex 4 :
        Data : 5
        Weight of the edge connecting this vertex to vertex 4 : 3

Enter details for Vertex 3 ::
        Adjacent vertex 1 :
        Data : 2
        Weight of the edge connecting this vertex to vertex 1 : 6

        Adjacent vertex 2 :
        Data : 3
        Weight of the edge connecting this vertex to vertex 2 : 4

        Adjacent vertex 3 :
        Data : 5
        Weight of the edge connecting this vertex to vertex 3 : 2

        Adjacent vertex 4 :
        Data : 6
        Weight of the edge connecting this vertex to vertex 4 : 5

Enter details for Vertex 4 ::
        Adjacent vertex 1 :
        Data : 3
        Weight of the edge connecting this vertex to vertex 1 : 3

        Adjacent vertex 2 :
        Data : 4
        Weight of the edge connecting this vertex to vertex 2 : 2

        Adjacent vertex 3 :
        Data : 6
        Weight of the edge connecting this vertex to vertex 3 : 2

Enter details for Vertex 5 ::
        Adjacent vertex 1 :
        Data : 4
        Weight of the edge connecting this vertex to vertex 1 : 5

        Adjacent vertex 2 :
        Data : 5
        Weight of the edge connecting this vertex to vertex 2 : 2

 (index, data)
 (0,1) ----0----> (0,1)
 (0,1) ----7----> (1,2)
 (0,1) ----8----> (2,3)
 (1,2) ----0----> (1,2)
 (1,2) ----7----> (0,1)
 (3,4) ----6----> (1,2)
 (3,4) ----4----> (2,3)
 (3,4) ----2----> (4,5)
 (3,4) ----5----> (5,6)
 (4,5) ----0----> (4,5)
 (4,5) ----3----> (2,3)
 (4,5) ----2----> (3,4)
 (4,5) ----2----> (5,6)
 (5,6) ----0----> (5,6)
 (5,6) ----5----> (3,4)
 (5,6) ----2----> (4,5)
BFS :: (0,1) (1,2) (2,3) (3,4) (4,5) (5,6)
DFS :: (5,6) (4,5) (3,4) (2,3) (1,2) (0,1)
```


# ViewingBinaryTree.cpp
```
-----------------------------------------------------------------
*****VIEW AND TRAVERSE A BINARY TREE FROM VARIOUS ANGLES*****
-----------------------------------------------------------------

----------------------------------------
        ***BINARY TREE 1***
----------------------------------------
PreOrder :: 1 2 4 5 3 6 7
InOrder :: 4 2 5 1 6 3 7
PostOrder :: 4 5 2 6 7 3 1
LevelOrder ::
1 -> 1
2 -> 2 3
3 -> 4 5 6 7
VerticalOrder ::
4
2
1 5 6
3
7
TopView :: 4 2 1 3 7
BottomView :: 4 2 6 3 7
LeftView :: 1 2 4
RightView :: 1 3 7
ZigZagLevelOrderTraversal :: 1 3 2 4 5 6 7 
ZigZagDiagonalTraversal ::
1 3 7
2 5 6
4
BoundaryTraversal ::1 2 4 5 6 7 3
Size of Binary Tree : 7
Height of Binary Tree : 2
----------------------------------------

----------------------------------------
        ***BINARY TREE 2***
----------------------------------------
PreOrder :: 1 2 4 5 6 3
InOrder :: 2 4 5 6 1 3
PostOrder :: 6 5 4 2 3 1
LevelOrder ::
1 -> 1
2 -> 2 3
3 -> 4
4 -> 5
5 -> 6
VerticalOrder ::
2
1 4
3 5
6
TopView :: 2 1 3 6
BottomView :: 2 4 5 6
LeftView :: 1 2 4 5 6
RightView :: 1 3 4 5 6
ZigZagLevelOrderTraversal :: 1 3 2 4 5 6 
ZigZagDiagonalTraversal ::
1 3
2 4 5 6
BoundaryTraversal ::1 2 6 3
Size of Binary Tree : 6
Height of Binary Tree : 4
----------------------------------------

----------------------------------------
        ***BINARY TREE 3***
----------------------------------------
PreOrder :: 1 2 4 5 8 10 9 11 3 6 7
InOrder :: 4 2 10 8 5 9 11 1 6 3 7
PostOrder :: 4 10 8 11 9 5 2 6 7 3 1
LevelOrder ::
1 -> 1
2 -> 2 3
1 3 7
2 5 9 11 6
4 8
10
BoundaryTraversal ::1 2 4 10 11 6 7 3
Size of Binary Tree : 11
Height of Binary Tree : 4
----------------------------------------
```
