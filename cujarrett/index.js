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
