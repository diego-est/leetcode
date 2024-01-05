use std::collections::HashMap;

fn min_operations(nums: Vec<i32>) -> i32 {
    let mut counts: HashMap<i32, i32> = HashMap::new();

    for &num in &nums {
        if let std::collections::hash_map::Entry::Vacant(e) = counts.entry(num) {
            e.insert(1);
        } else {
            *counts.get_mut(&num).expect("Already checked if map contains key") += 1;
        }
    }

    let mut b = false;
    counts.into_iter().fold(0i32, |acc, (_, count)| {
        b |= count == 1;
        if !b {
            acc + (count as f32 / 3.0).ceil() as i32
        } else {
            -1
        }
    })
}

fn main() {
    let nums1 = vec![2,3,3,2,2,4,2,3,4];
    let nums2 = vec![2,1,2,2,3,3];
    println!("nums1: {}", min_operations(nums1));
    println!("nums2: {}", min_operations(nums2));
}
