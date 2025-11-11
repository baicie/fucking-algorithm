use std::collections::HashMap;

#[derive(Debug,PartialEq)]
pub enum Method {
    Get,
    Post,
    Uninitialized,
}

impl From<&str> for Method {
    fn from(s: &str) -> Self {
        match s {
            "GET" => Method::Get,
            "POST" => Method::Post,
            _ => Method::Uninitialized,
        }
    }
}

#[derive(Debug,PartialEq)]
pub enum Version {
    V1_1,
    V2_0,
    Uninitialized,
}

impl From<&str> for Version {
    fn from(s: &str) -> Self {
        match s {
            "HTTP/1.1" => Version::V1_1,
            _ => Version::Uninitialized,
        }
    }
    
}

#[derive(Debug,PartialEq)]
pub enum Resurce {
    Path(String),
}

#[derive(Debug, )]
pub struct HttpRequest {
    pub method: Method,
    pub resource: Resurce,
    pub version: Version,
    pub headers: HashMap<String, String>,
    pub msg_body: String,
}


impl From<String> for HttpRequest  {
        fn from(req: String) -> Self {
            let mut parsed_method = Method::Uninitialized;
            let mut parsed_version = Version::V1_1;
            let mut parsed_path = Resurce::Path("".to_string());
            let mut parsed_headers = HashMap::new();
            let mut parsed_msg_body = "";

            for line in req.lines() {
                if line.contains("HTTP") {
                    let (method,resurce,version) = process_req_line(line);
                    parsed_method = method;
                    parsed_path = resurce;
                    parsed_version = version;
                }else if line.contains(":"){
                    let (key, value) = process_header_line(line);
                    parsed_headers.insert(key, value);
                }else if line.len() == 0 {
                    
                }else {
                    parsed_msg_body = line;
                }
            }

            HttpRequest {
                method: parsed_method,
                resource: parsed_path,
                version: parsed_version,
                headers: parsed_headers,
                msg_body: parsed_msg_body.to_string(),
            }
        }
}

fn process_req_line(s:&str) ->  (Method,Resurce,Version) {
    let mut words = s.split_whitespace();
    let method = words.next().unwrap().into();
    let path = Resurce::Path(words.next().unwrap().to_string());
    let version = words.next().unwrap().into();

    (method, path, version)
}

fn process_header_line(s:&str) -> (String, String) { 
    let mut header_items  = s.split(":"); 
    let mut key = String::from("");
    let mut value = String::from("");
    if let Some(k) = header_items.next() {
        key = k.to_string();
    }
    if let Some(v) = header_items.next() {
        value = v.to_string();
    }
    (key, value)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_method_into(){
        let m:Method = "GET".into();
        assert_eq!(m, Method::Get);
    }

    #[test]
    fn test_version_into(){
        let v:Version = "HTTP/1.1".into();
        assert_eq!(v, Version::V1_1);
    }

    #[test]
    fn test_read_http (){
        let s:String = String::from("GET /greeting HTTP/1.1\r\nHost: localhost:3000\r\nUser-Agent: curl/7.68.0\r\nAccept: */*\r\n\r\n");
        let mut headers_expected = HashMap::new();
        headers_expected.insert("Host".into(), " localhost".into());
        headers_expected.insert("Accept".into()," */*".into());
        headers_expected.insert("User-Agent".into()," curl/7.68.0".into());
        let req:HttpRequest = s.into();

        assert_eq!(req.method, Method::Get);
        assert_eq!(req.resource, Resurce::Path("/greeting".to_string()));
        assert_eq!(req.version, Version::V1_1);
        assert_eq!(req.headers, headers_expected);
    }
}