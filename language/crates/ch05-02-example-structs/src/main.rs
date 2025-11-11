// fn main() {
//     let width1 = 30;
//     let height1 = 50;

//     println!("area is {} sdasda", area(width1, height1));
// }

// fn area(width: u32, height: u32) -> u32 {
//     width * height
// }

// fn main() {
//     let rect1 = (30, 50);

//     println!("area is {}", area(rect1));
// }

// fn area(dimensions: (u32, u32)) -> u32 {
//     dimensions.0 * dimensions.1
// }
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 41,
    };

    println!("3. the area is {}", area(&rect1));
    // println!("rect1 is {:#?}", rect1);
    dbg!(&rect1);
}

fn area(rectangle: &Rectangle) -> u32 {
    rectangle.width * rectangle.height
}
