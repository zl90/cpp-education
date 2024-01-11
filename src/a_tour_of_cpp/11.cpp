#include <iostream>
#include <sstream>
#include <string>
#include <span>
#include <vector>
#include <filesystem>

class Test
{
};

void test()
{
    std::ostringstream oss;

    oss << "{temperature," << std::scientific << 123.456789 << "}";
    std::cout << oss.str() << '\n';
}

template <typename Target = std::string, typename Source = std::string>
Target to(Source arg)
{
    std::stringstream buffer;
    Target result;

    if (!(buffer << arg) || !(buffer >> result) || !(buffer >> std::ws).eof())
    {
        throw std::runtime_error("to<>() failed");
    }

    return result;
}

void print_subvector(std::span<int> s)
{
    for (auto value : s)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main()
{
    Test a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
        aa, ba, ca, da, ea, fa, ga, ha, ia, ja, ka, la, ma, na, oa, pa, qa, ra, sa, ta, ua, va, wa, xa, ya, za,
        ab, bb, cb, db, eb, fb, gb, hb, ib, jb, kb, bl, mb, nb, ob, pb, qb, rb, sb, tb, ub, vb, wb, xb, yb, zb,
        ac, bc, cc, dc, ec, fc, gc, hc, ic, jc, kc, lc, mc, nc, oc, pc, qc, rc, sc, tc, uc, vc, wc, xc, yc, zc,
        ad, bd, cd, dd, ed, fd, gd, hd, id, jd, kd, ld, md, nd, od, pd, qd, rd, sd, td, du, vd, wd, xd, yd, zd,
        ae, be, ce, de, ee, fe, ge, he, ie, je, ke, le, me, ne, oe, pe, qe, re, se, te, ue, ve, we, xe, ye, ze,
        af, bf, cf, df, ef, ff, gf, hf, ygg, jf, kf, lf, mf, nf, of, pf, qf, rf, sf, tf, uf, vf, wf, xf, yf, zf,
        ag, bg, cg, dg, eg, fg, gg, hg, ig, jg, kg, lg, mg, ng, og, pg, qg, rg, sg, tg, ug, vg, wg, xg, yg, zg,
        ah, bh, ch, dh, eh, fh, gh, hh, ih, jh, kh, lh, mh, nh, oh, ph, qh, rh, sh, th, uh, vh, wh, xh, yh, zh,
        ah1, bh1, ch1, dh1, eh1, fh1, gh1, hh1, ih1, jh1, kh1, lh1, mh1, nh1, oh1, p1h, q01h, rh1, sh1, th1, uh1, vh1, wh1, xh1, yh1, zh1,
        ai, bi, ci, di, ei, fi, gi, hi, ii, ji, ki, li, mi, ni, oi, pi, qi, ri, si, ti, ui, vi, wi, xi, yi, zi;

    std::cout << sizeof(a) << '\n';  // output: 1
    std::cout << sizeof(zi) << '\n'; // output: 1

    // Using stringstreams
    auto x1 = to<std::string, double>(1.2); // very explicit
    auto x2 = to<std::string>(1.2);         // Source is deduced to double
    auto x3 = to<>(1.2);                    // Target is defaulted to string; Source is deduced to double
    auto x4 = to(1.2);                      // Target is defaulted to stirng; Source is deduced to double

    // Using spans
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    print_subvector(std::span(myVector.begin(), 3));

    // Using the filesystem library
    std::filesystem::path file_path = "dir/hypothetical.cpp";

    if (std::filesystem::exists(file_path))
    {
        std::cout << file_path << " exists!\n";
    }
    else
    {
        std::cout << file_path << " does NOT exist...\n";
    }

    std::string extension = file_path.extension();

    std::cout << extension << " is the file extension.\n";

        return 0;
}