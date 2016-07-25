module Main where

import System.Environment
import Data.Char

main = do
  (args) <- getArgs
  xs <- getContents
  putStr (redact xs (map lwr args))
  
redact input ws = unlines [ process line | line <- lines input ]
  where process line  = unwords [ f word | word <- words line ]
        f w | lwr w `elem` ws  = replicate (length w) '*'
            | otherwise = w

lwr xs = map toLower xs