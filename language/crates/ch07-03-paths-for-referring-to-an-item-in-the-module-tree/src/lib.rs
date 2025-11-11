fn server_order() {}

mod back_of_house {
    // fn fix_incorrect_order() {
    //     cook_order();
    //     super::server_order();
    // }

    // fn cook_order() {}

    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    pub enum Appetizer {
        Soup,
        Salad,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }
}

pub fn eat_at_restaurant() {
    let mut meal = back_of_house::Breakfast::summer("Bye");
    meal.toast = String::from("Wheat");
    println!("i'd like {} toast pleace", meal.toast);
    // meal
}
