function du = my2ndode(t,u,a)
du = [u(2); -a/16*u(2)-145/16*u(1)];