// Info: https://nodejs.org/api/readline.html#readline_readline_createinterface_options
const file = process.argv[2]
var fs = require("fs")
var readline = require("readline")

var inputStream = fs.createReadStream(file)
var inputStreamInterface = readline.createInterface(inputStream)
let sum = 0

inputStreamInterface.on("line", (line) => {
  if (line.startsWith("breadsticks")) {
    sum += Number(line.split(" ")[1])
  }
})

inputStreamInterface.on("close", () => {
  console.log(`breadsticks sum: ${sum}`)
})
