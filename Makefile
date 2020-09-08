CROSS_COMPILE = 
CC = $(CROSS_COMPILE)gcc
CPP = $(CROSS_COMPILE)g++

APP_NAME = rtsp_server

VPATH  = .
VPATH += rtp
VPATH += rtp/payload
VPATH += rtsp
VPATH += rtsp/server/
VPATH += rtsp/server/aio
VPATH += rtsp/sdp/
VPATH += aio/ 
VPATH += http/
VPATH += flv/
VPATH += sdk/
VPATH += mov/
VPATH += media/

INCLUDE_PATH = include
FFMPEG_DIR_LIB = ffmpeg/lib/linux

SOURCES := $(foreach dir,$(VPATH),$(wildcard $(dir)/*))
C_SRCS   = $(filter %.c,$(SOURCES))
CPP_SRCS = $(filter %.cpp,$(SOURCES))

C_OBJS   = $(C_SRCS:%.c=%.o)
CPP_OBJS = $(CPP_SRCS:%.cpp=%.o)

OBJS   = $(C_OBJS) $(CPP_OBJS)

CFLAGS  := -g -D_HAVE_FFMPEG_ -D__STDC_CONSTANT_MACROS

LDFLAGS := -L$(FFMPEG_DIR_LIB)/
LDFLAGS += -lavformat -lavcodec -lswresample -lavutil -lswscale \
           -lx264 -lx265 -lopus -lasound -lpthread -lstdc++ -lm -lrt -lz -ldl\
           -lstdc++ -lpthread -lrt

CFLAGS += -I$(INCLUDE_PATH)
CFLAGS += -I$(INCLUDE_PATH)/rtp
CFLAGS += -I$(INCLUDE_PATH)/rtp/payload
CFLAGS += -I$(INCLUDE_PATH)/rtsp
CFLAGS += -I$(INCLUDE_PATH)/rtsp/server
CFLAGS += -I$(INCLUDE_PATH)/rtsp/server/aio
CFLAGS += -I$(INCLUDE_PATH)/aio
CFLAGS += -I$(INCLUDE_PATH)/http
CFLAGS += -I$(INCLUDE_PATH)/flv
CFLAGS += -I$(INCLUDE_PATH)/media
CFLAGS += -I$(INCLUDE_PATH)/mov
CFLAGS += -Iffmpeg/include

CPPFLAGS := -std=c++0x -D_HAVE_FFMPEG_
CPPFLAGS+ = -I$(INCLUDE_PATH)/http


all: $(APP_NAME)

$(APP_NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
	
%.o: %.cpp
	$(CPP) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<
	
clean:
	rm -rf $(OBJS)
	rm -f $(APP_NAME)