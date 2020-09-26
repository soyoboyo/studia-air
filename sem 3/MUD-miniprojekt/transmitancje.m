

run z_identyfikacja.m

%% przed symulacja
% zestawy punktow rownowagi
wektor_Qg0 = [QgN, (QgN*0.7)];
wektor_Tzew0 = [TzewN, (TzewN + 10)];
wektor_Fp0 = [FpN, (FpN*2)];

% zmiany wejsc
dQg = QgN*0.0; % 0 lub 0.1
dTzew = 2; % 0 lub 2

% typ wykresu
styl = {'-'; '--'}; grub = [3; 1]; kolo = ['k'; 'm'];

%% badanie ukladu
for i = 1:2
%% punkty rownowagi
Qg0 = wektor_Qg0(i); Tzew0 = wektor_Tzew0(i); Fp0 = wektor_Fp0(i);

% warunki poczatkowe
P = rop*cpp*Fp0; % parametr dla uproszczenia wzorów
MTw = Kg + Kw + P; % mianownik dla uproszczenia wzorów
Tg0 = -(Ks*MTw*Qg0 - Kw^2*Qg0 + Kw*MTw*Qg0 + P*Kg*Ks*Tzew0 + P*Kg*Kw*Tzew0 + Kg*Ks*Kw*Tzew0)/(Kg*(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw));
Ts0 = -(Kw*Qg0 + P*Kw*Tzew0 - Kg*Ks*Tzew0 + Ks*MTw*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);
Twew0 = -(Ks*Qg0 + Kw*Qg0 + Ks*Kw*Tzew0 + Ks*P*Tzew0 + Kw*P*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);
TG0(i) = Tg0; TS0(i) = Ts0; TWEW0(i) = Twew0;

%% transmitancje
M = [ Cvg*Cvs*MTw, ... 
         - Cvs*Kg^2 + Cvs*MTw*Kg - Cvg*Kw^2 + Cvg*MTw*Kw + Cvg*Ks*MTw, ...
         Kg*(-Kg*Kw - Ks*Kg - Kw^2 + MTw*Kw + Ks*MTw)];
L11 = [ Cvs*MTw, ... 
            - Kw^2 + MTw*Kw + Ks*MTw];
L12 = [ Cvs*Kg*P, ... 
            Kg*Ks*Kw + Kg*Ks*P + Kg*Kw*P];
L21 = [ Kg*Kw];
L22 = [ Cvg*Ks*MTw + Cvg*Kw*P, ...
            Kg*Ks*MTw - Kg^2*Ks + Kg*Kw*P];
L31 = [ Cvs*Kg, ...
            Kg*Ks + Kg*Kw];
L32 = [ Cvg*Cvs*P, ... 
Cvg*Ks*Kw + Cvs*Kg*P + Cvg*Ks*P + Cvg*Kw*P, ... 
             Kg*Ks*Kw + Kg*Ks*P + Kg*Kw*P];
 
   
%%  parametry symulacji
t0 = 40000; % czas wystapienia skoku wejsc
czas_sym = 400000; % czas symulacji
tmax = 500; % maksymalny skok
%set_param('transmitancje_model', 'StopTime', 'czas_sym', 'MaxStep', 'tmax'); % ustawianie parametrow symulacji
% jesli nie dziala, uruchomic symulacja raz bez set_param, potem uruchomic z set_param
sim('transmitancje_model.slx');
TG = [TG , Tg]; TS = [TS, Ts]; TWEW = [TWEW, Twew];


%% wyniki symulacji
figure(7); % grzejnik
p = plot(t, TG(: , i)); 
c = p.LineWidth; p.LineWidth = grub(i);  p.LineStyle =styl{i}; p.Color = kolo(i);
xlabel('Czas'); ylabel('Temepretura'); grid on; grid minor; hold on;
legend('Nominalne', 'zestaw 2');
title(['Temp grzejnika dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew)]);
%ylim([minTg maxTg]);

figure(8); % sciany
p = plot(t, TS(: , i)); 
c = p.LineWidth; p.LineWidth = grub(i);  p.LineStyle = styl{i}; p.Color = kolo(i);
xlabel('Czas'); ylabel('Temepretura'); grid on; grid minor; hold on;
legend('Nominalne', 'zestaw 2');
title(['Temp scian dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew)]);
%ylim([minTs maxTs]);

figure(9); % powietrze
p = plot(t, TWEW(: , i)); 
c = p.LineWidth; p.LineWidth = grub(i);  p.LineStyle = styl{i}; p.Color = kolo(i);
xlabel('Czas'); ylabel('Temepretura'); grid on; grid minor; hold on;
legend('Nominalne', 'zestaw 2');
title(['Temp powietrza dla wymuszen: dQg = ' num2str(dQg*100/QgN) '%, dTzew = ' num2str(dTzew)]);
%ylim([minTwew maxTwew]);

if i == 2 
    s3tw = TWEW;
    s3ts = TS;
    s3tg = TG;
    figure(7); hold off; grid minor; figure(8); hold off; grid minor; figure(9); hold off; grid minor; % czyszczenie wykresow po ostatniej symulacji
end
end