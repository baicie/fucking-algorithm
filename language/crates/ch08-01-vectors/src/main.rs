// // use std::collections::*;
// fn main() {
//     // let mut v = Vec::new();
//     // let mut v: Vec<i32> = Vec::new();
//     let mut v = vec![1, 2, 3];
//     // v.push(1);

//     println!("Hello, world!{}",);
// }

// fn main() {
//     let v = vec![1, 2, 3, 4, 5];

//     // let third: &i32 = &v[100];

//     // println!("{}", third);

//     match v.get(100) {
//         Some(value) => println!("{}", value),
//         None => println!("nothing"),
//     }
// }

// fn main() {
//     let mut v = vec![1, 2, 3, 4, 5];
//     let first = &v[0];
//     v.push(6);
//     println!("{}", first);
// }

// fn main() {
//     let v = vec![1, 2, 3, 4, 5];

//     for i in &v {
//         println!("{}", i);
//     }
// }

fn main() {
    let mut v = vec![1, 2, 3, 4, 5];

    for i in &mut v {
        // println!("{}", i);
        *i += 50;
    }

    println!("{:#?}", v);
}
