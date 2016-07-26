-- 1:

rev :: [a] -> [a]
rev [] = []
rev (x:xs) = rev xs ++ [x]




-- 2:


rpt :: Int -> a -> [a]
rpt 0 _ = []
rpt n x = x : rpt (n-1) x


-- 3:

unwrds :: [String] -> String
unwrds [] = ""
unwrds [x] = x
unwrds (x:xs) = x ++ ' ' : unwrds xs


-- 4:


subSeq :: (Ord a, Enum a) => a -> a -> [a]
--subSeq x y = [x .. y]
subSeq x y
 | x > y = []
 | succ x == y = [x,y]
 | otherwise = x : subSeq (succ x) y
 

-- 5:

innerProduct :: Num a =>[a] -> [a] -> a
innerProduct [] _ = 0
innerProduct _ [] = 0
innerProduct [x] [y] = x * y
innerProduct (x:xs) (y:ys) = x * y + innerProduct xs ys



-- 6:

merge :: Ord a => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge [x] [y] = if x < y then [x,y] else [y,x]
merge (x:xs) (y:ys) = if x < y then x : merge xs (y:ys) else y : merge (x:xs) ys