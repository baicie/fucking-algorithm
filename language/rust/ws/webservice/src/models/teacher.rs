use actix_web::web;
use serde::{Deserialize, Serialize};

#[derive(Debug, Serialize, Deserialize, Clone)]
pub struct Teacher {
    pub id: i32,
    pub name: String,
    pub picture_url: String,
    pub profile: String,
}

#[derive(Debug, Deserialize, Clone)]
pub struct CreateTeacher {
    pub name: String,
    pub picture_url: String,
    pub profile: String,
}
