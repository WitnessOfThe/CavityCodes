MATLAB="/usr/local/matlab/r2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/u/p/dp710/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for Chi_3_LLE_Runge_Kuarong" > Chi_3_LLE_Runge_Kuarong_mex.mki
echo "CC=$CC" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "CFLAGS=$CFLAGS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "CLIBS=$CLIBS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "CXX=$CXX" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "CXXLIBS=$CXXLIBS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "LDFLAGS=$LDFLAGS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "Arch=$Arch" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "LD=$LDXX" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo OMPFLAGS= >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo OMPLINKFLAGS= >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "EMC_COMPILER=gcc" >> Chi_3_LLE_Runge_Kuarong_mex.mki
echo "EMC_CONFIG=optim" >> Chi_3_LLE_Runge_Kuarong_mex.mki
"/usr/local/matlab/r2018b/bin/glnxa64/gmake" -j 1 -B -f Chi_3_LLE_Runge_Kuarong_mex.mk
