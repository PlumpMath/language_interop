import Foreign
import Foreign.C.Types
import Foreign.ForeignPtr

-- C

foreign import ccall "sinapprox"
    c_sinapprox :: CDouble -> CDouble

foreign import ccall "c_testing"
    c_testing :: IO ()

-- Rust

foreign import ccall "rust_testing"
    rust_testing :: IO ()

-- C++

type MyCPPClass = Ptr CMyCPPClass
data CMyCPPClass

foreign import ccall "cclib-c.h newmyCPPClass"
    newc :: CInt -> IO MyCPPClass

foreign import ccall "cclib-c.h myCPPClass_destroy"
    delc :: MyCPPClass -> IO ()

foreign import ccall "cclib-c.h myCPPClass_doVoidy"
    doVoidy :: MyCPPClass -> IO ()

foreign import ccall "cclib-c.h myCPPClass_doInty"
    doInty :: MyCPPClass -> CInt -> CInt

-- Do the mash

main :: IO ()
main = do
    c <- newc 3
    doVoidy c
    delc c
    rust_testing
    c_testing
