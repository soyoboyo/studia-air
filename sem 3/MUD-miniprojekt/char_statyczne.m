clc; clear;

run z_identyfikacja.m

% zestawy punktow rownowagi
wektor_Qg0 = [QgN, (QgN*0.7), (QgN*0.7)];
wektor_Tzew0 = [TzewN, (TzewN + 10), (TzewN + 10)];
wektor_Fp0 = [FpN, FpN, (FpN*2)];

% http://www.engineeringtoolbox.com/natural-draught-ventilation-d_122.html
for i = 1:3
%% obliczenia do wykresow
% zaleznosc od Qg
Tzew0 = wektor_Tzew0(i); Fp0 = wektor_Fp0(i);
Qg0 = [0.7*QgN : 0.1*QgN : 1.3*QgN]; 

P = rop*cpp*Fp0; % parametr dla uproszczenia wzorów
MTw = Kg + Kw + P; % mianownik dla uproszczenia wzorów

Tg0q = -(Ks*MTw.*Qg0 - Kw^2.*Qg0 + Kw*MTw.*Qg0 + P*Kg*Ks*Tzew0 + P*Kg*Kw*Tzew0 + Kg*Ks*Kw*Tzew0)/(Kg*(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw));
Ts0q = -(Kw.*Qg0 + P*Kw*Tzew0 - Kg*Ks*Tzew0 + Ks*MTw*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);
Twew0q = -(Ks*Qg0 + Kw*Qg0 + Ks*Kw*Tzew0 + Ks*P*Tzew0 + Kw*P*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);

% zaleznosc od Tzew
Qg0 = wektor_Qg0(i); Fp0 = wektor_Fp0(i);
Tzew0 = [0.7*TzewN : 0.1*TzewN : 1.3*TzewN];

P = rop*cpp*Fp0; % parametr dla uproszczenia wzorów
MTw = Kg + Kw + P; % mianownik dla uproszczenia wzorów

Tg0tz = -((Ks*MTw - Kw^2 + Kw*MTw)*Qg0 + P*Kg*Ks.*Tzew0 + P*Kg*Kw.*Tzew0 + Kg*Ks*Kw.*Tzew0)/(Kg*(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw));
Ts0tz = -(Kw*Qg0 + (P*Kw - Kg*Ks + Ks*MTw).*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);
Twew0tz = -(Ks*Qg0 + Kw*Qg0 + (Ks*Kw + Ks*P + Kw*P).*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);

% zaleznosc od Fp
Qg0 = wektor_Qg0(i); Tzew0 = wektor_Tzew0(i);
Fp0 = [0 : FpN : (15*FpN)];

P = rop*cpp.*Fp0; % parametr dla uproszczenia wzorów
MTw = Kg + Kw + rop*cpp*Fp0; % mianownik dla uproszczenia wzorów

Tg0fp = -((Ks*(Kg + Kw + P) - Kw^2 + Kw*(Kg + Kw + P))*Qg0 + (P*Kg*Ks + P*Kg*Kw + Kg*Ks*Kw)*Tzew0)./(Kg*(Kw^2 + Kg*Ks + Kg*Kw - Ks*(Kg + Kw + P) - Kw*(Kg + Kw + rop*cpp.*Fp0)));
Ts0fp = -(Kw*Qg0 + (P*Kw - Kg*Ks + Ks.*MTw)*Tzew0)./(Kw^2 + Kg*Ks + Kg*Kw - Ks.*MTw - Kw.*MTw);
Twew0fp = -((Ks + Kw)*Qg0 + (Ks*Kw + Ks*P + Kw*P)*Tzew0)./(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);

%% wykresy
Qg0 = [0.7*QgN : 0.1*QgN : (1.3*QgN)]; Tzew0 = [0.7*TzewN : 0.1*TzewN : 1.3*TzewN]; Fp0 = [0 : FpN : (15*FpN)];

figure(12); % zaleznosc od Qggrid on; grid minor;
subplot(3,1,1); 
plot(Qg0, Tg0q); title('Tg(Qg)');
xlabel('Qg [W]'); ylabel('Temp [C]'); hold on; grid on; grid minor;  legend('N', 'M', 'P1', 'P2');
if i == 1
plot(QgN, TgN,'*','MarkerSize',10); % punkt pracy w warunkach nominalnych
end
subplot(3,1,2); plot(Qg0, Ts0q); title('Ts(Qg)');
xlabel('Qg [W]'); ylabel('Temp [C]'); hold on; grid on; grid minor;
if i == 1
plot(QgN, TsN,'*','MarkerSize',10); % punkt pracy w warunkach nominalnych
end
subplot(3,1,3); plot(Qg0, Twew0q); title('Twew(Qg)');
xlabel('Qg [W]'); ylabel('Temp [C]'); hold on;grid on; grid minor;
if i == 1
plot(QgN, TwewN,'*','MarkerSize',10); % punkt pracy w warunkach nominalnych %
end

figure(13); % zaleznosc od Tzew0
subplot(3,1,1); plot(Tzew0, Tg0tz); title('Tg(Tzew)'); 
xlabel('Tzew [C]'); ylabel('Temp [C]'); hold on; grid on; grid minor;  legend('N', 'M', 'P1', 'P2');
if i == 1
plot(TzewN,TgN,'*','MarkerSize',10); % punkt pracy w warunkach nominalnych
end

subplot(3,1,2); plot(Tzew0, Ts0tz); title('Ts(Tzew)'); 
xlabel('Tzew [C]'); ylabel('Temp [C]'); hold on; grid on; grid minor;
if i == 1
plot(TzewN,TsN,'*','MarkerSize',10); % punkt pracy w warunkach nominalnych
end

subplot(3,1,3); plot(Tzew0, Twew0tz); title('Twew(Tzew)'); 
xlabel('Tzew [C]'); ylabel('Temp [C]'); hold on; grid on; grid minor;
if i == 1
plot(TzewN,TwewN,'*','MarkerSize',10);% punkt pracy w warunkach nominalnych
end

figure(14); % zaleznosc od Fp
subplot(3,1,1); p = plot(Fp0, Tg0fp); title('Tg(Fp)'); 
xlabel('Fp [m3/s]'); ylabel('Temp [C]'); hold on; grid on; grid minor;  legend('N', 'M', 'P1', 'P2');xlim([0 15*FpN]);
if i == 1
plot(FpN,TgN,'*','MarkerSize',10); % punkt pracy w warunkach nominalnych
end

subplot(3,1,2); plot(Fp0, Ts0fp); title('Ts(Fp)'); 
xlabel('Fp [m3/s]'); ylabel('Temp [C]'); hold on; grid on; grid minor;xlim([0 15*FpN]);
if i == 1
plot(FpN,TsN,'*','MarkerSize',10); % punkt pracy w warunkach nominalnych
end

subplot(3,1,3); plot(Fp0, Twew0fp); title('Twew(Fp)'); 
xlabel('Fp [m3/s]'); ylabel('Temp [C]'); hold on; grid on; grid minor; xlim([0 15*FpN]);
if i == 1
plot(FpN,TwewN,'*','MarkerSize',10);% punkt pracy w warunkach nominalnych
end


if i == 3
    figure(12);   hold off; figure(13); hold off;  figure(14); hold off; 
end
end
