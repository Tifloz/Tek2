module DeBruijn
    ( deBruijn
    , reverser_one
    ) where

deBruijn :: Int -> String -> String
deBruijn 0 _            = ""
deBruijn _ ""           = ""
deBruijn order alphabet = [ alphabet !! x | x <- sequence]
    where
        base        = length alphabet
        sequence    = changer base order

changer :: Int -> Int -> [Int]
changer base order = concat (filter (\xs -> mod order (length xs) == 0) (reverse(reverser base order [[0]])))

reverser :: Int -> Int -> [[Int]] -> [[Int]]
reverser base order prevWords
    | word == []    = prevWords
        | otherwise     = reverser base order (word : prevWords)
            where word  = reverser_one base order (head prevWords)

reverser_one :: Int -> Int -> [Int] -> [Int]
reverser_one base order prevWord = incr (dropZ word)
    where
        word    = take order (cycle prevWord)
        dropZ xs
            | length xs /= 0 && last xs == (base - 1) = dropZ (init xs)
            | otherwise = xs
        incr :: [Int] -> [Int]
        incr [] = []
        incr xs = (init xs) ++ [last xs + 1]
