# @param {String} s
# @return {Integer}

# Input: "226"
# Output: 3
# Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

def num_decodings(s)
    return 0 if s.empty? || (s.size > 1 && s[0] == '0')
    dp = Array.new(s.size+1, 0)
    dp[0] = 1
    for i in 1...dp.size
        dp[i] = s[i-1] == '0' ? 0 : dp[i-1]
        if i > 1 && ( s[i-2] == '1' || (s[i-2] == '2' && s[i-1].to_i <= 6) )
            dp[i] += dp[i-2]
        end
    end

    dp.last
end

s = "226"
puts num_decodings(s)