module DoStuff where

import Foreign.C.Types

doStuff :: Int -> IO ()
doStuff x = putStrLn $ "Hello from Haskell! " ++ (show x)

doStuff_hs :: CInt -> IO ()
doStuff_hs = doStuff . fromIntegral

foreign export ccall doStuff_hs :: CInt -> IO ()
