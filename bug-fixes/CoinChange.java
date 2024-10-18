import java.util.*;

public class CoinChange {

    public int coinChange(int[] coins, int amount) {
        if (amount < 1) return 0; // If the amount is 0 or negative, no coins are needed.

        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0; // Base case: 0 coins needed for amount 0

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
}
