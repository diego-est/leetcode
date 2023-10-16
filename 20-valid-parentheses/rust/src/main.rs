fn main() {
    println!("Hello, world!");
}

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut chvec = Vec::new();
        #[derive(PartialEq)]
        enum Parens {
            Clamp,
            Parenthesis,
            Bracket,
        }
        for ch in s.chars() {
            match ch {
                '(' => chvec.push(Parens::Parenthesis),
                '{' => chvec.push(Parens::Bracket),
                '[' => chvec.push(Parens::Clamp),
                ')' => if chvec.pop() == Some(Parens::Parenthesis) { continue } else { return false; },
                '}' => if chvec.pop() == Some(Parens::Bracket) { continue } else { return false; },
                ']' => if chvec.pop() == Some(Parens::Clamp) { continue } else { return false; },
                _ => unreachable!(),
            }
        }

        return chvec.is_empty();
    }
}
