// enum IpAddrKind {
//     V4,
//     V6,
// }

// struct IpAddr {
//     kind: IpAddrKind,
//     address: String,
// }

// fn main() {
//     let four = IpAddrKind::V4;
//     let six = IpAddrKind::V6;

//     let home = IpAddr {
//         kind: IpAddrKind::V4,
//         address: String::from("127.0.0.1"),
//     };

//     let lookback = IpAddr {
//         kind: IpAddrKind::V6,
//         address: String::from("::1"),
//     };

//     println!("Hello, world!");
// }

// enum IpAddr {
//     V4(String),
//     V6(String),
// }

// fn main() {
//     let home = IpAddr::V4(String::from("127.0.0.1"));
//     let loopback = IpAddr::V6(String::from("::1"));
// }

// enum Message {
//     Quit,
//     Move{s:i32,y:i32},
//     Write(String),
//     ChangeColor(i32,i32,i32),
// }

enum Option<T> {
    None,
    Some(T),
}

fn main() {
    let some_number = Some(5);
    let some_char = Some('e');

    let absent_number: Option<i32> = None;
}
