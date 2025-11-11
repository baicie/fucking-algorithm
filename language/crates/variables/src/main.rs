// fn main() {
//     println!("Hello, world!");
//     let mut x = 5;
//     println!("the value is {x}");

//     x = 6;
//     println!("the value is {x}");
// }

// fn main() {
//     let x = 5;
//     let x = x + 1;
//     {
//         let x = x * 2;
//         println!("the value1 is {x}");
//     }

//     println!("the value2 is {x}");
// }

// fn main() {
//     let mut conut = 0;
//     'conuting_up: loop {
//         println!("count = {conut}");
//         let mut remaining = 10;
//         loop {
//             println!("remainig = {remaining}");
//             if remaining == 9 {
//                 break;
//             }
//             if conut == 2 {
//                 break 'conuting_up;
//             }

//             remaining -= 1;
//         }
//         conut += 1;
//     }
//     println!("End count = {conut}");
// }

// fn main() {
//     let mut number = 3;
//     while number != 0 {
//         println!("{number}");
//         number -= 1;
//     }

//     println!("结束？")
// }

// fn main() {
//     let a = [10, 20, 30, 40, 50];
//     let mut index = 0;

//     while index < 5 {
//         println!("the vbalue is:{}", a[index]);

//         index += 1;
//     }
// }

// fn main() {
//     let a = [10, 20, 30, 40, 50];

//     for element in a {
//         println!("the value is: {element}");
//     }
// }

fn main() {
    for number in (1..4).rev() {
        println!("{number}!");
    }

    println!("LIFTOFF!!!");
}
