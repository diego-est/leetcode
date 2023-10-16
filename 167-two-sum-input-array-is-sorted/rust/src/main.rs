fn main() {
    println!("Hello, world!");
}

impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..numbers.len() {
            if let Ok(comp) = numbers.binary_search(&(target - numbers[i])) {
                match comp == i {
                    true => return vec![i as i32 + 1, comp as i32 + 2],
                    false => return vec![i as i32 + 1, comp as i32 + 1],
                }
            }
        }
        unreachable!();
    }
}
