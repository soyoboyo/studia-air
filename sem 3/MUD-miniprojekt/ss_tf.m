clc; clear;

run z_identyfikacja.m

%% przed symulacja
% zestawy punktow rownowagi
wektor_Qg0 = [QgN, (QgN*0.7), QgN, (QgN*0.7), QgN];
wektor_Tzew0 = [TzewN, (TzewN + 10), TzewN, (TzewN + 10), TzewN];
wektor_Fp0 = [FpN, FpN, FpN*2, FpN*2, FpN];

% zmiany wejsc
dQg = QgN*0.1; % 0 lub 0.05
dTzew = 2; %0 lub 2

% opcje dla obiektow
dQgoff = 0; dTzewoff = 0; % offset
Idelay = 0; % opoznienie

% opcje dla funckji step()
opcje = stepDataOptions('InputOffset',[dQgoff dTzewoff],'StepAmplitude',[dQg dTzew]);

%% petla tworzaca obiekty
for i = 1 : length(wektor_Qg0)
Qg0 = wektor_Qg0(i); Tzew0 = wektor_Tzew0(i); Fp0 = wektor_Fp0(i);
run  ss_tf_support.m
end

%% state space


figure(10);
step(obiekt_ss1,obiekt_ss2, obiekt_ss3, obiekt_ss4, opcje);
grid on; grid minor;
title(['Odp skokowa obiektu typu ss dla: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew)]);

%% transfer function

figure(11);
step(obiekt_tf1, obiekt_tf2, obiekt_tf3, obiekt_tf4, opcje);
grid on; grid minor;
title(['Odp skokowa obiektu typu tf dla: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew)]); 

