import numpy as np
import matplotlib.pyplot as plt

# ---------- HARDCODED SETTINGS ---------------
m, n = 30, 20
coeff_file = "data/coefficients3020.csv"
out_name = "plots/fit_3020"
ylim = (-10, 8)
# ---------------------------------------------

c = np.loadtxt(coeff_file)

x = np.linspace(0, 3 * np.pi, m)
y = x * np.cos(x)
xg = np.linspace(0, 3 * np.pi, 300)
fit = np.polyval(c[::-1], xg)

fig, ax = plt.subplots(figsize=(6, 4.5))
ax.plot(x, y, "o", mfc="none", mec="black", ms=8, label="input data")
ax.plot(xg, xg * np.cos(xg), "-", color="black", lw=0.8, label="x*cos(x)")
ax.plot(xg, fit, ".", color="red", ms=4, label="fit")

ax.set_xlabel("x")
ax.set_ylabel("y(x)")
ax.set_title(f"m = {m},  n = {n}")
ax.set_xlim(0, 10)
ax.set_ylim(*ylim)
ax.legend(loc="upper left")
ax.grid(alpha=0.3)

fig.savefig(out_name + ".png", dpi=200, bbox_inches="tight")
fig.savefig(out_name + ".pdf", bbox_inches="tight")