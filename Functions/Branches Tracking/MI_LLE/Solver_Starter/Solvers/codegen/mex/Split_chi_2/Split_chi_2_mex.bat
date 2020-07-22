@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2018b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2018b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=Split_chi_2_mex
set MEX_NAME=Split_chi_2_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for Split_chi_2 > Split_chi_2_mex.mki
echo CC=%COMPILER%>> Split_chi_2_mex.mki
echo CXX=%CXXCOMPILER%>> Split_chi_2_mex.mki
echo CFLAGS=%COMPFLAGS%>> Split_chi_2_mex.mki
echo CXXFLAGS=%CXXCOMPFLAGS%>> Split_chi_2_mex.mki
echo LINKER=%LINKER%>> Split_chi_2_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> Split_chi_2_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> Split_chi_2_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> Split_chi_2_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> Split_chi_2_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> Split_chi_2_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> Split_chi_2_mex.mki
echo OMPFLAGS= >> Split_chi_2_mex.mki
echo OMPLINKFLAGS= >> Split_chi_2_mex.mki
echo EMC_COMPILER=mingw64>> Split_chi_2_mex.mki
echo EMC_CONFIG=optim>> Split_chi_2_mex.mki
"C:\Program Files\MATLAB\R2018b\bin\win64\gmake" -j 1 -B -f Split_chi_2_mex.mk
