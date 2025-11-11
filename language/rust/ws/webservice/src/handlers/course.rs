use crate::error::AppError;
use crate::models::course::UpdateCourse;
use crate::state::AppState;
use crate::{dbaccess::course::*, models::course::CreateCourse};
use actix_web::{web, HttpResponse};

pub async fn post_new_course(
    new_course: web::Json<CreateCourse>,
    app_state: web::Data<AppState>,
) -> Result<HttpResponse, AppError> {
    post_new_course_db(&app_state.db, new_course.try_into()?)
        .await
        .map(|course| HttpResponse::Ok().json(course))
}

pub async fn get_courses_for_teacher(
    app_state: web::Data<AppState>,
    params: web::Path<i32>,
) -> Result<HttpResponse, AppError> {
    let teacher_id = params.into_inner();
    get_courses_for_teacher_db(&app_state.db, teacher_id)
        .await
        .map(|courses| HttpResponse::Ok().json(courses))
}

pub async fn get_course_by_id(
    app_state: web::Data<AppState>,
    params: web::Path<(i32, i32)>,
) -> Result<HttpResponse, AppError> {
    let (teacher_id, course_id) = params.into_inner();
    get_course_details_db(&app_state.db, teacher_id, course_id)
        .await
        .map(|course| HttpResponse::Ok().json(course))
}

pub async fn delete_course(
    app_state: web::Data<AppState>,
    params: web::Path<(i32, i32)>,
) -> Result<HttpResponse, AppError> {
    let (teacher_id, course_id) = params.into_inner();
    delete_course_db(&app_state.db, teacher_id, course_id)
        .await
        .map(|resp| HttpResponse::Ok().json(resp))
}

pub async fn update_course_details(
    app_state: web::Data<AppState>,
    params: web::Path<(i32, i32)>,
    course: web::Json<UpdateCourse>,
) -> Result<HttpResponse, AppError> {
    let (teacher_id, course_id) = params.into_inner();
    update_course_details_db(&app_state.db, teacher_id, course_id, course.into())
        .await
        .map(|resp| HttpResponse::Ok().json(resp))
}

#[cfg(test)]
mod tests {
    use crate::models::course::UpdateCourse;

    use super::*;
    use actix_web::http::StatusCode;
    use actix_web::ResponseError;
    use dotenv::dotenv;
    use sqlx::mysql::MySqlPoolOptions;
    use std::env;
    use std::sync::Mutex;

    #[actix_rt::test]
    async fn post_course_test() {
        dotenv().ok();
        let db_url = env::var("DATABASE_URL").expect("DATABASE_URL must be set");
        let dd_pool = MySqlPoolOptions::new().connect(&db_url).await.unwrap();
        let app_state: web::Data<AppState> = web::Data::new(AppState {
            health_check_response: "".to_string(),
            visit_count: Mutex::new(0),
            db: dd_pool,
        });
        let course = web::Json(CreateCourse {
            teacher_id: 1,
            name: "Test Course".to_string(),
            description: Some("Test Description".to_string()),
            format: None,
            structure: None,
            duration: None,
            price: None,
            language: Some("English".to_string()),
            level: None,
        });
        let resp = post_new_course(course, app_state).await.unwrap();
        assert_eq!(resp.status(), StatusCode::OK);
    }

    #[actix_rt::test]
    async fn get_all_courses_success() {
        dotenv().ok();
        let db_url = env::var("DATABASE_URL").expect("DATABASE_URL must be set");
        let dd_pool = MySqlPoolOptions::new().connect(&db_url).await.unwrap();
        let app_state: web::Data<AppState> = web::Data::new(AppState {
            health_check_response: "".to_string(),
            visit_count: Mutex::new(0),
            db: dd_pool,
        });

        let teacher_id: web::Path<i32> = web::Path::from(1);
        let resp = get_courses_for_teacher(app_state, teacher_id)
            .await
            .unwrap();
        assert_eq!(resp.status(), StatusCode::OK);
    }

    #[actix_rt::test]
    async fn get_course_by_id_test() {
        dotenv().ok();
        let db_url = env::var("DATABASE_URL").expect("DATABASE_URL must be set");
        let dd_pool = MySqlPoolOptions::new().connect(&db_url).await.unwrap();
        let app_state: web::Data<AppState> = web::Data::new(AppState {
            health_check_response: "".to_string(),
            visit_count: Mutex::new(0),
            db: dd_pool,
        });

        let params = web::Path::from((89, 2));
        let resp = get_course_by_id(app_state, params).await.unwrap();
        assert_eq!(resp.status(), StatusCode::OK);
    }

    #[actix_rt::test]
    async fn get_course_failure() {
        dotenv().ok();
        let db_url = env::var("DATABASE_URL").expect("DATABASE_URL must be set");
        let dd_pool = MySqlPoolOptions::new().connect(&db_url).await.unwrap();
        let app_state: web::Data<AppState> = web::Data::new(AppState {
            health_check_response: "".to_string(),
            visit_count: Mutex::new(0),
            db: dd_pool,
        });

        let params = web::Path::from((100, 1));
        let resp = get_course_by_id(app_state, params).await;

        match resp {
            Ok(_) => println!("Test failed"),
            Err(e) => assert_eq!(e.status_code(), StatusCode::NOT_FOUND),
        }
    }

    #[actix_rt::test]
    async fn update_course_success() {
        dotenv().ok();
        let db_url = env::var("DATABASE_URL").expect("DATABASE_URL must be set");
        let dd_pool = MySqlPoolOptions::new().connect(&db_url).await.unwrap();
        let app_state: web::Data<AppState> = web::Data::new(AppState {
            health_check_response: "".to_string(),
            visit_count: Mutex::new(0),
            db: dd_pool,
        });
        let update_course = UpdateCourse {
            name: Some("Updated Course".to_string()),
            description: Some("Updated Description".to_string()),
            format: None,
            structure: None,
            duration: None,
            price: None,
            language: Some("chinese".to_string()),
            level: Some("Intermediate".to_string()),
        };
        let params = web::Path::from((889, 1));
        let update_param = web::Json(update_course);
        let resp = update_course_details(app_state, params, update_param)
            .await
            .unwrap();
        assert_eq!(resp.status(), StatusCode::OK);
    }

    #[actix_rt::test]
    async fn delete_course_success() {
        dotenv().ok();
        let db_url = env::var("DATABASE_URL").expect("DATABASE_URL must be set");
        let dd_pool = MySqlPoolOptions::new().connect(&db_url).await.unwrap();
        let app_state: web::Data<AppState> = web::Data::new(AppState {
            health_check_response: "".to_string(),
            visit_count: Mutex::new(0),
            db: dd_pool,
        });
        let paeams = web::Path::from((1, 3));
        let resp = delete_course(app_state, paeams).await.unwrap();
        assert_eq!(resp.status(), StatusCode::OK);
    }

    #[actix_rt::test]
    async fn delete_course_failure() {
        dotenv().ok();
        let db_url = env::var("DATABASE_URL").expect("DATABASE_URL must be set");
        let dd_pool = MySqlPoolOptions::new().connect(&db_url).await.unwrap();
        let app_state: web::Data<AppState> = web::Data::new(AppState {
            health_check_response: "".to_string(),
            visit_count: Mutex::new(0),
            db: dd_pool,
        });
        let paeams = web::Path::from((1, 100));
        let resp = delete_course(app_state, paeams).await;
        match resp {
            Ok(_) => println!("Test failed"),
            Err(e) => assert_eq!(e.status_code(), StatusCode::NOT_FOUND),
        }
    }
}
