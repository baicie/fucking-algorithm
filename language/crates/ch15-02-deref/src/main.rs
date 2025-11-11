use std::ops::Deref;

fn hello(name: &str) {
    println!("hello,{}", name);
}

fn main() {
    let m = Box::new(String::from("Rust"));

    hello(&m);

    println!("Hello, world!");
}
