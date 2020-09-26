clc; clear all;
%% dane
syms Ks Kw Kg % wspolczynniki
syms P MTw % z drugiego rownania
% zakomentowac / odkomentowac
% syms rop cpp
% P = rop*cpp*Fp0;
% MTw = Kg + Kw + P;


%% warunki poczatkowe
syms Tg0 Ts0 Twew0 Tzew0 Qg0 Fp0 % do warunkow poczatkowych

% Twew0 = (Kg*Tg0 + Kw*Ts0 + P*Tzew0)/MTw; % wyliczone z drugiego rownania

wp1 = Tg0 == Qg0/Kg + Twew0;
wp2 = Ts0 == (Kw*Twew0 + Ks*Tzew0)/(Kw + Ks);
wp3 = Twew0 == (Kg*Tg0 + Kw*Ts0 + P*Tzew0)/MTw;

[Tg0 , Ts0, Twew0] = solve([wp1, wp2, wp3], [Tg0, Ts0, Twew0]); % warunki poczatkowe

%% rownania stanu
syms Tg Ts Tw Tz Qg Fp % wejscia i wyjscia
syms TG TS % pochodne
syms Cvp Cvg Cvs % pojemnosci cieplne
syms m1 m2 % mianowniki

% m1 = Cvg*MTw; % mianownik 1
% m2= Cvs*MTw; % mianownik 2

Tw = (Kg*Tg + Kw*Ts + P*Tz)/MTw;  % z drugiego rownania

rown1 = Cvg * TG == Qg - Kg * (Tg - Tw);
rown2 = Cvs * TS == Kw * (Tw - Ts) - Ks * (Ts - Tz);

[wynik1, wynik2] = solve([rown1, rown2], [TG, TS]);

[l1, mi1] = numden(wynik1);
[l2, mi2] = numden(wynik2);

m1 = subs(mi1, Cvg*MTw, m1);
m2 = subs(mi2, Cvs*MTw, m2);

% macierz A
% element macierzy A11 (dla Tg)
A11 = subs(l1, {Tg, Ts, Tz, Qg}, {1, 0, 0, 0})/m1;
% element macierzy A12 (dla Ts)
A12 = subs(l1, {Tg, Ts, Tz, Qg}, {0, 1, 0, 0})/m1;
% element macierzy A21 (dla Tg)
A21 = subs(l2, {Tg, Ts, Tz, Qg}, {1, 0, 0, 0})/m2;
% element macierzy A22 (dla Ts)
A22 = subs(l2, {Tg, Ts, Tz, Qg}, {0, 1, 0, 0})/m2;

% macierz B
% element macierzy A11 (dla Qg)
B11 = subs(l1, {Tg, Ts, Tz, Qg}, {0, 0, 0, 1})/m1;
% element macierzy A12 (dla Tz)
B12 = subs(l1, {Tg, Ts, Tz, Qg}, {0, 0, 1, 0})/m1;
% element macierzy A21 (dla Qg)
B21 = subs(l2, {Tg, Ts, Tz, Qg}, {0, 0, 0, 1})/m2;
% element macierzy A22 (dla Tz)
B22 = subs(l2, {Tg, Ts, Tz, Qg}, {0, 0, 1, 0})/m2;




%% transmitancje
syms s; % zmienna s
syms Tw;
syms MT1 MT2 MT3;
%{




rown1s = Cvg*Tg*s == Qg - Kg*(Tg - Tw);
rown2s = 0 == Kg*(Tg - Tw) - Kw*(Tw - Ts) - P*(Tw - Tz);
rown3s = Cvs*Ts*s == Kw*(Tw - Ts) - Ks*(Ts - Tz);

%}

MT1 = Cvg * s + Kg;
MT2 = Cvs *s + Kw + Ks;
MT3 = Kw + Kg + P;

rown1s = Tg == (Qg + Kg* Tw)/(MT1) ; 
rown2s = Ts == (Kw*Tw + Ks* Tz)/(MT2); 
rown3s = Tw == (Kg*Tg   + Kw*Ts  + P*Tz)/(MT3);


[tran1, tran2, tran3] = solve([rown1s, rown2s, rown3s], [Tg, Ts, Tw]);

% obieranie transmitancji
% rozdzielenie licznika od mianownika
[L1, M1] = numden(tran1);
[L2, M2] = numden(tran2);
[L3, M3] = numden(tran3);

% funkcja coeffs zwraca wspolczynniki stajace przy s w postaci wektora
% funkcja fliprl zamienia kolejnosc wspolczynnikow od lewej do prawej
M = fliplr(coeffs(M1, s));

% Licznik L11 czyli G11 = (L11 * Qg)/M
L1Qg = coeffs(subs(L1,Tz,0), Qg);
L11 = fliplr(coeffs(L1Qg, s));
% Licznik L12 czyli G12 = (L12 * Tz)/M
L1Tz = coeffs(subs(L1,Qg,0), Tz);
L12 = fliplr(coeffs(L1Tz, s));
% Licznik L11 czyli G21 = (L21 * Qg)/M
L2Qg = coeffs(subs(L2,Tz,0), Qg);
L21 = fliplr(coeffs(L2Qg, s));
% Licznik L22 czyli G22 = (L22 * Tz)/M
L2Tz = coeffs(subs(L2, Qg, 0), Tz);
L22 = fliplr(coeffs(L2Tz, s));
% Licznik L31 czyli G31 = (L31 * Qg)/M
L3Qg = coeffs(subs(L3,Tz,0), Qg);
L31 = fliplr(coeffs(L3Qg, s));
% Licznik L32 czyli G12 = (L12 * Tz)/M
L3Tz = coeffs(subs(L3,Qg,0), Tz);
L32 = fliplr(coeffs(L3Tz, s));


