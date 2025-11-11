use actix_web::{error, http::StatusCode, HttpResponse};
use serde::Serialize;
use sqlx::error::Error as SQLxError;
use std::fmt::{self};

#[derive(Debug)]
pub enum AppError {
    DBError(String),
    ActixError(String),
    NotFound(String),
}

#[derive(Debug, Serialize)]
pub struct MyErrorResponse {
    pub error_message: String,
}

impl AppError {
    fn error_response(&self) -> String {
        match self {
            AppError::DBError(msg) => {
                println!("DBError: {}", msg);
                "DBError".to_string()
            }
            AppError::ActixError(msg) => {
                println!("ActixError: {}", msg);
                "ActixError".to_string()
            }
            AppError::NotFound(msg) => {
                println!("NotFound: {}", msg);
                "NotFound".to_string()
            }
        }
    }
}

impl error::ResponseError for AppError {
    fn status_code(&self) -> StatusCode {
        match self {
            AppError::DBError(msg) | AppError::ActixError(msg) => StatusCode::INTERNAL_SERVER_ERROR,
            AppError::NotFound(msg) => StatusCode::NOT_FOUND,
        }
    }
    fn error_response(&self) -> HttpResponse {
        HttpResponse::build(self.status_code()).json(MyErrorResponse {
            error_message: self.error_response(),
        })
    }
}

impl fmt::Display for AppError {
    fn fmt(&self, f: &mut fmt::Formatter) -> Result<(), fmt::Error> {
        write!(f, "{}", self)
    }
}

impl From<actix_web::error::Error> for AppError {
    fn from(err: actix_web::error::Error) -> Self {
        AppError::ActixError(err.to_string())
    }
}

impl From<SQLxError> for AppError {
    fn from(err: SQLxError) -> Self {
        AppError::DBError(err.to_string())
    }
}
