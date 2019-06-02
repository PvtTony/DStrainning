CC = clang
LLDB = /usr/local/opt/llvm/bin/lldb
.PHONY : clean
export LDFLAGS="-L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib"
export CPPFLAGS="-I/usr/local/opt/llvm/include,/usr/local/opt/llvm/include/c++/v1/"
all:linearlist.c
	$(CC) -g -o linearlist linearlist.c
debug:
	$(LLDB) linearlist
clean:
	rm -rf linearlist.dSYM
	rm -f linearlist
