

















































two = 2

pie = 3.14159

name = "haskell"


fullname = forename ++ surname
forename = "Haskell "
surname  = "Curry"
namelen  = length fullname




unknown  = unknown
infinity = infinity + 1
insanity = unknown * infinity

one = two
two2 = one

sleep = "sheep" ++ sleep

w = length sleep
x = length [sleep]
y = length [insanity]
z = length [one,two]











addOne :: Int -> Int
addOne x = x+1

timesTwo :: Int -> Int
timesTwo x = x * 2

doublePlusOne :: Int -> Int
doublePlusOne x = addOne (timesTwo x)

largerOf2 :: Int -> Int -> Int
largerOf2 x y = if x > y then x else y

largerOf3 :: Int -> Int -> Int -> Int
largerOf3 a b c = largerOf2 a (largerOf2 b c)

sumTo :: Int -> Int
sumTo n = sum [1..n]

countWords :: String -> Int
countWords str = length (words str)








double x    = x + x

quadruple x = double (double x)

factorial n = product [1..n]

average ns  = sum ns `div` length ns

average' fs = sum fs / fromIntegral(length fs)




























n :: Int
n = a `div` length xs
        where a  = 10
              xs = [1,2,3,4,5]
              

last2 :: [a] -> a
last2 []     = error "empty list"
last2 [x]    = x
last2 (x:xs) = last2 xs

last3 :: (Eq a) => [a] -> a
last3 xs | xs == []       = error "empty list"
         | length xs >  1 = last3 (tail xs)
         | length xs == 1 = head xs






init2 :: [a] -> [a]
init2 []       = error "empty list"
init2 [x]      = []
init2 (x:xs)   = x : init2 xs

init3 :: (Eq a) => [a] -> [a]
init3 xs | xs == []        = error "empty list"  
         | length xs == 1  = []
         | otherwise       = head xs : init3 (tail xs)