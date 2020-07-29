MATLAB_ROOT = /usr/local/matlab/r2018b
MAKEFILE = Split_chi_2_mex.mk

include Split_chi_2_mex.mki


SRC_FILES =  \
	Split_chi_2_data.cpp \
	Split_chi_2_initialize.cpp \
	Split_chi_2_terminate.cpp \
	Split_chi_2.cpp \
	eml_int_forloop_overflow_check.cpp \
	exp.cpp \
	fft.cpp \
	fft1.cpp \
	FFTWApi.cpp \
	ifft.cpp \
	power.cpp \
	_coder_Split_chi_2_info.cpp \
	_coder_Split_chi_2_api.cpp \
	_coder_Split_chi_2_mex.cpp \
	Split_chi_2_emxutil.cpp \
	cpp_mexapi_version.cpp

MEX_FILE_NAME_WO_EXT = Split_chi_2_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexa64
TARGET = $(MEX_FILE_NAME)

SYS_LIBS = 


#
#====================================================================
# gmake makefile fragment for building MEX functions using Unix
# Copyright 2007-2016 The MathWorks, Inc.
#====================================================================
#

OBJEXT = o
.SUFFIXES: .$(OBJEXT)

OBJLISTC = $(SRC_FILES:.c=.$(OBJEXT))
OBJLISTCPP  = $(OBJLISTC:.cpp=.$(OBJEXT))
OBJLIST  = $(OBJLISTCPP:.cu=.$(OBJEXT))

target: $(TARGET)

ML_INCLUDES = -I "$(MATLAB_ROOT)/simulink/include"
ML_INCLUDES+= -I "$(MATLAB_ROOT)/toolbox/shared/simtargets"
SYS_INCLUDE = $(ML_INCLUDES)

# Additional includes

SYS_INCLUDE += -I "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches\ Tracking/MI_LLE/Solver_Starter/Solvers/codegen/mex/Split_chi_2"
SYS_INCLUDE += -I "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches\ Tracking/MI_LLE/Solver_Starter/Solvers"
SYS_INCLUDE += -I "./interface"
SYS_INCLUDE += -I "$(MATLAB_ROOT)/extern/include"
SYS_INCLUDE += -I "."

EML_LIBS = -lemlrt -lcovrt -lut -lmwmathutil 
SYS_LIBS += $(CLIBS) $(EML_LIBS)


EXPORTFILE = $(MEX_FILE_NAME_WO_EXT)_mex.map
ifeq ($(Arch),maci)
  EXPORTOPT = -Wl,-exported_symbols_list,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS))
else ifeq ($(Arch),maci64)
  EXPORTOPT = -Wl,-exported_symbols_list,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS)) -Wl,-rpath,@loader_path
else
  EXPORTOPT = -Wl,--version-script,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS) $(OMPFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS) $(OMPFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS)) 
endif
LINK_FLAGS += $(OMPLINKFLAGS)
ifeq ($(Arch),maci)
  LINK_FLAGS += -L$(MATLAB_ROOT)/sys/os/maci
endif
ifeq ($(EMC_CONFIG),optim)
  ifeq ($(Arch),mac)
    COMP_FLAGS += $(CDEBUGFLAGS)
    CXX_FLAGS += $(CXXDEBUGFLAGS)
  else
    COMP_FLAGS += $(COPTIMFLAGS)
    CXX_FLAGS += $(CXXOPTIMFLAGS)
  endif
  LINK_FLAGS += $(LDOPTIMFLAGS)
else
  COMP_FLAGS += $(CDEBUGFLAGS)
  CXX_FLAGS += $(CXXDEBUGFLAGS)
  LINK_FLAGS += $(LDDEBUGFLAGS)
endif
LINK_FLAGS += -o $(TARGET)
LINK_FLAGS += 

CCFLAGS = $(COMP_FLAGS) -std=c99   $(USER_INCLUDE) $(SYS_INCLUDE)
CPPFLAGS = $(CXX_FLAGS) -std=c++11   $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : %.cpp
	$(CXX) $(CPPFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : /u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches\ Tracking/MI_LLE/Solver_Starter/Solvers/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches\ Tracking/MI_LLE/Solver_Starter/Solvers/codegen/mex/Split_chi_2/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : interface/%.c
	$(CC) $(CCFLAGS) "$<"



%.$(OBJEXT) : /u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches\ Tracking/MI_LLE/Solver_Starter/Solvers/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : /u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches\ Tracking/MI_LLE/Solver_Starter/Solvers/codegen/mex/Split_chi_2/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : interface/%.cpp
	$(CXX) $(CPPFLAGS) "$<"



%.$(OBJEXT) : /u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches\ Tracking/MI_LLE/Solver_Starter/Solvers/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches\ Tracking/MI_LLE/Solver_Starter/Solvers/codegen/mex/Split_chi_2/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : interface/%.cu
	$(CC) $(CCFLAGS) "$<"




$(TARGET): $(OBJLIST) $(MAKEFILE)
	$(LD) $(EXPORTOPT) $(OBJLIST) $(LINK_FLAGS) $(SYS_LIBS)

#====================================================================

