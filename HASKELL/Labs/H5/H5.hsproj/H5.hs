

-- 1:

halve :: [a] -> ([a],[a])
halve xs = (take h xs, drop h xs)
             where h = length xs `div` 2
             



-- 2:

--split3 :: [a] -> ([a],[a][a])

split3 xs = (take n xs, take n (drop n xs), drop (n*2) xs)
             where n = length xs `div` 3
             

-- 3:

-- a:

safetailC :: [a] -> [a]

safetailC xs = if null xs then [] else tail xs


-- b:

safetailGE :: [a] -> [a]
safetailGE xs | null xs = []
              | otherwise = tail xs

-- c:

safetailPM :: [a] -> [a]
safetailPM [] = []
safetailPM (_:xs) = xs


-- 4:

second (x:xs) = head xs


-- 5:

third (x:xs) = head (tail (tail [1..]))


-- 6:

-- a:

(/\) :: Bool -> Bool -> Bool

False /\ False = False
False /\ True = True
True /\ False = True
True /\ True = True 


-- b:

(\/) :: Bool -> Bool -> Bool


b \/ c | b == c = b| otherwise = True



-- c:

(~>) :: Bool -> Bool -> Bool

False ~> False = False
False ~> True = True
True ~> False = True
True ~> True = True 



-- d:


(><) :: Bool -> Bool -> Bool

False >< False = False
False >< True = True
True >< False = True
True >< True = True 

