gcc = gcc -Wall -Werror -Wextra
clang = clang-format -i
cFiles = $(wildcard *.c)
hFiles = $(wildcard *.h)

all: clang str

reb: clang clean str

str:
	$(gcc) string.c -o str

clang:
	$(clang) $(cFiles) $(hFiles)

clean:
	rm -rf str
