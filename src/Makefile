MAKEFLAGS=-j8
MAKEFLAGS += --no-builtin-rules
.SUFFIXES:	#サフィックス無効
CC:=g++ #g++でビルドする

CFLAGS:= -g3 #デバッグ情報最大化
CFLAGS+= -Wall #エラーを全部出す
CFLAGS+= -Wextra #追加の警告オプション
CFLAGS+= -std=c++23 #C++23でビルドする

RELEASE+= -O2	#最適化オプション
RELEASE+= -fexcess-precision=fast #古いgccで計算
RELEASE+= -ffast-math #誤差を全く無視
RELEASE+= -funroll-loops #ループ展開
RELEASE+= -Wall #エラーを全部出す
RELEASE+= -Wextra #追加の警告オプション
RELEASE+= -std=c++23 #C++23でビルドする

TARGET1= Server.elf #実行ファイルの名前
TARGET2= Client.elf #実行ファイルの名前
SRCS1= server.cpp
SRCS2= client.cpp

HEADER_DIR=./headers/stdafx.h #ヘッダファイル
PRECOMPILED_DIR=./headers/stdafx.h.gch #ヘッダファイル
CLASS_DIR=./class/class_net.cpp #クラスファイル

all_release:TARGET1 TARGET2
DIR=$(shell which "ccache")

all:
ifeq (${DIR},/usr/bin/ccache)
	ccache $(CC) -o $(TARGET1) $(CFLAGS) -include $(HEADER_DIR) -include $(CLASS_DIR) $(SRCS1)
	ccache $(CC) -o $(TARGET2) $(CFLAGS) -include $(HEADER_DIR) -include $(CLASS_DIR) $(SRCS2)
else
	$(CC) -o $(TARGET1) $(CFLAGS)  $(HEADER_DIR) $(CLASS_DIR) $(SRCS1)
	$(CC) -o $(TARGET2) $(CFLAGS)  $(HEADER_DIR) $(CLASS_DIR) $(SRCS2)
endif
TARGET1:
	$(CC) -o $(TARGET1) $(RELEASE)  $(HEADER_DIR) $(CLASS_DIR) $(SRCS1)
TARGET2:
	$(CC) -o $(TARGET2) $(RELEASE)  $(HEADER_DIR) $(CLASS_DIR) $(SRCS2)
