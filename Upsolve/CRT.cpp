const int N = 20;
lint GCD(lint a, lint b) { return (b == 0) ? a : GCD(b, a % b); }
inline lint LCM(lint a, lint b) { return a / GCD(a, b) * b; }
inline lint normalize(lint x, llint mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { lint x, y, d; };
GCD_type ex_GCD(lint a, lint b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
lint a[N], n[N], ans, lcm;
pair<lint, lint> crt(t, lint a[N], lint n[N]) //1-indexed O(Tlog(LCM(ni)))
{ //Need not be coprime
    for(int i = 1; i <= t; i++) normalize(a[i], n[i]);
    ans = a[1], lcm = n[1];
    for(int i = 2; i <= t; i++)
    {
        auto pom = ex_GCD(lcm, n[i]);
        int x1 = pom.x, d = pom.d;
        if((a[i] - ans) % d != 0)   //NO SOLUTIONS
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
        lcm = LCM(lcm, n[i]);
    }
    return {ans, lcm};
}