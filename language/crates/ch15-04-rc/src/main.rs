use crate::List::{Cons, Nil};
use std::rc::Rc;

#[derive(Debug)]
enum List {
    Cons(i32, Rc<List>),
    Nil,
}

fn main() {
    // let b = Box::new(5);
    // println!("{}", b);

    let a = Rc::new(Cons(5, Rc::new(Cons(10, Rc::new(Nil)))));

    let b = Cons(3, Rc::clone(&a));
    println!("b= {}", Rc::strong_count(&a));

    {
        let c = Cons(4, Rc::clone(&a));
        println!("c= {}", Rc::strong_count(&a));
    }
    println!("sope ={}", Rc::strong_count(&a));
}
