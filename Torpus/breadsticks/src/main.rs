use std::env::args;

mod get_breadsticks;
mod get_cpus;

fn main() {
    let filename = args().nth(1).unwrap();
    println!("Available cpus: {}", get_cpus::get());
    println!("{}", get_breadsticks::get(&filename));
}
