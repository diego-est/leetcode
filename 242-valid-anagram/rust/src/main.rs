fn main() {
    println!("Hello, world!");
}

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut alphabet: [i32; 26] = [0; 26];
        for ch in s.chars() {
            alphabet[(ch as u32 - 97) as usize] += 1;
        }
        for ch in t.chars() {
            alphabet[(ch as u32 - 97) as usize] -= 1;
        }
        alphabet == [0; 26]
    }
}
