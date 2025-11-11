mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
        fn some_function() {}
    }
}

// 绝对路径
pub use crate::front_of_house::hosting;
// use front_of_house::hosting;

pub fn eat_at_restaurant() {
    hosting::add_to_waitlist();
}
