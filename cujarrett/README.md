# Solutions

## Bash

From [Travis](https://travis-ci.org/Torpus/breadsticks/jobs/656732657?utm_medium=notification&utm_source=github_status)
```shell
0.31s$ time node ./cujarrett/index.js word_number.txt
breadsticks sum: 3297861
real	0m0.311s
user	0m0.331s
sys	0m0.029s
```

First time I ran at this I used a trusted `.filter()` but swapped to a faster streaming option that I had no clue of before breadsticks fun.
```js
const fs = require("fs")
const file = process.argv[2]
const data = fs.readFileSync(file, "utf-8")
const lines = data.split("\n")
let sum = 0
lines.filter((line) => {
  if (line.includes("breadsticks")) {
    sum += Number(line.substring(line.indexOf(" ") + 1))
  }
})

console.log(`breadsticks sum: ${sum}`)
```
