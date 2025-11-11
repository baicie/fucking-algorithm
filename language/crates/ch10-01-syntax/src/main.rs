// fn main() {
//     let numbers = vec![34, 50, 25, 100, 65];
//     let largest = largest(&numbers);

//     println!("the largest number is {}", largest);
// }

// fn find_largest(arr: Vec<i32>) -> i32 {
//     let mut largest = arr[0];
//     for number in arr {
//         if number > largest {
//             largest = number;
//         }
//     }

//     largest
// }

// fn largest(list: &[i32]) -> i32 {
//     let mut largest = list[0];

//     for &number in list {
//         if number > largest {
//             largest = number;
//         }
//     }

//     largest
// }

// fn largest<T: std::cmp::PartialOrd>(list: &[T]) -> T {
//     let mut largest = list[0];

//     for &number in list {
//         if number > largest {
//             largest = number;
//         }
//     }

//     largest
// }

// fn main() {
//     let numbers = vec![34, 50, 25, 100, 65];
//     let largest = largest(&numbers);

//     println!("the largest number is {}", largest);
// }

// struct Point<T> {
//     x: T,
//     y: T,
// }

// struct Point<T, U> {
//     x: T,
//     y: U,
// }

// fn main() {
//     let int = Point { x: 5, y: 5.5 };
//     let float = Point { x: 1.1, y: 2.2 };
// }

// enum Option<T> {
//     Some(T),
//     None,
// }

// enum Result<T, E> {
//     Ok(T),
//     Err(E),
// }

// fn main() {}

// struct Point<T> {
//     x: T,
//     y: T,
// }

// impl<T> Point<T> {
//     fn x(&self) -> &T {
//         &self.x
//     }
// }

// fn main() {
//     let p = Point { x: 5, y: 10 };

//     println!("{}", p.x());
// }
#[derive(Debug)]
struct Point<T, U> {
    x: T,
    y: U,
}

impl<T, U> Point<T, U> {
    fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
        Point {
            x: self.x,
            y: other.y,
        }
    }
}

fn main() {
    let p1 = Point { x: 5, y: 4 };

    let p2 = Point { x: "hello", y: 'c' };

    let p3 = p1.mixup(p2);

    println!("{:#?}", p3);
}
