use std::env::args;

mod get_breadsticks;

fn main() {
    let filename = args().nth(1).unwrap();
    println!("{}", get_breadsticks::get(&filename));
}
