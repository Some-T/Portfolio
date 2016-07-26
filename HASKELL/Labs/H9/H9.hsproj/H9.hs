-- 1:

-- N/A



-- 2:


-- N/A


-- 3:

-- N/A


-- 4:


{- Chapter 7 Questions -}

-- map f (filter p xs)

all :: (a -> Bool) -> [a] -> Bool
all p  =  and . map p
-- or
-- all _ []        =  True
-- all p (x:xs)    =  p x && all p xs

any :: (a -> Bool) -> [a] -> Bool
any p =  or . map p
-- or
-- any  _ []   = False
-- any p (x:xs)    = p x || any p xs

takeWhile :: (a -> Bool) -> [a] -> [a]
takeWhile _ [] = []
takeWhile p (x:xs)
--            | p x =  x : takeWhile p xs
            | otherwise = []

dropWhile  :: (a -> Bool) -> [a] -> [a]
dropWhile _ [] = []
dropWhile p (x:xs)
--            | p x =  dropWhile p xs
            | otherwise = xs

-- map f = foldr (\x xs -> f x : xs) []
-- filter p = foldr (\x xs -> if p x then x : xs else xs) []

--dec2int :: [Int] -> Int
dec2Int = foldl (\x y -> 10 * x + y) 0

-- sumsqreven = compose [sum, map (^2), filter even]
-- The functions don't have the same type signatures.
-- sum :: [Int] -> Int
-- map (^2) :: [Int] -> [Int]
-- filter even :: [Int] -> [Int]