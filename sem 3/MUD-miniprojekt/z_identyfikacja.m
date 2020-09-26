
set(0,'defaultfigurecolor',[1 1 1]); % ustawienie bialego tla na wykresach

%% Zadanie 6.3.1. Pomieszczenie z ogrzewaniem elektrycznym i wentylacja (pojemnosci Cvw, Cvs, Cvg)
%{
Grzejnik elektryczny o mocy Qg ogrzewa pomieszczenie o kubaturze Vw. 
W modelu trzeba uwzglednic dwie najistotniejsze pojemnosci cieplne.
W warunkach nominalnych (TzewN = -20 stopni C, TwewN = 20 stopni C), moc
grzalki QgN = 20 kW.

Model opisuje przewodzenie ciepla powietrze-sciana Kw i sciana-powietrze Ks
oraz wentylacje Fp (wymiane powietrza przez nieszczelnosci)

Cvg * (Tg)'(t) = Qg(t) - Kg * ( Tg(t) - Twew(t) )
Cvw * (Twew)'(t) = Kg * (Tg(t) - Twew(t)) - Kw * (Twew(t) - Ts(t)) - cpp*rop*Fp(t) * (Twew(t) - Tzew(t))
Cvs * (Ts)'(t) = Kw * (Twew(t) - Ts(t)) - Ks * (Ts(t) - Tzew(t))

Cvg * Tg' = Qg - Kg * ( Tg - Twew )
Cvw * Twew' = Kg * (Tg - Twew) - Kw * (Twew - Ts) - cpp*rop*Fp * (Twew - Tzew)
Cvs * Ts' = Kw * (Twew - Ts) - Ks * (Ts - Tzew)

zmienne wyjscia: Tg, Ts i moze Twew
zmienne wejscia: gq - grzejnik, Fp - wentylacja, Tzew - temp zew
wspolczynniki: Kg - grzejnik powietrze, Kw - powietrze sciana, Ks - sciana zewnatrz


Wariant zalozen c: Pomijalna pojemnosc cieplna pomieszczenia (Cvw = 0).
Zaklada sie, ze przeplyw powietrza w warunkach nominalnych wynosi 10
m^3/godz, a wspolczynnik Ks jest o polowe wiekszy niz Kw.
%}
%% Warunki nominalne

TzewN = -20; % temp na zewnatrz -20 C
TwewN = 20; % temp wewnatrz 20 C
TgN = 60; % temp grzejnika 60 C
QgN = 20000; % moc grzejnika 20 kW

%% wnioski z wariantu
a = 3/2; % Ks jest o polowe wiekszy niz Kw /// Kw*a = Ks
TsN = (TwewN + a*TzewN)/(a + 1); % temp nominalna scian

%Cvw = 0%
FpN =10/3600; % wentylacja 10 m^3/godz konwersja na m^3 /s

%% wlasnosci fizyczne materialow
cpp = 1000; % J / (kg * K)  cieplo wlasciwe powietrza
rop = 1.2; % kg / m^3 gestosc powietrza
Vp = 10*10*3; % objetosc pomieszczenia 32 m^3
Cvp = cpp*rop*Vp; % pojemnosc cieplna pomieszczenia

cpw = 4175; % J / (kg * K) cieplo wlasciwe wody
row = 960; % kg / m^3 gestosc wody
Vg = 0.05; % 50 litrow wody w grzejniku [m^3]
Cvg = cpw*row*Vg; % pojemnosc cieplna grzejnika

cpb = 880; % J / (kg * K) cieplo wlasciwe cegiel
rob = 1400; % kg / m^3 gestosc cegiel dziurawka
Vb = (10.4 * 10.4 * 3.2) - Vp; % m^3 cegiel w scianach (grubosc 20 cm)
Cvs = cpb*rob*Vb; % pojemnosc cieplna scian

%% wspolczynniki w warunkach nominalnych
Kg = QgN/(TgN - TwewN);
Kw = (QgN - cpp*rop*FpN*(TwewN - TzewN)) / (TwewN - TsN);
Ks = Kw*a;

%% pozostale
% P jako parametr:
%P = rop*cpp*FpN;

% z drugiego rownania
% MTw = Kg + Kw + P;
% TwewN = (Kg*TgN)/MTw + (Kw*TsN)/MTw + (P*TzewN)/MTw;

TG = []; TS = []; TWEW = []; % puste macierze

