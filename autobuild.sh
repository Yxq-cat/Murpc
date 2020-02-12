#########################################################################
# File Name: build.sh
# Author: yan xiao qian
# mail: 1741719839@qq.com
# Created Time: 2020年01月03日 星期五 19时06分14秒
#########################################################################
#!/bin/bash

set -e

rm -rf `pwd`/build/*
list=`find ./ -name "*.proto"`
for file in ${list}
do
	path=${file%/*}
	`protoc -I=$path --cpp_out=$path $file`
done

cd `pwd`/build &&
	cmake .. &&
	make

cd ../
cp ./src/rpc_cfg.xml ./bin
