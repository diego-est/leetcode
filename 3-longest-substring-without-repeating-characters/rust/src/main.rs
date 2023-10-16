fn main() {
    println!("Hello, world!");
}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut substr = std::collections::VecDeque::new();
        let mut res = 0;
        for ch in s.chars() {
            while substr.contains(&ch) {
                substr.pop_front();
            }
            substr.push_back(ch);
            res = core::cmp::max(res, substr.len());
        }
        res as i32
    }
}
