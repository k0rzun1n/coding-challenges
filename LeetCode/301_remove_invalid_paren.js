let cc = console.log;

var removeInvalidParentheses = function (s) {
    const len = s.length;  // 1 <= s.length <= 25
    if (len == 0) return [];
    let az_mask = 0;
    let skip_mask = 0;  // skip mask
    for (let i = 0; i < len; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            az_mask |= 1 << i;
    um = {};
    let rm_count_min = Number.MAX_SAFE_INTEGER;
    for (let i = 0; i < (1 << len); i++) {
        if (i & az_mask) continue;
        if (isValid(s, i | az_mask)) {
            let s_masked = "";
            for (let j = 0; j < len; j++) {
                if ((1 << j) & i) continue;
                s_masked += s[j];
            }
            let rm_count = countSetBits(i);
            if (rm_count > rm_count_min) continue;
            rm_count_min = Math.min(rm_count_min, rm_count);
            um[s_masked] = rm_count;
        }
    }
    let res = [];
    for (p of Object.entries(um))
        if (p[1] == rm_count_min)
            res.push(p[0]);

    return res;
}
function countSetBits(n) {
    let count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
function bitCount (n) {
    n = n - ((n >> 1) & 0x55555555)
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333)
    return ((n + (n >> 4) & 0xF0F0F0F) * 0x1010101) >> 24
  }
  

function isValid(s, mask) {
    stk = [];
    let top = -1;
    for (let i = 0; i < s.length; i++) {
        if ((1 << i) & mask) continue;
        let c = s[i];
        if (top != -1 && stk[top]=="(" && c==")")
            top--;
        else
            stk[++top] = c;
    }
    return top == -1;
};

let v = removeInvalidParentheses("((()))a)");
cc(v);