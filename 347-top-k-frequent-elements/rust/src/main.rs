fn main() {
    println!("Hello, world!");
}

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        use std::collections::HashMap;
        let mut mp = HashMap::new();
        for num in nums {
            if let Some(occurences) = mp.get_mut(&num) {
                *occurences += 1;
            } else {
                mp.insert(num, 1);
            }
        }

        let mut pair_vec: Vec<(i32, &i32)> = mp.iter().map(|(a, b)| (a.to_owned(), b)).collect();
        pair_vec.sort_unstable_by(|a, b| b.1.cmp(a.1));
        pair_vec.truncate(k as usize);
        pair_vec.iter().map(|a| a.0).collect::<Vec<i32>>()
    }
}
