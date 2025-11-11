// struct User {
//     active: bool,
//     username: String,
//     email: String,
//     sign_in_count: u64,
// }

struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

struct AlwaysEqual;

fn main() {
    // let mut user1 = User {
    //     active: false,
    //     username: String::from("user1"),
    //     email: String::from("user1@example.com"),
    //     sign_in_count: 1,
    // };

    // user1.sign_in_count += 1;

    // let user2 = User {
    //     active: user1.active,
    //     username: user1.username,
    //     email: String::from("2.com"),
    //     sign_in_count: user1.sign_in_count,
    // };

    // let user2 = User {
    //     email: String::from("3.com"),
    //     ..user2
    // };

    // println!("{:?}", user1)

    let _black = Color(0, 0, 0);
    let _oigin = Point(0, 0, 0);
    let _subject = AlwaysEqual;
}

// fn build_user(email: String, username: String) -> User {
//     User {
//         active: true,
//         username,
//         email,
//         sign_in_count: 1,
//     }
// }
