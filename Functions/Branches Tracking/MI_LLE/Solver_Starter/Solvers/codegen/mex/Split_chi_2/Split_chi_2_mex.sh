MATLAB="/usr/local/matlab/r2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/u/p/dp710/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for Split_chi_2" > Split_chi_2_mex.mki
echo "CC=$CC" >> Split_chi_2_mex.mki
echo "CFLAGS=$CFLAGS" >> Split_chi_2_mex.mki
echo "CLIBS=$CLIBS" >> Split_chi_2_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> Split_chi_2_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> Split_chi_2_mex.mki
echo "CXX=$CXX" >> Split_chi_2_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> Split_chi_2_mex.mki
echo "CXXLIBS=$CXXLIBS" >> Split_chi_2_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> Split_chi_2_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> Split_chi_2_mex.mki
echo "LDFLAGS=$LDFLAGS" >> Split_chi_2_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> Split_chi_2_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> Split_chi_2_mex.mki
echo "Arch=$Arch" >> Split_chi_2_mex.mki
echo "LD=$LDXX" >> Split_chi_2_mex.mki
echo OMPFLAGS= >> Split_chi_2_mex.mki
echo OMPLINKFLAGS= >> Split_chi_2_mex.mki
echo "EMC_COMPILER=gcc" >> Split_chi_2_mex.mki
echo "EMC_CONFIG=optim" >> Split_chi_2_mex.mki
"/usr/local/matlab/r2018b/bin/glnxa64/gmake" -j 1 -B -f Split_chi_2_mex.mk
