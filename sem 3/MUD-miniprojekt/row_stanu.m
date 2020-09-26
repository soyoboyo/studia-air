
run z_identyfikacja.m

%% przed symulacja
% zestawy punktow rownowagi
wektor_Qg0 = [QgN, (QgN*0.7), QgN, (QgN*0.7)];
wektor_Tzew0 = [TzewN, (TzewN + 10), TzewN, (TzewN + 10)];
wektor_Fp0 = [FpN, FpN, FpN*2, FpN*2];

% zmiany wejsc
dQg = QgN*0.1; % 0 lub 0.05
dTzew = 0; % 0 lub 2

% typ wykresu
styl = {'-'; '--'; '-'; '--'}; grub = [3; 2; 1.5; 1]; kolo = ['k'; 'b'; 'g'; 'r'];

%% badanie ukladu
for i = 1:4
%% punkty rownowagi
Qg0 = wektor_Qg0(i); Tzew0 = wektor_Tzew0(i); Fp0 = wektor_Fp0(i);

% warunki poczatkowe nie zaleza od wyjsc
P = rop*cpp*Fp0; % parametr dla uproszczenia wzorów
MTw = Kg + Kw + P; % mianownik dla uproszczenia wzorów
Tg0 = -(Ks*MTw*Qg0 - Kw^2*Qg0 + Kw*MTw*Qg0 + P*Kg*Ks*Tzew0 + P*Kg*Kw*Tzew0 + Kg*Ks*Kw*Tzew0)/(Kg*(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw));
Ts0 = -(Kw*Qg0 + P*Kw*Tzew0 - Kg*Ks*Tzew0 + Ks*MTw*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);
Twew0 = -(Ks*Qg0 + Kw*Qg0 + Ks*Kw*Tzew0 + Ks*P*Tzew0 + Kw*P*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);
TG0(i) = Tg0; TS0(i) = Ts0; TWEW0(i) = Twew0;

m1 = Cvg*MTw; % mianownik 1
m2 = Cvs*MTw; % mianownik 2

%% macierze
% wspolczynnyki przy wyjsciach Tg i Ts
A = [ (Kg^2 - MTw*Kg)/m1,              (Kg*Kw)/m1; ...
        (Kg*Kw)/m2,     -(- Kw^2 + MTw*Kw + Ks*MTw)/m2];
% wspolczynniki przy wejsciach Qg i Tzew
B = [ 1/Cvg,      (Kg*P)/m1; ...
             0,          (Ks*MTw + Kw*P)/m2];     
% Twew = (Kg*Tg + Kw*Ts + P*Tzew)/MTw; 
% dodanie trzeciego wiersza do macierzy wyjsciowcyh
C = [1 , 0; 0, 1; Kg/MTw, Kw/MTw];
D = [0 , 0; 0, 0; 0, P/MTw];

% stan rownowagi
u0 = [Qg0; Tzew0];
x0 = (-A^-1) * (B*u0);

%%  parametry symulacji
t0 = 40000; % czas wystapienia skoku wejsc
czas_sym = 400000; % czas symulacji
tmax = 500; % maksymalny skok
%set_param('row_stanu_model', 'StopTime', 'czas_sym', 'MaxStep', 'tmax'); % ustawianie parametrow symulacji
% jesli nie dziala, uruchomic symulacja bez set_param, potem uruchomic z set_param
sim('row_stanu_model.slx');
TG = [TG , Tg]; TS = [TS, Ts]; TWEW = [TWEW, Twew];

%% wyniki symulacji
figure(4); % grzejnik
p = plot(t, TG(: , i)); 
c = p.LineWidth; p.LineWidth = grub(i);  p.LineStyle =styl{i}; p.Color = kolo(i);
xlabel('Czas [s]'); ylabel('Temepretura [C]');  grid on;  hold on;
legend(['Nominalne'], ...
['QgN*' num2str(wektor_Qg0(2)/QgN), ', TzN+' num2str(wektor_Tzew0(2) - TzewN), ', FpN*' num2str(wektor_Fp0(2)/FpN)], ...
['QgN', ', TzN', ', FpN*' num2str(wektor_Fp0(3)/FpN)], ...
['QgN*' num2str(wektor_Qg0(4)/QgN), ', TzN+' num2str(wektor_Tzew0(4) - TzewN), ', FpN*' num2str(wektor_Fp0(4)/FpN)]);
title(['Reakcja Tg dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew)], 'FontSize', 14);


figure(5); % sciany
p = plot(t, TS(: , i));
c = p.LineWidth; p.LineWidth = grub(i);  p.LineStyle =styl{i}; p.Color = kolo(i);
xlabel('Czas [s]'); ylabel('Temepretura [C]'); grid on;  hold on;
legend(['Nominalne'], ...
['QgN*' num2str(wektor_Qg0(2)/QgN), ', TzN+' num2str(wektor_Tzew0(2) - TzewN), ', FpN*' num2str(wektor_Fp0(2)/FpN)], ...
['QgN', ', TzN', ', FpN*' num2str(wektor_Fp0(3)/FpN)], ...
['QgN*' num2str(wektor_Qg0(4)/QgN), ', TzN+' num2str(wektor_Tzew0(4) - TzewN), ', FpN*' num2str(wektor_Fp0(4)/FpN)]);
title(['Reakcja Ts dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew)], 'FontSize', 14);


figure(6); % powietrze
p = plot(t, TWEW(: , i));
c = p.LineWidth; p.LineWidth = grub(i);  p.LineStyle =styl{i}; p.Color = kolo(i);
xlabel('Czas [s]'); ylabel('Temepretura [C]'); grid on; grid minor; hold on;
legend(['Nominalne'], ...
['QgN*' num2str(wektor_Qg0(2)/QgN), ', TzN+' num2str(wektor_Tzew0(2) - TzewN), ', FpN*' num2str(wektor_Fp0(2)/FpN)], ...
['QgN', ', TzN', ', FpN*' num2str(wektor_Fp0(3)/FpN)], ...
['QgN*' num2str(wektor_Qg0(4)/QgN), ', TzN+' num2str(wektor_Tzew0(4) - TzewN), ', FpN*' num2str(wektor_Fp0(4)/FpN)]);

title(['Reakcja Twew dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew)], 'FontSize', 13);

if i == 1
    spr_rs_tw = Twew;
end
if i == 4
    figure(4); grid minor; hold off;  figure(5); hold off; grid minor; figure(6); hold off;  grid minor;% czyszczenie wykresow po ostatniej symulacji
end

end