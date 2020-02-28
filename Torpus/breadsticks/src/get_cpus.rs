pub fn get() -> usize {
    use std::fs::File;
    use std::io::BufRead;
    use std::io::BufReader;

    let file = match File::open("/proc/cpuinfo") {
        Ok(val) => val,
        Err(_) => return 0,
    };
    let reader = BufReader::new(file);
    let mut count = 0;
    for line in reader.lines().filter_map(|result| result.ok()) {
        let mut it = line.split(':');
        let key = match it.next() {
            Some(key) => key.trim(),
            _ => continue,
        };
        if key == "processor" {
            count += 1;
        }
    }

    count
}