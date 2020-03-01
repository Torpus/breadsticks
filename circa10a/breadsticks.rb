r = Regexp.new("breadsticks")
result = 0

File.readlines(ARGV[0]).each do |line|
    if r.match(line)
        result += line.split(" ")[1].to_i
    end
end
puts result