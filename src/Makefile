MAKEFLAGS=-j8
MAKEFLAGS+= --no-builtin-rules
.SUFFIXES:	#サフィックス無効
CXX:=g++ #g++でビルドする

DEBUG:= -g3 #デバッグ情報最大化
CFLAGS:= -Wall #エラーを全部出す
CFLAGS+= -Wextra #追加の警告オプション
CFLAGS+= -Wcast-align #ポインタのキャスト
CFLAGS+= -Wdouble-promotion #floatからdouble
CFLAGS+= -Wconversion #暗黙的方変換
CFLAGS+= -Weffc++ #Effective C++
CFLAGS+= -Wfloat-equal #浮動小数点の比較
CFLAGS+= -Wlogical-op #正しい論理演算子
CFLAGS+= -Wmissing-declarations #前にないグローバル関数
CFLAGS+= -Wmissing-include-dirs #存在しないinclude
CFLAGS+= -Wold-style-cast #C風のキャストの防止
CFLAGS+= -Wswitch-default #default文の矯正
CFLAGS+= -Wunsafe-loop-optimizations #ループのオーバーフロー

CFLAGS+= -std=c++20 #C++23でビルドする
CFLAGS+= -pipe #パイプ処理でコンパイル
RELEASE:= -O2	#最適化オプション
RELEASE+= -fexcess-precision=fast #古いgccで計算
RELEASE+= -ffast-math #誤差を全く無視
RELEASE+= -fomit-frame-pointer #バイナリのサイズ減少
RELEASE+= -march=native #このアーキテクチャのみのバイナリ生成
RELEASE+= -pipe

TARGET1= main.elf #実行ファイルの名前
SRCS1= main.cpp

HEADER_DIR=./headers/stdafx.hpp #ヘッダファイル
CLASS_DIR=./class/class_net.cpp #クラスファイル

all:TARGET1
DIR=$(shell which "ccache")

TARGET1:
	$(CXX) -o $(TARGET1) $(CFLAGS) $(RELEASE) -include $(HEADER_DIR) -include $(CLASS_DIR) $(SRCS1) -lpigpio

