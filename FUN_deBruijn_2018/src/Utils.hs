module Utils
    ( getWords
    , isDeBruijnSequence
    , areUniques
    , areEquivalents
    , filtering
    ) where

import DeBruijn
import Data.List

getWords :: Int -> [a] -> [[a]]
getWords size xs = extractWords xs'
    where
        xs' = xs ++ take (size - 1) xs
        extractWords xs''
            | length xs'' == size   = [take size xs'']
            | otherwise             = take size xs'' : extractWords (drop 1 xs'')


isDeBruijnSequence :: Int -> String -> String -> Bool
isDeBruijnSequence order alphabet sequence = reference == words
    where
        reference   = sort (getWords order . deBruijn order $ alphabet)
        words       = sort (getWords order sequence)

areUniques :: (Ord a) => [a] -> Bool
areUniques xs = uniqueCheck sorted (drop 1 sorted)
    where
        sorted = sort xs
        uniqueCheck (x:xs') (y:ys)  = if x /= y then uniqueCheck xs' ys else False
        uniqueCheck [] _            = True
        uniqueCheck _ []            = True

rotate :: Int -> [a] -> [a]
rotate _ [] = []
rotate 0 xs = xs
rotate n xs = rotate (n - 1) (last xs : init xs)

areEquivalents :: (Eq a) => [a] -> [a] -> Bool
areEquivalents [] [] = True
areEquivalents xs ys = foldr (||) False [ rotate x xs == ys | x <- [0..(length xs)] ]

filtering :: (a -> a -> Bool) -> [a] -> [a]
filtering _ []        = []
filtering _ [x]       = [x]
filtering f (x:xs)    = x : [ y | y <- filtering f xs, f y x ]