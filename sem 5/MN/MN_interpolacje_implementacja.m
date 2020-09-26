clear all; clc;
set(0,'defaultfigurecolor',[1 1 1]); % ustawienie bialego tla na wykresach
% przyklad z wykladu
%x = [10 20 30 40 50];
%y = [0.98 0.93 0.86 0.76 0.64];

x = [0 1 2 3 4 5 5.5 6 7 ];
y = [1 4 1 5 3 5 3 2 0 ];
pkt = 3.5; % w punkcie x = 23

% (x + 0.5) (x - 0.1) (x - 0.25) (x - 0.7) (x - 1)
funkcja = [1 -1.55 0.295 0.3725 -0.12625 0.00875];
xf = [-0.55        0            0.2       0.6      1.05        0.4     ];    %0.3         ];
yf = [-0.050375 0.00875 -0.0014 0.0077  0.020615  0.00729 ];% 0.00224 ];
pktf = 0.5;

%% Interpolacja wielomianowa Lagrange'a

[wielomian, A] = MN_Lagrange(xf, yf);

wartosc = polyval(wielomian, pktf); % wartosc funkcji w punkcie pkt

%% Interpolacja metoda roznic skonczonych

[wielomian2, B] = MN_ilorazy(x, y);

wartosc2 = polyval(wielomian2, pkt); % wartosc funkcji w punkcie pkt

wielomian


wartosc


a= polyval(funkcja, pktf);
a







%% wykresy


v = linspace(-0.6, 1.1);
g = polyval(wielomian, v);
 
figure(1);
 hold on; grid on; grid minor;
title(['Zadanie interpolacji']);
 xlabel('x'); ylabel('f(x)');
 plot(v, polyval(funkcja, v));
 plot(v, polyval(wielomian, v));
 
 legend('funkcja oryginalna', 'wielomian interplacyjny');
 xlim([-0.55 1.05]) 
for i = 1:length(xf)
    plot(xf(i), yf(i), '*');
end
plot(pktf, wartosc, 'o');



