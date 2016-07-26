data Tree = Leaf Int
          | Fork Tree Int Tree
     deriving Show


t0 = Leaf 0
t1 = Fork (Fork (Leaf 1) 2 (Leaf 3)) 4 (Fork (Leaf 5) 6 (Leaf 7))
t2 = Fork (Fork (Fork (Leaf 1) 2 (Leaf 3)) 4 (Leaf 5)) 6 (Leaf 7)

{-

t1:

    4
   /   \
  2     6 
 / \   / \
1   3 5   7


t2:

      6
     / \
   4   7
   / \
  2   5 
 / \
1   3

-}

-- 1:

-- counts the leaf nodes in a tree
leaves :: Tree -> Int
leaves (Leaf n) = 1
leaves (Fork l n r) = leaves l + leaves r



-- 2:


-- returns list containing all the elements in a Tree
asList :: Tree -> [Int]
asList (Leaf n) = [n]
asList (Fork l n r) = asList l ++ [n] ++ asList r



-- 3:

-- reflects a Tree
reflect :: Tree -> Tree
reflect (Leaf n) = Leaf n
reflect (Fork l n r) = Fork (reflect r) n (reflect l) 


-- 4:

-- returns the height of a Tree
height :: Tree -> Int
height (Leaf n) = 1
height (Fork l n r) = 1 + max (height l) (height r)


-- 5:

-- maps a function over a Tree
mapTree :: (Int -> Int) -> Tree -> Tree
mapTree f (Leaf n) = Leaf (f n)
mapTree f (Fork l n r) = Fork (mapTree f l) (f n) (mapTree f r)



-- 6:

-- returns true or false depending upon whether or not the given item is contained (anywhere) in the tree
contains :: Tree -> Int -> Bool
contains (Leaf n) m = m == n
contains (Fork l n r) m = m == n || contains l m || contains r m