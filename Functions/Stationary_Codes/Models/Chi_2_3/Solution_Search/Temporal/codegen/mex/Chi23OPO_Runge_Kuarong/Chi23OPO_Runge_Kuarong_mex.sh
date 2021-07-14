MATLAB="/usr/local/matlab/r2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/u/p/dp710/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for Chi23OPO_Runge_Kuarong" > Chi23OPO_Runge_Kuarong_mex.mki
echo "CC=$CC" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "CFLAGS=$CFLAGS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "CLIBS=$CLIBS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "CXX=$CXX" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "CXXLIBS=$CXXLIBS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "LDFLAGS=$LDFLAGS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "Arch=$Arch" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "LD=$LD" >> Chi23OPO_Runge_Kuarong_mex.mki
echo OMPFLAGS= >> Chi23OPO_Runge_Kuarong_mex.mki
echo OMPLINKFLAGS= >> Chi23OPO_Runge_Kuarong_mex.mki
echo "EMC_COMPILER=gcc" >> Chi23OPO_Runge_Kuarong_mex.mki
echo "EMC_CONFIG=optim" >> Chi23OPO_Runge_Kuarong_mex.mki
"/usr/local/matlab/r2018b/bin/glnxa64/gmake" -j 1 -B -f Chi23OPO_Runge_Kuarong_mex.mk
