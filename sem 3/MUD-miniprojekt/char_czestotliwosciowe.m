clc; clear;

run z_identyfikacja.m
Idelay = 0;
%% przed symulacja
% zestawy punktow rownowagi
wektor_Qg0 = [QgN, (QgN*0.7), QgN, (QgN*0.7), QgN];
wektor_Tzew0 = [TzewN, (TzewN + 10), TzewN, (TzewN + 10), TzewN];
wektor_Fp0 = [FpN, FpN, FpN*2, FpN*2, FpN];

%% petla tworzaca obiekty
for i = 1 : length(wektor_Qg0)
Qg0 = wektor_Qg0(i); Tzew0 = wektor_Tzew0(i); Fp0 = wektor_Fp0(i);
run  ss_tf_support.m
end

%% charakterystyki czestotliwosciowe

% opoznienie ma byc 0 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

wmin = 10e-7; % poczatek osi w
wmax = 10e-2; % koniec osi w
w = {wmin, wmax}; % zakres czestotliwosci

opcje = bodeoptions;
opcje.Grid = 'on';

figure(15);
bode(obiekt_tf1,  opcje);
grid on;

%% wyznaczone z wykresow
s = tf('s');

K1 = 10^(-48/20); % k1 = -48 dB
T1 = 1/0.0012;

K2 = 10^(-61.9/20); % k2 = -61.9 dB
T2 = 1/(2.11e-05);
T3 = 1/(0.00163);

K3 = 10^(-0.0112/20);
T4 = 1/(2.11e-05);
T5 = 1/(0.00899);


sys1 = tf([K1], [T1 1]);
figure(16);
bode(obiekt_tf1(1,1), sys1, opcje);
grid on;

sys2 = tf([K2], [T2*T3 T2+T3 1]);
figure(17);
bode(obiekt_tf1(2,1), sys2, opcje);
grid on;

sys3 = tf([T5 1], [T4 1]);
figure(18);
bode(obiekt_tf1(3, 2), sys3, w, opcje);
grid on;