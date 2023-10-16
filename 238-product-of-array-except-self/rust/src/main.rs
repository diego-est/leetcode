fn main() {
    println!("Hello, world!");
}

impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut out = Vec::new();
        let mut lhs = 1;
        let mut rhs = 1;

        for i in 0..nums.len() {
            out.push(lhs);
            lhs *= nums[i];
        }
        
        for i in (0..nums.len()).rev() {
            out[i] *= rhs;
            rhs *= nums[i];
        }

        out
    }
}
