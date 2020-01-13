module Commands
    ( check
    , unique
    , clean
    ) where

import Utils

printer :: Bool -> IO ()
printer condition = putStrLn $ if condition then "OK" else "KO"

check :: Int -> String -> IO ()
check order alphabet = do
    userInput <- getLine
    printer $ checkSequence userInput
        where checkSequence = isDeBruijnSequence order alphabet

unique :: Int -> String -> IO ()
unique order alphabet = do
    lseq <- getLine
    rseq <- getLine
    printer (checkSequence lseq && checkSequence rseq && (not $ areEquivalents lseq rseq))
    where checkSequence = isDeBruijnSequence order alphabet

getLines :: IO [String]
getLines = do lines <- readLines []; return $ reverse lines
    where
        readLines :: [String] -> IO [String]
        readLines xs = do
            x <- getLine
            checkLine (x : xs)
        checkLine :: [String] -> IO [String]
        checkLine xs
            | head xs == "END"  = return $ tail xs
            | otherwise         = readLines xs

clean :: Int -> String -> IO ()
clean order alphabet = do
    lines <- getLines
    putStr $ foldr (\x y -> x ++ "\n" ++ y) "" (filterNotDeBruijn $ filtering (\x y -> not $ areEquivalents x y) lines)
    where
        filterNotDeBruijn xs = [ x | x <- xs, isDeBruijnSequence order alphabet x ]
