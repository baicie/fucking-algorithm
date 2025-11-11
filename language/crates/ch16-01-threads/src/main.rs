use std::thread;
// use std::time::Duration;
// fn main() {
//     println!("Hello, world!");
//     let handle = thread::spawn(|| {
//         for i in 1..10 {
//             println!("1. {}", i);
//             thread::sleep(Duration::from_millis(1));
//         }
//     });

//     handle.join().unwrap();

//     for i in 1..5 {
//         println!("2. {}", i);
//         thread::sleep(Duration::from_millis(1));
//     }
// }

fn main() {
    let v = vec![1, 2, 3];

    let handle = thread::spawn(move || {
        println!("{:?}", v);
    });

    handle.join().unwrap();
}
