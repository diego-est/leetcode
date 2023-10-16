fn main() {
    println!("Hello, world!");
}

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let str = s.replace(|c: char| !c.is_alphanumeric(), "");
        str.chars().rev().collect::<String>().eq_ignore_ascii_case(&str)
    }
}
