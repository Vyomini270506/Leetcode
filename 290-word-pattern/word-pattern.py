class Solution(object):
    def wordPattern(self, pattern, s):

        l1 = list(pattern)
        l2 = s.split()

        d = {}
        e = {}

        n = len(l1)
        m = len(l2)

        if n != m:
            return False

        for i in range(n):
            if l1[i] in d:
                if d[l1[i]] != l2[i]:
                    return False
            else:
                d[l1[i]] = l2[i]

            if l2[i] in e:
                if e[l2[i]] != l1[i]:
                    return False
            else:
                e[l2[i]] = l1[i]

        return True