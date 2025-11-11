use std::collections::HashMap;
// fn main() {
//     let mut map = HashMap::new();

//     map.insert(String::from("back"), 10);
//     map.insert(String::from("back2"), 50);

//     println!("Hello, world!");
// }

// fn main() {
//     let teams = vec![String::from("one"), String::from("two")];
//     let scores = vec![10, 50];

//     let map: HashMap<_, _> = teams.iter().zip(scores.iter()).collect();
// }

// fn main() {
//     let one = String::from("one");
//     let two = String::from("two");

//     let mut map = HashMap::new();
//     map.insert(&one, &two);

//     println!("{}:{}", one, two);
// }

// fn main() {
//     let mut map = HashMap::new();

//     map.insert(String::from("one"), 10);
//     map.insert(String::from("two"), 20);

//     let key = String::from("one1");
//     let score = map.get(&key);

//     match score {
//         Some(s) => println!("{}", s),
//         None => println!("not exist"),
//     }
// }

// fn main() {
//     let mut map = HashMap::new();

//     map.insert(String::from("one"), 10);
//     map.insert(String::from("two"), 20);

//     for (k, v) in &map {
//         println!("{}:{}", k, v);
//     }
// }

// fn main() {
//     let mut map = HashMap::new();

//     map.insert(String::from("one"), 10);
//     map.insert(String::from("one"), 20);

//     println!("{:?}", map);
// }

// fn main() {
//     let mut map = HashMap::new();

//     map.insert(String::from("one"), 10);
//     map.entry(String::from("two")).or_insert(50);
//     map.entry(String::from("one")).or_insert(40);

//     println!("{:?}", map);
// }

// fn main() {
//     let mut map = HashMap::new();

//     map.insert(String::from("one"), 10);
//     map.entry(String::from("two")).or_insert(50);
//     map.entry(String::from("one")).or_insert(40);

//     println!("{:?}", map);
// }

fn main() {
    let text = "helow world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }

    println!("{:#?}", map);
}
