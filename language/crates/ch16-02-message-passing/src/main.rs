use std::sync::mpsc;
use std::thread;
use std::time::Duration;

// fn main() {
//     let (tx, rx) = mpsc::channel();

//     thread::spawn(move || {
//         let val = String::from("hi");
//         tx.send(val).unwrap();
//         // tx.send(val).unwrap();
//         println!("val is {}", val);
//     });

//     let received = rx.recv().unwrap();

//     println!("Hello, world!,{}", received);
// }

// fn main() {
//     let (tx, rx) = mpsc::channel();

//     thread::spawn(move || {
//         let vals = vec![
//             String::from("hi"),
//             String::from("form"),
//             String::from("the"),
//             String::from("thread"),
//         ];

//         for val in vals {
//             tx.send(val).unwrap();
//             thread::sleep(Duration::from_millis(200));
//         }
//     });

//     for re in rx {
//         println!("fo: {}", re);
//     }
// }

fn main() {
    let (tx, rx) = mpsc::channel();
    let tx1 = mpsc::Sender::clone(&tx);
    thread::spawn(move || {
        let vals = vec![
            String::from("1:hi"),
            String::from("1:form"),
            String::from("1:the"),
            String::from("1:thread"),
        ];

        for val in vals {
            tx1.send(val).unwrap();
            thread::sleep(Duration::from_millis(200));
        }
    });

    thread::spawn(move || {
        let vals = vec![
            String::from("hi"),
            String::from("form"),
            String::from("the"),
            String::from("thread"),
        ];

        for val in vals {
            tx.send(val).unwrap();
            thread::sleep(Duration::from_millis(200));
        }
    });

    for re in rx {
        println!("fo: {}", re);
    }
}
