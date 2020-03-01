# Solutions

## Bash

```shell
time ./circa10a/breadsticks.sh word_number.txt
RESULT: 3297861
./circa10a/breadsticks.sh word_number.txt  0.22s user 0.02s system 95% cpu 0.249 total
```

## Go

```shell
go build -ldflags="-s -w" circa10a/go/breadsticks.go
time ./breadsticks word_number.txt
3297861
```

## Python

```shell
time python circa10a/breadsticks.py word_number.txt
3297861
```

## Ruby

```shell
time ruby circa10a/breadsticks.rb word_number.txt
3297861
```

## C

```shell
gcc -o breadsticks ./circa10a/breadsticks.c
time ./breadsticks word_number.txt
3297861
```
