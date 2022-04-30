MAKEFLAGS=-j8
MAKEFLAGS += --no-builtin-rules
.SUFFIXES:	#サフィックス無効
CC:=g++ #g++でビルドする

CFLAGS:= -g3 #デバッグ情報最大化
CFLAGS+= -Wall #エラーを全部出す
CFLAGS+= -Wextra #追加の警告オプション
CFLAGS+= -std=c++23 #C++23でビルドする

TARGET1= Server #実行ファイルの名前
TARGET2= Client #実行ファイルの名前
SRCS1= server.cpp
SRCS2= client.cpp

all_old:TARGET1 TARGET2
DIR=$(shell which "ccache")

all:
ifeq (${DIR},/usr/bin/ccache)
	ccache $(CC) -o $(TARGET1) $(CFLAGS) $(SRCS1)
	ccache $(CC) -o $(TARGET2) $(CFLAGS) $(SRCS2)
else
	$(CC) -o $(TARGET1) $(CFLAGS) $(SRCS1)
	$(CC) -o $(TARGET2) $(CFLAGS) $(SRCS2)
endif
TARGET1:
	$(CC) -o $(TARGET1) $(CFLAGS) $(SRCS1)
TARGET2:
	$(CC) -o $(TARGET2) $(CFLAGS) $(SRCS2)
