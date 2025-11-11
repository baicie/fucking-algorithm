// fn main() {
//     // let mut s = String::new();

//     let data = "initial contents";
//     let s = data.to_string();

//     let s1 = "initial contents".to_string();
// }

// fn main() {
//     let s = String::from("initial contents");

//     println!("{}", s);
// }

// fn main() {
//     let hello = String::from("السلام عليكم");
//     let hello = String::from("Dobrý den");
//     let hello = String::from("Hello");
//     let hello = String::from("שָׁלוֹם");
//     let hello = String::from("नमस्ते");
//     let hello = String::from("こんにちは");
//     let hello = String::from("안녕하세요");
//     let hello = String::from("你好");
//     let hello = String::from("Olá");
//     let hello = String::from("Здравствуйте");
//     let hello = String::from("Hola");
// }

// fn main() {
//     let mut s = String::from("foo");
//     let s1 = String::from("demo");
//     s.push_str(&s1);

//     println!("{},{}", s1, s);
// }

// fn main() {
//     let mut s = String::from("foo");
//     let s1 = String::from("demo");
//     s.push('l');

//     println!("{},{}", s1, s);
// }

// fn main() {
//     let s = String::from("foo");
//     let s1 = String::from("demo");

//     let s3 = s1 + &s;

//     println!("{}", s3);
//     println!("{}", s1);
//     println!("{}", s);
// }

// fn main() {
//     let s1 = String::from("foo");
//     let s2 = String::from("demo");
//     let s3 = String::from("bar");

//     let s = format!("{}-{}-{}", s1, s2, s3);
//     println!("{}", s);
// }

// fn main() {
//     let s = String::from("Здравствуйте").len();

//     println!("{}", s);
// }

// fn main() {
//     let s = String::from("Здравствуйте");

//     // println!("{}", s);
//     for b in s.bytes() {
//         println!("{}", b);
//     }
// }

// fn main() {
//     let s = String::from("Здравствуйте");

//     // println!("{}", s);
//     for b in s.chars() {
//         println!("{}", b);
//     }
// }

fn main() {
    let s = String::from("Здравствуйте");

    let hellow = &s[0..4];
    println!("{}", hellow);
}
