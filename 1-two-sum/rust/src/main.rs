fn main() {
    println!("Hello, world!");
}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        use std::collections::HashMap;
        let mut map: HashMap<i32, usize> = HashMap::new();
        for (index, item) in nums.iter().enumerate() {
            map.insert(*item, index);
        }

        for (index, item) in nums.iter().enumerate() {
            let complement = target - *item;
            if map.contains_key(&complement) && *map.get(&complement).unwrap() != index {
                return vec![index as i32, *map.get(&complement).unwrap() as i32]
            }
        }
        unreachable!();
    }
}
