fn main() {
    println!("Hello, world!");
}

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        use std::collections::HashMap;
        let mut anagram_map: HashMap<Vec<char>, Vec<String>> = HashMap::new();

        for string in strs {
            let mut chvec: Vec<char> = string.chars().collect();
            chvec.sort_unstable();

            if let Some(string_vec) = anagram_map.get_mut(&chvec) {
                string_vec.push(string);
            } else {
                anagram_map.insert(chvec, vec![string]);
            }
        }

        let mut res = Vec::new();
        for pair in anagram_map {
            res.push(pair.1);
        }
        res
    }
}
