// use ch10_02_traits::NewsArticle;
// use ch10_02_traits::Summary;
// use ch10_02_traits::Tweet;

// fn main() {
//     let tweet = Tweet {
//         username: String::from("horse_ebooks"),
//         content: String::from("of course"),
//         reply: false,
//         retweet: false,
//     };

//     let article = NewsArticle {
//         headline: String::from("penguins win the stanley"),
//         contnt: String::from("1111111111111111"),
//         author: String::from("baicie"),
//         location: String::from("beijing"),
//     };

//     println!("Hello, world!{}", tweet.summarize());
//     println!("article, world!{}", article.summarize());
// }

fn largest<T: PartialOrd + Clone>(list: &[T]) -> &T {
    let mut largest = &list[0];

    for number in list.iter() {
        if number > &largest {
            largest = number;
        }
    }

    largest
}

fn main() {
    // let numbers = vec![34, 50, 25, 100, 65];
    // let largest = largest(&numbers);

    // println!("the largest number is {}", largest);

    let str_list = vec![String::from("hellow"), String::from("world")];
    let res = largest(&str_list);

    println!("2. the largest number is {}", res);
}
