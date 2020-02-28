fn readline(line: &str) -> usize{
    let mut it = line.split(' ');
    let (key, value) = match (it.next(), it.next()) {
        (Some(key), Some(value)) => (key.trim(), value.trim()),
        _ => panic!(),
    };
    let mut size: usize = 0;
    if key == "breadsticks" {
        match value.parse() {
            Ok(val) => size = val,
            Err(_) => return size,
        }
    }
    size
}

pub fn get(filename: &str) -> usize {
    use std::fs::File;
    use std::io::BufRead;
    use std::io::BufReader;

    let file = match File::open(filename) {
        Ok(val) => val,
        Err(_) => return 0,
    };
    let reader = BufReader::new(file);
    let mut total: usize = 0;
    for line in reader.lines().filter_map(|result| result.ok()) {
            total += readline(&line);
    }

    total
}