module Lib
  ( usage
  ) where

import           System.Console.GetOpt

usage :: IO ()
usage =
  putStrLn
    "USAGE: ./imageCompressor n e IN\n\tn\tnumber of colors in the final image\n\te\tconvergence limit\n\tIN\tpath to the file containing the colors of the pixels"
