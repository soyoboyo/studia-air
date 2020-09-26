

run z_identyfikacja.m

i = 1;
%% przed symlacja
% zestawy punktow rownowagi
wektor_Qg0 = [QgN, (QgN*0.7), (QgN*0.7)];
wektor_Tzew0 = [TzewN, (TzewN +10), (TzewN +10)];
wektor_Fp0 = [FpN, FpN, FpN*2];

% zmiany wejsc
dQg = QgN*0.1; % 0 lub 0.1
dTzew = 0; % 0 lub 2
dFp = FpN*0.0; % 0 lub 0.5

% typ wykresu
styl = {'-'; ':'; '--'}; grub = [3; 2; 1]; kolo = ['k'; 'b'; 'r'];

%% badanie ukladu
for i = 1:length(wektor_Qg0)
%% punkty rownowagi
Qg0 = wektor_Qg0(i); Tzew0 = wektor_Tzew0(i); Fp0 = wektor_Fp0(i);

% warunki poczatkowe nie zaleza od wyjsc
P = rop*cpp*Fp0; % parametr dla uproszczenia wzorów
MTw = Kg + Kw + P; % mianownik dla uproszczenia wzorów
Tg0 = -(Ks*MTw*Qg0 - Kw^2*Qg0 + Kw*MTw*Qg0 + P*Kg*Ks*Tzew0 + P*Kg*Kw*Tzew0 + Kg*Ks*Kw*Tzew0)/(Kg*(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw));
Ts0 = -(Kw*Qg0 + P*Kw*Tzew0 - Kg*Ks*Tzew0 + Ks*MTw*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);
Twew0 = -(Ks*Qg0 + Kw*Qg0 + Ks*Kw*Tzew0 + Ks*P*Tzew0 + Kw*P*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);
TG0(i) = Tg0; TS0(i) = Ts0; TWEW0(i) = Twew0;
MTwew_dok = Kg + Kw; % mianownik bez wentylacji


%%  parametry symulacji
t0 = 40000; % czas wystapienia skoku wejsc
czas_sym = 400000; % czas symulacji
tmax = 500; % maksymalny skok
%set_param('dokladny_model', 'StopTime', 'czas_sym', 'MaxStep', 'tmax'); % ustawianie parametrow symulacji
% jesli nie dziala, uruchomic symulacja raz bez set_param, potem uruchomic jeszcze raz z set_param
sim('dokladny_model.slx');
TG = [TG , Tg]; TS = [TS, Ts]; TWEW = [TWEW, Twew];



%% wyniki symulacji
figure(1); % grzejnik
p = plot(t, TG(: , i) - TG0(i)); 
c = p.LineWidth; p.LineWidth = grub(i);  p.LineStyle =styl{i}; p.Color = kolo(i);
xlabel('Czas [s]'); ylabel('Temepretura [C]'); grid on; grid minor; hold on;
%legend(['Nominalne'], ['N*' num2str(wektor_Qg0(2)/QgN), ', N+' num2str(wektor_Tzew0(2) - TzewN), ', N*' num2str(wektor_Fp0(2)/FpN)], ['N*' num2str(Qg0/QgN), ', N+' num2str(wektor_Tzew0(i) - TzewN), ', N*' num2str(Fp0/FpN)]);
title(['Reakcja Tg dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew) ', dFp = ' num2str(dFp*100/FpN)  '%' ]);


figure(2); % sciany
p = plot(t, TS(: , i) - TS0(i));
c = p.LineWidth; p.LineWidth = grub(i);  p.LineStyle =styl{i}; p.Color = kolo(i);
xlabel('Czas [s]'); ylabel('Temepretura [C]'); grid on; grid minor; hold on;
%legend(['Nominalne'], ['N*' num2str(wektor_Qg0(2)/QgN), ', N+' num2str(wektor_Tzew0(2) - TzewN), ', N*' num2str(wektor_Fp0(2)/FpN)], ['N*' num2str(Qg0/QgN), ', N+' num2str(wektor_Tzew0(i) - TzewN), ', N*' num2str(Fp0/FpN)]);title(['Temp scian dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew) ', dFp = ' num2str(dFp*100/FpN)  '%' ]);
title(['Reakcja Ts dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew) ', dFp = ' num2str(dFp*100/FpN)  '%' ]);


figure(3); % powietrze
p = plot(t, TWEW(: , i) - TWEW0(i));
c = p.LineWidth; p.LineWidth = grub(i);  p.LineStyle =styl{i}; p.Color = kolo(i);
xlabel('Czas [s]'); ylabel('Temepretura [C]'); grid on; grid minor; hold on;
%legend(['Nominalne'], ['N*' num2str(wektor_Qg0(2)/QgN), ', N+' num2str(wektor_Tzew0(2) - TzewN), ', N*' num2str(wektor_Fp0(2)/FpN)], ['N*' num2str(Qg0/QgN), ', N+' num2str(wektor_Tzew0(i) - TzewN), ', N*' num2str(Fp0/FpN)]);title(['Temp powietrza dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew) ', dFp = ' num2str(dFp*100/FpN)  '%' ]);
title(['Reakcja Twew dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew) ', dFp = ' num2str(dFp*100/FpN)  '%' ]);

if i == 1
    spr_d_tw = Twew;
end

if i == 3 
    figure(1); hold off; figure(2); hold off; figure(3); hold off; % czyszczenie wykresow po ostatniej symulacji
end

end

