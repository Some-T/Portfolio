module H6 where
  
import Data.Char(toUpper)


-- 1:

-- a:{

zoe :: (Integral a, Num a) => a -> Int


zoe x
  | x == 0 = 0
  | x `mod` 2/=0 = 1
  | otherwise = 2
  


-- b:

pal :: String -> Bool

pal xs = xs == reverse xs


-- c:
upr :: Char -> Char

upr x
    |x `elem` ['a' .. 'z'] = toUpper x
    |x `elem` ['A' .. 'Z'] = x
    | otherwise ='?'
    


-- 2:


--a:

a = map (*10) [1..10]



--b:


b = map (2^) [1..20]



--c (Use map to transform the list [1..10] by applying the following formula to each value: multiply by five, then subtract one; then double the result.):


c = map (\n -> (n * 5 - 1) * 2) [1..10]



--d (Use map to generate the reciprocals of the list [1.0 .. 20.0]. (The reciprocal of a number x is 1/x):


d = map (\n -> (1/n) ) [1.0..20.00]


--e (Use map to transform a list of ones and zeros into its complement list (i.e. zeros become ones; and ones become zeros):


e = map (\n -> 1 - n) [1,1,0,0]


--f: (Use map to remove the head character from each of a list of words):

f = map (\n -> tail n) ["hello","testing","three"]

--g: (Use map to take the first two characters from each of a list of words)


--map (take 2) ["hello","testing","three"]


g = map (drop 2) ["hello","testing","three"]


--h: (Use map to drop the first and last characters from each of a list of words)

h = map (\text -> init (drop 1 text)) ["hello","testing","three"]



-- 3:


--a:


aa = id 7

 

--b:



bb = id id 7



--c:


cc = const 4 7



--d:


dd = flip const 4 7

--e:

ee = const const id 3 5

--f:


ff = flip const 3 5

--g:


gg = const flip id const 3 id 4


--h:

hh = flip const flip const True False

--i:


ii = (\f g x -> f (g x)) (+1) (*2) 3


--j:

jj = (\f g x -> g (f x)) (+1) (*2) 3