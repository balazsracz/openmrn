ifndef TOOLPATH
TOOLPATH := $(shell \
sh -c "if [ -d /usr/include/linux ]; then echo /usr/bin; \
      else echo; fi" \
)
endif

# Get the $(CFLAGSENV), $(CXXFLAGSENV), $(LDFLAGSENV)
include $(OPENMRNPATH)/etc/env.mk
include $(OPENMRNPATH)/etc/path.mk

DEPS += CLANGPPPATH

CC = $(CLANGPPPATH)/clang
CXX = $(CLANGPPPATH)/clang++
AR = $(CLANGPPPATH)/llvm-ar
LD = $(CLANGPPPATH)/clang++

# llvm-objdump is not 100% compatible with GCC conventions.  It turns out that
# newer versionf of llvm remove the -symbolize option causing errors.  For
# now, we just disable OBJDUMP for the llvm target.
OBJDUMP = #llvm-objdump

OBJDUMPOPTS=-symbolize 

HOST_TARGET := 1

STARTGROUP := -Wl,--start-group
ENDGROUP := -Wl,--end-group

ARCHSELECT = -m64
ARCHOPTIMIZATION = -g -O0 $(ARCHSELECT)

CSHAREDFLAGS = -c $(ARCHOPTIMIZATION) -Wall -Werror -MP -fno-stack-protector -D_GNU_SOURCE

CFLAGS = $(CSHAREDFLAGS) -std=gnu99

CXXFLAGS = $(CSHAREDFLAGS) -std=c++0x -D__STDC_FORMAT_MACROS \
           -D__STDC_LIMIT_MACROS #-D__LINEAR_MAP__

LDFLAGS = -g $(ARCHSELECT) -Wl,-Map="$(@:%=%.map)"
SYSLIB_SUBDIRS +=
SYSLIBRARIES = -lrt -lpthread

EXTENTION =

