// pub fn add(left: usize, right: usize) -> usize {
//     left + right
// }

// #[cfg(test)]
// mod tests {
//     use super::*;

//     #[test]
//     fn it_works() {
//         let result = add(2, 2);
//         assert_eq!(result, 4);
//     }

//     #[test]
//     fn another() {
//         panic!("make this test fail")
//     }
// }

// #[derive(Debug)]
// struct Rectangle {
//     width: u32,
//     height: u32,
// }

// impl Rectangle {
//     fn area(&self) -> u32 {
//         self.height * self.width
//     }
//     fn width(&self) -> bool {
//         self.width > 0
//     }
//     fn can_hold(&self, other: &Rectangle) -> bool {
//         self.width > other.width && self.height > other.height
//     }
//     fn square(size: u32) -> Self {
//         Self {
//             width: size,
//             height: size,
//         }
//     }
// }

// #[cfg(test)]
// mod tests {
//     use super::*;

//     #[test]
//     fn largesr_can_hold_smaller() {
//         let rect1 = Rectangle {
//             width: 30,
//             height: 50,
//         };

//         let rect2 = Rectangle {
//             width: 10,
//             height: 40,
//         };

//         assert!(rect1.can_hold(&rect2));
//     }

//     #[test]
//     fn samller_cammot_hold_larger() {
//         let rect1 = Rectangle {
//             width: 30,
//             height: 50,
//         };

//         let rect2 = Rectangle {
//             width: 10,
//             height: 40,
//         };

//         assert!(!rect2.can_hold(&rect1));
//     }
// }

// pub fn add_two(a: i32) -> i32 {
//     a + 2
// }

// #[cfg(test)]
// mod tests {
//     use super::*;

//     #[test]
//     fn if_adds_two() {
//         // assert_eq!(4, add_two(2));
//         assert_ne!(4, add_two(2));
//     }
// }

// pub fn greeting(name: &str) -> String {
//     format!("Hellow {}!", name)
// }

// #[cfg(test)]
// mod tests {
//     use super::*;

//     #[test]
//     fn greetings_contain_name() {
//         let result = greeting("Carol");
//         assert!(result.contains("Carol"), "Carol value {}", result);
//     }
// }

// pub struct Guess {
//     value: u32,
// }

// impl Guess {
//     pub fn new(value: u32) -> Guess {
//         if value < 1 || value > 100 {
//             panic!("between 1 and 100. got {}", value)
//         }

//         Guess { value }
//     }
// }

// #[cfg(test)]
// mod tests {
//     use super::*;

//     #[test]
//     #[should_panic]
//     fn greater_than_100() {
//         Guess::new(200);
//     }
// }

// pub struct Guess {
//     value: u32,
// }

// impl Guess {
//     pub fn new(value: u32) -> Guess {
//         if value < 1 {
//             panic!("big than 0. got {}", value)
//         } else if value > 100  {
//             panic!("smaller than 100. got {}", value)
//         }

//         Guess { value }
//     }
// }

// #[cfg(test)]
// mod tests {
//     use super::*;

//     #[test]
//     #[should_panic(expected = "smaller than 100.")]
//     fn greater_than_100() {
//         Guess::new(200);
//     }
// }

mod tests {
    #[test]
    fn it_works() -> Result<(), String> {
        if 2 + 2 == 4 {
            Ok(())
        } else {
            Err(String::from("two plus two does not equal four"))
        }
    }
}
