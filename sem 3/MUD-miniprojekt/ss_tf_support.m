
% warunki poczatkowe
P = rop*cpp*Fp0; % parametr dla uproszczenia wzorów
MTw = Kg + Kw + P; % mianownik dla uproszczenia wzorów
Tg0 = -(Ks*MTw*Qg0 - Kw^2*Qg0 + Kw*MTw*Qg0 + P*Kg*Ks*Tzew0 + P*Kg*Kw*Tzew0 + Kg*Ks*Kw*Tzew0)/(Kg*(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw));
Ts0 = -(Kw*Qg0 + P*Kw*Tzew0 - Kg*Ks*Tzew0 + Ks*MTw*Tzew0)/(Kw^2 + Kg*Ks + Kg*Kw - Ks*MTw - Kw*MTw);

m1 = Cvg*MTw; % mianownik 1
m2 = Cvs*MTw; % mianownik 2

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

% wspolczynniki transmitancji
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
         obiekt = ss(A, B, C, D);
         
if i == 1
    obiekt_ss1 = ss(A, B, C, D, 'InputName', {'Qg ' 'Tzew'}, 'OutputName', {'Tg' 'Ts ' 'Twew'}, ... 
    'InputDelay',[Idelay Idelay]); % definicja obiektu
    obiekt_tf1 = tf({L11, L12; L21, L22; L31, L32} , {M, M; M, M; M, M}, 'InputName', {'Qg ' 'Tzew'}, 'OutputName', {'Tg' 'Ts ' 'Twew'}, ... 
    'InputDelay',[Idelay Idelay]); % definicja obiektu
end

if i == 2
    obiekt_ss2 = ss(A, B, C, D, 'InputName', {'Qg ' 'Tzew'}, 'OutputName', {'Tg' 'Ts ' 'Twew'}, ... 
    'InputDelay',[Idelay Idelay]); % definicja obiektu
    obiekt_tf2 = tf({L11, L12; L21, L22; L31, L32} , {M, M; M, M; M, M}, 'InputName', {'Qg ' 'Tzew'}, 'OutputName', {'Tg' 'Ts ' 'Twew'}, ... 
    'InputDelay',[Idelay Idelay]); % definicja obiektu
end

if i == 3
    obiekt_ss3 = ss(A, B, C, D, 'InputName', {'Qg ' 'Tzew'}, 'OutputName', {'Tg' 'Ts ' 'Twew'}, ... 
    'InputDelay',[Idelay Idelay]); % definicja obiektu
    obiekt_tf3 = tf({L11, L12; L21, L22; L31, L32} , {M, M; M, M; M, M}, 'InputName', {'Qg ' 'Tzew'}, 'OutputName', {'Tg' 'Ts ' 'Twew'}, ... 
    'InputDelay',[Idelay Idelay]); % definicja obiektu
end

if i == 4
    obiekt_ss4 = ss(A, B, C, D, 'InputName', {'Qg ' 'Tzew'}, 'OutputName', {'Tg' 'Ts ' 'Twew'}, ... 
    'InputDelay',[Idelay Idelay]); % definicja obiektu
    obiekt_tf4 = tf({L11, L12; L21, L22; L31, L32} , {M, M; M, M; M, M}, 'InputName', {'Qg ' 'Tzew'}, 'OutputName', {'Tg' 'Ts ' 'Twew'}, ... 
    'InputDelay',[Idelay Idelay]); % definicja obiektu
end

if i == 5
    obiekt =  tf({L11, L12; L21, L22; L31, L32} , {M, M; M, M; M, M}, 'InputName', {'Qg ' 'Tzew'}, 'OutputName', {'Tg' 'Ts ' 'Twew'}, ... 
    'InputDelay',[Idelay Idelay]); % definicja obiektu
end
