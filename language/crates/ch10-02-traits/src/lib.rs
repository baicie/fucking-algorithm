use std::fmt::{Debug, Display};

pub trait Summary {
    // fn summarize(&self) -> String;
    fn summarize_auther(&self) -> String;
    fn summarize(&self) -> String {
        // String::from("(read),{}",)
        format!("{}", self.summarize_auther())
    }
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub contnt: String,
}

impl Summary for NewsArticle {
    // fn summarize(&self) -> String {
    //     format!("{},by {} ({})", self.headline, self.author, self.location)
    // }

    fn summarize_auther(&self) -> String {
        format!("@{}", self.author)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }

    fn summarize_auther(&self) -> String {
        format!("^{}", self.username)
    }
}

pub fn notify1(item1: impl Summary, item2: impl Summary) {
    println!("{}", item1.summarize());
}

pub fn notify2(item1: impl Summary + Display) {
    println!("{}", item1.summarize());
}

pub fn notify<T: Summary + Display>(item: T, item2: T) {
    println!("{}", item.summarize());
}

pub fn notify3<T: Summary + Display, U: Clone + Debug>(a: T, b: U) -> String {
    format!("{}", a.summarize())
}

pub fn notify4<T, U>(a: T, b: U) -> String
where
    T: Summary + Display,
    U: Clone + Debug,
{
    format!("{}", a.summarize())
}

// pub fn notify5<T, U>(flag: bool) -> impl Summary {
//     if flag {
//         NewsArticle {
//             headline: String::from("penguins win the stanley"),
//             contnt: String::from("1111111111111111"),
//             author: String::from("baicie"),
//             location: String::from("beijing"),
//         }
//     } else {
//         Tweet {
//             username: String::from("horse_ebooks"),
//             content: String::from("of course"),
//             reply: false,
//             retweet: false,
//         }
//     }
// }
