// use std::net::IpAddr;

// fn main() {
//     let home: IpAddr = "127.0.0.1".parse().unwrap();
// }

pub struct Guess {
    value: i32,
}

impl Guess {
    pub fn new(value: i32) -> Guess {
        if value < 1 || value > 100 {
            panic!("beween 1 and 100,{}", value);
        }

        Guess { value }
    }

    pub fn value(&self) -> i32 {
        self.value
    }
}

fn main() {
    
}
