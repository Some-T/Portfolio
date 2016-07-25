module Main where

import System.Environment
import Data.Char

main = do
  (args) <- getArgs
  xs <- getContents
  putStr (count xs (map lwr args))
  
count input ws = unlines [ process line | line <- lines input]
 where process line = head ws ++ " occurs " ++ show ( length [ w | w <- words line, lwr w `elem` ws]) ++ "times\n"

lwr xs = map toLower xs