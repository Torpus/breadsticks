package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io/ioutil"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func main() {
	var result int
	r, _ := regexp.Compile("breadsticks")
	content, _ := ioutil.ReadFile(os.Args[1])
	s := bufio.NewScanner(bytes.NewReader(content))
	s.Split(bufio.ScanLines)
	for s.Scan() {
		word := s.Bytes()
		str := string(word)
		if r.MatchString(str) {
			num, _ := strconv.Atoi(strings.Split(str, " ")[1])
			result += num
		}
	}
	fmt.Println(result)
}
