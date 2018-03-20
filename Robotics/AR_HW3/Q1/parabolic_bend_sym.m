syms ui uf ui_dot uf_dot a_b tf tc k t real 

a_b = k*4*(uf-ui)/tf^2;
u = (0<t & t<tc)*(ui+a_b*t^2/2)+(t>=tc & t<=tf-tc)*(ui+a_b*tc*(t-tc/2))+ ...
            (tf-tc<t & t<=tf)*(uf-a_b*(tf-t)^2/2)

tc = (ui-uf+(uf-ui)/)
