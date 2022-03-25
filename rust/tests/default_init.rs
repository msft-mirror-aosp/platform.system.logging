#[test]
fn default_init() {
    assert!(logger::init(Default::default()));

    if cfg!(target_os = "android") {
        // android_logger has default log level "off"
        assert_eq!(log::max_level(), log::LevelFilter::Off);
    } else {
        // env_logger has default log level "error"
        assert_eq!(log::max_level(), log::LevelFilter::Error);
    }
}