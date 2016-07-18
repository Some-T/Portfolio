
























































































-- 3:

-- a, b and c:

add (x,y) = x + y

join (xs,ys) = xs ++ ys

sumFromTo (m,n) = sum [m .. n]

volumeCylinder (radius,height) = pi * radius^2 * height

mult (x,y,z) = x * y * z

roots (a,b,c) = ((-b + t)/a', (-b - t)/a')
  where
     t  = b ^ 2 - 4 * a * c
     a' = 2 * a

     
-- d:

-- Currying in a sense is kind of removing the brackets.

-- Currying is the process of transforming a function that takes multiple arguments into a function that takes just a single argument and returns another function if any arguments are still needed.


add_ x y = x + y

join_ xs ys = xs ++ ys

sumFromTo_ m n = sum [m .. n]

volumeCylinder_ radius height = pi * radius^2 * height

mult_ x y z = x * y * z

roots_ a b c = ((-b + t)/a', (-b - t)/a')
  where
     t  = b ^ 2 - 4 * a * c
     a' = 2 * a


































-- 4:

-- a:

min3 a b c = min a (min b c)


-- b:

max4 a b c d = max a (max b (max c d)) 


-- c:


allTheSame a b c = a == b && b == c



-- d:

anyTwoTheSame a b c = a == b || b == c || a == c


-- e:

noneTheSame a b c = a /= b && b /= c


-- f:

finalSpeed i a t = i + a * t


-- g:

intoList a b c = [1,2,3]


-- h:

intoTuple a b c = (1,2,3)





