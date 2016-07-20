-- 1:

add:: Int -> Int -> Int -> Int
add x y z = x + y + z


--For the below I typed in GHCi terminal, stuff like append:: _ -> _ and swap:: _ -> _ etc...

-- a:


append:: [a] -> [a] -> [a]
append x y = x ++ y


-- b:

swap :: (a, b) -> (b, a)
swap (x,y) = (y,x)


-- c:

block:: (a,a) -> [a]
block (x,y) = [x,y]

-- d:

velocity:: Fractional a1 => a1 -> a1 -> a1 -> a1 
velocity u a t = u + 0.5 * a * t^2


-- e:

hash:: Integral a => a -> a
hash key = key `mod` 97


-- f:

smallest:: Ord a => a -> a -> a -> a
smallest x y z = minimum [x,y,z]


-- g:

largest:: Ord a => a -> a -> a -> a
largest x y z = x `max` y `max` z


-- h:

bigSmall:: Ord t => t -> t -> t -> (t, t)
bigSmall x y z = (largest x y z, smallest x y z)


-- i:
upDown :: (Ord t1, Ord t) => t -> t -> t1 -> t1 -> (t, t1)
upDown a b c d = (a `max` b, c `min` d)

-- j:
bracket :: [Char] -> [Char]
bracket xs = "(" ++ xs ++ ")"


-- k:

identity:: t -> t
identity x = x


-- l:

twice :: t -> (t, t)
twice x = (x,x)


-- m:

constant :: t -> t1 -> t
constant a b = a


-- n:

apply :: (t -> t1) -> t -> t1
apply f x = f x


-- o:

zeroSum :: Num t => (t -> t1) -> t -> t1
zeroSum f x = f (x + 0)


-- p:

zeroSum' :: (Num t, Num a) => (t -> a) -> t -> a
zeroSum' f x = f (x + 0) + 0




-- 3:


-- a:
funcAdd (a,b,c,d) = a + b + c + d



-- b:


aString x y = x

aString_ x y = if length x > length y then x else y

-- c:

mult_ a b c = (10 * a, 10 * b, 10 * c)


-- d:

allTheSame a b = (a == b)


-- e:

-- Unknown as of yet.
