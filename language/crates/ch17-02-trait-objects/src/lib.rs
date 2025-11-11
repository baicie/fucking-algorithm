// pub trait Draw {
//     fn draw(&self);
// }

// pub struct Screen {
//   pub components: Vec<Box<dyn Draw>>,
// }

// impl Screen {
//     pub fn run(&self){
//       for component in self.components.iter() {
//         component.draw();
//       }
//     }
// }

pub trait Draw {
    fn draw(&self);
}

pub struct Screen<T: Draw> {
    pub components: Vec<T>,
}

impl<T> Screen<T>
where
    T: Draw,
{
    pub fn run(&self) {
        for component in self.components.iter() {
            component.draw();
        }
    }
}
