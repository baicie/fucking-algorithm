// #[derive(Debug)]
// enum UsState {
//     Alabama,
//     Alaska,
// }
// enum Coin {
//     Penny,
//     Nickel,
//     Dime,
//     Quarter(UsState),
// }

// fn main() {
//     let coin1 = Coin::Quarter(UsState::Alabama);
//     value_in_cents(coin1);
// }

// fn value_in_cents(coin: Coin) -> u8 {
//     match coin {
//         Coin::Penny => {
//             println!("lick penny");
//             1
//         }
//         Coin::Nickel => 5,
//         Coin::Dime => 10,
//         Coin::Quarter(state) => {
//             println!("{:?}", state);
//             25
//         }
//     }
// }

// fn plus_one(x: Option<i32>) -> Option<i32> {
//     match x {
//         None => None,
//         Some(i) => Some(i + 1),
//     }
// }

// fn main() {
//     let five = Some(5);
//     let six = plus_one(five);
//     let none = plus_one(None);

//     println!("{:?},{:?},{:?}", five, six, none);
// }

fn main() {
    let dice_roll = 9;
    match dice_roll {
        3 => 3,
        _ => (),
    }
}
