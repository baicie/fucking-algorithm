use std::{
    fs::File,
    io::{self, ErrorKind, Read},
};

// fn main() {
//     let f = File::open("hello.txt");
//     println!("Hello, world!");

//     let f = match f {
//         Ok(file) => file,
//         Err(error) => {
//             panic!("Error {:?}", error);
//         }
//     };
// }

// fn main() {
//     let f = File::open("hello.txt");

//     let f = match f {
//         Ok(file) => file,
//         Err(error) => match error.kind() {
//             ErrorKind::NotFound => match File::create("hellow.txt") {
//                 Ok(fc) => fc,
//                 Err(e) => panic!("Error create file:{:?}", e),
//             },
//             other_error => panic!("Error opening the file :{:?}", other_error),
//         },
//     };
// }

// fn main() {
//     let f = File::open("hello2.txt").unwrap_or_else(|error| {
//         if error.kind() == ErrorKind::NotFound {
//             File::create("hellow.txt").unwrap_or_else(|error| {
//                 panic!("Error create file:{:?}", error);
//             })
//         } else {
//             panic!("Error opening the file :{:?}", error)
//         }
//     });
// }

// fn main() {
//     let f = File::open("hello2.txt").unwrap();
// }

// fn main() {
//     let f = File::open("hello2.txt").expect("无法打开文件");
// }

// fn read_username_from_file() -> Result<String, io::Error> {
//     let f = File::open("hello.txt");

//     let mut f = match f {
//         Ok(file) => file,
//         Err(e) => return Err(e),
//     };

//     let mut s = String::new();
//     match f.read_to_string(&mut s) {
//         Ok(_) => Ok(s),
//         Err(e) => Err(e),
//     }
// }

// fn main() {
//     let res = read_username_from_file();
// }

// fn read_username_from_file() -> Result<String, io::Error> {
//     let mut f = File::open("hello.txt")?;

//     let mut s = String::new();

//     f.read_to_string(&mut s)?;

//     Ok(s)
// }

// fn main() {
//     let res = read_username_from_file();
// }

fn read_username_from_file() -> Result<String, io::Error> {
    let mut s = String::new();
    File::open("hello.txt")?.read_to_string(&mut s)?;

    Ok(s)
}

fn main() {
    let res = read_username_from_file();
}
