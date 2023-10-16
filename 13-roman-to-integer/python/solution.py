class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = {}
        m["I"] = 1
        m["V"] = 5
        m["X"] = 10
        m["L"] = 50
        m["C"] = 100
        m["D"] = 500
        m["M"] = 1000

        acc = 0
        ps = 1001
        for c in s:
            v = m[c]
            if ps < v:
                acc -= 2 * ps
            acc += v
            ps = v
        return acc

