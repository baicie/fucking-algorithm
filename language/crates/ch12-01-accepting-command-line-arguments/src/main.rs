use ch12_01_accepting_command_line_arguments::Config;
use std::env;
use std::process;

fn main() {
    let config = Config::new(env::args()).unwrap_or_else(|err| {
        eprintln!("config err :{}", err);
        process::exit(1);
    });

    if let Err(err) = ch12_01_accepting_command_line_arguments::run(config) {
        eprintln!("run err :{}", err);
        process::exit(1);
    }
}
