cc = gcc


ofile = main.o DataSizeFcn.o DataArrayFcn.o
hfile = DataSizeFcn.h DataArrayFcn.h


# ReadData即生成的最终执行文件, 该文件的生成, 需要ofile中的那些文件
# 注: shell命令的前面, 一定要有个tab键
ReadData: $(ofile)
	$(cc) $(ofile) -o ReadData


# ofile中的那些文件的生成
# main.o的生成:
main.o: main.c DataSizeFcn.h DataArrayFcn.h
	$(cc) -c main.c
# DataSizeFcn.o的生成:
DataSizeFcn.o: DataSizeFcn.c
	$(cc) -c DataSizeFcn.c
# DataArrayFcn.o的生成:
DataArrayFcn.o: DataArrayFcn.c
	$(cc) -c DataArrayFcn.c


.PHONY: clean
clean:
	rm ReadData *.o
